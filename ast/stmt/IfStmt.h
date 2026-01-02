#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <cmath>
#include <iostream>
#include <string>

class IfStmt : public Stmt {
  public:
    // 单参数 单expr内容
    // 函数定义的 expr 需要允许 context 访问，因此定义为 shared ptr
    IfStmt(std::unique_ptr<Expr> ifExpr, std::unique_ptr<Stmt> ifStmt,
           std::unique_ptr<Stmt> elseStmt)
        : Stmt(), ifExpr(std::move(ifExpr)), ifStmt(std::move(ifStmt)),
          elseStmt(std::move(elseStmt)) {
        name = "if_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
        prefix += TAB;
        ifExpr->print(prefix);
        ifStmt->print(prefix);
        if (elseStmt) {
            elseStmt->print(prefix);
        }
    }
    // 需要传递expr给context，因此使用shared_ptr
    ASTResult execute(CompilerContext &ctx) {
        auto ifParam = ifExpr->execute(ctx);
        if (abs(ifParam.val.asNumber()) >= 1e-6) { // TODO 增加类型时修改
            result = ifStmt->execute(ctx);
        } else if (elseStmt) {
            result = elseStmt->execute(ctx);
        }
        return result;
    }

  private:
    std::unique_ptr<Expr> ifExpr;
    std::unique_ptr<Stmt> ifStmt;
    std::unique_ptr<Stmt> elseStmt;
};