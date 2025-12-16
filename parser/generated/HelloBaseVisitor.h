
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

  virtual std::any visitParamList(HelloParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(HelloParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(HelloParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(HelloParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeRef(HelloParser::TypeRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBuiltinType(HelloParser::BuiltinTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommaList(HelloParser::CommaListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStmt(HelloParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDeclStmt(HelloParser::VarDeclStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(HelloParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(HelloParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRepeatStmt(HelloParser::RepeatStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(HelloParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(HelloParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(HelloParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleExpr(HelloParser::SimpleExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(HelloParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpr(HelloParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExpr(HelloParser::MulExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(HelloParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(HelloParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(HelloParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCmpExpr(HelloParser::CmpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCmpOp(HelloParser::CmpOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddOp(HelloParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulOp(HelloParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(HelloParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexExpr(HelloParser::IndexExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralExpr(HelloParser::LiteralExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallExpr(HelloParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(HelloParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdExpr(HelloParser::IdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprList(HelloParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(HelloParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

