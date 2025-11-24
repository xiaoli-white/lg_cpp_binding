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

    void IRBuilder::createReturn()
    {
        insertPoint->addInstruction(new instruction::IRReturn());
    }

    void IRBuilder::createReturn(value::IRValue* value)
    {
        insertPoint->addInstruction(new instruction::IRReturn(value));
    }

    void IRBuilder::createGoto(base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(new instruction::IRGoto(target));
    }

    void IRBuilder::createNop()
    {
        insertPoint->addInstruction(new instruction::IRNop());
    }

    value::IRRegister* IRBuilder::createLoad(value::IRValue* ptr)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRLoad(ptr, reg));
        return reg;
    }

    void IRBuilder::createStore(value::IRValue* ptr, value::IRValue* value)
    {
        insertPoint->addInstruction(new instruction::IRStore(ptr, value));
    }

    void IRBuilder::createJumpIfTrue(value::IRValue* operand, base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(new instruction::IRConditionalJump(base::IRCondition::IF_TRUE, operand, target));
    }

    void IRBuilder::createJumpIfFalse(value::IRValue* operand, base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(new instruction::IRConditionalJump(base::IRCondition::IF_FALSE, operand, target));
    }

    void IRBuilder::createJumpIfEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::E, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfNotEqual(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::NE, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfLess(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::L, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfLessEqual(value::IRValue* operand1, value::IRValue* operand2,
                                          base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::LE, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfGreater(value::IRValue* operand1, value::IRValue* operand2, base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::G, operand1, operand2, target));
    }

    void IRBuilder::createJumpIfGreaterEqual(value::IRValue* operand1, value::IRValue* operand2,
                                             base::IRBasicBlock* target)
    {
        insertPoint->addInstruction(
            new instruction::IRConditionalJump(base::IRCondition::GE, operand1, operand2, target));
    }

    value::IRRegister* IRBuilder::createCmpEqual(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::E, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createCmpNotEqual(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::NE, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createCmpLess(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::L, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createCmpLessEqual(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::LE, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createCmpGreater(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::G, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createCmpGreaterEqual(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRCompare(base::IRCondition::GE, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createAdd(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::ADD, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createSub(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::SUB, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createMul(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::MUL, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createDiv(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::DIV, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createMod(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::MOD, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createAnd(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::AND, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createOr(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::OR, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createXor(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::XOR, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createShl(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::SHL, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createShr(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::SHR, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createUShr(value::IRValue* operand1, value::IRValue* operand2)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRBinaryOperates(instruction::IRBinaryOperates::Operator::USHR, operand1, operand2, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createInc(value::IRValue* operand)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::INC, operand, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createDec(value::IRValue* operand)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::DEC, operand, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createNot(value::IRValue* operand)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::NOT, operand, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createNeg(value::IRValue* operand)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRUnaryOperates(instruction::IRUnaryOperates::Operator::NEG, operand, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createStackAlloc(value::IRValue* size)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRStackAllocate(size, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createSetRegister(value::IRValue* value)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRSetRegister(value, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createZeroExtend(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::ZEXT, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createSignExtend(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::SEXT, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createTrunc(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::TRUNC, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createIntToFloat(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::ITOF, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createFloatToInt(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::FTOI, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createIntToPointer(value::IRValue* source, type::IRPointerType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::ITOP, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createPointerToInt(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::PTOI, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createPointerToPointer(value::IRValue* source, type::IRPointerType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::PTOP, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createFloatExtend(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::FEXT, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createFloatTrunc(value::IRValue* source, type::IRType* targetType)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(
            new instruction::IRTypeCast(instruction::IRTypeCast::Kind::FTRUNC, source, targetType, reg));
        return reg;
    }

    value::IRRegister* IRBuilder::createInvoke(function::IRFunction* function, std::vector<value::IRValue*> args)
    {
        return createInvoke(function->returnType, new value::IRFunctionReference(function), std::move(args));
    }

    value::IRRegister* IRBuilder::createInvoke(type::IRType* returnType, value::IRValue* func,
                                               std::vector<value::IRValue*> args)
    {
        const auto reg = ((dynamic_cast<type::IRVoidType*>(returnType) == nullptr)
                              ? new value::IRRegister(allocateRegisterName())
                              : nullptr);
        insertPoint->addInstruction(new instruction::IRInvoke(returnType, func, std::move(args), reg));
        return reg;
    }
    value::IRRegister* IRBuilder::createGetElementPointer(value::IRValue* ptr, std::vector<value::constant::IRIntegerConstant*> indices)
    {
        const auto reg = new value::IRRegister(allocateRegisterName());
        insertPoint->addInstruction(new instruction::IRGetElementPointer(ptr, std::move(indices), reg));
        return reg;
    }
    void IRBuilder::createAsm(std::string assembly, std::string constraints, std::vector<value::IRValue*> args)
    {
        insertPoint->addInstruction(new instruction::IRAssembly(std::move(assembly), std::move(constraints), std::move(args)));
    }
    std::string IRBuilder::allocateRegisterName() const
    {
        if (insertPoint->cfg == nullptr) throw std::runtime_error("Cannot allocate register name in IRBuilder: no CFG");
        if (insertPoint->cfg->function == nullptr) throw std::runtime_error("Cannot allocate register name in IRBuilder: no function");
        return std::to_string(insertPoint->cfg->function->registerCount++);
    }

}
