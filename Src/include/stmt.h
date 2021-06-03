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

class StmtList;

void printStmt(Stmt *stmt);

extern void printExpr(Expr *expr);

extern void printDecl(Decl *decl);

typedef unique_ptr<Node> nodePtr;
typedef unique_ptr<Stmt> stmtPtr;
typedef unique_ptr<StmtList> stmtListPtr;
typedef unique_ptr<Expr> exprPtr;
typedef unique_ptr<Decl> declPtr;

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

#endif //COMPILER_STMT_H
