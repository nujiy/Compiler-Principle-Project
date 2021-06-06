#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "./include/AST.h"
#include "./include/FlexLexer.h"

using namespace std;

extern int yyparse(yyFlexLexer *yyflex);

extern AST *program;

int main(int args,char** argv) {

    if(args != 2){
        cout<<"invalid input arguments"<<endl;
        return -1;
    }
    string filename = string(argv[1]);
    cout<<filename<<endl;
    ifstream *fileIn = new ifstream(filename, ios::in);
    if (!fileIn->is_open()) {
        cout << "failed in open file" << endl;
        return -1;
    }
    yyFlexLexer *yyflex = new yyFlexLexer(fileIn);

    yyparse(yyflex);
    if (program != nullptr)
        program->CodeGen();
    else
        cout << "no program scanned" << endl;
    fileIn->close();
    return 0;
}