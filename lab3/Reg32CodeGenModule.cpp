#include "Reg32CodeGenModule.h"
#include <algorithm>
#include <cctype>
#include <functional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <ostream>
#include <unordered_map>
#include <vector>

static bool containsCall(const ExprPtr& e) {
    if (!e) return false;
    if (std::dynamic_pointer_cast<CallExpr>(e)) return true;

    if (auto u = std::dynamic_pointer_cast<UnaryExpr>(e))
        return containsCall(u->arg);

    if (auto b = std::dynamic_pointer_cast<BinaryExpr>(e))
        return containsCall(b->lhs) || containsCall(b->rhs);

    if (auto a = std::dynamic_pointer_cast<AssignExpr>(e))
        return containsCall(a->lhs) || containsCall(a->rhs);

    return false;
}



namespace reg32_codegen {
namespace {

// ------------------------- utilities -------------------------

static std::string sanitizeLabel(std::string s) {
    for (char& c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (!(std::isalnum(uc) || c == '_')) c = '_';
    }
    if (s.empty()) s = "_";
    if (std::isdigit(static_cast<unsigned char>(s[0]))) s = "_" + s;
    return s;
}

static std::string fnLabel(const std::string& name) {
    // Keep function labels identical to source names (for multi-file linking).
    return sanitizeLabel(name);
}


static std::string nodeLabel(const CFGNode* n) {
    std::ostringstream o;
    o << "bb_" << sanitizeLabel(n->label);
    o << "_" << std::hex << (uintptr_t)n;
    return o.str();
}

static std::string trim(std::string s) {
    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front()))) s.erase(s.begin());
    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back()))) s.pop_back();
    return s;
}

static bool parseIntLiteral(const std::string& s, std::int32_t& outVal) {
    try {
        int base = 10;
        std::size_t idx = 0;
        if (s.size() >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) base = 16;
        else if (s.size() >= 2 && s[0] == '0' && (s[1] == 'b' || s[1] == 'B')) base = 2;
        long long v = std::stoll(s, &idx, base);
        if (idx != s.size()) return false;
        outVal = static_cast<std::int32_t>(v);
        return true;
    } catch (...) {
        return false;
    }
}

static bool parseCharLiteral(const std::string& s, std::int32_t& outVal) {
    // Expected: 'a', '\n', '\t', '\\', '\'', '\"', '\r', '\0'
    if (s.size() < 3) return false;
    if (s.front() != '\'' || s.back() != '\'') return false;

    std::string inner = s.substr(1, s.size() - 2); // without surrounding quotes

    if (inner.size() == 1) {
        outVal = static_cast<unsigned char>(inner[0]);
        return true;
    }

    if (inner.size() == 2 && inner[0] == '\\') {
        switch (inner[1]) {
            case 'n': outVal = 10; return true;
            case 'r': outVal = 13; return true;
            case 't': outVal = 9;  return true;
            case 'b': outVal = 8;  return true;
            case 'f': outVal = 12; return true;
            case '0': outVal = 0;  return true;
            case '\\': outVal = '\\'; return true;
            case '\'': outVal = '\''; return true;
            case '"': outVal = '"'; return true;
            default: return false;
        }
    }

    // (опционально) \uXXXX можно добавить позже
    return false;
}


static std::string getCalleeFromCallLabel(const std::string& lbl) {
    // expected: "call <name>"
    auto p = lbl.find("call");
    if (p == std::string::npos) return lbl;
    return trim(lbl.substr(p + 4));
}

// ------------------------- ProgramImage builder -------------------------

struct ImageBuilder {
    reg32::ProgramImage image;
    std::size_t codeSectionIndex{0};
    std::size_t dataSectionIndex{0};

    ImageBuilder() {
        reg32::Section code;
        code.decl.name = "code";
        code.decl.bank = reg32::BankName::code;
        code.decl.startAddr = static_cast<std::uint16_t>(0x0000);
        image.sections.push_back(std::move(code));
        codeSectionIndex = image.sections.size() - 1;

        reg32::Section data;
        data.decl.name = "data";
        data.decl.bank = reg32::BankName::dataMem;
        data.decl.startAddr = static_cast<std::uint16_t>(0x0000);
        image.sections.push_back(std::move(data));
        dataSectionIndex = image.sections.size() - 1;
    }

    reg32::Section& codeSec() { return image.sections.at(codeSectionIndex); }
    reg32::Section& dataSec() { return image.sections.at(dataSectionIndex); }

    void emitCodeLabel(const std::string& raw, const std::string& qualified) {
        reg32::LineItem li;
        li.label = reg32::Label{raw, qualified};
        li.payload = reg32::CommentLine{""};
        codeSec().lines.push_back(std::move(li));
    }

    void emitDataLabel(const std::string& raw, const std::string& qualified) {
        reg32::LineItem li;
        li.label = reg32::Label{raw, qualified};
        li.payload = reg32::CommentLine{""};
        dataSec().lines.push_back(std::move(li));
    }

    void emitInstr(const reg32::Instruction& ins, std::optional<reg32::Label> lbl = std::nullopt) {
        reg32::LineItem li;
        li.label = std::move(lbl);
        li.payload = ins;
        codeSec().lines.push_back(std::move(li));
    }

    void emitDataDD(std::uint32_t v, const std::string& comment = {}) {
        reg32::DataDef d;
        d.dir = reg32::DataDirective::dd;
        d.values = {v};
        d.comment = comment;
        reg32::LineItem li;
        li.payload = d;
        dataSec().lines.push_back(std::move(li));
    }

    // Record fixup for a label operand.
    void addFixupForLastInstr(std::size_t operandIndex, const std::string& targetLabel, reg32::LabelSpace sp) {
        const std::size_t line = codeSec().lines.size() - 1;
        image.fixups.push_back(reg32::Fixup{codeSectionIndex, line, operandIndex, targetLabel, sp});
    }
};

// ------------------------- CFG order -------------------------

static void dfs_rpo(CFGNode* n, std::set<uintptr_t>& vis, std::vector<CFGNode*>& post) {
    if (!n) return;
    uintptr_t id = reinterpret_cast<uintptr_t>(n);
    if (vis.count(id)) return;
    vis.insert(id);
    for (auto* s : n->successors) dfs_rpo(s, vis, post);
    post.push_back(n);
}

static std::vector<CFGNode*> reversePostOrder(const OpGraph& g) {
    std::vector<CFGNode*> post;
    std::set<uintptr_t> vis;
    dfs_rpo(g.entry, vis, post);
    std::reverse(post.begin(), post.end());
    return post;
}

// ------------------------- expression codegen -------------------------

struct FnEmitter {
    ImageBuilder& out;
    const OpGraph& g;
    const std::string fnRawName;
    const std::string fnEntryLabel;

    // var name -> stack offset (bytes): address = bp - offset
    std::unordered_map<std::string, std::int32_t> varOffset;
    std::int32_t frameSlots{0}; // number of 4-byte slots reserved with push

    // kept for compatibility (no longer used for locals)
    std::unordered_map<std::string, std::string> varLabel;

    // temp regs: r0..r5 for expression evaluation.
    // r6: address temp
    // r7: scratch
    std::vector<int> freeRegs;

    explicit FnEmitter(ImageBuilder& o, const OpGraph& gg)
        : out(o), g(gg), fnRawName(gg.function_name), fnEntryLabel(fnLabel(gg.function_name)) {
        for (int r = 5; r >= 0; --r) freeRegs.push_back(r);
        // Build stack frame layout: args first (r0..), then locals.
        // Slot size = 4 bytes. Addressing: [bp - offset]. offset starts at 4.
        std::int32_t off = 4;
        // args in order
        for (std::size_t i = 0; i < g.args.size(); ++i) {
            const std::string& a = g.args[i];
            if (!a.empty() && !varOffset.count(a)) {
                varOffset[a] = off;
                off += 4;
            }
        }
        // other locals (deterministic order)
        std::vector<std::string> locals;
        locals.reserve(g.variables.size());
        for (const auto& kv : g.variables) {
            if (!varOffset.count(kv.first)) locals.push_back(kv.first);
        }
        std::sort(locals.begin(), locals.end());
        for (const auto& v : locals) {
            varOffset[v] = off;
            off += 4;
        }
        frameSlots = (off - 4) / 4;
    }

    static reg32::Operand R(int r) { return reg32::Operand::reg(static_cast<std::uint8_t>(r)); }

    int alloc() {
        if (freeRegs.empty()) return 5; // MVP fallback
        int r = freeRegs.back();
        freeRegs.pop_back();
        return r;
    }

    void release(int r) {
        if (r < 0 || r > 5) return;
        for (int x : freeRegs) if (x == r) return;
        freeRegs.push_back(r);
    }

    void emit(reg32::Mnemonic m, std::vector<reg32::Operand> ops = {}, std::string cmt = {}) {
        reg32::Instruction ins;
        ins.mnemonic = m;
        ins.operands = std::move(ops);
        ins.comment = std::move(cmt);
        out.emitInstr(ins);

        // register fixups for label operands
        for (std::size_t i = 0; i < ins.operands.size(); ++i) {
            const auto& op = ins.operands[i];
            if (op.kind == reg32::OperandKind::LabelRef) {
                out.addFixupForLastInstr(i, op.label, op.labelSpace);
            }
        }
    }

    // li dst, imm16 (validate range)
    void emitLiImm(int dst, std::int32_t v, std::string cmt = {}) {
        // Your ISA li is imm16 sign-extend.
        if (v < -32768 || v > 32767) {
            // MVP: clip (you can replace with proper li32 later)
            std::ostringstream o;
            o << "WARN: imm " << v << " out of imm16 range; clipped";
            cmt = cmt.empty() ? o.str() : (cmt + "; " + o.str());
            if (v < -32768) v = -32768;
            if (v > 32767) v = 32767;
        }
        emit(reg32::Mnemonic::li, {R(dst), reg32::Operand::imm16(static_cast<std::int16_t>(v))}, std::move(cmt));
    }

    void emitLiDataLabel(int dst, const std::string& dataLbl, std::string cmt = {}) {
        reg32::Operand op = reg32::Operand::dataLabel(dataLbl);
        emit(reg32::Mnemonic::li, {R(dst), op}, std::move(cmt));
    }

    int genLoadVar(const std::string& name) {
        int dst = alloc();
        auto it = varOffset.find(name);
        if (it == varOffset.end()) {
            emitLiImm(dst, 0, "unknown var " + name);
            return dst;
        }
        // r6 = bp - offset; load dst, r6
        emit(reg32::Mnemonic::getbp, {R(6)}, "bp");
        emitLiImm(7, it->second, "off " + name);
        emit(reg32::Mnemonic::sub, {R(6), R(7)});
        emit(reg32::Mnemonic::load, {R(dst), R(6)}, "load " + name);
        return dst;
    }

    void genStoreVar(const std::string& name, int src) {
        auto it = varOffset.find(name);
        if (it == varOffset.end()) {
            // ignore unknown store
            return;
        }
        emit(reg32::Mnemonic::getbp, {R(6)}, "bp");
        emitLiImm(7, it->second, "off " + name);
        emit(reg32::Mnemonic::sub, {R(6), R(7)});
        emit(reg32::Mnemonic::store, {R(6), R(src)}, "store " + name);
    }


    void emitFrameProlog() {
        // Reserve stack slots for args + locals (4 bytes each).
        if (frameSlots > 0) {
            emitLiImm(7, 0, "frame init");
            for (int i = 0; i < frameSlots; ++i) {
                emit(reg32::Mnemonic::push, {R(7)});
            }
        }

        // Save incoming args r0..r3 into their stack slots.
        for (std::size_t i = 0; i < g.args.size() && i < 4; ++i) {
            const std::string& aname = g.args[i];
            auto it = varOffset.find(aname);
            if (it == varOffset.end()) continue;

            emit(reg32::Mnemonic::getbp, {R(6)}, "bp");
            emitLiImm(7, it->second, "off " + aname);
            emit(reg32::Mnemonic::sub, {R(6), R(7)});
            emit(reg32::Mnemonic::store, {R(6), R((int)i)}, "arg " + aname);
        }
    }

    int genExpr(const ExprPtr& e) {
        if (!e) {
            int r = alloc();
            emitLiImm(r, 0);
            return r;
        }

        if (auto lit = std::dynamic_pointer_cast<LiteralExpr>(e)) {
    int r = alloc();
    std::string v = trim(lit->value);

    if (v == "true") v = "1";
    if (v == "false") v = "0";

    std::int32_t parsed = 0;

    if (parseCharLiteral(v, parsed)) {
        emitLiImm(r, parsed);
    } else if (parseIntLiteral(v, parsed)) {
        emitLiImm(r, parsed);
    } else {
        emitLiImm(r, 0, "WARN: bad literal '" + v + "'");
    }

    return r;
}


        if (auto var = std::dynamic_pointer_cast<VarExpr>(e)) {
            return genLoadVar(var->name);
        }

        if (auto un = std::dynamic_pointer_cast<UnaryExpr>(e)) {
            int a = genExpr(un->arg);
            std::string op = trim(un->op);
            if (op == "-") {
                // a = 0 - a
                int tmp = alloc();
                emitLiImm(tmp, 0);
                emit(reg32::Mnemonic::sub, {R(tmp), R(a)}, "0 - a");
                // move back to a
                emit(reg32::Mnemonic::mov, {R(a), R(tmp)});
                release(tmp);
            } else if (op == "!") {
                // a = (a == 0)
                int z = alloc();
                emitLiImm(z, 0);
                emit(reg32::Mnemonic::eq, {R(a), R(z)}, "a==0");
                release(z);
            }
            return a;
        }

        if (auto bin = std::dynamic_pointer_cast<BinaryExpr>(e)) {
    // Сначала считаем lhs
    int l = genExpr(bin->lhs);

    // Если rhs содержит call, то l надо сохранить через стек
    const bool spillL = containsCall(bin->rhs);
    if (spillL) {
        emit(reg32::Mnemonic::push, {R(l)}, "spill lhs");
        // ⚠️ l нельзя release, он нам ещё нужен после pop
    }

    // Теперь считаем rhs
    int r = genExpr(bin->rhs);

    // Восстанавливаем lhs, если сохраняли
    if (spillL) {
        emit(reg32::Mnemonic::pop, {R(l)}, "restore lhs");
    }

    std::string op = trim(bin->op);

    auto emitRR = [&](reg32::Mnemonic m) { emit(m, {R(l), R(r)}); };

    if (op == "+") emitRR(reg32::Mnemonic::add);
    else if (op == "-") emitRR(reg32::Mnemonic::sub);
    else if (op == "*") emitRR(reg32::Mnemonic::mul);
    else if (op == "/") emitRR(reg32::Mnemonic::div);
    else if (op == "%") emitRR(reg32::Mnemonic::mod);
    else if (op == "==") emitRR(reg32::Mnemonic::eq);
    else if (op == "!=") emitRR(reg32::Mnemonic::neq);
    else if (op == "<") emitRR(reg32::Mnemonic::lt);
    else if (op == ">") emitRR(reg32::Mnemonic::gt);
    else if (op == "<=") emitRR(reg32::Mnemonic::le);
    else if (op == ">=") emitRR(reg32::Mnemonic::ge);
    else if (op == "&&") {
        int z = alloc();
        emitLiImm(z, 0);
        emit(reg32::Mnemonic::neq, {R(l), R(z)});
        emit(reg32::Mnemonic::neq, {R(r), R(z)});
        emit(reg32::Mnemonic::mul, {R(l), R(r)});
        release(z);
    } else if (op == "||") {
        int z = alloc();
        emitLiImm(z, 0);
        emit(reg32::Mnemonic::neq, {R(l), R(z)});
        emit(reg32::Mnemonic::neq, {R(r), R(z)});
        emit(reg32::Mnemonic::add, {R(l), R(r)});
        emit(reg32::Mnemonic::neq, {R(l), R(z)});
        release(z);
    } else {
        emitLiImm(l, 0, "WARN: unsupported op '" + op + "'");
    }

    release(r);
    return l;
}


        if (auto asg = std::dynamic_pointer_cast<AssignExpr>(e)) {
            auto lhsVar = std::dynamic_pointer_cast<VarExpr>(asg->lhs);
            int rhs = genExpr(asg->rhs);
            if (lhsVar) genStoreVar(lhsVar->name, rhs);
            return rhs;
        }

                // --- CallExpr as expression: a := readInt(); ---
        if (auto call = std::dynamic_pointer_cast<CallExpr>(e)) {
            // args -> r0..r3 (минимальная конвенция)
            for (size_t i = 0; i < call->args.size() && i < 4; ++i) {
                int ar = genExpr(call->args[i]);
                if ((int)i != ar)
                    emit(reg32::Mnemonic::mov, { reg32::Operand::reg((int)i), reg32::Operand::reg(ar) });
            }

            // call label
            emit(reg32::Mnemonic::call, { reg32::Operand::codeLabel(fnLabel(call->callee)) });

            // return value in r0 -> copy to a fresh temp if needed
            int dst = alloc();
            if (dst != 0)
                emit(reg32::Mnemonic::mov, { reg32::Operand::reg(dst), reg32::Operand::reg(0) });

            return dst;
        }


        int r = alloc();
        emitLiImm(r, 0, "WARN: unknown expr");
        return r;
    }

    void genStmtTrees(const std::vector<ExprPtr>& trees) {
        for (const auto& t : trees) {
            int r = genExpr(t);
            release(r);
        }
    }
};

// Create global data labels for all variables in all functions.
static void emitAllVariables(ImageBuilder& out,
                             const CallGraph& cg,
                             std::unordered_map<std::string, VarLayout>& perFn) {
    for (const auto& fkv : cg.functionGraphs) {
        const std::string& fnName = fkv.first;
        const OpGraph& g = *fkv.second;

        VarLayout layout;
        for (const auto& vkv : g.variables) {
            const std::string& var = vkv.first;
            std::string raw = "var_" + fnLabel(fnName) + "_" + sanitizeLabel(var);
            std::string qual = raw;
            out.emitDataLabel(raw, qual);
            out.emitDataDD(0, var);
            layout.varLabel[var] = qual;
        }
        perFn[fnName] = std::move(layout);
    }
}

} // namespace

CodeGenResult buildProgramImage(const CallGraph& cg) {
    ImageBuilder out;
    CodeGenResult res;

    // 1) Data section: allocate variables as dd 0 with labels.
    emitAllVariables(out, cg, res.vars);

    // 2) Code section: emit each function as a labeled block.
    for (const auto& fkv : cg.functionGraphs) {
        const std::string& fnName = fkv.first;
        const OpGraph& g = *fkv.second;
        if (!g.is_defined || g.is_extern) {
            continue;
        }

        FnEmitter fe(out, g);
        // import var labels
        auto it = res.vars.find(fnName);
        if (it != res.vars.end()) fe.varLabel = it->second.varLabel;

        const std::string entry = fe.fnEntryLabel;
        out.emitCodeLabel(entry, entry);

        // set entry label for main (if present)
        if (fnName == "main") {
            out.image.entryLabel = entry;
        }

        // prolog only for main: init stack pointers in DATA space
        if (fnName == "main") {
            fe.emit(reg32::Mnemonic::ldsp, {reg32::Operand::imm16(static_cast<std::int16_t>(0xFFFC))}, "init sp");
            fe.emit(reg32::Mnemonic::ldbp, {reg32::Operand::imm16(static_cast<std::int16_t>(0xFFFC))}, "init bp");
        }

        // ---- stack-frame prolog: reserve locals and save args ----
        fe.emitFrameProlog();


        // Emit CFG nodes in RPO order
        auto order = reversePostOrder(g);
        for (CFGNode* n : order) {
            if (!n) continue;
            if (n->type == NodeType::ENTRY) continue;

            std::string lbl = nodeLabel(n);
            out.emitCodeLabel(lbl, lbl);

            switch (n->type) {
                case NodeType::BASIC_BLOCK:
                case NodeType::LOOP_BODY: {
                    fe.genStmtTrees(n->exprTrees);
                    if (!n->successors.empty()) {
                        fe.emit(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(nodeLabel(n->successors[0]))});
                    }
                    break;
                }

                case NodeType::CONDITION: {
                    int r = fe.genExpr(n->conditionTree);
                    CFGNode* t = n->true_branch;
                    CFGNode* f = n->false_branch;
                    if (!t && !n->successors.empty()) t = n->successors[0];
                    if (!f && n->successors.size() > 1) f = n->successors[1];
                    if (!t) t = f;
                    if (!f) f = t;

                    fe.emit(reg32::Mnemonic::jnz, {FnEmitter::R(r), reg32::Operand::codeLabel(nodeLabel(t))});
                    fe.emit(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(nodeLabel(f))});
                    fe.release(r);
                    break;
                }

                case NodeType::LOOP_HEADER: {
                    int r = fe.genExpr(n->conditionTree);
                    CFGNode* body = n->loop_body;
                    CFGNode* ex = n->loop_exit;
                    if (!body && !n->successors.empty()) body = n->successors[0];
                    if (!ex && n->successors.size() > 1) ex = n->successors[1];
                    if (!body) body = ex;
                    if (!ex) ex = body;

                    if (n->is_until) {
                        fe.emit(reg32::Mnemonic::jnz, {FnEmitter::R(r), reg32::Operand::codeLabel(nodeLabel(ex))});
                        fe.emit(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(nodeLabel(body))});
                    } else {
                        fe.emit(reg32::Mnemonic::jnz, {FnEmitter::R(r), reg32::Operand::codeLabel(nodeLabel(body))});
                        fe.emit(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(nodeLabel(ex))});
                    }
                    fe.release(r);
                    break;
                }

                case NodeType::MERGE:
                case NodeType::LOOP_EXIT: {
                    if (!n->successors.empty()) {
                        fe.emit(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(nodeLabel(n->successors[0]))});
                    }
                    break;
                }

                case NodeType::CALL: {
                    const std::string callee = getCalleeFromCallLabel(n->label);
                    const std::string calleeLbl = fnLabel(callee);

                    for (std::size_t i = 0; i < n->exprTrees.size() && i < 4; ++i) {
                        int a = fe.genExpr(n->exprTrees[i]);
                        fe.emit(reg32::Mnemonic::mov, {reg32::Operand::reg(static_cast<std::uint8_t>(i)), FnEmitter::R(a)}, "arg");
                        fe.release(a);
                    }

                    fe.emit(reg32::Mnemonic::call, {reg32::Operand::codeLabel(calleeLbl)});

                    if (!n->successors.empty()) {
                        fe.emit(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(nodeLabel(n->successors[0]))});
                    }
                    break;
                }

                case NodeType::EXIT: {
                if (n->returnExpr) {
                    int v = fe.genExpr(n->returnExpr);
                    if (v != 0) fe.emit(reg32::Mnemonic::mov, {FnEmitter::R(0), FnEmitter::R(v)}, "return");
                    fe.release(v);
                } else {
                    fe.emitLiImm(0, 0, "return default 0");
                }
                fe.emit(reg32::Mnemonic::ret);
                break;
            }


                default: {
                    if (!n->successors.empty()) {
                        fe.emit(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(nodeLabel(n->successors[0]))});
                    }
                    break;
                }
            }
        }
    }

        
// ====================================================
// Builtin stdlib stubs (auto-added if referenced and not user-defined)
// ====================================================

auto isUserDefined = [&](const std::string& name) -> bool {
    auto it = cg.functionGraphs.find(name);
    if (it == cg.functionGraphs.end()) return false;
    const OpGraph& gg = *it->second;
    return gg.is_defined && !gg.is_extern;
};

// Detect calls to builtins (NodeType::CALL + CallExpr inside expression trees)
std::set<std::string> called;

std::function<void(const ExprPtr&)> collectCalls;
collectCalls = [&](const ExprPtr& e) {
    if (!e) return;
    if (auto call = std::dynamic_pointer_cast<CallExpr>(e)) {
        called.insert(call->callee);
        for (const auto& a : call->args) collectCalls(a);
        return;
    }
    if (auto un = std::dynamic_pointer_cast<UnaryExpr>(e)) {
        collectCalls(un->arg);
        return;
    }
    if (auto bin = std::dynamic_pointer_cast<BinaryExpr>(e)) {
        collectCalls(bin->lhs);
        collectCalls(bin->rhs);
        return;
    }
    if (auto asg = std::dynamic_pointer_cast<AssignExpr>(e)) {
        collectCalls(asg->lhs);
        collectCalls(asg->rhs);
        return;
    }
    // LiteralExpr / VarExpr / others: nothing
};

for (const auto& fkv : cg.functionGraphs) {
    const OpGraph& g2 = *fkv.second;
    auto order2 = reversePostOrder(g2);
    for (CFGNode* n2 : order2) {
        if (!n2) continue;

        if (n2->type == NodeType::CALL) {
            called.insert(getCalleeFromCallLabel(n2->label));
        }

        for (const auto& t : n2->exprTrees) collectCalls(t);
        collectCalls(n2->conditionTree);
    }
}

// Helpers to emit builtins without FnEmitter
auto emitFnLabel = [&](const std::string& name) { out.emitCodeLabel(name, name); };

auto emitI = [&](reg32::Mnemonic m, std::vector<reg32::Operand> ops = {}, std::string cmt = {}) {
    reg32::Instruction ins;
    ins.mnemonic = m;
    ins.operands = std::move(ops);
    ins.comment = std::move(cmt);
    out.emitInstr(ins);

    for (std::size_t i = 0; i < ins.operands.size(); ++i) {
        const auto& op = ins.operands[i];
        if (op.kind == reg32::OperandKind::LabelRef) {
            out.addFixupForLastInstr(i, op.label, op.labelSpace);
        }
    }
};

auto R = [&](int r) { return reg32::Operand::reg(static_cast<std::uint8_t>(r)); };
auto LI = [&](int r, int v, std::string cmt = {}) {
    emitI(reg32::Mnemonic::li, {R(r), reg32::Operand::imm16(static_cast<std::int16_t>(v))}, std::move(cmt));
};
auto JNZ = [&](int r, const std::string& lbl) {
    emitI(reg32::Mnemonic::jnz, {R(r), reg32::Operand::codeLabel(lbl)});
};
auto JMP = [&](const std::string& lbl) {
    emitI(reg32::Mnemonic::jmp, {reg32::Operand::codeLabel(lbl)});
};


if (called.count("readChar") && !isUserDefined("readChar")) {
    const std::string L_loop = "__bi_readChar_loop";
    emitFnLabel("readChar");
    emitFnLabel(L_loop);
    emitI(reg32::Mnemonic::in, {R(0)});  // r0 = next byte

    // if r0 is whitespace -> read again
    // space 32
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 32);
    emitI(reg32::Mnemonic::eq, {R(1), R(2)});
    JNZ(1, L_loop);

    // tab 9
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 9);
    emitI(reg32::Mnemonic::eq, {R(1), R(2)});
    JNZ(1, L_loop);

    // nl 10
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 10);
    emitI(reg32::Mnemonic::eq, {R(1), R(2)});
    JNZ(1, L_loop);

    // cr 13
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 13);
    emitI(reg32::Mnemonic::eq, {R(1), R(2)});
    JNZ(1, L_loop);

    emitI(reg32::Mnemonic::ret);
}

// ---- writeChar(char ch) ----
if (called.count("writeChar") && !isUserDefined("writeChar")) {
    emitFnLabel("writeChar");
    emitI(reg32::Mnemonic::out, {R(0)}); // write low byte of r0
    emitI(reg32::Mnemonic::ret);
}

// ---- readInt(): int ----
// Reads signed decimal integer from byte stream.
// Skips whitespace: ' ', '\\t', '\\n', '\\r' (covers Windows CRLF).
// Stops on first non-digit after optional sign and digits (delimiter consumed).
if (called.count("readInt") && !isUserDefined("readInt")) {
    const std::string L_skip = "__bi_readInt_skip";
    const std::string L_afterws = "__bi_readInt_afterws";
    const std::string L_digit = "__bi_readInt_digit";
    const std::string L_done = "__bi_readInt_done";
    const std::string L_neg = "__bi_readInt_neg";
    const std::string L_applyNeg = "__bi_readInt_applyNeg";

    emitFnLabel("readInt");

    // r1 = acc (0)
    LI(1, 0, "acc=0");
    // r2 = sign (1)
    LI(2, 1, "sign=1");

    emitFnLabel(L_skip);
    emitI(reg32::Mnemonic::in, {R(3)}, "c=in");

    // if c == ' ' or '\\t' or '\\n' or '\\r' then continue skipping
    // tmp in r4
    // space 32
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 32);
    emitI(reg32::Mnemonic::eq, {R(4), R(5)});
    JNZ(4, L_skip);

    // tab 9
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 9);
    emitI(reg32::Mnemonic::eq, {R(4), R(5)});
    JNZ(4, L_skip);

    // nl 10
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 10);
    emitI(reg32::Mnemonic::eq, {R(4), R(5)});
    JNZ(4, L_skip);

    // cr 13
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 13);
    emitI(reg32::Mnemonic::eq, {R(4), R(5)});
    JNZ(4, L_skip);

    // optional '-'
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 45); // '-'
    emitI(reg32::Mnemonic::eq, {R(4), R(5)});
    JNZ(4, L_neg);
    JMP(L_afterws);

    emitFnLabel(L_neg);
    LI(2, -1, "sign=-1");
    emitI(reg32::Mnemonic::in, {R(3)}, "c=in after '-'");

    emitFnLabel(L_afterws);
    // digit loop: while '0'<=c<='9'
    emitFnLabel(L_digit);

    // r4 = (c >= '0')
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 48); // '0'
    emitI(reg32::Mnemonic::ge, {R(4), R(5)});
    // if not >= '0' -> done
    // (jnz goes when true, so invert via tmp)
    // r4 is 0/1 already. If r4 == 0 -> done:
    // We'll do: r6= r4; li r7,1; eq r6,r7; jnz r6, continue; else done
    emitI(reg32::Mnemonic::mov, {R(6), R(4)});
    LI(7, 1);
    emitI(reg32::Mnemonic::eq, {R(6), R(7)});
    JNZ(6, "__bi_readInt_chk_hi");
    JMP(L_done);

    emitFnLabel("__bi_readInt_chk_hi");
    // r4 = (c <= '9')
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 57); // '9'
    emitI(reg32::Mnemonic::le, {R(4), R(5)});

    emitI(reg32::Mnemonic::mov, {R(6), R(4)});
    LI(7, 1);
    emitI(reg32::Mnemonic::eq, {R(6), R(7)});
    JNZ(6, "__bi_readInt_do_digit");
    JMP(L_done);

    emitFnLabel("__bi_readInt_do_digit");
    // digit = c - '0'  (reuse r4 as digit)
    emitI(reg32::Mnemonic::mov, {R(4), R(3)});
    LI(5, 48);
    emitI(reg32::Mnemonic::sub, {R(4), R(5)}, "digit=c-'0'");

    // acc = acc*10 + digit
    LI(5, 10);
    emitI(reg32::Mnemonic::mul, {R(1), R(5)}, "acc*=10");
    emitI(reg32::Mnemonic::add, {R(1), R(4)}, "acc+=digit");

    // read next char and continue
    emitI(reg32::Mnemonic::in, {R(3)}, "c=in next");
    JMP(L_digit);

    emitFnLabel(L_done);
    // apply sign if negative: if sign == -1 then acc = 0 - acc
    emitI(reg32::Mnemonic::mov, {R(4), R(2)});
    LI(5, -1);
    emitI(reg32::Mnemonic::eq, {R(4), R(5)});
    JNZ(4, L_applyNeg);

    // return acc
    emitI(reg32::Mnemonic::mov, {R(0), R(1)}, "ret=acc");
    emitI(reg32::Mnemonic::ret);

    emitFnLabel(L_applyNeg);
    LI(5, 0);
    emitI(reg32::Mnemonic::mov, {R(0), R(5)});
    emitI(reg32::Mnemonic::sub, {R(0), R(1)}, "0-acc");
    emitI(reg32::Mnemonic::ret);
}

// ---- writeInt(int x) ----
// Prints signed decimal integer to stdout as ASCII digits.
// Uses helper __writeUInt for positive values.
if (called.count("writeInt") && !isUserDefined("writeInt")) {
    const std::string L_zero = "__bi_writeInt_zero";
    const std::string L_neg = "__bi_writeInt_neg";
    const std::string L_done = "__bi_writeInt_done";

    const std::string H = "__writeUInt";
    const std::string H_base = "__bi_writeUInt_base";
    const std::string H_recur = "__bi_writeUInt_recur";
    const std::string H_after = "__bi_writeUInt_after";

    // helper first (safe even if unused directly)
    emitFnLabel(H);
    // if (r0 < 10) goto base
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 10);
    emitI(reg32::Mnemonic::lt, {R(1), R(2)});
    JNZ(1, H_base);
    JMP(H_recur);

    emitFnLabel(H_base);
    // out('0' + r0)
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 48);
    emitI(reg32::Mnemonic::add, {R(1), R(2)});
    emitI(reg32::Mnemonic::out, {R(1)});
    emitI(reg32::Mnemonic::ret);

    emitFnLabel(H_recur);
    // Save n
    emitI(reg32::Mnemonic::push, {R(0)}, "push n");
    // q = n/10
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 10);
    emitI(reg32::Mnemonic::div, {R(1), R(2)}, "q=n/10");
    // call __writeUInt(q)
    emitI(reg32::Mnemonic::mov, {R(0), R(1)});
    emitI(reg32::Mnemonic::call, {reg32::Operand::codeLabel(H)});
    // restore n into r3
    emitI(reg32::Mnemonic::pop, {R(3)}, "pop n");
    // rem = n % 10
    emitI(reg32::Mnemonic::mov, {R(1), R(3)});
    LI(2, 10);
    emitI(reg32::Mnemonic::mod, {R(1), R(2)}, "rem=n%10");
    // out('0'+rem)
    LI(2, 48);
    emitI(reg32::Mnemonic::add, {R(1), R(2)});
    emitI(reg32::Mnemonic::out, {R(1)});
    emitI(reg32::Mnemonic::ret);

    // now writeInt itself
    emitFnLabel("writeInt");

    // if x == 0 -> print '0'
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 0);
    emitI(reg32::Mnemonic::eq, {R(1), R(2)});
    JNZ(1, L_zero);

    // if x < 0 -> print '-', x = -x
    emitI(reg32::Mnemonic::mov, {R(1), R(0)});
    LI(2, 0);
    emitI(reg32::Mnemonic::lt, {R(1), R(2)});
    JNZ(1, L_neg);

    // positive: call helper
    emitI(reg32::Mnemonic::call, {reg32::Operand::codeLabel(H)});
    emitI(reg32::Mnemonic::ret);

    emitFnLabel(L_zero);
    LI(1, 48);
    emitI(reg32::Mnemonic::out, {R(1)});
    emitI(reg32::Mnemonic::ret);

    emitFnLabel(L_neg);
    // print '-'
    LI(1, 45);
    emitI(reg32::Mnemonic::out, {R(1)});
    // x = 0 - x
    LI(1, 0);
    emitI(reg32::Mnemonic::mov, {R(3), R(1)});
    emitI(reg32::Mnemonic::sub, {R(3), R(0)}, "negate");
    emitI(reg32::Mnemonic::mov, {R(0), R(3)});
    emitI(reg32::Mnemonic::call, {reg32::Operand::codeLabel(H)});
    emitI(reg32::Mnemonic::ret);
}

emitI(reg32::Mnemonic::hlt);

    res.image = std::move(out.image);
    return res;
}

} // namespace reg32_codegen


// ========================================================
// Listing printer (merged from Reg32ListingPrinter.cpp)
// ========================================================

namespace reg32 {

static const char* bankToString(reg32::BankName b) {
    switch (b) {
        case reg32::BankName::code: return "code";
        case reg32::BankName::dataMem: return "dataMem";
    }
    return "?";
}

static void printOperand(const reg32::Operand& op, std::ostream& out) {
    switch (op.kind) {
        case reg32::OperandKind::Reg: {
            out << 'r' << op.value;
            return;
        }
        case reg32::OperandKind::Imm16: {
            // print as signed decimal
            out << static_cast<int>(static_cast<std::int16_t>(op.value));
            return;
        }
        case reg32::OperandKind::LabelRef: {
            out << op.label;
            return;
        }
    }
}

static void printInstruction(const reg32::Instruction& ins, std::ostream& out) {
    out << "    " << reg32::toString(ins.mnemonic);
    if (!ins.operands.empty()) {
        out << ' ';
        for (std::size_t i = 0; i < ins.operands.size(); ++i) {
            if (i) out << ", ";
            printOperand(ins.operands[i], out);
        }
    }
    if (!ins.comment.empty()) out << "    ; " << ins.comment;
    out << "\n";
}

static void printDataDef(const reg32::DataDef& d, std::ostream& out) {
    const char* dir = "dd";
    if (d.dir == reg32::DataDirective::db) dir = "db";
    else if (d.dir == reg32::DataDirective::dw) dir = "dw";
    else if (d.dir == reg32::DataDirective::dd) dir = "dd";

    out << "    " << dir;
    if (!d.values.empty()) {
        out << ' ';
        for (std::size_t i = 0; i < d.values.size(); ++i) {
            if (i) out << ", ";
            out << d.values[i];
        }
    }
    if (!d.comment.empty()) out << "    ; " << d.comment;
    out << "\n";
}

static void printReserveDef(const reg32::ReserveDef& r, std::ostream& out) {
    const char* dir = "resd";
    if (r.dir == reg32::ReserveDirective::resb) dir = "resb";
    else if (r.dir == reg32::ReserveDirective::resw) dir = "resw";
    else if (r.dir == reg32::ReserveDirective::resd) dir = "resd";

    out << "    " << dir << ' ' << r.count;
    if (!r.comment.empty()) out << "    ; " << r.comment;
    out << "\n";
}

static void printComment(const reg32::CommentLine& c, std::ostream& out) {
    if (!c.text.empty()) out << "; " << c.text << "\n";
}

static void printLineItem(const reg32::LineItem& li, std::ostream& out) {
    if (li.label.has_value()) {
        out << li.label->qualifiedName << ":\n";
    }

    if (std::holds_alternative<reg32::Instruction>(li.payload)) {
        printInstruction(std::get<reg32::Instruction>(li.payload), out);
    } else if (std::holds_alternative<reg32::DataDef>(li.payload)) {
        printDataDef(std::get<reg32::DataDef>(li.payload), out);
    } else if (std::holds_alternative<reg32::ReserveDef>(li.payload)) {
        printReserveDef(std::get<reg32::ReserveDef>(li.payload), out);
    } else if (std::holds_alternative<reg32::CommentLine>(li.payload)) {
        printComment(std::get<reg32::CommentLine>(li.payload), out);
    } else if (std::holds_alternative<std::shared_ptr<reg32::Times>>(li.payload)) {
        // Not used by current codegen; keep minimal support.
        const auto& t = *std::get<std::shared_ptr<reg32::Times>>(li.payload);
        out << "    times " << t.count << " ";
        // times wraps a single item; print it inline without label.
        reg32::LineItem& inner = *t.item;
        inner.label.reset();
        if (std::holds_alternative<reg32::DataDef>(inner.payload)) {
            // print data def after 'times'
            const auto& d = std::get<reg32::DataDef>(inner.payload);
            const char* dir = (d.dir == reg32::DataDirective::db) ? "db" : (d.dir == reg32::DataDirective::dw) ? "dw" : "dd";
            out << dir;
            if (!d.values.empty()) {
                out << ' ';
                for (std::size_t i = 0; i < d.values.size(); ++i) {
                    if (i) out << ", ";
                    out << d.values[i];
                }
            }
            if (!d.comment.empty()) out << "    ; " << d.comment;
            out << "\n";
        } else {
            // Fallback: print as comment
            out << "; (unsupported times payload)\n";
        }
    }
}

void printListing(const reg32::ProgramImage& img, std::ostream& out) {

    for (const auto& sec : img.sections) {
        out << "[section " << (sec.decl.bank.has_value() ? bankToString(*sec.decl.bank) : sec.decl.name.c_str()) << "]" << "\n";

        for (const auto& li : sec.lines) {
            printLineItem(li, out);
        }
        out << "\n";
    }
}

} // namespace reg32