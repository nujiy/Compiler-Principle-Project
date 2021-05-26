%{
#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

AST* program; // total program

extern int yyparse();
int yyerror(const char* s);
int yywrap();
%}

%union
{
	Block* block;

	DataType* dataType;
	Decl* declaration;
	DeclList* declList;
	ParamsList* paramList;
	Stmt* stmt;
	StmtList* stmtList;
	Expr* expr; 
	FuncBody* funcbody;
	FuncImpl* funcImpl;
	FuncList* funcList;
	char Char;
	char Op;
	char* txt;

	IdentifierList* idList;
	vector<Decl*>* declVector;
}

%token SEMICOLON COMMA LEFTP RIGHTP  LEFTB RIGHTB
%token MAIN  RETURN FOR WHILE IF ELSE
%token <expr> IDENTIFIER 
%token <txt> INT FLOAT BOOL
%token <txt> INTEGER_VALUE FLOAT_VALUE BOOL_VALUE

%token ASSIGN GT LT EQ NEQ
%left <Op> ADD SUB
%left <Op> MUL DIV
%left <Op> POW

%type <block> global main_block function
%type <declaration> global_item protoType variable_decl
%type <declList> decl_list
%type <paramList> parameter_decl
%type <declVector> parameters
%type <dataType> type
%type <expr> value
%type <expr> expression term factor
%type <idList> variables parameterIDs
%type <stmt> stmt stmt_return assignment func_call
%type <stmtList> stmt_list
%type <funcbody> function_body
%type <funcImpl> function_impl
%type <funcList> function_list
%start program
%%

program: global main_block function {program = new AST($1,$2,$3);}
		;

global:  decl_list {$$ = new GlobalPart($1);}
			;

decl_list: decl_list global_item SEMICOLON {$$->addDecl($2); $$ = $1;}
			| {$$ = new DeclList();}
			;

main_block: MAIN LEFTP RIGHTP function_body {$$ = new MainPart($4);};

function: function_list {$$ = new FuncPart($1);}

function_list: function_list function_impl {$1->addFunction($2); $$ = $1;}
		| {$$ = new FuncList();}
		;

function_impl: protoType function_body {$$ = new FuncImpl($1,$2);}
		;

global_item: variable_decl {$$ = $1;}
		|	protoType {$$ = $1;}
		;

variable_decl: type IDENTIFIER	{$$ = new VariableDecl($1,$2);}
		| type IDENTIFIER value {$$ = new VariableDecl($1,$2,$3);}
		;

protoType: type IDENTIFIER LEFTP parameter_decl RIGHTP {$$ = new ProtoType($1,$2,$4);}	
		;

parameter_decl: parameters variable_decl {$$ = new ParamsList(*$1); $$->addParam($2);}
		| {$$ = new ParamsList();}
		;

parameters: parameters variable_decl COMMA {$1->push_back($2); $$ = $1;}
		| {$$ = new vector<Decl*>();}
		;

type: INT {$$ = new DataType($1);}
	| FLOAT {$$ = new DataType($1);}
	| BOOL {$$ = new DataType($1);}
	;

value: INTEGER_VALUE {$$ = new Integer(atoi($1));}
	| FLOAT_VALUE {$$ = new Float(atof($1));}
	;

function_body: LEFTB stmt_list  stmt_return RIGHTB {$$ = new FuncBody($2,$3);}
		;

stmt_return: RETURN value SEMICOLON {$$ = $2;}
		| RETURN SEMICOLON {$$ = new Void();}
		| SEMICOLON {$$ = new Void();}
		| {$$ = new Void();}
		;

stmt_list: stmt_list stmt SEMICOLON {$1->addStmt($2); $$ = $1;}
		| {$$ = new StmtList();}
		;

stmt: assignment {$$ = $1;}
	| func_call {$$ = $1;}
	;

assignment: IDENTIFIER ASSIGN expression {$$ = new Assignment($1,$3);}
		;

func_call: IDENTIFIER LEFTP parameterIDs RIGHTP {$$ = new FuncCall($1,$3);}
		;

parameterIDs: variables IDENTIFIER {$1->addIdentifier($2); $$ = $1;}
		| {$$ = new IdentifierList();}
		;

variables: variables IDENTIFIER COMMA {$1->addIdentifier($2); $$ = $1;}
		| {$$ = new IdentifierList();}
		;

expression: expression ADD term {$$ = new BinaryExpr($1,$3,OPADD);}
	| expression SUB term {$$ = new BinaryExpr($1,$3,OPSUB);}
	| term {$$ = $1;}
	;

term: term POW factor {$$ = new BinaryExpr($1,$3,OPPOW); }
	| term MUL factor {$$ = new BinaryExpr($1,$3,OPMUL); }
	| term DIV factor {$$ = new BinaryExpr($1,$3,OPDIV); }
	| factor {$$ = $1; }
	;

factor: LEFTP expression RIGHTP {$$ = $2; }
	| value {$$ = $1;}
	| IDENTIFIER {$$ = $1;}
	;

%%

int yywrap(){
	return 1;
}

int yyerror(const char *s){
	cout<<s<<endl;
	return 0;
}