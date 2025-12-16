// graph/Graph.h
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include "unordered_set"

using namespace std;

enum class NodeType {
    ENTRY,          // Вход в функцию
    EXIT,           // Выход (неявный, когда поток доходит до конца)
    BASIC_BLOCK,    // Блок операций
    CONDITION,      // if (expr) then ... [else ...]
    LOOP_HEADER,    // while/do-while/do-until (все циклы)
    LOOP_BODY,      // Тело цикла  
    LOOP_EXIT,      // Выход из цикла
    MERGE,          // Слияние после if/else
    CALL
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
    
    // Данные для разных типов узлов
    string condition;          // Условие для ветвления/цикла
    bool is_until = false;     // true если это repeat-until (инвертированное условие)
    vector<string> statements; // Операции в блоке
    
    vector<CFGNode*> predecessors;
    vector<CFGNode*> successors;
    
    // Специальные связи
    CFGNode* true_branch = nullptr;   // Для if: ветка true
    CFGNode* false_branch = nullptr;  // Для if: ветка false
    CFGNode* loop_body = nullptr;     // Для циклов: тело
    CFGNode* loop_exit = nullptr;     // Для циклов: выход
    
    CFGNode(NodeType t, const string& lbl = "", const string& val = "");
    
    void add_statement(const string& stmt);
    
    void add_successor(CFGNode* succ);
};

struct OpGraph {
    string function_name;
    unordered_map<string, types_t> variables;
    CFGNode* entry = nullptr;
    CFGNode* exit = nullptr;
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
