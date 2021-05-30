# Compiler-Principle-Project

ZJU compiler principle project

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
    - [x] 数组声明
    - [x] 赋值语句
    - [x] 算数表达式
    - [x] 逻辑运算表达式
    - [x] 函数调用
    - [ ] 循环语句
    - [ ] 分支语句
- 未完成
    - [ ] 类型检查
    - [ ] 作用域  
    - [ ] 生成符号表
    - [ ] 中间代码生成
    - [ ] 目标代码生成

### 2.EBNF定义
program: global main_block function
global: decl_list
decl_list: decl_list global_item SEMICOLON
global_item: variable_decl | protoType
id: IDENTIFIER
array_decl: type id '[' size ']' | type id '[' size ']' // to test
size: INT
variable_decl: type id | type id ASSIGN expression
protoType: type id LEFTP parameter_decl RIGHTP
parameter_decl:parameters variable_decl | e
parameters: parameters variable_decl | e 
type: INT | FLOAT | BOOL
main_block: MAIN LEFTP RIGHTP function_body
function: function_list
function_list: function_list function_impl
function_impl: protoType function_body
function_body: LEFTB stmt_list stmt_return RIGHTB
stmt_list: stmt_list stmt SEMICOLON | e
stmt: assignment | func_call | variable_decl
func_call: id LEFTP parameterIDs RIGHTP
parameterIDs: variables id | e
variables: variables id COMMA | e
assignment: id ASSIGN expression

expression: arith_expr | relation_expr | logic_expr

logic_expr: arith_expr logic_op arith_expr
logic_op: LT GT EQ NEQ EGT ELT 

relation_expr: logic_expr relation_op logic_expr
realation_op: AND OR 

arith_expr: arith_expr ADD term
            | arith_expr SUB term
            | term

term: term POW factor
        | term MUL factor
        | term DIV factor
        | factor

factor: LEFTP arith_expr RIGHTP
        | value
        | id
        | func_call

value: INTEGER_VALUE | FLOAT_VALUE
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