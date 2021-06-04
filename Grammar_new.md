

👇增加数组操作，修改赋值，可以赋一组值

```
	<id> -> IDENTIFIER 

	<basictype> -> INT | FLOAT | BOOL | VOID | STRING


<variable_decl> -> <basictype> <variable> <assignment_initial>
<assignment_initial> -> = <expression> | { <array_data> } | ε
<array_data> -> <expression> <array_data_closure> | ε
<array_data_closure> -> ,<expression> <array_data_closure> | ε
//可以给数组赋一组初值

👇暂时不需要，如果加上，也只能实现 int a = 0， int b 这样子的效果
  至于如何实现 int a, b我还没做好
//<decl> -> <variable_decl> <decl_closure> | ε
//<decl_closure> -> ,<variable_decl> <decl_closure> |ε
//下面这个定义是原来的定义，我认为是有问题的
//<variables> -> variables id  COMMA| e 

<variable> -> <id> <array>
<array> -> [<expression>] | ε
```

👆修改type 为 basictype，为以后的结构体或者指针做准备



```
	<parameter_decl> -> <variable_decl> <parameters> | ε 
	<parameters> -> ,<variable_decl> <parameters> | ε 


<func_call> -> <id> ( <parameterID_list> ) 
<parameterID_list> -> <expression> <parameterIDs> | ε
<parameterIDs> -> ,<expression> <parameterIDs> | ε


	<function> -> <function_list> 
	<function_list> -> <function_list> <function_impl> 
	<function_impl> -> <protoType> <function_body> 
	<function_body> -> { <stmt_list> <stmt_return> }

	<stmt_return> -> return <expression> ;
```



```
	<stmt_list> -> <stmt_list> <stmt> ; | ε

	<stmt> -> <assignment> | <func_call> | <variable_decl> | <loop> | <condition> | <stmt_print> | <stmt_scan> | <condition_with_otherwise>

<assignment> -> <variable> = <expression>
```





```
	<loop> -> <for_loop> | <while_loop>

	<for_loop> -> FOR (<assignment>; <expression> ; <assignment> ) { <stmt_list> }

	<while_loop> -> WHILE ( <expression> ) { <stmt_list> }

//break要不要加进去
```



```
<condition> -> IF ( <expresion> ) { <stmt_list> } <o
			 | IF ( <expresion> ) { <stmt_list> } ELSE { <stmt_list> }

```



*做保留字*

```
 //打印的时候只能打印一个表达式
 <stmt_print> -> PRINT ( <> ，)
 
 //读的时候只能读一个变量
 <stmt_scan> -> SCAN ( <variable> )
```









```
	<program> -> <global> <main_block> <function>

	<main_block> -> MAIN ( ) <function_body> 

	<global> -> <decl_list>
	<decl_list> -> <decl_list> <global_item> ;
	<global_item> -> <variable_decl> | <protoType> 

	<protoType> -> <basictype> <id> ( <parameter_decl> )
```





```
<expression> -> <arith_expr> | <relation_expr> | <logic_expr>


<logic_expr> ->  <arith_expr>  <logic_op>  <arith_expr>

<logic_op> -> LT | GT | EQ | NEQ | EGT | ELT

<relation_expr> -> <logic_expr>  <relation_op>  <logic_expr> 

<realation_op> -> AND | OR



<arith_expr> -> <arith_expr> ADD <term> | <arith_expr> SUB <term> | <term>

<term> -> <term> POW <factor> | <term> MUL <factor> | <term> DIV <factor> | <factor>

<factor> -> ( <arith_expr> ) | <value> | <variable> | <func_call>


<value> -> <INTEGER_VALUE> | <FLOAT_VALUE> 
<INTEGER_VALUE> -> -?(0|[1-9][0-9]*)
<FLOAT_VALUE> ->[0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?
```

