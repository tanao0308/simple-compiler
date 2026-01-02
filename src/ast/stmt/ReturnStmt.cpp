#include "ast/stmt/ReturnStmt.h"

#include <iostream>

#include "ast/Const.h"

ReturnStmt::ReturnStmt(std::unique_ptr<Expr> expr) : Stmt(), expr(std::move(expr)) { name = "return_stmt"; }
void ReturnStmt::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;

    prefix += TAB;
    expr->print(prefix);
}
ASTResult ReturnStmt::execute(CompilerContext &ctx) {
    result = expr->execute(ctx);
    result.signal = ControlSignal::Return;
    return result;
}