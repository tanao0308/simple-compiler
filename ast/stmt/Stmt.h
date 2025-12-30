#pragma once
#include "ast/ASTNode.h"

class Stmt : public ASTNode {
  public:
    Stmt(std::shared_ptr<CompilerContext> cc) : ASTNode(cc) {}
};