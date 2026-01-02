#pragma once
#include "ast/CompilerContext.h"
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
        std::cout << prefix << "└───" << name << ": ";
        std::cout << op << ": ";
        std::cout << "[result]";
        result.print();
        std::cout << std::endl;
        prefix += TAB;
        lhs->print(prefix);
        rhs->print(prefix);
    }
    ASTResult execute(CompilerContext &ctx) {
        result = ASTResult(cal(lhs->execute(ctx).val, rhs->execute(ctx).val));
        return result;
    }

  private:
    char op;
    std::unique_ptr<Expr> lhs;
    std::unique_ptr<Expr> rhs;
    Variable cal(Variable lnum, Variable rnum) {
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
                return lnum ^ rnum;
        }
    }
};