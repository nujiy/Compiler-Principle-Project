#ifndef COMPILER_DECL_H
#define COMPILER_DECL_H
#include "util.h"
#include "stmt.h"


class DeclList{
    vector<Decl*> declList;
public:
    DeclList(){}
    void addDecl(Decl* decl){
        this->declList.push_back(decl);
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
    Expr* name; // identifier
    Expr* value;
public:
    VariableDecl(int dType,Expr* name):name(name),value(new Expr()){
        name->setDType(dType);
        this->setDeclType(DECLVARIABLE);
        cout<<"a variable declared"<<endl;
    }
    VariableDecl(int dType,Expr* name,Expr* value):name(name),value(value){
        name->setDType(dType);
        this->setDeclType(DECLPROTO);
        cout<<"a variable declared"<<endl;
    }
    void Print()
    {
        cout<<getTypeMap(name->getDType())<<" ";
        name->Print();
        cout<<" ";
        value->Print();
        cout<<endl;
    }
};

// 参数列表声明 type name (params)
class ParamsList: public Decl{
    vector<Decl*> params;
public:
    ParamsList(){
        this->setDeclType(DECLPARAM);
    }
    ~ParamsList(){}
    ParamsList(vector<Decl*>& params):params(params){
        this->setDeclType(DECLPARAM);
    }
    void addParam(Decl* param){
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
    Expr* name;
    ParamsList* params;
public:
    ProtoType(int dType,Expr* funcName,ParamsList* params):name(funcName),params(params){
        funcName->setDType(dType);
        this->setDeclType(DECLPROTO);
        cout<<"a prototype declared"<<endl;
    }
    void Print(){
        cout<<getTypeMap(name->getDType())<<" ";
        name->Print();
        cout<<" (";
        params->Print();
        cout<<")"<<endl;
    }
};
#endif //COMPILER_DECL_H
