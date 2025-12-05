#include <lg/ir.h>
#include <ranges>

#include <utility>

namespace lg::ir
{
    namespace base
    {
        IRGlobalVariable::IRGlobalVariable(IRModule* module, std::vector<std::string> attributes, bool isConstant,
                                           std::string name,
                                           type::IRType* type,
                                           value::constant::IRConstant* initializer) :
            attributes(std::move(attributes)), isExtern(false),
            isConstant(isConstant), type(type), name(std::move(name)), initializer(initializer)
        {
            reference = new value::constant::IRGlobalVariableReference(module, this);
        }

        IRGlobalVariable::IRGlobalVariable(IRModule* module, std::vector<std::string> attributes, bool isConstant,
                                           std::string name,
                                           value::constant::IRConstant* initializer) :
            attributes(std::move(attributes)), isExtern(false),
            isConstant(isConstant), type(initializer->getType()), name(std::move(name)), initializer(initializer)
        {
            reference = new value::constant::IRGlobalVariableReference(module, this);
        }

        IRGlobalVariable::IRGlobalVariable(IRModule* module, std::vector<std::string> attributes, bool isConstant,
                                           std::string name,
                                           type::IRType* type) : attributes(std::move(attributes)), isExtern(false),
                                                                 isConstant(isConstant), type(type),
                                                                 name(std::move(name))
        {
            reference = new value::constant::IRGlobalVariableReference(module, this);
        }

        IRGlobalVariable::~IRGlobalVariable()
        {
            delete reference;
        }

        std::any IRGlobalVariable::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitGlobalVariable(this, std::move(additional));
        }

        std::string IRGlobalVariable::toString()
        {
            std::string s;
            for (const auto& attribute : attributes)s += "__attribute__(\"" + attribute + "\") ";
            if (isExtern) s += "extern ";
            if (isConstant) s += "constant ";
            s += "global " + name;
            if (isExtern) s += ": " + type->toString();
            else s += " = " + initializer->toString();
            return s;
        }

        void IRGlobalVariable::setInitializer(value::constant::IRConstant* initializer)
        {
            this->initializer = initializer;
            type = initializer->getType();
        }

        value::constant::IRGlobalVariableReference* IRGlobalVariable::getReference() const
        {
            return reference;
        }

        IRControlFlowGraph::~IRControlFlowGraph()
        {
            for (const auto& basicBlock : basicBlocks | std::views::values)delete basicBlock;
        }

        std::string IRControlFlowGraph::toString()
        {
            return "";
        }

        void IRControlFlowGraph::addBasicBlock(IRBasicBlock* basicBlock)
        {
            basicBlocks[basicBlock->name] = basicBlock;
            function->cfg = this;
        }

        IRBasicBlock::IRBasicBlock(std::string name) : name(std::move(name))
        {
        }

        IRBasicBlock::~IRBasicBlock()
        {
            for (const auto& instruction : instructions)delete instruction;
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
        bool IRType::operator!=(const IRType& other)
        {
            return !(*this == other);
        }

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

        bool IRIntegerType::operator==(const IRType& other)
        {
            if (auto* o = dynamic_cast<const IRIntegerType*>(&other))
                return size == o->size && _unsigned == o->_unsigned;
            return false;
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

        bool IRFloatType::operator==(const IRType& other)
        {
            return dynamic_cast<const IRFloatType*>(&other) != nullptr;
        }

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

        bool IRDoubleType::operator==(const IRType& other)
        {
            return dynamic_cast<const IRDoubleType*>(&other) != nullptr;
        }

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

        bool IRStructureType::operator==(const IRType& other)
        {
            if (auto* o = dynamic_cast<const IRStructureType*>(&other))
                return structure == o->structure;
            return false;
        }

        IRStructureType* IRStructureType::get(const structure::IRStructure* structure)
        {
            return structure->getType();
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

        bool IRArrayType::operator==(const IRType& other)
        {
            if (auto* o = dynamic_cast<const IRArrayType*>(&other))
                return base == o->base && size == o->size;
            return false;
        }

        IRArrayType* IRArrayType::get(IRModule* module, IRType* base, uint64_t size)
        {
            auto p = std::make_pair(base, size);
            if (module->arrayTypes.contains(p)) return module->arrayTypes[p];
            return module->arrayTypes[p] = new IRArrayType(base, size);
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

        bool IRPointerType::operator==(const IRType& other)
        {
            if (auto* o = dynamic_cast<const IRPointerType*>(&other))
                return base == o->base;
            return false;
        }

        IRPointerType* IRPointerType::get(IRModule* module, IRType* base)
        {
            if (module->pointerTypes.contains(base)) return module->pointerTypes[base];
            return module->pointerTypes[base] = new IRPointerType(base);
        }

        std::any IRVoidType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitVoidType(this, std::move(additional));
        }

        std::string IRVoidType::toString()
        {
            return "void";
        }

        bool IRVoidType::operator==(const IRType& other)
        {
            return dynamic_cast<const IRVoidType*>(&other) != nullptr;
        }


        IRVoidType* IRVoidType::get()
        {
            static IRVoidType instance;
            return &instance;
        }

        IRFunctionReferenceType::IRFunctionReferenceType(IRType* returnType, std::vector<IRType*> parameterTypes,
                                                         bool isVarArg) : returnType(returnType),
                                                                          parameterTypes(std::move(parameterTypes)),
                                                                          isVarArg(isVarArg)
        {
        }

        std::any IRFunctionReferenceType::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitFunctionReferenceType(this, std::move(additional));
        }

        std::string IRFunctionReferenceType::toString()
        {
            std::string s = "(";
            for (size_t i = 0; i < parameterTypes.size(); i++)
            {
                s += parameterTypes[i]->toString();
                if (isVarArg || (i != parameterTypes.size() - 1)) s += ", ";
            }
            if (isVarArg) s += "...";
            s += ") -> " + returnType->toString();
            return s;
        }

        bool IRFunctionReferenceType::operator==(const IRType& other)
        {
            if (auto* o = dynamic_cast<const IRFunctionReferenceType*>(&other))
            {
                if (o->isVarArg != isVarArg) return false;
                if (o->parameterTypes.size() != parameterTypes.size()) return false;
                for (size_t i = 0; i < parameterTypes.size(); i++)
                    if (o->parameterTypes[i] != parameterTypes[i])
                        return false;
                return o->returnType == returnType;
            }
            return false;
        }

        IRFunctionReferenceType* IRFunctionReferenceType::get(IRModule* module, IRType* returnType,
                                                              std::vector<IRType*> parameterTypes,
                                                              const bool isVarArg)
        {
            auto* instance = new IRFunctionReferenceType(returnType, std::move(parameterTypes), isVarArg);
            module->anotherTypes.push_back(instance);
            return instance;
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

        IRLocalVariableReference::IRLocalVariableReference(IRModule* module,
                                                           function::IRLocalVariable* variable) : variable(variable)
        {
            type = type::IRPointerType::get(module, variable->type);
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

        IRLocalVariableReference* IRLocalVariableReference::get(function::IRLocalVariable* variable)
        {
            return variable->getReference();
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

            IRIntegerConstant* IRIntegerConstant::get(IRModule* module, type::IRIntegerType* type, uint64_t value)
            {
                if (module->integerConstants.contains(type) && module->integerConstants[type].contains(value))
                    return module->integerConstants[type][value];
                return module->integerConstants[type][value] = new IRIntegerConstant(type, value);
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

            IRFloatConstant* IRFloatConstant::get(IRModule* module, float value)
            {
                if (module->floatConstants.contains(value))
                    return module->floatConstants[value];
                return module->floatConstants[value] = new IRFloatConstant(value);
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

            IRDoubleConstant* IRDoubleConstant::get(IRModule* module, double value)
            {
                if (module->doubleConstants.contains(value))
                    return module->doubleConstants[value];
                return module->doubleConstants[value] = new IRDoubleConstant(value);
            }

            IRArrayConstant::IRArrayConstant(type::IRArrayType* type,
                                             std::vector<IRConstant*> elements) : type(type),
                elements(std::move(elements))
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

            IRArrayConstant* IRArrayConstant::get(IRModule* module, type::IRArrayType* type,
                                                  std::vector<IRConstant*> elements)
            {
                auto* instance = new IRArrayConstant(type, std::move(elements));
                module->anotherValues.push_back(instance);
                return instance;
            }

            IRStringConstant::IRStringConstant(IRModule* module, std::string value) : value(std::move(value))
            {
                type = type::IRPointerType::get(module, type::IRIntegerType::getUnsignedInt32Type());
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

            IRStringConstant* IRStringConstant::get(IRModule* module, std::string value)
            {
                if (module->stringConstants.contains(value))
                    return module->stringConstants[value];
                return module->stringConstants[value] = new IRStringConstant(module, std::move(value));
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

            IRNullptrConstant* IRNullptrConstant::get(IRModule* module, type::IRPointerType* type)
            {
                if (module->nullptrConstants.contains(type))
                    return module->nullptrConstants[type];
                return module->nullptrConstants[type] = new IRNullptrConstant(type);
            }

            IRStructureInitializer::IRStructureInitializer(type::IRStructureType* type,
                                                           std::vector<IRConstant*> elements) : type(type),
                elements(std::move(elements))
            {
            }

            type::IRType* IRStructureInitializer::getType()
            {
                return type;
            }

            std::any IRStructureInitializer::accept(IRVisitor* visitor, std::any additional)
            {
                return visitor->visitStructureInitializer(this, std::move(additional));
            }

            std::string IRStructureInitializer::toString()
            {
                std::string s = "constant " + type->toString() + " {";
                for (int i = 0; i < elements.size(); i++)
                {
                    s += elements[i]->toString();
                    if (i < elements.size() - 1)s += ", ";
                }
                s += "}";
                return s;
            }

            IRStructureInitializer* IRStructureInitializer::get(IRModule* module, type::IRStructureType* type,
                                                                std::vector<IRConstant*> elements)
            {
                auto* instance = new IRStructureInitializer(type, std::move(elements));
                module->anotherValues.push_back(instance);
                return instance;
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

            IRFunctionReference* IRFunctionReference::get(const function::IRFunction* function)
            {
                return function->getReference();
            }

            IRGlobalVariableReference::IRGlobalVariableReference(IRModule* module,
                                                                 base::IRGlobalVariable* variable) : variable(variable)
            {
                type = type::IRPointerType::get(module, variable->type);
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

            IRGlobalVariableReference* IRGlobalVariableReference::get(const base::IRGlobalVariable* variable)
            {
                return variable->getReference();
            }
        }
    }

    namespace function
    {
        IRFunction::IRFunction(std::vector<std::string> attributes, type::IRType* returnType,
                               std::string name,
                               std::vector<IRLocalVariable*> args, bool isVarArg, std::vector<IRLocalVariable*> locals,
                               base::IRControlFlowGraph* cfg) : attributes(std::move(attributes)),
                                                                isExtern(cfg == nullptr),
                                                                returnType(returnType), name(std::move(name)),
                                                                args(std::move(args)), isVarArg(isVarArg),
                                                                locals(std::move(locals)),
                                                                cfg(cfg)
        {
            if (cfg != nullptr) cfg->function = this;
            for (const auto& arg : args) name2LocalVariable[arg->name] = arg;
            if (!isExtern) for (const auto& local : locals) name2LocalVariable[local->name] = local;
            reference = new value::constant::IRFunctionReference(this);
        }

        IRFunction::IRFunction(std::vector<std::string> attributes, type::IRType* returnType,
                               std::string name,
                               std::vector<IRLocalVariable*> args, bool isVarArg) : IRFunction(
            std::move(attributes), returnType, std::move(name), std::move(args), isVarArg, {}, nullptr)
        {
        }

        IRFunction::~IRFunction()
        {
            for (const auto& local : args) delete local;
            for (const auto& local : locals) delete local;
            delete cfg;
            delete reference;
        }


        std::any IRFunction::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitFunction(this, std::move(additional));
        }

        std::string IRFunction::toString()
        {
            return "";
        }

        void IRFunction::addBasicBlock(base::IRBasicBlock* basicBlock) const
        {
            cfg->addBasicBlock(basicBlock);
        }

        base::IRBasicBlock* IRFunction::getBasicBlock(const std::string& name) const
        {
            return cfg->basicBlocks[name];
        }

        IRLocalVariable* IRFunction::getLocalVariable(const std::string& name)
        {
            return name2LocalVariable[name];
        }

        value::constant::IRFunctionReference* IRFunction::getReference() const
        {
            return reference;
        }

        IRLocalVariable::IRLocalVariable(IRModule* module, type::IRType* type,
                                         std::string name) : type(type), name(std::move(name))
        {
            reference = new value::IRLocalVariableReference(module, this);
        }

        IRLocalVariable::~IRLocalVariable()
        {
            delete reference;
        }

        std::any IRLocalVariable::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitLocalVariable(this, std::move(additional));
        }

        std::string IRLocalVariable::toString()
        {
            return type->toString() + " " + name;
        }

        value::IRLocalVariableReference* IRLocalVariable::getReference() const
        {
            return reference;
        }
    }

    namespace structure
    {
        IRStructure::IRStructure(std::vector<std::string> attributes, std::string name, std::vector<IRField*> fields) :
            attributes(std::move(attributes)), name(std::move(name)), fields(std::move(fields))
        {
            type = new type::IRStructureType(this);
        }

        IRStructure::~IRStructure()
        {
            for (const auto& field : fields) delete field;
            delete type;
        }

        std::any IRStructure::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitStructure(this, std::move(additional));
        }

        std::string IRStructure::toString()
        {
            return "structure";
        }

        type::IRStructureType* IRStructure::getType() const
        {
            return type;
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

        IRBinaryOperates::~IRBinaryOperates()
        {
            delete target;
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

        IRUnaryOperates::~IRUnaryOperates()
        {
            delete target;
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

        IRGetElementPointer::IRGetElementPointer(IRModule* module, value::IRValue* pointer,
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
            target->type = type::IRPointerType::get(module, ty);
        }

        IRGetElementPointer::~IRGetElementPointer()
        {
            delete target;
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

        IRCompare::~IRCompare()
        {
            delete target;
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
                operand2 != nullptr ? ", " + operand2->toString() : "") + ", label " + target->name;
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
            return "goto label " + target->name;
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

        IRInvoke::~IRInvoke()
        {
            delete target;
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

        IRLoad::~IRLoad()
        {
            delete target;
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

        IRSetRegister::~IRSetRegister()
        {
            delete target;
        }

        std::any IRSetRegister::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitSetRegister(this, std::move(additional));
        }

        std::string IRSetRegister::toString()
        {
            return "%" + target->name + " = " + value->toString();
        }

        IRStackAllocate::IRStackAllocate(IRModule* module, type::IRType* type, value::IRValue* size,
                                         value::IRRegister* target) : type(type), size(size), target(target)
        {
            target->def = this;
            target->type = type::IRPointerType::get(module, type);
        }

        IRStackAllocate::~IRStackAllocate()
        {
            delete target;
        }

        std::any IRStackAllocate::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitStackAllocate(this, std::move(additional));
        }

        std::string IRStackAllocate::toString()
        {
            return "%" + target->name + " = stack_alloc " + type->toString() + (size != nullptr
                ? ", " + size->toString()
                : "");
        }

        IRTypeCast::IRTypeCast(Kind kind, value::IRValue* source, type::IRType* targetType, value::IRRegister* target) :
            kind(kind), source(source), targetType(targetType), target(target)
        {
            target->def = this;
            target->type = targetType;
        }

        IRTypeCast::~IRTypeCast()
        {
            delete target;
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
            case Kind::FTOINT:
                return "ftoint";
            case Kind::INTTOF:
                return "inttof";
            case Kind::INTTOPTR:
                return "inttoptr";
            case Kind::PTRTOINT:
                return "ptrtoint";
            case Kind::PTRTOPTR:
                return "ptrtoptr";
            case Kind::FEXT:
                return "fext";
            case Kind::FTRUNC:
                return "ftrunc";
            case Kind::BITCAST:
                return "bitcast";
            default:
                return "";
            }
        }

        IRPhi::IRPhi(std::unordered_map<base::IRBasicBlock*, value::IRValue*> values,
                     value::IRRegister* target) : values(std::move(values)), target(target)
        {
            target->def = this;
            target->type = values.begin()->second->getType();
        }

        IRPhi::~IRPhi()
        {
            delete target;
        }


        std::any IRPhi::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitPhi(this, std::move(additional));
        }

        std::string IRPhi::toString()
        {
            std::string result = "%" + target->name + " = phi ";
            for (auto& [block, value] : values)
            {
                result += ", [label: " + block->name + ", " + value->toString() + "]";
            }
            return result;
        }

        IRSwitch::IRSwitch(value::IRValue* value, base::IRBasicBlock* defaultCase,
                           std::unordered_map<value::constant::IRIntegerConstant*, base::IRBasicBlock*> cases) :
            value(value),
            defaultCase(defaultCase), cases(std::move(cases))
        {
        }

        std::any IRSwitch::accept(IRVisitor* visitor, std::any additional)
        {
            return visitor->visitSwitch(this, std::move(additional));
        }

        std::string IRSwitch::toString()
        {
            std::string s = "switch " + value->toString() + ", label" + defaultCase->name;
            for (auto& [value, block] : cases)
            {
                s += ", [" + value->toString() + ", label" + block->name + "]";
            }
            return s;
        }
    }

    std::any IRVisitor::visit(base::IRNode* node, std::any additional)
    {
        return node->accept(this, std::move(additional));
    }

    std::any IRVisitor::visitModule(IRModule* module, std::any additional)
    {
        for (const auto& structure : module->structures | std::views::values)
        {
            visit(structure, additional);
        }
        for (const auto& global : module->globals | std::views::values)
        {
            visit(global, additional);
        }
        for (const auto& function : module->functions | std::views::values)
        {
            visit(function, additional);
        }
        return nullptr;
    }

    std::any IRVisitor::visitGlobalVariable(base::IRGlobalVariable* irGlobalVariable, std::any additional)
    {
        visit(irGlobalVariable->type, additional);
        if (irGlobalVariable->initializer != nullptr)
        {
            visit(irGlobalVariable->initializer, std::move(additional));
        }
        return nullptr;
    }


    std::any IRVisitor::visitFunction(function::IRFunction* irFunction, std::any additional)
    {
        visit(irFunction->returnType, additional);
        for (auto& arg : irFunction->args)
        {
            visit(arg, additional);
        }
        if (irFunction->cfg != nullptr)
        {
            for (auto& local : irFunction->locals)
            {
                visit(local, additional);
            }
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

    std::any IRVisitor::visitFunctionReferenceType(type::IRFunctionReferenceType* irFunctionReferenceType,
                                                   std::any additional)
    {
        visit(irFunctionReferenceType->returnType, additional);
        for (auto* parameterType : irFunctionReferenceType->parameterTypes)
        {
            visit(parameterType, additional);
        }
        return nullptr;
    }


    std::any IRVisitor::visitRegister(value::IRRegister* irRegister, std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitFunctionReference(value::constant::IRFunctionReference* irFunctionReference,
                                               std::any additional)
    {
        return nullptr;
    }

    std::any IRVisitor::visitGlobalVariableReference(
        value::constant::IRGlobalVariableReference* irGlobalVariableReference,
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

    std::any IRVisitor::visitStructureInitializer(value::constant::IRStructureInitializer* irStructureInitializer,
                                                  std::any additional)
    {
        visit(irStructureInitializer->type, additional);
        for (const auto& element : irStructureInitializer->elements)
        {
            visit(element, additional);
        }
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
        visit(irStackAllocate->type, additional);
        if (irStackAllocate->size != nullptr)
        {
            visit(irStackAllocate->size, additional);
        }
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

    std::any IRVisitor::visitPhi(instruction::IRPhi* irPhi, std::any additional)
    {
        for (const auto& value : irPhi->values | std::views::values)
        {
            visit(value, additional);
        }
        visit(irPhi->target, std::move(additional));
        return nullptr;
    }

    std::any IRVisitor::visitSwitch(instruction::IRSwitch* irSwitch, std::any additional)
    {
        visit(irSwitch->value, additional);
        for (const auto& constant : irSwitch->cases | std::views::keys)
        {
            visit(constant, additional);
        }
        return nullptr;
    }

    IRModule::~IRModule()
    {
        for (const auto& global : globals | std::views::values) delete global;
        for (const auto& structure : structures | std::views::values) delete structure;
        for (const auto& function : functions | std::views::values) delete function;
        for (const auto& m : integerConstants | std::views::values)
            for (auto& constant : m | std::views::values)
                delete constant;
        for (const auto& constant : floatConstants | std::views::values) delete constant;
        for (const auto& constant : doubleConstants | std::views::values) delete constant;
        for (const auto& constant : stringConstants | std::views::values) delete constant;
        for (const auto& constant : nullptrConstants | std::views::values) delete constant;
        for (const auto& value : anotherValues) delete value;
        for (const auto& arrayType : arrayTypes | std::views::values) delete arrayType;
        for (const auto& pointerType : pointerTypes | std::views::values) delete pointerType;
        for (const auto& type : anotherTypes) delete type;
    }

    std::any IRModule::accept(IRVisitor* visitor, std::any additional)
    {
        return visitor->visitModule(this, std::move(additional));
    }

    std::string IRModule::toString()
    {
        return "";
    }

    void IRModule::putGlobalVariable(base::IRGlobalVariable* globalVariable)
    {
        globals[globalVariable->name] = globalVariable;
    }

    void IRModule::putStructure(structure::IRStructure* structure)
    {
        structures[structure->name] = structure;
    }

    void IRModule::putFunction(function::IRFunction* function)
    {
        functions[function->name] = function;
    }

    base::IRGlobalVariable* IRModule::getGlobalVariable(const std::string& name)
    {
        return globals[name];
    }

    structure::IRStructure* IRModule::getStructure(const std::string& name)
    {
        return structures[name];
    }

    function::IRFunction* IRModule::getFunction(const std::string& name)
    {
        return functions[name];
    }
}
