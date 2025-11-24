//
// Created by xiaoli on 2025/11/23.
//

#pragma once
#ifndef LG_CPP_BINDING_LG_CPP_BINDING_H
#define LG_CPP_BINDING_LG_CPP_BINDING_H
#include <any>
#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ir.h"

namespace lg::ir
{
    class IRModule;
    class IRBuilder;
    class IRVisitor;
    class IRDumper;

    namespace base
    {
        class IRNode;
        class IRGlobalVariable;
        class IRControlFlowGraph;
        class IRBasicBlock;
        enum class IRCondition;
    }

    namespace type
    {
        class IRType;
        class IRIntegerType;
        class IRFloatType;
        class IRDoubleType;
        class IRStructureType;
        class IRArrayType;
        class IRPointerType;
        class IRVoidType;
    }

    namespace value
    {
        class IRValue;
        class IRRegister;
        class IRFunctionReference;
        class IRGlobalVariableReference;
        class IRLocalVariableReference;

        namespace constant
        {
            class IRConstant;
            class IRIntegerConstant;
            class IRFloatConstant;
            class IRDoubleConstant;
            class IRArrayConstant;
            class IRStringConstant;
            class IRNullptrConstant;
        }
    }

    namespace function
    {
        class IRFunction;
        class IRLocalVariable;
    }

    namespace structure
    {
        class IRStructure;
        class IRField;
    }

    namespace instruction
    {
        class IRInstruction;
        class IRAssembly;
        class IRBinaryOperates;
        class IRUnaryOperates;
        class IRGetElementPointer;
        class IRCompare;
        class IRConditionalJump;
        class IRGoto;
        class IRInvoke;
        class IRReturn;
        class IRLoad;
        class IRStore;
        class IRNop;
        class IRSetRegister;
        class IRStackAllocate;
        class IRTypeCast;
    }

    namespace base
    {
        class IRNode
        {
        public:
            virtual ~IRNode() = default;
            virtual std::any accept(IRVisitor* visitor, std::any additional) = 0;
            virtual std::string toString() = 0;
        };

        class IRGlobalVariable final : public IRNode
        {
        public:
            type::IRType* type;
            std::string name;
            value::constant::IRConstant* initializer = nullptr;
            IRGlobalVariable(type::IRType* type, std::string name,
                             value::constant::IRConstant* initializer);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRControlFlowGraph final
        {
        public:
            function::IRFunction* function = nullptr;
            std::map<std::string, IRBasicBlock*> basicBlocks;
            std::map<IRBasicBlock*, std::vector<IRBasicBlock*>> predecessors;
            std::map<IRBasicBlock*, std::vector<IRBasicBlock*>> successors;
            std::string toString();
        };

        class IRBasicBlock final
        {
        public:
            IRBasicBlock* cfg = nullptr;
            std::string name;
            std::vector<instruction::IRInstruction*> instructions;
            explicit IRBasicBlock(std::string name);
            std::string toString();
        };

        enum class IRCondition
        {
            E,
            NE,
            L,
            LE,
            G,
            GE,
            IF_TRUE,
            IF_FALSE
        };

        std::string conditionToString(IRCondition condition);
    }

    namespace type
    {
        class IRType : public base::IRNode
        {
        };

        class IRIntegerType final : public IRType
        {
        public:
            enum class Size: uint8_t
            {
                OneBit = 1,
                OneByte = 8,
                TwoBytes = 16,
                FourBytes = 32,
                EightBytes = 64
            };

            Size size;
            bool _unsigned;
            IRIntegerType(Size size, bool _unsigned);

            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;

            static IRIntegerType* getUnsignedInt8Type();
            static IRIntegerType* getInt8Type();
            static IRIntegerType* getUnsignedInt16Type();
            static IRIntegerType* getInt16Type();
            static IRIntegerType* getUnsignedInt32Type();
            static IRIntegerType* getInt32Type();
            static IRIntegerType* getUnsignedInt64Type();
            static IRIntegerType* getInt64Type();
            static IRIntegerType* getCharType();
            static IRIntegerType* getBooleanType();
        };

        class IRFloatType final : public IRType
        {
        private:
            IRFloatType() = default;
        public:
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;

            static IRFloatType* get();
        };

        class IRDoubleType final : public IRType
        {
        private:
            IRDoubleType() = default;
        public:
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;

            static  IRDoubleType* get();
        };

        class IRStructureType final : public IRType
        {
        public:
            structure::IRStructure* structure;
            explicit IRStructureType(structure::IRStructure* structure);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRArrayType final : public IRType
        {
        public:
            IRType* base;
            uint64_t size;
            IRArrayType(IRType* base, uint64_t size);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRPointerType final : public IRType
        {
        public:
            IRType* base;
            explicit IRPointerType(IRType* base);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRVoidType : public IRType
        {
        private:
            IRVoidType() = default;
        public:
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;

            static  IRVoidType* get();
        };
    }

    namespace value
    {
        class IRValue : public base::IRNode
        {
        public:
            virtual type::IRType* getType() = 0;
        };

        class IRRegister final : public IRValue
        {
        public:
           instruction::IRInstruction* def = nullptr;
            type::IRType* type;
            std::string name;
            IRRegister(type::IRType* type, std::string name);
            type::IRType* getType() override;
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRFunctionReference final : public IRValue
        {
        public:
            function::IRFunction* function;
            explicit IRFunctionReference(function::IRFunction* function);
            type::IRType* getType() override;
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRGlobalVariableReference final : public IRValue
        {
        public:
            type::IRType* type;
            base::IRGlobalVariable* variable;
            explicit IRGlobalVariableReference(base::IRGlobalVariable* variable);
            type::IRType* getType() override;
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRLocalVariableReference final : public IRValue
        {
        public:
            type::IRType* type;
            function::IRLocalVariable* variable;
            explicit IRLocalVariableReference(function::IRLocalVariable* variable);
            type::IRType* getType() override;
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        namespace constant
        {
            class IRConstant : public IRValue
            {
            };

            class IRIntegerConstant final : public IRConstant
            {
            public:
                type::IRIntegerType* type;
                uint64_t value;
                IRIntegerConstant(type::IRIntegerType* type, uint64_t value);
                type::IRType* getType() override;
                std::any accept(IRVisitor* visitor, std::any additional) override;
                std::string toString() override;
            };

            class IRFloatConstant final : public IRConstant
            {
            public:
                float value;
                explicit IRFloatConstant(float value);
                type::IRType* getType() override;
                std::any accept(IRVisitor* visitor, std::any additional) override;
                std::string toString() override;
            };

            class IRDoubleConstant final : public IRConstant
            {
            public:
                double value;
                explicit IRDoubleConstant(double value);
                type::IRType* getType() override;
                std::any accept(IRVisitor* visitor, std::any additional) override;
                std::string toString() override;
            };

            class IRArrayConstant final : public IRConstant
            {
            public:
                type::IRArrayType* type;
                std::vector<IRConstant*> values;
                IRArrayConstant(type::IRArrayType* type, std::vector<IRConstant*> values);
                type::IRType* getType() override;
                std::any accept(IRVisitor* visitor, std::any additional) override;
                std::string toString() override;
            };

            class IRStringConstant final : public IRConstant
            {
            public:
                type::IRType* type;
                std::string value;
                explicit IRStringConstant(std::string value);
                type::IRType* getType() override;
                std::any accept(IRVisitor* visitor, std::any additional) override;
                std::string toString() override;
            };

            class IRNullptrConstant final : public IRConstant
            {
            public:
                type::IRPointerType* type;
                explicit IRNullptrConstant(type::IRPointerType* type);
                type::IRType* getType() override;
                std::any accept(IRVisitor* visitor, std::any additional) override;
                std::string toString() override;
            };
        }
    }

    namespace function
    {
        class IRFunction final : public base::IRNode
        {
        public:
            std::vector<std::string> attributes;
            type::IRType* returnType;
            std::string name;
            std::vector<IRLocalVariable*> args;
            std::vector<IRLocalVariable*> locals;
            base::IRControlFlowGraph* cfg;
            IRFunction(std::vector<std::string> attributes, type::IRType* returnType, std::string name,
                       std::vector<IRLocalVariable*> args, std::vector<IRLocalVariable*> locals,
                       base::IRControlFlowGraph* cfg);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRLocalVariable final : public base::IRNode
        {
        public:
            type::IRType* type;
            std::string name;
            IRLocalVariable(type::IRType* type, std::string name);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };
    }

    namespace structure
    {
        class IRStructure final : public base::IRNode
        {
        public:
            std::vector<std::string> attributes;
            std::string name;
            std::vector<IRField*> fields;
            IRStructure(std::vector<std::string> attributes, std::string name, std::vector<IRField*> fields);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRField final : public base::IRNode
        {
        public:
            type::IRType* type;
            std::string name;
            IRField(type::IRType* type, std::string name);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };
    }

    namespace instruction
    {
        class IRInstruction : public base::IRNode
        {
        };

        class IRAssembly final : public IRInstruction
        {
        public:
            std::string assembly;
            std::string constraints;
            std::vector<value::IRValue*> operands;
            IRAssembly(std::string assembly, std::string constraints, std::vector<value::IRValue*> operands);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRBinaryOperates final : public IRInstruction
        {
        public:
            enum class Operator
            {
                ADD,
                SUB,
                MUL,
                DIV,
                MOD,
                AND,
                OR,
                XOR,
                SHL,
                SHR,
                USHR
            };

            Operator op;
            value::IRValue* operand1;
            value::IRValue* operand2;
            value::IRRegister* target;
            IRBinaryOperates(Operator op, value::IRValue* operand1, value::IRValue* operand2,
                             value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
            static std::string operatorToString(Operator op);
        };

        class IRUnaryOperates final : public IRInstruction
        {
        public:
            enum class Operator
            {
                INC,
                DEC,
                NOT,
                NEG
            };

            Operator op;
            value::IRValue* operand;
            value::IRRegister* target;
            IRUnaryOperates(Operator op, value::IRValue* operand, value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
            static std::string operatorToString(Operator op);
        };

        class IRGetElementPointer final : public IRInstruction
        {
        public:
            value::IRValue* pointer;
            std::vector<value::IRValue*> indices;
            value::IRRegister* target;
            IRGetElementPointer(value::IRValue* pointer, std::vector<value::IRValue*> indices,
                                value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRCompare final : public IRInstruction
        {
        public:
            base::IRCondition condition;
            value::IRValue* operand1;
            value::IRValue* operand2;
            value::IRRegister* target;
            IRCompare(base::IRCondition condition, value::IRValue* operand1, value::IRValue* operand2,
                      value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRConditionalJump final : public IRInstruction
        {
        public:
            base::IRCondition condition;
            value::IRValue* operand1;
            value::IRValue* operand2;
            base::IRBasicBlock* target;
            IRConditionalJump(base::IRCondition condition, value::IRValue* operand1, value::IRValue* operand2,
                              base::IRBasicBlock* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRGoto final : public IRInstruction
        {
        public:
            base::IRBasicBlock* target;
            explicit IRGoto(base::IRBasicBlock* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRInvoke final : public IRInstruction
        {
        public:
            type::IRType* returnType;
            value::IRValue* func;
            std::vector<value::IRValue*> arguments;
            value::IRRegister* target;
            IRInvoke(type::IRType* returnType, value::IRValue* func,
                     std::vector<value::IRValue*> arguments,
                     value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRReturn final : public IRInstruction
        {
        public:
            value::IRValue* value;
            explicit IRReturn(value::IRValue* value);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRLoad final : public IRInstruction
        {
        public:
            value::IRValue* ptr;
            value::IRRegister* target;
            IRLoad(value::IRValue* ptr, value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRStore final : public IRInstruction
        {
        public:
            value::IRValue* ptr;
            value::IRValue* value;
            IRStore(value::IRValue* ptr, value::IRValue* value);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRNop final : public IRInstruction
        {
        public:
            IRNop();
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRSetRegister final : public IRInstruction
        {
        public:
            value::IRValue* value;
            value::IRRegister* target;
            IRSetRegister(value::IRValue* value, value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRStackAllocate final : public IRInstruction
        {
        public:
            value::IRValue* size;
            value::IRRegister* target;
            IRStackAllocate(value::IRValue* size, value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
        };

        class IRTypeCast final : public IRInstruction
        {
        public:
            enum class Kind
            {
                ZEXT,
                SEXT,
                TRUNC,
                FTOI,
                ITOF,
                ITOP,
                PTOI,
                FEXT,
                FTRUNC
            };

            Kind kind;
            value::IRValue* source;
            type::IRType* targetType;
            value::IRRegister* target;
            IRTypeCast(Kind kind, value::IRValue* source, type::IRType* targetType,
                       value::IRRegister* target);
            std::any accept(IRVisitor* visitor, std::any additional) override;
            std::string toString() override;
            static std::string kindToString(Kind kind);
        };
    }

    class IRBuilder
    {
    private:
        base::IRBasicBlock* insertPoint;

    public:
        void setInsertPoint(base::IRBasicBlock* insertPoint);
        void createReturn();
        void createReturn(value::IRValue* value);
    };

    class IRVisitor
    {
    public:
        virtual ~IRVisitor() = default;
        virtual std::any visit(base::IRNode* node, std::any additional);
        virtual std::any visitModule(IRModule* module, std::any additional);
        virtual std::any visitGlobalVariable(base::IRGlobalVariable* irGlobalVariable, std::any additional);
        virtual std::any visitFunction(function::IRFunction* irFunction, std::any additional);
        virtual std::any visitLocalVariable(function::IRLocalVariable* irLocalVariable, std::any additional);
        virtual std::any visitStructure(structure::IRStructure* irStructure, std::any additional);
        virtual std::any visitField(structure::IRField* irField, std::any additional);
        virtual std::any visitIntegerType(type::IRIntegerType* irIntegerType, std::any additional);
        virtual std::any visitFloatType(type::IRFloatType* irFloatType, std::any additional);
        virtual std::any visitDoubleType(type::IRDoubleType* irDoubleType, std::any additional);
        virtual std::any visitStructureType(type::IRStructureType* irStructureType, std::any additional);
        virtual std::any visitArrayType(type::IRArrayType* irArrayType, std::any additional);
        virtual std::any visitPointerType(type::IRPointerType* irPointerType, std::any additional);
        virtual std::any visitVoidType(type::IRVoidType* irVoidType, std::any additional);
        virtual std::any visitRegister(value::IRRegister* irRegister, std::any additional);
        virtual std::any visitFunctionReference(value::IRFunctionReference* irFunctionReference, std::any additional);
        virtual std::any visitGlobalVariableReference(value::IRGlobalVariableReference* irGlobalVariableReference,
                                                      std::any additional);
        virtual std::any visitLocalVariableReference(value::IRLocalVariableReference* irLocalVariableReference,
                                                     std::any additional);
        virtual std::any visitIntegerConstant(value::constant::IRIntegerConstant* irIntegerConstant,
                                              std::any additional);
        virtual std::any visitFloatConstant(value::constant::IRFloatConstant* irFloatConstant, std::any additional);
        virtual std::any visitDoubleConstant(value::constant::IRDoubleConstant* irDoubleConstant, std::any additional);
        virtual std::any visitArrayConstant(value::constant::IRArrayConstant* irArrayConstant, std::any additional);
        virtual std::any visitStringConstant(value::constant::IRStringConstant* irStringConstant, std::any additional);
        virtual std::any visitNullptrConstant(value::constant::IRNullptrConstant* irNullptrConstant,
                                              std::any additional);
        virtual std::any visitAssembly(instruction::IRAssembly* irAssembly, std::any additional);
        virtual std::any visitBinaryOperates(instruction::IRBinaryOperates* irBinaryOperates, std::any additional);
        virtual std::any visitUnaryOperates(instruction::IRUnaryOperates* irUnaryOperates, std::any additional);
        virtual std::any visitGetElementPointer(instruction::IRGetElementPointer* irGetElementPointer,
                                                std::any additional);
        virtual std::any visitCompare(instruction::IRCompare* irCompare, std::any additional);
        virtual std::any visitConditionalJump(instruction::IRConditionalJump* irConditionalJump, std::any additional);
        virtual std::any visitGoto(instruction::IRGoto* irGoto, std::any additional);
        virtual std::any visitInvoke(instruction::IRInvoke* irInvoke, std::any additional);
        virtual std::any visitReturn(instruction::IRReturn* irReturn, std::any additional);
        virtual std::any visitLoad(instruction::IRLoad* irLoad, std::any additional);
        virtual std::any visitStore(instruction::IRStore* irStore, std::any additional);
        virtual std::any visitNop(instruction::IRNop* irNop, std::any additional);
        virtual std::any visitSetRegister(instruction::IRSetRegister* irSetRegister, std::any additional);
        virtual std::any visitStackAllocate(instruction::IRStackAllocate* irStackAllocate, std::any additional);
        virtual std::any visitTypeCast(instruction::IRTypeCast* irTypeCast, std::any additional);
    };

    class IRModule : public base::IRNode
    {
    public:
        std::map<std::string, base::IRGlobalVariable*> globals;
        std::map<std::string, structure::IRStructure*> structures;
        std::map<std::string, function::IRFunction*> functions;

        ~IRModule() override = default;
        std::any accept(IRVisitor* visitor, std::any additional) override;
        std::string toString() override;
    };
}

#endif //LG_CPP_BINDING_LG_CPP_BINDING_H
