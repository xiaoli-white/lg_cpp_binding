//
// Created by xiaoli on 2025/11/24.
//

#include <IRParser.h>

#include "dumper.h"

namespace lg::ir::parser
{
    IRParser::IRParser(IRModule* module) : module(module)
    {
    }

    std::any IRParser::visitProgram(LGIRGrammarParser::ProgramContext* context)
    {
        for (auto& func : context->function())
        {
            visit(func->type());
            auto* returnType = std::any_cast<type::IRType*>(stack.top());
            stack.pop();
            visit(func->localVariables(0));
            const auto args = std::any_cast<std::vector<function::IRLocalVariable*>>(stack.top());
            stack.pop();
            visit(func->localVariables(1));
            const auto locals = std::any_cast<std::vector<function::IRLocalVariable*>>(stack.top());
            stack.pop();
            auto* function = new function::IRFunction({}, returnType, func->IDENTIFIER()->getText(), args, locals,
                                                      new base::IRControlFlowGraph());
            module->putFunction(function);
        }
        for (auto& func : context->function())visit(func);
        return nullptr;
    }

    std::any IRParser::visitFunction(LGIRGrammarParser::FunctionContext* context)
    {
        currentFunction = module->getFunction(context->IDENTIFIER()->getText());
        for (auto* basicBlock : context->basicBlock())
        {
            auto* block = new base::IRBasicBlock(basicBlock->IDENTIFIER()->getText());
            currentFunction->addBasicBlock(block);
        }
        for (auto* basicBlock : context->basicBlock())visit(basicBlock);
        name2Register.clear();
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
        stack.emplace(new function::IRLocalVariable(type, context->IDENTIFIER()->getText()));
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


    std::any IRParser::visitGoto(LGIRGrammarParser::GotoContext* context)
    {
        visit(context->label());
        builder.createGoto(std::any_cast<base::IRBasicBlock*>(stack.top()));
        stack.pop();
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


    std::any IRParser::visitIntegerConstant(LGIRGrammarParser::IntegerConstantContext* context)
    {
        visit(context->integerType());
        auto* type = dynamic_cast<type::IRIntegerType*>(std::any_cast<type::IRType*>(stack.top()));
        stack.pop();
        stack.emplace(
            static_cast<value::IRValue*>(new value::constant::IRIntegerConstant(
                type, std::stoll(context->INT_NUMBER()->getText()))));
        return nullptr;
    }


    std::any IRParser::visitIntegerType(LGIRGrammarParser::IntegerTypeContext* context)
    {
        if (context->I1())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getBooleanType()));
        }
        else if (context->I8())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getInt8Type()));
        }
        else if (context->I16())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getInt16Type()));
        }
        else if (context->I32())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getInt32Type()));
        }
        else if (context->I64())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getInt64Type()));
        }
        else if (context->U8())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getUnsignedInt8Type()));
        }
        else if (context->U16())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getUnsignedInt16Type()));
        }
        else if (context->U32())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getUnsignedInt32Type()));
        }
        else if (context->U64())
        {
            stack.emplace(static_cast<type::IRType*>(type::IRIntegerType::getUnsignedInt64Type()));
        }
        else
        {
            throw std::runtime_error("Invalid integer type");
        }
        return nullptr;
    }

    std::any IRParser::visitLabel(LGIRGrammarParser::LabelContext* context)
    {
        std::cout << context->IDENTIFIER()->getText() << std::endl;
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
        throw std::runtime_error("Invalid binary operator");
    }

    instruction::IRUnaryOperates::Operator IRParser::parseUnaryOperator(
        LGIRGrammarParser::UnaryOperatorContext* context)
    {
        if (context->INC()) return instruction::IRUnaryOperates::Operator::INC;
        if (context->DEC()) return instruction::IRUnaryOperates::Operator::DEC;
        if (context->NOT()) return instruction::IRUnaryOperates::Operator::NOT;
        if (context->NEG()) return instruction::IRUnaryOperates::Operator::NEG;
        throw std::runtime_error("Invalid unary operator");
    }

    std::string IRParser::getTargetRegisterName(LGIRGrammarParser::RegisterNameContext* context)
    {
        if (context->IDENTIFIER()) return context->IDENTIFIER()->getText();
        if (context->INT_NUMBER()) return context->INT_NUMBER()->getText();
        throw std::runtime_error("Invalid register name");
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
