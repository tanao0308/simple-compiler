#include "ast/expr/NumberExpr.h"
#include "ast/Const.h"
#include <iostream>

NumberExpr::NumberExpr(Variable num) : Expr(), num(num) {
    name = "number_expr";
}
void NumberExpr::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << num << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
}
ASTResult NumberExpr::execute(CompilerContext &ctx) {
    result = ASTResult(num);
    return result;
}