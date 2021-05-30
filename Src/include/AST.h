#ifndef _AST_H
#define _AST_H
#include <iostream>
#include <string>
#include <vector>
#include "decl.h"
#include "expr.h"
#include "function.h"
using namespace std;
class Block{
public:
    Block(){}
    virtual ~Block(){}
    virtual void Print() {};
};

// 全局成员 包括函数声明与全局变量
class GlobalPart:public Block {
    declListPtr decls;
public:
    GlobalPart(DeclList* decls):decls(decls){}
    void Print(){
        decls->Print();
    }
};

// 主函数 main(){...}
class MainPart:public Block {
    funcBodyPtr mainFunc;
public:
    MainPart(FuncBody* mainFunc):mainFunc(mainFunc){}
    void Print(){
        mainFunc->Print();
    }
};

class FuncPart:public Block {
    funcListPtr functions;
public:
    FuncPart(FuncList* functions):functions(functions){}
    void Print(){
        functions->Print();
    }
};


class AST {
GlobalPart* Global;
MainPart* Main;
FuncPart* Function;
public:
    AST(Block* Global,Block* Main,Block* Function):Global(dynamic_cast<GlobalPart*> (Global)),Main(dynamic_cast<MainPart*> (Main)),Function(dynamic_cast<FuncPart*> (Function)){
        setMap();
    };
    void Print()
    {
        Global->Print();
        Main->Print();
        Function->Print();
    }
};

#endif //_AST_H
