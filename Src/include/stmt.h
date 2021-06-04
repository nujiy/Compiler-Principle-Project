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
class Condition;
class ConditionOtherwise;
class StmtList;

void printStmt(Stmt *stmt);

extern void printExpr(Expr *expr);

extern void printDecl(Decl *decl);

typedef unique_ptr<Node> nodePtr;
typedef unique_ptr<Stmt> stmtPtr;
typedef unique_ptr<StmtList> stmtListPtr;
typedef unique_ptr<Expr> exprPtr;
typedef unique_ptr<Decl> declPtr;
typedef unique_ptr<Assignment> assignPtr;
typedef unique_ptr<ForLoop> forLoopPtr;
typedef unique_ptr<WhileLoop> whileLoopPtr;
typedef unique_ptr<Condition> conditionPtr;
typedef unique_ptr<ConditionOtherwise> conditionOtherwisePtr;

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

    llvm::Value *CodeGen();
};

// while循环
class WhileLoop:public Stmt{
    exprPtr expression;
    vector<stmtPtr> stmtlist;
public:
    WhileLoop(Expr* expression,StmtList* stmtlist):expression(expression){
        for(int i=0,e=stmtlist->stmtList.size(); i<e;i++){
            this->stmtlist.push_back(stmtPtr(stmtlist->stmtList[i]));
        }
        this->setStmtType(STMTWHILE);
        cout << "a while loop created" << endl;
    }
    void Print(){
        cout << " while (";
        expression->Print();
        cout << ")" << endl;
        cout << "{";
        for(int i=0,e=stmtlist.size(); i<e;i++){
            stmtlist[i]->Print();
        }
        cout << "}" << endl;
    }
};

// for循环
class ForLoop:public Stmt{
    exprPtr expression;
    assignPtr assignment_1, assignment_2;
    vector<stmtPtr> stmtlist;
public:
    ForLoop(Stmt* assignment_1, Expr* expression, Stmt* assignment_2,StmtList* stmtlist): expression(expression)
    {
        for(int i=0,e=stmtlist->stmtList.size();i<e;i++){
            this->stmtlist.push_back(stmtPtr(stmtlist->stmtList[i]));
        }
        this->assignment_1 = assignPtr(static_cast<Assignment*>(assignment_1));
        this->assignment_2 = assignPtr(static_cast<Assignment*>(assignment_2));
        this->setStmtType(STMTFOR);
        cout << "a for loop created" << endl;
    }

    void Print(){
        cout << "for (";
        assignment_1->Print();
        cout << ";";
        expression->Print();
        cout << ";";
        assignment_2->Print();
        cout << ")" << endl
             << "{" << endl;
        for(int i=0,e=stmtlist.size(); i<e;i++){
            stmtlist[i]->Print();
        }
        cout << "}" << endl;
    }
};

// if条件分支
class Condition :public Stmt
{
    exprPtr expression;
    vector<stmtPtr> stmtlist;
public:
    Condition(Expr* expression, StmtList * stmtlist):expression(expression){
        for(int i=0,e=stmtlist->stmtList.size();i<e;i++){
            this->stmtlist.push_back(stmtPtr(stmtlist->stmtList[i]));
        }
        this->setStmtType(STMTCONDITION);
        cout << "a condition created" << endl;
    }
    void Print(){
        cout << "if (";
        expression->Print();
        cout << ")" << endl
             << "{";
        for(int i=0,e=stmtlist.size(); i<e;i++){
            stmtlist[i]->Print();
        }
        cout << "}" << endl;
    }
};

// if-else
class ConditionOtherwise : public Stmt
{
    exprPtr expression;
    vector<stmtPtr> stmtlist_1, stmtlist_2;
public:
    ConditionOtherwise(Expr * expression,StmtList * stmtlist_1,StmtList * stmtlist_2):expression(expression) {
        for(int i=0,e=stmtlist_1->stmtList.size();i<e;i++){
            this->stmtlist_1.push_back(stmtPtr(stmtlist_1->stmtList[i]));
        }
        for(int i=0,e=stmtlist_2->stmtList.size();i<e;i++){
            this->stmtlist_2.push_back(stmtPtr(stmtlist_2->stmtList[i]));
        }

        this->setStmtType(STMTCONDITION_WITH_OTHERWISE);
        cout << "a condition with otherwise created" << endl;
    }
    void Print(){
        cout << "if (";
        expression->Print();
        cout << ")" << endl
             << "{";
        for(int i=0,e=stmtlist_1.size(); i<e;i++){
            stmtlist_1[i]->Print();
        }
        cout << "}" << endl
             << "else"
             << "{" << endl;
        for(int i=0,e=stmtlist_2.size(); i<e;i++){
            stmtlist_2[i]->Print();
        }
        cout << "}" << endl;
    }
};
#endif //COMPILER_STMT_H
