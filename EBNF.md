program: global main_block function

global: decl_list

decl_list: decl_list global_item SEMICOLON | ε

global_item: variable_decl | protoType |  array_decl

main_block: MAIN LEFTP RIGHTP function_body

function: function_list

function_list: function_list function_impl | ε

function_impl: protoType function_body

id: IDENTIFIER

variable_decl: type id | type id ASSIGN expression

array_decl: type id LEFTSB size RIGHTSB | type id LEFTSB RIGHTSB

size: INTEGER_VALUE

protoType: type id LEFTP parameter_decl RIGHTP

parameter_decl: parameters parameter | ε

parameters: parameters parameter COMMA | ε

parameter: variable_decl | array_decl

type: INT | FLOAT | BOOL | VOID | STRING

value: INTEGER_VALUE | FLOAT_VALUE | FALSE | TRUE | STRING_VALUE

function_body: LEFTB stmt_list  expr_return RIGHTB

stmt_list: stmt_list stmt SEMICOLON | stmt_list loop | stmt_list condition | ε

stmt: assignment | func_call | variable_decl | array_decl

assignment: left_id ASSIGN expression

func_call: id LEFTP parameterExprs RIGHTP

parameterExprs: variables expression | ε

variables: variables expression COMMA | ε

loop : for_loop | while_loop

for_loop : FOR LEFTP assignment SEMICOLON relation_expr SEMICOLON assignment RIGHTP LEFTB stmt_list expr_return RIGHTB

while_loop : WHILE LEFTP expression RIGHTP LEFTB stmt_list RIGHTB

condition : IF LEFTP relation_expr RIGHTP LEFTB stmt_list expr_return RIGHTB else_block

else_block : ELSE LEFTB stmt_list expr_return RIGHTB | ε

expression: arith_expr | relation_expr | logic_expr

expr_return: RETURN expression SEMICOLON | RETURN SEMICOLON | SEMICOLON | ε

relation_expr: arith_expr relation_op arith_expr

relation_op: LT | GT | ELT | EGT | NEQ | EQ

logic_expr: logic_expr logic_op logic_term | logic_term

logic_term: LEFTP relation_expr RIGHTP

logic_op: AND | OR

arith_expr: arith_expr ADD term | arith_expr SUB term | term

term: term POW factor | term MUL factor | term DIV factor | factor

left_id: id | id LEFTSB expression RIGHTSB | id LEFTSB RIGHTSB

factor: LEFTP arith_expr RIGHTP | value| func_call | left_id