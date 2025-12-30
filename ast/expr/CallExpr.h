#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>
#include <string>

class CallExpr : public Expr {
  public:
    CallExpr(std::shared_ptr<CompilerContext> cc, std::string funcName,
             Expr *parm)
        : Expr(cc), funcName(funcName), parm(parm) {
        name = "call_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << funcName << std::endl;
        prefix += TAB;
        parm->print(prefix);
    }
    std::unique_ptr<ASTResult> execute() {
        // 获取参数表达式的结果
        auto parmRes = parm->execute();
        // 将参数带入函数体
        auto funcDef = cc->getFunc(funcName);
        VarDef varDef = {funcDef->param, parmRes->getVal()};
        cc->setVar(varDef);
        return funcDef->body->execute();
    }

  private:
    std::string funcName;
    Expr *parm;
};