
// Generated from LGIRGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LGIRGrammarListener.h"


/**
 * This class provides an empty implementation of LGIRGrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LGIRGrammarBaseListener : public LGIRGrammarListener {
public:

  virtual void enterProgram(LGIRGrammarParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(LGIRGrammarParser::ProgramContext * /*ctx*/) override { }

  virtual void enterGlobalVariable(LGIRGrammarParser::GlobalVariableContext * /*ctx*/) override { }
  virtual void exitGlobalVariable(LGIRGrammarParser::GlobalVariableContext * /*ctx*/) override { }

  virtual void enterStructure(LGIRGrammarParser::StructureContext * /*ctx*/) override { }
  virtual void exitStructure(LGIRGrammarParser::StructureContext * /*ctx*/) override { }

  virtual void enterFields(LGIRGrammarParser::FieldsContext * /*ctx*/) override { }
  virtual void exitFields(LGIRGrammarParser::FieldsContext * /*ctx*/) override { }

  virtual void enterField(LGIRGrammarParser::FieldContext * /*ctx*/) override { }
  virtual void exitField(LGIRGrammarParser::FieldContext * /*ctx*/) override { }

  virtual void enterFunction(LGIRGrammarParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(LGIRGrammarParser::FunctionContext * /*ctx*/) override { }

  virtual void enterLocalVariables(LGIRGrammarParser::LocalVariablesContext * /*ctx*/) override { }
  virtual void exitLocalVariables(LGIRGrammarParser::LocalVariablesContext * /*ctx*/) override { }

  virtual void enterLocalVariable(LGIRGrammarParser::LocalVariableContext * /*ctx*/) override { }
  virtual void exitLocalVariable(LGIRGrammarParser::LocalVariableContext * /*ctx*/) override { }

  virtual void enterBasicBlock(LGIRGrammarParser::BasicBlockContext * /*ctx*/) override { }
  virtual void exitBasicBlock(LGIRGrammarParser::BasicBlockContext * /*ctx*/) override { }

  virtual void enterStatement(LGIRGrammarParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(LGIRGrammarParser::StatementContext * /*ctx*/) override { }

  virtual void enterNop(LGIRGrammarParser::NopContext * /*ctx*/) override { }
  virtual void exitNop(LGIRGrammarParser::NopContext * /*ctx*/) override { }

  virtual void enterStackAlloc(LGIRGrammarParser::StackAllocContext * /*ctx*/) override { }
  virtual void exitStackAlloc(LGIRGrammarParser::StackAllocContext * /*ctx*/) override { }

  virtual void enterLoad(LGIRGrammarParser::LoadContext * /*ctx*/) override { }
  virtual void exitLoad(LGIRGrammarParser::LoadContext * /*ctx*/) override { }

  virtual void enterStore(LGIRGrammarParser::StoreContext * /*ctx*/) override { }
  virtual void exitStore(LGIRGrammarParser::StoreContext * /*ctx*/) override { }

  virtual void enterAsm(LGIRGrammarParser::AsmContext * /*ctx*/) override { }
  virtual void exitAsm(LGIRGrammarParser::AsmContext * /*ctx*/) override { }

  virtual void enterGoto(LGIRGrammarParser::GotoContext * /*ctx*/) override { }
  virtual void exitGoto(LGIRGrammarParser::GotoContext * /*ctx*/) override { }

  virtual void enterInvoke(LGIRGrammarParser::InvokeContext * /*ctx*/) override { }
  virtual void exitInvoke(LGIRGrammarParser::InvokeContext * /*ctx*/) override { }

  virtual void enterReturn(LGIRGrammarParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(LGIRGrammarParser::ReturnContext * /*ctx*/) override { }

  virtual void enterSetRegister(LGIRGrammarParser::SetRegisterContext * /*ctx*/) override { }
  virtual void exitSetRegister(LGIRGrammarParser::SetRegisterContext * /*ctx*/) override { }

  virtual void enterGetElementPointer(LGIRGrammarParser::GetElementPointerContext * /*ctx*/) override { }
  virtual void exitGetElementPointer(LGIRGrammarParser::GetElementPointerContext * /*ctx*/) override { }

  virtual void enterCmp(LGIRGrammarParser::CmpContext * /*ctx*/) override { }
  virtual void exitCmp(LGIRGrammarParser::CmpContext * /*ctx*/) override { }

  virtual void enterConditionalJump(LGIRGrammarParser::ConditionalJumpContext * /*ctx*/) override { }
  virtual void exitConditionalJump(LGIRGrammarParser::ConditionalJumpContext * /*ctx*/) override { }

  virtual void enterUnaryOperates(LGIRGrammarParser::UnaryOperatesContext * /*ctx*/) override { }
  virtual void exitUnaryOperates(LGIRGrammarParser::UnaryOperatesContext * /*ctx*/) override { }

  virtual void enterBinaryOperates(LGIRGrammarParser::BinaryOperatesContext * /*ctx*/) override { }
  virtual void exitBinaryOperates(LGIRGrammarParser::BinaryOperatesContext * /*ctx*/) override { }

  virtual void enterTypeCast(LGIRGrammarParser::TypeCastContext * /*ctx*/) override { }
  virtual void exitTypeCast(LGIRGrammarParser::TypeCastContext * /*ctx*/) override { }

  virtual void enterPhi(LGIRGrammarParser::PhiContext * /*ctx*/) override { }
  virtual void exitPhi(LGIRGrammarParser::PhiContext * /*ctx*/) override { }

  virtual void enterSwitch(LGIRGrammarParser::SwitchContext * /*ctx*/) override { }
  virtual void exitSwitch(LGIRGrammarParser::SwitchContext * /*ctx*/) override { }

  virtual void enterPhiValue(LGIRGrammarParser::PhiValueContext * /*ctx*/) override { }
  virtual void exitPhiValue(LGIRGrammarParser::PhiValueContext * /*ctx*/) override { }

  virtual void enterSwitchCase(LGIRGrammarParser::SwitchCaseContext * /*ctx*/) override { }
  virtual void exitSwitchCase(LGIRGrammarParser::SwitchCaseContext * /*ctx*/) override { }

  virtual void enterType(LGIRGrammarParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(LGIRGrammarParser::TypeContext * /*ctx*/) override { }

  virtual void enterBaseType(LGIRGrammarParser::BaseTypeContext * /*ctx*/) override { }
  virtual void exitBaseType(LGIRGrammarParser::BaseTypeContext * /*ctx*/) override { }

  virtual void enterIntegerType(LGIRGrammarParser::IntegerTypeContext * /*ctx*/) override { }
  virtual void exitIntegerType(LGIRGrammarParser::IntegerTypeContext * /*ctx*/) override { }

  virtual void enterDecimalType(LGIRGrammarParser::DecimalTypeContext * /*ctx*/) override { }
  virtual void exitDecimalType(LGIRGrammarParser::DecimalTypeContext * /*ctx*/) override { }

  virtual void enterArrayType(LGIRGrammarParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(LGIRGrammarParser::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterVoidType(LGIRGrammarParser::VoidTypeContext * /*ctx*/) override { }
  virtual void exitVoidType(LGIRGrammarParser::VoidTypeContext * /*ctx*/) override { }

  virtual void enterStructureType(LGIRGrammarParser::StructureTypeContext * /*ctx*/) override { }
  virtual void exitStructureType(LGIRGrammarParser::StructureTypeContext * /*ctx*/) override { }

  virtual void enterFunctionReferenceType(LGIRGrammarParser::FunctionReferenceTypeContext * /*ctx*/) override { }
  virtual void exitFunctionReferenceType(LGIRGrammarParser::FunctionReferenceTypeContext * /*ctx*/) override { }

  virtual void enterTypes(LGIRGrammarParser::TypesContext * /*ctx*/) override { }
  virtual void exitTypes(LGIRGrammarParser::TypesContext * /*ctx*/) override { }

  virtual void enterValues(LGIRGrammarParser::ValuesContext * /*ctx*/) override { }
  virtual void exitValues(LGIRGrammarParser::ValuesContext * /*ctx*/) override { }

  virtual void enterValue(LGIRGrammarParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(LGIRGrammarParser::ValueContext * /*ctx*/) override { }

  virtual void enterConstants(LGIRGrammarParser::ConstantsContext * /*ctx*/) override { }
  virtual void exitConstants(LGIRGrammarParser::ConstantsContext * /*ctx*/) override { }

  virtual void enterConstant(LGIRGrammarParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(LGIRGrammarParser::ConstantContext * /*ctx*/) override { }

  virtual void enterIntegerConstant(LGIRGrammarParser::IntegerConstantContext * /*ctx*/) override { }
  virtual void exitIntegerConstant(LGIRGrammarParser::IntegerConstantContext * /*ctx*/) override { }

  virtual void enterDecimalConstant(LGIRGrammarParser::DecimalConstantContext * /*ctx*/) override { }
  virtual void exitDecimalConstant(LGIRGrammarParser::DecimalConstantContext * /*ctx*/) override { }

  virtual void enterArrayConstant(LGIRGrammarParser::ArrayConstantContext * /*ctx*/) override { }
  virtual void exitArrayConstant(LGIRGrammarParser::ArrayConstantContext * /*ctx*/) override { }

  virtual void enterStructureInitializer(LGIRGrammarParser::StructureInitializerContext * /*ctx*/) override { }
  virtual void exitStructureInitializer(LGIRGrammarParser::StructureInitializerContext * /*ctx*/) override { }

  virtual void enterStringConstant(LGIRGrammarParser::StringConstantContext * /*ctx*/) override { }
  virtual void exitStringConstant(LGIRGrammarParser::StringConstantContext * /*ctx*/) override { }

  virtual void enterFunctionReference(LGIRGrammarParser::FunctionReferenceContext * /*ctx*/) override { }
  virtual void exitFunctionReference(LGIRGrammarParser::FunctionReferenceContext * /*ctx*/) override { }

  virtual void enterGlobalReference(LGIRGrammarParser::GlobalReferenceContext * /*ctx*/) override { }
  virtual void exitGlobalReference(LGIRGrammarParser::GlobalReferenceContext * /*ctx*/) override { }

  virtual void enterLocalReference(LGIRGrammarParser::LocalReferenceContext * /*ctx*/) override { }
  virtual void exitLocalReference(LGIRGrammarParser::LocalReferenceContext * /*ctx*/) override { }

  virtual void enterRegister(LGIRGrammarParser::RegisterContext * /*ctx*/) override { }
  virtual void exitRegister(LGIRGrammarParser::RegisterContext * /*ctx*/) override { }

  virtual void enterRegisterName(LGIRGrammarParser::RegisterNameContext * /*ctx*/) override { }
  virtual void exitRegisterName(LGIRGrammarParser::RegisterNameContext * /*ctx*/) override { }

  virtual void enterLabel(LGIRGrammarParser::LabelContext * /*ctx*/) override { }
  virtual void exitLabel(LGIRGrammarParser::LabelContext * /*ctx*/) override { }

  virtual void enterCondition(LGIRGrammarParser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(LGIRGrammarParser::ConditionContext * /*ctx*/) override { }

  virtual void enterUnaryOperator(LGIRGrammarParser::UnaryOperatorContext * /*ctx*/) override { }
  virtual void exitUnaryOperator(LGIRGrammarParser::UnaryOperatorContext * /*ctx*/) override { }

  virtual void enterBinaryOperator(LGIRGrammarParser::BinaryOperatorContext * /*ctx*/) override { }
  virtual void exitBinaryOperator(LGIRGrammarParser::BinaryOperatorContext * /*ctx*/) override { }

  virtual void enterTypeCastKind(LGIRGrammarParser::TypeCastKindContext * /*ctx*/) override { }
  virtual void exitTypeCastKind(LGIRGrammarParser::TypeCastKindContext * /*ctx*/) override { }

  virtual void enterAttribute(LGIRGrammarParser::AttributeContext * /*ctx*/) override { }
  virtual void exitAttribute(LGIRGrammarParser::AttributeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

