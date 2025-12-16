#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "antlr4-runtime.h"
#include "HelloLexer.h"
#include "HelloParser.h"
#include "HelloASTVisitor.h"

#include "ASTNodes.h"
#include "Graph.h"
#include "CFGBuilder.h"

using namespace antlr4;
using namespace std;

// ========================================================
// AST PRINT
// ========================================================

static void printAST(const shared_ptr<ASTNode>& node,
                     ostream& out,
                     const string& prefix = "",
                     bool isLast = true) {
    if (!node) return;

    out << prefix;
    if (!prefix.empty())
        out << (isLast ? "└── " : "├── ");

    out << node->name;
    if (!node->value.empty())
        out << " : " << node->value;
    out << "\n";

    for (size_t i = 0; i < node->children.size(); ++i) {
        printAST(node->children[i], out,
                 prefix + (isLast ? "    " : "│   "),
                 i + 1 == node->children.size());
    }
}

// ========================================================
// MAIN
// ========================================================

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    ifstream stream(argv[1]);
    if (!stream.is_open()) {
        cerr << "Error: cannot open file " << argv[1] << "\n";
        return 1;
    }

    // ---------- PARSE ----------
    ANTLRInputStream input(stream);
    HelloLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    HelloParser parser(&tokens);

    tree::ParseTree* tree = parser.source();

    // ---------- AST ----------
    HelloASTVisitor visitor;
    auto ast = any_cast<shared_ptr<ASTNode>>(visitor.visit(tree));

    // ---------- PRINT AST ----------
    ofstream astFile("output.ast.txt");
    printAST(ast, cout);
    printAST(ast, astFile);
    astFile.close();

    cout << "\nAST saved to output.ast.txt\n";

    // ====================================================
    // BUILD CFGs
    // ====================================================

    CallGraph callGraph;

    for (auto& child : ast->children) {
        if (child->name != "FuncDef")
            continue;

        // -------- function name --------
        ASTNode* signature = child->children[0].get(); // FuncSignature
        string funcName = "anonymous";

        for (auto& sigChild : signature->children) {
            if (sigChild->name == "Identifier") {
                funcName = sigChild->value;
                break;
            }
        }

        cout << "Building CFG for function: " << funcName << endl;

        // -------- create graph --------
        OpGraph* graph = callGraph.create_function(funcName);

        // -------- function body --------
        ASTNode* body = nullptr;
        for (auto& c : child->children) {
            if (c->name == "Body") {
                body = c.get();
                break;
            }
        }

        if (!body) {
            cerr << "Warning: function " << funcName << " has no body\n";
            continue;
        }

        // -------- build CFG --------
        CFGBuilder builder(graph, &callGraph);
        builder.build(body);

        // -------- save DOT --------
        string dotName = funcName + ".cfg.dot";
        ofstream dotFile(dotName);
        dotFile << graph->to_dot();
        dotFile.close();

        cout << "CFG saved to " << dotName << endl;
    }

    // -------- save CallGraph DOT --------
    ofstream cgFile("callgraph.dot");
    cgFile << callGraph.to_dot();
    cgFile.close();
    cout << "CallGraph saved to callgraph.dot\n";

    return 0;
}
