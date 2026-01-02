#include "ast/CompilerContext.h"

CompilerContext::CompilerContext() { pushScope(); }
CompilerContext::~CompilerContext() {}

void CompilerContext::setVar(const std::string &name, const Variable &var) {
    scopes.back()[name] = var;
}
Variable CompilerContext::getVar(const std::string &name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto found = it->find(name);
        if (found != it->end()) {
            return found->second;
        }
    }
    throw std::runtime_error("Undefined variable: " + name);
}
void CompilerContext::setFunc(const Function func) {
    functions[func.name] = std::make_shared<Function>(func);
}
std::shared_ptr<Function> CompilerContext::getFunc(const std::string &name) {
    auto found = functions.find(name);
    if (found != functions.end()) {
        return found->second;
    }
    throw std::runtime_error("Undefined function: " + name);
}
void CompilerContext::pushScope() { scopes.push_back({}); }
void CompilerContext::popScope() { scopes.pop_back(); }