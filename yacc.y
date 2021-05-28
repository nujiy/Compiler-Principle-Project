%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
#include "AST.h"
#include "FlexLexer.h"
using namespace std;

AST* program; // total program
extern int yyparse(yyFlexLexer* yyflex);
int yyerror(const char* s);
%}

%union
{
	Block* block;

	int dataType;
	Decl* declaration;
	DeclList* declList;
	ParamsList* paramList;
	Stmt* stmt;
	StmtList* stmtList;
	Expr* expr;
	ExprList* exprList;
	FuncBody* funcbody;
	FuncImpl* funcImpl;
	FuncList* funcList;
	char Char;
	char Op;
	char* txt;
    string* Str;
	vector<Decl*>* declVector;
}

%token SEMICOLON COMMA LEFTP RIGHTP  LEFTB RIGHTB
%token MAIN  RETURN FOR WHILE IF ELSE
%token <Str> IDENTIFIER
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
%type <expr> id value func_call
%type <expr> expression term factor
%type <exprList> variables parameterExprs
%type <stmt> stmt stmt_return assignment
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
		;

function_list: function_list function_impl {$1->addFunction($2); $$ = $1;}
		| {$$ = new FuncList();}
		;

function_impl: protoType function_body {$$ = new FuncImpl($1,$2);}
		;

global_item: variable_decl {$$ = $1;}
		|	protoType {$$ = $1;}
		;

id: IDENTIFIER {$$ = new Identifier(*$1);}
    ;

variable_decl: type id	{$$ = new VariableDecl($1,$2);}
		| type id ASSIGN expression {$$ = new VariableDecl($1,$2,$4);}
		;

protoType: type id LEFTP parameter_decl RIGHTP {$$ = new ProtoType($1,$2,$4);}
		;

parameter_decl: parameters variable_decl {$$ = new ParamsList(*$1); $$->addParam($2);}
		| {$$ = new ParamsList();}
		;

parameters: parameters variable_decl COMMA {$1->push_back($2); $$ = $1;}
		| {$$ = new vector<Decl*>();}
		;

type: INT {$$ = VALUEINT;}
	| FLOAT {$$ = VALUEFLOAT;}
	| BOOL {$$ = VALUEBOOL;}
	;

value: INTEGER_VALUE {$$ = new Integer(atoi($1));}
	| FLOAT_VALUE {$$ = new Float(atof($1));}
	;

function_body: LEFTB stmt_list  stmt_return RIGHTB {$$ = new FuncBody($2,$3);}
		;

stmt_return: RETURN expression SEMICOLON {$$ = $2;}
		| RETURN SEMICOLON {$$ = new Void();}
		| SEMICOLON {$$ = new Void();}
		| {$$ = new Void();}
		;

stmt_list: stmt_list stmt SEMICOLON {$1->addStmt($2); $$ = $1;}
		| {$$ = new StmtList();}
		;

stmt: assignment {$$ = $1;}
	| func_call {$$ = $1;}
	| variable_decl {$$ = $1;}
	;

assignment: id ASSIGN expression {$$ = new Assignment($1,$3);}
		;

func_call: id LEFTP parameterExprs RIGHTP {$$ = new FuncCall($1,$3);}
		;

parameterExprs: variables expression {$1->addExpr($2); $$ = $1;}
		| {$$ = new ExprList();}
		;

variables: variables expression COMMA {$1->addExpr($2); $$ = $1;}
		| {$$ = new ExprList();}
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
	| func_call {$$ = $1;}
	| id {$$ = $1;}
	;

%%

int yyerror(const char *s){
	cout<<s<<endl;
	return 0;
}