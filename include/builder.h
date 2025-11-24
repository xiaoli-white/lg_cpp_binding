//
// Created by xiaoli on 2025/11/24.
//

#pragma once
#ifndef LG_CPP_BINDING_BUILDER_H
#define LG_CPP_BINDING_BUILDER_H

#include <ir.h>

namespace lg::ir
{
    class IRBuilder
    {
    private:
        base::IRBasicBlock* insertPoint = nullptr;

    public:
        IRBuilder() = default;
        void setInsertPoint(base::IRBasicBlock* insertPoint);
        void createReturn();
        void createReturn(value::IRValue* value);
        void createGoto(base::IRBasicBlock* target);
        void createNop();
        value::IRRegister* createLoad(value::IRValue* ptr);
        void createStore(value::IRValue* ptr, value::IRValue* value);
        void createJumpIfTrue(value::IRValue* operand, base::IRBasicBlock* target);
        void createJumpIfFalse(value::IRValue* operand, base::IRBasicBlock* target);
        void createJumpIfEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target);
        void createJumpIfNotEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target);
        void createJumpIfLess(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target);
        void createJumpIfLessEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target);
        void createJumpIfGreater(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target);
        void createJumpIfGreaterEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target);
        value::IRRegister* createCmpEqual(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createCmpNotEqual(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createCmpLess(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createCmpLessEqual(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createCmpGreater(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createCmpGreaterEqual(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createAdd(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createSub(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createMul(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createDiv(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createMod(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createAnd(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createOr(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createXor(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createShl(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createShr(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createUShr(value::IRValue* operand1, value::IRValue* operand2);
        value::IRRegister* createInc(value::IRValue* operand);
        value::IRRegister* createDec(value::IRValue* operand);
        value::IRRegister* createNot(value::IRValue* operand);
        value::IRRegister* createNeg(value::IRValue* operand);
        value::IRRegister* createStackAlloc(value::IRValue* size);
        value::IRRegister* createSetRegister(value::IRValue* value);
        value::IRRegister* createZeroExtend(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createSignExtend(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createTrunc(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createIntToFloat(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createFloatToInt(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createIntToPointer(value::IRValue* source, type::IRPointerType* targetType);
        value::IRRegister* createPointerToInt(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createPointerToPointer(value::IRValue* source, type::IRPointerType* targetType);
        value::IRRegister* createFloatExtend(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createFloatTrunc(value::IRValue* source, type::IRType* targetType);
        value::IRRegister* createInvoke(function::IRFunction* function, std::vector<value::IRValue*> args);
        value::IRRegister* createInvoke(type::IRType* returnType, value::IRValue* func,
                                        std::vector<value::IRValue*> args);
        value::IRRegister* createGetElementPointer(value::IRValue* ptr,
                                                   std::vector<value::constant::IRIntegerConstant*> indices);
        void createAsm(std::string assembly, std::string constraints, std::vector<value::IRValue*> args);

    private:
        [[nodiscard]] std::string allocateRegisterName() const;
    };
}

#endif //LG_CPP_BINDING_BUILDER_H
