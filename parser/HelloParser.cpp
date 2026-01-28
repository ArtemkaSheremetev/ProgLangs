
// Generated from Hello.g4 by ANTLR 4.13.2


#include "HelloVisitor.h"

#include "HelloParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct HelloParserStaticData final {
  HelloParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  HelloParserStaticData(const HelloParserStaticData&) = delete;
  HelloParserStaticData(HelloParserStaticData&&) = delete;
  HelloParserStaticData& operator=(const HelloParserStaticData&) = delete;
  HelloParserStaticData& operator=(HelloParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag helloParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<HelloParserStaticData> helloParserStaticData = nullptr;

void helloParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (helloParserStaticData != nullptr) {
    return;
  }
#else
  assert(helloParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<HelloParserStaticData>(
    std::vector<std::string>{
      "source", "sourceItem", "funcDef", "funcSignature", "argList", "argDef", 
      "body", "varDeclList", "statementBlock", "statement", "returnStatement", 
      "ifStatement", "whileStatement", "doStatement", "exprStatement", "expr", 
      "assignExpr", "logicalOrExpr", "logicalAndExpr", "compareExpr", "addSubExpr", 
      "mulDivExpr", "unaryExpr", "callExpr", "primaryExpr", "exprList", 
      "typeRef", "builtinType", "literal", "identifier"
    },
    std::vector<std::string>{
      "", "'method'", "';'", "'('", "')'", "':'", "','", "'begin'", "'end'", 
      "'return'", "'if'", "'then'", "'else'", "'while'", "'do'", "'repeat'", 
      "'until'", "':='", "'||'", "'&&'", "'<'", "'<='", "'>'", "'>='", "'=='", 
      "'!='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['", "']'", "'array'", 
      "'of'", "'bool'", "'byte'", "'int'", "'uint'", "'long'", "'ulong'", 
      "'char'", "'string'", "'var'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "VAR", "BoolLiteral", "StringLiteral", 
      "CharLiteral", "HexLiteral", "BitsLiteral", "DecimalLiteral", "Identifier", 
      "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,54,278,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,1,0,5,0,62,8,0,10,0,12,0,65,9,0,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,2,1,2,3,2,75,8,2,1,3,1,3,1,3,3,3,80,8,3,1,3,1,3,1,3,3,3,85,8,3,1,4,
  	1,4,1,4,5,4,90,8,4,10,4,12,4,93,9,4,1,5,1,5,1,5,3,5,98,8,5,1,6,1,6,5,
  	6,102,8,6,10,6,12,6,105,9,6,1,6,1,6,1,7,1,7,1,7,5,7,112,8,7,10,7,12,7,
  	115,9,7,1,7,1,7,3,7,119,8,7,1,7,1,7,1,8,1,8,5,8,125,8,8,10,8,12,8,128,
  	9,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,139,8,9,1,10,1,10,3,10,143,
  	8,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,3,11,153,8,11,1,12,1,12,
  	1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,
  	1,16,1,16,1,16,3,16,174,8,16,1,17,1,17,1,17,5,17,179,8,17,10,17,12,17,
  	182,9,17,1,18,1,18,1,18,5,18,187,8,18,10,18,12,18,190,9,18,1,19,1,19,
  	1,19,5,19,195,8,19,10,19,12,19,198,9,19,1,20,1,20,1,20,5,20,203,8,20,
  	10,20,12,20,206,9,20,1,21,1,21,1,21,5,21,211,8,21,10,21,12,21,214,9,21,
  	1,22,1,22,1,22,3,22,219,8,22,1,23,1,23,1,23,3,23,224,8,23,1,23,1,23,1,
  	24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,236,8,24,1,24,1,24,1,24,3,
  	24,241,8,24,1,24,5,24,244,8,24,10,24,12,24,247,9,24,1,25,1,25,1,25,5,
  	25,252,8,25,10,25,12,25,255,9,25,1,26,1,26,1,26,1,26,1,26,5,26,262,8,
  	26,10,26,12,26,265,9,26,1,26,1,26,1,26,3,26,270,8,26,1,27,1,27,1,28,1,
  	28,1,29,1,29,1,29,0,1,48,30,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,0,7,2,0,13,13,16,16,1,0,20,
  	25,1,0,26,27,1,0,28,30,2,0,26,27,31,31,1,0,36,43,1,0,45,50,281,0,63,1,
  	0,0,0,2,68,1,0,0,0,4,70,1,0,0,0,6,76,1,0,0,0,8,86,1,0,0,0,10,94,1,0,0,
  	0,12,103,1,0,0,0,14,108,1,0,0,0,16,122,1,0,0,0,18,138,1,0,0,0,20,140,
  	1,0,0,0,22,146,1,0,0,0,24,154,1,0,0,0,26,159,1,0,0,0,28,165,1,0,0,0,30,
  	168,1,0,0,0,32,170,1,0,0,0,34,175,1,0,0,0,36,183,1,0,0,0,38,191,1,0,0,
  	0,40,199,1,0,0,0,42,207,1,0,0,0,44,218,1,0,0,0,46,220,1,0,0,0,48,235,
  	1,0,0,0,50,248,1,0,0,0,52,269,1,0,0,0,54,271,1,0,0,0,56,273,1,0,0,0,58,
  	275,1,0,0,0,60,62,3,2,1,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,
  	64,1,0,0,0,64,66,1,0,0,0,65,63,1,0,0,0,66,67,5,0,0,1,67,1,1,0,0,0,68,
  	69,3,4,2,0,69,3,1,0,0,0,70,71,5,1,0,0,71,74,3,6,3,0,72,75,3,12,6,0,73,
  	75,5,2,0,0,74,72,1,0,0,0,74,73,1,0,0,0,75,5,1,0,0,0,76,77,3,58,29,0,77,
  	79,5,3,0,0,78,80,3,8,4,0,79,78,1,0,0,0,79,80,1,0,0,0,80,81,1,0,0,0,81,
  	84,5,4,0,0,82,83,5,5,0,0,83,85,3,52,26,0,84,82,1,0,0,0,84,85,1,0,0,0,
  	85,7,1,0,0,0,86,91,3,10,5,0,87,88,5,6,0,0,88,90,3,10,5,0,89,87,1,0,0,
  	0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,9,1,0,0,0,93,91,1,0,0,
  	0,94,97,3,58,29,0,95,96,5,5,0,0,96,98,3,52,26,0,97,95,1,0,0,0,97,98,1,
  	0,0,0,98,11,1,0,0,0,99,100,5,44,0,0,100,102,3,14,7,0,101,99,1,0,0,0,102,
  	105,1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,106,1,0,0,0,105,103,1,
  	0,0,0,106,107,3,16,8,0,107,13,1,0,0,0,108,113,3,58,29,0,109,110,5,6,0,
  	0,110,112,3,58,29,0,111,109,1,0,0,0,112,115,1,0,0,0,113,111,1,0,0,0,113,
  	114,1,0,0,0,114,118,1,0,0,0,115,113,1,0,0,0,116,117,5,5,0,0,117,119,3,
  	52,26,0,118,116,1,0,0,0,118,119,1,0,0,0,119,120,1,0,0,0,120,121,5,2,0,
  	0,121,15,1,0,0,0,122,126,5,7,0,0,123,125,3,18,9,0,124,123,1,0,0,0,125,
  	128,1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,127,129,1,0,0,0,128,126,1,
  	0,0,0,129,130,5,8,0,0,130,131,5,2,0,0,131,17,1,0,0,0,132,139,3,20,10,
  	0,133,139,3,22,11,0,134,139,3,24,12,0,135,139,3,26,13,0,136,139,3,16,
  	8,0,137,139,3,28,14,0,138,132,1,0,0,0,138,133,1,0,0,0,138,134,1,0,0,0,
  	138,135,1,0,0,0,138,136,1,0,0,0,138,137,1,0,0,0,139,19,1,0,0,0,140,142,
  	5,9,0,0,141,143,3,30,15,0,142,141,1,0,0,0,142,143,1,0,0,0,143,144,1,0,
  	0,0,144,145,5,2,0,0,145,21,1,0,0,0,146,147,5,10,0,0,147,148,3,30,15,0,
  	148,149,5,11,0,0,149,152,3,18,9,0,150,151,5,12,0,0,151,153,3,18,9,0,152,
  	150,1,0,0,0,152,153,1,0,0,0,153,23,1,0,0,0,154,155,5,13,0,0,155,156,3,
  	30,15,0,156,157,5,14,0,0,157,158,3,18,9,0,158,25,1,0,0,0,159,160,5,15,
  	0,0,160,161,3,18,9,0,161,162,7,0,0,0,162,163,3,30,15,0,163,164,5,2,0,
  	0,164,27,1,0,0,0,165,166,3,30,15,0,166,167,5,2,0,0,167,29,1,0,0,0,168,
  	169,3,32,16,0,169,31,1,0,0,0,170,173,3,34,17,0,171,172,5,17,0,0,172,174,
  	3,32,16,0,173,171,1,0,0,0,173,174,1,0,0,0,174,33,1,0,0,0,175,180,3,36,
  	18,0,176,177,5,18,0,0,177,179,3,36,18,0,178,176,1,0,0,0,179,182,1,0,0,
  	0,180,178,1,0,0,0,180,181,1,0,0,0,181,35,1,0,0,0,182,180,1,0,0,0,183,
  	188,3,38,19,0,184,185,5,19,0,0,185,187,3,38,19,0,186,184,1,0,0,0,187,
  	190,1,0,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,37,1,0,0,0,190,188,1,
  	0,0,0,191,196,3,40,20,0,192,193,7,1,0,0,193,195,3,40,20,0,194,192,1,0,
  	0,0,195,198,1,0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,39,1,0,0,0,198,
  	196,1,0,0,0,199,204,3,42,21,0,200,201,7,2,0,0,201,203,3,42,21,0,202,200,
  	1,0,0,0,203,206,1,0,0,0,204,202,1,0,0,0,204,205,1,0,0,0,205,41,1,0,0,
  	0,206,204,1,0,0,0,207,212,3,44,22,0,208,209,7,3,0,0,209,211,3,44,22,0,
  	210,208,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,1,0,0,0,213,43,
  	1,0,0,0,214,212,1,0,0,0,215,216,7,4,0,0,216,219,3,44,22,0,217,219,3,48,
  	24,0,218,215,1,0,0,0,218,217,1,0,0,0,219,45,1,0,0,0,220,221,3,58,29,0,
  	221,223,5,3,0,0,222,224,3,50,25,0,223,222,1,0,0,0,223,224,1,0,0,0,224,
  	225,1,0,0,0,225,226,5,4,0,0,226,47,1,0,0,0,227,228,6,24,-1,0,228,236,
  	3,56,28,0,229,236,3,58,29,0,230,236,3,46,23,0,231,232,5,3,0,0,232,233,
  	3,30,15,0,233,234,5,4,0,0,234,236,1,0,0,0,235,227,1,0,0,0,235,229,1,0,
  	0,0,235,230,1,0,0,0,235,231,1,0,0,0,236,245,1,0,0,0,237,238,10,2,0,0,
  	238,240,5,32,0,0,239,241,3,50,25,0,240,239,1,0,0,0,240,241,1,0,0,0,241,
  	242,1,0,0,0,242,244,5,33,0,0,243,237,1,0,0,0,244,247,1,0,0,0,245,243,
  	1,0,0,0,245,246,1,0,0,0,246,49,1,0,0,0,247,245,1,0,0,0,248,253,3,30,15,
  	0,249,250,5,6,0,0,250,252,3,30,15,0,251,249,1,0,0,0,252,255,1,0,0,0,253,
  	251,1,0,0,0,253,254,1,0,0,0,254,51,1,0,0,0,255,253,1,0,0,0,256,270,3,
  	54,27,0,257,270,3,58,29,0,258,259,5,34,0,0,259,263,5,32,0,0,260,262,5,
  	6,0,0,261,260,1,0,0,0,262,265,1,0,0,0,263,261,1,0,0,0,263,264,1,0,0,0,
  	264,266,1,0,0,0,265,263,1,0,0,0,266,267,5,33,0,0,267,268,5,35,0,0,268,
  	270,3,52,26,0,269,256,1,0,0,0,269,257,1,0,0,0,269,258,1,0,0,0,270,53,
  	1,0,0,0,271,272,7,5,0,0,272,55,1,0,0,0,273,274,7,6,0,0,274,57,1,0,0,0,
  	275,276,5,51,0,0,276,59,1,0,0,0,27,63,74,79,84,91,97,103,113,118,126,
  	138,142,152,173,180,188,196,204,212,218,223,235,240,245,253,263,269
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  helloParserStaticData = std::move(staticData);
}

}

HelloParser::HelloParser(TokenStream *input) : HelloParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

HelloParser::HelloParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  HelloParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *helloParserStaticData->atn, helloParserStaticData->decisionToDFA, helloParserStaticData->sharedContextCache, options);
}

HelloParser::~HelloParser() {
  delete _interpreter;
}

const atn::ATN& HelloParser::getATN() const {
  return *helloParserStaticData->atn;
}

std::string HelloParser::getGrammarFileName() const {
  return "Hello.g4";
}

const std::vector<std::string>& HelloParser::getRuleNames() const {
  return helloParserStaticData->ruleNames;
}

const dfa::Vocabulary& HelloParser::getVocabulary() const {
  return helloParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView HelloParser::getSerializedATN() const {
  return helloParserStaticData->serializedATN;
}


//----------------- SourceContext ------------------------------------------------------------------

HelloParser::SourceContext::SourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HelloParser::SourceContext::EOF() {
  return getToken(HelloParser::EOF, 0);
}

std::vector<HelloParser::SourceItemContext *> HelloParser::SourceContext::sourceItem() {
  return getRuleContexts<HelloParser::SourceItemContext>();
}

HelloParser::SourceItemContext* HelloParser::SourceContext::sourceItem(size_t i) {
  return getRuleContext<HelloParser::SourceItemContext>(i);
}


size_t HelloParser::SourceContext::getRuleIndex() const {
  return HelloParser::RuleSource;
}


std::any HelloParser::SourceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitSource(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::SourceContext* HelloParser::source() {
  SourceContext *_localctx = _tracker.createInstance<SourceContext>(_ctx, getState());
  enterRule(_localctx, 0, HelloParser::RuleSource);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__0) {
      setState(60);
      sourceItem();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    match(HelloParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceItemContext ------------------------------------------------------------------

HelloParser::SourceItemContext::SourceItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::FuncDefContext* HelloParser::SourceItemContext::funcDef() {
  return getRuleContext<HelloParser::FuncDefContext>(0);
}


size_t HelloParser::SourceItemContext::getRuleIndex() const {
  return HelloParser::RuleSourceItem;
}


std::any HelloParser::SourceItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitSourceItem(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::SourceItemContext* HelloParser::sourceItem() {
  SourceItemContext *_localctx = _tracker.createInstance<SourceItemContext>(_ctx, getState());
  enterRule(_localctx, 2, HelloParser::RuleSourceItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    funcDef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

HelloParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::FuncSignatureContext* HelloParser::FuncDefContext::funcSignature() {
  return getRuleContext<HelloParser::FuncSignatureContext>(0);
}

HelloParser::BodyContext* HelloParser::FuncDefContext::body() {
  return getRuleContext<HelloParser::BodyContext>(0);
}


size_t HelloParser::FuncDefContext::getRuleIndex() const {
  return HelloParser::RuleFuncDef;
}


std::any HelloParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::FuncDefContext* HelloParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 4, HelloParser::RuleFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(HelloParser::T__0);
    setState(71);
    funcSignature();
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__6:
      case HelloParser::VAR: {
        setState(72);
        body();
        break;
      }

      case HelloParser::T__1: {
        setState(73);
        match(HelloParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncSignatureContext ------------------------------------------------------------------

HelloParser::FuncSignatureContext::FuncSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::IdentifierContext* HelloParser::FuncSignatureContext::identifier() {
  return getRuleContext<HelloParser::IdentifierContext>(0);
}

HelloParser::ArgListContext* HelloParser::FuncSignatureContext::argList() {
  return getRuleContext<HelloParser::ArgListContext>(0);
}

HelloParser::TypeRefContext* HelloParser::FuncSignatureContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
}


size_t HelloParser::FuncSignatureContext::getRuleIndex() const {
  return HelloParser::RuleFuncSignature;
}


std::any HelloParser::FuncSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitFuncSignature(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::FuncSignatureContext* HelloParser::funcSignature() {
  FuncSignatureContext *_localctx = _tracker.createInstance<FuncSignatureContext>(_ctx, getState());
  enterRule(_localctx, 6, HelloParser::RuleFuncSignature);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    identifier();
    setState(77);
    match(HelloParser::T__2);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::Identifier) {
      setState(78);
      argList();
    }
    setState(81);
    match(HelloParser::T__3);
    setState(84);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__4) {
      setState(82);
      match(HelloParser::T__4);
      setState(83);
      typeRef();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

HelloParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::ArgDefContext *> HelloParser::ArgListContext::argDef() {
  return getRuleContexts<HelloParser::ArgDefContext>();
}

HelloParser::ArgDefContext* HelloParser::ArgListContext::argDef(size_t i) {
  return getRuleContext<HelloParser::ArgDefContext>(i);
}


size_t HelloParser::ArgListContext::getRuleIndex() const {
  return HelloParser::RuleArgList;
}


std::any HelloParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ArgListContext* HelloParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 8, HelloParser::RuleArgList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    argDef();
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__5) {
      setState(87);
      match(HelloParser::T__5);
      setState(88);
      argDef();
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgDefContext ------------------------------------------------------------------

HelloParser::ArgDefContext::ArgDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::IdentifierContext* HelloParser::ArgDefContext::identifier() {
  return getRuleContext<HelloParser::IdentifierContext>(0);
}

HelloParser::TypeRefContext* HelloParser::ArgDefContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
}


size_t HelloParser::ArgDefContext::getRuleIndex() const {
  return HelloParser::RuleArgDef;
}


std::any HelloParser::ArgDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitArgDef(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ArgDefContext* HelloParser::argDef() {
  ArgDefContext *_localctx = _tracker.createInstance<ArgDefContext>(_ctx, getState());
  enterRule(_localctx, 10, HelloParser::RuleArgDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    identifier();
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__4) {
      setState(95);
      match(HelloParser::T__4);
      setState(96);
      typeRef();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

HelloParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::StatementBlockContext* HelloParser::BodyContext::statementBlock() {
  return getRuleContext<HelloParser::StatementBlockContext>(0);
}

std::vector<tree::TerminalNode *> HelloParser::BodyContext::VAR() {
  return getTokens(HelloParser::VAR);
}

tree::TerminalNode* HelloParser::BodyContext::VAR(size_t i) {
  return getToken(HelloParser::VAR, i);
}

std::vector<HelloParser::VarDeclListContext *> HelloParser::BodyContext::varDeclList() {
  return getRuleContexts<HelloParser::VarDeclListContext>();
}

HelloParser::VarDeclListContext* HelloParser::BodyContext::varDeclList(size_t i) {
  return getRuleContext<HelloParser::VarDeclListContext>(i);
}


size_t HelloParser::BodyContext::getRuleIndex() const {
  return HelloParser::RuleBody;
}


std::any HelloParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::BodyContext* HelloParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 12, HelloParser::RuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::VAR) {
      setState(99);
      match(HelloParser::VAR);
      setState(100);
      varDeclList();
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(106);
    statementBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclListContext ------------------------------------------------------------------

HelloParser::VarDeclListContext::VarDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::IdentifierContext *> HelloParser::VarDeclListContext::identifier() {
  return getRuleContexts<HelloParser::IdentifierContext>();
}

HelloParser::IdentifierContext* HelloParser::VarDeclListContext::identifier(size_t i) {
  return getRuleContext<HelloParser::IdentifierContext>(i);
}

HelloParser::TypeRefContext* HelloParser::VarDeclListContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
}


size_t HelloParser::VarDeclListContext::getRuleIndex() const {
  return HelloParser::RuleVarDeclList;
}


std::any HelloParser::VarDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitVarDeclList(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::VarDeclListContext* HelloParser::varDeclList() {
  VarDeclListContext *_localctx = _tracker.createInstance<VarDeclListContext>(_ctx, getState());
  enterRule(_localctx, 14, HelloParser::RuleVarDeclList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    identifier();
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__5) {
      setState(109);
      match(HelloParser::T__5);
      setState(110);
      identifier();
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__4) {
      setState(116);
      match(HelloParser::T__4);
      setState(117);
      typeRef();
    }
    setState(120);
    match(HelloParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementBlockContext ------------------------------------------------------------------

HelloParser::StatementBlockContext::StatementBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::StatementContext *> HelloParser::StatementBlockContext::statement() {
  return getRuleContexts<HelloParser::StatementContext>();
}

HelloParser::StatementContext* HelloParser::StatementBlockContext::statement(size_t i) {
  return getRuleContext<HelloParser::StatementContext>(i);
}


size_t HelloParser::StatementBlockContext::getRuleIndex() const {
  return HelloParser::RuleStatementBlock;
}


std::any HelloParser::StatementBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitStatementBlock(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::StatementBlockContext* HelloParser::statementBlock() {
  StatementBlockContext *_localctx = _tracker.createInstance<StatementBlockContext>(_ctx, getState());
  enterRule(_localctx, 16, HelloParser::RuleStatementBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(HelloParser::T__6);
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4468417604134536) != 0)) {
      setState(123);
      statement();
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(129);
    match(HelloParser::T__7);
    setState(130);
    match(HelloParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

HelloParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::ReturnStatementContext* HelloParser::StatementContext::returnStatement() {
  return getRuleContext<HelloParser::ReturnStatementContext>(0);
}

HelloParser::IfStatementContext* HelloParser::StatementContext::ifStatement() {
  return getRuleContext<HelloParser::IfStatementContext>(0);
}

HelloParser::WhileStatementContext* HelloParser::StatementContext::whileStatement() {
  return getRuleContext<HelloParser::WhileStatementContext>(0);
}

HelloParser::DoStatementContext* HelloParser::StatementContext::doStatement() {
  return getRuleContext<HelloParser::DoStatementContext>(0);
}

HelloParser::StatementBlockContext* HelloParser::StatementContext::statementBlock() {
  return getRuleContext<HelloParser::StatementBlockContext>(0);
}

HelloParser::ExprStatementContext* HelloParser::StatementContext::exprStatement() {
  return getRuleContext<HelloParser::ExprStatementContext>(0);
}


size_t HelloParser::StatementContext::getRuleIndex() const {
  return HelloParser::RuleStatement;
}


std::any HelloParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::StatementContext* HelloParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, HelloParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(132);
        returnStatement();
        break;
      }

      case HelloParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(133);
        ifStatement();
        break;
      }

      case HelloParser::T__12: {
        enterOuterAlt(_localctx, 3);
        setState(134);
        whileStatement();
        break;
      }

      case HelloParser::T__14: {
        enterOuterAlt(_localctx, 4);
        setState(135);
        doStatement();
        break;
      }

      case HelloParser::T__6: {
        enterOuterAlt(_localctx, 5);
        setState(136);
        statementBlock();
        break;
      }

      case HelloParser::T__2:
      case HelloParser::T__25:
      case HelloParser::T__26:
      case HelloParser::T__30:
      case HelloParser::BoolLiteral:
      case HelloParser::StringLiteral:
      case HelloParser::CharLiteral:
      case HelloParser::HexLiteral:
      case HelloParser::BitsLiteral:
      case HelloParser::DecimalLiteral:
      case HelloParser::Identifier: {
        enterOuterAlt(_localctx, 6);
        setState(137);
        exprStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

HelloParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::ExprContext* HelloParser::ReturnStatementContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}


size_t HelloParser::ReturnStatementContext::getRuleIndex() const {
  return HelloParser::RuleReturnStatement;
}


std::any HelloParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ReturnStatementContext* HelloParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, HelloParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(HelloParser::T__8);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4468417604091912) != 0)) {
      setState(141);
      expr();
    }
    setState(144);
    match(HelloParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

HelloParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::ExprContext* HelloParser::IfStatementContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

std::vector<HelloParser::StatementContext *> HelloParser::IfStatementContext::statement() {
  return getRuleContexts<HelloParser::StatementContext>();
}

HelloParser::StatementContext* HelloParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<HelloParser::StatementContext>(i);
}


size_t HelloParser::IfStatementContext::getRuleIndex() const {
  return HelloParser::RuleIfStatement;
}


std::any HelloParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::IfStatementContext* HelloParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, HelloParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(HelloParser::T__9);
    setState(147);
    expr();
    setState(148);
    match(HelloParser::T__10);
    setState(149);
    statement();
    setState(152);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(150);
      match(HelloParser::T__11);
      setState(151);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

HelloParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::ExprContext* HelloParser::WhileStatementContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::StatementContext* HelloParser::WhileStatementContext::statement() {
  return getRuleContext<HelloParser::StatementContext>(0);
}


size_t HelloParser::WhileStatementContext::getRuleIndex() const {
  return HelloParser::RuleWhileStatement;
}


std::any HelloParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::WhileStatementContext* HelloParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, HelloParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(HelloParser::T__12);
    setState(155);
    expr();
    setState(156);
    match(HelloParser::T__13);
    setState(157);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoStatementContext ------------------------------------------------------------------

HelloParser::DoStatementContext::DoStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::StatementContext* HelloParser::DoStatementContext::statement() {
  return getRuleContext<HelloParser::StatementContext>(0);
}

HelloParser::ExprContext* HelloParser::DoStatementContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}


size_t HelloParser::DoStatementContext::getRuleIndex() const {
  return HelloParser::RuleDoStatement;
}


std::any HelloParser::DoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitDoStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::DoStatementContext* HelloParser::doStatement() {
  DoStatementContext *_localctx = _tracker.createInstance<DoStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, HelloParser::RuleDoStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(HelloParser::T__14);
    setState(160);
    statement();
    setState(161);
    _la = _input->LA(1);
    if (!(_la == HelloParser::T__12

    || _la == HelloParser::T__15)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(162);
    expr();
    setState(163);
    match(HelloParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprStatementContext ------------------------------------------------------------------

HelloParser::ExprStatementContext::ExprStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::ExprContext* HelloParser::ExprStatementContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}


size_t HelloParser::ExprStatementContext::getRuleIndex() const {
  return HelloParser::RuleExprStatement;
}


std::any HelloParser::ExprStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitExprStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ExprStatementContext* HelloParser::exprStatement() {
  ExprStatementContext *_localctx = _tracker.createInstance<ExprStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, HelloParser::RuleExprStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    expr();
    setState(166);
    match(HelloParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

HelloParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::AssignExprContext* HelloParser::ExprContext::assignExpr() {
  return getRuleContext<HelloParser::AssignExprContext>(0);
}


size_t HelloParser::ExprContext::getRuleIndex() const {
  return HelloParser::RuleExpr;
}


std::any HelloParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ExprContext* HelloParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 30, HelloParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    assignExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignExprContext ------------------------------------------------------------------

HelloParser::AssignExprContext::AssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::LogicalOrExprContext* HelloParser::AssignExprContext::logicalOrExpr() {
  return getRuleContext<HelloParser::LogicalOrExprContext>(0);
}

HelloParser::AssignExprContext* HelloParser::AssignExprContext::assignExpr() {
  return getRuleContext<HelloParser::AssignExprContext>(0);
}


size_t HelloParser::AssignExprContext::getRuleIndex() const {
  return HelloParser::RuleAssignExpr;
}


std::any HelloParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::AssignExprContext* HelloParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 32, HelloParser::RuleAssignExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    logicalOrExpr();
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__16) {
      setState(171);
      match(HelloParser::T__16);
      setState(172);
      assignExpr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOrExprContext ------------------------------------------------------------------

HelloParser::LogicalOrExprContext::LogicalOrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::LogicalAndExprContext *> HelloParser::LogicalOrExprContext::logicalAndExpr() {
  return getRuleContexts<HelloParser::LogicalAndExprContext>();
}

HelloParser::LogicalAndExprContext* HelloParser::LogicalOrExprContext::logicalAndExpr(size_t i) {
  return getRuleContext<HelloParser::LogicalAndExprContext>(i);
}


size_t HelloParser::LogicalOrExprContext::getRuleIndex() const {
  return HelloParser::RuleLogicalOrExpr;
}


std::any HelloParser::LogicalOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::LogicalOrExprContext* HelloParser::logicalOrExpr() {
  LogicalOrExprContext *_localctx = _tracker.createInstance<LogicalOrExprContext>(_ctx, getState());
  enterRule(_localctx, 34, HelloParser::RuleLogicalOrExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    logicalAndExpr();
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__17) {
      setState(176);
      match(HelloParser::T__17);
      setState(177);
      logicalAndExpr();
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalAndExprContext ------------------------------------------------------------------

HelloParser::LogicalAndExprContext::LogicalAndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::CompareExprContext *> HelloParser::LogicalAndExprContext::compareExpr() {
  return getRuleContexts<HelloParser::CompareExprContext>();
}

HelloParser::CompareExprContext* HelloParser::LogicalAndExprContext::compareExpr(size_t i) {
  return getRuleContext<HelloParser::CompareExprContext>(i);
}


size_t HelloParser::LogicalAndExprContext::getRuleIndex() const {
  return HelloParser::RuleLogicalAndExpr;
}


std::any HelloParser::LogicalAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::LogicalAndExprContext* HelloParser::logicalAndExpr() {
  LogicalAndExprContext *_localctx = _tracker.createInstance<LogicalAndExprContext>(_ctx, getState());
  enterRule(_localctx, 36, HelloParser::RuleLogicalAndExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    compareExpr();
    setState(188);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__18) {
      setState(184);
      match(HelloParser::T__18);
      setState(185);
      compareExpr();
      setState(190);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompareExprContext ------------------------------------------------------------------

HelloParser::CompareExprContext::CompareExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::AddSubExprContext *> HelloParser::CompareExprContext::addSubExpr() {
  return getRuleContexts<HelloParser::AddSubExprContext>();
}

HelloParser::AddSubExprContext* HelloParser::CompareExprContext::addSubExpr(size_t i) {
  return getRuleContext<HelloParser::AddSubExprContext>(i);
}


size_t HelloParser::CompareExprContext::getRuleIndex() const {
  return HelloParser::RuleCompareExpr;
}


std::any HelloParser::CompareExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitCompareExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::CompareExprContext* HelloParser::compareExpr() {
  CompareExprContext *_localctx = _tracker.createInstance<CompareExprContext>(_ctx, getState());
  enterRule(_localctx, 38, HelloParser::RuleCompareExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    addSubExpr();
    setState(196);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 66060288) != 0)) {
      setState(192);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 66060288) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(193);
      addSubExpr();
      setState(198);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddSubExprContext ------------------------------------------------------------------

HelloParser::AddSubExprContext::AddSubExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::MulDivExprContext *> HelloParser::AddSubExprContext::mulDivExpr() {
  return getRuleContexts<HelloParser::MulDivExprContext>();
}

HelloParser::MulDivExprContext* HelloParser::AddSubExprContext::mulDivExpr(size_t i) {
  return getRuleContext<HelloParser::MulDivExprContext>(i);
}


size_t HelloParser::AddSubExprContext::getRuleIndex() const {
  return HelloParser::RuleAddSubExpr;
}


std::any HelloParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::AddSubExprContext* HelloParser::addSubExpr() {
  AddSubExprContext *_localctx = _tracker.createInstance<AddSubExprContext>(_ctx, getState());
  enterRule(_localctx, 40, HelloParser::RuleAddSubExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    mulDivExpr();
    setState(204);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__25

    || _la == HelloParser::T__26) {
      setState(200);
      _la = _input->LA(1);
      if (!(_la == HelloParser::T__25

      || _la == HelloParser::T__26)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(201);
      mulDivExpr();
      setState(206);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulDivExprContext ------------------------------------------------------------------

HelloParser::MulDivExprContext::MulDivExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::UnaryExprContext *> HelloParser::MulDivExprContext::unaryExpr() {
  return getRuleContexts<HelloParser::UnaryExprContext>();
}

HelloParser::UnaryExprContext* HelloParser::MulDivExprContext::unaryExpr(size_t i) {
  return getRuleContext<HelloParser::UnaryExprContext>(i);
}


size_t HelloParser::MulDivExprContext::getRuleIndex() const {
  return HelloParser::RuleMulDivExpr;
}


std::any HelloParser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::MulDivExprContext* HelloParser::mulDivExpr() {
  MulDivExprContext *_localctx = _tracker.createInstance<MulDivExprContext>(_ctx, getState());
  enterRule(_localctx, 42, HelloParser::RuleMulDivExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    unaryExpr();
    setState(212);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1879048192) != 0)) {
      setState(208);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1879048192) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(209);
      unaryExpr();
      setState(214);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

HelloParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::UnaryExprContext* HelloParser::UnaryExprContext::unaryExpr() {
  return getRuleContext<HelloParser::UnaryExprContext>(0);
}

HelloParser::PrimaryExprContext* HelloParser::UnaryExprContext::primaryExpr() {
  return getRuleContext<HelloParser::PrimaryExprContext>(0);
}


size_t HelloParser::UnaryExprContext::getRuleIndex() const {
  return HelloParser::RuleUnaryExpr;
}


std::any HelloParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::UnaryExprContext* HelloParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 44, HelloParser::RuleUnaryExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__25:
      case HelloParser::T__26:
      case HelloParser::T__30: {
        enterOuterAlt(_localctx, 1);
        setState(215);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2348810240) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(216);
        unaryExpr();
        break;
      }

      case HelloParser::T__2:
      case HelloParser::BoolLiteral:
      case HelloParser::StringLiteral:
      case HelloParser::CharLiteral:
      case HelloParser::HexLiteral:
      case HelloParser::BitsLiteral:
      case HelloParser::DecimalLiteral:
      case HelloParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(217);
        primaryExpr(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallExprContext ------------------------------------------------------------------

HelloParser::CallExprContext::CallExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::IdentifierContext* HelloParser::CallExprContext::identifier() {
  return getRuleContext<HelloParser::IdentifierContext>(0);
}

HelloParser::ExprListContext* HelloParser::CallExprContext::exprList() {
  return getRuleContext<HelloParser::ExprListContext>(0);
}


size_t HelloParser::CallExprContext::getRuleIndex() const {
  return HelloParser::RuleCallExpr;
}


std::any HelloParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::CallExprContext* HelloParser::callExpr() {
  CallExprContext *_localctx = _tracker.createInstance<CallExprContext>(_ctx, getState());
  enterRule(_localctx, 46, HelloParser::RuleCallExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    identifier();
    setState(221);
    match(HelloParser::T__2);
    setState(223);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4468417604091912) != 0)) {
      setState(222);
      exprList();
    }
    setState(225);
    match(HelloParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExprContext ------------------------------------------------------------------

HelloParser::PrimaryExprContext::PrimaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::LiteralContext* HelloParser::PrimaryExprContext::literal() {
  return getRuleContext<HelloParser::LiteralContext>(0);
}

HelloParser::IdentifierContext* HelloParser::PrimaryExprContext::identifier() {
  return getRuleContext<HelloParser::IdentifierContext>(0);
}

HelloParser::CallExprContext* HelloParser::PrimaryExprContext::callExpr() {
  return getRuleContext<HelloParser::CallExprContext>(0);
}

HelloParser::ExprContext* HelloParser::PrimaryExprContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::PrimaryExprContext* HelloParser::PrimaryExprContext::primaryExpr() {
  return getRuleContext<HelloParser::PrimaryExprContext>(0);
}

HelloParser::ExprListContext* HelloParser::PrimaryExprContext::exprList() {
  return getRuleContext<HelloParser::ExprListContext>(0);
}


size_t HelloParser::PrimaryExprContext::getRuleIndex() const {
  return HelloParser::RulePrimaryExpr;
}


std::any HelloParser::PrimaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpr(this);
  else
    return visitor->visitChildren(this);
}


HelloParser::PrimaryExprContext* HelloParser::primaryExpr() {
   return primaryExpr(0);
}

HelloParser::PrimaryExprContext* HelloParser::primaryExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  HelloParser::PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, parentState);
  HelloParser::PrimaryExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, HelloParser::RulePrimaryExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(235);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(228);
      literal();
      break;
    }

    case 2: {
      setState(229);
      identifier();
      break;
    }

    case 3: {
      setState(230);
      callExpr();
      break;
    }

    case 4: {
      setState(231);
      match(HelloParser::T__2);
      setState(232);
      expr();
      setState(233);
      match(HelloParser::T__3);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PrimaryExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePrimaryExpr);
        setState(237);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(238);
        match(HelloParser::T__31);
        setState(240);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 4468417604091912) != 0)) {
          setState(239);
          exprList();
        }
        setState(242);
        match(HelloParser::T__32); 
      }
      setState(247);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprListContext ------------------------------------------------------------------

HelloParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::ExprContext *> HelloParser::ExprListContext::expr() {
  return getRuleContexts<HelloParser::ExprContext>();
}

HelloParser::ExprContext* HelloParser::ExprListContext::expr(size_t i) {
  return getRuleContext<HelloParser::ExprContext>(i);
}


size_t HelloParser::ExprListContext::getRuleIndex() const {
  return HelloParser::RuleExprList;
}


std::any HelloParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ExprListContext* HelloParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 50, HelloParser::RuleExprList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    expr();
    setState(253);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__5) {
      setState(249);
      match(HelloParser::T__5);
      setState(250);
      expr();
      setState(255);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeRefContext ------------------------------------------------------------------

HelloParser::TypeRefContext::TypeRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HelloParser::BuiltinTypeContext* HelloParser::TypeRefContext::builtinType() {
  return getRuleContext<HelloParser::BuiltinTypeContext>(0);
}

HelloParser::IdentifierContext* HelloParser::TypeRefContext::identifier() {
  return getRuleContext<HelloParser::IdentifierContext>(0);
}

HelloParser::TypeRefContext* HelloParser::TypeRefContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
}


size_t HelloParser::TypeRefContext::getRuleIndex() const {
  return HelloParser::RuleTypeRef;
}


std::any HelloParser::TypeRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitTypeRef(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::TypeRefContext* HelloParser::typeRef() {
  TypeRefContext *_localctx = _tracker.createInstance<TypeRefContext>(_ctx, getState());
  enterRule(_localctx, 52, HelloParser::RuleTypeRef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__35:
      case HelloParser::T__36:
      case HelloParser::T__37:
      case HelloParser::T__38:
      case HelloParser::T__39:
      case HelloParser::T__40:
      case HelloParser::T__41:
      case HelloParser::T__42: {
        enterOuterAlt(_localctx, 1);
        setState(256);
        builtinType();
        break;
      }

      case HelloParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(257);
        identifier();
        break;
      }

      case HelloParser::T__33: {
        enterOuterAlt(_localctx, 3);
        setState(258);
        match(HelloParser::T__33);
        setState(259);
        match(HelloParser::T__31);
        setState(263);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == HelloParser::T__5) {
          setState(260);
          match(HelloParser::T__5);
          setState(265);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(266);
        match(HelloParser::T__32);
        setState(267);
        match(HelloParser::T__34);
        setState(268);
        typeRef();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltinTypeContext ------------------------------------------------------------------

HelloParser::BuiltinTypeContext::BuiltinTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::BuiltinTypeContext::getRuleIndex() const {
  return HelloParser::RuleBuiltinType;
}


std::any HelloParser::BuiltinTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitBuiltinType(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::BuiltinTypeContext* HelloParser::builtinType() {
  BuiltinTypeContext *_localctx = _tracker.createInstance<BuiltinTypeContext>(_ctx, getState());
  enterRule(_localctx, 54, HelloParser::RuleBuiltinType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17523466567680) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

HelloParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HelloParser::LiteralContext::BoolLiteral() {
  return getToken(HelloParser::BoolLiteral, 0);
}

tree::TerminalNode* HelloParser::LiteralContext::StringLiteral() {
  return getToken(HelloParser::StringLiteral, 0);
}

tree::TerminalNode* HelloParser::LiteralContext::CharLiteral() {
  return getToken(HelloParser::CharLiteral, 0);
}

tree::TerminalNode* HelloParser::LiteralContext::HexLiteral() {
  return getToken(HelloParser::HexLiteral, 0);
}

tree::TerminalNode* HelloParser::LiteralContext::BitsLiteral() {
  return getToken(HelloParser::BitsLiteral, 0);
}

tree::TerminalNode* HelloParser::LiteralContext::DecimalLiteral() {
  return getToken(HelloParser::DecimalLiteral, 0);
}


size_t HelloParser::LiteralContext::getRuleIndex() const {
  return HelloParser::RuleLiteral;
}


std::any HelloParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::LiteralContext* HelloParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 56, HelloParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2216615441596416) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

HelloParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HelloParser::IdentifierContext::Identifier() {
  return getToken(HelloParser::Identifier, 0);
}


size_t HelloParser::IdentifierContext::getRuleIndex() const {
  return HelloParser::RuleIdentifier;
}


std::any HelloParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::IdentifierContext* HelloParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 58, HelloParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    match(HelloParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool HelloParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 24: return primaryExprSempred(antlrcpp::downCast<PrimaryExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool HelloParser::primaryExprSempred(PrimaryExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void HelloParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  helloParserInitialize();
#else
  ::antlr4::internal::call_once(helloParserOnceFlag, helloParserInitialize);
#endif
}
