#pragma once
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"

class ExprStmt : public Stmt {
  public:
    ExprStmt(std::unique_ptr<Expr> expr);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::unique_ptr<Expr> expr;
};