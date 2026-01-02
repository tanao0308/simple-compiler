#include "ast/stmt/WhileStmt.h"

#include <cmath>
#include <iostream>
#include <string>

#include "ast/Const.h"

WhileStmt::WhileStmt(std::unique_ptr<Expr> whileExpr, std::unique_ptr<Stmt> whileStmt)
    : Stmt(), whileExpr(std::move(whileExpr)), whileStmt(std::move(whileStmt)) {
    name = "while_stmt";
}
void WhileStmt::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    whileExpr->print(prefix);
    whileStmt->print(prefix);
}
ASTResult WhileStmt::execute(CompilerContext &ctx) {
    auto whileParam = whileExpr->execute(ctx);
    while (abs(whileParam.val.asNumber()) >= 1e-6) {
        result = whileStmt->execute(ctx);
        whileParam = whileExpr->execute(ctx);
    }
    return result;
}