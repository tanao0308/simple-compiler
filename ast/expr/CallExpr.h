#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>
#include <string>

class CallExpr : public Expr {
  public:
    CallExpr(std::string funcName, std::unique_ptr<Expr> param)
        : Expr(), funcName(funcName), param(std::move(param)) {
        name = "call_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << "└───" << name << ": ";
        std::cout << funcName << " | " << result.val << std::endl;
        prefix += TAB;
        param->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        // 将参数带入函数体
        auto func = ctx.getFunc(funcName);
        if (!func) {
            // 符号表找不到 func
            return ASTResult(0);
        }
        // 获取参数表达式的结果
        auto paramRes = param->execute(ctx);
        ctx.setVar(VarDef(func->param, paramRes.val));
        result = func->body->execute(ctx);
        return result;
    }

  private:
    std::string funcName;
    std::unique_ptr<Expr> param;
};