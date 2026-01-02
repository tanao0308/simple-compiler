#include "ast/program/Program.h"
#include "ast/ASTNode.h"
#include "ast/Const.h"
#include "ast/stmt/Stmt.h"
#include <iostream>
#include <vector>

Program::Program(std::vector<std::unique_ptr<Stmt>> &&stmts)
    : ASTNode(), stmts(std::move(stmts)) {
    name = "program";
}
void Program::print(std::string prefix) {
    std::cout << prefix << name << ": ";
    std::cout << "[result]";
    result.print();
    std::cout << std::endl;
    prefix += TAB;
    for (auto &stmt : stmts) {
        stmt->print(prefix);
    }
}
ASTResult Program::execute(CompilerContext &ctx) {
    for (auto &stmt : stmts) {
        stmt->execute(ctx);
    }
    auto val = ctx.getVar("result");
    result = ASTResult(val);
    return result;
}