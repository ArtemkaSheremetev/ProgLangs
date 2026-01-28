#pragma once
#include <memory>
#include <string>
#include <ostream>
#include <vector>
#include <iostream>

struct ExprNode {
    virtual ~ExprNode() = default;
};

using ExprPtr = std::shared_ptr<ExprNode>;

struct LiteralExpr : ExprNode {
    std::string value;
    LiteralExpr(const std::string& v) : value(v) {}
};

struct VarExpr : ExprNode {
    std::string name;
    VarExpr(const std::string& n) : name(n) {}
};

struct UnaryExpr : ExprNode {
    std::string op;
    ExprPtr arg;
    UnaryExpr(const std::string& o, ExprPtr a)
        : op(o), arg(a) {}
};

struct BinaryExpr : ExprNode {
    std::string op;
    ExprPtr lhs, rhs;
    BinaryExpr(const std::string& o, ExprPtr l, ExprPtr r)
        : op(o), lhs(l), rhs(r) {}
};

struct AssignExpr : ExprNode {
    ExprPtr lhs, rhs;
    AssignExpr(ExprPtr l, ExprPtr r)
        : lhs(l), rhs(r) {}
};

struct CallExpr : ExprNode {
    std::string callee;
    std::vector<ExprPtr> args;
    CallExpr(const std::string& c, std::vector<ExprPtr> a)
        : callee(c), args(std::move(a)) {}
};

inline void printIndent(std::ostream& out, int n) {
    for (int i = 0; i < n; ++i) out << "  ";
}

inline void printExprTree(const ExprPtr& e, std::ostream& out, int indent = 0) {
    if (!e) { printIndent(out, indent); out << "<null>\n"; return; }

    if (auto lit = std::dynamic_pointer_cast<LiteralExpr>(e)) {
        printIndent(out, indent); out << "Literal: " << lit->value << "\n"; return;
    }
    if (auto var = std::dynamic_pointer_cast<VarExpr>(e)) {
        printIndent(out, indent); out << "Id: " << var->name << "\n"; return;
    }
    if (auto un = std::dynamic_pointer_cast<UnaryExpr>(e)) {
        printIndent(out, indent); out << "Unary: " << un->op << "\n";
        printExprTree(un->arg, out, indent + 1); return;
    }
    if (auto bin = std::dynamic_pointer_cast<BinaryExpr>(e)) {
        printIndent(out, indent); out << "Binary: " << bin->op << "\n";
        printExprTree(bin->lhs, out, indent + 1);
        printExprTree(bin->rhs, out, indent + 1);
        return;
    }
    if (auto asg = std::dynamic_pointer_cast<AssignExpr>(e)) {
        printIndent(out, indent); out << "Assign\n";
        printIndent(out, indent + 1); out << "LHS:\n";
        printExprTree(asg->lhs, out, indent + 2);
        printIndent(out, indent + 1); out << "RHS:\n";
        printExprTree(asg->rhs, out, indent + 2);
        return;
    }

    if (auto call = std::dynamic_pointer_cast<CallExpr>(e)) {
        printIndent(out, indent);
        out << "Call: " << call->callee << "\n";
        if (!call->args.empty()) {
            printIndent(out, indent + 1);
            out << "Args:\n";
            for (auto& a : call->args) {
                printExprTree(a, out, indent + 2);
            }
        }
        return;
    }

    std::cout << "typeid: " << typeid(*e).name() << "\n";
    printIndent(out, indent); out << "adsjbsadjsad ExprNode>\n";
}

