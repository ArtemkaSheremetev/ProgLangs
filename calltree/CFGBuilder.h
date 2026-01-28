#pragma once

#include "Graph.h"
#include "ASTNodes.h"
#include "exprTree.h"

types_t ParseType(const std::string& str);

struct BuildRes {
    CFGNode* start = nullptr;
    CFGNode* end = nullptr;
};


class CFGBuilder {
public:
    CFGBuilder(OpGraph* g, CallGraph* cg);

    void build(ASTNode* body);

private:
    OpGraph* graph;
    CallGraph* callGraph;
    CFGNode* current;

    // ====== visitors ======
    BuildRes visitStatement(ASTNode* node);
    BuildRes visitBlock(ASTNode* node);
    BuildRes visitReturn(ASTNode* node);
    BuildRes visitIf(ASTNode* node);
    BuildRes visitWhile(ASTNode* node);
    BuildRes visitDo(ASTNode* node, ASTNode* condNode);
    BuildRes visitCall(ASTNode* node);

    void visitVars(ASTNode* node);

    // ====== expressions ======
    std::string exprToString(ASTNode* node);
    ExprPtr buildExprTree(ASTNode* node);
};
