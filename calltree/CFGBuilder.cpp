#include "CFGBuilder.h"
#include <sstream>

using namespace std;

CFGBuilder::CFGBuilder(OpGraph* g, CallGraph* cg)
    : graph(g), callGraph(cg), current(g->entry) {}


// ========================================================
// ENTRY
// ========================================================

void CFGBuilder::build(ASTNode* body) {
    CFGNode* tail = graph->entry;

    for (auto& ch : body->children) {
        if (ch->name == "VarDeclList") {
            visitVars(ch.get());
            continue;
        }

        if (ch->name == "StatementBlock") {
            BuildRes r = visitBlock(ch.get());
            if (r.start) tail->add_successor(r.start);
            tail = r.end ? r.end : tail;
        }
    }

    if (tail && tail != graph->exit && tail->type != NodeType::EXIT)
    tail->add_successor(graph->exit);

    current = tail;
}


// ========================================================
// VARIABLES
// ========================================================

void CFGBuilder::visitVars(ASTNode* node) {
    vector<string> names;
    types_t type = INT;

    for (auto& ch : node->children) {
        if (ch->name == "Identifier") {
            names.push_back(ch->value);
        } else if (ch->name == "TypeRef") {
            type = ParseType(ch->children[0]->value);
        }
    }

    for (auto& n : names)
        graph->variables[n] = type;
}


// ========================================================
// BLOCK (просто склеивает statements)
// ========================================================

BuildRes CFGBuilder::visitBlock(ASTNode* node) {
    BuildRes res;
    CFGNode* first = nullptr;
    CFGNode* prevEnd = nullptr;

    for (size_t i = 0; i < node->children.size(); ++i) {
        ASTNode* stmt = node->children[i].get();
        BuildRes r = visitStatement(stmt);

        if (!first) first = r.start;

        if (prevEnd && r.start) {
            if (prevEnd->type != NodeType::EXIT) {
                prevEnd->add_successor(r.start);
            }
        }

        prevEnd = r.end;

        // return завершает блок
        if (prevEnd && prevEnd->type == NodeType::EXIT) {
            break;
        }
    }

    res.start = first;
    res.end   = prevEnd ? prevEnd : first;
    return res;
}




// ========================================================
// STATEMENTS DISPATCH
// ========================================================

BuildRes CFGBuilder::visitStatement(ASTNode* node) {
    BuildRes r;
    if (!node) return r;

    if (node->name == "ReturnStatement") return visitReturn(node);
    if (node->name == "IfStatement")      return visitIf(node);
    if (node->name == "WhileStatement")   return visitWhile(node);
    if (node->name == "DoStatement")      return visitDo(node, nullptr);
    if (node->name == "StatementBlock")   return visitBlock(node);
    if (node->name == "CallExpr")         return visitCall(node);

    // обычное выражение / присваивание
    CFGNode* stmt = graph->create_node(NodeType::BASIC_BLOCK, "stmt");
    stmt->add_statement(exprToString(node));
    stmt->exprTrees.push_back(buildExprTree(node));

    r.start = r.end = stmt;
    return r;
}

BuildRes CFGBuilder::visitReturn(ASTNode* node) {
    BuildRes r;

    CFGNode* ex = graph->create_node(NodeType::EXIT, "exit");

    // return expr;
    if (!node->children.empty() && node->children[0]) {
        ex->returnExpr = buildExprTree(node->children[0].get());
        ex->add_statement("return " + exprToString(node->children[0].get()));
    } else {
        ex->add_statement("return");
        ex->returnExpr = nullptr;
    }

    // EXIT — терминатор: successors не добавляем
    r.start = r.end = ex;
    return r;
}


// ========================================================
// CALL (без использования current)
// ========================================================

BuildRes CFGBuilder::visitCall(ASTNode* node) {
    BuildRes r;

    string callee = node->children[0]->value;
    string caller = graph->function_name;

    CFGNode* call = graph->create_node(NodeType::CALL, "call");
    call->label = "call " + callee;

    // ---- аргументы ----
    if (node->children.size() > 1) {
        ASTNode* argNode = node->children[1].get();

        // Case A: CallExpr(Identifier, ExprList)
        if (argNode->name == "ExprList") {
            for (auto& arg : argNode->children) {
                call->statements.push_back(exprToString(arg.get()));
                call->exprTrees.push_back(buildExprTree(arg.get()));
            }
        }
        // Case B: CallExpr(Identifier, arg1, arg2, ...)
        else {
            for (size_t i = 1; i < node->children.size(); ++i) {
                ASTNode* arg = node->children[i].get();
                call->statements.push_back(exprToString(arg));
                call->exprTrees.push_back(buildExprTree(arg));
            }
        }
    }

    if (callGraph)
        callGraph->add_call(caller, callee);

    r.start = r.end = call;
    return r;
}




// ========================================================
// IF (без then/else прокладок)
// ========================================================

BuildRes CFGBuilder::visitIf(ASTNode* node) {
    BuildRes r;

    CFGNode* cond = graph->create_node(NodeType::CONDITION, "if");
    cond->condition = exprToString(node->children[0].get());
    cond->conditionTree = buildExprTree(node->children[0].get());

    CFGNode* merge = graph->create_node(NodeType::MERGE, "merge");

    // THEN
    BuildRes thenR = visitStatement(node->children[1].get());
    if (thenR.start) {
        cond->add_successor(thenR.start);
        cond->true_branch = thenR.start;
        if (thenR.end && thenR.end->type != NodeType::EXIT)
            thenR.end->add_successor(merge);

    } else {
        cond->add_successor(merge);
        cond->true_branch = merge;
    }

    // ELSE
    if (node->children.size() > 2) {
        BuildRes elseR = visitStatement(node->children[2].get());
        if (elseR.start) {
            cond->add_successor(elseR.start);
            cond->false_branch = elseR.start;
            if (elseR.end && elseR.end->type != NodeType::EXIT)
                elseR.end->add_successor(merge);
        } else {
            cond->add_successor(merge);
            cond->false_branch = merge;
        }
    } else {
        cond->add_successor(merge);
        cond->false_branch = merge;
    }

    r.start = cond;
    r.end = merge;
    return r;
}


// ========================================================
// WHILE
// ========================================================

BuildRes CFGBuilder::visitWhile(ASTNode* node) {
    BuildRes r;

    CFGNode* header = graph->create_node(NodeType::LOOP_HEADER, "while");
    header->condition = exprToString(node->children[0].get());
    header->conditionTree = buildExprTree(node->children[0].get());

    CFGNode* after = graph->create_node(NodeType::MERGE, "after_while");

    BuildRes bodyR = visitStatement(node->children[1].get());

    if (bodyR.start) {
        header->add_successor(bodyR.start); // true ветка
        header->loop_body = bodyR.start;
        if (bodyR.end && bodyR.end->type != NodeType::EXIT)
            bodyR.end->add_successor(header);
    } else {
        // пустое тело: бесконечный цикл теоретически, но пусть true ведёт в header
        header->add_successor(header);
        header->loop_body = header;
    }

    header->add_successor(after);          // false ветка
    header->loop_exit = after;

    r.start = header;
    r.end = after;
    return r;
}


// ========================================================
// DO / REPEAT-UNTIL
// repeat { body } until cond
// порядок: body -> header(cond) -> (exit OR back to body)
// ========================================================

BuildRes CFGBuilder::visitDo(ASTNode* node, ASTNode* condNode) {
    BuildRes r;
    if (!node) return r;

    // Новый формат: DoStatement(value="until|while", children=[body, cond])
    ASTNode* bodyNode = nullptr;
    ASTNode* condExpr = nullptr;

    if (node->children.size() >= 2) {
        bodyNode = node->children[0].get();
        condExpr = node->children[1].get();
    }
    // На всякий случай оставим обратную совместимость
    if (condNode) condExpr = condNode;

    // Строим тело: оно может быть и StatementBlock, и одиночным statement
    BuildRes bodyR;
    if (bodyNode) {
        if (bodyNode->name == "StatementBlock") bodyR = visitBlock(bodyNode);
        else bodyR = visitStatement(bodyNode);
    }

    CFGNode* header = graph->create_node(NodeType::LOOP_HEADER, "repeat");
    header->is_until = (node->value == "until"); // "until" или "while"

    if (condExpr) {
        header->condition = exprToString(condExpr);
        header->conditionTree = buildExprTree(condExpr);
    }

    CFGNode* after = graph->create_node(NodeType::MERGE, "after_repeat");

    // repeat всегда сначала выполняет тело
    CFGNode* bodyStart = bodyR.start ? bodyR.start : header;
    CFGNode* bodyEnd   = bodyR.end   ? bodyR.end   : header;

    // тело -> проверка
    if (bodyEnd != header && bodyEnd && bodyEnd->type != NodeType::EXIT)
        bodyEnd->add_successor(header);

    // Из header:
    // repeat ... until cond;  TRUE => exit,  FALSE => loop
    // repeat ... while cond;  TRUE => loop, FALSE => exit
    if (header->is_until) {
        header->add_successor(after);     // true  -> exit
        header->add_successor(bodyStart); // false -> loop
    } else {
        header->add_successor(bodyStart); // true  -> loop
        header->add_successor(after);     // false -> exit
    }

    header->loop_body = bodyStart;
    header->loop_exit = after;

    r.start = bodyStart;
    r.end = after;
    return r;
}


// ========================================================
// EXPRESSION TREE
// ========================================================

ExprPtr CFGBuilder::buildExprTree(ASTNode* node) {
    if (!node) return nullptr;

    if (node->name == "Literal")
        return make_shared<LiteralExpr>(node->value);

    if (node->name == "Identifier")
        return make_shared<VarExpr>(node->value);

    if (node->name == "UnaryExpr")
        return make_shared<UnaryExpr>(
            node->value,
            buildExprTree(node->children[0].get())
        );

    if (node->name == "BinaryExpr" || node->name == "CompareExpr")
        return make_shared<BinaryExpr>(
            node->value,
            buildExprTree(node->children[0].get()),
            buildExprTree(node->children[1].get())
        );

    if (node->name == "AssignExpr")
        return make_shared<AssignExpr>(
            buildExprTree(node->children[0].get()),
            buildExprTree(node->children[1].get())
        );

    if (node->name == "CallExpr") {
    if (node->children.empty()) return nullptr;

    std::string callee = node->children[0]->value;
    std::vector<ExprPtr> args;

    if (node->children.size() >= 2) {
        ASTNode* argNode = node->children[1].get();

        // ✅ ExprList из твоего AST
        if (argNode && (argNode->name == "ExprList" ||
                        argNode->name == "Args" ||
                        argNode->name == "ArgList" ||
                        argNode->name == "Arguments")) {
            for (auto& a : argNode->children) {
                args.push_back(buildExprTree(a.get()));
            }
        } else {
            // Case B: args are directly in CallExpr children (from index 1)
            for (size_t i = 1; i < node->children.size(); ++i) {
                args.push_back(buildExprTree(node->children[i].get()));
            }
        }
    }

    return make_shared<CallExpr>(callee, std::move(args));
}

    return nullptr;
}


// ========================================================
// STRING (для DOT / отладки)
// ========================================================

string CFGBuilder::exprToString(ASTNode* node) {
    if (!node) return "";

    if (node->name == "AssignExpr") {
        if (node->children.size() >= 2) {
            return exprToString(node->children[0].get()) +
                   " := " +
                   exprToString(node->children[1].get());
        }
        return "(:=)";
    }

    if (node->name == "BinaryExpr" || node->name == "CompareExpr") {
        if (node->children.size() >= 2) {
            return "(" +
                   exprToString(node->children[0].get()) +
                   " " + node->value + " " +
                   exprToString(node->children[1].get()) +
                   ")";
        }
        return "(" + node->value + ")";
    }

    if (node->name == "UnaryExpr") {
        if (!node->children.empty()) {
            return "(" + node->value + " " + exprToString(node->children[0].get()) + ")";
        }
        return "(" + node->value + ")";
    }

    if (node->name == "Literal" || node->name == "Identifier") {
        return node->value;
    }

    if (node->name == "ExprList") {
        string s;
        for (size_t i = 0; i < node->children.size(); ++i) {
            s += exprToString(node->children[i].get());
            if (i + 1 < node->children.size()) s += ", ";
        }
        return s;
    }

    if (node->name == "CallExpr") {
        if (node->children.empty()) return "call(?)";

        string s = node->children[0]->value + "(";

        if (node->children.size() > 1) {
            ASTNode* argNode = node->children[1].get();

            // Case A: CallExpr(Identifier, ExprList)
            if (argNode && (argNode->name == "ExprList" ||
                            argNode->name == "Args" ||
                            argNode->name == "ArgList" ||
                            argNode->name == "Arguments")) {
                for (size_t i = 0; i < argNode->children.size(); ++i) {
                    s += exprToString(argNode->children[i].get());
                    if (i + 1 < argNode->children.size()) s += ", ";
                }
            } else {
                // Case B: CallExpr(Identifier, arg1, arg2, ...)
                for (size_t i = 1; i < node->children.size(); ++i) {
                    s += exprToString(node->children[i].get());
                    if (i + 1 < node->children.size()) s += ", ";
                }
            }
        }

        return s + ")";
    }

    // fallback for debug
    return node->name;
}



// ========================================================
// TYPE PARSE
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
