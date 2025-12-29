#pragma once
#include <string>
#include <iostream>
#include "ast/Const.h"
#include "ast/expr/Expr.h"

class CallExpr : public Expr {
public:
    CallExpr(std::string var, Expr* parm)
        : var(var), parm(parm) {
        name = "call_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << var << std::endl;
        prefix += TAB;
        parm->print(prefix);
    }
private:
    std::string var;
    Expr* parm;
};