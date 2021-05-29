cmake_minimum_required(VERSION 3.19.2)
project(parser)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_FIND_ROOT_PATH ".")
set(CMAKE_INCLUDE_PATH "./Src/include")
add_executable(parser
        Src/main.cpp
        Src/src/parser.cpp
        Src/src/AST.cpp
        Src/src/lex.yy.cc
        Src/src/stmt.cpp
        Src/src/expr.cpp
        Src/src/decl.cpp
        Src/src/util.cpp)