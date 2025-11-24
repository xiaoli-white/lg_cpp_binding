//
// Created by xiaoli on 2025/11/24.
//

#pragma once
#ifndef LG_CPP_BINDING_BUILDER_H
#define LG_CPP_BINDING_BUILDER_H

#include <ir.h>

namespace lg::ir
{
    class IRBuilder
    {
    private:
        base::IRBasicBlock* insertPoint = nullptr;

    public:
        IRBuilder() = default;
        void setInsertPoint(base::IRBasicBlock* insertPoint);
        void createReturn();
        void createReturn(value::IRValue* value);
    };
}

#endif //LG_CPP_BINDING_BUILDER_H
