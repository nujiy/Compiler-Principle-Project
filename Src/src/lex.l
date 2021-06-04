%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include "../include/AST.h"
#include "../include/parser.hpp"
using namespace std;
%}

%option noyywrap

%%

[ \t\n]+ {}
\[ {return LEFTSB;}
] {return RIGHTSB;}
\( {return LEFTP;}
\) {return RIGHTP;}
\{ {return LEFTB;}
\} {return RIGHTB;}
, {return COMMA;}
; {return SEMICOLON;}

= {return ASSIGN;}
\+ {return ADD;}
\- {return SUB;}
\* {return MUL;}
\/ {return DIV;}
\^ {return POW;}
> {return GT;}
\< {return LT;}
== {return EQ;}
\<> {return NEQ;}
\<= {return ELT;}
>= {return EGT;}
\| {return OR;}
&& {return AND;}

Float {return FLOAT;}
Int {return INT;}
Bool { return BOOL;}
Void {return VOID;}
String {returen STRING;}
true {return TRUE;}
false {return FALSE;}
break {return BREAK;}

main { return MAIN;}
return {return RETURN;}
while {return WHILE;}
for {return FOR;}
if {return IF;}
else {return ELSE;}

(_|[a-zA-Z])+[_a-zA-Z0-9]* {yylval.Str = new string(yytext); return IDENTIFIER;}

-?(0|[1-9][0-9]*) {yylval.valueStr = yytext;return INTEGER_VALUE;}

[0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)? {return FLOAT_VALUE;}

.
%%