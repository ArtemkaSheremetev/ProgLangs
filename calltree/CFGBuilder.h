#pragma once

#include <memory>
#include <string>

#include "ASTNodes.h"
#include "Graph.h"
#include <unordered_map>
#include <stack>


struct CFGBuilder {
    OpGraph* graph;     // текущий граф функции
    CFGNode* current;  // текущая точка потока управления
    CallGraph* callGraph;
    
    explicit CFGBuilder(OpGraph* g, CallGraph* cg);

    // Точка входа — тело функции (Body)
    void build(ASTNode* body);

    // Обход AST
    CFGNode* visitStatement(ASTNode* stmt);
    CFGNode* visitBlock(ASTNode* block);
    CFGNode* visitCall(ASTNode* node);
    CFGNode* emitExprNode(ASTNode* node);
    void visitVars(ASTNode* vars);

private:
    // Специализированные конструкции
    CFGNode* visitIf(ASTNode* stmt);
    CFGNode* visitWhile(ASTNode* stmt);
    CFGNode* visitDo(ASTNode* stmt, ASTNode* condNode);
    // Утилиты
    std::string exprToString(ASTNode* expr);
};
