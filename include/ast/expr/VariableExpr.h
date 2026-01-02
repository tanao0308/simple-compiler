#pragma once
#include "ast/expr/Expr.h"

class VariableExpr : public Expr {
  public:
    VariableExpr(std::string var);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::string var;
};