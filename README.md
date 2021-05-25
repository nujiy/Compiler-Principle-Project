# Compiler-Principle-Project
ZJU compiler principle project 

测试命令
命令行输入:
win_bison -d -o parser.cpp yacc.y
win_flex -+ lex.l
g++ -o parser main.cpp parser.cpp lex.yy.cc AST.cpp

需要手动修改#include <FlexLexer.h> 为 #include "FlexLexer.h"