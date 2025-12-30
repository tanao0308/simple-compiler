#pragma once
#include "ast/ASTNode.h"
#include "ast/Const.h"
#include "ast/stmt/Stmt.h"
#include <iostream>
#include <vector>

class Program : public ASTNode {
  public:
    Program(std::vector<Stmt *> *stmts) : stmts(stmts) { name = "program"; }
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