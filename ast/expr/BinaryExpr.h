#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>

class BinaryExpr : public Expr {
  public:
    BinaryExpr(char op, Expr *lhs, Expr *rhs) : op(op), lhs(lhs), rhs(rhs) {
        name = "binary_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << op << std::endl;
        prefix += TAB;
        lhs->print(prefix);
        rhs->print(prefix);
    }

  private:
    char op;
    Expr *lhs;
    Expr *rhs;
};