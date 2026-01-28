#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace reg32 {

enum class BankName { code, dataMem };
struct SectionDecl {
    std::string name;
    std::optional<BankName> bank;
    std::optional<std::uint16_t> startAddr;
};

enum class Mnemonic {
    
    li,
    mov,
    load,
    store,

    add,
    sub,
    mul,
    div,
    mod,

    eq,
    neq,
    lt,
    gt,
    le,
    ge,

    jmp,
    jnz,
    call,
    ret,

    ldsp,
    ldbp,

    push,
    pop,

    getbp,
    getsp,

    setio,
    in,
    out,
    
    hlt
};

inline const char* toString(Mnemonic m) {
    switch (m) {
        case Mnemonic::li: return "li";
        case Mnemonic::mov: return "mov";
        case Mnemonic::load: return "load";
        case Mnemonic::store: return "store";
        case Mnemonic::add: return "add";
        case Mnemonic::sub: return "sub";
        case Mnemonic::mul: return "mul";
        case Mnemonic::div: return "div";
        case Mnemonic::mod: return "mod";
        case Mnemonic::eq: return "eq";
        case Mnemonic::neq: return "neq";
        case Mnemonic::lt: return "lt";
        case Mnemonic::gt: return "gt";
        case Mnemonic::le: return "le";
        case Mnemonic::ge: return "ge";
        case Mnemonic::jmp: return "jmp";
        case Mnemonic::jnz: return "jnz";
        case Mnemonic::call: return "call";
        case Mnemonic::ret: return "ret";
        case Mnemonic::ldsp: return "ldsp";
        case Mnemonic::ldbp: return "ldbp";
        case Mnemonic::push: return "push";
        case Mnemonic::pop: return "pop";
        case Mnemonic::getbp: return "getbp";
        case Mnemonic::getsp: return "getsp";
        case Mnemonic::setio: return "setio";
        case Mnemonic::in: return "in";
        case Mnemonic::out: return "out";
        case Mnemonic::hlt: return "hlt";
    }
    return "?";
}

struct Label {
    std::string rawName;
    std::string qualifiedName;
};

enum class LabelSpace { Code, Data };

enum class OperandKind { Reg, Imm16, LabelRef };

struct Operand {
    OperandKind kind{OperandKind::Imm16};
    std::uint32_t value{0};          
    std::string label;               
    LabelSpace labelSpace{LabelSpace::Code};

    static Operand reg(std::uint8_t r) {
        Operand o;
        o.kind = OperandKind::Reg;
        o.value = r;
        return o;
    }

    static Operand imm16(std::int16_t v) {
        Operand o;
        o.kind = OperandKind::Imm16;
        o.value = static_cast<std::uint16_t>(v);
        return o;
    }

    static Operand codeLabel(std::string lbl) {
        Operand o;
        o.kind = OperandKind::LabelRef;
        o.label = std::move(lbl);
        o.labelSpace = LabelSpace::Code;
        return o;
    }

    static Operand dataLabel(std::string lbl) {
        Operand o;
        o.kind = OperandKind::LabelRef;
        o.label = std::move(lbl);
        o.labelSpace = LabelSpace::Data;
        return o;
    }
};

struct Instruction {
    Mnemonic mnemonic{Mnemonic::li};
    std::vector<Operand> operands;
    std::string comment;
};

enum class DataDirective { db, dw, dd };
enum class ReserveDirective { resb, resw, resd };

struct DataDef {
    DataDirective dir{DataDirective::dd};
    std::vector<std::uint32_t> values;
    std::string comment;
};

struct ReserveDef {
    ReserveDirective dir{ReserveDirective::resd};
    std::uint32_t count{0};
    std::string comment;
};

struct CommentLine {
    std::string text;
};

struct LineItem;
struct Times;

struct LineItem {
    std::optional<Label> label;
    std::variant<Instruction, DataDef, ReserveDef, CommentLine, std::shared_ptr<Times>> payload;
};

struct Times {
    std::uint32_t count{0};
    std::shared_ptr<LineItem> item;
};

struct Section {
    SectionDecl decl;
    std::vector<LineItem> lines;
};

struct Fixup {
    std::size_t sectionIndex{0};
    std::size_t lineIndex{0};
    std::size_t operandIndex{0};
    std::string targetLabel;
    LabelSpace targetSpace{LabelSpace::Code};
};

struct ProgramImage {
    std::vector<Section> sections;
    std::optional<std::string> entryLabel;
    std::vector<Fixup> fixups;
};
void printListing(const reg32::ProgramImage& img, std::ostream& out);
} 
