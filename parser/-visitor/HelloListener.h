
// Generated from Hello.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "HelloParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by HelloParser.
 */
class  HelloListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSource(HelloParser::SourceContext *ctx) = 0;
  virtual void exitSource(HelloParser::SourceContext *ctx) = 0;

  virtual void enterSourceItem(HelloParser::SourceItemContext *ctx) = 0;
  virtual void exitSourceItem(HelloParser::SourceItemContext *ctx) = 0;

  virtual void enterFuncDef(HelloParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(HelloParser::FuncDefContext *ctx) = 0;

  virtual void enterParamList(HelloParser::ParamListContext *ctx) = 0;
  virtual void exitParamList(HelloParser::ParamListContext *ctx) = 0;

  virtual void enterParam(HelloParser::ParamContext *ctx) = 0;
  virtual void exitParam(HelloParser::ParamContext *ctx) = 0;

  virtual void enterBody(HelloParser::BodyContext *ctx) = 0;
  virtual void exitBody(HelloParser::BodyContext *ctx) = 0;

  virtual void enterBlock(HelloParser::BlockContext *ctx) = 0;
  virtual void exitBlock(HelloParser::BlockContext *ctx) = 0;

  virtual void enterTypeRef(HelloParser::TypeRefContext *ctx) = 0;
  virtual void exitTypeRef(HelloParser::TypeRefContext *ctx) = 0;

  virtual void enterBuiltinType(HelloParser::BuiltinTypeContext *ctx) = 0;
  virtual void exitBuiltinType(HelloParser::BuiltinTypeContext *ctx) = 0;

  virtual void enterCommaList(HelloParser::CommaListContext *ctx) = 0;
  virtual void exitCommaList(HelloParser::CommaListContext *ctx) = 0;

  virtual void enterBlockStmt(HelloParser::BlockStmtContext *ctx) = 0;
  virtual void exitBlockStmt(HelloParser::BlockStmtContext *ctx) = 0;

  virtual void enterVarDeclStmt(HelloParser::VarDeclStmtContext *ctx) = 0;
  virtual void exitVarDeclStmt(HelloParser::VarDeclStmtContext *ctx) = 0;

  virtual void enterIfStmt(HelloParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(HelloParser::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(HelloParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(HelloParser::WhileStmtContext *ctx) = 0;

  virtual void enterRepeatStmt(HelloParser::RepeatStmtContext *ctx) = 0;
  virtual void exitRepeatStmt(HelloParser::RepeatStmtContext *ctx) = 0;

  virtual void enterBreakStmt(HelloParser::BreakStmtContext *ctx) = 0;
  virtual void exitBreakStmt(HelloParser::BreakStmtContext *ctx) = 0;

  virtual void enterReturnStmt(HelloParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(HelloParser::ReturnStmtContext *ctx) = 0;

  virtual void enterExprStmt(HelloParser::ExprStmtContext *ctx) = 0;
  virtual void exitExprStmt(HelloParser::ExprStmtContext *ctx) = 0;

  virtual void enterSimpleExpr(HelloParser::SimpleExprContext *ctx) = 0;
  virtual void exitSimpleExpr(HelloParser::SimpleExprContext *ctx) = 0;

  virtual void enterUnaryExpr(HelloParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(HelloParser::UnaryExprContext *ctx) = 0;

  virtual void enterAddExpr(HelloParser::AddExprContext *ctx) = 0;
  virtual void exitAddExpr(HelloParser::AddExprContext *ctx) = 0;

  virtual void enterMulExpr(HelloParser::MulExprContext *ctx) = 0;
  virtual void exitMulExpr(HelloParser::MulExprContext *ctx) = 0;

  virtual void enterOrExpr(HelloParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(HelloParser::OrExprContext *ctx) = 0;

  virtual void enterAssignExpr(HelloParser::AssignExprContext *ctx) = 0;
  virtual void exitAssignExpr(HelloParser::AssignExprContext *ctx) = 0;

  virtual void enterAndExpr(HelloParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(HelloParser::AndExprContext *ctx) = 0;

  virtual void enterCmpExpr(HelloParser::CmpExprContext *ctx) = 0;
  virtual void exitCmpExpr(HelloParser::CmpExprContext *ctx) = 0;

  virtual void enterCmpOp(HelloParser::CmpOpContext *ctx) = 0;
  virtual void exitCmpOp(HelloParser::CmpOpContext *ctx) = 0;

  virtual void enterAddOp(HelloParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(HelloParser::AddOpContext *ctx) = 0;

  virtual void enterMulOp(HelloParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(HelloParser::MulOpContext *ctx) = 0;

  virtual void enterUnaryOp(HelloParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(HelloParser::UnaryOpContext *ctx) = 0;

  virtual void enterIndexExpr(HelloParser::IndexExprContext *ctx) = 0;
  virtual void exitIndexExpr(HelloParser::IndexExprContext *ctx) = 0;

  virtual void enterLiteralExpr(HelloParser::LiteralExprContext *ctx) = 0;
  virtual void exitLiteralExpr(HelloParser::LiteralExprContext *ctx) = 0;

  virtual void enterCallExpr(HelloParser::CallExprContext *ctx) = 0;
  virtual void exitCallExpr(HelloParser::CallExprContext *ctx) = 0;

  virtual void enterParenExpr(HelloParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(HelloParser::ParenExprContext *ctx) = 0;

  virtual void enterIdExpr(HelloParser::IdExprContext *ctx) = 0;
  virtual void exitIdExpr(HelloParser::IdExprContext *ctx) = 0;

  virtual void enterExprList(HelloParser::ExprListContext *ctx) = 0;
  virtual void exitExprList(HelloParser::ExprListContext *ctx) = 0;

  virtual void enterLiteral(HelloParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(HelloParser::LiteralContext *ctx) = 0;


};

