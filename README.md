# Compiler-Principle-Project

ZJU compiler principle project

## 运行调试说明

#### 1.测试命令
flex和bison编译:
win_bison --defines=../include/parser.hpp -o parser.cpp yacc.ypp
win_flex -+ lex.l

#### 2.编译问题记录：
- 需要手动修改lex.yy.cc中#include <FlexLexer.h> 为 #include "FlexLexer.h"
- no reference to yylex：g++编译lex文件不直接提供默认yylex，需要手动修改parser.cpp中的yyparser定义为yyparser(yyFlexLexer* yyflex)，并修改调用yylex函数为yyflex->yylex

#### 3.运行命令
编译:cmake
生成IR:parser <filename>
- 将IR转换为bitcode:llvm-as test.ll -o test.bc
- lli读入bitcode运行:lli test.bc
生成可执行文件:
- 转汇编:llc test.bc -o test.s
- 链接:g++ test.s -o test 
  g++ test.s -o test

## 具体实现
### 1. 内容列表
- 语法
    - [x] 变量声明
    - [x] 函数声明
    - [x] 数组声明
    - [x] 赋值语句
    - [x] 算数表达式、关系运算表达式、逻辑运算表达式
    - [x] 函数调用
    - [x] 循环语句
    - [x] 分支语句
    - [x] 输入输出 
    - [x] 类型检查
    - [x] 中间代码生成
    - [x] 目标代码生成


### 3.AST解释说明

从属关系定义：
Stmt:Decl | Expr | Assignment | Condition | Loop
Decl: Variable | Array | ProtoType
Expr: Identifier | FuncCall | ArrayExpr | BinaryExpr | Value

## 参考资料
[llvm doc](https://llvm-tutorial-cn.readthedocs.io/en/latest/)
[llvm doc中文翻译](https://kaleidoscope-llvm-tutorial-zh-cn.readthedocs.io/zh_CN/latest/chapter-3.html#id9)