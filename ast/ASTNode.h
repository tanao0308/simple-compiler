#pragma once

#include <string>

class ASTVisitor;

class ASTNode {
  public:
    virtual ~ASTNode() = default;
    virtual void print(std::string prefix = "") = 0;

  protected:
    std::string name;

  private:
};
