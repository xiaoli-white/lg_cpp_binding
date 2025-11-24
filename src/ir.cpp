#include <ir.h>
#include <ranges>

#include <utility>

namespace lg::ir
{
    namespace base
    {
        IRGlobalVariable::IRGlobalVariable(type::IRType* type, std::string name,
                                           value::constant::IRConstant* initializer) : type(type),
            name(std::move(name)), initializer(initializer)
        {
        }

        std::any IRGlobalVariable::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitGlobalVariable(this, std::move(additional));
        }

        std::string IRGlobalVariable::toString()
        {
            return name + " = " + initializer->toString();
        }

        std::string IRControlFlowGraph::toString()
        {
            return "";
        }

        IRBasicBlock::IRBasicBlock(std::string name) : name(std::move(name))
        {
        }

        std::string IRBasicBlock::toString()
        {
            return "";
        }

        void IRBasicBlock::addInstruction(instruction::IRInstruction* instruction)
        {
            instructions.push_back(instruction);
        }

        std::string conditionToString(IRCondition condition)
        {
            switch (condition)
            {
            case IRCondition::E:
                return "e";
            case IRCondition::NE:
                return "ne";
            case IRCondition::L:
                return "l";
            case IRCondition::LE:
                return "le";
            case IRCondition::G:
                return "g";
            case IRCondition::GE:
                return "ge";
            case IRCondition::IF_TRUE:
                return "if_true";
            case IRCondition::IF_FALSE:
                return "if_false";
            default:
                return "unknown";
            }
        }
    }

    namespace type
    {
        IRIntegerType::IRIntegerType(Size size, bool _unsigned) : size(size), _unsigned(_unsigned)
        {
        }

        std::any IRIntegerType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitIntegerType(this, std::move(additional));
        }

        std::string IRIntegerType::toString()
        {
            return (_unsigned ? "u" : "i") + std::to_string(static_cast<uint8_t>(size));
        }

        IRIntegerType* IRIntegerType::getUnsignedInt8Type()
        {
            static IRIntegerType instance(Size::OneByte, true);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getInt8Type()
        {
            static IRIntegerType instance(Size::OneByte, false);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getUnsignedInt16Type()
        {
            static IRIntegerType instance(Size::TwoBytes, true);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getInt16Type()
        {
            static IRIntegerType instance(Size::TwoBytes, false);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getUnsignedInt32Type()
        {
            static IRIntegerType instance(Size::FourBytes, true);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getInt32Type()
        {
            static IRIntegerType instance(Size::FourBytes, false);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getUnsignedInt64Type()
        {
            static IRIntegerType instance(Size::EightBytes, true);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getInt64Type()
        {
            static IRIntegerType instance(Size::EightBytes, false);
            return &instance;
        }

        IRIntegerType* IRIntegerType::getCharType()
        {
            return getUnsignedInt32Type();
        }

        IRIntegerType* IRIntegerType::getBooleanType()
        {
            static IRIntegerType instance(Size::OneBit, false);
            return &instance;
        }

        std::any IRFloatType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitFloatType(this, std::move(additional));
        }

        std::string IRFloatType::toString() { return "float"; }

        IRFloatType* IRFloatType::get()
        {
            static IRFloatType instance;
            return &instance;
        }

        std::any IRDoubleType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitDoubleType(this, std::move(additional));
        }

        std::string IRDoubleType::toString() { return "double"; }

        IRDoubleType* IRDoubleType::get()
        {
            static IRDoubleType instance;
            return &instance;
        }

        IRStructureType::IRStructureType(structure::IRStructure* structure) : structure(structure)
        {
        }

        std::any IRStructureType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitStructureType(this, std::move(additional));
        }

        std::string IRStructureType::toString()
        {
            return "structure " + structure->name;
        }

        IRStructureType* IRStructureType::get(structure::IRStructure* structure)
        {
            return new IRStructureType(structure);
        }

        IRArrayType::IRArrayType(IRType* base, uint64_t size) : base(base), size(size)
        {
        }

        std::any IRArrayType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitArrayType(this, std::move(additional));
        }

        std::string IRArrayType::toString()
        {
            return "[" + std::to_string(size) + " x " + base->toString() + "]";
        }

        IRArrayType* IRArrayType::get(IRType* base, uint64_t size)
        {
            return new IRArrayType(base, size);
        }

        IRPointerType::IRPointerType(IRType* base) : base(base)
        {
        }

        std::any IRPointerType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitPointerType(this, std::move(additional));
        }

        std::string IRPointerType::toString()
        {
            return base->toString() + "*";
        }

        IRPointerType* IRPointerType::get(IRType* base)
        {
            return new IRPointerType(base);
        }


        std::any IRVoidType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitVoidType(this, std::move(additional));
        }

        std::string IRVoidType::toString()
        {
            return "void";
        }

        IRVoidType* IRVoidType::get()
        {
            static IRVoidType instance;
            return &instance;
        }
    }

    namespace value
    {
        IRRegister::IRRegister(std::string name) : name(std::move(name))
        {
        }

        type::IRType* IRRegister::getType()
        {
            return type;
        }

        std::any IRRegister::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitRegister(this, std::move(additional));
        }

        std::string IRRegister::toString()
        {
            return type->toString() + " %" + name;
        }

        IRFunctionReference::IRFunctionReference(function::IRFunction* function) : function(function)
        {
        }

        type::IRType* IRFunctionReference::getType()
        {
            return function->returnType;
        }

        std::any IRFunctionReference::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitFunctionReference(this, std::move(additional));
        }

        std::string IRFunctionReference::toString()
        {
            return "funcref " + function->name;
        }

        IRGlobalVariableReference::IRGlobalVariableReference(base::IRGlobalVariable* variable) : variable(variable)
        {
            type = type::IRPointerType::get(variable->type);
        }

        type::IRType* IRGlobalVariableReference::getType()
        {
            return type;
        }

        std::any IRGlobalVariableReference::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitGlobalVariableReference(this, std::move(additional));
        }

        std::string IRGlobalVariableReference::toString()
        {
            return "globalref " + variable->name;
        }

        IRLocalVariableReference::IRLocalVariableReference(function::IRLocalVariable* variable) : variable(variable)
        {
            type = type::IRPointerType::get(variable->type);
        }

        type::IRType* IRLocalVariableReference::getType()
        {
            return type;
        }

        std::any IRLocalVariableReference::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitLocalVariableReference(this, std::move(additional));
        }

        std::string IRLocalVariableReference::toString()
        {
            return "localref " + variable->name;
        }

        namespace constant
        {
            IRIntegerConstant::IRIntegerConstant(type::IRIntegerType* type, uint64_t value) : type(type), value(value)
            {
            }

            type::IRType* IRIntegerConstant::getType()
            {
                return type;
            }

            std::any IRIntegerConstant::accept(IRVisitor* visitor, std::any additional)
            {
                return visitor->visitIntegerConstant(this, std::move(additional));
            }

            std::string IRIntegerConstant::toString()
            {
                return type->toString() + " " + std::to_string(value);
            }

            IRFloatConstant::IRFloatConstant(float value) : value(value)
            {
            }

            type::IRType* IRFloatConstant::getType()
            {
                return type::IRFloatType::get();
            }

            std::any IRFloatConstant::accept(IRVisitor* visitor, std::any additional)
            {
                return visitor->visitFloatConstant(this, std::move(additional));
            }

            std::string IRFloatConstant::toString()
            {
                return "float " + std::to_string(value);
            }

            IRDoubleConstant::IRDoubleConstant(double value) : value(value)
            {
            }

            type::IRType* IRDoubleConstant::getType()
            {
                return type::IRDoubleType::get();
            }

            std::any IRDoubleConstant::accept(IRVisitor* visitor, std::any additional)
            {
                return visitor->visitDoubleConstant(this, std::move(additional));
            }

            std::string IRDoubleConstant::toString()
            {
                return "double " + std::to_string(value);
            }

            IRArrayConstant::IRArrayConstant(type::IRArrayType* type,
                                             std::vector<IRConstant*> values) : type(type), elements(std::move(values))
            {
            }

            type::IRType* IRArrayConstant::getType()
            {
                return type;
            }

            std::any IRArrayConstant::accept(IRVisitor* visitor, std::any additional)
            {
                return visitor->visitArrayConstant(this, std::move(additional));
            }

            std::string IRArrayConstant::toString()
            {
                std::string result = type->toString() + " [";
                for (int i = 0; i < elements.size(); i++)
                {
                    result += elements[i]->toString();
                    if (i < elements.size() - 1)result += ", ";
                }
                result += "]";
                return result;
            }

            IRStringConstant::IRStringConstant(std::string value) : value(std::move(value))
            {
                type = type::IRPointerType::get(type::IRIntegerType::getUnsignedInt32Type());
            }

            type::IRType* IRStringConstant::getType()
            {
                return type;
            }

            std::any IRStringConstant::accept(IRVisitor* visitor, std::any additional)
            {
                return visitor->visitStringConstant(this, std::move(additional));
            }

            std::string IRStringConstant::toString()
            {
                return "string \"" + value + "\"";
            }

            IRNullptrConstant::IRNullptrConstant(type::IRPointerType* type) : type(type)
            {
            }

            type::IRType* IRNullptrConstant::getType()
            {
                return type;
            }

            std::any IRNullptrConstant::accept(IRVisitor* visitor, std::any additional)
            {
                return visitor->visitNullptrConstant(this, std::move(additional));
            }

            std::string IRNullptrConstant::toString()
            {
                return type->toString() + " nullptr";
            }
        }
    }

    namespace function
    {
        IRFunction::IRFunction(std::vector<std::string> attributes, type::IRType* returnType, std::string name,
                               std::vector<IRLocalVariable*> args, std::vector<IRLocalVariable*> locals,
                               base::IRControlFlowGraph* cfg) : attributes(std::move(attributes)),
                                                                returnType(returnType), name(std::move(name)),
                                                                args(std::move(args)), locals(std::move(locals)),
                                                                cfg(cfg)
        {
            if (cfg != nullptr) cfg->function = this;
        }

        std::any IRFunction::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitFunction(this, std::move(additional));
        }

        std::string IRFunction::toString()
        {
            return "";
        }

        IRLocalVariable::IRLocalVariable(type::IRType* type, std::string name) : type(type), name(std::move(name))
        {
        }

        std::any IRLocalVariable::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitLocalVariable(this, std::move(additional));
        }

        std::string IRLocalVariable::toString()
        {
            return name + " " + type->toString();
        }
    }

    namespace structure
    {
        IRStructure::IRStructure(std::vector<std::string> attributes, std::string name, std::vector<IRField*> fields) :
            attributes(std::move(attributes)), name(std::move(name)), fields(std::move(fields))
        {
        }

        std::any IRStructure::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitStructure(this, std::move(additional));
        }

        std::string IRStructure::toString()
        {
            return "structure";
        }

        IRField::IRField(type::IRType* type, std::string name) : type(type), name(std::move(name))
        {
        }

        std::any IRField::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitField(this, std::move(additional));
        }

        std::string IRField::toString()
        {
            return type->toString() + " " + name;
        }
    }

    namespace instruction
    {
        IRAssembly::IRAssembly(std::string assembly, std::string constraints, std::vector<value::IRValue*> operands) :
            assembly(std::move(assembly)), constraints(std::move(constraints)), operands(std::move(operands))
        {
        }

        std::any IRAssembly::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitAssembly(this, std::move(additional));
        }

        std::string IRAssembly::toString()
        {
            std::string result = "asm \"" + assembly + "\", \"" + constraints + "\"(";
            for (int i = 0; i < operands.size(); i++)
            {
                result += operands[i]->toString();
                if (i < operands.size() - 1)result += ", ";
            }
            result += ")";
            return result;
        }

        IRBinaryOperates::IRBinaryOperates(Operator op, value::IRValue* operand1, value::IRValue* operand2,
                                           value::IRRegister* target) : op(op), operand1(operand1), operand2(operand2),
                                                                        target(target)
        {
            target->def = this;
            target->type = operand1->getType();
        }

        std::any IRBinaryOperates::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitBinaryOperates(this, std::move(additional));
        }

        std::string IRBinaryOperates::toString()
        {
            return "%" + target->name + " = " + operatorToString(op) + " " + operand1->toString() + ", " + operand2->
                toString();
        }

        std::string IRBinaryOperates::operatorToString(Operator op)
        {
            switch (op)
            {
            case Operator::ADD:
                return "add";
            case Operator::SUB:
                return "sub";
            case Operator::MUL:
                return "mul";
            case Operator::DIV:
                return "div";
            case Operator::MOD:
                return "mod";
            case Operator::AND:
                return "and";
            case Operator::OR:
                return "or";
            case Operator::XOR:
                return "xor";
            case Operator::SHL:
                return "shl";
            case Operator::SHR:
                return "shr";
            case Operator::USHR:
                return "ushr";
            default:
                return "";
            }
        }

        IRUnaryOperates::IRUnaryOperates(Operator op, value::IRValue* operand,
                                         value::IRRegister* target) : op(op), operand(operand), target(target)
        {
            target->def = this;
            target->type = operand->getType();
        }

        std::any IRUnaryOperates::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitUnaryOperates(this, std::move(additional));
        }

        std::string IRUnaryOperates::toString()
        {
            return "%" + target->name + " = " + operatorToString(op) + " " + operand->toString();
        }

        std::string IRUnaryOperates::operatorToString(Operator op)
        {
            switch (op)
            {
            case Operator::INC:
                return "inc";
            case Operator::DEC:
                return "dec";
            case Operator::NOT:
                return "not";
            case Operator::NEG:
                return "neg";
            default:
                return "";
            }
        }

        IRGetElementPointer::IRGetElementPointer(value::IRValue* pointer,
                                                 std::vector<value::constant::IRIntegerConstant*> indices,
                                                 value::IRRegister* target) : pointer(pointer),
                                                                              indices(std::move(indices)),
                                                                              target(target)
        {
            target->def = this;
            type::IRType* ty = pointer->getType();
            for (auto& index : indices)
            {
                if (auto pointerType = dynamic_cast<type::IRPointerType*>(ty))
                {
                    ty = pointerType->base;
                }
                else if (auto arrayType = dynamic_cast<type::IRArrayType*>(ty))
                {
                    ty = arrayType->base;
                }
                else if (auto structureType = dynamic_cast<type::IRStructureType*>(ty))
                {
                    ty = structureType->structure->fields[index->value]->type;
                }
            }
            target->type = type::IRPointerType::get(ty);
        }

        std::any IRGetElementPointer::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitGetElementPointer(this, std::move(additional));
        }

        std::string IRGetElementPointer::toString()
        {
            std::string result = "%" + target->name + " = getelementptr " + pointer->toString();
            for (const auto& index : indices)
            {
                result += ", " + index->toString();
            }
            return result;
        }

        IRCompare::IRCompare(base::IRCondition condition, value::IRValue* operand1, value::IRValue* operand2,
                             value::IRRegister* target) : condition(condition), operand1(operand1), operand2(operand2),
                                                          target(target)
        {
            target->def = this;
            target->type = type::IRIntegerType::getBooleanType();
        }

        std::any IRCompare::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitCompare(this, std::move(additional));
        }

        std::string IRCompare::toString()
        {
            return "%" + target->name + " = cmp " + conditionToString(condition) + ", " + operand1->toString() + ", " +
                operand2->toString();
        }

        IRConditionalJump::IRConditionalJump(base::IRCondition condition, value::IRValue* operand,
                                             base::IRBasicBlock* target) : condition(condition), operand1(operand),
                                                                           operand2(nullptr), target(target)
        {
        }

        IRConditionalJump::IRConditionalJump(base::IRCondition condition, value::IRValue* operand1,
                                             value::IRValue* operand2,
                                             base::IRBasicBlock* target) : condition(condition), operand1(operand1),
                                                                           operand2(operand2), target(target)
        {
        }

        std::any IRConditionalJump::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitConditionalJump(this, std::move(additional));
        }

        std::string IRConditionalJump::toString()
        {
            return "conditional_jump " + conditionToString(condition) + ", " + operand1->toString() + (
                operand2 != nullptr ? ", " + operand2->toString() : "") + ", label" + target->name;
        }

        IRGoto::IRGoto(base::IRBasicBlock* target) : target(target)
        {
        }

        std::any IRGoto::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitGoto(this, std::move(additional));
        }

        std::string IRGoto::toString()
        {
            return "goto label" + target->name;
        }

        IRInvoke::IRInvoke(type::IRType* returnType, value::IRValue* func, std::vector<value::IRValue*> arguments,
                           value::IRRegister* target) : returnType(returnType), func(func),
                                                        arguments(std::move(arguments)), target(target)
        {
            if (target != nullptr)
            {
                target->def = this;
                target->type = returnType;
            }
        }

        std::any IRInvoke::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitInvoke(this, std::move(additional));
        }

        std::string IRInvoke::toString()
        {
            std::string result;
            if (target != nullptr)
            {
                result += "%" + target->name + " = ";
            }
            result += "invoke " + returnType->toString() + " " + func->toString() + "(";
            for (int i = 0; i < arguments.size(); i++)
            {
                result += arguments[i]->toString();
                if (i < arguments.size() - 1)
                {
                    result += ", ";
                }
            }
            result += ")";
            return result;
        }

        IRReturn::IRReturn() : value(nullptr)
        {
        }

        IRReturn::IRReturn(value::IRValue* value) : value(value)
        {
        }

        std::any IRReturn::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitReturn(this, std::move(additional));
        }

        std::string IRReturn::toString()
        {
            return "return" + (value != nullptr ? " " + value->toString() : "");
        }

        IRLoad::IRLoad(value::IRValue* ptr, value::IRRegister* target) : ptr(ptr), target(target)
        {
            target->def = this;
            target->type = dynamic_cast<type::IRPointerType*>(ptr->getType())->base;
        }

        std::any IRLoad::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitLoad(this, std::move(additional));
        }

        std::string IRLoad::toString()
        {
            return "%" + target->name + " = load " + ptr->toString();
        }

        IRStore::IRStore(value::IRValue* ptr, value::IRValue* value) : ptr(ptr), value(value)
        {
        }

        std::any IRStore::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitStore(this, std::move(additional));
        }

        std::string IRStore::toString()
        {
            return "store " + ptr->toString() + ", " + value->toString();
        }

        std::any IRNop::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitNop(this, std::move(additional));
        }

        std::string IRNop::toString()
        {
            return "nop";
        }

        IRSetRegister::IRSetRegister(value::IRValue* value, value::IRRegister* target) : value(value), target(target)
        {
            target->def = this;
            target->type = value->getType();
        }

        std::any IRSetRegister::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitSetRegister(this, std::move(additional));
        }

        std::string IRSetRegister::toString()
        {
            return "%" + target->name + " = " + value->toString();
        }

        IRStackAllocate::IRStackAllocate(value::IRValue* size, value::IRRegister* target) : size(size), target(target)
        {
            target->def = this;
            target->type = type::IRPointerType::get(type::IRVoidType::get());
        }

        std::any IRStackAllocate::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitStackAllocate(this, std::move(additional));
        }

        std::string IRStackAllocate::toString()
        {
            return "%" + target->name + " = stack_alloc " + size->toString();
        }

        IRTypeCast::IRTypeCast(Kind kind, value::IRValue* source, type::IRType* targetType, value::IRRegister* target) :
            kind(kind), source(source), targetType(targetType), target(target)
        {
            target->def = this;
            target->type = targetType;
        }

        std::any IRTypeCast::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitTypeCast(this, std::move(additional));
        }

        std::string IRTypeCast::toString()
        {
            return "%" + target->name + " = " + kindToString(kind) + " " + source->toString() + " to " + targetType->
                toString();
        }

        std::string IRTypeCast::kindToString(Kind kind)
        {
            switch (kind)
            {
            case Kind::ZEXT:
                return "zext";
            case Kind::SEXT:
                return "sext";
            case Kind::TRUNC:
                return "trunc";
            case Kind::FTOI:
                return "ftoi";
            case Kind::ITOF:
                return "itof";
            case Kind::ITOP:
                return "itop";
            case Kind::PTOI:
                return "ptoi";
            case Kind::PTOP:
                return "ptop";
            case Kind::FEXT:
                return "fext";
            case Kind::FTRUNC:
                return "ftrunc";
            default:
                return "";
            }
        }
    }

    std::any IRVisitor::visit(base::IRNode* node, std::any additional)
    {
        return node->accept(this, std::move(additional));
    }

    std::any IRVisitor::visitModule(IRModule* module, std::any additional)
    {
        for (auto& function : module->functions | std::views::values)
        {
            visit(function, additional);
        }
        for (auto& structure : module->structures | std::views::values)
        {
            visit(structure, additional);
        }
        for (auto& global : module->globals | std::views::values)
        {
            visit(global, additional);
        }
        return nullptr;
    }

    std::any IRVisitor::visitGlobalVariable(base::IRGlobalVariable* irGlobalVariable, std::any additional)
    {
        visit(irGlobalVariable->type, additional);
        return visit(irGlobalVariable->initializer, std::move(additional));
    }

    std::any IRVisitor::visitFunction(function::IRFunction* irFunction, std::any additional)
    {
        visit(irFunction->returnType, additional);
        for (auto& arg : irFunction->args)
        {
            visit(arg, additional);
        }
        for (auto& local : irFunction->locals)
        {
            visit(local, additional);
        }
        if (irFunction->cfg != nullptr)
        {
            for (auto& block : irFunction->cfg->basicBlocks | std::views::values)
            {
                for (auto& instruction : block->instructions)
                {
                    visit(instruction, additional);
                }
            }
        }
        return nullptr;
    }

    std::any IRVisitor::visitLocalVariable(function::IRLocalVariable* irLocalVariable, std::any additional)
    {
        return visit(irLocalVariable->type, std::move(additional));
    }

    std::any IRVisitor::visitStructure(structure::IRStructure* irStructure, std::any additional)
    {
        for (auto& field : irStructure->fields)
        {
            visit(field, additional);
        }
        return nullptr;
    }

    std::any IRVisitor::visitField(structure::IRField* irField, std::any additional)
    {
        return visit(irField->type, std::move(additional));
    }

    std::any IRVisitor::visitIntegerType(type::IRIntegerType* irIntegerType, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitFloatType(type::IRFloatType* irFloatType, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitDoubleType(type::IRDoubleType* irDoubleType, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitStructureType(type::IRStructureType* irStructureType, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitArrayType(type::IRArrayType* irArrayType, std::any additional)
    {
        return visit(irArrayType->base, std::move(additional));
    }

    std::any IRVisitor::visitPointerType(type::IRPointerType* irPointerType, std::any additional)
    {
        return visit(irPointerType->base, std::move(additional));
    }

    std::any IRVisitor::visitVoidType(type::IRVoidType* irVoidType, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitRegister(value::IRRegister* irRegister, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitFunctionReference(value::IRFunctionReference* irFunctionReference, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitGlobalVariableReference(value::IRGlobalVariableReference* irGlobalVariableReference,
                                                     std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitLocalVariableReference(value::IRLocalVariableReference* irLocalVariableReference,
                                                    std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitIntegerConstant(value::constant::IRIntegerConstant* irIntegerConstant, std::any additional)
    {
        return visit(irIntegerConstant->type, std::move(additional));
    }

    std::any IRVisitor::visitFloatConstant(value::constant::IRFloatConstant* irFloatConstant, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitDoubleConstant(value::constant::IRDoubleConstant* irDoubleConstant, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitArrayConstant(value::constant::IRArrayConstant* irArrayConstant, std::any additional)
    {
        visit(irArrayConstant->type, additional);
        for (auto& element : irArrayConstant->elements)
        {
            visit(element, additional);
        }
        return nullptr;
    }

    std::any IRVisitor::visitStringConstant(value::constant::IRStringConstant* irStringConstant, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitNullptrConstant(value::constant::IRNullptrConstant* irNullptrConstant, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitAssembly(instruction::IRAssembly* irAssembly, std::any additional)
    {
        for (auto& operand : irAssembly->operands)
        {
            visit(operand, additional);
        }
        return nullptr;
    }

    std::any IRVisitor::visitBinaryOperates(instruction::IRBinaryOperates* irBinaryOperates, std::any additional)
    {
        visit(irBinaryOperates->operand1, additional);
        visit(irBinaryOperates->operand2, additional);
        visit(irBinaryOperates->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitUnaryOperates(instruction::IRUnaryOperates* irUnaryOperates, std::any additional)
    {
        visit(irUnaryOperates->operand, additional);
        visit(irUnaryOperates->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitGetElementPointer(instruction::IRGetElementPointer* irGetElementPointer,
                                               std::any additional)
    {
        visit(irGetElementPointer->pointer, additional);
        for (auto& index : irGetElementPointer->indices)
        {
            visit(index, additional);
        }
        visit(irGetElementPointer->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitCompare(instruction::IRCompare* irCompare, std::any additional)
    {
        visit(irCompare->operand1, additional);
        visit(irCompare->operand2, additional);
        visit(irCompare->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitConditionalJump(instruction::IRConditionalJump* irConditionalJump, std::any additional)
    {
        visit(irConditionalJump->operand1, additional);
        if (irConditionalJump->operand2 != nullptr)
        {
            visit(irConditionalJump->operand2, std::move(additional));
        }
        return nullptr;
    }

    std::any IRVisitor::visitGoto(instruction::IRGoto* irGoto, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitInvoke(instruction::IRInvoke* irInvoke, std::any additional)
    {
        visit(irInvoke->returnType, additional);
        visit(irInvoke->func, additional);
        for (auto& arg : irInvoke->arguments)
        {
            visit(arg, additional);
        }
        if (irInvoke->target != nullptr)
        {
            visit(irInvoke->target, std::move(additional));
        }
        return nullptr;
    }

    std::any IRVisitor::visitReturn(instruction::IRReturn* irReturn, std::any additional)
    {
        if (irReturn->value != nullptr)
        {
            visit(irReturn->value, std::move(additional));
        }
        return nullptr;
    }

    std::any IRVisitor::visitLoad(instruction::IRLoad* irLoad, std::any additional)
    {
        visit(irLoad->ptr, additional);
        visit(irLoad->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitStore(instruction::IRStore* irStore, std::any additional)
    {
        visit(irStore->ptr, std::move(additional));
        visit(irStore->value, additional);
        return nullptr;
    }

    std::any IRVisitor::visitNop(instruction::IRNop* irNop, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitSetRegister(instruction::IRSetRegister* irSetRegister, std::any additional)
    {
        visit(irSetRegister->value, std::move(additional));
        visit(irSetRegister->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitStackAllocate(instruction::IRStackAllocate* irStackAllocate, std::any additional)
    {
        visit(irStackAllocate->size, additional);
        visit(irStackAllocate->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitTypeCast(instruction::IRTypeCast* irTypeCast, std::any additional)
    {
        visit(irTypeCast->source, additional);
        visit(irTypeCast->targetType, additional);
        visit(irTypeCast->target, std::move(additional));
        return nullptr;
    }


    std::any IRModule::accept(IRVisitor* visitor, std::any additional)
    {
        return visitor->visitModule(this, std::move(additional));
    }

    std::string IRModule::toString()
    {
        return "";
    }
}
