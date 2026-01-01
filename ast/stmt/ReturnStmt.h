#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>

class ReturnStmt : public Stmt {
  public:
    ReturnStmt(std::unique_ptr<Expr> expr) : Stmt(), expr(std::move(expr)) {
        name = "return_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << " | " << result.val << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        result = expr->execute(ctx);
        result.signal = ControlSignal::Return;
        return result;
    }

  private:
    std::unique_ptr<Expr> expr;
};