#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>

class NumberExpr : public Expr {
  public:
    NumberExpr(double num) : Expr(), num(num) { name = "number_expr"; }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << num << std::endl;
    }
    ASTResult execute(CompilerContext &ctx) {
        auto res = ASTResult(num);
        return res;
    }

  private:
    double num;
};