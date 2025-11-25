//
// Created by xiaoli on 2025/11/24.
//

#pragma once
#ifndef LG_CPP_BINDING_DUMPER_H
#define LG_CPP_BINDING_DUMPER_H

#include <ir.h>

namespace lg::ir
{
    class IRDumper;

    class IRDumper final : public IRVisitor
    {
    private:
        std::ostream& out;
    public:
        IRDumper();
        explicit IRDumper(std::ostream& out);
        std::any visitGlobalVariable(base::IRGlobalVariable* irGlobalVariable, std::any prefix) override;
        std::any visitStructure(structure::IRStructure* irStructure, std::any prefix) override;
        std::any visitFunction(function::IRFunction* irFunction, std::any prefix) override;
    };
}

#endif //LG_CPP_BINDING_DUMPER_H