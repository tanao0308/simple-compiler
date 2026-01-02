#pragma once

#include "ast/CompilerContext.h"
#include "ast/Const.h"
#include "ast/Type.h"
#include <memory>
#include <string>

struct ASTResult {
    Variable val;
    ControlSignal signal;
    ASTResult(Variable val, ControlSignal signal = ControlSignal::Normal)
        : val(val), signal(signal) {}
    void print() { std::cout << val; }
};

class ASTNode {
  public:
    ASTNode() : result(Variable()) {}
    virtual ~ASTNode() = default;
    virtual void print(std::string prefix = "") = 0;
    virtual ASTResult execute(CompilerContext &ctx) = 0;

  protected:
    std::string name;
    ASTResult result;

  private:
};
