#pragma once

#include <string>
#include <memory>

namespace ast {

    class Expr {
    };

    class Number : public Expr {
        public:
            double value;
            Number(double value) : value(value) {}
    };

    class Variable : public Expr {
        public:
            std::string name;
            Variable(const std::string &name) : name(name) {}
    };

    class Binary : public Expr {
        public:
            char op;
            std::unique_ptr<Expr> lhs, rhs;
            Binary(char op, Expr *lhs, Expr *rhs) : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    };

}