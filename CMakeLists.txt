cmake_minimum_required(VERSION 3.19)
project(Compiler_Principle_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

include_directories("F:\\SoftWarePackage\\Class\\CP\\usr\\local\\include")

add_executable(Compiler_Principle_Project
        AST.cpp
        AST.h
        lex.yy.cc
        main.cpp
        parser.cpp
        parser.hpp)
