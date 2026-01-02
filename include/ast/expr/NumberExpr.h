#pragma once
#include "ast/expr/Expr.h"

class NumberExpr : public Expr {
  public:
    NumberExpr(Variable num);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    Variable num;
};