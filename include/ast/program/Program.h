#pragma once
#include "ast/ASTNode.h"

class Program : public ASTNode {
  public:
    // 要转移 vector<unique ptr> 也需要 move
    Program(std::vector<std::unique_ptr<Stmt>> &&stmts);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::vector<std::unique_ptr<Stmt>> stmts;
};