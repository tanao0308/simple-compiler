#pragma once

#include "ast/CompilerContext.h"
#include <memory>
#include <string>

class ASTVisitor;

class ASTResult {
  public:
    ASTResult(double val) : val(val) {}
    double getVal() { return val; }
    void setVal(double curVal) { val = curVal; }

  private:
    double val;
};

class ASTNode {
  public:
    ASTNode() {}
    virtual ~ASTNode() = default;
    virtual void print(std::string prefix = "") = 0;
    virtual ASTResult execute([[maybe_unused]] CompilerContext &ctx) = 0;

  protected:
    std::string name;

  private:
};
