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
        std::cout << funcName << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
        prefix += TAB;
        param->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        // 将参数带入函数体
        auto func = ctx.getFunc(funcName);
        if (!func) {
            throw std::runtime_error("符号表未找到函数");
        }
        // 获取参数表达式的结果
        auto paramRes = param->execute(ctx);
        ctx.pushScope(); // 先嵌套作用域，再设置参数
        ctx.setVar(func->param, Variable(paramRes.val));
        result = func->body->execute(ctx);
        ctx.popScope();
        return result;
    }

  private:
    std::string funcName;
    std::unique_ptr<Expr> param;
};