//
// Created by xiaoli on 2025/11/24.
//

#include <IRParser.h>

#include "dumper.h"

namespace lg::ir::parser
{
    IRParser::IRParser(IRModule* module) : module(module), builder(module)
    {
    }

    std::any IRParser::visitProgram(LGIRGrammarParser::ProgramContext* context)
    {
        for (const auto& structure : context->structure())
        {
            std::vector<std::string> attributes;
            for (const auto& attribute : structure->attribute())
            {
                attributes.emplace_back(parseAttribute(attribute));
            }
            module->putStructure(
                new structure::IRStructure(std::move(attributes), structure->IDENTIFIER()->getText(), {}));
        }
        for (const auto& globalVariable : context->globalVariable())
        {
            std::vector<std::string> attributes;
            for (const auto& attribute : globalVariable->attribute())
            {
                attributes.emplace_back(parseAttribute(attribute));
            }
            if (globalVariable->EXTERN())
            {
                visit(globalVariable->type());
                auto* type = std::any_cast<type::IRType*>(stack.top());
                stack.pop();
                module->putGlobalVariable(new base::IRGlobalVariable(module, std::move(attributes),
                                                                     globalVariable->CONST() != nullptr,
                                                                     globalVariable->IDENTIFIER()->getText(), type));
            }
            else
            {
                module->putGlobalVariable(new base::IRGlobalVariable(module, std::move(attributes),
                                                                     globalVariable->CONST() != nullptr,
                                                                     globalVariable->IDENTIFIER()->getText(),
                                                                     static_cast<value::constant::IRConstant*>(
                                                                         nullptr)));
            }
        }
        for (const auto& func : context->function())
        {
            std::vector<std::string> attributes;
            for (const auto& attribute : func->attribute())
            {
                attributes.emplace_back(parseAttribute(attribute));
            }
            visit(func->type());
            auto* returnType = std::any_cast<type::IRType*>(stack.top());
            stack.pop();
            visit(func->localVariables(0));
            const auto args = std::any_cast<std::vector<function::IRLocalVariable*>>(stack.top());
            stack.pop();
            function::IRFunction* function;
            if (func->EXTERN())
            {
                function = new function::IRFunction(std::move(attributes), returnType, func->IDENTIFIER()->getText(),
                                                    args, func->ELLIPSIS() != nullptr);
            }
            else
            {
                visit(func->localVariables(1));
                const auto locals = std::any_cast<std::vector<function::IRLocalVariable*>>(stack.top());
                stack.pop();
                function = new function::IRFunction(std::move(attributes), returnType,
                                                    func->IDENTIFIER()->getText(),
                                                    args, func->ELLIPSIS() != nullptr, locals,
                                                    new base::IRControlFlowGraph());
            }
            module->putFunction(function);
        }
        for (const auto& structure : context->structure()) visit(structure);
        for (const auto& globalVariable : context->globalVariable()) visit(globalVariable);
        for (const auto& func : context->function()) visit(func);
        return nullptr;
    }

    std::any IRParser::visitGlobalVariable(LGIRGrammarParser::GlobalVariableContext* context)
    {
        if (!context->EXTERN())
        {
            visit(context->constant());
            auto* value = std::any_cast<value::IRValue*>(stack.top());
            auto* constant = dynamic_cast<value::constant::IRConstant*>(value);
            if (constant == nullptr) throw std::runtime_error("Initializer must be a constant");
            module->getGlobalVariable(context->IDENTIFIER()->getText())->setInitializer(constant);
        }
        return nullptr;
    }

    std::any IRParser::visitStructure(LGIRGrammarParser::StructureContext* context)
    {
        visit(context->fields());
        auto fields = std::any_cast<std::vector<structure::IRField*>>(stack.top());
        stack.pop();
        structure::IRStructure* structure = module->getStructure(context->IDENTIFIER()->getText());
        structure->fields = std::move(fields);
        return nullptr;
    }

    std::any IRParser::visitFields(LGIRGrammarParser::FieldsContext* context)
    {
        std::vector<structure::IRField*> fields;
        for (const auto& field : context->field())
        {
            visit(field);
            fields.emplace_back(std::any_cast<structure::IRField*>(stack.top()));
            stack.pop();
        }
        stack.emplace(fields);
        return nullptr;
    }

    std::any IRParser::visitField(LGIRGrammarParser::FieldContext* context)
    {
        visit(context->type());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        stack.emplace(new structure::IRField(type, context->IDENTIFIER()->getText()));
        return nullptr;
    }

    std::any IRParser::visitFunction(LGIRGrammarParser::FunctionContext* context)
    {
        currentFunction = module->getFunction(context->IDENTIFIER()->getText());
        if (!context->EXTERN())
        {
            for (auto* basicBlock : context->basicBlock())
            {
                auto* block = new base::IRBasicBlock(basicBlock->IDENTIFIER()->getText());
                currentFunction->addBasicBlock(block);
            }
            for (auto* basicBlock : context->basicBlock())visit(basicBlock);
            name2Register.clear();
        }
        return nullptr;
    }

    std::any IRParser::visitBasicBlock(LGIRGrammarParser::BasicBlockContext* context)
    {
        auto* block = currentFunction->getBasicBlock(context->IDENTIFIER()->getText());
        builder.setInsertPoint(block);
        for (auto* statement : context->statement())
        {
            visit(statement);
        }
        return nullptr;
    }

    std::any IRParser::visitLocalVariables(LGIRGrammarParser::LocalVariablesContext* context)
    {
        std::vector<function::IRLocalVariable*> fields;
        for (auto* localVariable : context->localVariable())
        {
            visit(localVariable);
            fields.emplace_back(std::any_cast<function::IRLocalVariable*>(stack.top()));
            stack.pop();
        }
        stack.emplace(fields);
        return nullptr;
    }

    std::any IRParser::visitLocalVariable(LGIRGrammarParser::LocalVariableContext* context)
    {
        visit(context->type());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        stack.emplace(new function::IRLocalVariable(module, type, context->IDENTIFIER()->getText()));
        return nullptr;
    }

    std::any IRParser::visitAsm(LGIRGrammarParser::AsmContext* context)
    {
        visit(context->values());
        const auto values = std::any_cast<std::vector<value::IRValue*>>(stack.top());
        stack.pop();
        const auto assembly = context->STRING_LITERAL(0)->getText();
        const auto constraints = context->STRING_LITERAL(1)->getText();
        builder.createAsm(assembly.substr(1, assembly.length() - 2), constraints.substr(1, constraints.length() - 2),
                          values);
        return nullptr;
    }

    std::any IRParser::visitBinaryOperates(LGIRGrammarParser::BinaryOperatesContext* context)
    {
        visit(context->value(0));
        auto* operand1 = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        visit(context->value(1));
        auto* operand2 = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = new value::IRRegister(regName);
        builder.getInsertPoint()->addInstruction(new instruction::IRBinaryOperates(
            parseBinaryOperator(context->binaryOperator()), operand1, operand2, reg));
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitUnaryOperates(LGIRGrammarParser::UnaryOperatesContext* context)
    {
        visit(context->value());
        auto* operand = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = new value::IRRegister(regName);
        builder.getInsertPoint()->addInstruction(new instruction::IRUnaryOperates(
            parseUnaryOperator(context->unaryOperator()), operand, reg));
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitGetElementPointer(LGIRGrammarParser::GetElementPointerContext* context)
    {
        visit(context->value(0));
        auto* ptr = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        std::vector<value::constant::IRIntegerConstant*> indices;
        for (int i = 1; i < context->value().size(); i++)
        {
            visit(context->value(i));
            auto* index = std::any_cast<value::IRValue*>(stack.top());
            stack.pop();
            if (auto* constant = dynamic_cast<value::constant::IRIntegerConstant*>(index))
            {
                indices.push_back(constant);
            }
            else
            {
                throw std::runtime_error("index must be integer constant");
            }
        }
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = builder.createGetElementPointer(ptr, indices, regName);
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitCmp(LGIRGrammarParser::CmpContext* context)
    {
        const base::IRCondition condition = parseCondition(context->condition());
        visit(context->value(0));
        auto* operand1 = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        visit(context->value(1));
        auto* operand2 = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = new value::IRRegister(regName);
        builder.getInsertPoint()->addInstruction(new instruction::IRCompare(condition, operand1, operand2, reg));
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitConditionalJump(LGIRGrammarParser::ConditionalJumpContext* context)
    {
        const base::IRCondition condition = parseCondition(context->condition());
        visit(context->value(0));
        auto* operand1 = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        value::IRValue* operand2;
        if (context->value().size() == 1)
        {
            operand2 = nullptr;
        }
        else
        {
            visit(context->value(1));
            operand2 = std::any_cast<value::IRValue*>(stack.top());
            stack.pop();
        }
        visit(context->label());
        builder.getInsertPoint()->addInstruction(
            new instruction::IRConditionalJump(condition, operand1, operand2,
                                               std::any_cast<base::IRBasicBlock*>(stack.top())));
        stack.pop();
        return nullptr;
    }


    std::any IRParser::visitGoto(LGIRGrammarParser::GotoContext* context)
    {
        visit(context->label());
        builder.createGoto(std::any_cast<base::IRBasicBlock*>(stack.top()));
        stack.pop();
        return nullptr;
    }

    std::any IRParser::visitInvoke(LGIRGrammarParser::InvokeContext* context)
    {
        visit(context->type());
        auto* returnType = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        visit(context->value());
        auto* func = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        visit(context->values());
        auto args = std::any_cast<std::vector<value::IRValue*>>(stack.top());
        stack.pop();
        std::string regName;
        auto* registerName = context->registerName();
        if (registerName) regName = getTargetRegisterName(registerName);
        else regName = "";
        auto* reg = builder.createInvoke(returnType, func, std::move(args), regName);
        if (registerName) name2Register[regName] = reg;
        return nullptr;
    }


    std::any IRParser::visitReturn(LGIRGrammarParser::ReturnContext* context)
    {
        value::IRValue* value;
        if (context->value())
        {
            visit(context->value());
            value = std::any_cast<value::IRValue*>(stack.top());
            stack.pop();
        }
        else
        {
            value = nullptr;
        }
        builder.createReturn(value);
        return nullptr;
    }

    std::any IRParser::visitLoad(LGIRGrammarParser::LoadContext* context)
    {
        visit(context->value());
        auto* ptr = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = builder.createLoad(ptr, regName);
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitStore(LGIRGrammarParser::StoreContext* context)
    {
        visit(context->value(0));
        auto* ptr = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        visit(context->value(1));
        auto* value = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        builder.createStore(ptr, value);
        return nullptr;
    }

    std::any IRParser::visitNop(LGIRGrammarParser::NopContext* context)
    {
        builder.createNop();
        return nullptr;
    }

    std::any IRParser::visitSetRegister(LGIRGrammarParser::SetRegisterContext* context)
    {
        visit(context->value());
        auto* value = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = builder.createSetRegister(value, regName);
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitStackAlloc(LGIRGrammarParser::StackAllocContext* context)
    {
        visit(context->type());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        value::IRValue* size;
        if (context->value())
        {
            visit(context->value());
            size = std::any_cast<value::IRValue*>(stack.top());
            stack.pop();
        }
        else
        {
            size = nullptr;
        }
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = builder.createStackAlloc(type, size, regName);
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitTypeCast(LGIRGrammarParser::TypeCastContext* context)
    {
        visit(context->value());
        auto* source = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        visit(context->type());
        auto* targetType = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = new value::IRRegister(regName);
        builder.getInsertPoint()->addInstruction(
            new instruction::IRTypeCast(parseTypeCastKind(context->typeCastKind()), source, targetType, reg));
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitPhi(LGIRGrammarParser::PhiContext* context)
    {
        std::unordered_map<base::IRBasicBlock*, value::IRValue*> values;
        for (const auto& value : context->phiValue())
        {
            visit(value);
            values.emplace(std::any_cast<std::pair<base::IRBasicBlock*, value::IRValue*>>(stack.top()));
            stack.pop();
        }
        const auto regName = getTargetRegisterName(context->registerName());
        auto* reg = builder.createPhi(std::move(values), regName);
        name2Register[regName] = reg;
        return nullptr;
    }

    std::any IRParser::visitSwitch(LGIRGrammarParser::SwitchContext* context)
    {
        visit(context->value());
        auto* value = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        auto* basicBlock = currentFunction->getBasicBlock(context->label()->IDENTIFIER()->getText());
        std::unordered_map<value::constant::IRIntegerConstant*, base::IRBasicBlock*> cases;
        for (const auto& case_ : context->switchCase())
        {
            visit(case_);
            cases.emplace(
                std::any_cast<std::pair<value::constant::IRIntegerConstant*, base::IRBasicBlock*>>(stack.top()));
            stack.pop();
        }
        builder.createSwitch(value, basicBlock, std::move(cases));
        return nullptr;
    }

    std::any IRParser::visitPhiValue(LGIRGrammarParser::PhiValueContext* context)
    {
        auto* basicBlock = currentFunction->getBasicBlock(context->label()->IDENTIFIER()->getText());
        visit(context->value());
        auto* value = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        stack.emplace(
            std::make_any<std::pair<base::IRBasicBlock*, value::IRValue*>>(std::make_pair(basicBlock, value)));
        return nullptr;
    }

    std::any IRParser::visitSwitchCase(LGIRGrammarParser::SwitchCaseContext* context)
    {
        visit(context->integerConstant());
        auto* value = std::any_cast<value::IRValue*>(stack.top());
        stack.pop();
        auto* constant = dynamic_cast<value::constant::IRIntegerConstant*>(value);
        if (constant == nullptr) throw std::runtime_error("phi value must be integer constant");
        auto* basicBlock = currentFunction->getBasicBlock(context->label()->IDENTIFIER()->getText());
        stack.emplace(std::make_any<std::pair<value::constant::IRIntegerConstant*, base::IRBasicBlock*>>(
            std::make_pair(constant, basicBlock)));
        return nullptr;
    }

    std::any IRParser::visitValues(LGIRGrammarParser::ValuesContext* context)
    {
        std::vector<value::IRValue*> values;
        for (auto value : context->value())
        {
            visit(value);
            values.push_back(std::any_cast<value::IRValue*>(stack.top()));
            stack.pop();
        }
        stack.emplace(values);
        return nullptr;
    }

    std::any IRParser::visitRegister(LGIRGrammarParser::RegisterContext* context)
    {
        auto* reg = name2Register[getTargetRegisterName(context->registerName())];
        visit(context->type());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        if (*(reg->getType()) != *type)
        {
            throw std::runtime_error("register type mismatch");
        }
        stack.pop();
        stack.emplace(std::make_any<value::IRValue*>(reg));
        return nullptr;
    }

    std::any IRParser::visitFunctionReference(LGIRGrammarParser::FunctionReferenceContext* context)
    {
        auto* func = module->getFunction(context->IDENTIFIER()->getText());
        stack.emplace(std::make_any<value::IRValue*>(value::constant::IRFunctionReference::get(func)));
        return nullptr;
    }

    std::any IRParser::visitGlobalReference(LGIRGrammarParser::GlobalReferenceContext* context)
    {
        auto* global = module->getGlobalVariable(context->IDENTIFIER()->getText());
        stack.emplace(std::make_any<value::IRValue*>(value::constant::IRGlobalVariableReference::get(global)));
        return nullptr;
    }

    std::any IRParser::visitLocalReference(LGIRGrammarParser::LocalReferenceContext* context)
    {
        auto* local = currentFunction->getLocalVariable(context->IDENTIFIER()->getText());
        stack.emplace(std::make_any<value::IRValue*>(value::IRLocalVariableReference::get(local)));
        return nullptr;
    }

    std::any IRParser::visitConstants(LGIRGrammarParser::ConstantsContext* context)
    {
        std::vector<value::constant::IRConstant*> constants;
        for (const auto& constant : context->constant())
        {
            visit(constant);
            auto* value = std::any_cast<value::IRValue*>(stack.top());
            stack.pop();
            constants.push_back(dynamic_cast<value::constant::IRConstant*>(value));
        }
        stack.emplace(std::make_any<std::vector<value::constant::IRConstant*>>(std::move(constants)));
        return nullptr;
    }


    std::any IRParser::visitIntegerConstant(LGIRGrammarParser::IntegerConstantContext* context)
    {
        visit(context->integerType());
        auto* type = dynamic_cast<type::IRIntegerType*>(std::any_cast<type::IRType*>(stack.top()));
        stack.pop();
        stack.emplace(
            std::make_any<value::IRValue*>(value::constant::IRIntegerConstant::get(module,
                type, std::stoll(context->INT_NUMBER()->getText()))));
        return nullptr;
    }

    std::any IRParser::visitDecimalConstant(LGIRGrammarParser::DecimalConstantContext* context)
    {
        visit(context->decimalType());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        if (dynamic_cast<type::IRFloatType*>(type) != nullptr)
        {
            stack.push(std::make_any<value::IRValue*>(
                value::constant::IRFloatConstant::get(module, std::stof(context->DECIMAL_NUMBER()->getText()))));
        }
        else if (dynamic_cast<type::IRDoubleType*>(type) != nullptr)
        {
            stack.push(std::make_any<value::IRValue*>(
                value::constant::IRDoubleConstant::get(module, std::stod(context->DECIMAL_NUMBER()->getText()))));
        }
        else
        {
            throw std::runtime_error("decimal constant type mismatch");
        }
        return nullptr;
    }

    std::any IRParser::visitArrayConstant(LGIRGrammarParser::ArrayConstantContext* context)
    {
        visit(context->arrayType());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        auto* arrayType = dynamic_cast<type::IRArrayType*>(type);
        if (arrayType == nullptr) throw std::runtime_error("array constant type mismatch");
        visit(context->constants());
        auto elements = std::any_cast<std::vector<value::constant::IRConstant*>>(stack.top());
        stack.pop();
        stack.emplace(
            std::make_any<value::IRValue*>(
                value::constant::IRArrayConstant::get(module, arrayType, std::move(elements))));
        return nullptr;
    }

    std::any IRParser::visitStructureInitializer(LGIRGrammarParser::StructureInitializerContext* context)
    {
        visit(context->structureType());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        auto* structureType = dynamic_cast<type::IRStructureType*>(type);
        if (structureType == nullptr) throw std::runtime_error("structure constant type mismatch");
        visit(context->constants());
        auto elements = std::any_cast<std::vector<value::constant::IRConstant*>>(stack.top());
        stack.pop();
        stack.emplace(std::make_any<value::IRValue*>(
            value::constant::IRStructureInitializer::get(module, structureType, std::move(elements))));
        return nullptr;
    }

    std::any IRParser::visitStringConstant(LGIRGrammarParser::StringConstantContext* context)
    {
        const auto text = context->STRING_LITERAL()->getText();
        stack.emplace(
            std::make_any<value::IRValue*>(
                value::constant::IRStringConstant::get(module, text.substr(1, text.size() - 2))));
        return nullptr;
    }


    std::any IRParser::visitTypes(LGIRGrammarParser::TypesContext* context)
    {
        std::vector<type::IRType*> types;
        for (const auto& type : context->type())
        {
            visit(type);
            types.push_back(std::any_cast<type::IRType*>(stack.top()));
            stack.pop();
        }
        stack.emplace(types);
        return nullptr;
    }

    std::any IRParser::visitType(LGIRGrammarParser::TypeContext* context)
    {
        visit(context->baseType());
        auto* type = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        for (size_t i = 0; i < context->MULTIPLY().size(); ++i)
        {
            type = type::IRPointerType::get(module, type);
        }
        stack.emplace(std::make_any<type::IRType*>(type));
        return nullptr;
    }

    std::any IRParser::visitIntegerType(LGIRGrammarParser::IntegerTypeContext* context)
    {
        if (context->I1())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getBooleanType()));
        }
        else if (context->I8())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getInt8Type()));
        }
        else if (context->I16())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getInt16Type()));
        }
        else if (context->I32())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getInt32Type()));
        }
        else if (context->I64())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getInt64Type()));
        }
        else if (context->U8())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getUnsignedInt8Type()));
        }
        else if (context->U16())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getUnsignedInt16Type()));
        }
        else if (context->U32())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getUnsignedInt32Type()));
        }
        else if (context->U64())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRIntegerType::getUnsignedInt64Type()));
        }
        else
        {
            throw std::runtime_error("Invalid integer type: " + context->getText());
        }
        return nullptr;
    }

    std::any IRParser::visitDecimalType(LGIRGrammarParser::DecimalTypeContext* context)
    {
        if (context->FLOAT())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRFloatType::get()));
            return nullptr;
        }
        if (context->DOUBLE())
        {
            stack.emplace(std::make_any<type::IRType*>(type::IRDoubleType::get()));
            return nullptr;
        }
        throw std::runtime_error("Invalid decimal type: " + context->getText());
    }

    std::any IRParser::visitArrayType(LGIRGrammarParser::ArrayTypeContext* context)
    {
        visit(context->type());
        auto* base = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        stack.emplace(
            std::make_any<type::IRType*>(
                type::IRArrayType::get(module, base, std::stoll(context->INT_NUMBER()->getText()))));
        return nullptr;
    }

    std::any IRParser::visitStructureType(LGIRGrammarParser::StructureTypeContext* context)
    {
        auto* structure = module->getStructure(context->IDENTIFIER()->getText());
        stack.emplace(std::make_any<type::IRType*>(type::IRStructureType::get(structure)));
        return nullptr;
    }

    std::any IRParser::visitFunctionReferenceType(LGIRGrammarParser::FunctionReferenceTypeContext* context)
    {
        visit(context->types());
        auto types = std::any_cast<std::vector<type::IRType*>>(stack.top());
        stack.pop();
        visit(context->type());
        auto* returnType = std::any_cast<type::IRType*>(stack.top());
        stack.pop();
        const bool isVarArg = (context->ELLIPSIS() != nullptr);
        stack.emplace(
            std::make_any<type::IRType*>(
                type::IRFunctionReferenceType::get(module, returnType, std::move(types), isVarArg)));
        return nullptr;
    }

    std::any IRParser::visitVoidType(LGIRGrammarParser::VoidTypeContext* context)
    {
        stack.emplace(std::make_any<type::IRType*>(type::IRVoidType::get()));
        return nullptr;
    }


    std::any IRParser::visitLabel(LGIRGrammarParser::LabelContext* context)
    {
        stack.emplace(currentFunction->getBasicBlock(context->IDENTIFIER()->getText()));
        return nullptr;
    }

    instruction::IRBinaryOperates::Operator IRParser::parseBinaryOperator(
        LGIRGrammarParser::BinaryOperatorContext* context)
    {
        if (context->ADD()) return instruction::IRBinaryOperates::Operator::ADD;
        if (context->SUB()) return instruction::IRBinaryOperates::Operator::SUB;
        if (context->MUL()) return instruction::IRBinaryOperates::Operator::MUL;
        if (context->DIV()) return instruction::IRBinaryOperates::Operator::DIV;
        if (context->MOD()) return instruction::IRBinaryOperates::Operator::MOD;
        if (context->AND()) return instruction::IRBinaryOperates::Operator::AND;
        if (context->OR()) return instruction::IRBinaryOperates::Operator::OR;
        if (context->XOR()) return instruction::IRBinaryOperates::Operator::XOR;
        if (context->SHL()) return instruction::IRBinaryOperates::Operator::SHL;
        if (context->SHR()) return instruction::IRBinaryOperates::Operator::SHR;
        if (context->USHR()) return instruction::IRBinaryOperates::Operator::USHR;
        throw std::runtime_error("Invalid binary operator: " + context->getText());
    }

    instruction::IRUnaryOperates::Operator IRParser::parseUnaryOperator(
        LGIRGrammarParser::UnaryOperatorContext* context)
    {
        if (context->INC()) return instruction::IRUnaryOperates::Operator::INC;
        if (context->DEC()) return instruction::IRUnaryOperates::Operator::DEC;
        if (context->NOT()) return instruction::IRUnaryOperates::Operator::NOT;
        if (context->NEG()) return instruction::IRUnaryOperates::Operator::NEG;
        throw std::runtime_error("Invalid unary operator: " + context->getText());
    }

    base::IRCondition IRParser::parseCondition(LGIRGrammarParser::ConditionContext* context)
    {
        const std::string text = context->getText();
        if (text == "if_true") return base::IRCondition::IF_TRUE;
        if (text == "if_false") return base::IRCondition::IF_FALSE;
        if (text == "e") return base::IRCondition::E;
        if (text == "ne") return base::IRCondition::NE;
        if (text == "l") return base::IRCondition::L;
        if (text == "le") return base::IRCondition::LE;
        if (text == "g") return base::IRCondition::G;
        if (text == "ge") return base::IRCondition::GE;
        throw std::runtime_error("Invalid condition: " + text);
    }

    instruction::IRTypeCast::Kind IRParser::parseTypeCastKind(LGIRGrammarParser::TypeCastKindContext* context)
    {
        if (context->ZEXT()) return instruction::IRTypeCast::Kind::ZEXT;
        if (context->SEXT()) return instruction::IRTypeCast::Kind::SEXT;
        if (context->TRUNC()) return instruction::IRTypeCast::Kind::TRUNC;
        if (context->INTTOF()) return instruction::IRTypeCast::Kind::INTTOF;
        if (context->FTOINT()) return instruction::IRTypeCast::Kind::FTOINT;
        if (context->INTTOPTR()) return instruction::IRTypeCast::Kind::INTTOPTR;
        if (context->PTRTOINT()) return instruction::IRTypeCast::Kind::PTRTOINT;
        if (context->PTRTOPTR()) return instruction::IRTypeCast::Kind::PTRTOPTR;
        if (context->FEXT()) return instruction::IRTypeCast::Kind::FEXT;
        if (context->FTRUNC()) return instruction::IRTypeCast::Kind::FTRUNC;
        if (context->BITCAST()) return instruction::IRTypeCast::Kind::BITCAST;
        throw std::runtime_error("Invalid type cast kind: " + context->getText());
    }

    std::string IRParser::getTargetRegisterName(LGIRGrammarParser::RegisterNameContext* context)
    {
        if (context->IDENTIFIER()) return context->IDENTIFIER()->getText();
        if (context->INT_NUMBER()) return context->INT_NUMBER()->getText();
        throw std::runtime_error("Invalid register name: " + context->getText());
    }

    std::string IRParser::parseAttribute(LGIRGrammarParser::AttributeContext* context)
    {
        std::string s = context->STRING_LITERAL()->getText();
        return s.substr(1, s.size() - 2);
    }

    IRModule* parse(const std::string& code)
    {
        std::istringstream stream(code);
        antlr4::ANTLRInputStream input(stream);
        return parse(input);
    }

    IRModule* parse(std::istream& stream)
    {
        antlr4::ANTLRInputStream input(stream);
        return parse(input);
    }

    IRModule* parse(antlr4::ANTLRInputStream& stream)
    {
        LGIRGrammarLexer lexer(&stream);
        antlr4::CommonTokenStream tokens(&lexer);
        LGIRGrammarParser grammarParser(&tokens);
        auto program = grammarParser.program();
        auto* module = new IRModule();
        IRParser parser(module);
        parser.visit(program);
        return module;
    }
}
