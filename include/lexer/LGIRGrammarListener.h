
// Generated from LGIRGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "lexer/LGIRGrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LGIRGrammarParser.
 */
class  LGIRGrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(LGIRGrammarParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(LGIRGrammarParser::ProgramContext *ctx) = 0;

  virtual void enterGlobalVariable(LGIRGrammarParser::GlobalVariableContext *ctx) = 0;
  virtual void exitGlobalVariable(LGIRGrammarParser::GlobalVariableContext *ctx) = 0;

  virtual void enterStructure(LGIRGrammarParser::StructureContext *ctx) = 0;
  virtual void exitStructure(LGIRGrammarParser::StructureContext *ctx) = 0;

  virtual void enterFields(LGIRGrammarParser::FieldsContext *ctx) = 0;
  virtual void exitFields(LGIRGrammarParser::FieldsContext *ctx) = 0;

  virtual void enterField(LGIRGrammarParser::FieldContext *ctx) = 0;
  virtual void exitField(LGIRGrammarParser::FieldContext *ctx) = 0;

  virtual void enterFunction(LGIRGrammarParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(LGIRGrammarParser::FunctionContext *ctx) = 0;

  virtual void enterStatement(LGIRGrammarParser::StatementContext *ctx) = 0;
  virtual void exitStatement(LGIRGrammarParser::StatementContext *ctx) = 0;

  virtual void enterStack_alloc(LGIRGrammarParser::Stack_allocContext *ctx) = 0;
  virtual void exitStack_alloc(LGIRGrammarParser::Stack_allocContext *ctx) = 0;

  virtual void enterLoad(LGIRGrammarParser::LoadContext *ctx) = 0;
  virtual void exitLoad(LGIRGrammarParser::LoadContext *ctx) = 0;

  virtual void enterStore(LGIRGrammarParser::StoreContext *ctx) = 0;
  virtual void exitStore(LGIRGrammarParser::StoreContext *ctx) = 0;

  virtual void enterAsm(LGIRGrammarParser::AsmContext *ctx) = 0;
  virtual void exitAsm(LGIRGrammarParser::AsmContext *ctx) = 0;

  virtual void enterGoto(LGIRGrammarParser::GotoContext *ctx) = 0;
  virtual void exitGoto(LGIRGrammarParser::GotoContext *ctx) = 0;

  virtual void enterInvoke(LGIRGrammarParser::InvokeContext *ctx) = 0;
  virtual void exitInvoke(LGIRGrammarParser::InvokeContext *ctx) = 0;

  virtual void enterReturn(LGIRGrammarParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(LGIRGrammarParser::ReturnContext *ctx) = 0;

  virtual void enterSetRegister(LGIRGrammarParser::SetRegisterContext *ctx) = 0;
  virtual void exitSetRegister(LGIRGrammarParser::SetRegisterContext *ctx) = 0;

  virtual void enterGetElementPointer(LGIRGrammarParser::GetElementPointerContext *ctx) = 0;
  virtual void exitGetElementPointer(LGIRGrammarParser::GetElementPointerContext *ctx) = 0;

  virtual void enterCmp(LGIRGrammarParser::CmpContext *ctx) = 0;
  virtual void exitCmp(LGIRGrammarParser::CmpContext *ctx) = 0;

  virtual void enterConditionalJump(LGIRGrammarParser::ConditionalJumpContext *ctx) = 0;
  virtual void exitConditionalJump(LGIRGrammarParser::ConditionalJumpContext *ctx) = 0;

  virtual void enterUnaryOperates(LGIRGrammarParser::UnaryOperatesContext *ctx) = 0;
  virtual void exitUnaryOperates(LGIRGrammarParser::UnaryOperatesContext *ctx) = 0;

  virtual void enterBinaryOperates(LGIRGrammarParser::BinaryOperatesContext *ctx) = 0;
  virtual void exitBinaryOperates(LGIRGrammarParser::BinaryOperatesContext *ctx) = 0;

  virtual void enterTypeCast(LGIRGrammarParser::TypeCastContext *ctx) = 0;
  virtual void exitTypeCast(LGIRGrammarParser::TypeCastContext *ctx) = 0;

  virtual void enterType(LGIRGrammarParser::TypeContext *ctx) = 0;
  virtual void exitType(LGIRGrammarParser::TypeContext *ctx) = 0;

  virtual void enterBaseType(LGIRGrammarParser::BaseTypeContext *ctx) = 0;
  virtual void exitBaseType(LGIRGrammarParser::BaseTypeContext *ctx) = 0;

  virtual void enterIntegerType(LGIRGrammarParser::IntegerTypeContext *ctx) = 0;
  virtual void exitIntegerType(LGIRGrammarParser::IntegerTypeContext *ctx) = 0;

  virtual void enterDecimalType(LGIRGrammarParser::DecimalTypeContext *ctx) = 0;
  virtual void exitDecimalType(LGIRGrammarParser::DecimalTypeContext *ctx) = 0;

  virtual void enterArrayType(LGIRGrammarParser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(LGIRGrammarParser::ArrayTypeContext *ctx) = 0;

  virtual void enterVoidType(LGIRGrammarParser::VoidTypeContext *ctx) = 0;
  virtual void exitVoidType(LGIRGrammarParser::VoidTypeContext *ctx) = 0;

  virtual void enterStructureType(LGIRGrammarParser::StructureTypeContext *ctx) = 0;
  virtual void exitStructureType(LGIRGrammarParser::StructureTypeContext *ctx) = 0;

  virtual void enterValues(LGIRGrammarParser::ValuesContext *ctx) = 0;
  virtual void exitValues(LGIRGrammarParser::ValuesContext *ctx) = 0;

  virtual void enterValue(LGIRGrammarParser::ValueContext *ctx) = 0;
  virtual void exitValue(LGIRGrammarParser::ValueContext *ctx) = 0;

  virtual void enterConstant(LGIRGrammarParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(LGIRGrammarParser::ConstantContext *ctx) = 0;

  virtual void enterIntegerConstant(LGIRGrammarParser::IntegerConstantContext *ctx) = 0;
  virtual void exitIntegerConstant(LGIRGrammarParser::IntegerConstantContext *ctx) = 0;

  virtual void enterDecimalConstant(LGIRGrammarParser::DecimalConstantContext *ctx) = 0;
  virtual void exitDecimalConstant(LGIRGrammarParser::DecimalConstantContext *ctx) = 0;

  virtual void enterArrayConstant(LGIRGrammarParser::ArrayConstantContext *ctx) = 0;
  virtual void exitArrayConstant(LGIRGrammarParser::ArrayConstantContext *ctx) = 0;

  virtual void enterFunctionReference(LGIRGrammarParser::FunctionReferenceContext *ctx) = 0;
  virtual void exitFunctionReference(LGIRGrammarParser::FunctionReferenceContext *ctx) = 0;

  virtual void enterGlobalReference(LGIRGrammarParser::GlobalReferenceContext *ctx) = 0;
  virtual void exitGlobalReference(LGIRGrammarParser::GlobalReferenceContext *ctx) = 0;

  virtual void enterLocalReference(LGIRGrammarParser::LocalReferenceContext *ctx) = 0;
  virtual void exitLocalReference(LGIRGrammarParser::LocalReferenceContext *ctx) = 0;

  virtual void enterRegister(LGIRGrammarParser::RegisterContext *ctx) = 0;
  virtual void exitRegister(LGIRGrammarParser::RegisterContext *ctx) = 0;

  virtual void enterRegisterName(LGIRGrammarParser::RegisterNameContext *ctx) = 0;
  virtual void exitRegisterName(LGIRGrammarParser::RegisterNameContext *ctx) = 0;

  virtual void enterLabel(LGIRGrammarParser::LabelContext *ctx) = 0;
  virtual void exitLabel(LGIRGrammarParser::LabelContext *ctx) = 0;

  virtual void enterCondition(LGIRGrammarParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(LGIRGrammarParser::ConditionContext *ctx) = 0;

  virtual void enterUnaryOperator(LGIRGrammarParser::UnaryOperatorContext *ctx) = 0;
  virtual void exitUnaryOperator(LGIRGrammarParser::UnaryOperatorContext *ctx) = 0;

  virtual void enterBinaryOperator(LGIRGrammarParser::BinaryOperatorContext *ctx) = 0;
  virtual void exitBinaryOperator(LGIRGrammarParser::BinaryOperatorContext *ctx) = 0;

  virtual void enterTypeCastKind(LGIRGrammarParser::TypeCastKindContext *ctx) = 0;
  virtual void exitTypeCastKind(LGIRGrammarParser::TypeCastKindContext *ctx) = 0;


};

