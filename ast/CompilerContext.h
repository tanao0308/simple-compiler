#pragma once
#include "ast/Const.h"
#include "ast/Type.h"
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

class ASTNode;
class Stmt;

class CompilerContext {
  public:
    CompilerContext() { pushScope(); }
    ~CompilerContext() {}

    // 禁止拷贝
    CompilerContext(const CompilerContext &) = delete;
    CompilerContext &operator=(const CompilerContext &) = delete;

    // 允许移动
    CompilerContext(CompilerContext &&) = default;
    CompilerContext &operator=(CompilerContext &&) = default;

    // 增删符号表
    void setVar(const std::string &name, const Variable &var) {
        scopes.back()[name] = var;
    }
    Variable getVar(const std::string &name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) {
                return found->second;
            }
        }
        throw std::runtime_error("Undefined variable: " + name);
    }
    void setFunc(const Function func) {
        functions[func.name] = std::make_shared<Function>(func);
    }
    std::shared_ptr<Function> getFunc(const std::string &name) {
        auto found = functions.find(name);
        if (found != functions.end()) {
            return found->second;
        }
        throw std::runtime_error("Undefined function: " + name);
    }
    // 变量定义域
    void pushScope() { scopes.push_back({}); }
    void popScope() { scopes.pop_back(); }

  private:
    // 符号表
    using Scope = std::unordered_map<std::string, Variable>;
    std::vector<Scope> scopes;
    std::unordered_map<std::string, std::shared_ptr<Function>> functions;
};