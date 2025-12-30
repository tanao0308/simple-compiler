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
    ASTNode(std::shared_ptr<CompilerContext> cc) : cc(cc) {}
    virtual ~ASTNode() = default;
    virtual void print(std::string prefix = "") = 0;
    virtual std::unique_ptr<ASTResult> execute() = 0;

  protected:
    std::shared_ptr<CompilerContext> cc;
    std::string name;

  private:
};
