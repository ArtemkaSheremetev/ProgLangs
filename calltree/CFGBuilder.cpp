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

    for (size_t i = 0; i < node->children.size(); ++i) {
        ASTNode* stmt = node->children[i].get();

        if (stmt->name == "DoStatement") {
            ASTNode* cond = nullptr;

            // Проверяем, идёт ли сразу CompareExpr после DoStatement
            if (i + 1 < node->children.size() &&
                node->children[i + 1]->name == "CompareExpr") {
                cond = node->children[i + 1].get();
                i++; // пропускаем CompareExpr в основном цикле
            }

            visitDo(stmt, cond);
            continue;
        }

        visitStatement(stmt);
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
            type = ParseType(ch->children[0]->value); 
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
    if (!node) return current;

    if (node->name == "IfStatement")
        return visitIf(node);

    if (node->name == "WhileStatement")
        return visitWhile(node);

    if (node->name == "DoStatement")
        return visitDo(node, nullptr);

    if (node->name == "StatementBlock")
        return visitBlock(node);

    if (node->name == "CallExpr")
        return visitCall(node);

    // Обычное выражение/присваивание
    CFGNode* stmt = graph->create_node(NodeType::BASIC_BLOCK, "stmt");
    stmt->add_statement(exprToString(node));

    current->add_successor(stmt);
    current = stmt;

    return current;
}


// ========================================================
// CALL
// ========================================================

CFGNode* CFGBuilder::visitCall(ASTNode* node) {
    std::string callee = node->children[0]->value;
    std::string caller = graph->function_name;

    CFGNode* call = graph->create_node(NodeType::CALL, "call");
    call->label = "call " + callee;

    if (node->children.size() > 1) {
        for (auto& arg : node->children[1]->children) {
            call->statements.push_back(exprToString(arg.get()));
        }
    }

    current->add_successor(call);
    current = call;

    if (callGraph) {
        callGraph->add_call(caller, callee);
    }

    return current;
}


// ========================================================
// IF
// ========================================================

CFGNode* CFGBuilder::visitIf(ASTNode* node) {
    CFGNode* cond = graph->create_node(NodeType::CONDITION, "if");
    cond->condition = exprToString(node->children[0].get());

    current->add_successor(cond);

    CFGNode* thenBlock = graph->create_node(NodeType::BASIC_BLOCK, "then");
    cond->true_branch = thenBlock;
    cond->add_successor(thenBlock);

    current = thenBlock;
    CFGNode* thenEnd = visitStatement(node->children[1].get());

    CFGNode* elseEnd = nullptr;
    if (node->children.size() > 2) {
        CFGNode* elseBlock = graph->create_node(NodeType::BASIC_BLOCK, "else");
        cond->false_branch = elseBlock;
        cond->add_successor(elseBlock);

        current = elseBlock;
        elseEnd = visitStatement(node->children[2].get());
    }

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
    CFGNode* header = graph->create_node(NodeType::LOOP_HEADER, "while");
    header->condition = exprToString(node->children[0].get());

    current->add_successor(header);

    CFGNode* body = graph->create_node(NodeType::LOOP_BODY, "while_body");
    header->loop_body = body;
    header->add_successor(body);

    current = body;
    CFGNode* bodyEnd = visitStatement(node->children[1].get());
    bodyEnd->add_successor(header);

    CFGNode* exit = graph->create_node(NodeType::LOOP_EXIT, "while_exit");
    header->loop_exit = exit;
    header->add_successor(exit);

    current = exit;
    return current;
}


// ========================================================
// DO / REPEAT
// ========================================================

CFGNode* CFGBuilder::visitDo(ASTNode* node, ASTNode* condNode) {
    CFGNode* header = graph->create_node(NodeType::LOOP_HEADER, "repeat");

    if (condNode)
        header->condition = exprToString(condNode);

    header->is_until = true;

    current->add_successor(header);

    CFGNode* body = graph->create_node(NodeType::LOOP_BODY, "repeat_body");
    header->loop_body = body;
    header->add_successor(body);

    current = body;

    CFGNode* last = body;
    for (auto& child : node->children) {
        last = visitStatement(child.get());
    }

    last->add_successor(header);

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

    if (node->name == "AssignExpr") {
        std::string lhs = exprToString(node->children[0].get());
        std::string rhs = exprToString(node->children[1].get());
        return lhs + " := " + rhs;
    }

    if (node->name == "BinaryExpr") {
        std::string left  = exprToString(node->children[0].get());
        std::string right = exprToString(node->children[1].get());
        return "(" + left + " " + node->value + " " + right + ")";
    }

    if (node->name == "CompareExpr") {
        string left  = exprToString(node->children[0].get());
        string right = exprToString(node->children[1].get());
        return "(" + left + " " + node->value + " " + right + ")";
    }

    if (node->name == "Literal" || node->name == "Identifier") {
        return node->value;
    }

    if (node->name == "CallExpr") {
        std::string callee = node->children[0]->value;
        std::string args;
        if (node->children.size() > 1) {
            for (size_t i = 0; i < node->children[1]->children.size(); ++i) {
                args += exprToString(node->children[1]->children[i].get());
                if (i + 1 < node->children[1]->children.size()) args += ", ";
            }
        }
        return callee + "(" + args + ")";
    }

    return node->name;
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
