#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "AST.h"
#include "FlexLexer.h"
using namespace std;
extern int yyparse(yyFlexLexer* yyflex);
extern AST* program;
int main(){
    ifstream* fileIn = new ifstream("test.ll");
    ofstream* fileOut = new ofstream("out.ll");
    yyFlexLexer* yyflex = new yyFlexLexer(fileIn,fileOut);

    yyparse(yyflex);

    program->Print();
    fileIn->close();
    fileOut->close();
    return 0;
}