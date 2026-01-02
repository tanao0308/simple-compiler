#include "ast/stmt/ListStmt.h"
#include "ast/Const.h"
#include "ast/expr/Expr.h"
#include <iostream>
ListStmt::ListStmt(std::vector<std::unique_ptr<Stmt>> &&stmts)
    : Stmt(), stmts(std::move(stmts)) {
    name = "list_stmt";
}
void ListStmt::print(std::string prefix) {
    std::cout << prefix << "└───" << name << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    for (auto &stmt : stmts) {
        stmt->print(prefix);
    }
}
ASTResult ListStmt::execute(CompilerContext &ctx) {
    for (auto &stmt : stmts) {
        ASTResult res = stmt->execute(ctx);
        if (res.signal == ControlSignal::Return) {
            result = res;
            return result;
        }
    }
    // 无 return 的 list stmt
    return result = ASTResult(Variable());
}