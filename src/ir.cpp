#include <ir.h>

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
        IRRegister::IRRegister(type::IRType* type, std::string name) : type(type), name(std::move(name))
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
            type = new type::IRPointerType(variable->type);
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
            type = new type::IRPointerType(variable->type);
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
                                             std::vector<IRConstant*> values) : type(type), values(std::move(values))
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
                for (int i = 0; i < values.size(); i++)
                {
                    result += values[i]->toString();
                    if (i < values.size() - 1)result += ", ";
                }
                result += "]";
                return result;
            }

            IRStringConstant::IRStringConstant(std::string value) : value(std::move(value))
            {
                type = new type::IRPointerType(type::IRIntegerType::getUnsignedInt32Type());
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
            cfg->function = this;
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

    std::any IRVisitor::visit(base::IRNode* node, std::any additional)
    {
        return node->accept(this, std::move(additional));
    }

    std::any IRVisitor::visitModule(IRModule* module, std::any additional)
    {
        for (auto& [name, function] : module->functions)
        {
            visit(function, additional);
        }
        for (auto& [name, structure] : module->structures)
        {
            visit(structure, additional);
        }
        for (auto& [name, global] : module->globals)
        {
            visit(global, additional);
        }
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
