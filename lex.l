%{
#include <math.h>
#include <string>
#include "AST.h"
#include "parser.hpp"
using namespace std;
%}

%option noyywrap

%%

[ \t\n] ;

"(" {return LEFTP;}
")" {return RIGHTP;}
"{" {return LEFTB;}
"}" {return RIGHTB;}
"," {return COMMA;}
";" {return SEMICOLON;}

"=" {return ASSIGN;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
"^" {return POW;}
">" {return GT;}
"<" {return LT;}
"==" {return EQ;}
"<>" {return NEQ;}


"Float" {return FLOAT;}
"Int" {return INT;}
"Bool" {return BOOL;}

"main" {return MAIN;}
"return" {return RETURN;}
"while" {return WHILE;}
"for" {return FOR;}
"if" {return IF;}
"else" {return ELSE;}

[_a-zA-Z]+[_a-zA-Z0-9]* {return IDENTIFIER;}

-?(0|[1-9][0-9]*) {return INTEGER_VALUE;}

[0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)? {return FLOAT_VALUE;}

%%