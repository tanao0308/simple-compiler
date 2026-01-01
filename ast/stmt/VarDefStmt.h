#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>

class VarDefStmt : public Stmt {
  public:
    VarDefStmt(std::string var, std::unique_ptr<Expr> expr)
        : Stmt(), var(var), expr(std::move(expr)) {
        name = "var_def_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << var << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        ctx.setVar({var, expr->execute(ctx).getVal()});
        return ASTResult(0);
    }

  private:
    std::string var;
    std::unique_ptr<Expr> expr;
};