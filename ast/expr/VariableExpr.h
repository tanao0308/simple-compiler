#pragma once
#include <string>
#include <iostream>
#include "ast/Const.h"
#include "ast/expr/Expr.h"

class VariableExpr : public Expr {
public:
    VariableExpr(std::string var)
        : var(var) {
        name = "variable_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << var << std::endl;
    }
private:
    std::string var;
};