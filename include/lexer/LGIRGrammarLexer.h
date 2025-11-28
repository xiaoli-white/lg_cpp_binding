
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
    GLOBAL = 35, STRUCTURE = 36, FUNCTION = 37, NOP = 38, STACK_ALLOC = 39, 
    LOAD = 40, STORE = 41, ASM = 42, GOTO = 43, INVOKE = 44, RETURN = 45, 
    GETELEMENTPTR = 46, CMP = 47, CONDITIONAL_JUMP = 48, PHI = 49, SWITCH = 50, 
    INC = 51, DEC = 52, NOT = 53, NEG = 54, ADD = 55, SUB = 56, MUL = 57, 
    DIV = 58, MOD = 59, AND = 60, OR = 61, XOR = 62, SHL = 63, SHR = 64, 
    USHR = 65, ZEXT = 66, SEXT = 67, TRUNC = 68, ITOF = 69, FTOI = 70, ITOP = 71, 
    PTOI = 72, PTOP = 73, FEXT = 74, FTRUNC = 75, FUNCREF = 76, GLOBALREF = 77, 
    LOCALREF = 78, CONSTANT = 79, LABEL = 80, STRING = 81, ELLIPSIS = 82, 
    MULTIPLY = 83, INT_NUMBER = 84, DECIMAL_NUMBER = 85, WS = 86, STRING_LITERAL = 87, 
    IDENTIFIER = 88
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

