%{
#include <math.h>
#include "yacc.tab.h"
}%

%%
\+ {return ADD;}
\- {return SUB;}
\* {return MUL;}
/ {return DIV;}
\^ {return POW}

return {
    return RETURN;
}

while {
    return WHILE;
}

for {
    return FOR;
}

if {
    return IF;
}

else {
    return ELSE;
}

(_ | [a-zA-Z])[_a-zA-Z0-9]* {
    return NAME;
}

Void | Int | Float | String | Char {
    return BASICTYPE;
}

\* {
    return ADDRSTAR;
}

-?(0|[1-9][0-9]*) {
    yylval.val = atoi(yytext);
    return INTEGER;
}

[0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)? {
	yylval.val = atof(yytext);
	return FLOAT;
}

%%