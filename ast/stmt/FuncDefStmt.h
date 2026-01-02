#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>
#include <string>

class FuncDefStmt : public Stmt {
  public:
    // 单参数 单expr内容
    // 函数定义的 expr 需要允许 context 访问，因此定义为 shared ptr
    FuncDefStmt(std::string func, std::string param, std::unique_ptr<Stmt> stmt)
        : Stmt(), func(func), param(param), stmt(std::move(stmt)) {
        name = "func_def_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << func << "(" << param << ") "
                  << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
        prefix += TAB;
        stmt->print(prefix);
    }
    // 需要传递expr给context，因此使用shared_ptr
    ASTResult execute(CompilerContext &ctx) {
        ctx.setFunc(Function(func, param, stmt));
        result = ASTResult(Variable());
        return result;
    }

  private:
    std::string func;
    std::string param;
    std::shared_ptr<Stmt> stmt; // 需要传递给context
};