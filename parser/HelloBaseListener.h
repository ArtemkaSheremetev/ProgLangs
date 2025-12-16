
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

  virtual void enterFuncSignature(HelloParser::FuncSignatureContext * /*ctx*/) override { }
  virtual void exitFuncSignature(HelloParser::FuncSignatureContext * /*ctx*/) override { }

  virtual void enterArgList(HelloParser::ArgListContext * /*ctx*/) override { }
  virtual void exitArgList(HelloParser::ArgListContext * /*ctx*/) override { }

  virtual void enterArgDef(HelloParser::ArgDefContext * /*ctx*/) override { }
  virtual void exitArgDef(HelloParser::ArgDefContext * /*ctx*/) override { }

  virtual void enterBody(HelloParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(HelloParser::BodyContext * /*ctx*/) override { }

  virtual void enterVarDeclList(HelloParser::VarDeclListContext * /*ctx*/) override { }
  virtual void exitVarDeclList(HelloParser::VarDeclListContext * /*ctx*/) override { }

  virtual void enterStatementBlock(HelloParser::StatementBlockContext * /*ctx*/) override { }
  virtual void exitStatementBlock(HelloParser::StatementBlockContext * /*ctx*/) override { }

  virtual void enterStatement(HelloParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(HelloParser::StatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(HelloParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(HelloParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(HelloParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(HelloParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterDoStatement(HelloParser::DoStatementContext * /*ctx*/) override { }
  virtual void exitDoStatement(HelloParser::DoStatementContext * /*ctx*/) override { }

  virtual void enterExprStatement(HelloParser::ExprStatementContext * /*ctx*/) override { }
  virtual void exitExprStatement(HelloParser::ExprStatementContext * /*ctx*/) override { }

  virtual void enterExpr(HelloParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(HelloParser::ExprContext * /*ctx*/) override { }

  virtual void enterAssignExpr(HelloParser::AssignExprContext * /*ctx*/) override { }
  virtual void exitAssignExpr(HelloParser::AssignExprContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpr(HelloParser::LogicalOrExprContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpr(HelloParser::LogicalOrExprContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpr(HelloParser::LogicalAndExprContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpr(HelloParser::LogicalAndExprContext * /*ctx*/) override { }

  virtual void enterCompareExpr(HelloParser::CompareExprContext * /*ctx*/) override { }
  virtual void exitCompareExpr(HelloParser::CompareExprContext * /*ctx*/) override { }

  virtual void enterAddSubExpr(HelloParser::AddSubExprContext * /*ctx*/) override { }
  virtual void exitAddSubExpr(HelloParser::AddSubExprContext * /*ctx*/) override { }

  virtual void enterMulDivExpr(HelloParser::MulDivExprContext * /*ctx*/) override { }
  virtual void exitMulDivExpr(HelloParser::MulDivExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(HelloParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(HelloParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterCallExpr(HelloParser::CallExprContext * /*ctx*/) override { }
  virtual void exitCallExpr(HelloParser::CallExprContext * /*ctx*/) override { }

  virtual void enterPrimaryExpr(HelloParser::PrimaryExprContext * /*ctx*/) override { }
  virtual void exitPrimaryExpr(HelloParser::PrimaryExprContext * /*ctx*/) override { }

  virtual void enterExprList(HelloParser::ExprListContext * /*ctx*/) override { }
  virtual void exitExprList(HelloParser::ExprListContext * /*ctx*/) override { }

  virtual void enterTypeRef(HelloParser::TypeRefContext * /*ctx*/) override { }
  virtual void exitTypeRef(HelloParser::TypeRefContext * /*ctx*/) override { }

  virtual void enterBuiltinType(HelloParser::BuiltinTypeContext * /*ctx*/) override { }
  virtual void exitBuiltinType(HelloParser::BuiltinTypeContext * /*ctx*/) override { }

  virtual void enterLiteral(HelloParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(HelloParser::LiteralContext * /*ctx*/) override { }

  virtual void enterIdentifier(HelloParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(HelloParser::IdentifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

