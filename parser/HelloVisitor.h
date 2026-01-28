
// Generated from Hello.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "HelloParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by HelloParser.
 */
class  HelloVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by HelloParser.
   */
    virtual std::any visitSource(HelloParser::SourceContext *context) = 0;

    virtual std::any visitSourceItem(HelloParser::SourceItemContext *context) = 0;

    virtual std::any visitFuncDef(HelloParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncSignature(HelloParser::FuncSignatureContext *context) = 0;

    virtual std::any visitArgList(HelloParser::ArgListContext *context) = 0;

    virtual std::any visitArgDef(HelloParser::ArgDefContext *context) = 0;

    virtual std::any visitBody(HelloParser::BodyContext *context) = 0;

    virtual std::any visitVarDeclList(HelloParser::VarDeclListContext *context) = 0;

    virtual std::any visitStatementBlock(HelloParser::StatementBlockContext *context) = 0;

    virtual std::any visitStatement(HelloParser::StatementContext *context) = 0;

    virtual std::any visitReturnStatement(HelloParser::ReturnStatementContext *context) = 0;

    virtual std::any visitIfStatement(HelloParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileStatement(HelloParser::WhileStatementContext *context) = 0;

    virtual std::any visitDoStatement(HelloParser::DoStatementContext *context) = 0;

    virtual std::any visitExprStatement(HelloParser::ExprStatementContext *context) = 0;

    virtual std::any visitExpr(HelloParser::ExprContext *context) = 0;

    virtual std::any visitAssignExpr(HelloParser::AssignExprContext *context) = 0;

    virtual std::any visitLogicalOrExpr(HelloParser::LogicalOrExprContext *context) = 0;

    virtual std::any visitLogicalAndExpr(HelloParser::LogicalAndExprContext *context) = 0;

    virtual std::any visitCompareExpr(HelloParser::CompareExprContext *context) = 0;

    virtual std::any visitAddSubExpr(HelloParser::AddSubExprContext *context) = 0;

    virtual std::any visitMulDivExpr(HelloParser::MulDivExprContext *context) = 0;

    virtual std::any visitUnaryExpr(HelloParser::UnaryExprContext *context) = 0;

    virtual std::any visitCallExpr(HelloParser::CallExprContext *context) = 0;

    virtual std::any visitPrimaryExpr(HelloParser::PrimaryExprContext *context) = 0;

    virtual std::any visitExprList(HelloParser::ExprListContext *context) = 0;

    virtual std::any visitTypeRef(HelloParser::TypeRefContext *context) = 0;

    virtual std::any visitBuiltinType(HelloParser::BuiltinTypeContext *context) = 0;

    virtual std::any visitLiteral(HelloParser::LiteralContext *context) = 0;

    virtual std::any visitIdentifier(HelloParser::IdentifierContext *context) = 0;


};

