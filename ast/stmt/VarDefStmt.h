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
        std::cout << var << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        ctx.setVar(var, expr->execute(ctx).val);
        return result = ASTResult(Variable());
    }

  private:
    std::string var;
    std::unique_ptr<Expr> expr;
};