#include "ast/expr/BinaryExpr.h"

#include <cmath>
#include <iostream>

#include "ast/CompilerContext.h"
#include "ast/Const.h"

BinaryExpr::BinaryExpr(char op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
    : Expr(), op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {
    name = "binary_expr";
}
void BinaryExpr::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << op << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    lhs->print(prefix);
    rhs->print(prefix);
}
ASTResult BinaryExpr::execute(CompilerContext &ctx) {
    result = ASTResult(cal(lhs->execute(ctx).val, rhs->execute(ctx).val));
    return result;
}
Variable BinaryExpr::cal(Variable lnum, Variable rnum) {
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