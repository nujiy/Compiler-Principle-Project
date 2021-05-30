#ifndef COMPILER_FUNCTION_H
#define COMPILER_FUNCTION_H
#include <memory>
#include "decl.h"

class FuncImpl;
class FuncList;
class FuncBody;

typedef shared_ptr<FuncImpl> funcImplPtr;
typedef shared_ptr<FuncList> funcListPtr;
typedef shared_ptr<FuncBody> funcBodyPtr;

class FuncBody{
    stmtListPtr stmts;
    stmtPtr stmtReturn;
public:
    FuncBody(StmtList* stmts,Stmt* stmtReturn):stmts(stmts),stmtReturn(stmtReturn){}
    void Print(){
        cout<<"{"<<endl;
        stmts->Print();
        cout<<"return ";
        stmtReturn->Print();
        cout<<endl<<"}"<<endl;
    }
};

class FuncImpl{
    declPtr proto;
    funcBodyPtr funcBody;
public:
    FuncImpl(Decl* proto,FuncBody* funcBody):proto(proto),funcBody(funcBody){}
    void Print(){
        proto->Print();
        funcBody->Print();
        cout<<endl;
    }
};

// 函数实现体
class FuncList{
    vector<funcImplPtr> functions;
public:
    FuncList(){}
    void addFunction(FuncImpl* impl){
        funcImplPtr tmp(impl);
        this->functions.push_back(tmp);
    }

    void Print(){
        for(int i = 0;i<functions.size();i++){
            functions[i]->Print();
        }
    }
};
#endif //COMPILER_FUNCTION_H
