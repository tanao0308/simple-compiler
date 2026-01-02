#pragma once
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <variant>

class Stmt;

struct Void {};
enum class ValueType { Void, Int, Float, Bool };
using Value = std::variant<Void, int, double, bool>;

// 带类型的变量类
struct Variable {
    ValueType type; // 变量类型
    Value val;      // 变量值
    Variable() : type(ValueType::Void), val(Void{}) {}
    Variable(int v) : type(ValueType::Int), val(v) {}
    Variable(double v) : type(ValueType::Float), val(v) {}
    Variable(bool v) : type(ValueType::Bool), val(v) {}

    // 重载算术运算符，返回类型为 lhs 的类型
    Variable operator+(const Variable &rhs) const {
        return fromDouble(asNumber() + rhs.asNumber());
    }
    Variable operator-(const Variable &rhs) const {
        return fromDouble(asNumber() - rhs.asNumber());
    }
    Variable operator*(const Variable &rhs) const {
        return fromDouble(asNumber() * rhs.asNumber());
    }
    Variable operator/(const Variable &rhs) const {
        return fromDouble(asNumber() / rhs.asNumber());
    }
    Variable operator^(const Variable &rhs) const {
        return fromDouble(pow(asNumber(), rhs.asNumber()));
    }

    // 把 Variable 转 double，用于计算
    double asNumber() const {
        switch (type) {
            case ValueType::Int:
                return static_cast<double>(std::get<int>(val));
            case ValueType::Float:
                return std::get<double>(val);
            case ValueType::Bool:
                return std::get<bool>(val) ? 1.0 : 0.0;
            default:
                throw std::runtime_error("Variable is not a number");
        }
    }
    // 返回 lhs 类型的 Variable
    Variable fromDouble(double v) const {
        switch (type) {
            case ValueType::Int:
                return Variable(static_cast<int>(v));
            case ValueType::Float:
                return Variable(v);
            case ValueType::Bool:
                return Variable(v != 0.0);
            default:
                throw std::runtime_error("Cannot create Variable from Void");
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Variable &var) {
        switch (var.type) {
            case ValueType::Int:
                os << "Int(" << std::get<int>(var.val) << ")";
                break;
            case ValueType::Float:
                os << "Float(" << std::get<double>(var.val) << ")";
                break;
            case ValueType::Bool:
                os << "Bool(" << (std::get<bool>(var.val) ? "true" : "false")
                   << ")";
                break;
            case ValueType::Void:
                os << "Void";
                break;
        }
        return os;
    }
};

struct Function {
    std::string name;
    std::string param;
    std::shared_ptr<Stmt> body;
    Function(std::string name, std::string param, std::shared_ptr<Stmt> body)
        : name(name), param(param), body(body) {}
};