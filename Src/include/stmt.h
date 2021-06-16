#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H

#include <vector>
#include <iostream>
#include <memory>
#include <llvm/IR/Value.h>
#include "util.h"

using namespace std;

class Node;
class Stmt;
class Expr;
class Decl;
class Assignment;
class WhileLoop;
class ForLoop;
class ConditionBlock;
class Condition;
class StmtList;

void printStmt(Stmt *stmt);

extern void printExpr(Expr *expr);

extern void printDecl(Decl *decl);

typedef unique_ptr<Node> nodePtr;
typedef unique_ptr<Stmt> stmtPtr;
typedef unique_ptr<Expr> exprPtr;
typedef unique_ptr<Decl> declPtr;
typedef unique_ptr<Assignment> assignPtr;
typedef unique_ptr<ConditionBlock> condBlockPtr;

class Node {
    int nodeType;
public:
    Node() {}

    void setNodeType(int type) {
        nodeType = type;
    }

    int getNodeType() {
        return nodeType;
    }
};

// 各类语句
class Stmt : public Node {
    int stmtType;
public:
    Stmt() {
        this->setNodeType(NODESTMT);
    }

    ~Stmt() {}

    void setStmtType(int stmtType) {
        this->stmtType = stmtType;
    }

    int getStmtType() {
        return this->stmtType;
    }

    virtual void Print() {
        printStmt(this);
    }

    virtual llvm::Value *CodeGen();
};

class StmtList {
public:
    vector<Stmt *> stmtList;

    StmtList() {}

    void addStmt(Stmt *stmt) {
        this->stmtList.push_back(stmt);
    }
};

// 表达式
class Expr : public Stmt {
    int exprType;
    exprPtr valueptr;
public:
    int dType;

    Expr() {
        this->dType = -1; // base node
        this->setStmtType(STMTEXPR);
    }

    ~Expr() {}

    void setExprType(int exprType) {
        this->exprType = exprType;
    }

    int getExprType() {
        return this->exprType;
    }

    void setDType(int dType) {
        this->dType = dType;
    }

    virtual int getDType() {
        return this->dType;
    }

    virtual void Print() {
        printExpr(this);
    }

    llvm::Value *CodeGen();
};

// 声明语句
class Decl : public Stmt {
    int declType;
public:
    Decl() {
        this->setStmtType(STMTDECL);
    }

    void setDeclType(int declType) {
        this->declType = declType;
    }

    int getDeclType() {
        return this->declType;
    }

    virtual void Print() {
        printDecl(this);
    }

    virtual llvm::Value *CodeGen();
};

// 赋值语句
class Assignment : public Stmt {
    exprPtr identifier;
    exprPtr expression;
public:
    Assignment(Expr *identifier, Expr *expression) : identifier(identifier), expression(expression) {
        this->setStmtType(STMTASSIGN);
        cout << "an assignment created" << endl;
    }

    void Print() {
        identifier->Print();
        cout << "=";
        expression->Print();
        cout << endl;
    }

    Expr* getLeftID(){
        return identifier.get();
    }

    Expr* getRightValue(){
        return expression.get();
    };

    llvm::Value *CodeGen();
};

// while循环
class WhileLoop:public Stmt{
    exprPtr condition;
    vector<stmtPtr> stmtlist;
public:
    WhileLoop(Expr* expression,StmtList* stmtlist):condition(expression){
        for(int i=0,e=stmtlist->stmtList.size(); i<e;i++){
            this->stmtlist.push_back(stmtPtr(stmtlist->stmtList[i]));
        }
        this->setStmtType(STMTWHILE);
        cout << "a while loop created" << endl;
    }
    void Print(){
        cout << " while (";
        condition->Print();
        cout << ")" << endl;
        cout << "{";
        for(int i=0,e=stmtlist.size(); i<e;i++){
            stmtlist[i]->Print();
        }
        cout << "}" << endl;
    }

    llvm::Value* CodeGen();
};

// for循环 要求只有一个变量
class ForLoop:public Stmt{
    assignPtr initAssign;
    exprPtr condition;
    assignPtr stepAssign;
    vector<stmtPtr> stmtlist;
    exprPtr returnExpr;
public:
    ForLoop(Stmt* initAssign, Expr* condition, Stmt* stepAssign,StmtList* stmtlist,Expr* returnExpr)
    {
        for(int i=0,e=stmtlist->stmtList.size();i<e;i++){
            this->stmtlist.push_back(stmtPtr(stmtlist->stmtList[i]));
        }
        this->condition = exprPtr(condition);
        this->initAssign = assignPtr(static_cast<Assignment*>(initAssign));
        this->stepAssign = assignPtr(static_cast<Assignment*>(stepAssign));
        this->returnExpr = exprPtr(returnExpr);
        this->setStmtType(STMTFOR);
        cout << "a for loop created" << endl;
    }

    void Print(){
        cout << "for (";
        initAssign->Print();
        cout << ";";
        condition->Print();
        cout << ";";
        stepAssign->Print();
        cout << "){" << endl;
        for(int i=0,e=stmtlist.size(); i<e;i++){
            stmtlist[i]->Print();
        }
        cout << "}" << endl;
    }

    Expr* getVar(){
        return initAssign->getLeftID();
    }

    Expr* getInitValue(){
        return initAssign->getRightValue();
    }

    Expr* getStepValue(){
        return stepAssign->getRightValue();
    }

    llvm::Value* CodeGen();
};

class ConditionBlock:public Stmt {
public:
    vector<stmtPtr> stmtList;
    exprPtr returnExpr;
    ConditionBlock(StmtList* stmtList,Expr* returnExpr){
        for(int i=0,e=stmtList->stmtList.size();i<e;i++){
            this->stmtList.push_back(stmtPtr(stmtList->stmtList[i]));
        }
        this->returnExpr = exprPtr(returnExpr);
    }

    void Print(){
        for(int i=0,e=stmtList.size(); i<e;i++){
            stmtList[i]->Print();
        }

        if(returnExpr)
            returnExpr->Print();
    }

    llvm::Value* CodeGen();
};

class Condition :public Stmt
{
    exprPtr expression;
    vector<condBlockPtr> block;
public:
    Condition(Expr* expression, Stmt* ifBlock,Stmt* elseBlock):expression(expression){
        this->block.push_back(condBlockPtr (static_cast<ConditionBlock*>(ifBlock)));
        if(elseBlock)
            this->block.push_back(condBlockPtr (static_cast<ConditionBlock*>(elseBlock)));
        this->setStmtType(STMTCONDITION);
        cout << "a condition created" << endl;
    }
    void Print(){
        cout << "if (";
        expression->Print();
        cout << ")" << endl;
        for(int i=0,e=block.size(); i<e;i++){
            cout<< "{";
            block[i]->Print();
            cout << "}" << endl;
        }
    }

    llvm::Value* CodeGen();
};
#endif //COMPILER_STMT_H
