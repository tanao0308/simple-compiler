#pragma once
#include "ast/ASTNode.h"
#include "ast/Const.h"
#include "ast/stmt/Stmt.h"
#include <iostream>
#include <vector>

class Program : public ASTNode {
  public:
    // 要转移 vector<unique ptr> 也需要 move
    Program(std::vector<std::unique_ptr<Stmt>> &&stmts)
        : ASTNode(), stmts(std::move(stmts)) {
        name = "program";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " | " << result.val << std::endl;
        prefix += TAB;
        for (auto &stmt : stmts) {
            stmt->print(prefix);
        }
    }
    ASTResult execute(CompilerContext &ctx) {
        for (auto &stmt : stmts) {
            stmt->execute(ctx);
        }
        auto var = ctx.getVar("result");
        if (!var) {
            // 符号表找不到 var
            return ASTResult(0);
        }
        result = ASTResult(var->val);
        return result;
    }

  private:
    std::vector<std::unique_ptr<Stmt>> stmts;
};