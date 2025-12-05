cmake_minimum_required(VERSION 4.0)
project(lg-cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(antlr4-runtime REQUIRED)

include_directories(${ANTLR4_INCLUDE_DIR} include/)

add_library(lg SHARED
        src/lexer/LGIRGrammarParser.cpp
        src/lexer/LGIRGrammarListener.cpp
        src/lexer/LGIRGrammarLexer.cpp
        src/lexer/LGIRGrammarBaseListener.cpp
        include/lg/lexer/LGIRGrammarLexer.h
        include/lg/lexer/LGIRGrammarBaseListener.h
        src/ir.cpp
        include/lg/ir.h
        include/lg/builder.h
        src/builder.cpp
        include/lg/dumper.h
        src/dumper.cpp
        src/parser.cpp
        include/lg/parser.h
        src/lexer/LGIRGrammarBaseVisitor.cpp
        src/lexer/LGIRGrammarVisitor.cpp
        include/lg/lexer/LGIRGrammarBaseVisitor.h
)
add_executable(lg-cpp_test
        src/test.cpp
)

target_link_libraries(lg antlr4-runtime)
target_link_libraries(lg-cpp_test lg)
