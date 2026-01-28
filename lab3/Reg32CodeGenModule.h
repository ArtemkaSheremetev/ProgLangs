#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include "Graph.h"
#include "Reg32VMImageStructures.h"

namespace reg32_codegen {
// Simple metadata: where each variable got placed in DATA.
struct VarLayout {
    // qualified label (e.g. "var_fn_main_x")
    std::unordered_map<std::string, std::string> varLabel;
};

struct CodeGenResult {
    reg32::ProgramImage image;
    // Per-function variable labels (debug / later passes)
    std::unordered_map<std::string, VarLayout> vars;
};

// Build a structured ProgramImage (CODE + DATA sections, labels, fixups)
// from your CallGraph + per-function CFG (OpGraph).
CodeGenResult buildProgramImage(const CallGraph& cg);

} // namespace reg32_codegen
