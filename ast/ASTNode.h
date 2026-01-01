#pragma once

#include "ast/CompilerContext.h"
#include "ast/Const.h"
#include <memory>
#include <string>

// TODO 在增加类型系统的时候修改为模板类
struct ASTResult {
    double val;
    ControlSignal signal;
    ASTResult(double val, ControlSignal signal = ControlSignal::Normal)
        : val(val), signal(signal) {}
};

class ASTNode {
  public:
    ASTNode() : result(0) {}
    virtual ~ASTNode() = default;
    virtual void print(std::string prefix = "") = 0;
    virtual ASTResult execute([[maybe_unused]] CompilerContext &ctx) = 0;

  protected:
    std::string name;
    ASTResult result;

  private:
};
