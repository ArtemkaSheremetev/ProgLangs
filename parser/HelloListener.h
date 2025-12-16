
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

  virtual void enterFuncSignature(HelloParser::FuncSignatureContext *ctx) = 0;
  virtual void exitFuncSignature(HelloParser::FuncSignatureContext *ctx) = 0;

  virtual void enterArgList(HelloParser::ArgListContext *ctx) = 0;
  virtual void exitArgList(HelloParser::ArgListContext *ctx) = 0;

  virtual void enterArgDef(HelloParser::ArgDefContext *ctx) = 0;
  virtual void exitArgDef(HelloParser::ArgDefContext *ctx) = 0;

  virtual void enterBody(HelloParser::BodyContext *ctx) = 0;
  virtual void exitBody(HelloParser::BodyContext *ctx) = 0;

  virtual void enterVarDeclList(HelloParser::VarDeclListContext *ctx) = 0;
  virtual void exitVarDeclList(HelloParser::VarDeclListContext *ctx) = 0;

  virtual void enterStatementBlock(HelloParser::StatementBlockContext *ctx) = 0;
  virtual void exitStatementBlock(HelloParser::StatementBlockContext *ctx) = 0;

  virtual void enterStatement(HelloParser::StatementContext *ctx) = 0;
  virtual void exitStatement(HelloParser::StatementContext *ctx) = 0;

  virtual void enterIfStatement(HelloParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(HelloParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(HelloParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(HelloParser::WhileStatementContext *ctx) = 0;

  virtual void enterDoStatement(HelloParser::DoStatementContext *ctx) = 0;
  virtual void exitDoStatement(HelloParser::DoStatementContext *ctx) = 0;

  virtual void enterExprStatement(HelloParser::ExprStatementContext *ctx) = 0;
  virtual void exitExprStatement(HelloParser::ExprStatementContext *ctx) = 0;

  virtual void enterExpr(HelloParser::ExprContext *ctx) = 0;
  virtual void exitExpr(HelloParser::ExprContext *ctx) = 0;

  virtual void enterAssignExpr(HelloParser::AssignExprContext *ctx) = 0;
  virtual void exitAssignExpr(HelloParser::AssignExprContext *ctx) = 0;

  virtual void enterLogicalOrExpr(HelloParser::LogicalOrExprContext *ctx) = 0;
  virtual void exitLogicalOrExpr(HelloParser::LogicalOrExprContext *ctx) = 0;

  virtual void enterLogicalAndExpr(HelloParser::LogicalAndExprContext *ctx) = 0;
  virtual void exitLogicalAndExpr(HelloParser::LogicalAndExprContext *ctx) = 0;

  virtual void enterCompareExpr(HelloParser::CompareExprContext *ctx) = 0;
  virtual void exitCompareExpr(HelloParser::CompareExprContext *ctx) = 0;

  virtual void enterAddSubExpr(HelloParser::AddSubExprContext *ctx) = 0;
  virtual void exitAddSubExpr(HelloParser::AddSubExprContext *ctx) = 0;

  virtual void enterMulDivExpr(HelloParser::MulDivExprContext *ctx) = 0;
  virtual void exitMulDivExpr(HelloParser::MulDivExprContext *ctx) = 0;

  virtual void enterUnaryExpr(HelloParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(HelloParser::UnaryExprContext *ctx) = 0;

  virtual void enterCallExpr(HelloParser::CallExprContext *ctx) = 0;
  virtual void exitCallExpr(HelloParser::CallExprContext *ctx) = 0;

  virtual void enterPrimaryExpr(HelloParser::PrimaryExprContext *ctx) = 0;
  virtual void exitPrimaryExpr(HelloParser::PrimaryExprContext *ctx) = 0;

  virtual void enterExprList(HelloParser::ExprListContext *ctx) = 0;
  virtual void exitExprList(HelloParser::ExprListContext *ctx) = 0;

  virtual void enterTypeRef(HelloParser::TypeRefContext *ctx) = 0;
  virtual void exitTypeRef(HelloParser::TypeRefContext *ctx) = 0;

  virtual void enterBuiltinType(HelloParser::BuiltinTypeContext *ctx) = 0;
  virtual void exitBuiltinType(HelloParser::BuiltinTypeContext *ctx) = 0;

  virtual void enterLiteral(HelloParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(HelloParser::LiteralContext *ctx) = 0;

  virtual void enterIdentifier(HelloParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(HelloParser::IdentifierContext *ctx) = 0;


};

