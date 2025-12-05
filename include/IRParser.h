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
        std::unordered_map<std::string, value::IRRegister*> name2Register;

    public:
        explicit IRParser(IRModule* module);
        std::any visitProgram(LGIRGrammarParser::ProgramContext* context) override;
        std::any visitGlobalVariable(LGIRGrammarParser::GlobalVariableContext* context) override;
        std::any visitStructure(LGIRGrammarParser::StructureContext* context) override;
        std::any visitFields(LGIRGrammarParser::FieldsContext* context) override;
        std::any visitField(LGIRGrammarParser::FieldContext* context) override;
        std::any visitFunction(LGIRGrammarParser::FunctionContext* context) override;
        std::any visitBasicBlock(LGIRGrammarParser::BasicBlockContext* context) override;
        std::any visitLocalVariables(LGIRGrammarParser::LocalVariablesContext* context) override;
        std::any visitLocalVariable(LGIRGrammarParser::LocalVariableContext* context) override;
        std::any visitAsm(LGIRGrammarParser::AsmContext* context) override;
        std::any visitBinaryOperates(LGIRGrammarParser::BinaryOperatesContext* context) override;
        std::any visitUnaryOperates(LGIRGrammarParser::UnaryOperatesContext* context) override;
        std::any visitGetElementPointer(LGIRGrammarParser::GetElementPointerContext* context) override;
        std::any visitCmp(LGIRGrammarParser::CmpContext* context) override;
        std::any visitConditionalJump(LGIRGrammarParser::ConditionalJumpContext* context) override;
        std::any visitGoto(LGIRGrammarParser::GotoContext* context) override;
        std::any visitInvoke(LGIRGrammarParser::InvokeContext* context) override;
        std::any visitReturn(LGIRGrammarParser::ReturnContext* context) override;
        std::any visitLoad(LGIRGrammarParser::LoadContext* context) override;
        std::any visitStore(LGIRGrammarParser::StoreContext* context) override;
        std::any visitNop(LGIRGrammarParser::NopContext* context) override;
        std::any visitSetRegister(LGIRGrammarParser::SetRegisterContext* context) override;
        std::any visitStackAlloc(LGIRGrammarParser::StackAllocContext* context) override;
        std::any visitTypeCast(LGIRGrammarParser::TypeCastContext* context) override;
        std::any visitPhi(LGIRGrammarParser::PhiContext* context) override;
        std::any visitSwitch(LGIRGrammarParser::SwitchContext* context) override;
        std::any visitPhiValue(LGIRGrammarParser::PhiValueContext* context) override;
        std::any visitSwitchCase(LGIRGrammarParser::SwitchCaseContext* context) override;
        std::any visitValues(LGIRGrammarParser::ValuesContext* context) override;
        std::any visitRegister(LGIRGrammarParser::RegisterContext* context) override;
        std::any visitFunctionReference(LGIRGrammarParser::FunctionReferenceContext* context) override;
        std::any visitGlobalReference(LGIRGrammarParser::GlobalReferenceContext* context) override;
        std::any visitLocalReference(LGIRGrammarParser::LocalReferenceContext* context) override;
        std::any visitConstants(LGIRGrammarParser::ConstantsContext* context) override;
        std::any visitIntegerConstant(LGIRGrammarParser::IntegerConstantContext* context) override;
        std::any visitDecimalConstant(LGIRGrammarParser::DecimalConstantContext* context) override;
        std::any visitArrayConstant(LGIRGrammarParser::ArrayConstantContext* context) override;
        std::any visitStructureInitializer(LGIRGrammarParser::StructureInitializerContext* context) override;
        std::any visitStringConstant(LGIRGrammarParser::StringConstantContext* context) override;
        std::any visitTypes(LGIRGrammarParser::TypesContext* context) override;
        std::any visitType(LGIRGrammarParser::TypeContext* context) override;
        std::any visitIntegerType(LGIRGrammarParser::IntegerTypeContext* context) override;
        std::any visitDecimalType(LGIRGrammarParser::DecimalTypeContext* context) override;
        std::any visitArrayType(LGIRGrammarParser::ArrayTypeContext* context) override;
        std::any visitFunctionReferenceType(LGIRGrammarParser::FunctionReferenceTypeContext* context) override;
        std::any visitStructureType(LGIRGrammarParser::StructureTypeContext* context) override;
        std::any visitVoidType(LGIRGrammarParser::VoidTypeContext* context) override;
        std::any visitLabel(LGIRGrammarParser::LabelContext* context) override;

    private:
        static instruction::IRBinaryOperates::Operator parseBinaryOperator(
            LGIRGrammarParser::BinaryOperatorContext* context);
        static instruction::IRUnaryOperates::Operator parseUnaryOperator(
            LGIRGrammarParser::UnaryOperatorContext* context);
        static base::IRCondition parseCondition(LGIRGrammarParser::ConditionContext* context);
        static instruction::IRTypeCast::Kind parseTypeCastKind(LGIRGrammarParser::TypeCastKindContext* context);
        static std::string getTargetRegisterName(LGIRGrammarParser::RegisterNameContext* context);
        static std::string parseAttribute(LGIRGrammarParser::AttributeContext*  context);
    };

    IRModule* parse(const std::string& code);
    IRModule* parse(std::istream& stream);
    IRModule* parse(antlr4::ANTLRInputStream& stream);
}

#endif //LG_CPP_BINDING_IRPARSER_H
