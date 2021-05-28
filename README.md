# Compiler-Principle-Project

ZJU compiler principle project

## 运行说明

#### 1.测试命令

命令行输入:
win_bison -d -o parser.cpp yacc.y
win_flex -+ lex.l
g++ -o parser main.cpp parser.cpp lex.yy.cc AST.cpp

#### 2.g++编译问题记录：

- 需要手动修改lex.yy.cc中#include <FlexLexer.h> 为 #include "FlexLexer.h"
- no reference to yylex：g++编译lex文件不直接提供yylex实现体，需要手动修改parser.cpp中的yyparser定义为yyparser(yyFlexLexer* yyflex)，并修改调用yylex函数为yyflex->yylex

## 具体实现

### 1.EBNF定义

### 2.AST解释说明

从属关系定义：

```json
{
Stmt:{
stmtType: Decl | Assign | FuncCall | Expr | Return
}

Decl:{
declType: Variable | ProtoType | Params
}

Expr:{
valueType: Bool | Int | Void | Float
exprType: ID | Value | BinaryExpr
}

}
```
