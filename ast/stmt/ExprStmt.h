#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>

class ExprStmt : public Stmt {
  public:
    ExprStmt(std::shared_ptr<CompilerContext> cc, Expr *expr)
        : Stmt(cc), expr(expr) {
        name = "expr_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
    std::unique_ptr<ASTResult> execute() { return expr->execute(); }

  private:
    Expr *expr;
};