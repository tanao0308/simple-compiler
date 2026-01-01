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
        std::cout << prefix << "└───" << name << ": ";
        std::cout << var << " | " << result.val << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        ctx.setVar(VarDef(var, expr->execute(ctx).val));
        result = ASTResult(0);
        return result;
    }

  private:
    std::string var;
    std::unique_ptr<Expr> expr;
};