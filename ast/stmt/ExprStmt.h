#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>

class ExprStmt : public Stmt {
  public:
    ExprStmt(std::unique_ptr<Expr> expr) : Stmt(), expr(std::move(expr)) {
        name = "expr_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) { return expr->execute(ctx); }

  private:
    std::unique_ptr<Expr> expr;
};