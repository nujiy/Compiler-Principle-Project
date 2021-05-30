#ifndef COMPILER_DECL_H
#define COMPILER_DECL_H
#include <iostream>
#include "util.h"
#include "stmt.h"

using namespace std;

class DeclList;
class ProtoType;

typedef shared_ptr<DeclList> declListPtr;
typedef shared_ptr<ProtoType> protoPtr;

class DeclList{
    vector<declPtr> declList;
public:
    DeclList(){}
    void addDecl(Decl* decl){
        shared_ptr<Decl> tmp(decl);
        this->declList.push_back(tmp);
    }
    void Print()
    {
        for(int i=0;i<this->declList.size();i++) {
            declList[i]->Print();
        }
    }
};

// 变量声明 type name
class VariableDecl: public Decl{
    exprPtr name; // identifier
    exprPtr value;
public:
    VariableDecl(int dType,Expr* name):name(name),value(new Expr()){
        name->setDType(dType);
        this->setDeclType(DECLVARIABLE);
    }
    VariableDecl(int dType,Expr* name,Expr* value):name(name),value(value){
        name->setDType(dType);
        this->setDeclType(DECLPROTO);
    }
    void Print()
    {
        cout<<getTypeMap(name->getDType())<<" ";
        name->Print();
        cout<<" ";
        if(value != NULL)
            value->Print();
        cout<<endl;
    }
};

// 参数列表声明 type name (params)
class ParamsList: public Decl{
    vector<declPtr> params;
public:
    ParamsList(){
        this->setDeclType(DECLPARAM);
    }
    ~ParamsList(){}
    ParamsList(vector<declPtr>& params):params(params){
        this->setDeclType(DECLPARAM);
    }
    void addParam(declPtr param){
        this->params.push_back(param);
    }
    void Print(){
        for(int i=0;i<params.size();i++){
            if(i==0){
                params[i]->Print();
            }
            else{
                cout<<" ,";
                params[i]->Print();
            }
        }
        cout<<endl;
    }
};

// 函数原型声明
class ProtoType: public Decl{
    exprPtr name;
    declListPtr params;
public:
    ProtoType(int dType,Expr* funcName,DeclList* params):name(funcName),params(params){
        funcName->setDType(dType);
        this->setDeclType(DECLPROTO);
    }
    void Print(){
        cout<<getTypeMap(name->getDType())<<" ";
        name->Print();
        cout<<" (";
        params->Print();
        cout<<")"<<endl;
    }
};

class ArrayDecl: public Decl{
    exprPtr name;
    int size;
    int dType;
public:
    ArrayDecl(int dType,Expr* arrayName,int size):dType(dType),name(arrayName),size(size){
        arrayName->setDType(VALUEARRAY);
        this->setDeclType(DECLARRAY);
    }
    void Print(){
        cout<<getTypeMap(this->dType)<<" "<<endl;
        this->name->Print();
        cout<<"["<<size<<"]"<<endl;
    }
};

#endif //COMPILER_DECL_H