#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H
#include <vector>
#include <iostream>
#include <memory>
#include "util.h"
using namespace std;
class Stmt;
class Expr;
class Decl;
class StmtReturn;
class Assignment;
class StmtList;

void printStmt(Stmt* stmt);
extern void printExpr(Expr* expr);
extern void printDecl(Decl* decl);

typedef shared_ptr<Stmt> stmtPtr;
typedef shared_ptr<StmtList> stmtListPtr;
typedef shared_ptr<Expr> exprPtr;
typedef shared_ptr<Decl> declPtr;
typedef shared_ptr<StmtReturn> returnPtr;
typedef shared_ptr<Assignment> assignPtr;
typedef shared_ptr<For_loop> for_loopPtr;
typedef shared_ptr<While_loop> while_loopPtr;
typedef shared_ptr<Condition> conditionPtr;
typedef shared_ptr<Condition_with_otherwise> condition_with_otherwisePtr;

    // 各类语句
    class Stmt
{
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
    vector <stmtPtr> stmtList;
public:
    StmtList(){
    }
    void addStmt(Stmt* stmt){
        stmtPtr tmp(stmt);
        this->stmtList.push_back(tmp);
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
    exprPtr valueptr;
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

    virtual exprPtr getValue();

    virtual void Print(){
        printExpr(this);
    }
};

class StmtReturn: public Stmt{
    exprPtr value;
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
    exprPtr identifier;
    exprPtr expression;
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

class While_loop:public Stmt{
    exprPtr expression;
    stmtListPtr stmtlist;
public:
    While_loop(Expr* expression,Expr* stmtlist):expression(expression),stmtlist(stmtlist){
        this->setStmtType(STMTWHILE);
        cout << "a while loop created" << endl;
    }
    void Print(){
        cout << " while (";
        expression->Print();
        cout << ")" << endl;
        cout << "{";
        stmtlist->Print();
        cout << "}" << endl;
    }
};

class For_loop:public Stmt{
    exprPtr expression;
    assignPtr assignment_1, assignment_2;
    stmtListPtr stmtlist;
public:
    For_loop(Expr* assignment_1, Expr* expression, Expr* assignment_2,Expr* stmtlist): assignment_1(assignment_1) ,expression(expression), assignment_2(assignment_2),stmtlist(stmtlist)
    {
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
        stmtlist->Print();
        cout << "}" << endl;
    }
};

class Condition :public Stmt
{
    exprPtr expression;
    stmtListPtr stmtlist;
public:
    Condition(Expr* expression, Expr * stmtlist):expression(expression),stmtlist(stmtlist){
        this->setStmtType(STMTCONDITION);
        cout << "a condition created" << endl;
    }
    void Print(){
        cout << "if (";
        expression->Print();
        cout << ")" << endl
             << "{";
        stmtlist->Print();
        cout << "}" << endl;
    }
};

class Condition_with_otherwise : public Stmt
{
    exprPtr expression;
    stmtListPtr stmtlist_1, stmtlist_2;

public:
    Condition_with_otherwise(Expr * expression,Expr * stmtlist_1,Expr * stmtlist_2):expression(expression),stmtlist_1(stmtlist_1),stmtlist_2(stmtlist_2) {
        this->setStmtType(STMTCONDITION_WITH_OTHERWISE);
        cout << "a condition with otherwise created" << endl;
    }
    void Print(){
        cout << "if (";
        expression->Print();
        cout << ")" << endl
             << "{";
        stmtlist_1->Print();
        cout << "}" << endl
             << "else"
             << "{" << endl;
        stmtlist_2->Print();
        cout << "}" << endl;
    }
};
#endif //COMPILER_STMT_H
