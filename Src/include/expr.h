#ifndef COMPILER_EXPR_H
#define COMPILER_EXPR_H
#include <memory>
#include "util.h"
#include "stmt.h"
using namespace std;
class ExprList;

typedef shared_ptr<ExprList> exprListPtr;

class ExprList{
    vector<exprPtr> exprList;
public:
    ExprList(){
    }
    void addExpr(Expr* expr){
        exprPtr tmp(expr);
        this->exprList.push_back(tmp);
    }
    void Print(){
        for(int i=0;i<exprList.size();i++){
            exprList[i]->Print();
        }
    }
};

// 字面量表达式
class Void:public Expr{
public:
    Void(){
        this->setDType(VALUEVOID);
        this->setExprType(EXPRVALUE);
    }
    void Print(){}
};

class Integer:public Expr{
    int value;
public:
    Integer(int value):value(value){
        this->setDType(VALUEINT);
        this->setExprType(EXPRVALUE);
    }
    void Print(){
        cout<<value;
    }
};

class Float:public Expr{
    double value;
public:
    Float(double value):value(value){
        this->setDType(VALUEFLOAT);
        this->setExprType(EXPRVALUE);

    }
    void Print(){
        cout<<value;
    }
};

class Bool:public Expr{
    bool value;
public:
    Bool(bool value):value(value){
        this->setDType(VALUEBOOL);
        this->setExprType(EXPRVALUE);
    }
    void Print(){
        cout<<value;
    }
};

// 函数名、变量名标识符
class Identifier:public Expr {
    string& identifier;
public:
    Identifier(string& identifier):identifier(identifier){
        this->setExprType(EXPRID);
    }

    void Print(){
        cout<<identifier;
    }
};

// 函数调用表达式
class FuncCall:public Expr{
    exprPtr funcName;
    exprListPtr params;
public:
    FuncCall(Expr* funcName,ExprList* params): funcName(funcName),params(params){
        this->setExprType(EXPRFUNCCALL);
    }
    FuncCall(exprPtr funcName):funcName(funcName){
        this->setExprType(EXPRFUNCCALL);
    }
    void Print(){
        funcName->Print();
        cout<<"(";
        params->Print();
        cout<<")"<<endl;
    }
};

// 二元运算表达式
class BinaryExpr: public Expr{
    exprPtr Left;
    exprPtr Right;
    int op;
public:
    BinaryExpr(Expr* Left,Expr* Right,int op):Left(Left),Right(Right),op(op) {
        this->setExprType(EXPRBINARY);

        if(op == OPEQ || op==OPLT || op == OPGT || op == OPEGT || op == OPELT || op == OPNEQ || op == OPAND || op == OPOR)
            this->setDType(VALUEBOOL);
        else{
            this->setDType(Left->getDType());
        }
    }

    exprPtr getValue() {
        if(this->getDType() == VALUEBOOL)
        {
            return make_shared<Bool>(false);
        }
        else{

        }
    }

    void Print() {
        cout<<"(";
        this->Left->Print();
        cout<<")"<< getOpMap(this->op)<<"(";
        this->Right->Print();
        cout<<")";
    }
};

#endif //COMPILER_EXPR_H
