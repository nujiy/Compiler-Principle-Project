#include <stdio.h>
#include <stdlib.h>
#include "parser.cpp"
extern FILE* yyin;

int main(){
    FILE* fp = fopen("test.ll","r");
    if(fp == NULL)
    {
        yyerror("no such file");
        return -1;
    }
    yyin = fp;
    yyparse();
    fclose(fp);
    return 0;
}