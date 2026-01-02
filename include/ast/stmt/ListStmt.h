#pragma once
#include "ast/stmt/Stmt.h"

class ListStmt : public Stmt {
  public:
    ListStmt(std::vector<std::unique_ptr<Stmt>> &&stmts);
    void print(std::string prefix = "") override;
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::vector<std::unique_ptr<Stmt>> stmts;
};