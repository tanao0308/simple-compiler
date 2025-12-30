#pragma once

#include "ast/CompilerContext.h"
#include "ast/program/Program.h"

class Compiler {
  public:
    Compiler() : cc(std::make_shared<CompilerContext>()), root(nullptr) {}
    void setRoot(std::shared_ptr<Program> program) { root = program; }
    std::shared_ptr<CompilerContext> getCc() { return cc; }
    void print() { root->print(); }
    std::unique_ptr<ASTResult> execute() { return root->execute(); }

  private:
    std::shared_ptr<CompilerContext> cc;
    std::shared_ptr<Program> root;
};