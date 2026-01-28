// graph/Graph.cpp
#include "Graph.h"
#include <sstream>
#include <iostream>
#include "exprTree.h"
#include <ostream>

using namespace std;

static string type_to_string(types_t t);

//CFGNode методы

void CFGNode::add_statement(const string& stmt) {
    if (type == NodeType::BASIC_BLOCK || type == NodeType::LOOP_BODY) {
        statements.push_back(stmt);
    }
}

CFGNode::CFGNode(NodeType t, const string& lbl, const string& val)
    : type(t), label(lbl), value(val) {}


void CFGNode::add_successor(CFGNode* succ) {
    if (!succ || succ == this) return;
    
    if (find(successors.begin(), successors.end(), succ) == successors.end()) {
        successors.push_back(succ);
        
        if (find(succ->predecessors.begin(), succ->predecessors.end(), this) 
            == succ->predecessors.end()) {
            succ->predecessors.push_back(this);
        }    
    }
}

//OpGraph методы

CFGNode* OpGraph::create_node(NodeType type, const string& label, 
                              const string& value) {
    nodes.emplace_back(make_unique<CFGNode>(type, label, value));
    return nodes.back().get();
}

//CallGraph методы

OpGraph* CallGraph::create_function(const string& name) {
    // Создаем новый OpGraph
    auto graph = make_unique<OpGraph>();
    graph->function_name = name;
    
    // Создаем entry и exit узлы
    graph->entry = graph->create_node(NodeType::ENTRY, "entry");
    graph->exit = graph->create_node(NodeType::EXIT, "exit");
    
    OpGraph* ptr = graph.get();
    functionGraphs[name] = move(graph);
    return ptr;
}

OpGraph* CallGraph::get_function(const string& name) {
    auto it = functionGraphs.find(name);
    if (it != functionGraphs.end()) {
        return it->second.get();
    }
    return nullptr;
}

void CallGraph::add_call(const string& caller, const string& callee) {
    edges[caller].insert(callee);
}

string CallGraph::to_dot() {
    stringstream dot;
    dot << "digraph CallGraph {\n";
    dot << "  rankdir=LR;\n";
    dot << "  node [shape=box, fontname=\"Courier\"];\n\n";

    // Сначала все функции как узлы
    for (const auto& [funcName, graphPtr] : functionGraphs) {
        dot << "  \"" << funcName << "\";\n";
    }

    dot << "\n  // edges\n";
    for (const auto& [caller, callees] : edges) {
        for (const auto& callee : callees) {
            dot << "  \"" << caller << "\" -> \"" << callee << "\";\n";
        }
    }

    dot << "}\n";
    return dot.str();
}

static std::string escape_dot(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    for (char c : s) {
        if (c == '\\' || c == '"') out.push_back('\\');
        out.push_back(c);
    }
    return out;
}

static void exprTreeToLines(const ExprPtr& e, std::vector<std::string>& lines, int indent = 0) {
    std::string ind(indent * 2, ' ');

    if (!e) {
        lines.push_back(ind + "<null>");
        return;
    }

    if (auto lit = std::dynamic_pointer_cast<LiteralExpr>(e)) {
        lines.push_back(ind + "Literal: " + lit->value);
        return;
    }
    if (auto var = std::dynamic_pointer_cast<VarExpr>(e)) {
        lines.push_back(ind + "Id: " + var->name);
        return;
    }
    if (auto un = std::dynamic_pointer_cast<UnaryExpr>(e)) {
        lines.push_back(ind + "Unary: " + un->op);
        exprTreeToLines(un->arg, lines, indent + 1);
        return;
    }
    if (auto bin = std::dynamic_pointer_cast<BinaryExpr>(e)) {
        lines.push_back(ind + "Binary: " + bin->op);
        exprTreeToLines(bin->lhs, lines, indent + 1);
        exprTreeToLines(bin->rhs, lines, indent + 1);
        return;
    }
    if (auto asg = std::dynamic_pointer_cast<AssignExpr>(e)) {
        lines.push_back(ind + "Assign");
        lines.push_back(ind + "  LEFT:");
        exprTreeToLines(asg->lhs, lines, indent + 2);
        lines.push_back(ind + "  RIGHT:");
        exprTreeToLines(asg->rhs, lines, indent + 2);
        return;
    }

    if (auto call = std::dynamic_pointer_cast<CallExpr>(e)) {
        lines.push_back(ind + "Call: " + call->callee);
        if (!call->args.empty()) {
            lines.push_back(ind + "  Args:");
            for (auto& a : call->args) {
                exprTreeToLines(a, lines, indent + 2);
            }
        }
        return;
    }

    lines.push_back(ind + "<unknown ExprNode>");
}

static std::string exprTreeToDotLabel(const ExprPtr& e) {
    std::vector<std::string> lines;
    exprTreeToLines(e, lines, 0);

    std::string out;
    for (const auto& ln : lines) {
        out += escape_dot(ln);
        out += "\\l"; // left-justified linebreak
    }
    return out;
}

string OpGraph::to_dot() const {
    stringstream dot;

    dot << "digraph " << function_name << " {\n";
    dot << "  rankdir=TB;\n";
    dot << "  node [fontname=\"Courier\"];\n\n";

    // -------- nodes --------
    for (const auto& node : nodes) {
        string shape;

        switch (node->type) {
            case NodeType::ENTRY:
            case NodeType::EXIT:
                shape = "ellipse";
                break;
            case NodeType::CONDITION:
                shape = "diamond";
                break;
            case NodeType::LOOP_HEADER:
            case NodeType::LOOP_EXIT:
                shape = "hexagon";
                break;
            case NodeType::MERGE:
                shape = "rectangle";
                break;
            default:
                shape = "box";
        }

        // -------- label --------
        string label = escape_dot(node->label);

        if (!node->condition.empty()) {
            label += "\\n[" + escape_dot(node->condition) + "]";
        }

        // condition expression tree
        if (node->conditionTree) {
            label += "\\n cond-tree \\l";
            label += exprTreeToDotLabel(node->conditionTree);
        }

        // statements + expr trees
        for (size_t i = 0; i < node->statements.size(); ++i) {
            label += "\\n" + escape_dot(node->statements[i]);

            if (i < node->exprTrees.size() && node->exprTrees[i]) {
                label += "\\n expr-tree \\l";
                label += exprTreeToDotLabel(node->exprTrees[i]);
            }
        }

        // variables in ENTRY
        if (node->type == NodeType::ENTRY && !variables.empty()) {
            label += "\\n    vars    ";
            for (const auto& [name, type] : variables) {
                label += "\\n" + escape_dot(name) +
                         " : " + escape_dot(type_to_string(type));
            }
        }

        dot << "  n" << reinterpret_cast<uintptr_t>(node.get())
            << " [shape=" << shape
            << ", labeljust=l, label=\"" << label << "\"];\n";
    }

    // -------- edges --------
    dot << "\n  // Successor edges\n";
    for (const auto& node : nodes) {
        for (CFGNode* succ : node->successors) {

            string edge_label;
            string style;

            if (node->true_branch == succ) {
                edge_label = "true";
            } else if (node->false_branch == succ) {
                edge_label = "false";
            } else if (node->loop_body == succ) {
                edge_label = "body";
                style = "dashed";
            } else if (node->loop_exit == succ) {
                edge_label = "exit";
                style = "dotted";
            }

            dot << "  n" << reinterpret_cast<uintptr_t>(node.get())
                << " -> n" << reinterpret_cast<uintptr_t>(succ);

            if (!edge_label.empty() || !style.empty()) {
                dot << " [";
                bool first = true;

                if (!edge_label.empty()) {
                    dot << "label=\"" << edge_label << "\"";
                    first = false;
                }
                if (!style.empty()) {
                    if (!first) dot << ", ";
                    dot << "style=\"" << style << "\"";
                }
                dot << "]";
            }

            dot << ";\n";
        }
    }

    dot << "}\n";
    return dot.str();
}


inline std::string type_to_string(types_t t) {
    switch (t) {
        case types_t::BOOL:   return "bool";
        case types_t::BYTE:   return "byte";
        case types_t::INT:    return "int";
        case types_t::UINT:   return "uint";
        case types_t::LONG:   return "long";
        case types_t::ULONG:  return "ulong";
        case types_t::CHAR:   return "char";
        case types_t::STRING: return "string";
        default:              return "unknown";
    }
}

