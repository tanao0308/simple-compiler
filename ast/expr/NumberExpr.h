#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>

class NumberExpr : public Expr {
  public:
    NumberExpr(double num) : num(num) { name = "number_expr"; }
    void print(std::string prefix = "") override {
        std::cout << prefix << " " << name << " " << num << std::endl;
    }

  private:
    double num;
};