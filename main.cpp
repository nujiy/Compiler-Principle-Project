#include <iostream>
#include <fstream>
#include <string>
#include "FlexLexer.h"
using namespace std;
extern int yyparse(yyFlexLexer* yyflex);

int main(){
    ifstream* fileIn = new ifstream("test.ll");
    ofstream* fileOut = new ofstream("out.ll");
    yyFlexLexer* yyflex = new yyFlexLexer(fileIn,fileOut);

    yyparse(yyflex);
    fileIn->close();
    fileOut->close();
    return 0;
}