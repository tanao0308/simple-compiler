#pragma once
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "ast/Const.h"
#include "ast/Type.h"

class ASTNode;
class Stmt;

class CompilerContext {
  public:
    CompilerContext();
    ~CompilerContext();

    // 禁止拷贝
    CompilerContext(const CompilerContext &) = delete;
    CompilerContext &operator=(const CompilerContext &) = delete;

    // 允许移动
    CompilerContext(CompilerContext &&) = default;
    CompilerContext &operator=(CompilerContext &&) = default;

    // 增删符号表
    void setVar(const std::string &name, const Variable &var);
    Variable getVar(const std::string &name);
    void setFunc(const Function func);
    std::shared_ptr<Function> getFunc(const std::string &name);
    // 变量定义域
    void pushScope();
    void popScope();

  private:
    // 符号表
    using Scope = std::unordered_map<std::string, Variable>;
    std::vector<Scope> scopes;
    std::unordered_map<std::string, std::shared_ptr<Function>> functions;
};