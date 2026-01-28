#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "antlr4-runtime.h"
#include "HelloLexer.h"
#include "HelloParser.h"
#include "HelloASTVisitor.h"
#include "Reg32CodeGenModule.h"
#include "ASTNodes.h"
#include "Graph.h"
#include "CFGBuilder.h"
#include "exprTree.h"
#include "Reg32VMImageStructures.h"

using namespace antlr4;
using namespace std;
using namespace reg32_codegen;

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

        // -------- find body (optional) --------
        ASTNode* body = nullptr;
        for (auto& c : child->children) {
            if (c->name == "Body") {
                body = c.get();
                break;
            }
        }
        bool hasBody = (body != nullptr);

        OpGraph* graph = callGraph.get_function(funcName);
        if (!graph) graph = callGraph.create_function(funcName);

        graph->args.clear();

        for (auto& sigChild : signature->children) {
            if (sigChild->name != "ArgList") continue;

            // ArgList -> ArgDef*
            for (auto& argDef : sigChild->children) {
                if (argDef->name != "ArgDef") continue;

                std::string argName;
                types_t argType = types_t::INT; // default

                for (auto& a : argDef->children) {
                    if (a->name == "Identifier") argName = a->value;
                    else if (a->name == "TypeRef" && !a->children.empty()) {
                        // TypeRef -> BuiltinType/Identifier...
                        argType = ParseType(a->children[0]->value);
                    }
                }

                if (!argName.empty()) {
                    graph->args.push_back(argName);
                    graph->variables[argName] = argType; // ✅ важно: теперь n станет переменной
                }
            }
        }


        // -------- mark defined/extern --------
        graph->function_name = funcName;
        graph->is_defined = hasBody;
        graph->is_extern  = !hasBody;

        if (!hasBody) {
            cout << "Registered extern function: " << funcName << endl;
            continue;
        }

        cout << "Building CFG for function: " << funcName << endl;

        CFGBuilder builder(graph, &callGraph);
        builder.build(body);

        // dot
        string dotName = funcName + ".cfg.dot";
        ofstream dotFile(dotName);
        dotFile << graph->to_dot();
        dotFile.close();

        cout << "CFG saved to " << dotName << endl;
    }

        // === ASM ===
        auto res = reg32_codegen::buildProgramImage(callGraph);
        std::ofstream asmFile("program.s");
        reg32::printListing(res.image, asmFile);
        asmFile.close();

        std::cout << "ASM saved to program.s\n";
    

    // -------- save CallGraph DOT --------
    ofstream cgFile("callgraph.dot");
    cgFile << callGraph.to_dot();
    cgFile.close();
    cout << "CallGraph saved to callgraph.dot\n";

    return 0;
}
