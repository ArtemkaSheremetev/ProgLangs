
// Generated from Hello.g4 by ANTLR 4.13.2


#include "HelloListener.h"
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
      "body", "varDeclList", "statementBlock", "statement", "ifStatement", 
      "whileStatement", "doStatement", "exprStatement", "expr", "assignExpr", 
      "logicalOrExpr", "logicalAndExpr", "compareExpr", "addSubExpr", "mulDivExpr", 
      "unaryExpr", "callExpr", "primaryExpr", "exprList", "typeRef", "builtinType", 
      "literal", "identifier"
    },
    std::vector<std::string>{
      "", "'method'", "';'", "'('", "')'", "':'", "','", "'begin'", "'end'", 
      "'if'", "'then'", "'else'", "'while'", "'do'", "'repeat'", "'until'", 
      "':='", "'||'", "'&&'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['", "']'", "'array'", 
      "'of'", "'bool'", "'byte'", "'int'", "'uint'", "'long'", "'ulong'", 
      "'char'", "'string'", "'var'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "VAR", "BoolLiteral", "StringLiteral", 
      "CharLiteral", "HexLiteral", "BitsLiteral", "DecimalLiteral", "Identifier", 
      "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,53,269,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,5,0,60,8,0,10,0,12,0,63,9,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,3,
  	2,73,8,2,1,3,1,3,1,3,3,3,78,8,3,1,3,1,3,1,3,3,3,83,8,3,1,4,1,4,1,4,5,
  	4,88,8,4,10,4,12,4,91,9,4,1,5,1,5,1,5,3,5,96,8,5,1,6,1,6,5,6,100,8,6,
  	10,6,12,6,103,9,6,1,6,1,6,1,7,1,7,1,7,5,7,110,8,7,10,7,12,7,113,9,7,1,
  	7,1,7,3,7,117,8,7,1,7,1,7,1,8,1,8,5,8,123,8,8,10,8,12,8,126,9,8,1,8,1,
  	8,1,8,1,9,1,9,1,9,1,9,1,9,3,9,136,8,9,1,10,1,10,1,10,1,10,1,10,1,10,3,
  	10,144,8,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	13,1,13,1,13,1,14,1,14,1,15,1,15,1,15,3,15,165,8,15,1,16,1,16,1,16,5,
  	16,170,8,16,10,16,12,16,173,9,16,1,17,1,17,1,17,5,17,178,8,17,10,17,12,
  	17,181,9,17,1,18,1,18,1,18,5,18,186,8,18,10,18,12,18,189,9,18,1,19,1,
  	19,1,19,5,19,194,8,19,10,19,12,19,197,9,19,1,20,1,20,1,20,5,20,202,8,
  	20,10,20,12,20,205,9,20,1,21,1,21,1,21,3,21,210,8,21,1,22,1,22,1,22,3,
  	22,215,8,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,227,
  	8,23,1,23,1,23,1,23,3,23,232,8,23,1,23,5,23,235,8,23,10,23,12,23,238,
  	9,23,1,24,1,24,1,24,5,24,243,8,24,10,24,12,24,246,9,24,1,25,1,25,1,25,
  	1,25,1,25,5,25,253,8,25,10,25,12,25,256,9,25,1,25,1,25,1,25,3,25,261,
  	8,25,1,26,1,26,1,27,1,27,1,28,1,28,1,28,0,1,46,29,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,0,7,2,
  	0,12,12,15,15,1,0,19,24,1,0,25,26,1,0,27,29,2,0,25,26,30,30,1,0,35,42,
  	1,0,44,49,271,0,61,1,0,0,0,2,66,1,0,0,0,4,68,1,0,0,0,6,74,1,0,0,0,8,84,
  	1,0,0,0,10,92,1,0,0,0,12,101,1,0,0,0,14,106,1,0,0,0,16,120,1,0,0,0,18,
  	135,1,0,0,0,20,137,1,0,0,0,22,145,1,0,0,0,24,150,1,0,0,0,26,156,1,0,0,
  	0,28,159,1,0,0,0,30,161,1,0,0,0,32,166,1,0,0,0,34,174,1,0,0,0,36,182,
  	1,0,0,0,38,190,1,0,0,0,40,198,1,0,0,0,42,209,1,0,0,0,44,211,1,0,0,0,46,
  	226,1,0,0,0,48,239,1,0,0,0,50,260,1,0,0,0,52,262,1,0,0,0,54,264,1,0,0,
  	0,56,266,1,0,0,0,58,60,3,2,1,0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,
  	0,0,61,62,1,0,0,0,62,64,1,0,0,0,63,61,1,0,0,0,64,65,5,0,0,1,65,1,1,0,
  	0,0,66,67,3,4,2,0,67,3,1,0,0,0,68,69,5,1,0,0,69,72,3,6,3,0,70,73,3,12,
  	6,0,71,73,5,2,0,0,72,70,1,0,0,0,72,71,1,0,0,0,73,5,1,0,0,0,74,75,3,56,
  	28,0,75,77,5,3,0,0,76,78,3,8,4,0,77,76,1,0,0,0,77,78,1,0,0,0,78,79,1,
  	0,0,0,79,82,5,4,0,0,80,81,5,5,0,0,81,83,3,50,25,0,82,80,1,0,0,0,82,83,
  	1,0,0,0,83,7,1,0,0,0,84,89,3,10,5,0,85,86,5,6,0,0,86,88,3,10,5,0,87,85,
  	1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,89,90,1,0,0,0,90,9,1,0,0,0,91,89,
  	1,0,0,0,92,95,3,56,28,0,93,94,5,5,0,0,94,96,3,50,25,0,95,93,1,0,0,0,95,
  	96,1,0,0,0,96,11,1,0,0,0,97,98,5,43,0,0,98,100,3,14,7,0,99,97,1,0,0,0,
  	100,103,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,102,104,1,0,0,0,103,101,
  	1,0,0,0,104,105,3,16,8,0,105,13,1,0,0,0,106,111,3,56,28,0,107,108,5,6,
  	0,0,108,110,3,56,28,0,109,107,1,0,0,0,110,113,1,0,0,0,111,109,1,0,0,0,
  	111,112,1,0,0,0,112,116,1,0,0,0,113,111,1,0,0,0,114,115,5,5,0,0,115,117,
  	3,50,25,0,116,114,1,0,0,0,116,117,1,0,0,0,117,118,1,0,0,0,118,119,5,2,
  	0,0,119,15,1,0,0,0,120,124,5,7,0,0,121,123,3,18,9,0,122,121,1,0,0,0,123,
  	126,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,127,1,0,0,0,126,124,1,
  	0,0,0,127,128,5,8,0,0,128,129,5,2,0,0,129,17,1,0,0,0,130,136,3,20,10,
  	0,131,136,3,22,11,0,132,136,3,24,12,0,133,136,3,16,8,0,134,136,3,26,13,
  	0,135,130,1,0,0,0,135,131,1,0,0,0,135,132,1,0,0,0,135,133,1,0,0,0,135,
  	134,1,0,0,0,136,19,1,0,0,0,137,138,5,9,0,0,138,139,3,28,14,0,139,140,
  	5,10,0,0,140,143,3,18,9,0,141,142,5,11,0,0,142,144,3,18,9,0,143,141,1,
  	0,0,0,143,144,1,0,0,0,144,21,1,0,0,0,145,146,5,12,0,0,146,147,3,28,14,
  	0,147,148,5,13,0,0,148,149,3,18,9,0,149,23,1,0,0,0,150,151,5,14,0,0,151,
  	152,3,18,9,0,152,153,7,0,0,0,153,154,3,28,14,0,154,155,5,2,0,0,155,25,
  	1,0,0,0,156,157,3,28,14,0,157,158,5,2,0,0,158,27,1,0,0,0,159,160,3,30,
  	15,0,160,29,1,0,0,0,161,164,3,32,16,0,162,163,5,16,0,0,163,165,3,30,15,
  	0,164,162,1,0,0,0,164,165,1,0,0,0,165,31,1,0,0,0,166,171,3,34,17,0,167,
  	168,5,17,0,0,168,170,3,34,17,0,169,167,1,0,0,0,170,173,1,0,0,0,171,169,
  	1,0,0,0,171,172,1,0,0,0,172,33,1,0,0,0,173,171,1,0,0,0,174,179,3,36,18,
  	0,175,176,5,18,0,0,176,178,3,36,18,0,177,175,1,0,0,0,178,181,1,0,0,0,
  	179,177,1,0,0,0,179,180,1,0,0,0,180,35,1,0,0,0,181,179,1,0,0,0,182,187,
  	3,38,19,0,183,184,7,1,0,0,184,186,3,38,19,0,185,183,1,0,0,0,186,189,1,
  	0,0,0,187,185,1,0,0,0,187,188,1,0,0,0,188,37,1,0,0,0,189,187,1,0,0,0,
  	190,195,3,40,20,0,191,192,7,2,0,0,192,194,3,40,20,0,193,191,1,0,0,0,194,
  	197,1,0,0,0,195,193,1,0,0,0,195,196,1,0,0,0,196,39,1,0,0,0,197,195,1,
  	0,0,0,198,203,3,42,21,0,199,200,7,3,0,0,200,202,3,42,21,0,201,199,1,0,
  	0,0,202,205,1,0,0,0,203,201,1,0,0,0,203,204,1,0,0,0,204,41,1,0,0,0,205,
  	203,1,0,0,0,206,207,7,4,0,0,207,210,3,42,21,0,208,210,3,46,23,0,209,206,
  	1,0,0,0,209,208,1,0,0,0,210,43,1,0,0,0,211,212,3,56,28,0,212,214,5,3,
  	0,0,213,215,3,48,24,0,214,213,1,0,0,0,214,215,1,0,0,0,215,216,1,0,0,0,
  	216,217,5,4,0,0,217,45,1,0,0,0,218,219,6,23,-1,0,219,227,3,54,27,0,220,
  	227,3,56,28,0,221,227,3,44,22,0,222,223,5,3,0,0,223,224,3,28,14,0,224,
  	225,5,4,0,0,225,227,1,0,0,0,226,218,1,0,0,0,226,220,1,0,0,0,226,221,1,
  	0,0,0,226,222,1,0,0,0,227,236,1,0,0,0,228,229,10,2,0,0,229,231,5,31,0,
  	0,230,232,3,48,24,0,231,230,1,0,0,0,231,232,1,0,0,0,232,233,1,0,0,0,233,
  	235,5,32,0,0,234,228,1,0,0,0,235,238,1,0,0,0,236,234,1,0,0,0,236,237,
  	1,0,0,0,237,47,1,0,0,0,238,236,1,0,0,0,239,244,3,28,14,0,240,241,5,6,
  	0,0,241,243,3,28,14,0,242,240,1,0,0,0,243,246,1,0,0,0,244,242,1,0,0,0,
  	244,245,1,0,0,0,245,49,1,0,0,0,246,244,1,0,0,0,247,261,3,52,26,0,248,
  	261,3,56,28,0,249,250,5,33,0,0,250,254,5,31,0,0,251,253,5,6,0,0,252,251,
  	1,0,0,0,253,256,1,0,0,0,254,252,1,0,0,0,254,255,1,0,0,0,255,257,1,0,0,
  	0,256,254,1,0,0,0,257,258,5,32,0,0,258,259,5,34,0,0,259,261,3,50,25,0,
  	260,247,1,0,0,0,260,248,1,0,0,0,260,249,1,0,0,0,261,51,1,0,0,0,262,263,
  	7,5,0,0,263,53,1,0,0,0,264,265,7,6,0,0,265,55,1,0,0,0,266,267,5,50,0,
  	0,267,57,1,0,0,0,26,61,72,77,82,89,95,101,111,116,124,135,143,164,171,
  	179,187,195,203,209,214,226,231,236,244,254,260
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

void HelloParser::SourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSource(this);
}

void HelloParser::SourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSource(this);
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
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__0) {
      setState(58);
      sourceItem();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
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

void HelloParser::SourceItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourceItem(this);
}

void HelloParser::SourceItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourceItem(this);
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
    setState(66);
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

void HelloParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void HelloParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
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
    setState(68);
    match(HelloParser::T__0);
    setState(69);
    funcSignature();
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__6:
      case HelloParser::VAR: {
        setState(70);
        body();
        break;
      }

      case HelloParser::T__1: {
        setState(71);
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

void HelloParser::FuncSignatureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncSignature(this);
}

void HelloParser::FuncSignatureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncSignature(this);
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
    setState(74);
    identifier();
    setState(75);
    match(HelloParser::T__2);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::Identifier) {
      setState(76);
      argList();
    }
    setState(79);
    match(HelloParser::T__3);
    setState(82);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__4) {
      setState(80);
      match(HelloParser::T__4);
      setState(81);
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

void HelloParser::ArgListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgList(this);
}

void HelloParser::ArgListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgList(this);
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
    setState(84);
    argDef();
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__5) {
      setState(85);
      match(HelloParser::T__5);
      setState(86);
      argDef();
      setState(91);
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

void HelloParser::ArgDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgDef(this);
}

void HelloParser::ArgDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgDef(this);
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
    setState(92);
    identifier();
    setState(95);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__4) {
      setState(93);
      match(HelloParser::T__4);
      setState(94);
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

void HelloParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void HelloParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
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
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::VAR) {
      setState(97);
      match(HelloParser::VAR);
      setState(98);
      varDeclList();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(104);
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

void HelloParser::VarDeclListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclList(this);
}

void HelloParser::VarDeclListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclList(this);
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
    setState(106);
    identifier();
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__5) {
      setState(107);
      match(HelloParser::T__5);
      setState(108);
      identifier();
      setState(113);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__4) {
      setState(114);
      match(HelloParser::T__4);
      setState(115);
      typeRef();
    }
    setState(118);
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

void HelloParser::StatementBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBlock(this);
}

void HelloParser::StatementBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBlock(this);
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
    setState(120);
    match(HelloParser::T__6);
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2234208802067080) != 0)) {
      setState(121);
      statement();
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
    match(HelloParser::T__7);
    setState(128);
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

void HelloParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void HelloParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
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
    setState(135);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(130);
        ifStatement();
        break;
      }

      case HelloParser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(131);
        whileStatement();
        break;
      }

      case HelloParser::T__13: {
        enterOuterAlt(_localctx, 3);
        setState(132);
        doStatement();
        break;
      }

      case HelloParser::T__6: {
        enterOuterAlt(_localctx, 4);
        setState(133);
        statementBlock();
        break;
      }

      case HelloParser::T__2:
      case HelloParser::T__24:
      case HelloParser::T__25:
      case HelloParser::T__29:
      case HelloParser::BoolLiteral:
      case HelloParser::StringLiteral:
      case HelloParser::CharLiteral:
      case HelloParser::HexLiteral:
      case HelloParser::BitsLiteral:
      case HelloParser::DecimalLiteral:
      case HelloParser::Identifier: {
        enterOuterAlt(_localctx, 5);
        setState(134);
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

void HelloParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void HelloParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any HelloParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::IfStatementContext* HelloParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, HelloParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(HelloParser::T__8);
    setState(138);
    expr();
    setState(139);
    match(HelloParser::T__9);
    setState(140);
    statement();
    setState(143);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(141);
      match(HelloParser::T__10);
      setState(142);
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

void HelloParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void HelloParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}


std::any HelloParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::WhileStatementContext* HelloParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, HelloParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(HelloParser::T__11);
    setState(146);
    expr();
    setState(147);
    match(HelloParser::T__12);
    setState(148);
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

void HelloParser::DoStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoStatement(this);
}

void HelloParser::DoStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoStatement(this);
}


std::any HelloParser::DoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitDoStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::DoStatementContext* HelloParser::doStatement() {
  DoStatementContext *_localctx = _tracker.createInstance<DoStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, HelloParser::RuleDoStatement);
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
    setState(150);
    match(HelloParser::T__13);
    setState(151);
    statement();
    setState(152);
    _la = _input->LA(1);
    if (!(_la == HelloParser::T__11

    || _la == HelloParser::T__14)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(153);
    expr();
    setState(154);
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

void HelloParser::ExprStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStatement(this);
}

void HelloParser::ExprStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStatement(this);
}


std::any HelloParser::ExprStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitExprStatement(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ExprStatementContext* HelloParser::exprStatement() {
  ExprStatementContext *_localctx = _tracker.createInstance<ExprStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, HelloParser::RuleExprStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    expr();
    setState(157);
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

void HelloParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void HelloParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any HelloParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ExprContext* HelloParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 28, HelloParser::RuleExpr);

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

void HelloParser::AssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignExpr(this);
}

void HelloParser::AssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignExpr(this);
}


std::any HelloParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::AssignExprContext* HelloParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 30, HelloParser::RuleAssignExpr);
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
    setState(161);
    logicalOrExpr();
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__15) {
      setState(162);
      match(HelloParser::T__15);
      setState(163);
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

void HelloParser::LogicalOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpr(this);
}

void HelloParser::LogicalOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpr(this);
}


std::any HelloParser::LogicalOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::LogicalOrExprContext* HelloParser::logicalOrExpr() {
  LogicalOrExprContext *_localctx = _tracker.createInstance<LogicalOrExprContext>(_ctx, getState());
  enterRule(_localctx, 32, HelloParser::RuleLogicalOrExpr);
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
    setState(166);
    logicalAndExpr();
    setState(171);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__16) {
      setState(167);
      match(HelloParser::T__16);
      setState(168);
      logicalAndExpr();
      setState(173);
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

void HelloParser::LogicalAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpr(this);
}

void HelloParser::LogicalAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpr(this);
}


std::any HelloParser::LogicalAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::LogicalAndExprContext* HelloParser::logicalAndExpr() {
  LogicalAndExprContext *_localctx = _tracker.createInstance<LogicalAndExprContext>(_ctx, getState());
  enterRule(_localctx, 34, HelloParser::RuleLogicalAndExpr);
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
    setState(174);
    compareExpr();
    setState(179);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__17) {
      setState(175);
      match(HelloParser::T__17);
      setState(176);
      compareExpr();
      setState(181);
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

void HelloParser::CompareExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompareExpr(this);
}

void HelloParser::CompareExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompareExpr(this);
}


std::any HelloParser::CompareExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitCompareExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::CompareExprContext* HelloParser::compareExpr() {
  CompareExprContext *_localctx = _tracker.createInstance<CompareExprContext>(_ctx, getState());
  enterRule(_localctx, 36, HelloParser::RuleCompareExpr);
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
    setState(182);
    addSubExpr();
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 33030144) != 0)) {
      setState(183);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 33030144) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(184);
      addSubExpr();
      setState(189);
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

void HelloParser::AddSubExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSubExpr(this);
}

void HelloParser::AddSubExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSubExpr(this);
}


std::any HelloParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::AddSubExprContext* HelloParser::addSubExpr() {
  AddSubExprContext *_localctx = _tracker.createInstance<AddSubExprContext>(_ctx, getState());
  enterRule(_localctx, 38, HelloParser::RuleAddSubExpr);
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
    setState(190);
    mulDivExpr();
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__24

    || _la == HelloParser::T__25) {
      setState(191);
      _la = _input->LA(1);
      if (!(_la == HelloParser::T__24

      || _la == HelloParser::T__25)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(192);
      mulDivExpr();
      setState(197);
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

void HelloParser::MulDivExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDivExpr(this);
}

void HelloParser::MulDivExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDivExpr(this);
}


std::any HelloParser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::MulDivExprContext* HelloParser::mulDivExpr() {
  MulDivExprContext *_localctx = _tracker.createInstance<MulDivExprContext>(_ctx, getState());
  enterRule(_localctx, 40, HelloParser::RuleMulDivExpr);
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
    setState(198);
    unaryExpr();
    setState(203);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 939524096) != 0)) {
      setState(199);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 939524096) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(200);
      unaryExpr();
      setState(205);
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

void HelloParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}

void HelloParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}


std::any HelloParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::UnaryExprContext* HelloParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 42, HelloParser::RuleUnaryExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__24:
      case HelloParser::T__25:
      case HelloParser::T__29: {
        enterOuterAlt(_localctx, 1);
        setState(206);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1174405120) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(207);
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
        setState(208);
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

void HelloParser::CallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExpr(this);
}

void HelloParser::CallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExpr(this);
}


std::any HelloParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::CallExprContext* HelloParser::callExpr() {
  CallExprContext *_localctx = _tracker.createInstance<CallExprContext>(_ctx, getState());
  enterRule(_localctx, 44, HelloParser::RuleCallExpr);
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
    setState(211);
    identifier();
    setState(212);
    match(HelloParser::T__2);
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2234208802045960) != 0)) {
      setState(213);
      exprList();
    }
    setState(216);
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

void HelloParser::PrimaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpr(this);
}

void HelloParser::PrimaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpr(this);
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
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, HelloParser::RulePrimaryExpr, precedence);

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
    setState(226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(219);
      literal();
      break;
    }

    case 2: {
      setState(220);
      identifier();
      break;
    }

    case 3: {
      setState(221);
      callExpr();
      break;
    }

    case 4: {
      setState(222);
      match(HelloParser::T__2);
      setState(223);
      expr();
      setState(224);
      match(HelloParser::T__3);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(236);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PrimaryExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePrimaryExpr);
        setState(228);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(229);
        match(HelloParser::T__30);
        setState(231);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2234208802045960) != 0)) {
          setState(230);
          exprList();
        }
        setState(233);
        match(HelloParser::T__31); 
      }
      setState(238);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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

void HelloParser::ExprListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprList(this);
}

void HelloParser::ExprListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprList(this);
}


std::any HelloParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::ExprListContext* HelloParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 48, HelloParser::RuleExprList);
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
    setState(239);
    expr();
    setState(244);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__5) {
      setState(240);
      match(HelloParser::T__5);
      setState(241);
      expr();
      setState(246);
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

void HelloParser::TypeRefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeRef(this);
}

void HelloParser::TypeRefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeRef(this);
}


std::any HelloParser::TypeRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitTypeRef(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::TypeRefContext* HelloParser::typeRef() {
  TypeRefContext *_localctx = _tracker.createInstance<TypeRefContext>(_ctx, getState());
  enterRule(_localctx, 50, HelloParser::RuleTypeRef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__34:
      case HelloParser::T__35:
      case HelloParser::T__36:
      case HelloParser::T__37:
      case HelloParser::T__38:
      case HelloParser::T__39:
      case HelloParser::T__40:
      case HelloParser::T__41: {
        enterOuterAlt(_localctx, 1);
        setState(247);
        builtinType();
        break;
      }

      case HelloParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(248);
        identifier();
        break;
      }

      case HelloParser::T__32: {
        enterOuterAlt(_localctx, 3);
        setState(249);
        match(HelloParser::T__32);
        setState(250);
        match(HelloParser::T__30);
        setState(254);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == HelloParser::T__5) {
          setState(251);
          match(HelloParser::T__5);
          setState(256);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(257);
        match(HelloParser::T__31);
        setState(258);
        match(HelloParser::T__33);
        setState(259);
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

void HelloParser::BuiltinTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltinType(this);
}

void HelloParser::BuiltinTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltinType(this);
}


std::any HelloParser::BuiltinTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitBuiltinType(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::BuiltinTypeContext* HelloParser::builtinType() {
  BuiltinTypeContext *_localctx = _tracker.createInstance<BuiltinTypeContext>(_ctx, getState());
  enterRule(_localctx, 52, HelloParser::RuleBuiltinType);
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
    setState(262);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8761733283840) != 0))) {
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

void HelloParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void HelloParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


std::any HelloParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::LiteralContext* HelloParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 54, HelloParser::RuleLiteral);
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
    setState(264);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1108307720798208) != 0))) {
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

void HelloParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void HelloParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


std::any HelloParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HelloVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

HelloParser::IdentifierContext* HelloParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 56, HelloParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
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
    case 23: return primaryExprSempred(antlrcpp::downCast<PrimaryExprContext *>(context), predicateIndex);

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
