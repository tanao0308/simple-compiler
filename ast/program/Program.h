#pragma once
#include "ast/ASTNode.h"
#include "ast/Const.h"
#include "ast/stmt/Stmt.h"
#include <iostream>
#include <vector>

class Program : public ASTNode {
  public:
    Program(std::shared_ptr<CompilerContext> cc, std::vector<Stmt *> *stmts)
        : ASTNode(cc), stmts(stmts) {
        name = "program";
    }
    void print(std::string prefix = "") override {
        std::cout << prefix << name << std::endl;
        prefix += TAB;
        for (auto stmt : *stmts) {
            stmt->print(prefix);
        }
    }

  private:
    std::vector<Stmt *> *stmts;
};