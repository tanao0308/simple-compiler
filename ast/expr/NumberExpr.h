#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>

class NumberExpr : public Expr {
  public:
    NumberExpr(Variable num) : Expr(), num(num) { name = "number_expr"; }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << num << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
    }
    ASTResult execute(CompilerContext &ctx) {
        result = ASTResult(num);
        return result;
    }

  private:
    Variable num;
};