grammar Hello;

// ---------------- Source ----------------
source
    : sourceItem* EOF
    ;

sourceItem
    : funcDef
    ;

// ---------------- Functions ----------------
funcDef
    : 'method' funcSignature (body | ';')
    ;

funcSignature
    : identifier '(' argList? ')' (':' typeRef)?
    ;

argList
    : argDef (',' argDef)*
    ;

argDef
    : identifier (':' typeRef)?
    ;

// ---------------- Body ----------------
body
    : ('var' varDeclList)* statementBlock
    ;

varDeclList
    : identifier (',' identifier)* (':' typeRef)? ';'
    ;

statementBlock
    : 'begin' statement* 'end' ';'
    ;

// ---------------- Statements ----------------
statement
    : ifStatement
    | whileStatement
    | doStatement
    | statementBlock
    | exprStatement
    ;

ifStatement
    : 'if' expr 'then' statement ('else' statement)?
    ;

whileStatement
    : 'while' expr 'do' statement
    ;

doStatement
    : 'repeat' statement ('while' | 'until') expr ';'
    ;

exprStatement
    : expr ';'
    ;

// ---------------- Expressions ----------------
expr
    : assignExpr
    ;

assignExpr
    : logicalOrExpr (':=' assignExpr)?
    ;

logicalOrExpr
    : logicalAndExpr ('||' logicalAndExpr)*
    ;

logicalAndExpr
    : compareExpr ('&&' compareExpr)*
    ;

compareExpr
    : addSubExpr (('<' | '<=' | '>' | '>=' | '==' | '!=') addSubExpr)*
    ;

addSubExpr
    : mulDivExpr (('+' | '-') mulDivExpr)*
    ;

mulDivExpr
    : unaryExpr (('*' | '/' | '%') unaryExpr)*
    ;

unaryExpr
    : ('!' | '+' | '-') unaryExpr
    | primaryExpr
    ;

callExpr
    : identifier '(' exprList? ')'
    ;

primaryExpr
    : literal
    | identifier
    | callExpr
    | primaryExpr '[' exprList? ']'
    | '(' expr ')'
    ;


// ---------------- Expression List ----------------
exprList
    : expr (',' expr)*
    ;

// ---------------- Types ----------------
typeRef
    : builtinType
    | identifier
    | 'array' '[' (',' )* ']' 'of' typeRef
    ;

builtinType
    : 'bool' | 'byte' | 'int' | 'uint' | 'long' | 'ulong' | 'char' | 'string'
    ;

// ---------------- Literals ----------------
literal
    : BoolLiteral
    | StringLiteral
    | CharLiteral
    | HexLiteral
    | BitsLiteral
    | DecimalLiteral
    ;

// ---------------- Lexer ----------------
VAR: 'var';

BoolLiteral
    : 'true' | 'false'
    ;

StringLiteral
    : '"' (ESC_SEQ | ~["\\\r\n])* '"'
    ;

CharLiteral
    : '\'' (ESC_SEQ | ~['\\\r\n]) '\''
    ;

HexLiteral
    : '0' [xX] HexDigit+
    ;

BitsLiteral
    : '0' [bB] [01]+
    ;

DecimalLiteral
    : Digit+ ('.' Digit+)? ([eE] [+-]? Digit+)?
    ;

identifier
    : Identifier
    ;

Identifier
    : [a-zA-Z_] [a-zA-Z0-9_]*
    ;

WS
    : [ \t\r\n\u000C]+ -> skip
    ;

LINE_COMMENT
    : '//' ~[\r\n]* -> skip
    ;

BLOCK_COMMENT
    : '/*' .*? '*/' -> skip
    ;

// Fragments
fragment Digit : [0-9];
fragment HexDigit : [0-9a-fA-F];
fragment ESC_SEQ
    : '\\' [btnfr"'\\]
    | '\\' 'u' HexDigit HexDigit HexDigit HexDigit
    ;
