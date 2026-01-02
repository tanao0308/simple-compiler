#pragma once
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"

class VarDefStmt : public Stmt {
  public:
    VarDefStmt(std::string var, std::unique_ptr<Expr> expr);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::string var;
    std::unique_ptr<Expr> expr;
};