cmake_minimum_required(VERSION 3.19.2)
project(parser)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_FIND_ROOT_PATH ".")
set(CMAKE_INCLUDE_PATH "./Src/include")

if(NOT DEFINED ENV{LLVM_DIR})
    set(ENV{LLVM_DIR} D:/Compile/llvm-install/llvm-project/build/lib/cmake/llvm)
endif()

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITION})

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(parser
        Src/main.cpp
        Src/src/parser.cpp
        Src/src/AST.cpp
        Src/src/lex.yy.cc
        Src/src/stmt.cpp
        Src/src/expr.cpp
        Src/src/decl.cpp
        Src/src/util.cpp
        Src/src/codeGen.cpp)

llvm_map_components_to_libnames(llvm_libs core orcjit native)

target_link_libraries(parser ${llvm_libs})
message(STATUS "FIND ${llvm_libs}")