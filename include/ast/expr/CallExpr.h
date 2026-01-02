#pragma once
#include "ast/expr/Expr.h"

class CallExpr : public Expr {
  public:
    CallExpr(std::string funcName, std::unique_ptr<Expr> param);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::string funcName;
    std::unique_ptr<Expr> param;
};