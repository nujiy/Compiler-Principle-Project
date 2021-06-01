# Compiler-Principle-Project

ZJU compiler principle project

## ==本分支用来修改词法语法分析器==

## ==Grammar已经修改，稍后修改词法语法分析器==

## 运行说明

#### 1.测试命令
命令行输入:
测试文件testfile需要与exe置于同一目录下
win_bison --defines=../include/parser.h -o parser.cpp yacc.ypp
win_flex -+ lex.l
g++ -o parser main.cpp parser.cpp lex.yy.cc AST.cpp

#### 2.g++编译问题记录：
- 需要手动修改lex.yy.cc中#include <FlexLexer.h> 为 #include "FlexLexer.h"
- no reference to yylex：g++编译lex文件不直接提供yylex实现体，需要手动修改parser.cpp中的yyparser定义为yyparser(yyFlexLexer* yyflex)，并修改调用yylex函数为yyflex->yylex

## 具体实现
### 1. 内容列表
- 语法
    - [x] 变量声明
    - [ ] 类型声明: 考虑结构体
    - [x] 函数声明
    - [x] 数组声明以及访问
    - [x] 赋值语句
    - [x] 算数表达式
    - [x] 逻辑运算表达式
    - [x] 函数调用
    - [x] 循环语句
    - [x] 分支语句
- 未完成
    - [ ] 类型检查
    - [ ] 作用域  
    - [ ] 生成符号表
    - [ ] 中间代码生成
    - [ ] 目标代码生成

### 2.EBNF定义

### 3.AST解释说明

从属关系定义：

```
{
Stmt:{
stmtType: Decl | Assign | Expr | Return
}

Decl:{
declType: Variable | ProtoType | Params
}

Expr:{
valueType: Bool | Int | Void | Float
exprType: ID | Value | BinaryExpr | FuncCall
}

}
```