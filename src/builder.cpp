//
// Created by xiaoli on 2025/11/24.
//
#include <builder.h>
#include <stdexcept>

#include <utility>

namespace lg::ir
{
    void IRBuilder::setInsertPoint(base::IRBasicBlock* insertPoint)
    {
        this->insertPoint = insertPoint;
    }

    base::IRBasicBlock* IRBuilder::getInsertPoint() const
    {
        return insertPoint;
    }

    void IRBuilder::createReturn() const
    {
        insertPoint->addInstruction(new instruction::IRReturn());
    }

    void IRBuilder::createReturn(value::IRValue* value) const
    {
        insertPoint->addInstruction(new instruction::IRReturn(value));
    }

    void IRBuilder::createGoto(base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(new instruction::IRGoto(target));
    }

    void IRBuilder::createNop() const
    {
        insertPoint->addInstruction(new instruction::IRNop());
    }

    value::IRRegister* IRBuilder::createLoad(value::IRValue* ptr, const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRLoad(ptr, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createLoad(value::IRValue* ptr) const
    {
        return createLoad(ptr, allocateRegisterName());
    }

    void IRBuilder::createStore(value::IRValue* ptr, value::IRValue* value) const
    {
        insertPoint->addInstruction(new instruction::IRStore(ptr, value));
    }

    void IRBuilder::createJumpIfTrue(value::IRValue* operand, base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(new instruction::IRConditionalJump(base::IRCondition::IF_TRUE, operand, target));
    }

    void IRBuilder::createJumpIfFalse(value::IRValue* operand, base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(new instruction::IRConditionalJump(base::IRCondition::IF_FALSE, operand, target));
    }

    void IRBuilder::createJumpIfEqual(value::IRValue* operand1, value::IRValue* operand2,
                                      base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::E, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfNotEqual(value::IRValue* operand1, value::IRValue* operand2,
                                         base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::NE, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfLess(value::IRValue* operand1, value::IRValue* operand2,
                                     base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::L, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfLessEqual(value::IRValue* operand1, value::IRValue* operand2,
                                          base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::LE, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfGreater(value::IRValue* operand1, value::IRValue* operand2,
                                        base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::G, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfGreaterEqual(value::IRValue* operand1, value::IRValue* operand2,
                                             base::IRBasicBlock* target) const
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::GE, operand1, operand2, target));
    }

    value::IRRegister* IRBuilder::createCmpEqual(value::IRValue* operand1, value::IRValue* operand2,
                                                 const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::E, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createCmpEqual(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createCmpEqual(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createCmpNotEqual(value::IRValue* operand1, value::IRValue* operand2,
                                                    const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::NE, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createCmpNotEqual(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createCmpNotEqual(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createCmpLess(value::IRValue* operand1, value::IRValue* operand2,
                                                const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::L, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createCmpLess(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createCmpLess(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createCmpLessEqual(value::IRValue* operand1, value::IRValue* operand2,
                                                     const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::LE, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createCmpLessEqual(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createCmpLessEqual(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createCmpGreater(value::IRValue* operand1, value::IRValue* operand2,
                                                   const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::G, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createCmpGreater(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createCmpGreater(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createCmpGreaterEqual(value::IRValue* operand1, value::IRValue* operand2,
                                                        const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::GE, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createCmpGreaterEqual(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createCmpGreaterEqual(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createAdd(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::ADD, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createAdd(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createAdd(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createSub(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::SUB, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createSub(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createSub(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createMul(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::MUL, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createMul(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createMul(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createDiv(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::DIV, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createDiv(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createDiv(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createMod(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::MOD, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createMod(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createMod(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createAnd(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::AND, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createAnd(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createAnd(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createOr(value::IRValue* operand1, value::IRValue* operand2,
                                           const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::OR, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createOr(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createOr(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createXor(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::XOR, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createXor(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createXor(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createShl(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::SHL, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createShl(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createShl(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createShr(value::IRValue* operand1, value::IRValue* operand2,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::SHR, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createShr(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createShr(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createUShr(value::IRValue* operand1, value::IRValue* operand2,
                                             const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::USHR, operand1, operand2, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createUShr(value::IRValue* operand1, value::IRValue* operand2) const
    {
        return createUShr(operand1, operand2, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createInc(value::IRValue* operand, const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::INC, operand, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createInc(value::IRValue* operand) const
    {
        return createInc(operand, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createDec(value::IRValue* operand, const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::DEC, operand, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createDec(value::IRValue* operand) const
    {
        return createDec(operand, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createNot(value::IRValue* operand, const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::NOT, operand, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createNot(value::IRValue* operand) const
    {
        return createNot(operand, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createNeg(value::IRValue* operand, const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::NEG, operand, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createNeg(value::IRValue* operand) const
    {
        return createNeg(operand, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createStackAlloc(type::IRType* type, value::IRValue* size,
                                                   const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRStackAllocate(type, size, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createStackAlloc(type::IRType* type, value::IRValue* size) const
    {
        return createStackAlloc(type, size, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createStackAlloc(type::IRType* type, const std::string& targetName) const
    {
        return createStackAlloc(type, nullptr, targetName);
    }

    value::IRRegister* IRBuilder::createStackAlloc(type::IRType* type) const
    {
        return createStackAlloc(type, allocateRegisterName());
    }


    value::IRRegister* IRBuilder::createSetRegister(value::IRValue* value, const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRSetRegister(value, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createSetRegister(value::IRValue* value) const
    {
        return createSetRegister(value, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createZeroExtend(value::IRValue* source, type::IRType* targetType,
                                                   const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::ZEXT, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createZeroExtend(value::IRValue* source, type::IRType* targetType) const
    {
        return createZeroExtend(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createSignExtend(value::IRValue* source, type::IRType* targetType,
                                                   const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::SEXT, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createSignExtend(value::IRValue* source, type::IRType* targetType) const
    {
        return createSignExtend(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createTrunc(value::IRValue* source, type::IRType* targetType,
                                              const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::TRUNC, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createTrunc(value::IRValue* source, type::IRType* targetType) const
    {
        return createTrunc(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createIntToFloat(value::IRValue* source, type::IRType* targetType,
                                                   const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::INTTOF, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createIntToFloat(value::IRValue* source, type::IRType* targetType) const
    {
        return createIntToFloat(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createFloatToInt(value::IRValue* source, type::IRType* targetType,
                                                   const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::FTOINT, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createFloatToInt(value::IRValue* source, type::IRType* targetType) const
    {
        return createFloatToInt(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createIntToPointer(value::IRValue* source, type::IRPointerType* targetType,
                                                     const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::INTTOPTR, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createIntToPointer(value::IRValue* source, type::IRPointerType* targetType) const
    {
        return createIntToPointer(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createPointerToInt(value::IRValue* source, type::IRType* targetType,
                                                     const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::PTRTOINT, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createPointerToInt(value::IRValue* source, type::IRType* targetType) const
    {
        return createPointerToInt(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createPointerToPointer(value::IRValue* source, type::IRPointerType* targetType,
                                                         const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::PTRTOPTR, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createPointerToPointer(value::IRValue* source, type::IRPointerType* targetType) const
    {
        return createPointerToPointer(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createFloatExtend(value::IRValue* source, type::IRType* targetType,
                                                    const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::FEXT, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createFloatExtend(value::IRValue* source, type::IRType* targetType) const
    {
        return createFloatExtend(source, targetType, allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createFloatTrunc(value::IRValue* source, type::IRType* targetType,
                                                   const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::FTRUNC, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createFloatTrunc(value::IRValue* source, type::IRType* targetType) const
    {
        return createFloatTrunc(source, targetType, allocateRegisterName());
    }
    value::IRRegister* IRBuilder::createBitCast(value::IRValue* source, type::IRType* targetType,
                                                       const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::BITCAST, source, targetType, reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createBitCast(value::IRValue* source, type::IRType* targetType) const
    {
        return createBitCast(source, targetType, allocateRegisterName());
    }
    value::IRRegister* IRBuilder::createInvoke(function::IRFunction* function, std::vector<value::IRValue*> args,
                                               const std::string& targetName) const
    {
        return createInvoke(function->returnType, new value::constant::IRFunctionReference(function), std::move(args),
                            targetName);
    }


    value::IRRegister* IRBuilder::createInvoke(function::IRFunction* function, std::vector<value::IRValue*> args) const
    {
        auto* returnType = function->returnType;
        const auto reg = ((dynamic_cast<type::IRVoidType*>(returnType) == nullptr)
                              ? new value::IRRegister(allocateRegisterName())
                              : nullptr);
        insertPoint->addInstruction(
            new instruction::IRInvoke(returnType, new value::constant::IRFunctionReference(function), std::move(args),
                                      reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createInvoke(type::IRType* returnType, value::IRValue* func,
                                               std::vector<value::IRValue*> args, const std::string& targetName) const
    {
        const auto reg = ((dynamic_cast<type::IRVoidType*>(returnType) == nullptr)
                              ? new value::IRRegister(targetName)
                              : nullptr);
        insertPoint->addInstruction(new instruction::IRInvoke(returnType, func, std::move(args), reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createInvoke(type::IRType* returnType, value::IRValue* func,
                                               std::vector<value::IRValue*> args) const
    {
        return createInvoke(returnType, func, std::move(args), allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createGetElementPointer(value::IRValue* ptr,
                                                          std::vector<value::constant::IRIntegerConstant*> indices,
                                                          const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRGetElementPointer(ptr, std::move(indices), reg));
        return reg;
    }


    value::IRRegister* IRBuilder::createGetElementPointer(value::IRValue* ptr,
                                                          std::vector<value::constant::IRIntegerConstant*> indices)
    const
    {
        return createGetElementPointer(ptr, std::move(indices), allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createPhi(std::unordered_map<base::IRBasicBlock*, value::IRValue*> values) const
    {
        return createPhi(std::move(values), allocateRegisterName());
    }

    value::IRRegister* IRBuilder::createPhi(std::unordered_map<base::IRBasicBlock*, value::IRValue*> values,
                                            const std::string& targetName) const
    {
        const auto reg = new value::IRRegister(targetName);
        insertPoint->addInstruction(new instruction::IRPhi(std::move(values), reg));
        return reg;
    }

    void IRBuilder::createSwitch(value::IRValue* value, base::IRBasicBlock* defaultCase,
                                 std::unordered_map<value::constant::IRIntegerConstant*, base::IRBasicBlock*> cases)
    const
    {
        insertPoint->addInstruction(new instruction::IRSwitch(value, defaultCase, std::move(cases)));
    }

    void IRBuilder::createAsm(std::string assembly, std::string constraints, std::vector<value::IRValue*> args) const
    {
        insertPoint->addInstruction(
            new instruction::IRAssembly(std::move(assembly), std::move(constraints), std::move(args)));
    }

    std::string IRBuilder::allocateRegisterName() const
    {
        if (insertPoint->cfg == nullptr) throw std::runtime_error("Cannot allocate register name in IRBuilder: no CFG");
        if (insertPoint->cfg->function == nullptr)
            throw std::runtime_error(
                "Cannot allocate register name in IRBuilder: no function");
        return std::to_string(insertPoint->cfg->function->registerCount++);
    }
}
