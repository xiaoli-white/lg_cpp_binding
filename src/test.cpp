//
// Created by xiaoli on 2025/11/25.
//

#include <dumper.h>
#include <string>

#include "IRParser.h"

int main(int argc, char* argv[])
{
    std::string code = R"(function i32 main(i32 a, i32 b){i32 c, i32 d}{entry: %1 = add i32 1, i32 2 asm "mov rax, 1",""() %3 = getelementptr i32** %1, i32 1, i32 2 goto label exit exit: return i32 %1})";
    std::string c = "function i32 main(){}{"
                    "entry:"
                    "\t%1 = add i32 1, i32 2"
                    "\t%2 = cmp e, i32 %1, i32 3"
                    "\tconditional_jump e, i32 %1, i32 3, label exit "
                    "exit:"
                    "\tnop"
                    "\tinvoke void i32 %1()"
                    "\treturn i32 %1"
                    "}";
    auto* module = lg::ir::parser::parse(c);
    lg::ir::IRDumper dumper;
    dumper.visitModule(module, std::string(""));
    delete module;
    return 0;
}
