#include "ast/expr/VariableExpr.h"

#include <iostream>
#include <string>

#include "ast/Const.h"

VariableExpr::VariableExpr(std::string var) : Expr(), var(var) { name = "variable_expr"; }
void VariableExpr::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << var << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
}
ASTResult VariableExpr::execute(CompilerContext &ctx) {
    result = ASTResult(ctx.getVar(var));
    return result;
}