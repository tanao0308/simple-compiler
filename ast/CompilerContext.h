#pragma once
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

class ASTNode;
class Expr;

struct FuncDef {
    std::string name;
    std::string param;
    std::shared_ptr<Expr> body;
    FuncDef(std::string name, std::string param, std::shared_ptr<Expr> body)
        : name(name), param(param), body(body) {}
};

struct VarDef {
    std::string name;
    double val;
    VarDef(std::string name, double val) : name(name), val(val) {}
};

class CompilerContext {
  public:
    CompilerContext() {}
    ~CompilerContext() {}

    // 禁止拷贝
    CompilerContext(const CompilerContext &) = delete;
    CompilerContext &operator=(const CompilerContext &) = delete;

    // 允许移动
    CompilerContext(CompilerContext &&) = default;
    CompilerContext &operator=(CompilerContext &&) = default;

    // 增删符号表
    void setVar(const VarDef &varDef) {
        var2val[varDef.name] = std::make_shared<VarDef>(varDef); // 拷贝，非引用
    }
    std::shared_ptr<VarDef> getVar(const std::string &name) {
        auto it = var2val.find(name);
        if (it == var2val.end()) {
            return nullptr;
        }
        return it->second;
    }
    void setFunc(const FuncDef &funcDef) {
        func2def[funcDef.name] = std::make_shared<FuncDef>(funcDef);
    }
    std::shared_ptr<FuncDef> getFunc(const std::string &name) {
        auto it = func2def.find(name);
        if (it == func2def.end()) {
            return nullptr;
        }
        return it->second;
    }

    // 清空上下文（用于重新编译）
    void clear() {
        var2val.clear();
        func2def.clear();
    }

  private:
    // 符号表
    std::unordered_map<std::string, std::shared_ptr<VarDef>> var2val;
    std::unordered_map<std::string, std::shared_ptr<FuncDef>> func2def;
};

// 使用：在 main 中创建，层层传递