#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <cmath>
#include <iostream>

class BinaryExpr : public Expr {
  public:
    BinaryExpr(char op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
        : Expr(), op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {
        name = "binary_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << op << std::endl;
        prefix += TAB;
        lhs->print(prefix);
        rhs->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        auto res = ASTResult(0);
        res.setVal(cal(lhs->execute(ctx).getVal(), rhs->execute(ctx).getVal()));
        return res;
    }

  private:
    char op;
    std::unique_ptr<Expr> lhs;
    std::unique_ptr<Expr> rhs;
    double cal(double lnum, double rnum) {
        switch (op) {
            case '+':
                return lnum + rnum;
            case '-':
                return lnum - rnum;
            case '*':
                return lnum * rnum;
            case '/':
                return lnum / rnum;
            case '^':
                return pow(lnum, rnum);
        }
    }
};