#ifndef COMPILER_DECL_H
#define COMPILER_DECL_H

#include <iostream>
#include <llvm/IR/Function.h>
#include "util.h"
#include "stmt.h"
#include "expr.h"

using namespace std;

class DeclList;

class VariableDecl;

class ProtoType;

typedef unique_ptr<DeclList> declListPtr;
typedef unique_ptr<ProtoType> protoPtr;
typedef std::unique_ptr<llvm::GlobalVariable> globalVarPtr;

class DeclList {
public:
    vector<Decl *> declList;

    DeclList() {}

    void addDecl(Decl *decl) {
        this->declList.push_back(decl);
    }
};

// 变量声明 type name
class VariableDecl : public Decl {
    Identifier* name;
    exprPtr value;
    string id;
public:
    VariableDecl(int dType, Expr *name) : value(nullptr) {
        this->name = static_cast<Identifier*>(name);
        this->name->setDType(dType);
        this->setDeclType(DECLVARIABLE);
        this->id = this->name->getId();
    }

    VariableDecl(int dType, Expr *name, Expr *value) {
        this->name = static_cast<Identifier *>(name);
        this->name->setDType(dType);
        this->value = exprPtr(value);
        this->setDeclType(DECLVARIABLE);
        this->id = this->name->getId();
    }

    string &getID() {
        return this->name->getId();
    }

    int getVarType() {
        return this->name->getDType();
    }

    Identifier* getIdPtr(){
        return this->name;
    }

    void Print() {
        cout << getTypeMap(name->getDType()) << " ";
        name->Print();
        cout << " ";
        if (value)
            value->Print();
        cout << endl;
    }

    void GlobalGen();

    llvm::Value *CodeGen();
};

// 参数列表声明 type name (params)
class ParamsList : public Decl {
    vector<Decl *> params;
public:
    ParamsList() {
        this->setDeclType(DECLPARAM);
    }

    ~ParamsList() {}

    ParamsList(vector<Decl *> &params) : params(params) {
        this->setDeclType(DECLPARAM);
    }

    void addParam(Decl *param) {
        this->params.push_back(param);
    }

    void Print() {
        for (int i = 0; i < params.size(); i++) {
            if (i == 0) {
                params[i]->Print();
            } else {
                cout << " ,";
                params[i]->Print();
            }
        }
        cout << endl;
    }
};

class ArrayDecl : public Decl {
    idPtr name;
    int size;
    int dType;
public:
    ArrayDecl(int dType, Expr *arrayName, int size) : dType(dType), size(size) {
        Identifier *p = static_cast<Identifier *>(arrayName);
        this->name = idPtr(p);
        this->name->setDType(VALUEARRAY);
        this->setDeclType(DECLARRAY);
    }

    ArrayDecl(int dType,Expr* arrayName):dType(dType){
        this->name = idPtr(static_cast<Identifier*>(arrayName));
        this->name->setDType(VALUEARRAY);
        this->setDeclType(DECLARRAY);
        this->size = -1;
    }

    void Print() {
        cout << getTypeMap(this->dType) << " " << endl;
        this->name->Print();
        cout << "[" << size << "]" << endl;
    }

    string &getID() {
        return name->getId();
    }

    llvm::Value *CodeGen();
};

// 函数原型声明
class ProtoType : public Decl {
    idPtr name;
    vector<declPtr> params;
public:
    ProtoType(int dType, Expr *funcName, DeclList *params) {
        for (int i = 0, e = params->declList.size(); i < e; i++) {
            declPtr p = declPtr(params->declList[i]);
            this->params.push_back(std::move(p));
        }

        Identifier *p = static_cast<Identifier *>(funcName);
        this->name = idPtr(p);

        funcName->setDType(dType);
        this->setDeclType(DECLPROTO);
    }

    void Print() {
        cout << getTypeMap(name->getDType()) << " ";
        name->Print();
        cout << " (";
        for (int i = 0, e = params.size(); i < e; i++) {
            params[i]->Print();
        }
        cout << ")" << endl;
    }

    string &getFuncName() {
        return name->getId();
    }

    int getParamSize() {
        return params.size();
    }

    string &getParamName(int index) {
        Decl *d = params[index].get();
        string *empty = new string("");
        if (d->getDeclType() == DECLVARIABLE) {
            return static_cast<VariableDecl *>(d)->getID();
        } else if (d->getDeclType() == DECLARRAY) {
            return static_cast<ArrayDecl *>(d)->getID();
        } else {
            return *empty;
        }
    }

    int getParamType(int index) {
        VariableDecl* v = static_cast<VariableDecl*>(params[index].get());
        return v->getVarType();
    }

    int getReturnType() {
        return name->getDType();
    }

    Identifier* getParamsPtr(int index){
        VariableDecl* v = static_cast<VariableDecl*>(params[index].get());
        return v->getIdPtr();
    }

    llvm::Value *CodeGen();

    llvm::Function* FunctionGen();
};

#endif //COMPILER_DECL_H