#ifndef COMPILER_EXPR_H
#define COMPILER_EXPR_H

#include <memory>
#include "stmt.h"

using namespace std;

class ExprList;

class Identifier;

class ValueExpr;

typedef unique_ptr<ExprList> exprListPtr;
typedef unique_ptr<Identifier> idPtr;
typedef unique_ptr<ValueExpr> valuePtr;

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
    Float(double value) : value(value) {
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

#endif //COMPILER_EXPR_H
