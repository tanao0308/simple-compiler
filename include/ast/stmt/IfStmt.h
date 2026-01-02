#pragma once
#include "ast/expr/Expr.h"
#include "ast/stmt/Stmt.h"

class IfStmt : public Stmt {
  public:
    // 单参数 单expr内容
    // 函数定义的 expr 需要允许 context 访问，因此定义为 shared ptr
    IfStmt(std::unique_ptr<Expr> ifExpr, std::unique_ptr<Stmt> ifStmt,
           std::unique_ptr<Stmt> elseStmt);
    void print(std::string prefix = "") override;
    // 需要传递expr给context，因此使用shared_ptr
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::unique_ptr<Expr> ifExpr;
    std::unique_ptr<Stmt> ifStmt;
    std::unique_ptr<Stmt> elseStmt;
};