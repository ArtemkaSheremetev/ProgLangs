// graph/Graph.cpp
#include "Graph.h"
#include <sstream>
#include <iostream>

using namespace std;

static string type_to_string(types_t t);

// ==================== CFGNode методы ====================

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
        }    // Проверяем, нет ли уже такой связи
    }
}

// ==================== OpGraph методы ====================

CFGNode* OpGraph::create_node(NodeType type, const string& label, 
                              const string& value) {
    nodes.emplace_back(make_unique<CFGNode>(type, label, value));
    return nodes.back().get();
}

string OpGraph::to_dot() const {
    stringstream dot;
    
    dot << "digraph " << function_name << " {\n";
    dot << "  rankdir=TB;\n";
    dot << "  node [fontname=\"Courier\"];\n\n";
    
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
                shape = "circle";
                break;
            default:
                shape = "box";
        }
        
        // Формируем метку узла
        string label = node->label;
        if (!node->condition.empty()) {
            label += "\\n[" + node->condition + "]";
        }
        if (!node->statements.empty()) {
            for (const auto& stmt : node->statements) {
                label += "\\n" + stmt;
            }
        }
        
        if (node->type == NodeType::ENTRY && !variables.empty()) {
            label += "\\n--- vars ---";
            for (const auto& [name, type] : variables) {
                label += "\\n" + name + " : " + type_to_string(type);
            }
        }

        dot << "  n" << reinterpret_cast<uintptr_t>(node.get())
            << " [shape=" << shape << ", label=\"" << label << "\"];\n";
    }
    
    // Добавляем обычные связи (successors)
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

// ==================== CallGraph методы ====================

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

string type_to_string(types_t t) {
    switch (t) {
        case BOOL:   return "bool";
        case BYTE:   return "byte";
        case INT:    return "int";
        case UINT:   return "uint";
        case LONG:   return "long";
        case ULONG:  return "ulong";
        case CHAR:   return "char";
        case STRING: return "string";
        default:     return "unknown";
    }
}
