#pragma once
#include "ast/ASTNode.h"

class Expr : public ASTNode {
  public:
    Expr(std::shared_ptr<CompilerContext> cc) : ASTNode(cc) {}
};