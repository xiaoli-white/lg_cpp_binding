//
// Created by xiaoli on 2025/11/25.
//

#include <dumper.h>
#include <string>

#include "IRParser.h"

int main(int argc, char* argv[])
{
    std::string code = "function i32 main(i32 a, i32 b){i32 c, i32 d}{entry:asm \"mov rax, 1\",\"\"() goto label exit exit: return i32 1}";
    auto module = lg::ir::parser::parse(code);
    lg::ir::IRDumper dumper;
    dumper.visitModule(module, std::string(""));
    return 0;
}
