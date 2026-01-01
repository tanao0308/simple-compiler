#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>
#include <string>

class VariableExpr : public Expr {
  public:
    VariableExpr(std::string var) : Expr(), var(var) { name = "variable_expr"; }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << var << std::endl;
    }
    ASTResult execute(CompilerContext &ctx) {
        auto res = ASTResult(ctx.getVar(var)->val);
        return res;
    }

  private:
    std::string var;
};