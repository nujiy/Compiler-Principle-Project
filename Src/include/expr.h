#ifndef COMPILER_EXPR_H
#define COMPILER_EXPR_H
#include "util.h"
#include "stmt.h"

class ExprList{
    vector<Expr*> exprList;
public:
    ExprList(){
        cout<<"exprList created"<<endl;
    }
    void addExpr(Expr* expr){
        this->exprList.push_back(expr);
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
    Identifier* funcName;
    ExprList* params;
public:
    FuncCall(Expr* funcName,ExprList* params): funcName(dynamic_cast<Identifier*> (funcName)),params(params){
        this->setExprType(EXPRFUNCCALL);
        cout<<"a FuncCall created"<<endl;
    }
    FuncCall(Expr* funcName):funcName(dynamic_cast<Identifier*> (funcName)){
        this->setExprType(EXPRFUNCCALL);
        cout<<"a FuncCall created"<<endl;
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
    Expr* Left;
    Expr* Right;
    int op;
public:
    BinaryExpr(Expr* Left,Expr* Right,int op):Left(Left),Right(Right),op(op) {
        this->setExprType(EXPRBINARY);

        if(op == OPEQ || op==OPLT || op == OPGT)
            this->setDType(VALUEBOOL);
        else{
            this->setDType(Left->getDType());
        }
    }

    Expr* getValue() {
        if(this->getDType() == VALUEBOOL)
        {
            return new Bool(false);
        }
        else{
            // calcaulate value
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
