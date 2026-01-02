#pragma once
#include "ast/expr/Expr.h"

class BinaryExpr : public Expr {
  public:
    BinaryExpr(char op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    char op;
    std::unique_ptr<Expr> lhs;
    std::unique_ptr<Expr> rhs;
    Variable cal(Variable lnum, Variable rnum);
};