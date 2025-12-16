
// Generated from Hello.g4 by ANTLR 4.13.2


#include "HelloListener.h"

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
      "source", "sourceItem", "funcDef", "paramList", "param", "body", "block", 
      "typeRef", "builtinType", "commaList", "stmt", "expr", "cmpOp", "addOp", 
      "mulOp", "unaryOp", "primary", "exprList", "literal"
    },
    std::vector<std::string>{
      "", "'method'", "'('", "')'", "':'", "','", "';'", "'begin'", "'end'", 
      "'array'", "'['", "']'", "'of'", "'bool'", "'byte'", "'int'", "'uint'", 
      "'long'", "'ulong'", "'char'", "'string'", "'var'", "'if'", "'then'", 
      "'else'", "'while'", "'do'", "'repeat'", "'until'", "'break'", "'return'", 
      "':='", "'||'", "'&&'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "BoolLiteral", "StringLiteral", 
      "CharLiteral", "HexLiteral", "BitsLiteral", "DecimalLiteral", "ID", 
      "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,55,230,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,5,0,40,8,0,10,0,12,0,43,
  	9,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,3,2,53,8,2,1,2,1,2,1,2,3,2,58,8,2,
  	1,2,1,2,1,3,1,3,1,3,5,3,65,8,3,10,3,12,3,68,9,3,1,4,1,4,1,4,3,4,73,8,
  	4,1,5,1,5,3,5,77,8,5,1,6,1,6,5,6,81,8,6,10,6,12,6,84,9,6,1,6,1,6,1,6,
  	1,7,1,7,1,7,1,7,1,7,3,7,94,8,7,1,7,1,7,1,7,3,7,99,8,7,1,8,1,8,1,9,4,9,
  	104,8,9,11,9,12,9,105,1,10,1,10,1,10,1,10,1,10,5,10,113,8,10,10,10,12,
  	10,116,9,10,1,10,1,10,3,10,120,8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	3,10,129,8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,3,10,146,8,10,1,10,1,10,1,10,1,10,3,10,152,8,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,162,8,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,5,11,182,8,11,10,11,12,11,185,9,11,1,12,1,12,1,13,1,13,1,14,1,14,1,
  	15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,202,8,16,1,16,1,16,1,
  	16,3,16,207,8,16,1,16,1,16,1,16,1,16,1,16,1,16,5,16,215,8,16,10,16,12,
  	16,218,9,16,1,17,1,17,1,17,5,17,223,8,17,10,17,12,17,226,9,17,1,18,1,
  	18,1,18,0,2,22,32,19,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,0,7,1,0,13,20,2,0,25,25,28,28,1,0,34,39,1,0,40,41,1,0,42,44,2,0,40,
  	41,45,45,1,0,46,51,245,0,41,1,0,0,0,2,46,1,0,0,0,4,48,1,0,0,0,6,61,1,
  	0,0,0,8,69,1,0,0,0,10,76,1,0,0,0,12,78,1,0,0,0,14,98,1,0,0,0,16,100,1,
  	0,0,0,18,103,1,0,0,0,20,151,1,0,0,0,22,161,1,0,0,0,24,186,1,0,0,0,26,
  	188,1,0,0,0,28,190,1,0,0,0,30,192,1,0,0,0,32,201,1,0,0,0,34,219,1,0,0,
  	0,36,227,1,0,0,0,38,40,3,2,1,0,39,38,1,0,0,0,40,43,1,0,0,0,41,39,1,0,
  	0,0,41,42,1,0,0,0,42,44,1,0,0,0,43,41,1,0,0,0,44,45,5,0,0,1,45,1,1,0,
  	0,0,46,47,3,4,2,0,47,3,1,0,0,0,48,49,5,1,0,0,49,50,5,52,0,0,50,52,5,2,
  	0,0,51,53,3,6,3,0,52,51,1,0,0,0,52,53,1,0,0,0,53,54,1,0,0,0,54,57,5,3,
  	0,0,55,56,5,4,0,0,56,58,3,14,7,0,57,55,1,0,0,0,57,58,1,0,0,0,58,59,1,
  	0,0,0,59,60,3,10,5,0,60,5,1,0,0,0,61,66,3,8,4,0,62,63,5,5,0,0,63,65,3,
  	8,4,0,64,62,1,0,0,0,65,68,1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,7,1,
  	0,0,0,68,66,1,0,0,0,69,72,5,52,0,0,70,71,5,4,0,0,71,73,3,14,7,0,72,70,
  	1,0,0,0,72,73,1,0,0,0,73,9,1,0,0,0,74,77,3,12,6,0,75,77,5,6,0,0,76,74,
  	1,0,0,0,76,75,1,0,0,0,77,11,1,0,0,0,78,82,5,7,0,0,79,81,3,20,10,0,80,
  	79,1,0,0,0,81,84,1,0,0,0,82,80,1,0,0,0,82,83,1,0,0,0,83,85,1,0,0,0,84,
  	82,1,0,0,0,85,86,5,8,0,0,86,87,5,6,0,0,87,13,1,0,0,0,88,99,3,16,8,0,89,
  	99,5,52,0,0,90,91,5,9,0,0,91,93,5,10,0,0,92,94,3,18,9,0,93,92,1,0,0,0,
  	93,94,1,0,0,0,94,95,1,0,0,0,95,96,5,11,0,0,96,97,5,12,0,0,97,99,3,14,
  	7,0,98,88,1,0,0,0,98,89,1,0,0,0,98,90,1,0,0,0,99,15,1,0,0,0,100,101,7,
  	0,0,0,101,17,1,0,0,0,102,104,5,5,0,0,103,102,1,0,0,0,104,105,1,0,0,0,
  	105,103,1,0,0,0,105,106,1,0,0,0,106,19,1,0,0,0,107,152,3,12,6,0,108,109,
  	5,21,0,0,109,114,5,52,0,0,110,111,5,5,0,0,111,113,5,52,0,0,112,110,1,
  	0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,119,1,0,0,0,
  	116,114,1,0,0,0,117,118,5,4,0,0,118,120,3,14,7,0,119,117,1,0,0,0,119,
  	120,1,0,0,0,120,121,1,0,0,0,121,152,5,6,0,0,122,123,5,22,0,0,123,124,
  	3,22,11,0,124,125,5,23,0,0,125,128,3,20,10,0,126,127,5,24,0,0,127,129,
  	3,20,10,0,128,126,1,0,0,0,128,129,1,0,0,0,129,152,1,0,0,0,130,131,5,25,
  	0,0,131,132,3,22,11,0,132,133,5,26,0,0,133,134,3,20,10,0,134,152,1,0,
  	0,0,135,136,5,27,0,0,136,137,3,20,10,0,137,138,7,1,0,0,138,139,3,22,11,
  	0,139,140,5,6,0,0,140,152,1,0,0,0,141,142,5,29,0,0,142,152,5,6,0,0,143,
  	145,5,30,0,0,144,146,3,22,11,0,145,144,1,0,0,0,145,146,1,0,0,0,146,147,
  	1,0,0,0,147,152,5,6,0,0,148,149,3,22,11,0,149,150,5,6,0,0,150,152,1,0,
  	0,0,151,107,1,0,0,0,151,108,1,0,0,0,151,122,1,0,0,0,151,130,1,0,0,0,151,
  	135,1,0,0,0,151,141,1,0,0,0,151,143,1,0,0,0,151,148,1,0,0,0,152,21,1,
  	0,0,0,153,154,6,11,-1,0,154,155,5,52,0,0,155,156,5,31,0,0,156,162,3,22,
  	11,8,157,158,3,30,15,0,158,159,3,22,11,2,159,162,1,0,0,0,160,162,3,32,
  	16,0,161,153,1,0,0,0,161,157,1,0,0,0,161,160,1,0,0,0,162,183,1,0,0,0,
  	163,164,10,7,0,0,164,165,5,32,0,0,165,182,3,22,11,8,166,167,10,6,0,0,
  	167,168,5,33,0,0,168,182,3,22,11,7,169,170,10,5,0,0,170,171,3,24,12,0,
  	171,172,3,22,11,6,172,182,1,0,0,0,173,174,10,4,0,0,174,175,3,26,13,0,
  	175,176,3,22,11,5,176,182,1,0,0,0,177,178,10,3,0,0,178,179,3,28,14,0,
  	179,180,3,22,11,4,180,182,1,0,0,0,181,163,1,0,0,0,181,166,1,0,0,0,181,
  	169,1,0,0,0,181,173,1,0,0,0,181,177,1,0,0,0,182,185,1,0,0,0,183,181,1,
  	0,0,0,183,184,1,0,0,0,184,23,1,0,0,0,185,183,1,0,0,0,186,187,7,2,0,0,
  	187,25,1,0,0,0,188,189,7,3,0,0,189,27,1,0,0,0,190,191,7,4,0,0,191,29,
  	1,0,0,0,192,193,7,5,0,0,193,31,1,0,0,0,194,195,6,16,-1,0,195,202,3,36,
  	18,0,196,202,5,52,0,0,197,198,5,2,0,0,198,199,3,22,11,0,199,200,5,3,0,
  	0,200,202,1,0,0,0,201,194,1,0,0,0,201,196,1,0,0,0,201,197,1,0,0,0,202,
  	216,1,0,0,0,203,204,10,3,0,0,204,206,5,2,0,0,205,207,3,34,17,0,206,205,
  	1,0,0,0,206,207,1,0,0,0,207,208,1,0,0,0,208,215,5,3,0,0,209,210,10,2,
  	0,0,210,211,5,10,0,0,211,212,3,22,11,0,212,213,5,11,0,0,213,215,1,0,0,
  	0,214,203,1,0,0,0,214,209,1,0,0,0,215,218,1,0,0,0,216,214,1,0,0,0,216,
  	217,1,0,0,0,217,33,1,0,0,0,218,216,1,0,0,0,219,224,3,22,11,0,220,221,
  	5,5,0,0,221,223,3,22,11,0,222,220,1,0,0,0,223,226,1,0,0,0,224,222,1,0,
  	0,0,224,225,1,0,0,0,225,35,1,0,0,0,226,224,1,0,0,0,227,228,7,6,0,0,228,
  	37,1,0,0,0,23,41,52,57,66,72,76,82,93,98,105,114,119,128,145,151,161,
  	181,183,201,206,214,216,224
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
    setState(41);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__0) {
      setState(38);
      sourceItem();
      setState(43);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(44);
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
    setState(46);
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

tree::TerminalNode* HelloParser::FuncDefContext::ID() {
  return getToken(HelloParser::ID, 0);
}

HelloParser::BodyContext* HelloParser::FuncDefContext::body() {
  return getRuleContext<HelloParser::BodyContext>(0);
}

HelloParser::ParamListContext* HelloParser::FuncDefContext::paramList() {
  return getRuleContext<HelloParser::ParamListContext>(0);
}

HelloParser::TypeRefContext* HelloParser::FuncDefContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
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

HelloParser::FuncDefContext* HelloParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 4, HelloParser::RuleFuncDef);
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
    setState(48);
    match(HelloParser::T__0);
    setState(49);
    match(HelloParser::ID);
    setState(50);
    match(HelloParser::T__1);
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::ID) {
      setState(51);
      paramList();
    }
    setState(54);
    match(HelloParser::T__2);
    setState(57);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__3) {
      setState(55);
      match(HelloParser::T__3);
      setState(56);
      typeRef();
    }
    setState(59);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

HelloParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::ParamContext *> HelloParser::ParamListContext::param() {
  return getRuleContexts<HelloParser::ParamContext>();
}

HelloParser::ParamContext* HelloParser::ParamListContext::param(size_t i) {
  return getRuleContext<HelloParser::ParamContext>(i);
}


size_t HelloParser::ParamListContext::getRuleIndex() const {
  return HelloParser::RuleParamList;
}

void HelloParser::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void HelloParser::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}

HelloParser::ParamListContext* HelloParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 6, HelloParser::RuleParamList);
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
    param();
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__4) {
      setState(62);
      match(HelloParser::T__4);
      setState(63);
      param();
      setState(68);
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

//----------------- ParamContext ------------------------------------------------------------------

HelloParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HelloParser::ParamContext::ID() {
  return getToken(HelloParser::ID, 0);
}

HelloParser::TypeRefContext* HelloParser::ParamContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
}


size_t HelloParser::ParamContext::getRuleIndex() const {
  return HelloParser::RuleParam;
}

void HelloParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void HelloParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

HelloParser::ParamContext* HelloParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 8, HelloParser::RuleParam);
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
    setState(69);
    match(HelloParser::ID);
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HelloParser::T__3) {
      setState(70);
      match(HelloParser::T__3);
      setState(71);
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

HelloParser::BlockContext* HelloParser::BodyContext::block() {
  return getRuleContext<HelloParser::BlockContext>(0);
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

HelloParser::BodyContext* HelloParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 10, HelloParser::RuleBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        block();
        break;
      }

      case HelloParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        match(HelloParser::T__5);
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

//----------------- BlockContext ------------------------------------------------------------------

HelloParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HelloParser::StmtContext *> HelloParser::BlockContext::stmt() {
  return getRuleContexts<HelloParser::StmtContext>();
}

HelloParser::StmtContext* HelloParser::BlockContext::stmt(size_t i) {
  return getRuleContext<HelloParser::StmtContext>(i);
}


size_t HelloParser::BlockContext::getRuleIndex() const {
  return HelloParser::RuleBlock;
}

void HelloParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void HelloParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

HelloParser::BlockContext* HelloParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 12, HelloParser::RuleBlock);
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
    setState(78);
    match(HelloParser::T__6);
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8975315202211972) != 0)) {
      setState(79);
      stmt();
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(85);
    match(HelloParser::T__7);
    setState(86);
    match(HelloParser::T__5);
   
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

tree::TerminalNode* HelloParser::TypeRefContext::ID() {
  return getToken(HelloParser::ID, 0);
}

HelloParser::TypeRefContext* HelloParser::TypeRefContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
}

HelloParser::CommaListContext* HelloParser::TypeRefContext::commaList() {
  return getRuleContext<HelloParser::CommaListContext>(0);
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

HelloParser::TypeRefContext* HelloParser::typeRef() {
  TypeRefContext *_localctx = _tracker.createInstance<TypeRefContext>(_ctx, getState());
  enterRule(_localctx, 14, HelloParser::RuleTypeRef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__12:
      case HelloParser::T__13:
      case HelloParser::T__14:
      case HelloParser::T__15:
      case HelloParser::T__16:
      case HelloParser::T__17:
      case HelloParser::T__18:
      case HelloParser::T__19: {
        enterOuterAlt(_localctx, 1);
        setState(88);
        builtinType();
        break;
      }

      case HelloParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(89);
        match(HelloParser::ID);
        break;
      }

      case HelloParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(90);
        match(HelloParser::T__8);
        setState(91);
        match(HelloParser::T__9);
        setState(93);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == HelloParser::T__4) {
          setState(92);
          commaList();
        }
        setState(95);
        match(HelloParser::T__10);
        setState(96);
        match(HelloParser::T__11);
        setState(97);
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

HelloParser::BuiltinTypeContext* HelloParser::builtinType() {
  BuiltinTypeContext *_localctx = _tracker.createInstance<BuiltinTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, HelloParser::RuleBuiltinType);
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
    setState(100);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2088960) != 0))) {
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

//----------------- CommaListContext ------------------------------------------------------------------

HelloParser::CommaListContext::CommaListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::CommaListContext::getRuleIndex() const {
  return HelloParser::RuleCommaList;
}

void HelloParser::CommaListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommaList(this);
}

void HelloParser::CommaListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommaList(this);
}

HelloParser::CommaListContext* HelloParser::commaList() {
  CommaListContext *_localctx = _tracker.createInstance<CommaListContext>(_ctx, getState());
  enterRule(_localctx, 18, HelloParser::RuleCommaList);
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
    do {
      setState(102);
      match(HelloParser::T__4);
      setState(105); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == HelloParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

HelloParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::StmtContext::getRuleIndex() const {
  return HelloParser::RuleStmt;
}

void HelloParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtContext ------------------------------------------------------------------

HelloParser::ExprContext* HelloParser::ExprStmtContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::ExprStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStmt(this);
}
void HelloParser::ExprStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStmt(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

HelloParser::ExprContext* HelloParser::WhileStmtContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::StmtContext* HelloParser::WhileStmtContext::stmt() {
  return getRuleContext<HelloParser::StmtContext>(0);
}

HelloParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}
void HelloParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

HelloParser::ExprContext* HelloParser::IfStmtContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

std::vector<HelloParser::StmtContext *> HelloParser::IfStmtContext::stmt() {
  return getRuleContexts<HelloParser::StmtContext>();
}

HelloParser::StmtContext* HelloParser::IfStmtContext::stmt(size_t i) {
  return getRuleContext<HelloParser::StmtContext>(i);
}

HelloParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void HelloParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

HelloParser::BlockContext* HelloParser::BlockStmtContext::block() {
  return getRuleContext<HelloParser::BlockContext>(0);
}

HelloParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::BlockStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStmt(this);
}
void HelloParser::BlockStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStmt(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

HelloParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::BreakStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStmt(this);
}
void HelloParser::BreakStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStmt(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

HelloParser::ExprContext* HelloParser::ReturnStmtContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}
void HelloParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}
//----------------- RepeatStmtContext ------------------------------------------------------------------

HelloParser::StmtContext* HelloParser::RepeatStmtContext::stmt() {
  return getRuleContext<HelloParser::StmtContext>(0);
}

HelloParser::ExprContext* HelloParser::RepeatStmtContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::RepeatStmtContext::RepeatStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::RepeatStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRepeatStmt(this);
}
void HelloParser::RepeatStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRepeatStmt(this);
}
//----------------- VarDeclStmtContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> HelloParser::VarDeclStmtContext::ID() {
  return getTokens(HelloParser::ID);
}

tree::TerminalNode* HelloParser::VarDeclStmtContext::ID(size_t i) {
  return getToken(HelloParser::ID, i);
}

HelloParser::TypeRefContext* HelloParser::VarDeclStmtContext::typeRef() {
  return getRuleContext<HelloParser::TypeRefContext>(0);
}

HelloParser::VarDeclStmtContext::VarDeclStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void HelloParser::VarDeclStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclStmt(this);
}
void HelloParser::VarDeclStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclStmt(this);
}
HelloParser::StmtContext* HelloParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 20, HelloParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::T__6: {
        _localctx = _tracker.createInstance<HelloParser::BlockStmtContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(107);
        block();
        break;
      }

      case HelloParser::T__20: {
        _localctx = _tracker.createInstance<HelloParser::VarDeclStmtContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(108);
        match(HelloParser::T__20);
        setState(109);
        match(HelloParser::ID);
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == HelloParser::T__4) {
          setState(110);
          match(HelloParser::T__4);
          setState(111);
          match(HelloParser::ID);
          setState(116);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(119);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == HelloParser::T__3) {
          setState(117);
          match(HelloParser::T__3);
          setState(118);
          typeRef();
        }
        setState(121);
        match(HelloParser::T__5);
        break;
      }

      case HelloParser::T__21: {
        _localctx = _tracker.createInstance<HelloParser::IfStmtContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(122);
        match(HelloParser::T__21);
        setState(123);
        expr(0);
        setState(124);
        match(HelloParser::T__22);
        setState(125);
        stmt();
        setState(128);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(126);
          match(HelloParser::T__23);
          setState(127);
          stmt();
          break;
        }

        default:
          break;
        }
        break;
      }

      case HelloParser::T__24: {
        _localctx = _tracker.createInstance<HelloParser::WhileStmtContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(130);
        match(HelloParser::T__24);
        setState(131);
        expr(0);
        setState(132);
        match(HelloParser::T__25);
        setState(133);
        stmt();
        break;
      }

      case HelloParser::T__26: {
        _localctx = _tracker.createInstance<HelloParser::RepeatStmtContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(135);
        match(HelloParser::T__26);
        setState(136);
        stmt();
        setState(137);
        _la = _input->LA(1);
        if (!(_la == HelloParser::T__24

        || _la == HelloParser::T__27)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(138);
        expr(0);
        setState(139);
        match(HelloParser::T__5);
        break;
      }

      case HelloParser::T__28: {
        _localctx = _tracker.createInstance<HelloParser::BreakStmtContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(141);
        match(HelloParser::T__28);
        setState(142);
        match(HelloParser::T__5);
        break;
      }

      case HelloParser::T__29: {
        _localctx = _tracker.createInstance<HelloParser::ReturnStmtContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(143);
        match(HelloParser::T__29);
        setState(145);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 8975313417535492) != 0)) {
          setState(144);
          expr(0);
        }
        setState(147);
        match(HelloParser::T__5);
        break;
      }

      case HelloParser::T__1:
      case HelloParser::T__39:
      case HelloParser::T__40:
      case HelloParser::T__44:
      case HelloParser::BoolLiteral:
      case HelloParser::StringLiteral:
      case HelloParser::CharLiteral:
      case HelloParser::HexLiteral:
      case HelloParser::BitsLiteral:
      case HelloParser::DecimalLiteral:
      case HelloParser::ID: {
        _localctx = _tracker.createInstance<HelloParser::ExprStmtContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(148);
        expr(0);
        setState(149);
        match(HelloParser::T__5);
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

//----------------- ExprContext ------------------------------------------------------------------

HelloParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::ExprContext::getRuleIndex() const {
  return HelloParser::RuleExpr;
}

void HelloParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleExprContext ------------------------------------------------------------------

HelloParser::PrimaryContext* HelloParser::SimpleExprContext::primary() {
  return getRuleContext<HelloParser::PrimaryContext>(0);
}

HelloParser::SimpleExprContext::SimpleExprContext(ExprContext *ctx) { copyFrom(ctx); }

void HelloParser::SimpleExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleExpr(this);
}
void HelloParser::SimpleExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleExpr(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

HelloParser::UnaryOpContext* HelloParser::UnaryExprContext::unaryOp() {
  return getRuleContext<HelloParser::UnaryOpContext>(0);
}

HelloParser::ExprContext* HelloParser::UnaryExprContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::UnaryExprContext::UnaryExprContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- AddExprContext ------------------------------------------------------------------

std::vector<HelloParser::ExprContext *> HelloParser::AddExprContext::expr() {
  return getRuleContexts<HelloParser::ExprContext>();
}

HelloParser::ExprContext* HelloParser::AddExprContext::expr(size_t i) {
  return getRuleContext<HelloParser::ExprContext>(i);
}

HelloParser::AddOpContext* HelloParser::AddExprContext::addOp() {
  return getRuleContext<HelloParser::AddOpContext>(0);
}

HelloParser::AddExprContext::AddExprContext(ExprContext *ctx) { copyFrom(ctx); }

void HelloParser::AddExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpr(this);
}
void HelloParser::AddExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpr(this);
}
//----------------- MulExprContext ------------------------------------------------------------------

std::vector<HelloParser::ExprContext *> HelloParser::MulExprContext::expr() {
  return getRuleContexts<HelloParser::ExprContext>();
}

HelloParser::ExprContext* HelloParser::MulExprContext::expr(size_t i) {
  return getRuleContext<HelloParser::ExprContext>(i);
}

HelloParser::MulOpContext* HelloParser::MulExprContext::mulOp() {
  return getRuleContext<HelloParser::MulOpContext>(0);
}

HelloParser::MulExprContext::MulExprContext(ExprContext *ctx) { copyFrom(ctx); }

void HelloParser::MulExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpr(this);
}
void HelloParser::MulExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpr(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<HelloParser::ExprContext *> HelloParser::OrExprContext::expr() {
  return getRuleContexts<HelloParser::ExprContext>();
}

HelloParser::ExprContext* HelloParser::OrExprContext::expr(size_t i) {
  return getRuleContext<HelloParser::ExprContext>(i);
}

HelloParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }

void HelloParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void HelloParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

tree::TerminalNode* HelloParser::AssignExprContext::ID() {
  return getToken(HelloParser::ID, 0);
}

HelloParser::ExprContext* HelloParser::AssignExprContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::AssignExprContext::AssignExprContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- AndExprContext ------------------------------------------------------------------

std::vector<HelloParser::ExprContext *> HelloParser::AndExprContext::expr() {
  return getRuleContexts<HelloParser::ExprContext>();
}

HelloParser::ExprContext* HelloParser::AndExprContext::expr(size_t i) {
  return getRuleContext<HelloParser::ExprContext>(i);
}

HelloParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }

void HelloParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void HelloParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}
//----------------- CmpExprContext ------------------------------------------------------------------

std::vector<HelloParser::ExprContext *> HelloParser::CmpExprContext::expr() {
  return getRuleContexts<HelloParser::ExprContext>();
}

HelloParser::ExprContext* HelloParser::CmpExprContext::expr(size_t i) {
  return getRuleContext<HelloParser::ExprContext>(i);
}

HelloParser::CmpOpContext* HelloParser::CmpExprContext::cmpOp() {
  return getRuleContext<HelloParser::CmpOpContext>(0);
}

HelloParser::CmpExprContext::CmpExprContext(ExprContext *ctx) { copyFrom(ctx); }

void HelloParser::CmpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCmpExpr(this);
}
void HelloParser::CmpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCmpExpr(this);
}

HelloParser::ExprContext* HelloParser::expr() {
   return expr(0);
}

HelloParser::ExprContext* HelloParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  HelloParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  HelloParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, HelloParser::RuleExpr, precedence);

    

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
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(154);
      match(HelloParser::ID);
      setState(155);
      match(HelloParser::T__30);
      setState(156);
      expr(8);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(157);
      unaryOp();
      setState(158);
      expr(2);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SimpleExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(160);
      primary(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(183);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(181);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(163);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(164);
          match(HelloParser::T__31);
          setState(165);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(166);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(167);
          match(HelloParser::T__32);
          setState(168);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<CmpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(169);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(170);
          cmpOp();
          setState(171);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(173);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(174);
          addOp();
          setState(175);
          expr(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<MulExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(177);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(178);
          mulOp();
          setState(179);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- CmpOpContext ------------------------------------------------------------------

HelloParser::CmpOpContext::CmpOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::CmpOpContext::getRuleIndex() const {
  return HelloParser::RuleCmpOp;
}

void HelloParser::CmpOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCmpOp(this);
}

void HelloParser::CmpOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCmpOp(this);
}

HelloParser::CmpOpContext* HelloParser::cmpOp() {
  CmpOpContext *_localctx = _tracker.createInstance<CmpOpContext>(_ctx, getState());
  enterRule(_localctx, 24, HelloParser::RuleCmpOp);
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
    setState(186);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1082331758592) != 0))) {
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

//----------------- AddOpContext ------------------------------------------------------------------

HelloParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::AddOpContext::getRuleIndex() const {
  return HelloParser::RuleAddOp;
}

void HelloParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void HelloParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}

HelloParser::AddOpContext* HelloParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 26, HelloParser::RuleAddOp);
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
    setState(188);
    _la = _input->LA(1);
    if (!(_la == HelloParser::T__39

    || _la == HelloParser::T__40)) {
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

//----------------- MulOpContext ------------------------------------------------------------------

HelloParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::MulOpContext::getRuleIndex() const {
  return HelloParser::RuleMulOp;
}

void HelloParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void HelloParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}

HelloParser::MulOpContext* HelloParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 28, HelloParser::RuleMulOp);
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
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30786325577728) != 0))) {
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

//----------------- UnaryOpContext ------------------------------------------------------------------

HelloParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::UnaryOpContext::getRuleIndex() const {
  return HelloParser::RuleUnaryOp;
}

void HelloParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void HelloParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

HelloParser::UnaryOpContext* HelloParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 30, HelloParser::RuleUnaryOp);
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
    setState(192);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 38482906972160) != 0))) {
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

//----------------- PrimaryContext ------------------------------------------------------------------

HelloParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HelloParser::PrimaryContext::getRuleIndex() const {
  return HelloParser::RulePrimary;
}

void HelloParser::PrimaryContext::copyFrom(PrimaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IndexExprContext ------------------------------------------------------------------

HelloParser::PrimaryContext* HelloParser::IndexExprContext::primary() {
  return getRuleContext<HelloParser::PrimaryContext>(0);
}

HelloParser::ExprContext* HelloParser::IndexExprContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::IndexExprContext::IndexExprContext(PrimaryContext *ctx) { copyFrom(ctx); }

void HelloParser::IndexExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexExpr(this);
}
void HelloParser::IndexExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexExpr(this);
}
//----------------- LiteralExprContext ------------------------------------------------------------------

HelloParser::LiteralContext* HelloParser::LiteralExprContext::literal() {
  return getRuleContext<HelloParser::LiteralContext>(0);
}

HelloParser::LiteralExprContext::LiteralExprContext(PrimaryContext *ctx) { copyFrom(ctx); }

void HelloParser::LiteralExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralExpr(this);
}
void HelloParser::LiteralExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralExpr(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

HelloParser::PrimaryContext* HelloParser::CallExprContext::primary() {
  return getRuleContext<HelloParser::PrimaryContext>(0);
}

HelloParser::ExprListContext* HelloParser::CallExprContext::exprList() {
  return getRuleContext<HelloParser::ExprListContext>(0);
}

HelloParser::CallExprContext::CallExprContext(PrimaryContext *ctx) { copyFrom(ctx); }

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
//----------------- ParenExprContext ------------------------------------------------------------------

HelloParser::ExprContext* HelloParser::ParenExprContext::expr() {
  return getRuleContext<HelloParser::ExprContext>(0);
}

HelloParser::ParenExprContext::ParenExprContext(PrimaryContext *ctx) { copyFrom(ctx); }

void HelloParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void HelloParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* HelloParser::IdExprContext::ID() {
  return getToken(HelloParser::ID, 0);
}

HelloParser::IdExprContext::IdExprContext(PrimaryContext *ctx) { copyFrom(ctx); }

void HelloParser::IdExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExpr(this);
}
void HelloParser::IdExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HelloListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExpr(this);
}

HelloParser::PrimaryContext* HelloParser::primary() {
   return primary(0);
}

HelloParser::PrimaryContext* HelloParser::primary(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  HelloParser::PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, parentState);
  HelloParser::PrimaryContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, HelloParser::RulePrimary, precedence);

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
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HelloParser::BoolLiteral:
      case HelloParser::StringLiteral:
      case HelloParser::CharLiteral:
      case HelloParser::HexLiteral:
      case HelloParser::BitsLiteral:
      case HelloParser::DecimalLiteral: {
        _localctx = _tracker.createInstance<LiteralExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(195);
        literal();
        break;
      }

      case HelloParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(196);
        match(HelloParser::ID);
        break;
      }

      case HelloParser::T__1: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(197);
        match(HelloParser::T__1);
        setState(198);
        expr(0);
        setState(199);
        match(HelloParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(216);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(214);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<CallExprContext>(_tracker.createInstance<PrimaryContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePrimary);
          setState(203);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(204);
          match(HelloParser::T__1);
          setState(206);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 8975313417535492) != 0)) {
            setState(205);
            exprList();
          }
          setState(208);
          match(HelloParser::T__2);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<IndexExprContext>(_tracker.createInstance<PrimaryContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePrimary);
          setState(209);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(210);
          match(HelloParser::T__9);
          setState(211);
          expr(0);
          setState(212);
          match(HelloParser::T__10);
          break;
        }

        default:
          break;
        } 
      }
      setState(218);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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

HelloParser::ExprListContext* HelloParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 34, HelloParser::RuleExprList);
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
    setState(219);
    expr(0);
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HelloParser::T__4) {
      setState(220);
      match(HelloParser::T__4);
      setState(221);
      expr(0);
      setState(226);
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

HelloParser::LiteralContext* HelloParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 36, HelloParser::RuleLiteral);
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
    setState(227);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4433230883192832) != 0))) {
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

bool HelloParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 16: return primarySempred(antlrcpp::downCast<PrimaryContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool HelloParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool HelloParser::primarySempred(PrimaryContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);

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
