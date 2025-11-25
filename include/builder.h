//
// Created by xiaoli on 2025/11/24.
//

#pragma once
#ifndef LG_CPP_BINDING_BUILDER_H
#define LG_CPP_BINDING_BUILDER_H

#include <ir.h>

namespace lg::ir
{
    class IRBuilder;

    class IRBuilder
    {
    private:
        base::IRBasicBlock* insertPoint = nullptr;

    public:
        IRBuilder() = default;
        void setInsertPoint(base::IRBasicBlock* insertPoint);
        void createReturn() const;
        void createReturn(value::IRValue* value) const;
        void createGoto(base::IRBasicBlock* target) const;
        void createNop() const;
        value::IRRegister* createLoad(value::IRValue* ptr, const std::string& targetName) const;
        value::IRRegister* createLoad(value::IRValue* ptr) const;
        void createStore(value::IRValue* ptr, value::IRValue* value) const;
        void createJumpIfTrue(value::IRValue* operand, base::IRBasicBlock* target) const;
        void createJumpIfFalse(value::IRValue* operand, base::IRBasicBlock* target) const;
        void createJumpIfEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target) const;
        void createJumpIfNotEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target) const;
        void createJumpIfLess(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target) const;
        void createJumpIfLessEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target) const;
        void createJumpIfGreater(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target) const;
        void createJumpIfGreaterEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target) const;
        value::IRRegister* createCmpEqual(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createCmpEqual(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createCmpNotEqual(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createCmpNotEqual(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createCmpLess(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createCmpLess(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createCmpLessEqual(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createCmpLessEqual(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createCmpGreater(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createCmpGreater(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createCmpGreaterEqual(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createCmpGreaterEqual(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createAdd(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createAdd(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createSub(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createSub(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createMul(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createMul(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createDiv(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createDiv(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createMod(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createMod(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createAnd(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createAnd(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createOr(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createOr(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createXor(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createXor(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createShl(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createShl(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createShr(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createShr(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createUShr(value::IRValue* operand1, value::IRValue* operand2, const std::string& targetName) const;
        value::IRRegister* createUShr(value::IRValue* operand1, value::IRValue* operand2) const;
        value::IRRegister* createInc(value::IRValue* operand, const std::string& targetName) const;
        value::IRRegister* createInc(value::IRValue* operand) const;
        value::IRRegister* createDec(value::IRValue* operand, const std::string& targetName) const;
        value::IRRegister* createDec(value::IRValue* operand) const;
        value::IRRegister* createNot(value::IRValue* operand, const std::string& targetName) const;
        value::IRRegister* createNot(value::IRValue* operand) const;
        value::IRRegister* createNeg(value::IRValue* operand, const std::string& targetName) const;
        value::IRRegister* createNeg(value::IRValue* operand) const;
        value::IRRegister* createStackAlloc(value::IRValue* size, const std::string& targetName) const;
        value::IRRegister* createStackAlloc(value::IRValue* size) const;
        value::IRRegister* createSetRegister(value::IRValue* value, const std::string& targetName) const;
        value::IRRegister* createSetRegister(value::IRValue* value) const;
        value::IRRegister* createZeroExtend(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createZeroExtend(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createSignExtend(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createSignExtend(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createTrunc(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createTrunc(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createIntToFloat(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createIntToFloat(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createFloatToInt(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createFloatToInt(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createIntToPointer(value::IRValue* source, type::IRPointerType* targetType, const std::string& targetName) const;
        value::IRRegister* createIntToPointer(value::IRValue* source, type::IRPointerType* targetType) const;
        value::IRRegister* createPointerToInt(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createPointerToInt(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createPointerToPointer(value::IRValue* source, type::IRPointerType* targetType, const std::string& targetName) const;
        value::IRRegister* createPointerToPointer(value::IRValue* source, type::IRPointerType* targetType) const;
        value::IRRegister* createFloatExtend(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createFloatExtend(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createFloatTrunc(value::IRValue* source, type::IRType* targetType, const std::string& targetName) const;
        value::IRRegister* createFloatTrunc(value::IRValue* source, type::IRType* targetType) const;
        value::IRRegister* createInvoke(function::IRFunction* function, std::vector<value::IRValue*> args, const std::string& targetName) const;
        value::IRRegister* createInvoke(function::IRFunction* function, std::vector<value::IRValue*> args) const;
        value::IRRegister* createInvoke(type::IRType* returnType, value::IRValue* func,
                                        std::vector<value::IRValue*> args, const std::string& targetName) const;
        value::IRRegister* createInvoke(type::IRType* returnType, value::IRValue* func,
                                        std::vector<value::IRValue*> args) const;
        value::IRRegister* createGetElementPointer(value::IRValue* ptr,
                                                   std::vector<value::constant::IRIntegerConstant*> indices, const std::string& targetName) const;
        value::IRRegister* createGetElementPointer(value::IRValue* ptr,
                                                   std::vector<value::constant::IRIntegerConstant*> indices) const;
        void createAsm(std::string assembly, std::string constraints, std::vector<value::IRValue*> args) const;

    private:
        [[nodiscard]] std::string allocateRegisterName() const;
    };
}

#endif //LG_CPP_BINDING_BUILDER_H
