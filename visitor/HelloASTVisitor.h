#pragma once

#include "HelloVisitor.h"
#include "HelloParser.h"
#include "ASTNodes.h"
#include <memory>

class HelloASTVisitor : public HelloVisitor {
public:
    HelloASTVisitor() = default;

    // Основные методы
    std::any visitSource(HelloParser::SourceContext *context) override;

    std::any visitSourceItem(HelloParser::SourceItemContext *context) override;

    std::any visitFuncDef(HelloParser::FuncDefContext *context) override;

    std::any visitFuncSignature(HelloParser::FuncSignatureContext *context) override;

    std::any visitArgList(HelloParser::ArgListContext *context) override;

    std::any visitArgDef(HelloParser::ArgDefContext *context) override;

    std::any visitBody(HelloParser::BodyContext *context) override;

    std::any visitVarDeclList(HelloParser::VarDeclListContext *context) override;

    std::any visitStatementBlock(HelloParser::StatementBlockContext *context) override;

    std::any visitStatement(HelloParser::StatementContext *context) override;

    std::any visitIfStatement(HelloParser::IfStatementContext *context) override;

    std::any visitWhileStatement(HelloParser::WhileStatementContext *context) override;

    std::any visitDoStatement(HelloParser::DoStatementContext *context) override;

    std::any visitExprStatement(HelloParser::ExprStatementContext *context) override;

    std::any visitExpr(HelloParser::ExprContext *context) override;

    std::any visitAssignExpr(HelloParser::AssignExprContext *context) override;

    std::any visitLogicalOrExpr(HelloParser::LogicalOrExprContext *context) override;

    std::any visitLogicalAndExpr(HelloParser::LogicalAndExprContext *context) override;

    std::any visitCompareExpr(HelloParser::CompareExprContext *context) override;

    std::any visitAddSubExpr(HelloParser::AddSubExprContext *context) override;

    std::any visitMulDivExpr(HelloParser::MulDivExprContext *context) override;

    std::any visitUnaryExpr(HelloParser::UnaryExprContext *context) override;

    std::any visitPrimaryExpr(HelloParser::PrimaryExprContext *context) override;

    std::any visitExprList(HelloParser::ExprListContext *context) override;

    std::any visitTypeRef(HelloParser::TypeRefContext *context) override;

    std::any visitBuiltinType(HelloParser::BuiltinTypeContext *context) override;

    std::any visitLiteral(HelloParser::LiteralContext *context) override;

    std::any visitIdentifier(HelloParser::IdentifierContext *context) override;

    std::any visitCallExpr(HelloParser::CallExprContext *context) override;
};
