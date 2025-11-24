cmake_minimum_required(VERSION 4.0)
project(lg_cpp_binding)

set(CMAKE_CXX_STANDARD 20)

find_path(ANTLR4_INCLUDE_DIR antlr4-runtime.h
        PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)

find_package(antlr4-runtime REQUIRED)


add_library(lg_cpp_binding SHARED
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
)
include_directories(${ANTLR4_INCLUDE_DIR} include/)

target_link_libraries(lg_cpp_binding antlr4-runtime)