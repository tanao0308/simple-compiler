#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>
#include <string>

class FuncDefStmt : public Stmt {
  public:
    // 单参数 单expr内容
    FuncDefStmt(std::shared_ptr<CompilerContext> cc, std::string func,
                std::string parm, Expr *expr)
        : Stmt(cc), func(func), parm(parm), expr(expr) {
        name = "func_def_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << func << "(" << parm << ") " << name << std::endl;
        prefix += TAB;
        expr->print(prefix);
    }

  private:
    std::string func;
    std::string parm;
    Expr *expr;
};