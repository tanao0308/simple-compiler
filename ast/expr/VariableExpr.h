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
        std::cout << var << " | " << result.val << std::endl;
    }
    ASTResult execute(CompilerContext &ctx) {
        result = ASTResult(ctx.getVar(var)->val);
        return result;
    }

  private:
    std::string var;
};