#pragma once
#include <iostream>
#include "ast/Const.h"
#include "ast/stmt/Stmt.h"
#include "ast/expr/Expr.h"

class ExprStmt : public Stmt {
public:
    ExprStmt(Expr* expr): expr(expr) {
        name = "expr_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
private:
    Expr* expr;
};