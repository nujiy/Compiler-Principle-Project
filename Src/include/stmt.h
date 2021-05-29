#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H
#include <vector>
#include <iostream>
#include "util.h"
using namespace std;
class Stmt;
class Expr;
class Decl;
void printStmt(Stmt* stmt);
extern void printExpr(Expr* expr);
extern void printDecl(Decl* decl);

// 各类语句
class Stmt {
    int stmtType;
public:
    Stmt(){}
    ~Stmt(){}
    void setStmtType(int stmtType){
        this->stmtType = stmtType;
    }

    int getStmtType(){
        return this->stmtType;
    }

    virtual void Print(){
        printStmt(this);
    }
};

class StmtList {
    vector<Stmt*> stmtList;
public:
    StmtList(){
    }
    void addStmt(Stmt* stmt){
        this->stmtList.push_back(stmt);
    }
    void Print(){
        for(int i=0;i<stmtList.size();i++){
            stmtList[i]->Print();
        }
    }
};

// 表达式
class Expr: public Stmt{
    int dType;
    int exprType;
    Expr* valueptr;
public:
    Expr(){
        this->dType = -1; // base node
        this->setStmtType(STMTEXPR);
    }
    ~Expr(){}
    void setDType(int dType);

    int getDType();

    void setExprType(int exprType);

    int getExprType();

    virtual Expr* getValue();

    virtual void Print(){
        printExpr(this);
    }
};

class StmtReturn: public Stmt{
    Expr* value;
public:
    StmtReturn(Expr* value):value(value){
        this->setStmtType(STMTRETURN);
    }
    void Print(){
        value->Print();
    }
};

// 声明语句
class Decl:public Stmt{
    int declType;
public:
    Decl(){
        this->setStmtType(STMTDECL);
    }
    void setDeclType(int declType){
        this->declType = declType;
    }

    int getDeclType(){
        return this->declType;
    }

    virtual void Print(){
        printDecl(this);
    }
};

// 赋值语句
class Assignment:public Stmt{
    Expr* identifier;
    Expr* expression;
public:
    Assignment(Expr* identifier,Expr* expression):identifier(identifier),expression(expression){
        this->setStmtType(STMTASSIGN);
        cout<<"an assignment created"<<endl;
    }
    void Print(){
        identifier->Print();
        cout<<"=";
        expression->Print();
        cout<<endl;
    }
};

#endif //COMPILER_STMT_H
