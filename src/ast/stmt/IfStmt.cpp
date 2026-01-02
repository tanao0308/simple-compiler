#include "ast/stmt/IfStmt.h"
#include "ast/Const.h"
#include <cmath>
#include <iostream>
#include <string>

IfStmt::IfStmt(std::unique_ptr<Expr> ifExpr, std::unique_ptr<Stmt> ifStmt,
               std::unique_ptr<Stmt> elseStmt)
    : Stmt(), ifExpr(std::move(ifExpr)), ifStmt(std::move(ifStmt)),
      elseStmt(std::move(elseStmt)) {
    name = "if_stmt";
}
void IfStmt::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    ifExpr->print(prefix);
    ifStmt->print(prefix);
    if (elseStmt) {
        elseStmt->print(prefix);
    }
}
ASTResult IfStmt::execute(CompilerContext &ctx) {
    auto ifParam = ifExpr->execute(ctx);
    if (abs(ifParam.val.asNumber()) >= 1e-6) { // TODO 增加类型时修改
        result = ifStmt->execute(ctx);
    } else if (elseStmt) {
        result = elseStmt->execute(ctx);
    }
    return result;
}