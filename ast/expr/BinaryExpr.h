#pragma once
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <cmath>
#include <iostream>

class BinaryExpr : public Expr {
  public:
    BinaryExpr(std::shared_ptr<CompilerContext> cc, char op, Expr *lhs,
               Expr *rhs)
        : Expr(cc), op(op), lhs(lhs), rhs(rhs) {
        name = "binary_expr";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << " " << op << std::endl;
        prefix += TAB;
        lhs->print(prefix);
        rhs->print(prefix);
    }
    std::unique_ptr<ASTResult> execute() {
        auto res = std::make_unique<ASTResult>(0);
        res->setVal(cal(lhs->execute()->getVal(), lhs->execute()->getVal()));
        return res;
    }

  private:
    char op;
    Expr *lhs;
    Expr *rhs;
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