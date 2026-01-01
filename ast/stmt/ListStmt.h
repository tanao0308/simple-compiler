#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"
#include <iostream>

class ListStmt : public Stmt {
  public:
    ListStmt(std::vector<std::unique_ptr<Stmt>> &&stmts)
        : Stmt(), stmts(std::move(stmts)) {
        name = "list_stmt";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << " | " << result.val << std::endl;
        prefix += TAB;
        for (auto &stmt : stmts) {
            stmt->print(prefix);
        }
    }
    ASTResult execute(CompilerContext &ctx) {
        ASTResult res(0);
        for (auto &stmt : stmts) {
            res = stmt->execute(ctx);
            if (res.signal == ControlSignal::Return) {
                result = res;
                return result;
            }
        }
        // 无 return 的 list stmt
        return result = ASTResult(0);
    }

  private:
    std::vector<std::unique_ptr<Stmt>> stmts;
};