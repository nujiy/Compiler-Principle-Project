#ifndef COMPILER_FUNCTION_H
#define COMPILER_FUNCTION_H
#include "decl.h"

class FuncBody{
    StmtList* stmts;
    StmtReturn* stmtReturn;
public:
    FuncBody(StmtList* stmts,Stmt* stmtReturn):stmts(stmts),stmtReturn(dynamic_cast<StmtReturn*>(stmtReturn)){
        cout<<"a Function Body ceated"<<endl;
    }
    void Print(){
        cout<<"{"<<endl;
        stmts->Print();
        cout<<"return ";
        stmtReturn->Print();
        cout<<endl<<"}"<<endl;
    }
};

class FuncImpl{
    ProtoType* proto;
    FuncBody* funcBody;
public:
    FuncImpl(Decl* proto,FuncBody* funcBody):proto(dynamic_cast<ProtoType*>(proto)),funcBody(funcBody){}
    void Print(){
        proto->Print();
        funcBody->Print();
        cout<<endl;
    }
};

// 函数实现体
class FuncList{
    vector<FuncImpl*> functions;
public:
    FuncList(){
        cout<<"create FuncList node"<<endl;
    }
    void addFunction(FuncImpl* impl){
        this->functions.push_back(impl);
        cout<<"impl a function"<<endl;
    }

    void Print(){
        for(int i = 0;i<functions.size();i++){
            functions[i]->Print();
        }
    }
};
#endif //COMPILER_FUNCTION_H
