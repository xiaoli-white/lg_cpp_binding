
// Generated from LGIRGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LGIRGrammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, I1 = 22, I8 = 23, U8 = 24, I16 = 25, U16 = 26, I32 = 27, 
    U32 = 28, I64 = 29, U64 = 30, FLOAT = 31, DOUBLE = 32, VOID = 33, CONST = 34, 
    GLOBAL = 35, STRUCTURE = 36, EXTERN = 37, FUNCTION = 38, NOP = 39, STACK_ALLOC = 40, 
    LOAD = 41, STORE = 42, ASM = 43, GOTO = 44, INVOKE = 45, RETURN = 46, 
    GETELEMENTPTR = 47, CMP = 48, CONDITIONAL_JUMP = 49, PHI = 50, SWITCH = 51, 
    INC = 52, DEC = 53, NOT = 54, NEG = 55, ADD = 56, SUB = 57, MUL = 58, 
    DIV = 59, MOD = 60, AND = 61, OR = 62, XOR = 63, SHL = 64, SHR = 65, 
    USHR = 66, ZEXT = 67, SEXT = 68, TRUNC = 69, INTTOF = 70, FTOINT = 71, 
    INTTOPTR = 72, PTRTOINT = 73, PTRTOPTR = 74, FEXT = 75, FTRUNC = 76, 
    FUNCREF = 77, GLOBALREF = 78, LOCALREF = 79, CONSTANT = 80, LABEL = 81, 
    STRING = 82, ELLIPSIS = 83, MULTIPLY = 84, INT_NUMBER = 85, DECIMAL_NUMBER = 86, 
    WS = 87, STRING_LITERAL = 88, IDENTIFIER = 89
  };

  explicit LGIRGrammarLexer(antlr4::CharStream *input);

  ~LGIRGrammarLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

