#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>
#include <string>

class VariableExpr : public Expr {
  public:
    VariableExpr(std::string var) : Expr(), var(var) { name = "variable_expr"; }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << var << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
    }
    ASTResult execute(CompilerContext &ctx) {
        result = ASTResult(ctx.getVar(var));
        return result;
    }

  private:
    std::string var;
};