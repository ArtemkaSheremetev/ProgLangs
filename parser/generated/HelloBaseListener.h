
// Generated from Hello.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "HelloListener.h"


/**
 * This class provides an empty implementation of HelloListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  HelloBaseListener : public HelloListener {
public:

  virtual void enterSource(HelloParser::SourceContext * /*ctx*/) override { }
  virtual void exitSource(HelloParser::SourceContext * /*ctx*/) override { }

  virtual void enterSourceItem(HelloParser::SourceItemContext * /*ctx*/) override { }
  virtual void exitSourceItem(HelloParser::SourceItemContext * /*ctx*/) override { }

  virtual void enterFuncDef(HelloParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(HelloParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterParamList(HelloParser::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(HelloParser::ParamListContext * /*ctx*/) override { }

  virtual void enterParam(HelloParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(HelloParser::ParamContext * /*ctx*/) override { }

  virtual void enterBody(HelloParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(HelloParser::BodyContext * /*ctx*/) override { }

  virtual void enterBlock(HelloParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(HelloParser::BlockContext * /*ctx*/) override { }

  virtual void enterTypeRef(HelloParser::TypeRefContext * /*ctx*/) override { }
  virtual void exitTypeRef(HelloParser::TypeRefContext * /*ctx*/) override { }

  virtual void enterBuiltinType(HelloParser::BuiltinTypeContext * /*ctx*/) override { }
  virtual void exitBuiltinType(HelloParser::BuiltinTypeContext * /*ctx*/) override { }

  virtual void enterCommaList(HelloParser::CommaListContext * /*ctx*/) override { }
  virtual void exitCommaList(HelloParser::CommaListContext * /*ctx*/) override { }

  virtual void enterBlockStmt(HelloParser::BlockStmtContext * /*ctx*/) override { }
  virtual void exitBlockStmt(HelloParser::BlockStmtContext * /*ctx*/) override { }

  virtual void enterVarDeclStmt(HelloParser::VarDeclStmtContext * /*ctx*/) override { }
  virtual void exitVarDeclStmt(HelloParser::VarDeclStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(HelloParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(HelloParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(HelloParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(HelloParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterRepeatStmt(HelloParser::RepeatStmtContext * /*ctx*/) override { }
  virtual void exitRepeatStmt(HelloParser::RepeatStmtContext * /*ctx*/) override { }

  virtual void enterBreakStmt(HelloParser::BreakStmtContext * /*ctx*/) override { }
  virtual void exitBreakStmt(HelloParser::BreakStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(HelloParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(HelloParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterExprStmt(HelloParser::ExprStmtContext * /*ctx*/) override { }
  virtual void exitExprStmt(HelloParser::ExprStmtContext * /*ctx*/) override { }

  virtual void enterSimpleExpr(HelloParser::SimpleExprContext * /*ctx*/) override { }
  virtual void exitSimpleExpr(HelloParser::SimpleExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(HelloParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(HelloParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterAddExpr(HelloParser::AddExprContext * /*ctx*/) override { }
  virtual void exitAddExpr(HelloParser::AddExprContext * /*ctx*/) override { }

  virtual void enterMulExpr(HelloParser::MulExprContext * /*ctx*/) override { }
  virtual void exitMulExpr(HelloParser::MulExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(HelloParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(HelloParser::OrExprContext * /*ctx*/) override { }

  virtual void enterAssignExpr(HelloParser::AssignExprContext * /*ctx*/) override { }
  virtual void exitAssignExpr(HelloParser::AssignExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(HelloParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(HelloParser::AndExprContext * /*ctx*/) override { }

  virtual void enterCmpExpr(HelloParser::CmpExprContext * /*ctx*/) override { }
  virtual void exitCmpExpr(HelloParser::CmpExprContext * /*ctx*/) override { }

  virtual void enterCmpOp(HelloParser::CmpOpContext * /*ctx*/) override { }
  virtual void exitCmpOp(HelloParser::CmpOpContext * /*ctx*/) override { }

  virtual void enterAddOp(HelloParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(HelloParser::AddOpContext * /*ctx*/) override { }

  virtual void enterMulOp(HelloParser::MulOpContext * /*ctx*/) override { }
  virtual void exitMulOp(HelloParser::MulOpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(HelloParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(HelloParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterIndexExpr(HelloParser::IndexExprContext * /*ctx*/) override { }
  virtual void exitIndexExpr(HelloParser::IndexExprContext * /*ctx*/) override { }

  virtual void enterLiteralExpr(HelloParser::LiteralExprContext * /*ctx*/) override { }
  virtual void exitLiteralExpr(HelloParser::LiteralExprContext * /*ctx*/) override { }

  virtual void enterCallExpr(HelloParser::CallExprContext * /*ctx*/) override { }
  virtual void exitCallExpr(HelloParser::CallExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(HelloParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(HelloParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterIdExpr(HelloParser::IdExprContext * /*ctx*/) override { }
  virtual void exitIdExpr(HelloParser::IdExprContext * /*ctx*/) override { }

  virtual void enterExprList(HelloParser::ExprListContext * /*ctx*/) override { }
  virtual void exitExprList(HelloParser::ExprListContext * /*ctx*/) override { }

  virtual void enterLiteral(HelloParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(HelloParser::LiteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

