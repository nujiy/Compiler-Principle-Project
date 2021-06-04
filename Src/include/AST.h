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
    virtual void CodeGen() {};
};

// 全局成员 包括函数声明与全局变量
class GlobalPart:public Block {
    vector<declPtr> decls;
public:
    GlobalPart(DeclList* decls){
        for(int i = 0,e = decls->declList.size(); i<e;i++){
            this->decls.push_back(declPtr(decls->declList[i]));
        }
    }
    void CodeGen();
    void Print(){
        for(int i=0,e=decls.size();i<e;i++){
            decls[i]->Print();
        }
    }
};

// 主函数 main(){...}
class MainPart:public Block {
    funcBodyPtr mainFunc;
public:
    MainPart(FuncBody* mainFunc):mainFunc(mainFunc){}
    void CodeGen();
    void Print(){
        mainFunc->Print();
    }
};

class FuncPart:public Block {
    vector<funcImplPtr> functions;
public:
    FuncPart(FuncList* functions) {
        for(int i=0,e = functions->functions.size();i<e;i++){
            this->functions.push_back(funcImplPtr(functions->functions[i]));
        }
    }
    void CodeGen();
    void Print(){
        for(int i=0,e=functions.size();i<e;i++){
            functions[i]->Print();
        }
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
    void Print(){
        Global->Print();
        Main->Print();
        Function->Print();
    }
    void CodeGen();
};

#endif //_AST_H
