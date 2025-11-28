cmake_minimum_required(VERSION 4.0)
project(lg_cpp_binding)

set(CMAKE_CXX_STANDARD 20)

find_package(antlr4-runtime REQUIRED)

include_directories(${ANTLR4_INCLUDE_DIR} include/)

add_library(lg SHARED
        src/lexer/LGIRGrammarParser.cpp
        src/lexer/LGIRGrammarListener.cpp
        src/lexer/LGIRGrammarLexer.cpp
        src/lexer/LGIRGrammarBaseListener.cpp
        include/lexer/LGIRGrammarLexer.h
        include/lexer/LGIRGrammarBaseListener.h
        src/ir.cpp
        include/ir.h
        include/lg-cpp-binding.h
        include/builder.h
        src/builder.cpp
        include/dumper.h
        src/dumper.cpp
        src/IRParser.cpp
        include/IRParser.h
        src/lexer/LGIRGrammarBaseVisitor.cpp
        src/lexer/LGIRGrammarVisitor.cpp
        include/lexer/LGIRGrammarBaseVisitor.h
)
add_executable(lg_cpp_binding_test
        src/test.cpp
)

target_link_libraries(lg antlr4-runtime)
target_link_libraries(lg_cpp_binding_test antlr4-runtime lg)
