#include "HelloASTVisitor.h"

// ------------------ Source ------------------
std::any HelloASTVisitor::visitSource(HelloParser::SourceContext *context) {
    auto node = std::make_shared<ASTNode>("Source");
    for (auto item : context->sourceItem()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(item)));
    }
    return node;
}

// ------------------ SourceItem ------------------
std::any HelloASTVisitor::visitSourceItem(HelloParser::SourceItemContext *context) {
    return visit(context->funcDef());
}

// ------------------ FuncDef ------------------
std::any HelloASTVisitor::visitFuncDef(HelloParser::FuncDefContext *context) {
    auto node = std::make_shared<ASTNode>("FuncDef");
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->funcSignature())));
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->body())));
    return node;
}

// ------------------ FuncSignature ------------------
std::any HelloASTVisitor::visitFuncSignature(HelloParser::FuncSignatureContext *context) {
    auto node = std::make_shared<ASTNode>("FuncSignature");
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->identifier())));
    if (context->argList()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->argList())));
    }
    if (context->typeRef()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->typeRef())));
    }
    return node;
}

// ------------------ ArgList ------------------
std::any HelloASTVisitor::visitArgList(HelloParser::ArgListContext *context) {
    auto node = std::make_shared<ASTNode>("ArgList");
    for (auto arg : context->argDef()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(arg)));
    }
    return node;
}

// ------------------ ArgDef ------------------
std::any HelloASTVisitor::visitArgDef(HelloParser::ArgDefContext *context) {
    auto node = std::make_shared<ASTNode>("ArgDef");
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->identifier())));
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->typeRef())));
    return node;
}

// ------------------ Body ------------------
std::any HelloASTVisitor::visitBody(HelloParser::BodyContext *context) {
    auto node = std::make_shared<ASTNode>("Body");
    for (size_t i = 0; i < context->VAR().size(); i++) {
        node->addChild(std::make_shared<ASTNode>("VAR", context->VAR(i)->getText()));
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->varDeclList(i))));
    }
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->statementBlock())));
    return node;
}

// ------------------ VarDeclList ------------------
std::any HelloASTVisitor::visitVarDeclList(HelloParser::VarDeclListContext *context) {
    auto node = std::make_shared<ASTNode>("VarDeclList");
    for (auto id : context->identifier()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(id)));
    }
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->typeRef())));
    return node;
}

// ------------------ StatementBlock ------------------
std::any HelloASTVisitor::visitStatementBlock(HelloParser::StatementBlockContext *context) {
    auto node = std::make_shared<ASTNode>("StatementBlock");
    for (auto stmt : context->statement()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(stmt)));
    }
    return node;
}

// ------------------ Statement ------------------
std::any HelloASTVisitor::visitStatement(HelloParser::StatementContext *context) {
    if (context->ifStatement()) return visit(context->ifStatement());
    if (context->whileStatement()) return visit(context->whileStatement());
    if (context->doStatement()) return visit(context->doStatement());
    if (context->statementBlock()) return visit(context->statementBlock());
    if (context->exprStatement()) return visit(context->exprStatement());
    return nullptr;
}

// ------------------ IfStatement ------------------
std::any HelloASTVisitor::visitIfStatement(HelloParser::IfStatementContext *context) {
    auto node = std::make_shared<ASTNode>("IfStatement");
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->expr())));
    for (auto stmt : context->statement()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(stmt)));
    }
    return node;
}

// ------------------ WhileStatement ------------------
std::any HelloASTVisitor::visitWhileStatement(HelloParser::WhileStatementContext *context) {
    auto node = std::make_shared<ASTNode>("WhileStatement");
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->expr())));
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->statement())));
    return node;
}

// ------------------ DoStatement ------------------
std::any HelloASTVisitor::visitDoStatement(HelloParser::DoStatementContext *context) {
    auto node = std::make_shared<ASTNode>("DoStatement");
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->statement())));
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->expr())));
    return node;
}

// ------------------ ExprStatement ------------------
std::any HelloASTVisitor::visitExprStatement(HelloParser::ExprStatementContext *context) {
    return visit(context->expr());
}

// ------------------ Expr / AssignExpr ------------------
std::any HelloASTVisitor::visitExpr(HelloParser::ExprContext *context) {
    return visit(context->assignExpr());
}

std::any HelloASTVisitor::visitAssignExpr(HelloParser::AssignExprContext *context) {
    if (context->assignExpr()) {
        auto node = std::make_shared<ASTNode>("AssignExpr");
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->logicalOrExpr())));
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->assignExpr())));
        return node;
    }
    // если нет присваивания — просто возвращаем child
    return visit(context->logicalOrExpr());
}

// ------------------ Logical / Compare / Add / Mul / Unary / Primary ------------------
std::any HelloASTVisitor::visitLogicalOrExpr(HelloParser::LogicalOrExprContext *context) {
    if (context->logicalAndExpr().size() == 1)
        return visit(context->logicalAndExpr(0));

    auto node = std::make_shared<ASTNode>("LogicalOrExpr");
    for (auto child : context->logicalAndExpr()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(child)));
    }
    return node;
}

std::any HelloASTVisitor::visitLogicalAndExpr(HelloParser::LogicalAndExprContext *context) {
    if (context->compareExpr().size() == 1)
        return visit(context->compareExpr(0));

    auto node = std::make_shared<ASTNode>("LogicalAndExpr");
    for (auto child : context->compareExpr()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(child)));
    }
    return node;
}

std::any HelloASTVisitor::visitCallExpr(HelloParser::CallExprContext *context) {
    auto node = std::make_shared<ASTNode>("CallExpr");

    // имя функции
    node->addChild(std::any_cast<ASTNodePtr>(visit(context->identifier())));

    // аргументы, если есть
    if (context->exprList()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->exprList())));
    }

    return node;
}


std::any HelloASTVisitor::visitCompareExpr(HelloParser::CompareExprContext *context) {
    if (context->addSubExpr().size() == 1)
        return visit(context->addSubExpr(0));

    auto node = std::make_shared<ASTNode>("CompareExpr");
    for (auto child : context->addSubExpr()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(child)));
    }
    return node;
}

std::any HelloASTVisitor::visitAddSubExpr(HelloParser::AddSubExprContext *ctx) {
    // первый операнд
    auto left = std::any_cast<ASTNodePtr>(visit(ctx->mulDivExpr(0)));

    // дальше цепочка (op rhs)
    for (size_t i = 1; i < ctx->mulDivExpr().size(); ++i) {
        // оператор между operands
        std::string op = ctx->children[2*i - 1]->getText(); // + или -

        auto right = std::any_cast<ASTNodePtr>(visit(ctx->mulDivExpr(i)));

        auto bin = std::make_shared<ASTNode>("BinaryExpr", op);
        bin->addChild(left);
        bin->addChild(right);

        left = bin;
    }

    return left;
}


std::any HelloASTVisitor::visitMulDivExpr(HelloParser::MulDivExprContext *context) {
    if (context->unaryExpr().size() == 1)
        return visit(context->unaryExpr(0));

    auto node = std::make_shared<ASTNode>("MulDivExpr");
    for (auto child : context->unaryExpr()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(child)));
    }
    return node;
}

std::any HelloASTVisitor::visitUnaryExpr(HelloParser::UnaryExprContext *context) {
    if (context->unaryExpr()) {
        auto node = std::make_shared<ASTNode>(
            "UnaryExpr",
            context->children[0]->getText()// !, -, +
        );
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->unaryExpr())));
        return node;
    }
    return visit(context->primaryExpr());
}


std::any HelloASTVisitor::visitPrimaryExpr(HelloParser::PrimaryExprContext *context) {
    if (context->primaryExpr()) {
        auto node = std::make_shared<ASTNode>("IndexExpr");
        node->addChild(std::any_cast<ASTNodePtr>(visit(context->primaryExpr())));
        if (context->exprList()) {
            node->addChild(std::any_cast<ASTNodePtr>(visit(context->exprList())));
        }
        return node;
    }

    if (context->callExpr()) return visit(context->callExpr());
    if (context->literal()) return visit(context->literal());
    if (context->identifier()) return visit(context->identifier());
    if (context->expr()) return visit(context->expr());

    return nullptr;
}


// ------------------ ExprList ------------------
std::any HelloASTVisitor::visitExprList(HelloParser::ExprListContext *context) {
    auto node = std::make_shared<ASTNode>("ExprList");
    for (auto e : context->expr()) {
        node->addChild(std::any_cast<ASTNodePtr>(visit(e)));
    }
    return node;
}

// ------------------ TypeRef ------------------
std::any HelloASTVisitor::visitTypeRef(HelloParser::TypeRefContext *context) {
    auto node = std::make_shared<ASTNode>("TypeRef");
    if (context->builtinType()) node->addChild(std::any_cast<ASTNodePtr>(visit(context->builtinType())));
    if (context->identifier()) node->addChild(std::any_cast<ASTNodePtr>(visit(context->identifier())));
    if (context->typeRef()) node->addChild(std::any_cast<ASTNodePtr>(visit(context->typeRef())));
    return node;
}

// ------------------ BuiltinType ------------------
std::any HelloASTVisitor::visitBuiltinType(HelloParser::BuiltinTypeContext *context) {
    return std::make_shared<ASTNode>("BuiltinType", context->getText());
}

// ------------------ Literal ------------------
std::any HelloASTVisitor::visitLiteral(HelloParser::LiteralContext *context) {
    return std::make_shared<ASTNode>("Literal", context->getText());
}

// ------------------ Identifier ------------------
std::any HelloASTVisitor::visitIdentifier(HelloParser::IdentifierContext *context) {
    return std::make_shared<ASTNode>("Identifier", context->getText());
}
