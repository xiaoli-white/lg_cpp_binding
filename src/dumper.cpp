//
// Created by xiaoli on 2025/11/24.
//

#include <dumper.h>
#include <iostream>

namespace lg::ir
{
    IRDumper::IRDumper() : out(std::cout)
    {
    }

    IRDumper::IRDumper(std::ostream& out) : out(out)
    {
    }

    std::any IRDumper::visitGlobalVariable(base::IRGlobalVariable* irGlobalVariable, std::any prefix)
    {
        out << std::any_cast<std::string>(prefix) << irGlobalVariable->toString() << std::endl;
        return nullptr;
    }

    std::any IRDumper::visitStructure(structure::IRStructure* irStructure, std::any prefix)
    {
        const auto pre = std::any_cast<std::string>(prefix);
        out << pre;
        for (const auto& attribute : irStructure->attributes) out << "__attribute__(\"" << attribute << "\") ";
        out << "structure " << irStructure->name << " {" << std::endl;
        for (int i = 0; i < irStructure->fields.size(); ++i)
        {
            out << pre << "\t" << irStructure->fields[i]->toString();
            if (i < irStructure->fields.size() - 1) out << ",";
            out << std::endl;
        }
        out << pre << "}";
        return nullptr;
    }

    std::any IRDumper::visitFunction(function::IRFunction* irFunction, std::any prefix)
    {
        const auto pre = std::any_cast<std::string>(prefix);
        out << pre;
        for (const auto& attribute : irFunction->attributes) out << "__attribute__(\"" << attribute << "\") ";
        if (irFunction->isExtern) out << "extern ";
        out << "function " << irFunction->returnType->toString() << " " << irFunction->name << "(";
        for (int i = 0; i < irFunction->args.size(); ++i)
        {
            out << irFunction->args[i]->toString();
            if (irFunction->isVarArg || (i != irFunction->args.size() - 1)) out << ", ";
        }
        if (irFunction->isVarArg) out << "...";
        out << ")";
        if (irFunction->isExtern)
        {
            out << std::endl;
        }
        else
        {
            out << " {" << std::endl;
            for (int i = 0; i < irFunction->locals.size(); ++i)
            {
                out << pre << "\t" << irFunction->locals[i]->toString();
                if (i < irFunction->locals.size() - 1) out << ",";
                out << std::endl;
            }
            out << pre << "} {" << std::endl;
            for (auto& [name, basicBlock] : irFunction->cfg->basicBlocks)
            {
                out << pre << "\t" << name << ":" << std::endl;
                for (auto& instruction : basicBlock->instructions)
                {
                    out << pre << "\t\t" << instruction->toString() << std::endl;
                }
            }
            out << pre << "}" << std::endl;
        }
        return nullptr;
    }
}
