#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include "Graph.h"
#include "Reg32VMImageStructures.h"

namespace reg32_codegen {
struct VarLayout {
    std::unordered_map<std::string, std::string> varLabel;
};

struct CodeGenResult {
    reg32::ProgramImage image;
    std::unordered_map<std::string, VarLayout> vars;
};

CodeGenResult buildProgramImage(const CallGraph& cg);
}
