#pragma once
#include "ast/stmt/Stmt.h"

class FuncDefStmt : public Stmt {
  public:
    // 单参数 单expr内容
    // 函数定义的 expr 需要允许 context 访问，因此定义为 shared ptr
    FuncDefStmt(std::string func, std::string param,
                std::unique_ptr<Stmt> stmt);
    void print(std::string prefix = "") override;
    // 需要传递expr给context，因此使用shared_ptr
    ASTResult execute(CompilerContext &ctx) override;

  private:
    std::string func;
    std::string param;
    std::shared_ptr<Stmt> stmt; // 需要传递给context
};