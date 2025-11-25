//
// Created by xiaoli on 2025/11/24.
//

#pragma once
#ifndef LG_CPP_BINDING_IRPARSER_H
#define LG_CPP_BINDING_IRPARSER_H

#include <ir.h>
#include <builder.h>
#include <lexer/LGIRGrammarBaseVisitor.h>
#include <lexer/LGIRGrammarParser.h>

#include "lexer/LGIRGrammarLexer.h"


namespace lg::ir::parser
{
    class IRParser;

    class IRParser final : public LGIRGrammarBaseVisitor
    {
    private:
        IRModule* module;
        function::IRFunction* currentFunction = nullptr;
        std::stack<std::any> stack;
        IRBuilder builder;

    public:
        explicit IRParser(IRModule* module);
        std::any visitFunction(LGIRGrammarParser::FunctionContext* context) override;
        std::any visitBasicBlock(LGIRGrammarParser::BasicBlockContext* context) override;
        std::any visitLocalVariables(LGIRGrammarParser::LocalVariablesContext* context) override;
        std::any visitLocalVariable(LGIRGrammarParser::LocalVariableContext* context) override;
        std::any visitReturn(LGIRGrammarParser::ReturnContext* context) override;
        std::any visitIntegerConstant(LGIRGrammarParser::IntegerConstantContext* context) override;
        std::any visitIntegerType(LGIRGrammarParser::IntegerTypeContext* context) override;
    };

    IRModule* parse(const std::string& code);
    IRModule* parse(std::istream& stream);
    IRModule* parse(antlr4::ANTLRInputStream& stream);
}

#endif //LG_CPP_BINDING_IRPARSER_H
