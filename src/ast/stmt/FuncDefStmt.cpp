#include "ast/stmt/FuncDefStmt.h"
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>
#include <string>

FuncDefStmt::FuncDefStmt(std::string func, std::string param,
                         std::unique_ptr<Stmt> stmt)
    : Stmt(), func(func), param(param), stmt(std::move(stmt)) {
    name = "func_def_stmt";
}
void FuncDefStmt::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << func << "(" << param << ") "
              << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    stmt->print(prefix);
}
ASTResult FuncDefStmt::execute(CompilerContext &ctx) {
    ctx.setFunc(Function(func, param, stmt));
    result = ASTResult(Variable());
    return result;
}