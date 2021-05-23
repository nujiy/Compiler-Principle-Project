%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yyerror(char* s);
int yywrap();
%}

%union
{
	double val;
	char op;
};

%start program
%token <op> STOP
%token <op> END
%token <val> NUM

%left <op> ADD SUB
%left <op> MUL DIV
%left <op> POW
%left <op> '(' ')'

%type <val> exp
%type <val> term
%type <val> factor
%%

program: list STOP END {return $1;}

exp: exp ADD term {$$ = $1 + $3; }
	| exp SUB term {$$ = $1 - $3; }
	| term {$$ = $1;}
	;

term: term POW factor {$$ = pow($1,$3);}
	| term MUL factor {$$ = $1 * $3; }
	| term DIV factor {
		 	if($3 == 0.0)
				yyerror("divide by zero!");
			else
				$$ = $1 / $3;
			}
	| factor {$$ = $1; }
	;

factor: '(' exp ')' {$$ = $2; }
	| SUB factor {$$ = -$2;}
	| NUM {$$ = $1;}
	;
%%

int yywrap(){
	return 1;
}

int yyerror(char *s){
	printf("%s\n",s);
	return 0;
}

int main(){
	yyparse();
	return 0;
}