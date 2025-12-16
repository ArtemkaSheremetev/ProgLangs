#include "CFGBuilder.h"
#include <sstream>

types_t ParseType(const std::string& str);

using namespace std;

CFGBuilder::CFGBuilder(OpGraph* g, CallGraph* cg)
    : graph(g), callGraph(cg), current(g->entry) {}

    
// ========================================================
// ENTRY
// ========================================================

void CFGBuilder::build(ASTNode* body) {
    for (size_t i = 0; i < body->children.size(); i++) {
        ASTNode* ch = body->children[i].get();

        if (ch->name == "VarDeclList") {
            visitVars(ch);
        }
        else if (ch->name == "StatementBlock") {
            visitBlock(ch);
        }
    }

    if (current && current != graph->exit) {
        current->add_successor(graph->exit);
    }
}

// ========================================================
// STATEMENT BLOCK
// ========================================================

CFGNode* CFGBuilder::visitBlock(ASTNode* node) {
    CFGNode* block = graph->create_node(NodeType::BASIC_BLOCK, "block");
    current->add_successor(block);
    current = block;

    for (auto& stmt : node->children) {
        visitStatement(stmt.get());
    }
    return current;
}

// ========================================================
// VARIABLES
// ========================================================

void CFGBuilder::visitVars(ASTNode* node) {
    vector<string> names;
    types_t type = INT; // default

    for (auto& ch : node->children) {
        if (ch->name == "Identifier") {
            names.push_back(ch->value);
        }
        else if (ch->name == "TypeRef") {
            type = ParseType(ch->children[0]->value); // возвращает types_t
        }
    }

    for (const auto& name : names) {
        graph->variables[name] = type;
    }
}


// ========================================================
// STATEMENTS DISPATCH
// ========================================================

CFGNode* CFGBuilder::visitStatement(ASTNode* node) {
    if (node->name == "IfStatement")
        return visitIf(node);

    if (node->name == "WhileStatement")
        return visitWhile(node);

    if (node->name == "DoStatement")
        return visitDo(node);

    if (node->name == "StatementBlock")
        return visitBlock(node);

    // ⬇⬇⬇ ВАЖНО ⬇⬇⬇
    if (node->name == "CallExpr")
        return visitCall(node);

    current->add_statement(exprToString(node));
    return current;
}


// ========================================================
// IF
// ========================================================

CFGNode* CFGBuilder::visitCall(ASTNode* node) {
    // children[0] = Identifier
    std::string callee = node->children[0]->value;
    std::string caller = graph->function_name;

    // 1. CFG node
    CFGNode* call = graph->create_node(NodeType::CALL, "call");
    call->label = "call " + callee;

    // аргументы
    if (node->children.size() > 1) {
        for (auto& arg : node->children[1]->children) {
            call->statements.push_back(exprToString(arg.get()));
        }
    }

    current->add_successor(call);
    current = call;

    // 2. CallGraph edge
    if (callGraph) {
        callGraph->add_call(caller, callee);
    }

    return current;
}



CFGNode* CFGBuilder::visitIf(ASTNode* node) {
    // children: [cond, then, else?]
    CFGNode* cond = graph->create_node(NodeType::CONDITION, "if");
    cond->condition = exprToString(node->children[0].get());

    current->add_successor(cond);

    // THEN
    CFGNode* thenBlock = graph->create_node(NodeType::BASIC_BLOCK, "then");
    cond->true_branch = thenBlock;
    cond->add_successor(thenBlock);

    current = thenBlock;
    CFGNode* thenEnd = visitStatement(node->children[1].get());

    // ELSE
    CFGNode* elseEnd = nullptr;
    if (node->children.size() > 2) {
        CFGNode* elseBlock = graph->create_node(NodeType::BASIC_BLOCK, "else");
        cond->false_branch = elseBlock;
        cond->add_successor(elseBlock);

        current = elseBlock;
        elseEnd = visitStatement(node->children[2].get());
    }

    // MERGE
    CFGNode* merge = graph->create_node(NodeType::MERGE, "merge");
    thenEnd->add_successor(merge);

    if (elseEnd)
        elseEnd->add_successor(merge);
    else
        cond->add_successor(merge);

    current = merge;
    return current;
}

// ========================================================
// WHILE
// ========================================================

CFGNode* CFGBuilder::visitWhile(ASTNode* node) {
    // children: [cond, body]
    CFGNode* header = graph->create_node(NodeType::LOOP_HEADER, "while");
    header->condition = exprToString(node->children[0].get());

    current->add_successor(header);

    // BODY
    CFGNode* body = graph->create_node(NodeType::LOOP_BODY, "while_body");
    header->loop_body = body;
    header->add_successor(body);

    current = body;
    CFGNode* bodyEnd = visitStatement(node->children[1].get());
    bodyEnd->add_successor(header);

    // EXIT
    CFGNode* exit = graph->create_node(NodeType::LOOP_EXIT, "while_exit");
    header->loop_exit = exit;
    header->add_successor(exit);

    current = exit;
    return current;
}

// ========================================================
// DO / REPEAT
// ========================================================

CFGNode* CFGBuilder::visitDo(ASTNode* node) {
    // children: [body, cond]
    CFGNode* header = graph->create_node(NodeType::LOOP_HEADER, "repeat");
    header->condition = exprToString(node->children[1].get());
    header->is_until = (node->value == "until");

    current->add_successor(header);

    // BODY
    CFGNode* body = graph->create_node(NodeType::LOOP_BODY, "repeat_body");
    header->loop_body = body;
    header->add_successor(body);

    current = body;
    CFGNode* bodyEnd = visitStatement(node->children[0].get());
    bodyEnd->add_successor(header);

    // EXIT
    CFGNode* exit = graph->create_node(NodeType::LOOP_EXIT, "repeat_exit");
    header->loop_exit = exit;
    header->add_successor(exit);

    current = exit;
    return current;
}

// ========================================================
// EXPRESSION TO STRING
// ========================================================

string CFGBuilder::exprToString(ASTNode* node) {
    if (!node) return "";

    if (node->name == "CallExpr") {
        std::stringstream ss;
        ss << node->children[0]->value << "(";
        if (node->children.size() > 1) {
            auto& args = node->children[1]->children;
            for (size_t i = 0; i < args.size(); ++i) {
                ss << exprToString(args[i].get());
                if (i + 1 < args.size()) ss << ", ";
            }
        }
        ss << ")";
        return ss.str();
    }

    if (!node->value.empty())
        return node->value;

    if (node->children.empty())
        return node->name;

    stringstream ss;
    ss << node->name << "(";
    for (size_t i = 0; i < node->children.size(); ++i) {
        ss << exprToString(node->children[i].get());
        if (i + 1 < node->children.size())
            ss << ", ";
    }
    ss << ")";
    return ss.str();
}


// ========================================================
// HELPERS
// ========================================================

types_t ParseType(const std::string& str) {
    if (str == "bool") return types_t::BOOL;
    else if (str == "byte") return types_t::BYTE;
    else if (str == "int") return types_t::INT;
    else if (str == "uint") return types_t::UINT;
    else if (str == "long") return types_t::LONG;
    else if (str == "ulong") return types_t::ULONG;
    else if (str == "char") return types_t::CHAR;
    else return types_t::STRING;
}
