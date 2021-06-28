#ifndef COMPILER_EXPR_H
#define COMPILER_EXPR_H

#include <memory>
#include "stmt.h"

using namespace std;

class ExprList;

class Identifier;

class ValueExpr;

typedef unique_ptr<Identifier> idPtr;

class ExprList {
public:
    vector<Expr *> exprList;

    ExprList() {
    }

    void addExpr(Expr *expr) {
        this->exprList.push_back(expr);
    }
};

class ValueExpr : public Expr {
    int valueType;
public:
    ValueExpr() {
        this->setExprType(EXPRVALUE);
    }

    void setValueType(int type) {
        valueType = type;
        this->setDType(type);
    }

    int getValueType() {
        return valueType;
    }
};

// 字面量表达式
class Void : public ValueExpr {
public:
    Void() {
        this->setValueType(VALUEVOID);
        cout<<"create void"<<endl;
    }

    void Print() {}

    llvm::Value *CodeGen();
};

class Integer : public ValueExpr {
    int value;
public:
    Integer(int value) : value(value) {
        this->setValueType(VALUEINT);
    }

    void Print() {
        cout << value;
    }

    llvm::Value *CodeGen();
};

class Float : public ValueExpr {
    double value;
public:
    Float(double value) {
        this->value = value;
        this->setValueType(VALUEFLOAT);
    }

    void Print() {
        cout << value;
    }

    llvm::Value *CodeGen();
};

class Bool : public ValueExpr {
    bool value;
public:
    Bool(bool value) : value(value) {
        this->setValueType(VALUEBOOL);
    }

    void Print() {
        cout << value;
    }

    llvm::Value *CodeGen();
};

class String: public ValueExpr {
    string value;
public:
    String(string& value){
        if(value.length() == 2)
            this->value = "";
        else
            this->value = value.substr(1,value.length()-2);
        this->setValueType(VALUESTRING);
    }

    String(){
        this->value = "";
    }

    string& getValue(){
        return this->value;
    }

    void Print() {
        cout << value;
    }

    llvm::Value *CodeGen();

};
// identifier
class Identifier : public Expr {
    std::string &identifier;
public:
    Identifier(string &identifier) : identifier(identifier) {
        this->setExprType(EXPRID);
    }

    std::string &getId() {
        return this->identifier;
    }

    void Print() {
        cout << identifier;
    }

    llvm::Value *CodeGen();
};

// function call
class FuncCall : public Expr {
    idPtr func;
    vector<exprPtr> params;
public:
    FuncCall(Expr *funcName, ExprList *params) {
        Identifier *p = static_cast<Identifier *>(funcName);
        this->func = idPtr(p);

        for (int i = 0, e = params->exprList.size(); i < e; i++) {
            this->params.push_back(exprPtr(params->exprList[i]));
        }
        this->setExprType(EXPRFUNCCALL);
    }

    FuncCall(Expr *funcName) {
        Identifier *p = static_cast<Identifier *>(funcName);
        this->func = idPtr(p);
        this->setExprType(EXPRFUNCCALL);
        cout<<"a funcall created"<<endl;
    }

    void Print() {
        func->Print();
        cout << "(";
        for (int i = 0; i < params.size(); i++) {
            params[i]->Print();
        }
        cout << ")" << endl;
    }

    llvm::Value *CodeGen();
};

// 二元运算表达式
class BinaryExpr : public Expr {
    exprPtr Left;
    exprPtr Right;
    int op;
public:
    BinaryExpr(Expr *Left, Expr *Right, int op) : Left(Left), Right(Right), op(op) {
        this->setExprType(EXPRBINARY);
        this->setDType(-1); // didn't initialize
    }

    int getDType();

    void Print() {
        cout << "(";
        this->Left->Print();
        cout << ")" << getOpMap(this->op) << "(";
        this->Right->Print();
        cout << ")";
    }

    llvm::Value *CodeGen();
};

class ArrayExpr: public Expr {
    idPtr id;
    exprPtr index;
public:
    ArrayExpr(Expr* id,Expr* index){
        this->id = idPtr(static_cast<Identifier*>(id));
        this->index = exprPtr(index);
        this->setExprType(EXPRARRAY);
    }

    ArrayExpr(Expr* id){
        this->id = idPtr(static_cast<Identifier*>(id));
        this->index = nullptr;
        this->setExprType(EXPRARRAY);
    }

    string& getId(){
        return id->getId();
    }

    int getDType();

    void Print() {
        id->Print();
        cout<<'['<<endl;
        if(index)
            index->Print();
        cout << "]";
    }

    Expr* getIndex(){
        if(index)
            return index.get();
        return nullptr;
    }

    llvm::Value* CodeGen();
};
#endif //COMPILER_EXPR_H
