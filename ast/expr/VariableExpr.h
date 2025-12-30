#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>
#include <string>

class VariableExpr : public Expr {
  public:
    VariableExpr(std::shared_ptr<CompilerContext> cc, std::string var)
        : Expr(cc), var(var) {
        name = "variable_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << var << std::endl;
    }

  private:
    std::string var;
};