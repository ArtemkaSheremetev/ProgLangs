// graph/Graph.h
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include "unordered_set"
#include "exprTree.h"
#include <ostream>

using namespace std;

enum class NodeType {
    ENTRY,          // Вход в функцию
    EXIT,           // Выход 
    BASIC_BLOCK,    // Блок операций
    CONDITION,      // if (expr) then / else
    LOOP_HEADER,    // while do-while do-until 
    LOOP_BODY,      // Тело цикла  
    LOOP_EXIT,      // Выход из цикла
    MERGE,          // Слияние после if/else
    CALL            //Вызов функции
};

typedef enum{
    BOOL = 0,
    BYTE,
    INT,
    UINT,
    LONG,
    ULONG,
    CHAR,
    STRING
}types_t;

struct CFGNode {
    NodeType type;
    string label;    
    string value;   
    
    string condition;          
    bool is_until = false;     
    vector<string> statements; 
    vector<ExprPtr> exprTrees; 
    ExprPtr conditionTree;
    ExprPtr returnExpr; 
    vector<CFGNode*> predecessors;
    vector<CFGNode*> successors;
    
    CFGNode* true_branch = nullptr;   
    CFGNode* false_branch = nullptr;  
    CFGNode* loop_body = nullptr;     
    CFGNode* loop_exit = nullptr;    
    
    CFGNode(NodeType t, const string& lbl = "", const string& val = "");
    
    void add_statement(const string& stmt);
    
    void add_successor(CFGNode* succ);
};

struct OpGraph {
    string function_name;

    bool is_defined = false;   
    bool is_extern  = false;  

    unordered_map<string, types_t> variables;
    std::vector<std::string> args; 
    CFGNode* entry = nullptr;
    CFGNode* exit  = nullptr;

    vector<unique_ptr<CFGNode>> nodes;

    CFGNode* create_node(NodeType type, const string& label = "",
                         const string& value = "");

    string to_dot() const;
};


struct CallGraph {
    unordered_map<string, unique_ptr<OpGraph>> functionGraphs;
    unordered_map<string, unordered_set<string>> edges;

    OpGraph* create_function(const string& name);
    OpGraph* get_function(const string& name);
    string to_dot();
    void add_call(const string& caller, const string& callee);
};

void DumpExprTrees(const OpGraph& g, std::ostream& out);
