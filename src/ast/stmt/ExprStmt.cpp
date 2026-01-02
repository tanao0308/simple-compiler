#include "ast/stmt/ExprStmt.h"

#include <iostream>

#include "ast/Const.h"

ExprStmt::ExprStmt(std::unique_ptr<Expr> expr) : Stmt(), expr(std::move(expr)) { name = "expr_stmt"; }
void ExprStmt::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    expr->print(prefix);
}
ASTResult ExprStmt::execute(CompilerContext &ctx) {
    result = expr->execute(ctx);
    return result;
}