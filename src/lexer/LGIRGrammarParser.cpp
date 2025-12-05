
// Generated from LGIRGrammar.g4 by ANTLR 4.13.2


#include "lg/lexer/LGIRGrammarListener.h"
#include "lg/lexer/LGIRGrammarVisitor.h"

#include "lg/lexer/LGIRGrammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LGIRGrammarParserStaticData final {
  LGIRGrammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LGIRGrammarParserStaticData(const LGIRGrammarParserStaticData&) = delete;
  LGIRGrammarParserStaticData(LGIRGrammarParserStaticData&&) = delete;
  LGIRGrammarParserStaticData& operator=(const LGIRGrammarParserStaticData&) = delete;
  LGIRGrammarParserStaticData& operator=(LGIRGrammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lgirgrammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LGIRGrammarParserStaticData> lgirgrammarParserStaticData = nullptr;

void lgirgrammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lgirgrammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(lgirgrammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LGIRGrammarParserStaticData>(
    std::vector<std::string>{
      "program", "globalVariable", "structure", "fields", "field", "function", 
      "localVariables", "localVariable", "basicBlock", "statement", "nop", 
      "stackAlloc", "load", "store", "asm", "goto", "invoke", "return", 
      "setRegister", "getElementPointer", "cmp", "conditionalJump", "unaryOperates", 
      "binaryOperates", "typeCast", "phi", "switch", "phiValue", "switchCase", 
      "type", "baseType", "integerType", "decimalType", "arrayType", "voidType", 
      "structureType", "functionReferenceType", "types", "values", "value", 
      "constants", "constant", "integerConstant", "decimalConstant", "arrayConstant", 
      "structureInitializer", "stringConstant", "functionReference", "globalReference", 
      "localReference", "register", "registerName", "label", "condition", 
      "unaryOperator", "binaryOperator", "typeCastKind", "attribute"
    },
    std::vector<std::string>{
      "", "'='", "':'", "'{'", "'}'", "','", "'('", "')'", "'to'", "'['", 
      "']'", "'x'", "'->'", "'%'", "'if_true'", "'if_false'", "'e'", "'ne'", 
      "'l'", "'le'", "'g'", "'ge'", "'i1'", "'i8'", "'u8'", "'i16'", "'u16'", 
      "'i32'", "'u32'", "'i64'", "'u64'", "'float'", "'double'", "'void'", 
      "'const'", "'global'", "'structure'", "'extern'", "'function'", "'nop'", 
      "'stack_alloc'", "'load'", "'store'", "'asm'", "'goto'", "'invoke'", 
      "'return'", "'getelementptr'", "'cmp'", "'conditional_jump'", "'phi'", 
      "'switch'", "'inc'", "'dec'", "'not'", "'neg'", "'add'", "'sub'", 
      "'mul'", "'div'", "'mod'", "'and'", "'or'", "'xor'", "'shl'", "'shr'", 
      "'ushr'", "'zext'", "'sext'", "'trunc'", "'inttof'", "'ftoint'", "'inttoptr'", 
      "'ptrtoint'", "'ptrtoptr'", "'fext'", "'ftrunc'", "'bitcast'", "'funcref'", 
      "'globalref'", "'localref'", "'constant'", "'label'", "'string'", 
      "'...'", "'*'", "'__attribute__'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "I1", "I8", "U8", "I16", "U16", "I32", "U32", 
      "I64", "U64", "FLOAT", "DOUBLE", "VOID", "CONST", "GLOBAL", "STRUCTURE", 
      "EXTERN", "FUNCTION", "NOP", "STACK_ALLOC", "LOAD", "STORE", "ASM", 
      "GOTO", "INVOKE", "RETURN", "GETELEMENTPTR", "CMP", "CONDITIONAL_JUMP", 
      "PHI", "SWITCH", "INC", "DEC", "NOT", "NEG", "ADD", "SUB", "MUL", 
      "DIV", "MOD", "AND", "OR", "XOR", "SHL", "SHR", "USHR", "ZEXT", "SEXT", 
      "TRUNC", "INTTOF", "FTOINT", "INTTOPTR", "PTRTOINT", "PTRTOPTR", "FEXT", 
      "FTRUNC", "BITCAST", "FUNCREF", "GLOBALREF", "LOCALREF", "CONSTANT", 
      "LABEL", "STRING", "ELLIPSIS", "MULTIPLY", "ATTRIBUTE", "INT_NUMBER", 
      "DECIMAL_NUMBER", "WS", "STRING_LITERAL", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,91,519,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,1,0,1,0,1,0,5,0,120,8,0,10,0,12,0,123,9,0,1,0,1,0,1,1,5,
  	1,128,8,1,10,1,12,1,131,9,1,1,1,3,1,134,8,1,1,1,3,1,137,8,1,1,1,1,1,1,
  	1,1,1,3,1,143,8,1,1,1,1,1,3,1,147,8,1,1,2,5,2,150,8,2,10,2,12,2,153,9,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,5,3,164,8,3,10,3,12,3,167,9,3,1,
  	3,3,3,170,8,3,1,4,1,4,1,4,1,5,5,5,176,8,5,10,5,12,5,179,9,5,1,5,3,5,182,
  	8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,191,8,5,1,5,1,5,1,5,1,5,1,5,1,5,5,
  	5,199,8,5,10,5,12,5,202,9,5,1,5,1,5,3,5,206,8,5,1,6,1,6,1,6,5,6,211,8,
  	6,10,6,12,6,214,9,6,1,6,3,6,217,8,6,1,7,1,7,1,7,1,8,1,8,1,8,5,8,225,8,
  	8,10,8,12,8,228,9,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,3,9,247,8,9,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	3,11,257,8,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,3,16,282,
  	8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,3,17,293,8,17,1,18,
  	1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,4,19,305,8,19,11,19,12,19,
  	306,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,
  	1,21,1,21,3,21,324,8,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,25,
  	1,25,1,25,1,25,1,25,5,25,353,8,25,10,25,12,25,356,9,25,1,26,1,26,1,26,
  	1,26,1,26,1,26,5,26,364,8,26,10,26,12,26,367,9,26,1,27,1,27,1,27,1,27,
  	1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,29,1,29,5,29,383,8,29,10,29,
  	12,29,386,9,29,1,30,1,30,1,30,1,30,1,30,1,30,3,30,394,8,30,1,31,1,31,
  	1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,35,1,35,1,35,1,36,
  	1,36,1,36,1,36,3,36,415,8,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,5,37,
  	424,8,37,10,37,12,37,427,9,37,1,37,3,37,430,8,37,1,38,1,38,1,38,5,38,
  	435,8,38,10,38,12,38,438,9,38,1,38,3,38,441,8,38,1,39,1,39,1,39,3,39,
  	446,8,39,1,40,1,40,1,40,5,40,451,8,40,10,40,12,40,454,9,40,1,40,3,40,
  	457,8,40,1,41,1,41,1,41,1,41,1,41,1,41,1,41,3,41,466,8,41,1,42,1,42,1,
  	42,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,46,1,46,1,46,1,47,1,47,1,47,1,48,1,48,1,48,1,49,1,49,1,49,1,50,1,
  	50,1,50,1,51,1,51,1,51,1,52,1,52,1,52,1,53,1,53,1,54,1,54,1,55,1,55,1,
  	56,1,56,1,57,1,57,1,57,1,57,1,57,1,57,0,0,58,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,
  	66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,
  	110,112,114,0,7,1,0,22,30,1,0,31,32,2,0,87,87,91,91,1,0,14,21,1,0,52,
  	55,1,0,56,66,1,0,67,77,523,0,121,1,0,0,0,2,129,1,0,0,0,4,151,1,0,0,0,
  	6,169,1,0,0,0,8,171,1,0,0,0,10,177,1,0,0,0,12,216,1,0,0,0,14,218,1,0,
  	0,0,16,221,1,0,0,0,18,246,1,0,0,0,20,248,1,0,0,0,22,250,1,0,0,0,24,258,
  	1,0,0,0,26,263,1,0,0,0,28,267,1,0,0,0,30,275,1,0,0,0,32,281,1,0,0,0,34,
  	290,1,0,0,0,36,294,1,0,0,0,38,298,1,0,0,0,40,308,1,0,0,0,42,317,1,0,0,
  	0,44,328,1,0,0,0,46,333,1,0,0,0,48,340,1,0,0,0,50,347,1,0,0,0,52,357,
  	1,0,0,0,54,368,1,0,0,0,56,374,1,0,0,0,58,380,1,0,0,0,60,393,1,0,0,0,62,
  	395,1,0,0,0,64,397,1,0,0,0,66,399,1,0,0,0,68,405,1,0,0,0,70,407,1,0,0,
  	0,72,410,1,0,0,0,74,429,1,0,0,0,76,440,1,0,0,0,78,445,1,0,0,0,80,456,
  	1,0,0,0,82,465,1,0,0,0,84,467,1,0,0,0,86,470,1,0,0,0,88,473,1,0,0,0,90,
  	478,1,0,0,0,92,484,1,0,0,0,94,487,1,0,0,0,96,490,1,0,0,0,98,493,1,0,0,
  	0,100,496,1,0,0,0,102,499,1,0,0,0,104,502,1,0,0,0,106,505,1,0,0,0,108,
  	507,1,0,0,0,110,509,1,0,0,0,112,511,1,0,0,0,114,513,1,0,0,0,116,120,3,
  	2,1,0,117,120,3,4,2,0,118,120,3,10,5,0,119,116,1,0,0,0,119,117,1,0,0,
  	0,119,118,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,
  	124,1,0,0,0,123,121,1,0,0,0,124,125,5,0,0,1,125,1,1,0,0,0,126,128,3,114,
  	57,0,127,126,1,0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,
  	130,133,1,0,0,0,131,129,1,0,0,0,132,134,5,37,0,0,133,132,1,0,0,0,133,
  	134,1,0,0,0,134,136,1,0,0,0,135,137,5,34,0,0,136,135,1,0,0,0,136,137,
  	1,0,0,0,137,138,1,0,0,0,138,139,5,35,0,0,139,142,5,91,0,0,140,141,5,1,
  	0,0,141,143,3,82,41,0,142,140,1,0,0,0,142,143,1,0,0,0,143,146,1,0,0,0,
  	144,145,5,2,0,0,145,147,3,58,29,0,146,144,1,0,0,0,146,147,1,0,0,0,147,
  	3,1,0,0,0,148,150,3,114,57,0,149,148,1,0,0,0,150,153,1,0,0,0,151,149,
  	1,0,0,0,151,152,1,0,0,0,152,154,1,0,0,0,153,151,1,0,0,0,154,155,5,36,
  	0,0,155,156,5,91,0,0,156,157,5,3,0,0,157,158,3,6,3,0,158,159,5,4,0,0,
  	159,5,1,0,0,0,160,165,3,8,4,0,161,162,5,5,0,0,162,164,3,8,4,0,163,161,
  	1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,0,166,170,1,0,0,
  	0,167,165,1,0,0,0,168,170,1,0,0,0,169,160,1,0,0,0,169,168,1,0,0,0,170,
  	7,1,0,0,0,171,172,3,58,29,0,172,173,5,91,0,0,173,9,1,0,0,0,174,176,3,
  	114,57,0,175,174,1,0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,
  	0,0,178,181,1,0,0,0,179,177,1,0,0,0,180,182,5,37,0,0,181,180,1,0,0,0,
  	181,182,1,0,0,0,182,183,1,0,0,0,183,184,5,38,0,0,184,185,3,58,29,0,185,
  	186,5,91,0,0,186,187,5,6,0,0,187,190,3,12,6,0,188,189,5,5,0,0,189,191,
  	5,84,0,0,190,188,1,0,0,0,190,191,1,0,0,0,191,192,1,0,0,0,192,205,5,7,
  	0,0,193,194,5,3,0,0,194,195,3,12,6,0,195,196,5,4,0,0,196,200,5,3,0,0,
  	197,199,3,16,8,0,198,197,1,0,0,0,199,202,1,0,0,0,200,198,1,0,0,0,200,
  	201,1,0,0,0,201,203,1,0,0,0,202,200,1,0,0,0,203,204,5,4,0,0,204,206,1,
  	0,0,0,205,193,1,0,0,0,205,206,1,0,0,0,206,11,1,0,0,0,207,212,3,14,7,0,
  	208,209,5,5,0,0,209,211,3,14,7,0,210,208,1,0,0,0,211,214,1,0,0,0,212,
  	210,1,0,0,0,212,213,1,0,0,0,213,217,1,0,0,0,214,212,1,0,0,0,215,217,1,
  	0,0,0,216,207,1,0,0,0,216,215,1,0,0,0,217,13,1,0,0,0,218,219,3,58,29,
  	0,219,220,5,91,0,0,220,15,1,0,0,0,221,222,5,91,0,0,222,226,5,2,0,0,223,
  	225,3,18,9,0,224,223,1,0,0,0,225,228,1,0,0,0,226,224,1,0,0,0,226,227,
  	1,0,0,0,227,17,1,0,0,0,228,226,1,0,0,0,229,247,3,20,10,0,230,247,3,22,
  	11,0,231,247,3,24,12,0,232,247,3,26,13,0,233,247,3,28,14,0,234,247,3,
  	30,15,0,235,247,3,32,16,0,236,247,3,34,17,0,237,247,3,36,18,0,238,247,
  	3,38,19,0,239,247,3,40,20,0,240,247,3,42,21,0,241,247,3,44,22,0,242,247,
  	3,46,23,0,243,247,3,48,24,0,244,247,3,50,25,0,245,247,3,52,26,0,246,229,
  	1,0,0,0,246,230,1,0,0,0,246,231,1,0,0,0,246,232,1,0,0,0,246,233,1,0,0,
  	0,246,234,1,0,0,0,246,235,1,0,0,0,246,236,1,0,0,0,246,237,1,0,0,0,246,
  	238,1,0,0,0,246,239,1,0,0,0,246,240,1,0,0,0,246,241,1,0,0,0,246,242,1,
  	0,0,0,246,243,1,0,0,0,246,244,1,0,0,0,246,245,1,0,0,0,247,19,1,0,0,0,
  	248,249,5,39,0,0,249,21,1,0,0,0,250,251,3,102,51,0,251,252,5,1,0,0,252,
  	253,5,40,0,0,253,256,3,58,29,0,254,255,5,5,0,0,255,257,3,78,39,0,256,
  	254,1,0,0,0,256,257,1,0,0,0,257,23,1,0,0,0,258,259,3,102,51,0,259,260,
  	5,1,0,0,260,261,5,41,0,0,261,262,3,78,39,0,262,25,1,0,0,0,263,264,5,42,
  	0,0,264,265,3,78,39,0,265,266,3,78,39,0,266,27,1,0,0,0,267,268,5,43,0,
  	0,268,269,5,90,0,0,269,270,5,5,0,0,270,271,5,90,0,0,271,272,5,6,0,0,272,
  	273,3,76,38,0,273,274,5,7,0,0,274,29,1,0,0,0,275,276,5,44,0,0,276,277,
  	3,104,52,0,277,31,1,0,0,0,278,279,3,102,51,0,279,280,5,1,0,0,280,282,
  	1,0,0,0,281,278,1,0,0,0,281,282,1,0,0,0,282,283,1,0,0,0,283,284,5,45,
  	0,0,284,285,3,58,29,0,285,286,3,78,39,0,286,287,5,6,0,0,287,288,3,76,
  	38,0,288,289,5,7,0,0,289,33,1,0,0,0,290,292,5,46,0,0,291,293,3,78,39,
  	0,292,291,1,0,0,0,292,293,1,0,0,0,293,35,1,0,0,0,294,295,3,102,51,0,295,
  	296,5,1,0,0,296,297,3,78,39,0,297,37,1,0,0,0,298,299,3,102,51,0,299,300,
  	5,1,0,0,300,301,5,47,0,0,301,304,3,78,39,0,302,303,5,5,0,0,303,305,3,
  	78,39,0,304,302,1,0,0,0,305,306,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,
  	0,307,39,1,0,0,0,308,309,3,102,51,0,309,310,5,1,0,0,310,311,5,48,0,0,
  	311,312,3,106,53,0,312,313,5,5,0,0,313,314,3,78,39,0,314,315,5,5,0,0,
  	315,316,3,78,39,0,316,41,1,0,0,0,317,318,5,49,0,0,318,319,3,106,53,0,
  	319,320,5,5,0,0,320,323,3,78,39,0,321,322,5,5,0,0,322,324,3,78,39,0,323,
  	321,1,0,0,0,323,324,1,0,0,0,324,325,1,0,0,0,325,326,5,5,0,0,326,327,3,
  	104,52,0,327,43,1,0,0,0,328,329,3,102,51,0,329,330,5,1,0,0,330,331,3,
  	108,54,0,331,332,3,78,39,0,332,45,1,0,0,0,333,334,3,102,51,0,334,335,
  	5,1,0,0,335,336,3,110,55,0,336,337,3,78,39,0,337,338,5,5,0,0,338,339,
  	3,78,39,0,339,47,1,0,0,0,340,341,3,102,51,0,341,342,5,1,0,0,342,343,3,
  	112,56,0,343,344,3,78,39,0,344,345,5,8,0,0,345,346,3,58,29,0,346,49,1,
  	0,0,0,347,348,3,102,51,0,348,349,5,1,0,0,349,354,5,50,0,0,350,351,5,5,
  	0,0,351,353,3,54,27,0,352,350,1,0,0,0,353,356,1,0,0,0,354,352,1,0,0,0,
  	354,355,1,0,0,0,355,51,1,0,0,0,356,354,1,0,0,0,357,358,5,51,0,0,358,359,
  	3,78,39,0,359,360,5,5,0,0,360,365,3,104,52,0,361,362,5,5,0,0,362,364,
  	3,56,28,0,363,361,1,0,0,0,364,367,1,0,0,0,365,363,1,0,0,0,365,366,1,0,
  	0,0,366,53,1,0,0,0,367,365,1,0,0,0,368,369,5,9,0,0,369,370,3,104,52,0,
  	370,371,5,5,0,0,371,372,3,78,39,0,372,373,5,10,0,0,373,55,1,0,0,0,374,
  	375,5,9,0,0,375,376,3,84,42,0,376,377,5,5,0,0,377,378,3,104,52,0,378,
  	379,5,10,0,0,379,57,1,0,0,0,380,384,3,60,30,0,381,383,5,85,0,0,382,381,
  	1,0,0,0,383,386,1,0,0,0,384,382,1,0,0,0,384,385,1,0,0,0,385,59,1,0,0,
  	0,386,384,1,0,0,0,387,394,3,62,31,0,388,394,3,64,32,0,389,394,3,66,33,
  	0,390,394,3,68,34,0,391,394,3,70,35,0,392,394,3,72,36,0,393,387,1,0,0,
  	0,393,388,1,0,0,0,393,389,1,0,0,0,393,390,1,0,0,0,393,391,1,0,0,0,393,
  	392,1,0,0,0,394,61,1,0,0,0,395,396,7,0,0,0,396,63,1,0,0,0,397,398,7,1,
  	0,0,398,65,1,0,0,0,399,400,5,9,0,0,400,401,5,87,0,0,401,402,5,11,0,0,
  	402,403,3,58,29,0,403,404,5,10,0,0,404,67,1,0,0,0,405,406,5,33,0,0,406,
  	69,1,0,0,0,407,408,5,36,0,0,408,409,5,91,0,0,409,71,1,0,0,0,410,411,5,
  	6,0,0,411,414,3,74,37,0,412,413,5,5,0,0,413,415,5,84,0,0,414,412,1,0,
  	0,0,414,415,1,0,0,0,415,416,1,0,0,0,416,417,5,7,0,0,417,418,5,12,0,0,
  	418,419,3,58,29,0,419,73,1,0,0,0,420,425,3,58,29,0,421,422,5,5,0,0,422,
  	424,3,58,29,0,423,421,1,0,0,0,424,427,1,0,0,0,425,423,1,0,0,0,425,426,
  	1,0,0,0,426,430,1,0,0,0,427,425,1,0,0,0,428,430,1,0,0,0,429,420,1,0,0,
  	0,429,428,1,0,0,0,430,75,1,0,0,0,431,436,3,78,39,0,432,433,5,5,0,0,433,
  	435,3,78,39,0,434,432,1,0,0,0,435,438,1,0,0,0,436,434,1,0,0,0,436,437,
  	1,0,0,0,437,441,1,0,0,0,438,436,1,0,0,0,439,441,1,0,0,0,440,431,1,0,0,
  	0,440,439,1,0,0,0,441,77,1,0,0,0,442,446,3,100,50,0,443,446,3,82,41,0,
  	444,446,3,98,49,0,445,442,1,0,0,0,445,443,1,0,0,0,445,444,1,0,0,0,446,
  	79,1,0,0,0,447,452,3,82,41,0,448,449,5,5,0,0,449,451,3,82,41,0,450,448,
  	1,0,0,0,451,454,1,0,0,0,452,450,1,0,0,0,452,453,1,0,0,0,453,457,1,0,0,
  	0,454,452,1,0,0,0,455,457,1,0,0,0,456,447,1,0,0,0,456,455,1,0,0,0,457,
  	81,1,0,0,0,458,466,3,84,42,0,459,466,3,86,43,0,460,466,3,88,44,0,461,
  	466,3,90,45,0,462,466,3,92,46,0,463,466,3,94,47,0,464,466,3,96,48,0,465,
  	458,1,0,0,0,465,459,1,0,0,0,465,460,1,0,0,0,465,461,1,0,0,0,465,462,1,
  	0,0,0,465,463,1,0,0,0,465,464,1,0,0,0,466,83,1,0,0,0,467,468,3,62,31,
  	0,468,469,5,87,0,0,469,85,1,0,0,0,470,471,3,64,32,0,471,472,5,88,0,0,
  	472,87,1,0,0,0,473,474,3,66,33,0,474,475,5,9,0,0,475,476,3,80,40,0,476,
  	477,5,10,0,0,477,89,1,0,0,0,478,479,5,81,0,0,479,480,3,70,35,0,480,481,
  	5,3,0,0,481,482,3,80,40,0,482,483,5,4,0,0,483,91,1,0,0,0,484,485,5,83,
  	0,0,485,486,5,90,0,0,486,93,1,0,0,0,487,488,5,78,0,0,488,489,5,91,0,0,
  	489,95,1,0,0,0,490,491,5,79,0,0,491,492,5,91,0,0,492,97,1,0,0,0,493,494,
  	5,80,0,0,494,495,5,91,0,0,495,99,1,0,0,0,496,497,3,58,29,0,497,498,3,
  	102,51,0,498,101,1,0,0,0,499,500,5,13,0,0,500,501,7,2,0,0,501,103,1,0,
  	0,0,502,503,5,82,0,0,503,504,5,91,0,0,504,105,1,0,0,0,505,506,7,3,0,0,
  	506,107,1,0,0,0,507,508,7,4,0,0,508,109,1,0,0,0,509,510,7,5,0,0,510,111,
  	1,0,0,0,511,512,7,6,0,0,512,113,1,0,0,0,513,514,5,86,0,0,514,515,5,6,
  	0,0,515,516,5,90,0,0,516,517,5,7,0,0,517,115,1,0,0,0,37,119,121,129,133,
  	136,142,146,151,165,169,177,181,190,200,205,212,216,226,246,256,281,292,
  	306,323,354,365,384,393,414,425,429,436,440,445,452,456,465
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lgirgrammarParserStaticData = std::move(staticData);
}

}

LGIRGrammarParser::LGIRGrammarParser(TokenStream *input) : LGIRGrammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LGIRGrammarParser::LGIRGrammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LGIRGrammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *lgirgrammarParserStaticData->atn, lgirgrammarParserStaticData->decisionToDFA, lgirgrammarParserStaticData->sharedContextCache, options);
}

LGIRGrammarParser::~LGIRGrammarParser() {
  delete _interpreter;
}

const atn::ATN& LGIRGrammarParser::getATN() const {
  return *lgirgrammarParserStaticData->atn;
}

std::string LGIRGrammarParser::getGrammarFileName() const {
  return "LGIRGrammar.g4";
}

const std::vector<std::string>& LGIRGrammarParser::getRuleNames() const {
  return lgirgrammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& LGIRGrammarParser::getVocabulary() const {
  return lgirgrammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LGIRGrammarParser::getSerializedATN() const {
  return lgirgrammarParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

LGIRGrammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::ProgramContext::EOF() {
  return getToken(LGIRGrammarParser::EOF, 0);
}

std::vector<LGIRGrammarParser::GlobalVariableContext *> LGIRGrammarParser::ProgramContext::globalVariable() {
  return getRuleContexts<LGIRGrammarParser::GlobalVariableContext>();
}

LGIRGrammarParser::GlobalVariableContext* LGIRGrammarParser::ProgramContext::globalVariable(size_t i) {
  return getRuleContext<LGIRGrammarParser::GlobalVariableContext>(i);
}

std::vector<LGIRGrammarParser::StructureContext *> LGIRGrammarParser::ProgramContext::structure() {
  return getRuleContexts<LGIRGrammarParser::StructureContext>();
}

LGIRGrammarParser::StructureContext* LGIRGrammarParser::ProgramContext::structure(size_t i) {
  return getRuleContext<LGIRGrammarParser::StructureContext>(i);
}

std::vector<LGIRGrammarParser::FunctionContext *> LGIRGrammarParser::ProgramContext::function() {
  return getRuleContexts<LGIRGrammarParser::FunctionContext>();
}

LGIRGrammarParser::FunctionContext* LGIRGrammarParser::ProgramContext::function(size_t i) {
  return getRuleContext<LGIRGrammarParser::FunctionContext>(i);
}


size_t LGIRGrammarParser::ProgramContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleProgram;
}

void LGIRGrammarParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void LGIRGrammarParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any LGIRGrammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ProgramContext* LGIRGrammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, LGIRGrammarParser::RuleProgram);
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
    setState(121);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 34) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 34)) & 4503599627370527) != 0)) {
      setState(119);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(116);
        globalVariable();
        break;
      }

      case 2: {
        setState(117);
        structure();
        break;
      }

      case 3: {
        setState(118);
        function();
        break;
      }

      default:
        break;
      }
      setState(123);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(124);
    match(LGIRGrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalVariableContext ------------------------------------------------------------------

LGIRGrammarParser::GlobalVariableContext::GlobalVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::GlobalVariableContext::GLOBAL() {
  return getToken(LGIRGrammarParser::GLOBAL, 0);
}

tree::TerminalNode* LGIRGrammarParser::GlobalVariableContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}

std::vector<LGIRGrammarParser::AttributeContext *> LGIRGrammarParser::GlobalVariableContext::attribute() {
  return getRuleContexts<LGIRGrammarParser::AttributeContext>();
}

LGIRGrammarParser::AttributeContext* LGIRGrammarParser::GlobalVariableContext::attribute(size_t i) {
  return getRuleContext<LGIRGrammarParser::AttributeContext>(i);
}

tree::TerminalNode* LGIRGrammarParser::GlobalVariableContext::EXTERN() {
  return getToken(LGIRGrammarParser::EXTERN, 0);
}

tree::TerminalNode* LGIRGrammarParser::GlobalVariableContext::CONST() {
  return getToken(LGIRGrammarParser::CONST, 0);
}

LGIRGrammarParser::ConstantContext* LGIRGrammarParser::GlobalVariableContext::constant() {
  return getRuleContext<LGIRGrammarParser::ConstantContext>(0);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::GlobalVariableContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}


size_t LGIRGrammarParser::GlobalVariableContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleGlobalVariable;
}

void LGIRGrammarParser::GlobalVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalVariable(this);
}

void LGIRGrammarParser::GlobalVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalVariable(this);
}


std::any LGIRGrammarParser::GlobalVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitGlobalVariable(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::GlobalVariableContext* LGIRGrammarParser::globalVariable() {
  GlobalVariableContext *_localctx = _tracker.createInstance<GlobalVariableContext>(_ctx, getState());
  enterRule(_localctx, 2, LGIRGrammarParser::RuleGlobalVariable);
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
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LGIRGrammarParser::ATTRIBUTE) {
      setState(126);
      attribute();
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::EXTERN) {
      setState(132);
      match(LGIRGrammarParser::EXTERN);
    }
    setState(136);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::CONST) {
      setState(135);
      match(LGIRGrammarParser::CONST);
    }
    setState(138);
    match(LGIRGrammarParser::GLOBAL);
    setState(139);
    match(LGIRGrammarParser::IDENTIFIER);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::T__0) {
      setState(140);
      match(LGIRGrammarParser::T__0);
      setState(141);
      constant();
    }
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::T__1) {
      setState(144);
      match(LGIRGrammarParser::T__1);
      setState(145);
      type();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureContext ------------------------------------------------------------------

LGIRGrammarParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::StructureContext::STRUCTURE() {
  return getToken(LGIRGrammarParser::STRUCTURE, 0);
}

tree::TerminalNode* LGIRGrammarParser::StructureContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}

LGIRGrammarParser::FieldsContext* LGIRGrammarParser::StructureContext::fields() {
  return getRuleContext<LGIRGrammarParser::FieldsContext>(0);
}

std::vector<LGIRGrammarParser::AttributeContext *> LGIRGrammarParser::StructureContext::attribute() {
  return getRuleContexts<LGIRGrammarParser::AttributeContext>();
}

LGIRGrammarParser::AttributeContext* LGIRGrammarParser::StructureContext::attribute(size_t i) {
  return getRuleContext<LGIRGrammarParser::AttributeContext>(i);
}


size_t LGIRGrammarParser::StructureContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleStructure;
}

void LGIRGrammarParser::StructureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure(this);
}

void LGIRGrammarParser::StructureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure(this);
}


std::any LGIRGrammarParser::StructureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitStructure(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::StructureContext* LGIRGrammarParser::structure() {
  StructureContext *_localctx = _tracker.createInstance<StructureContext>(_ctx, getState());
  enterRule(_localctx, 4, LGIRGrammarParser::RuleStructure);
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
    setState(151);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LGIRGrammarParser::ATTRIBUTE) {
      setState(148);
      attribute();
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(154);
    match(LGIRGrammarParser::STRUCTURE);
    setState(155);
    match(LGIRGrammarParser::IDENTIFIER);
    setState(156);
    match(LGIRGrammarParser::T__2);
    setState(157);
    fields();
    setState(158);
    match(LGIRGrammarParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldsContext ------------------------------------------------------------------

LGIRGrammarParser::FieldsContext::FieldsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LGIRGrammarParser::FieldContext *> LGIRGrammarParser::FieldsContext::field() {
  return getRuleContexts<LGIRGrammarParser::FieldContext>();
}

LGIRGrammarParser::FieldContext* LGIRGrammarParser::FieldsContext::field(size_t i) {
  return getRuleContext<LGIRGrammarParser::FieldContext>(i);
}


size_t LGIRGrammarParser::FieldsContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleFields;
}

void LGIRGrammarParser::FieldsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFields(this);
}

void LGIRGrammarParser::FieldsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFields(this);
}


std::any LGIRGrammarParser::FieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitFields(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::FieldsContext* LGIRGrammarParser::fields() {
  FieldsContext *_localctx = _tracker.createInstance<FieldsContext>(_ctx, getState());
  enterRule(_localctx, 6, LGIRGrammarParser::RuleFields);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LGIRGrammarParser::T__5:
      case LGIRGrammarParser::T__8:
      case LGIRGrammarParser::I1:
      case LGIRGrammarParser::I8:
      case LGIRGrammarParser::U8:
      case LGIRGrammarParser::I16:
      case LGIRGrammarParser::U16:
      case LGIRGrammarParser::I32:
      case LGIRGrammarParser::U32:
      case LGIRGrammarParser::I64:
      case LGIRGrammarParser::U64:
      case LGIRGrammarParser::FLOAT:
      case LGIRGrammarParser::DOUBLE:
      case LGIRGrammarParser::VOID:
      case LGIRGrammarParser::STRUCTURE: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        field();
        setState(165);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == LGIRGrammarParser::T__4) {
          setState(161);
          match(LGIRGrammarParser::T__4);
          setState(162);
          field();
          setState(167);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case LGIRGrammarParser::T__3: {
        enterOuterAlt(_localctx, 2);

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

//----------------- FieldContext ------------------------------------------------------------------

LGIRGrammarParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::FieldContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::FieldContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}


size_t LGIRGrammarParser::FieldContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleField;
}

void LGIRGrammarParser::FieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterField(this);
}

void LGIRGrammarParser::FieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitField(this);
}


std::any LGIRGrammarParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::FieldContext* LGIRGrammarParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 8, LGIRGrammarParser::RuleField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    type();
    setState(172);
    match(LGIRGrammarParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

LGIRGrammarParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::FunctionContext::FUNCTION() {
  return getToken(LGIRGrammarParser::FUNCTION, 0);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::FunctionContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::FunctionContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}

std::vector<LGIRGrammarParser::LocalVariablesContext *> LGIRGrammarParser::FunctionContext::localVariables() {
  return getRuleContexts<LGIRGrammarParser::LocalVariablesContext>();
}

LGIRGrammarParser::LocalVariablesContext* LGIRGrammarParser::FunctionContext::localVariables(size_t i) {
  return getRuleContext<LGIRGrammarParser::LocalVariablesContext>(i);
}

std::vector<LGIRGrammarParser::AttributeContext *> LGIRGrammarParser::FunctionContext::attribute() {
  return getRuleContexts<LGIRGrammarParser::AttributeContext>();
}

LGIRGrammarParser::AttributeContext* LGIRGrammarParser::FunctionContext::attribute(size_t i) {
  return getRuleContext<LGIRGrammarParser::AttributeContext>(i);
}

tree::TerminalNode* LGIRGrammarParser::FunctionContext::EXTERN() {
  return getToken(LGIRGrammarParser::EXTERN, 0);
}

tree::TerminalNode* LGIRGrammarParser::FunctionContext::ELLIPSIS() {
  return getToken(LGIRGrammarParser::ELLIPSIS, 0);
}

std::vector<LGIRGrammarParser::BasicBlockContext *> LGIRGrammarParser::FunctionContext::basicBlock() {
  return getRuleContexts<LGIRGrammarParser::BasicBlockContext>();
}

LGIRGrammarParser::BasicBlockContext* LGIRGrammarParser::FunctionContext::basicBlock(size_t i) {
  return getRuleContext<LGIRGrammarParser::BasicBlockContext>(i);
}


size_t LGIRGrammarParser::FunctionContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleFunction;
}

void LGIRGrammarParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void LGIRGrammarParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any LGIRGrammarParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::FunctionContext* LGIRGrammarParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 10, LGIRGrammarParser::RuleFunction);
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
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LGIRGrammarParser::ATTRIBUTE) {
      setState(174);
      attribute();
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(181);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::EXTERN) {
      setState(180);
      match(LGIRGrammarParser::EXTERN);
    }
    setState(183);
    match(LGIRGrammarParser::FUNCTION);
    setState(184);
    type();
    setState(185);
    match(LGIRGrammarParser::IDENTIFIER);
    setState(186);
    match(LGIRGrammarParser::T__5);
    setState(187);
    localVariables();
    setState(190);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::T__4) {
      setState(188);
      match(LGIRGrammarParser::T__4);
      setState(189);
      match(LGIRGrammarParser::ELLIPSIS);
    }
    setState(192);
    match(LGIRGrammarParser::T__6);
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::T__2) {
      setState(193);
      match(LGIRGrammarParser::T__2);
      setState(194);
      localVariables();
      setState(195);
      match(LGIRGrammarParser::T__3);
      setState(196);
      match(LGIRGrammarParser::T__2);
      setState(200);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LGIRGrammarParser::IDENTIFIER) {
        setState(197);
        basicBlock();
        setState(202);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(203);
      match(LGIRGrammarParser::T__3);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalVariablesContext ------------------------------------------------------------------

LGIRGrammarParser::LocalVariablesContext::LocalVariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LGIRGrammarParser::LocalVariableContext *> LGIRGrammarParser::LocalVariablesContext::localVariable() {
  return getRuleContexts<LGIRGrammarParser::LocalVariableContext>();
}

LGIRGrammarParser::LocalVariableContext* LGIRGrammarParser::LocalVariablesContext::localVariable(size_t i) {
  return getRuleContext<LGIRGrammarParser::LocalVariableContext>(i);
}


size_t LGIRGrammarParser::LocalVariablesContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleLocalVariables;
}

void LGIRGrammarParser::LocalVariablesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalVariables(this);
}

void LGIRGrammarParser::LocalVariablesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalVariables(this);
}


std::any LGIRGrammarParser::LocalVariablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitLocalVariables(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::LocalVariablesContext* LGIRGrammarParser::localVariables() {
  LocalVariablesContext *_localctx = _tracker.createInstance<LocalVariablesContext>(_ctx, getState());
  enterRule(_localctx, 12, LGIRGrammarParser::RuleLocalVariables);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(216);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LGIRGrammarParser::T__5:
      case LGIRGrammarParser::T__8:
      case LGIRGrammarParser::I1:
      case LGIRGrammarParser::I8:
      case LGIRGrammarParser::U8:
      case LGIRGrammarParser::I16:
      case LGIRGrammarParser::U16:
      case LGIRGrammarParser::I32:
      case LGIRGrammarParser::U32:
      case LGIRGrammarParser::I64:
      case LGIRGrammarParser::U64:
      case LGIRGrammarParser::FLOAT:
      case LGIRGrammarParser::DOUBLE:
      case LGIRGrammarParser::VOID:
      case LGIRGrammarParser::STRUCTURE: {
        enterOuterAlt(_localctx, 1);
        setState(207);
        localVariable();
        setState(212);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(208);
            match(LGIRGrammarParser::T__4);
            setState(209);
            localVariable(); 
          }
          setState(214);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        }
        break;
      }

      case LGIRGrammarParser::T__3:
      case LGIRGrammarParser::T__4:
      case LGIRGrammarParser::T__6: {
        enterOuterAlt(_localctx, 2);

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

//----------------- LocalVariableContext ------------------------------------------------------------------

LGIRGrammarParser::LocalVariableContext::LocalVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::LocalVariableContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::LocalVariableContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}


size_t LGIRGrammarParser::LocalVariableContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleLocalVariable;
}

void LGIRGrammarParser::LocalVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalVariable(this);
}

void LGIRGrammarParser::LocalVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalVariable(this);
}


std::any LGIRGrammarParser::LocalVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitLocalVariable(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::LocalVariableContext* LGIRGrammarParser::localVariable() {
  LocalVariableContext *_localctx = _tracker.createInstance<LocalVariableContext>(_ctx, getState());
  enterRule(_localctx, 14, LGIRGrammarParser::RuleLocalVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    type();
    setState(219);
    match(LGIRGrammarParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicBlockContext ------------------------------------------------------------------

LGIRGrammarParser::BasicBlockContext::BasicBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::BasicBlockContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}

std::vector<LGIRGrammarParser::StatementContext *> LGIRGrammarParser::BasicBlockContext::statement() {
  return getRuleContexts<LGIRGrammarParser::StatementContext>();
}

LGIRGrammarParser::StatementContext* LGIRGrammarParser::BasicBlockContext::statement(size_t i) {
  return getRuleContext<LGIRGrammarParser::StatementContext>(i);
}


size_t LGIRGrammarParser::BasicBlockContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleBasicBlock;
}

void LGIRGrammarParser::BasicBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicBlock(this);
}

void LGIRGrammarParser::BasicBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicBlock(this);
}


std::any LGIRGrammarParser::BasicBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitBasicBlock(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::BasicBlockContext* LGIRGrammarParser::basicBlock() {
  BasicBlockContext *_localctx = _tracker.createInstance<BasicBlockContext>(_ctx, getState());
  enterRule(_localctx, 16, LGIRGrammarParser::RuleBasicBlock);
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
    setState(221);
    match(LGIRGrammarParser::IDENTIFIER);
    setState(222);
    match(LGIRGrammarParser::T__1);
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2951638964772864) != 0)) {
      setState(223);
      statement();
      setState(228);
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

//----------------- StatementContext ------------------------------------------------------------------

LGIRGrammarParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::NopContext* LGIRGrammarParser::StatementContext::nop() {
  return getRuleContext<LGIRGrammarParser::NopContext>(0);
}

LGIRGrammarParser::StackAllocContext* LGIRGrammarParser::StatementContext::stackAlloc() {
  return getRuleContext<LGIRGrammarParser::StackAllocContext>(0);
}

LGIRGrammarParser::LoadContext* LGIRGrammarParser::StatementContext::load() {
  return getRuleContext<LGIRGrammarParser::LoadContext>(0);
}

LGIRGrammarParser::StoreContext* LGIRGrammarParser::StatementContext::store() {
  return getRuleContext<LGIRGrammarParser::StoreContext>(0);
}

LGIRGrammarParser::AsmContext* LGIRGrammarParser::StatementContext::asm_() {
  return getRuleContext<LGIRGrammarParser::AsmContext>(0);
}

LGIRGrammarParser::GotoContext* LGIRGrammarParser::StatementContext::goto_() {
  return getRuleContext<LGIRGrammarParser::GotoContext>(0);
}

LGIRGrammarParser::InvokeContext* LGIRGrammarParser::StatementContext::invoke() {
  return getRuleContext<LGIRGrammarParser::InvokeContext>(0);
}

LGIRGrammarParser::ReturnContext* LGIRGrammarParser::StatementContext::return_() {
  return getRuleContext<LGIRGrammarParser::ReturnContext>(0);
}

LGIRGrammarParser::SetRegisterContext* LGIRGrammarParser::StatementContext::setRegister() {
  return getRuleContext<LGIRGrammarParser::SetRegisterContext>(0);
}

LGIRGrammarParser::GetElementPointerContext* LGIRGrammarParser::StatementContext::getElementPointer() {
  return getRuleContext<LGIRGrammarParser::GetElementPointerContext>(0);
}

LGIRGrammarParser::CmpContext* LGIRGrammarParser::StatementContext::cmp() {
  return getRuleContext<LGIRGrammarParser::CmpContext>(0);
}

LGIRGrammarParser::ConditionalJumpContext* LGIRGrammarParser::StatementContext::conditionalJump() {
  return getRuleContext<LGIRGrammarParser::ConditionalJumpContext>(0);
}

LGIRGrammarParser::UnaryOperatesContext* LGIRGrammarParser::StatementContext::unaryOperates() {
  return getRuleContext<LGIRGrammarParser::UnaryOperatesContext>(0);
}

LGIRGrammarParser::BinaryOperatesContext* LGIRGrammarParser::StatementContext::binaryOperates() {
  return getRuleContext<LGIRGrammarParser::BinaryOperatesContext>(0);
}

LGIRGrammarParser::TypeCastContext* LGIRGrammarParser::StatementContext::typeCast() {
  return getRuleContext<LGIRGrammarParser::TypeCastContext>(0);
}

LGIRGrammarParser::PhiContext* LGIRGrammarParser::StatementContext::phi() {
  return getRuleContext<LGIRGrammarParser::PhiContext>(0);
}

LGIRGrammarParser::SwitchContext* LGIRGrammarParser::StatementContext::switch_() {
  return getRuleContext<LGIRGrammarParser::SwitchContext>(0);
}


size_t LGIRGrammarParser::StatementContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleStatement;
}

void LGIRGrammarParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void LGIRGrammarParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any LGIRGrammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::StatementContext* LGIRGrammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, LGIRGrammarParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(229);
      nop();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(230);
      stackAlloc();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(231);
      load();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(232);
      store();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(233);
      asm_();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(234);
      goto_();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(235);
      invoke();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(236);
      return_();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(237);
      setRegister();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(238);
      getElementPointer();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(239);
      cmp();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(240);
      conditionalJump();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(241);
      unaryOperates();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(242);
      binaryOperates();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(243);
      typeCast();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(244);
      phi();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(245);
      switch_();
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

//----------------- NopContext ------------------------------------------------------------------

LGIRGrammarParser::NopContext::NopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::NopContext::NOP() {
  return getToken(LGIRGrammarParser::NOP, 0);
}


size_t LGIRGrammarParser::NopContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleNop;
}

void LGIRGrammarParser::NopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNop(this);
}

void LGIRGrammarParser::NopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNop(this);
}


std::any LGIRGrammarParser::NopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitNop(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::NopContext* LGIRGrammarParser::nop() {
  NopContext *_localctx = _tracker.createInstance<NopContext>(_ctx, getState());
  enterRule(_localctx, 20, LGIRGrammarParser::RuleNop);

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
    match(LGIRGrammarParser::NOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StackAllocContext ------------------------------------------------------------------

LGIRGrammarParser::StackAllocContext::StackAllocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::StackAllocContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::StackAllocContext::STACK_ALLOC() {
  return getToken(LGIRGrammarParser::STACK_ALLOC, 0);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::StackAllocContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::StackAllocContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}


size_t LGIRGrammarParser::StackAllocContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleStackAlloc;
}

void LGIRGrammarParser::StackAllocContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStackAlloc(this);
}

void LGIRGrammarParser::StackAllocContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStackAlloc(this);
}


std::any LGIRGrammarParser::StackAllocContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitStackAlloc(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::StackAllocContext* LGIRGrammarParser::stackAlloc() {
  StackAllocContext *_localctx = _tracker.createInstance<StackAllocContext>(_ctx, getState());
  enterRule(_localctx, 22, LGIRGrammarParser::RuleStackAlloc);
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
    setState(250);
    registerName();
    setState(251);
    match(LGIRGrammarParser::T__0);
    setState(252);
    match(LGIRGrammarParser::STACK_ALLOC);
    setState(253);
    type();
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::T__4) {
      setState(254);
      match(LGIRGrammarParser::T__4);
      setState(255);
      value();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoadContext ------------------------------------------------------------------

LGIRGrammarParser::LoadContext::LoadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::LoadContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::LoadContext::LOAD() {
  return getToken(LGIRGrammarParser::LOAD, 0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::LoadContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}


size_t LGIRGrammarParser::LoadContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleLoad;
}

void LGIRGrammarParser::LoadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoad(this);
}

void LGIRGrammarParser::LoadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoad(this);
}


std::any LGIRGrammarParser::LoadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitLoad(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::LoadContext* LGIRGrammarParser::load() {
  LoadContext *_localctx = _tracker.createInstance<LoadContext>(_ctx, getState());
  enterRule(_localctx, 24, LGIRGrammarParser::RuleLoad);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    registerName();
    setState(259);
    match(LGIRGrammarParser::T__0);
    setState(260);
    match(LGIRGrammarParser::LOAD);
    setState(261);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StoreContext ------------------------------------------------------------------

LGIRGrammarParser::StoreContext::StoreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::StoreContext::STORE() {
  return getToken(LGIRGrammarParser::STORE, 0);
}

std::vector<LGIRGrammarParser::ValueContext *> LGIRGrammarParser::StoreContext::value() {
  return getRuleContexts<LGIRGrammarParser::ValueContext>();
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::StoreContext::value(size_t i) {
  return getRuleContext<LGIRGrammarParser::ValueContext>(i);
}


size_t LGIRGrammarParser::StoreContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleStore;
}

void LGIRGrammarParser::StoreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStore(this);
}

void LGIRGrammarParser::StoreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStore(this);
}


std::any LGIRGrammarParser::StoreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitStore(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::StoreContext* LGIRGrammarParser::store() {
  StoreContext *_localctx = _tracker.createInstance<StoreContext>(_ctx, getState());
  enterRule(_localctx, 26, LGIRGrammarParser::RuleStore);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(LGIRGrammarParser::STORE);
    setState(264);
    value();
    setState(265);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsmContext ------------------------------------------------------------------

LGIRGrammarParser::AsmContext::AsmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::AsmContext::ASM() {
  return getToken(LGIRGrammarParser::ASM, 0);
}

std::vector<tree::TerminalNode *> LGIRGrammarParser::AsmContext::STRING_LITERAL() {
  return getTokens(LGIRGrammarParser::STRING_LITERAL);
}

tree::TerminalNode* LGIRGrammarParser::AsmContext::STRING_LITERAL(size_t i) {
  return getToken(LGIRGrammarParser::STRING_LITERAL, i);
}

LGIRGrammarParser::ValuesContext* LGIRGrammarParser::AsmContext::values() {
  return getRuleContext<LGIRGrammarParser::ValuesContext>(0);
}


size_t LGIRGrammarParser::AsmContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleAsm;
}

void LGIRGrammarParser::AsmContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsm(this);
}

void LGIRGrammarParser::AsmContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsm(this);
}


std::any LGIRGrammarParser::AsmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitAsm(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::AsmContext* LGIRGrammarParser::asm_() {
  AsmContext *_localctx = _tracker.createInstance<AsmContext>(_ctx, getState());
  enterRule(_localctx, 28, LGIRGrammarParser::RuleAsm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(LGIRGrammarParser::ASM);
    setState(268);
    match(LGIRGrammarParser::STRING_LITERAL);
    setState(269);
    match(LGIRGrammarParser::T__4);
    setState(270);
    match(LGIRGrammarParser::STRING_LITERAL);
    setState(271);
    match(LGIRGrammarParser::T__5);
    setState(272);
    values();
    setState(273);
    match(LGIRGrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoContext ------------------------------------------------------------------

LGIRGrammarParser::GotoContext::GotoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::GotoContext::GOTO() {
  return getToken(LGIRGrammarParser::GOTO, 0);
}

LGIRGrammarParser::LabelContext* LGIRGrammarParser::GotoContext::label() {
  return getRuleContext<LGIRGrammarParser::LabelContext>(0);
}


size_t LGIRGrammarParser::GotoContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleGoto;
}

void LGIRGrammarParser::GotoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto(this);
}

void LGIRGrammarParser::GotoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto(this);
}


std::any LGIRGrammarParser::GotoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitGoto(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::GotoContext* LGIRGrammarParser::goto_() {
  GotoContext *_localctx = _tracker.createInstance<GotoContext>(_ctx, getState());
  enterRule(_localctx, 30, LGIRGrammarParser::RuleGoto);

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
    match(LGIRGrammarParser::GOTO);
    setState(276);
    label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InvokeContext ------------------------------------------------------------------

LGIRGrammarParser::InvokeContext::InvokeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::InvokeContext::INVOKE() {
  return getToken(LGIRGrammarParser::INVOKE, 0);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::InvokeContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::InvokeContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}

LGIRGrammarParser::ValuesContext* LGIRGrammarParser::InvokeContext::values() {
  return getRuleContext<LGIRGrammarParser::ValuesContext>(0);
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::InvokeContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}


size_t LGIRGrammarParser::InvokeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleInvoke;
}

void LGIRGrammarParser::InvokeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInvoke(this);
}

void LGIRGrammarParser::InvokeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInvoke(this);
}


std::any LGIRGrammarParser::InvokeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitInvoke(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::InvokeContext* LGIRGrammarParser::invoke() {
  InvokeContext *_localctx = _tracker.createInstance<InvokeContext>(_ctx, getState());
  enterRule(_localctx, 32, LGIRGrammarParser::RuleInvoke);
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
    setState(281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::T__12) {
      setState(278);
      registerName();
      setState(279);
      match(LGIRGrammarParser::T__0);
    }
    setState(283);
    match(LGIRGrammarParser::INVOKE);
    setState(284);
    type();
    setState(285);
    value();
    setState(286);
    match(LGIRGrammarParser::T__5);
    setState(287);
    values();
    setState(288);
    match(LGIRGrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnContext ------------------------------------------------------------------

LGIRGrammarParser::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::ReturnContext::RETURN() {
  return getToken(LGIRGrammarParser::RETURN, 0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::ReturnContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}


size_t LGIRGrammarParser::ReturnContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleReturn;
}

void LGIRGrammarParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void LGIRGrammarParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}


std::any LGIRGrammarParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ReturnContext* LGIRGrammarParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 34, LGIRGrammarParser::RuleReturn);
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
    setState(290);
    match(LGIRGrammarParser::RETURN);
    setState(292);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 85895152192) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 78)) & 47) != 0)) {
      setState(291);
      value();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetRegisterContext ------------------------------------------------------------------

LGIRGrammarParser::SetRegisterContext::SetRegisterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::SetRegisterContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::SetRegisterContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}


size_t LGIRGrammarParser::SetRegisterContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleSetRegister;
}

void LGIRGrammarParser::SetRegisterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetRegister(this);
}

void LGIRGrammarParser::SetRegisterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetRegister(this);
}


std::any LGIRGrammarParser::SetRegisterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitSetRegister(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::SetRegisterContext* LGIRGrammarParser::setRegister() {
  SetRegisterContext *_localctx = _tracker.createInstance<SetRegisterContext>(_ctx, getState());
  enterRule(_localctx, 36, LGIRGrammarParser::RuleSetRegister);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    registerName();
    setState(295);
    match(LGIRGrammarParser::T__0);
    setState(296);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GetElementPointerContext ------------------------------------------------------------------

LGIRGrammarParser::GetElementPointerContext::GetElementPointerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::GetElementPointerContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::GetElementPointerContext::GETELEMENTPTR() {
  return getToken(LGIRGrammarParser::GETELEMENTPTR, 0);
}

std::vector<LGIRGrammarParser::ValueContext *> LGIRGrammarParser::GetElementPointerContext::value() {
  return getRuleContexts<LGIRGrammarParser::ValueContext>();
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::GetElementPointerContext::value(size_t i) {
  return getRuleContext<LGIRGrammarParser::ValueContext>(i);
}


size_t LGIRGrammarParser::GetElementPointerContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleGetElementPointer;
}

void LGIRGrammarParser::GetElementPointerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGetElementPointer(this);
}

void LGIRGrammarParser::GetElementPointerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGetElementPointer(this);
}


std::any LGIRGrammarParser::GetElementPointerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitGetElementPointer(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::GetElementPointerContext* LGIRGrammarParser::getElementPointer() {
  GetElementPointerContext *_localctx = _tracker.createInstance<GetElementPointerContext>(_ctx, getState());
  enterRule(_localctx, 38, LGIRGrammarParser::RuleGetElementPointer);
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
    setState(298);
    registerName();
    setState(299);
    match(LGIRGrammarParser::T__0);
    setState(300);
    match(LGIRGrammarParser::GETELEMENTPTR);
    setState(301);
    value();
    setState(304); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(302);
      match(LGIRGrammarParser::T__4);
      setState(303);
      value();
      setState(306); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == LGIRGrammarParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CmpContext ------------------------------------------------------------------

LGIRGrammarParser::CmpContext::CmpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::CmpContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::CmpContext::CMP() {
  return getToken(LGIRGrammarParser::CMP, 0);
}

LGIRGrammarParser::ConditionContext* LGIRGrammarParser::CmpContext::condition() {
  return getRuleContext<LGIRGrammarParser::ConditionContext>(0);
}

std::vector<LGIRGrammarParser::ValueContext *> LGIRGrammarParser::CmpContext::value() {
  return getRuleContexts<LGIRGrammarParser::ValueContext>();
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::CmpContext::value(size_t i) {
  return getRuleContext<LGIRGrammarParser::ValueContext>(i);
}


size_t LGIRGrammarParser::CmpContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleCmp;
}

void LGIRGrammarParser::CmpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCmp(this);
}

void LGIRGrammarParser::CmpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCmp(this);
}


std::any LGIRGrammarParser::CmpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitCmp(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::CmpContext* LGIRGrammarParser::cmp() {
  CmpContext *_localctx = _tracker.createInstance<CmpContext>(_ctx, getState());
  enterRule(_localctx, 40, LGIRGrammarParser::RuleCmp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    registerName();
    setState(309);
    match(LGIRGrammarParser::T__0);
    setState(310);
    match(LGIRGrammarParser::CMP);
    setState(311);
    condition();
    setState(312);
    match(LGIRGrammarParser::T__4);
    setState(313);
    value();
    setState(314);
    match(LGIRGrammarParser::T__4);
    setState(315);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalJumpContext ------------------------------------------------------------------

LGIRGrammarParser::ConditionalJumpContext::ConditionalJumpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::ConditionalJumpContext::CONDITIONAL_JUMP() {
  return getToken(LGIRGrammarParser::CONDITIONAL_JUMP, 0);
}

LGIRGrammarParser::ConditionContext* LGIRGrammarParser::ConditionalJumpContext::condition() {
  return getRuleContext<LGIRGrammarParser::ConditionContext>(0);
}

std::vector<LGIRGrammarParser::ValueContext *> LGIRGrammarParser::ConditionalJumpContext::value() {
  return getRuleContexts<LGIRGrammarParser::ValueContext>();
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::ConditionalJumpContext::value(size_t i) {
  return getRuleContext<LGIRGrammarParser::ValueContext>(i);
}

LGIRGrammarParser::LabelContext* LGIRGrammarParser::ConditionalJumpContext::label() {
  return getRuleContext<LGIRGrammarParser::LabelContext>(0);
}


size_t LGIRGrammarParser::ConditionalJumpContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleConditionalJump;
}

void LGIRGrammarParser::ConditionalJumpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalJump(this);
}

void LGIRGrammarParser::ConditionalJumpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalJump(this);
}


std::any LGIRGrammarParser::ConditionalJumpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitConditionalJump(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ConditionalJumpContext* LGIRGrammarParser::conditionalJump() {
  ConditionalJumpContext *_localctx = _tracker.createInstance<ConditionalJumpContext>(_ctx, getState());
  enterRule(_localctx, 42, LGIRGrammarParser::RuleConditionalJump);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    match(LGIRGrammarParser::CONDITIONAL_JUMP);
    setState(318);
    condition();
    setState(319);
    match(LGIRGrammarParser::T__4);
    setState(320);
    value();
    setState(323);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(321);
      match(LGIRGrammarParser::T__4);
      setState(322);
      value();
      break;
    }

    default:
      break;
    }
    setState(325);
    match(LGIRGrammarParser::T__4);
    setState(326);
    label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatesContext ------------------------------------------------------------------

LGIRGrammarParser::UnaryOperatesContext::UnaryOperatesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::UnaryOperatesContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

LGIRGrammarParser::UnaryOperatorContext* LGIRGrammarParser::UnaryOperatesContext::unaryOperator() {
  return getRuleContext<LGIRGrammarParser::UnaryOperatorContext>(0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::UnaryOperatesContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}


size_t LGIRGrammarParser::UnaryOperatesContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleUnaryOperates;
}

void LGIRGrammarParser::UnaryOperatesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperates(this);
}

void LGIRGrammarParser::UnaryOperatesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperates(this);
}


std::any LGIRGrammarParser::UnaryOperatesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitUnaryOperates(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::UnaryOperatesContext* LGIRGrammarParser::unaryOperates() {
  UnaryOperatesContext *_localctx = _tracker.createInstance<UnaryOperatesContext>(_ctx, getState());
  enterRule(_localctx, 44, LGIRGrammarParser::RuleUnaryOperates);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    registerName();
    setState(329);
    match(LGIRGrammarParser::T__0);
    setState(330);
    unaryOperator();
    setState(331);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryOperatesContext ------------------------------------------------------------------

LGIRGrammarParser::BinaryOperatesContext::BinaryOperatesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::BinaryOperatesContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

LGIRGrammarParser::BinaryOperatorContext* LGIRGrammarParser::BinaryOperatesContext::binaryOperator() {
  return getRuleContext<LGIRGrammarParser::BinaryOperatorContext>(0);
}

std::vector<LGIRGrammarParser::ValueContext *> LGIRGrammarParser::BinaryOperatesContext::value() {
  return getRuleContexts<LGIRGrammarParser::ValueContext>();
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::BinaryOperatesContext::value(size_t i) {
  return getRuleContext<LGIRGrammarParser::ValueContext>(i);
}


size_t LGIRGrammarParser::BinaryOperatesContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleBinaryOperates;
}

void LGIRGrammarParser::BinaryOperatesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOperates(this);
}

void LGIRGrammarParser::BinaryOperatesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOperates(this);
}


std::any LGIRGrammarParser::BinaryOperatesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitBinaryOperates(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::BinaryOperatesContext* LGIRGrammarParser::binaryOperates() {
  BinaryOperatesContext *_localctx = _tracker.createInstance<BinaryOperatesContext>(_ctx, getState());
  enterRule(_localctx, 46, LGIRGrammarParser::RuleBinaryOperates);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    registerName();
    setState(334);
    match(LGIRGrammarParser::T__0);
    setState(335);
    binaryOperator();
    setState(336);
    value();
    setState(337);
    match(LGIRGrammarParser::T__4);
    setState(338);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeCastContext ------------------------------------------------------------------

LGIRGrammarParser::TypeCastContext::TypeCastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::TypeCastContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

LGIRGrammarParser::TypeCastKindContext* LGIRGrammarParser::TypeCastContext::typeCastKind() {
  return getRuleContext<LGIRGrammarParser::TypeCastKindContext>(0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::TypeCastContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::TypeCastContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}


size_t LGIRGrammarParser::TypeCastContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleTypeCast;
}

void LGIRGrammarParser::TypeCastContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeCast(this);
}

void LGIRGrammarParser::TypeCastContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeCast(this);
}


std::any LGIRGrammarParser::TypeCastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitTypeCast(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::TypeCastContext* LGIRGrammarParser::typeCast() {
  TypeCastContext *_localctx = _tracker.createInstance<TypeCastContext>(_ctx, getState());
  enterRule(_localctx, 48, LGIRGrammarParser::RuleTypeCast);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    registerName();
    setState(341);
    match(LGIRGrammarParser::T__0);
    setState(342);
    typeCastKind();
    setState(343);
    value();
    setState(344);
    match(LGIRGrammarParser::T__7);
    setState(345);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PhiContext ------------------------------------------------------------------

LGIRGrammarParser::PhiContext::PhiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::PhiContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::PhiContext::PHI() {
  return getToken(LGIRGrammarParser::PHI, 0);
}

std::vector<LGIRGrammarParser::PhiValueContext *> LGIRGrammarParser::PhiContext::phiValue() {
  return getRuleContexts<LGIRGrammarParser::PhiValueContext>();
}

LGIRGrammarParser::PhiValueContext* LGIRGrammarParser::PhiContext::phiValue(size_t i) {
  return getRuleContext<LGIRGrammarParser::PhiValueContext>(i);
}


size_t LGIRGrammarParser::PhiContext::getRuleIndex() const {
  return LGIRGrammarParser::RulePhi;
}

void LGIRGrammarParser::PhiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhi(this);
}

void LGIRGrammarParser::PhiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhi(this);
}


std::any LGIRGrammarParser::PhiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitPhi(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::PhiContext* LGIRGrammarParser::phi() {
  PhiContext *_localctx = _tracker.createInstance<PhiContext>(_ctx, getState());
  enterRule(_localctx, 50, LGIRGrammarParser::RulePhi);
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
    setState(347);
    registerName();
    setState(348);
    match(LGIRGrammarParser::T__0);
    setState(349);
    match(LGIRGrammarParser::PHI);
    setState(354);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LGIRGrammarParser::T__4) {
      setState(350);
      match(LGIRGrammarParser::T__4);
      setState(351);
      phiValue();
      setState(356);
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

//----------------- SwitchContext ------------------------------------------------------------------

LGIRGrammarParser::SwitchContext::SwitchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::SwitchContext::SWITCH() {
  return getToken(LGIRGrammarParser::SWITCH, 0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::SwitchContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}

LGIRGrammarParser::LabelContext* LGIRGrammarParser::SwitchContext::label() {
  return getRuleContext<LGIRGrammarParser::LabelContext>(0);
}

std::vector<LGIRGrammarParser::SwitchCaseContext *> LGIRGrammarParser::SwitchContext::switchCase() {
  return getRuleContexts<LGIRGrammarParser::SwitchCaseContext>();
}

LGIRGrammarParser::SwitchCaseContext* LGIRGrammarParser::SwitchContext::switchCase(size_t i) {
  return getRuleContext<LGIRGrammarParser::SwitchCaseContext>(i);
}


size_t LGIRGrammarParser::SwitchContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleSwitch;
}

void LGIRGrammarParser::SwitchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch(this);
}

void LGIRGrammarParser::SwitchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch(this);
}


std::any LGIRGrammarParser::SwitchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitSwitch(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::SwitchContext* LGIRGrammarParser::switch_() {
  SwitchContext *_localctx = _tracker.createInstance<SwitchContext>(_ctx, getState());
  enterRule(_localctx, 52, LGIRGrammarParser::RuleSwitch);
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
    setState(357);
    match(LGIRGrammarParser::SWITCH);
    setState(358);
    value();
    setState(359);
    match(LGIRGrammarParser::T__4);
    setState(360);
    label();
    setState(365);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LGIRGrammarParser::T__4) {
      setState(361);
      match(LGIRGrammarParser::T__4);
      setState(362);
      switchCase();
      setState(367);
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

//----------------- PhiValueContext ------------------------------------------------------------------

LGIRGrammarParser::PhiValueContext::PhiValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::LabelContext* LGIRGrammarParser::PhiValueContext::label() {
  return getRuleContext<LGIRGrammarParser::LabelContext>(0);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::PhiValueContext::value() {
  return getRuleContext<LGIRGrammarParser::ValueContext>(0);
}


size_t LGIRGrammarParser::PhiValueContext::getRuleIndex() const {
  return LGIRGrammarParser::RulePhiValue;
}

void LGIRGrammarParser::PhiValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhiValue(this);
}

void LGIRGrammarParser::PhiValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhiValue(this);
}


std::any LGIRGrammarParser::PhiValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitPhiValue(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::PhiValueContext* LGIRGrammarParser::phiValue() {
  PhiValueContext *_localctx = _tracker.createInstance<PhiValueContext>(_ctx, getState());
  enterRule(_localctx, 54, LGIRGrammarParser::RulePhiValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(LGIRGrammarParser::T__8);
    setState(369);
    label();
    setState(370);
    match(LGIRGrammarParser::T__4);
    setState(371);
    value();
    setState(372);
    match(LGIRGrammarParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchCaseContext ------------------------------------------------------------------

LGIRGrammarParser::SwitchCaseContext::SwitchCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::IntegerConstantContext* LGIRGrammarParser::SwitchCaseContext::integerConstant() {
  return getRuleContext<LGIRGrammarParser::IntegerConstantContext>(0);
}

LGIRGrammarParser::LabelContext* LGIRGrammarParser::SwitchCaseContext::label() {
  return getRuleContext<LGIRGrammarParser::LabelContext>(0);
}


size_t LGIRGrammarParser::SwitchCaseContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleSwitchCase;
}

void LGIRGrammarParser::SwitchCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchCase(this);
}

void LGIRGrammarParser::SwitchCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchCase(this);
}


std::any LGIRGrammarParser::SwitchCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitSwitchCase(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::SwitchCaseContext* LGIRGrammarParser::switchCase() {
  SwitchCaseContext *_localctx = _tracker.createInstance<SwitchCaseContext>(_ctx, getState());
  enterRule(_localctx, 56, LGIRGrammarParser::RuleSwitchCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    match(LGIRGrammarParser::T__8);
    setState(375);
    integerConstant();
    setState(376);
    match(LGIRGrammarParser::T__4);
    setState(377);
    label();
    setState(378);
    match(LGIRGrammarParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

LGIRGrammarParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::BaseTypeContext* LGIRGrammarParser::TypeContext::baseType() {
  return getRuleContext<LGIRGrammarParser::BaseTypeContext>(0);
}

std::vector<tree::TerminalNode *> LGIRGrammarParser::TypeContext::MULTIPLY() {
  return getTokens(LGIRGrammarParser::MULTIPLY);
}

tree::TerminalNode* LGIRGrammarParser::TypeContext::MULTIPLY(size_t i) {
  return getToken(LGIRGrammarParser::MULTIPLY, i);
}


size_t LGIRGrammarParser::TypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleType;
}

void LGIRGrammarParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void LGIRGrammarParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any LGIRGrammarParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 58, LGIRGrammarParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(380);
    baseType();
    setState(384);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(381);
        match(LGIRGrammarParser::MULTIPLY); 
      }
      setState(386);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseTypeContext ------------------------------------------------------------------

LGIRGrammarParser::BaseTypeContext::BaseTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::IntegerTypeContext* LGIRGrammarParser::BaseTypeContext::integerType() {
  return getRuleContext<LGIRGrammarParser::IntegerTypeContext>(0);
}

LGIRGrammarParser::DecimalTypeContext* LGIRGrammarParser::BaseTypeContext::decimalType() {
  return getRuleContext<LGIRGrammarParser::DecimalTypeContext>(0);
}

LGIRGrammarParser::ArrayTypeContext* LGIRGrammarParser::BaseTypeContext::arrayType() {
  return getRuleContext<LGIRGrammarParser::ArrayTypeContext>(0);
}

LGIRGrammarParser::VoidTypeContext* LGIRGrammarParser::BaseTypeContext::voidType() {
  return getRuleContext<LGIRGrammarParser::VoidTypeContext>(0);
}

LGIRGrammarParser::StructureTypeContext* LGIRGrammarParser::BaseTypeContext::structureType() {
  return getRuleContext<LGIRGrammarParser::StructureTypeContext>(0);
}

LGIRGrammarParser::FunctionReferenceTypeContext* LGIRGrammarParser::BaseTypeContext::functionReferenceType() {
  return getRuleContext<LGIRGrammarParser::FunctionReferenceTypeContext>(0);
}


size_t LGIRGrammarParser::BaseTypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleBaseType;
}

void LGIRGrammarParser::BaseTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaseType(this);
}

void LGIRGrammarParser::BaseTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaseType(this);
}


std::any LGIRGrammarParser::BaseTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitBaseType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::BaseTypeContext* LGIRGrammarParser::baseType() {
  BaseTypeContext *_localctx = _tracker.createInstance<BaseTypeContext>(_ctx, getState());
  enterRule(_localctx, 60, LGIRGrammarParser::RuleBaseType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LGIRGrammarParser::I1:
      case LGIRGrammarParser::I8:
      case LGIRGrammarParser::U8:
      case LGIRGrammarParser::I16:
      case LGIRGrammarParser::U16:
      case LGIRGrammarParser::I32:
      case LGIRGrammarParser::U32:
      case LGIRGrammarParser::I64:
      case LGIRGrammarParser::U64: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        integerType();
        break;
      }

      case LGIRGrammarParser::FLOAT:
      case LGIRGrammarParser::DOUBLE: {
        enterOuterAlt(_localctx, 2);
        setState(388);
        decimalType();
        break;
      }

      case LGIRGrammarParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(389);
        arrayType();
        break;
      }

      case LGIRGrammarParser::VOID: {
        enterOuterAlt(_localctx, 4);
        setState(390);
        voidType();
        break;
      }

      case LGIRGrammarParser::STRUCTURE: {
        enterOuterAlt(_localctx, 5);
        setState(391);
        structureType();
        break;
      }

      case LGIRGrammarParser::T__5: {
        enterOuterAlt(_localctx, 6);
        setState(392);
        functionReferenceType();
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

//----------------- IntegerTypeContext ------------------------------------------------------------------

LGIRGrammarParser::IntegerTypeContext::IntegerTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::I1() {
  return getToken(LGIRGrammarParser::I1, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::I8() {
  return getToken(LGIRGrammarParser::I8, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::U8() {
  return getToken(LGIRGrammarParser::U8, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::I16() {
  return getToken(LGIRGrammarParser::I16, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::U16() {
  return getToken(LGIRGrammarParser::U16, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::I32() {
  return getToken(LGIRGrammarParser::I32, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::U32() {
  return getToken(LGIRGrammarParser::U32, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::I64() {
  return getToken(LGIRGrammarParser::I64, 0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerTypeContext::U64() {
  return getToken(LGIRGrammarParser::U64, 0);
}


size_t LGIRGrammarParser::IntegerTypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleIntegerType;
}

void LGIRGrammarParser::IntegerTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerType(this);
}

void LGIRGrammarParser::IntegerTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerType(this);
}


std::any LGIRGrammarParser::IntegerTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitIntegerType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::IntegerTypeContext* LGIRGrammarParser::integerType() {
  IntegerTypeContext *_localctx = _tracker.createInstance<IntegerTypeContext>(_ctx, getState());
  enterRule(_localctx, 62, LGIRGrammarParser::RuleIntegerType);
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
    setState(395);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2143289344) != 0))) {
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

//----------------- DecimalTypeContext ------------------------------------------------------------------

LGIRGrammarParser::DecimalTypeContext::DecimalTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::DecimalTypeContext::FLOAT() {
  return getToken(LGIRGrammarParser::FLOAT, 0);
}

tree::TerminalNode* LGIRGrammarParser::DecimalTypeContext::DOUBLE() {
  return getToken(LGIRGrammarParser::DOUBLE, 0);
}


size_t LGIRGrammarParser::DecimalTypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleDecimalType;
}

void LGIRGrammarParser::DecimalTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecimalType(this);
}

void LGIRGrammarParser::DecimalTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecimalType(this);
}


std::any LGIRGrammarParser::DecimalTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitDecimalType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::DecimalTypeContext* LGIRGrammarParser::decimalType() {
  DecimalTypeContext *_localctx = _tracker.createInstance<DecimalTypeContext>(_ctx, getState());
  enterRule(_localctx, 64, LGIRGrammarParser::RuleDecimalType);
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
    setState(397);
    _la = _input->LA(1);
    if (!(_la == LGIRGrammarParser::FLOAT

    || _la == LGIRGrammarParser::DOUBLE)) {
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

//----------------- ArrayTypeContext ------------------------------------------------------------------

LGIRGrammarParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::ArrayTypeContext::INT_NUMBER() {
  return getToken(LGIRGrammarParser::INT_NUMBER, 0);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::ArrayTypeContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}


size_t LGIRGrammarParser::ArrayTypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleArrayType;
}

void LGIRGrammarParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void LGIRGrammarParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}


std::any LGIRGrammarParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ArrayTypeContext* LGIRGrammarParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 66, LGIRGrammarParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(LGIRGrammarParser::T__8);
    setState(400);
    match(LGIRGrammarParser::INT_NUMBER);
    setState(401);
    match(LGIRGrammarParser::T__10);
    setState(402);
    type();
    setState(403);
    match(LGIRGrammarParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VoidTypeContext ------------------------------------------------------------------

LGIRGrammarParser::VoidTypeContext::VoidTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::VoidTypeContext::VOID() {
  return getToken(LGIRGrammarParser::VOID, 0);
}


size_t LGIRGrammarParser::VoidTypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleVoidType;
}

void LGIRGrammarParser::VoidTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoidType(this);
}

void LGIRGrammarParser::VoidTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoidType(this);
}


std::any LGIRGrammarParser::VoidTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitVoidType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::VoidTypeContext* LGIRGrammarParser::voidType() {
  VoidTypeContext *_localctx = _tracker.createInstance<VoidTypeContext>(_ctx, getState());
  enterRule(_localctx, 68, LGIRGrammarParser::RuleVoidType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    match(LGIRGrammarParser::VOID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureTypeContext ------------------------------------------------------------------

LGIRGrammarParser::StructureTypeContext::StructureTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::StructureTypeContext::STRUCTURE() {
  return getToken(LGIRGrammarParser::STRUCTURE, 0);
}

tree::TerminalNode* LGIRGrammarParser::StructureTypeContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}


size_t LGIRGrammarParser::StructureTypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleStructureType;
}

void LGIRGrammarParser::StructureTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructureType(this);
}

void LGIRGrammarParser::StructureTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructureType(this);
}


std::any LGIRGrammarParser::StructureTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitStructureType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::StructureTypeContext* LGIRGrammarParser::structureType() {
  StructureTypeContext *_localctx = _tracker.createInstance<StructureTypeContext>(_ctx, getState());
  enterRule(_localctx, 70, LGIRGrammarParser::RuleStructureType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(LGIRGrammarParser::STRUCTURE);
    setState(408);
    match(LGIRGrammarParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionReferenceTypeContext ------------------------------------------------------------------

LGIRGrammarParser::FunctionReferenceTypeContext::FunctionReferenceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::TypesContext* LGIRGrammarParser::FunctionReferenceTypeContext::types() {
  return getRuleContext<LGIRGrammarParser::TypesContext>(0);
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::FunctionReferenceTypeContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::FunctionReferenceTypeContext::ELLIPSIS() {
  return getToken(LGIRGrammarParser::ELLIPSIS, 0);
}


size_t LGIRGrammarParser::FunctionReferenceTypeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleFunctionReferenceType;
}

void LGIRGrammarParser::FunctionReferenceTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionReferenceType(this);
}

void LGIRGrammarParser::FunctionReferenceTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionReferenceType(this);
}


std::any LGIRGrammarParser::FunctionReferenceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitFunctionReferenceType(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::FunctionReferenceTypeContext* LGIRGrammarParser::functionReferenceType() {
  FunctionReferenceTypeContext *_localctx = _tracker.createInstance<FunctionReferenceTypeContext>(_ctx, getState());
  enterRule(_localctx, 72, LGIRGrammarParser::RuleFunctionReferenceType);
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
    setState(410);
    match(LGIRGrammarParser::T__5);
    setState(411);
    types();
    setState(414);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LGIRGrammarParser::T__4) {
      setState(412);
      match(LGIRGrammarParser::T__4);
      setState(413);
      match(LGIRGrammarParser::ELLIPSIS);
    }
    setState(416);
    match(LGIRGrammarParser::T__6);
    setState(417);
    match(LGIRGrammarParser::T__11);
    setState(418);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypesContext ------------------------------------------------------------------

LGIRGrammarParser::TypesContext::TypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LGIRGrammarParser::TypeContext *> LGIRGrammarParser::TypesContext::type() {
  return getRuleContexts<LGIRGrammarParser::TypeContext>();
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::TypesContext::type(size_t i) {
  return getRuleContext<LGIRGrammarParser::TypeContext>(i);
}


size_t LGIRGrammarParser::TypesContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleTypes;
}

void LGIRGrammarParser::TypesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypes(this);
}

void LGIRGrammarParser::TypesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypes(this);
}


std::any LGIRGrammarParser::TypesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitTypes(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::TypesContext* LGIRGrammarParser::types() {
  TypesContext *_localctx = _tracker.createInstance<TypesContext>(_ctx, getState());
  enterRule(_localctx, 74, LGIRGrammarParser::RuleTypes);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(429);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LGIRGrammarParser::T__5:
      case LGIRGrammarParser::T__8:
      case LGIRGrammarParser::I1:
      case LGIRGrammarParser::I8:
      case LGIRGrammarParser::U8:
      case LGIRGrammarParser::I16:
      case LGIRGrammarParser::U16:
      case LGIRGrammarParser::I32:
      case LGIRGrammarParser::U32:
      case LGIRGrammarParser::I64:
      case LGIRGrammarParser::U64:
      case LGIRGrammarParser::FLOAT:
      case LGIRGrammarParser::DOUBLE:
      case LGIRGrammarParser::VOID:
      case LGIRGrammarParser::STRUCTURE: {
        enterOuterAlt(_localctx, 1);
        setState(420);
        type();
        setState(425);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(421);
            match(LGIRGrammarParser::T__4);
            setState(422);
            type(); 
          }
          setState(427);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
        }
        break;
      }

      case LGIRGrammarParser::T__4:
      case LGIRGrammarParser::T__6: {
        enterOuterAlt(_localctx, 2);

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

//----------------- ValuesContext ------------------------------------------------------------------

LGIRGrammarParser::ValuesContext::ValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LGIRGrammarParser::ValueContext *> LGIRGrammarParser::ValuesContext::value() {
  return getRuleContexts<LGIRGrammarParser::ValueContext>();
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::ValuesContext::value(size_t i) {
  return getRuleContext<LGIRGrammarParser::ValueContext>(i);
}


size_t LGIRGrammarParser::ValuesContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleValues;
}

void LGIRGrammarParser::ValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValues(this);
}

void LGIRGrammarParser::ValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValues(this);
}


std::any LGIRGrammarParser::ValuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitValues(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ValuesContext* LGIRGrammarParser::values() {
  ValuesContext *_localctx = _tracker.createInstance<ValuesContext>(_ctx, getState());
  enterRule(_localctx, 76, LGIRGrammarParser::RuleValues);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(440);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LGIRGrammarParser::T__5:
      case LGIRGrammarParser::T__8:
      case LGIRGrammarParser::I1:
      case LGIRGrammarParser::I8:
      case LGIRGrammarParser::U8:
      case LGIRGrammarParser::I16:
      case LGIRGrammarParser::U16:
      case LGIRGrammarParser::I32:
      case LGIRGrammarParser::U32:
      case LGIRGrammarParser::I64:
      case LGIRGrammarParser::U64:
      case LGIRGrammarParser::FLOAT:
      case LGIRGrammarParser::DOUBLE:
      case LGIRGrammarParser::VOID:
      case LGIRGrammarParser::STRUCTURE:
      case LGIRGrammarParser::FUNCREF:
      case LGIRGrammarParser::GLOBALREF:
      case LGIRGrammarParser::LOCALREF:
      case LGIRGrammarParser::CONSTANT:
      case LGIRGrammarParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(431);
        value();
        setState(436);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == LGIRGrammarParser::T__4) {
          setState(432);
          match(LGIRGrammarParser::T__4);
          setState(433);
          value();
          setState(438);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case LGIRGrammarParser::T__6: {
        enterOuterAlt(_localctx, 2);

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

//----------------- ValueContext ------------------------------------------------------------------

LGIRGrammarParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::RegisterContext* LGIRGrammarParser::ValueContext::register_() {
  return getRuleContext<LGIRGrammarParser::RegisterContext>(0);
}

LGIRGrammarParser::ConstantContext* LGIRGrammarParser::ValueContext::constant() {
  return getRuleContext<LGIRGrammarParser::ConstantContext>(0);
}

LGIRGrammarParser::LocalReferenceContext* LGIRGrammarParser::ValueContext::localReference() {
  return getRuleContext<LGIRGrammarParser::LocalReferenceContext>(0);
}


size_t LGIRGrammarParser::ValueContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleValue;
}

void LGIRGrammarParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void LGIRGrammarParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


std::any LGIRGrammarParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ValueContext* LGIRGrammarParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 78, LGIRGrammarParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(445);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(442);
      register_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(443);
      constant();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(444);
      localReference();
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

//----------------- ConstantsContext ------------------------------------------------------------------

LGIRGrammarParser::ConstantsContext::ConstantsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LGIRGrammarParser::ConstantContext *> LGIRGrammarParser::ConstantsContext::constant() {
  return getRuleContexts<LGIRGrammarParser::ConstantContext>();
}

LGIRGrammarParser::ConstantContext* LGIRGrammarParser::ConstantsContext::constant(size_t i) {
  return getRuleContext<LGIRGrammarParser::ConstantContext>(i);
}


size_t LGIRGrammarParser::ConstantsContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleConstants;
}

void LGIRGrammarParser::ConstantsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstants(this);
}

void LGIRGrammarParser::ConstantsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstants(this);
}


std::any LGIRGrammarParser::ConstantsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitConstants(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ConstantsContext* LGIRGrammarParser::constants() {
  ConstantsContext *_localctx = _tracker.createInstance<ConstantsContext>(_ctx, getState());
  enterRule(_localctx, 80, LGIRGrammarParser::RuleConstants);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(456);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LGIRGrammarParser::T__8:
      case LGIRGrammarParser::I1:
      case LGIRGrammarParser::I8:
      case LGIRGrammarParser::U8:
      case LGIRGrammarParser::I16:
      case LGIRGrammarParser::U16:
      case LGIRGrammarParser::I32:
      case LGIRGrammarParser::U32:
      case LGIRGrammarParser::I64:
      case LGIRGrammarParser::U64:
      case LGIRGrammarParser::FLOAT:
      case LGIRGrammarParser::DOUBLE:
      case LGIRGrammarParser::FUNCREF:
      case LGIRGrammarParser::GLOBALREF:
      case LGIRGrammarParser::CONSTANT:
      case LGIRGrammarParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(447);
        constant();
        setState(452);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == LGIRGrammarParser::T__4) {
          setState(448);
          match(LGIRGrammarParser::T__4);
          setState(449);
          constant();
          setState(454);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case LGIRGrammarParser::T__3:
      case LGIRGrammarParser::T__9: {
        enterOuterAlt(_localctx, 2);

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

//----------------- ConstantContext ------------------------------------------------------------------

LGIRGrammarParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::IntegerConstantContext* LGIRGrammarParser::ConstantContext::integerConstant() {
  return getRuleContext<LGIRGrammarParser::IntegerConstantContext>(0);
}

LGIRGrammarParser::DecimalConstantContext* LGIRGrammarParser::ConstantContext::decimalConstant() {
  return getRuleContext<LGIRGrammarParser::DecimalConstantContext>(0);
}

LGIRGrammarParser::ArrayConstantContext* LGIRGrammarParser::ConstantContext::arrayConstant() {
  return getRuleContext<LGIRGrammarParser::ArrayConstantContext>(0);
}

LGIRGrammarParser::StructureInitializerContext* LGIRGrammarParser::ConstantContext::structureInitializer() {
  return getRuleContext<LGIRGrammarParser::StructureInitializerContext>(0);
}

LGIRGrammarParser::StringConstantContext* LGIRGrammarParser::ConstantContext::stringConstant() {
  return getRuleContext<LGIRGrammarParser::StringConstantContext>(0);
}

LGIRGrammarParser::FunctionReferenceContext* LGIRGrammarParser::ConstantContext::functionReference() {
  return getRuleContext<LGIRGrammarParser::FunctionReferenceContext>(0);
}

LGIRGrammarParser::GlobalReferenceContext* LGIRGrammarParser::ConstantContext::globalReference() {
  return getRuleContext<LGIRGrammarParser::GlobalReferenceContext>(0);
}


size_t LGIRGrammarParser::ConstantContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleConstant;
}

void LGIRGrammarParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void LGIRGrammarParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}


std::any LGIRGrammarParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ConstantContext* LGIRGrammarParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 82, LGIRGrammarParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(465);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LGIRGrammarParser::I1:
      case LGIRGrammarParser::I8:
      case LGIRGrammarParser::U8:
      case LGIRGrammarParser::I16:
      case LGIRGrammarParser::U16:
      case LGIRGrammarParser::I32:
      case LGIRGrammarParser::U32:
      case LGIRGrammarParser::I64:
      case LGIRGrammarParser::U64: {
        enterOuterAlt(_localctx, 1);
        setState(458);
        integerConstant();
        break;
      }

      case LGIRGrammarParser::FLOAT:
      case LGIRGrammarParser::DOUBLE: {
        enterOuterAlt(_localctx, 2);
        setState(459);
        decimalConstant();
        break;
      }

      case LGIRGrammarParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(460);
        arrayConstant();
        break;
      }

      case LGIRGrammarParser::CONSTANT: {
        enterOuterAlt(_localctx, 4);
        setState(461);
        structureInitializer();
        break;
      }

      case LGIRGrammarParser::STRING: {
        enterOuterAlt(_localctx, 5);
        setState(462);
        stringConstant();
        break;
      }

      case LGIRGrammarParser::FUNCREF: {
        enterOuterAlt(_localctx, 6);
        setState(463);
        functionReference();
        break;
      }

      case LGIRGrammarParser::GLOBALREF: {
        enterOuterAlt(_localctx, 7);
        setState(464);
        globalReference();
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

//----------------- IntegerConstantContext ------------------------------------------------------------------

LGIRGrammarParser::IntegerConstantContext::IntegerConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::IntegerTypeContext* LGIRGrammarParser::IntegerConstantContext::integerType() {
  return getRuleContext<LGIRGrammarParser::IntegerTypeContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::IntegerConstantContext::INT_NUMBER() {
  return getToken(LGIRGrammarParser::INT_NUMBER, 0);
}


size_t LGIRGrammarParser::IntegerConstantContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleIntegerConstant;
}

void LGIRGrammarParser::IntegerConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerConstant(this);
}

void LGIRGrammarParser::IntegerConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerConstant(this);
}


std::any LGIRGrammarParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::IntegerConstantContext* LGIRGrammarParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 84, LGIRGrammarParser::RuleIntegerConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    integerType();
    setState(468);
    match(LGIRGrammarParser::INT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalConstantContext ------------------------------------------------------------------

LGIRGrammarParser::DecimalConstantContext::DecimalConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::DecimalTypeContext* LGIRGrammarParser::DecimalConstantContext::decimalType() {
  return getRuleContext<LGIRGrammarParser::DecimalTypeContext>(0);
}

tree::TerminalNode* LGIRGrammarParser::DecimalConstantContext::DECIMAL_NUMBER() {
  return getToken(LGIRGrammarParser::DECIMAL_NUMBER, 0);
}


size_t LGIRGrammarParser::DecimalConstantContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleDecimalConstant;
}

void LGIRGrammarParser::DecimalConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecimalConstant(this);
}

void LGIRGrammarParser::DecimalConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecimalConstant(this);
}


std::any LGIRGrammarParser::DecimalConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitDecimalConstant(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::DecimalConstantContext* LGIRGrammarParser::decimalConstant() {
  DecimalConstantContext *_localctx = _tracker.createInstance<DecimalConstantContext>(_ctx, getState());
  enterRule(_localctx, 86, LGIRGrammarParser::RuleDecimalConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(470);
    decimalType();
    setState(471);
    match(LGIRGrammarParser::DECIMAL_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayConstantContext ------------------------------------------------------------------

LGIRGrammarParser::ArrayConstantContext::ArrayConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::ArrayTypeContext* LGIRGrammarParser::ArrayConstantContext::arrayType() {
  return getRuleContext<LGIRGrammarParser::ArrayTypeContext>(0);
}

LGIRGrammarParser::ConstantsContext* LGIRGrammarParser::ArrayConstantContext::constants() {
  return getRuleContext<LGIRGrammarParser::ConstantsContext>(0);
}


size_t LGIRGrammarParser::ArrayConstantContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleArrayConstant;
}

void LGIRGrammarParser::ArrayConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayConstant(this);
}

void LGIRGrammarParser::ArrayConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayConstant(this);
}


std::any LGIRGrammarParser::ArrayConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitArrayConstant(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ArrayConstantContext* LGIRGrammarParser::arrayConstant() {
  ArrayConstantContext *_localctx = _tracker.createInstance<ArrayConstantContext>(_ctx, getState());
  enterRule(_localctx, 88, LGIRGrammarParser::RuleArrayConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    arrayType();
    setState(474);
    match(LGIRGrammarParser::T__8);
    setState(475);
    constants();
    setState(476);
    match(LGIRGrammarParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureInitializerContext ------------------------------------------------------------------

LGIRGrammarParser::StructureInitializerContext::StructureInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::StructureInitializerContext::CONSTANT() {
  return getToken(LGIRGrammarParser::CONSTANT, 0);
}

LGIRGrammarParser::StructureTypeContext* LGIRGrammarParser::StructureInitializerContext::structureType() {
  return getRuleContext<LGIRGrammarParser::StructureTypeContext>(0);
}

LGIRGrammarParser::ConstantsContext* LGIRGrammarParser::StructureInitializerContext::constants() {
  return getRuleContext<LGIRGrammarParser::ConstantsContext>(0);
}


size_t LGIRGrammarParser::StructureInitializerContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleStructureInitializer;
}

void LGIRGrammarParser::StructureInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructureInitializer(this);
}

void LGIRGrammarParser::StructureInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructureInitializer(this);
}


std::any LGIRGrammarParser::StructureInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitStructureInitializer(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::StructureInitializerContext* LGIRGrammarParser::structureInitializer() {
  StructureInitializerContext *_localctx = _tracker.createInstance<StructureInitializerContext>(_ctx, getState());
  enterRule(_localctx, 90, LGIRGrammarParser::RuleStructureInitializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(478);
    match(LGIRGrammarParser::CONSTANT);
    setState(479);
    structureType();
    setState(480);
    match(LGIRGrammarParser::T__2);
    setState(481);
    constants();
    setState(482);
    match(LGIRGrammarParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

LGIRGrammarParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::StringConstantContext::STRING() {
  return getToken(LGIRGrammarParser::STRING, 0);
}

tree::TerminalNode* LGIRGrammarParser::StringConstantContext::STRING_LITERAL() {
  return getToken(LGIRGrammarParser::STRING_LITERAL, 0);
}


size_t LGIRGrammarParser::StringConstantContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleStringConstant;
}

void LGIRGrammarParser::StringConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringConstant(this);
}

void LGIRGrammarParser::StringConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringConstant(this);
}


std::any LGIRGrammarParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::StringConstantContext* LGIRGrammarParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 92, LGIRGrammarParser::RuleStringConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(LGIRGrammarParser::STRING);
    setState(485);
    match(LGIRGrammarParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionReferenceContext ------------------------------------------------------------------

LGIRGrammarParser::FunctionReferenceContext::FunctionReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::FunctionReferenceContext::FUNCREF() {
  return getToken(LGIRGrammarParser::FUNCREF, 0);
}

tree::TerminalNode* LGIRGrammarParser::FunctionReferenceContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}


size_t LGIRGrammarParser::FunctionReferenceContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleFunctionReference;
}

void LGIRGrammarParser::FunctionReferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionReference(this);
}

void LGIRGrammarParser::FunctionReferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionReference(this);
}


std::any LGIRGrammarParser::FunctionReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitFunctionReference(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::FunctionReferenceContext* LGIRGrammarParser::functionReference() {
  FunctionReferenceContext *_localctx = _tracker.createInstance<FunctionReferenceContext>(_ctx, getState());
  enterRule(_localctx, 94, LGIRGrammarParser::RuleFunctionReference);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    match(LGIRGrammarParser::FUNCREF);
    setState(488);
    match(LGIRGrammarParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalReferenceContext ------------------------------------------------------------------

LGIRGrammarParser::GlobalReferenceContext::GlobalReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::GlobalReferenceContext::GLOBALREF() {
  return getToken(LGIRGrammarParser::GLOBALREF, 0);
}

tree::TerminalNode* LGIRGrammarParser::GlobalReferenceContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}


size_t LGIRGrammarParser::GlobalReferenceContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleGlobalReference;
}

void LGIRGrammarParser::GlobalReferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalReference(this);
}

void LGIRGrammarParser::GlobalReferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalReference(this);
}


std::any LGIRGrammarParser::GlobalReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitGlobalReference(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::GlobalReferenceContext* LGIRGrammarParser::globalReference() {
  GlobalReferenceContext *_localctx = _tracker.createInstance<GlobalReferenceContext>(_ctx, getState());
  enterRule(_localctx, 96, LGIRGrammarParser::RuleGlobalReference);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(490);
    match(LGIRGrammarParser::GLOBALREF);
    setState(491);
    match(LGIRGrammarParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalReferenceContext ------------------------------------------------------------------

LGIRGrammarParser::LocalReferenceContext::LocalReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::LocalReferenceContext::LOCALREF() {
  return getToken(LGIRGrammarParser::LOCALREF, 0);
}

tree::TerminalNode* LGIRGrammarParser::LocalReferenceContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}


size_t LGIRGrammarParser::LocalReferenceContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleLocalReference;
}

void LGIRGrammarParser::LocalReferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalReference(this);
}

void LGIRGrammarParser::LocalReferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalReference(this);
}


std::any LGIRGrammarParser::LocalReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitLocalReference(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::LocalReferenceContext* LGIRGrammarParser::localReference() {
  LocalReferenceContext *_localctx = _tracker.createInstance<LocalReferenceContext>(_ctx, getState());
  enterRule(_localctx, 98, LGIRGrammarParser::RuleLocalReference);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    match(LGIRGrammarParser::LOCALREF);
    setState(494);
    match(LGIRGrammarParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegisterContext ------------------------------------------------------------------

LGIRGrammarParser::RegisterContext::RegisterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LGIRGrammarParser::TypeContext* LGIRGrammarParser::RegisterContext::type() {
  return getRuleContext<LGIRGrammarParser::TypeContext>(0);
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::RegisterContext::registerName() {
  return getRuleContext<LGIRGrammarParser::RegisterNameContext>(0);
}


size_t LGIRGrammarParser::RegisterContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleRegister;
}

void LGIRGrammarParser::RegisterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegister(this);
}

void LGIRGrammarParser::RegisterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegister(this);
}


std::any LGIRGrammarParser::RegisterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitRegister(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::RegisterContext* LGIRGrammarParser::register_() {
  RegisterContext *_localctx = _tracker.createInstance<RegisterContext>(_ctx, getState());
  enterRule(_localctx, 100, LGIRGrammarParser::RuleRegister);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    type();
    setState(497);
    registerName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegisterNameContext ------------------------------------------------------------------

LGIRGrammarParser::RegisterNameContext::RegisterNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::RegisterNameContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}

tree::TerminalNode* LGIRGrammarParser::RegisterNameContext::INT_NUMBER() {
  return getToken(LGIRGrammarParser::INT_NUMBER, 0);
}


size_t LGIRGrammarParser::RegisterNameContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleRegisterName;
}

void LGIRGrammarParser::RegisterNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegisterName(this);
}

void LGIRGrammarParser::RegisterNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegisterName(this);
}


std::any LGIRGrammarParser::RegisterNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitRegisterName(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::RegisterNameContext* LGIRGrammarParser::registerName() {
  RegisterNameContext *_localctx = _tracker.createInstance<RegisterNameContext>(_ctx, getState());
  enterRule(_localctx, 102, LGIRGrammarParser::RuleRegisterName);
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
    setState(499);
    match(LGIRGrammarParser::T__12);
    setState(500);
    _la = _input->LA(1);
    if (!(_la == LGIRGrammarParser::INT_NUMBER

    || _la == LGIRGrammarParser::IDENTIFIER)) {
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

//----------------- LabelContext ------------------------------------------------------------------

LGIRGrammarParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::LabelContext::LABEL() {
  return getToken(LGIRGrammarParser::LABEL, 0);
}

tree::TerminalNode* LGIRGrammarParser::LabelContext::IDENTIFIER() {
  return getToken(LGIRGrammarParser::IDENTIFIER, 0);
}


size_t LGIRGrammarParser::LabelContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleLabel;
}

void LGIRGrammarParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void LGIRGrammarParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}


std::any LGIRGrammarParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::LabelContext* LGIRGrammarParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 104, LGIRGrammarParser::RuleLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(502);
    match(LGIRGrammarParser::LABEL);
    setState(503);
    match(LGIRGrammarParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

LGIRGrammarParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LGIRGrammarParser::ConditionContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleCondition;
}

void LGIRGrammarParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void LGIRGrammarParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}


std::any LGIRGrammarParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::ConditionContext* LGIRGrammarParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 106, LGIRGrammarParser::RuleCondition);
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
    setState(505);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4177920) != 0))) {
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

//----------------- UnaryOperatorContext ------------------------------------------------------------------

LGIRGrammarParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::UnaryOperatorContext::INC() {
  return getToken(LGIRGrammarParser::INC, 0);
}

tree::TerminalNode* LGIRGrammarParser::UnaryOperatorContext::DEC() {
  return getToken(LGIRGrammarParser::DEC, 0);
}

tree::TerminalNode* LGIRGrammarParser::UnaryOperatorContext::NOT() {
  return getToken(LGIRGrammarParser::NOT, 0);
}

tree::TerminalNode* LGIRGrammarParser::UnaryOperatorContext::NEG() {
  return getToken(LGIRGrammarParser::NEG, 0);
}


size_t LGIRGrammarParser::UnaryOperatorContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleUnaryOperator;
}

void LGIRGrammarParser::UnaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperator(this);
}

void LGIRGrammarParser::UnaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperator(this);
}


std::any LGIRGrammarParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::UnaryOperatorContext* LGIRGrammarParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 108, LGIRGrammarParser::RuleUnaryOperator);
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
    setState(507);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 67553994410557440) != 0))) {
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

//----------------- BinaryOperatorContext ------------------------------------------------------------------

LGIRGrammarParser::BinaryOperatorContext::BinaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::ADD() {
  return getToken(LGIRGrammarParser::ADD, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::SUB() {
  return getToken(LGIRGrammarParser::SUB, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::MUL() {
  return getToken(LGIRGrammarParser::MUL, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::DIV() {
  return getToken(LGIRGrammarParser::DIV, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::MOD() {
  return getToken(LGIRGrammarParser::MOD, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::AND() {
  return getToken(LGIRGrammarParser::AND, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::OR() {
  return getToken(LGIRGrammarParser::OR, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::XOR() {
  return getToken(LGIRGrammarParser::XOR, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::SHL() {
  return getToken(LGIRGrammarParser::SHL, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::SHR() {
  return getToken(LGIRGrammarParser::SHR, 0);
}

tree::TerminalNode* LGIRGrammarParser::BinaryOperatorContext::USHR() {
  return getToken(LGIRGrammarParser::USHR, 0);
}


size_t LGIRGrammarParser::BinaryOperatorContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleBinaryOperator;
}

void LGIRGrammarParser::BinaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOperator(this);
}

void LGIRGrammarParser::BinaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOperator(this);
}


std::any LGIRGrammarParser::BinaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitBinaryOperator(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::BinaryOperatorContext* LGIRGrammarParser::binaryOperator() {
  BinaryOperatorContext *_localctx = _tracker.createInstance<BinaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 110, LGIRGrammarParser::RuleBinaryOperator);
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
    setState(509);
    _la = _input->LA(1);
    if (!(((((_la - 56) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 56)) & 2047) != 0))) {
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

//----------------- TypeCastKindContext ------------------------------------------------------------------

LGIRGrammarParser::TypeCastKindContext::TypeCastKindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::ZEXT() {
  return getToken(LGIRGrammarParser::ZEXT, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::SEXT() {
  return getToken(LGIRGrammarParser::SEXT, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::TRUNC() {
  return getToken(LGIRGrammarParser::TRUNC, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::INTTOF() {
  return getToken(LGIRGrammarParser::INTTOF, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::FTOINT() {
  return getToken(LGIRGrammarParser::FTOINT, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::INTTOPTR() {
  return getToken(LGIRGrammarParser::INTTOPTR, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::PTRTOINT() {
  return getToken(LGIRGrammarParser::PTRTOINT, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::PTRTOPTR() {
  return getToken(LGIRGrammarParser::PTRTOPTR, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::FEXT() {
  return getToken(LGIRGrammarParser::FEXT, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::FTRUNC() {
  return getToken(LGIRGrammarParser::FTRUNC, 0);
}

tree::TerminalNode* LGIRGrammarParser::TypeCastKindContext::BITCAST() {
  return getToken(LGIRGrammarParser::BITCAST, 0);
}


size_t LGIRGrammarParser::TypeCastKindContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleTypeCastKind;
}

void LGIRGrammarParser::TypeCastKindContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeCastKind(this);
}

void LGIRGrammarParser::TypeCastKindContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeCastKind(this);
}


std::any LGIRGrammarParser::TypeCastKindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitTypeCastKind(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::TypeCastKindContext* LGIRGrammarParser::typeCastKind() {
  TypeCastKindContext *_localctx = _tracker.createInstance<TypeCastKindContext>(_ctx, getState());
  enterRule(_localctx, 112, LGIRGrammarParser::RuleTypeCastKind);
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
    setState(511);
    _la = _input->LA(1);
    if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & 2047) != 0))) {
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

//----------------- AttributeContext ------------------------------------------------------------------

LGIRGrammarParser::AttributeContext::AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LGIRGrammarParser::AttributeContext::ATTRIBUTE() {
  return getToken(LGIRGrammarParser::ATTRIBUTE, 0);
}

tree::TerminalNode* LGIRGrammarParser::AttributeContext::STRING_LITERAL() {
  return getToken(LGIRGrammarParser::STRING_LITERAL, 0);
}


size_t LGIRGrammarParser::AttributeContext::getRuleIndex() const {
  return LGIRGrammarParser::RuleAttribute;
}

void LGIRGrammarParser::AttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute(this);
}

void LGIRGrammarParser::AttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LGIRGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute(this);
}


std::any LGIRGrammarParser::AttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LGIRGrammarVisitor*>(visitor))
    return parserVisitor->visitAttribute(this);
  else
    return visitor->visitChildren(this);
}

LGIRGrammarParser::AttributeContext* LGIRGrammarParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 114, LGIRGrammarParser::RuleAttribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    match(LGIRGrammarParser::ATTRIBUTE);
    setState(514);
    match(LGIRGrammarParser::T__5);
    setState(515);
    match(LGIRGrammarParser::STRING_LITERAL);
    setState(516);
    match(LGIRGrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void LGIRGrammarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lgirgrammarParserInitialize();
#else
  ::antlr4::internal::call_once(lgirgrammarParserOnceFlag, lgirgrammarParserInitialize);
#endif
}
