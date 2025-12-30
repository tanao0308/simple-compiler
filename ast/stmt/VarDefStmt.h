#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>

class VarDefStmt : public Stmt {
  public:
    VarDefStmt(std::string var, Expr *expr) : var(var), expr(expr) {
        name = "var_def_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << var << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }

  private:
    std::string var;
    Expr *expr;
};