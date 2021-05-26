# Compiler-Principle-Project
ZJU compiler principle project 

测试命令
命令行输入:
win_bison -d -o parser.cpp yacc.y
win_flex -+ lex.l
g++ -o parser main.cpp parser.cpp lex.yy.cc AST.cpp

g++编译问题记录：
- 需要手动修改lex.yy.cc中#include <FlexLexer.h> 为 #include "FlexLexer.h"
- no reference to yylex：g++编译lex文件不直接提供yylex实现体，需要手动为yyparser函数传入参数，并修改yylex函数为yyflex->yylex
- no reference to yywrap：g++编译lex文件不提供类中实现，需要自定义yywrap实现或者是直接为FlexLexer.h中的类内成员函数提供实现。