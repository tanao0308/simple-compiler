#pragma once

#include "ast/CompilerContext.h"
#include "ast/program/Program.h"

class Compiler {
  public:
    Compiler() : ctx(), root(nullptr) {}
    void setRoot(std::unique_ptr<Program> program) {
        root = std::move(program);
    }
    // 只访问，返回引用
    // const CompilerContext& getCtx() { return *ctx; }
    void print() { root->print(); }
    ASTResult execute() { return root->execute(ctx); }

  private:
    CompilerContext ctx;
    std::unique_ptr<Program> root;
};