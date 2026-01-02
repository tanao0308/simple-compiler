#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <cmath>
#include <iostream>
#include <string>

class WhileStmt : public Stmt {
  public:
    // 单参数 单expr内容
    // 函数定义的 expr 需要允许 context 访问，因此定义为 shared ptr
    WhileStmt(std::unique_ptr<Expr> whileExpr, std::unique_ptr<Stmt> whileStmt)
        : Stmt(), whileExpr(std::move(whileExpr)),
          whileStmt(std::move(whileStmt)) {
        name = "while_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
        prefix += TAB;
        whileExpr->print(prefix);
        whileStmt->print(prefix);
    }
    // 需要传递expr给context，因此使用shared_ptr
    ASTResult execute(CompilerContext &ctx) {
        auto whileParam = whileExpr->execute(ctx);
        while (abs(whileParam.val.asNumber()) >= 1e-6) {
            result = whileStmt->execute(ctx);
            whileParam = whileExpr->execute(ctx);
        }
        return result;
    }

  private:
    std::unique_ptr<Expr> whileExpr;
    std::unique_ptr<Stmt> whileStmt;
};