
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

    virtual std::any visitParamList(HelloParser::ParamListContext *context) = 0;

    virtual std::any visitParam(HelloParser::ParamContext *context) = 0;

    virtual std::any visitBody(HelloParser::BodyContext *context) = 0;

    virtual std::any visitBlock(HelloParser::BlockContext *context) = 0;

    virtual std::any visitTypeRef(HelloParser::TypeRefContext *context) = 0;

    virtual std::any visitBuiltinType(HelloParser::BuiltinTypeContext *context) = 0;

    virtual std::any visitCommaList(HelloParser::CommaListContext *context) = 0;

    virtual std::any visitBlockStmt(HelloParser::BlockStmtContext *context) = 0;

    virtual std::any visitVarDeclStmt(HelloParser::VarDeclStmtContext *context) = 0;

    virtual std::any visitIfStmt(HelloParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(HelloParser::WhileStmtContext *context) = 0;

    virtual std::any visitRepeatStmt(HelloParser::RepeatStmtContext *context) = 0;

    virtual std::any visitBreakStmt(HelloParser::BreakStmtContext *context) = 0;

    virtual std::any visitReturnStmt(HelloParser::ReturnStmtContext *context) = 0;

    virtual std::any visitExprStmt(HelloParser::ExprStmtContext *context) = 0;

    virtual std::any visitSimpleExpr(HelloParser::SimpleExprContext *context) = 0;

    virtual std::any visitUnaryExpr(HelloParser::UnaryExprContext *context) = 0;

    virtual std::any visitAddExpr(HelloParser::AddExprContext *context) = 0;

    virtual std::any visitMulExpr(HelloParser::MulExprContext *context) = 0;

    virtual std::any visitOrExpr(HelloParser::OrExprContext *context) = 0;

    virtual std::any visitAssignExpr(HelloParser::AssignExprContext *context) = 0;

    virtual std::any visitAndExpr(HelloParser::AndExprContext *context) = 0;

    virtual std::any visitCmpExpr(HelloParser::CmpExprContext *context) = 0;

    virtual std::any visitCmpOp(HelloParser::CmpOpContext *context) = 0;

    virtual std::any visitAddOp(HelloParser::AddOpContext *context) = 0;

    virtual std::any visitMulOp(HelloParser::MulOpContext *context) = 0;

    virtual std::any visitUnaryOp(HelloParser::UnaryOpContext *context) = 0;

    virtual std::any visitIndexExpr(HelloParser::IndexExprContext *context) = 0;

    virtual std::any visitLiteralExpr(HelloParser::LiteralExprContext *context) = 0;

    virtual std::any visitCallExpr(HelloParser::CallExprContext *context) = 0;

    virtual std::any visitParenExpr(HelloParser::ParenExprContext *context) = 0;

    virtual std::any visitIdExpr(HelloParser::IdExprContext *context) = 0;

    virtual std::any visitExprList(HelloParser::ExprListContext *context) = 0;

    virtual std::any visitLiteral(HelloParser::LiteralContext *context) = 0;


};

