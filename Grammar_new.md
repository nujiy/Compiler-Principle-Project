```
<program> -> <global> <main_block> <function>

<global> -> <decl_list>

<decl_list> -> <decl_list> <global_item> ;

<global_item> -> <variable_decl> | <protoType> 

<protoType> -> <basictype> <id> ( <parameter_decl> )
```

```
<id> -> IDENTIFIER 

variable_decl: type id | type id ASSIGN expression 




```





~~array_decl: type id '[' size ']' | type id '[' size ']' // to test~~

~~size: INT~~ 



parameter_decl:parameters variable_decl | e 

parameters: parameters variable_decl | e 

<basictype> -> INT | FLOAT | BOOL | CHAR | VOID

main_block: MAIN ( ) function_body 

function: function_list 

function_list: function_list function_impl 

function_impl: protoType function_body 

function_body: { stmt_list stmt_return }



```
<stmt_list> -> <stmt_list> <stmt> ; | ε

<stmt> -> <assignment> | <func_call> | <variable_decl> | <loop> | <condition>
//variable decl 
```



func_call: id LEFTP parameterIDs RIGHTP 

parameterIDs: variables id | e 

variables: variables id COMMA | e 

assignment: id ASSIGN expression



```
<expression> -> <arith_expr> | <relation_expr> | <logic_expr>

<logic_expr> -> <arith_expr> <logic_op> <arith_expr> 

<logic_op> -> LT | GT | EQ | NEQ | EGT | ELT

<relation_expr> -> <logic_expr> <relation_op> <logic_expr> 

<realation_op> -> AND | OR

<arith_expr> -> <arith_expr> ADD <term> | <arith_expr> SUB <term> | <term>

<term> -> <term> POW <factor> | <term> MUL <factor> | <term> DIV <factor> | <factor>

<factor> -> ( <arith_expr> ) | <value> | <id> | <func_call>

<value> -> <INTEGER_VALUE> | <FLOAT_VALUE> | <CHAR_VALUE>
<INTEGER_VALUE> -> -?(0|[1-9][0-9]*)
<FLOAT_VALUE> ->[0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?
```





```
<loop> -> <for_loop> | <while_loop>

<for_loop> -> FOR (<> <>;<>) { <stmt_list> }

<while_loop> -> WHILE ( <expression> ) { <stmt_list> }
```



```
<condition> -> if ( <expresion> ) { <stmt_list> } <otherwise>

<otherwise> -> ELSE { <stmt_list> } | ε
```

