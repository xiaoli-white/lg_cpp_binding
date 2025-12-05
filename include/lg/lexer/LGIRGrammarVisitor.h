
// Generated from LGIRGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LGIRGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LGIRGrammarParser.
 */
class  LGIRGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LGIRGrammarParser.
   */
    virtual std::any visitProgram(LGIRGrammarParser::ProgramContext *context) = 0;

    virtual std::any visitGlobalVariable(LGIRGrammarParser::GlobalVariableContext *context) = 0;

    virtual std::any visitStructure(LGIRGrammarParser::StructureContext *context) = 0;

    virtual std::any visitFields(LGIRGrammarParser::FieldsContext *context) = 0;

    virtual std::any visitField(LGIRGrammarParser::FieldContext *context) = 0;

    virtual std::any visitFunction(LGIRGrammarParser::FunctionContext *context) = 0;

    virtual std::any visitLocalVariables(LGIRGrammarParser::LocalVariablesContext *context) = 0;

    virtual std::any visitLocalVariable(LGIRGrammarParser::LocalVariableContext *context) = 0;

    virtual std::any visitBasicBlock(LGIRGrammarParser::BasicBlockContext *context) = 0;

    virtual std::any visitStatement(LGIRGrammarParser::StatementContext *context) = 0;

    virtual std::any visitNop(LGIRGrammarParser::NopContext *context) = 0;

    virtual std::any visitStackAlloc(LGIRGrammarParser::StackAllocContext *context) = 0;

    virtual std::any visitLoad(LGIRGrammarParser::LoadContext *context) = 0;

    virtual std::any visitStore(LGIRGrammarParser::StoreContext *context) = 0;

    virtual std::any visitAsm(LGIRGrammarParser::AsmContext *context) = 0;

    virtual std::any visitGoto(LGIRGrammarParser::GotoContext *context) = 0;

    virtual std::any visitInvoke(LGIRGrammarParser::InvokeContext *context) = 0;

    virtual std::any visitReturn(LGIRGrammarParser::ReturnContext *context) = 0;

    virtual std::any visitSetRegister(LGIRGrammarParser::SetRegisterContext *context) = 0;

    virtual std::any visitGetElementPointer(LGIRGrammarParser::GetElementPointerContext *context) = 0;

    virtual std::any visitCmp(LGIRGrammarParser::CmpContext *context) = 0;

    virtual std::any visitConditionalJump(LGIRGrammarParser::ConditionalJumpContext *context) = 0;

    virtual std::any visitUnaryOperates(LGIRGrammarParser::UnaryOperatesContext *context) = 0;

    virtual std::any visitBinaryOperates(LGIRGrammarParser::BinaryOperatesContext *context) = 0;

    virtual std::any visitTypeCast(LGIRGrammarParser::TypeCastContext *context) = 0;

    virtual std::any visitPhi(LGIRGrammarParser::PhiContext *context) = 0;

    virtual std::any visitSwitch(LGIRGrammarParser::SwitchContext *context) = 0;

    virtual std::any visitPhiValue(LGIRGrammarParser::PhiValueContext *context) = 0;

    virtual std::any visitSwitchCase(LGIRGrammarParser::SwitchCaseContext *context) = 0;

    virtual std::any visitType(LGIRGrammarParser::TypeContext *context) = 0;

    virtual std::any visitBaseType(LGIRGrammarParser::BaseTypeContext *context) = 0;

    virtual std::any visitIntegerType(LGIRGrammarParser::IntegerTypeContext *context) = 0;

    virtual std::any visitDecimalType(LGIRGrammarParser::DecimalTypeContext *context) = 0;

    virtual std::any visitArrayType(LGIRGrammarParser::ArrayTypeContext *context) = 0;

    virtual std::any visitVoidType(LGIRGrammarParser::VoidTypeContext *context) = 0;

    virtual std::any visitStructureType(LGIRGrammarParser::StructureTypeContext *context) = 0;

    virtual std::any visitFunctionReferenceType(LGIRGrammarParser::FunctionReferenceTypeContext *context) = 0;

    virtual std::any visitTypes(LGIRGrammarParser::TypesContext *context) = 0;

    virtual std::any visitValues(LGIRGrammarParser::ValuesContext *context) = 0;

    virtual std::any visitValue(LGIRGrammarParser::ValueContext *context) = 0;

    virtual std::any visitConstants(LGIRGrammarParser::ConstantsContext *context) = 0;

    virtual std::any visitConstant(LGIRGrammarParser::ConstantContext *context) = 0;

    virtual std::any visitIntegerConstant(LGIRGrammarParser::IntegerConstantContext *context) = 0;

    virtual std::any visitDecimalConstant(LGIRGrammarParser::DecimalConstantContext *context) = 0;

    virtual std::any visitArrayConstant(LGIRGrammarParser::ArrayConstantContext *context) = 0;

    virtual std::any visitStructureInitializer(LGIRGrammarParser::StructureInitializerContext *context) = 0;

    virtual std::any visitStringConstant(LGIRGrammarParser::StringConstantContext *context) = 0;

    virtual std::any visitFunctionReference(LGIRGrammarParser::FunctionReferenceContext *context) = 0;

    virtual std::any visitGlobalReference(LGIRGrammarParser::GlobalReferenceContext *context) = 0;

    virtual std::any visitLocalReference(LGIRGrammarParser::LocalReferenceContext *context) = 0;

    virtual std::any visitRegister(LGIRGrammarParser::RegisterContext *context) = 0;

    virtual std::any visitRegisterName(LGIRGrammarParser::RegisterNameContext *context) = 0;

    virtual std::any visitLabel(LGIRGrammarParser::LabelContext *context) = 0;

    virtual std::any visitCondition(LGIRGrammarParser::ConditionContext *context) = 0;

    virtual std::any visitUnaryOperator(LGIRGrammarParser::UnaryOperatorContext *context) = 0;

    virtual std::any visitBinaryOperator(LGIRGrammarParser::BinaryOperatorContext *context) = 0;

    virtual std::any visitTypeCastKind(LGIRGrammarParser::TypeCastKindContext *context) = 0;

    virtual std::any visitAttribute(LGIRGrammarParser::AttributeContext *context) = 0;


};

