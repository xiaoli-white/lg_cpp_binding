
// Generated from LGIRGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "lexer/LGIRGrammarVisitor.h"


/**
 * This class provides an empty implementation of LGIRGrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LGIRGrammarBaseVisitor : public LGIRGrammarVisitor {
public:
  virtual ~LGIRGrammarBaseVisitor() = default;

  virtual std::any visitProgram(LGIRGrammarParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalVariable(LGIRGrammarParser::GlobalVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure(LGIRGrammarParser::StructureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFields(LGIRGrammarParser::FieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitField(LGIRGrammarParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(LGIRGrammarParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(LGIRGrammarParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStack_alloc(LGIRGrammarParser::Stack_allocContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoad(LGIRGrammarParser::LoadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStore(LGIRGrammarParser::StoreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsm(LGIRGrammarParser::AsmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGoto(LGIRGrammarParser::GotoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvoke(LGIRGrammarParser::InvokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(LGIRGrammarParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetRegister(LGIRGrammarParser::SetRegisterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGetElementPointer(LGIRGrammarParser::GetElementPointerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCmp(LGIRGrammarParser::CmpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditionalJump(LGIRGrammarParser::ConditionalJumpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOperates(LGIRGrammarParser::UnaryOperatesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryOperates(LGIRGrammarParser::BinaryOperatesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeCast(LGIRGrammarParser::TypeCastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(LGIRGrammarParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBaseType(LGIRGrammarParser::BaseTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerType(LGIRGrammarParser::IntegerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimalType(LGIRGrammarParser::DecimalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(LGIRGrammarParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVoidType(LGIRGrammarParser::VoidTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructureType(LGIRGrammarParser::StructureTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValues(LGIRGrammarParser::ValuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue(LGIRGrammarParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(LGIRGrammarParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerConstant(LGIRGrammarParser::IntegerConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimalConstant(LGIRGrammarParser::DecimalConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayConstant(LGIRGrammarParser::ArrayConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionReference(LGIRGrammarParser::FunctionReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalReference(LGIRGrammarParser::GlobalReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocalReference(LGIRGrammarParser::LocalReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRegister(LGIRGrammarParser::RegisterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRegisterName(LGIRGrammarParser::RegisterNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabel(LGIRGrammarParser::LabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition(LGIRGrammarParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOperator(LGIRGrammarParser::UnaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryOperator(LGIRGrammarParser::BinaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeCastKind(LGIRGrammarParser::TypeCastKindContext *ctx) override {
    return visitChildren(ctx);
  }


};

