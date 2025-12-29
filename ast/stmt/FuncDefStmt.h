#pragma once
#include <string>
#include <iostream>
#include "ast/Const.h"
#include "ast/stmt/Stmt.h"
#include "ast/expr/Expr.h"

class FuncDefStmt : public Stmt {
public:
    // 单参数 单expr内容
    FuncDefStmt(std::string func, std::string parm, Expr* expr):
        func(func), parm(parm), expr(expr) {
        name = "func_def_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << func << "(" << parm << ")" << name << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
private:
    std::string func;
    std::string parm;
    Expr* expr;
};