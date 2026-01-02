#include "ast/stmt/VarDefStmt.h"

#include "ast/Const.h"
#include <iostream>
VarDefStmt::VarDefStmt(std::string var, std::unique_ptr<Expr> expr)
    : Stmt(), var(var), expr(std::move(expr)) {
    name = "var_def_stmt";
}
void VarDefStmt::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << var << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    expr->print(prefix);
}
ASTResult VarDefStmt::execute(CompilerContext &ctx) {
    ctx.setVar(var, expr->execute(ctx).val);
    return result = ASTResult(Variable());
}