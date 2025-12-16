
// Generated from Hello.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "HelloVisitor.h"


/**
 * This class provides an empty implementation of HelloVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  HelloBaseVisitor : public HelloVisitor {
public:

  virtual std::any visitSource(HelloParser::SourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSourceItem(HelloParser::SourceItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(HelloParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncSignature(HelloParser::FuncSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgList(HelloParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgDef(HelloParser::ArgDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(HelloParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDeclList(HelloParser::VarDeclListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementBlock(HelloParser::StatementBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(HelloParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(HelloParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(HelloParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoStatement(HelloParser::DoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStatement(HelloParser::ExprStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(HelloParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(HelloParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOrExpr(HelloParser::LogicalOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAndExpr(HelloParser::LogicalAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompareExpr(HelloParser::CompareExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSubExpr(HelloParser::AddSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDivExpr(HelloParser::MulDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(HelloParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallExpr(HelloParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpr(HelloParser::PrimaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprList(HelloParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeRef(HelloParser::TypeRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBuiltinType(HelloParser::BuiltinTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(HelloParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(HelloParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }


};

