#include "../include/stmt.h"

void printStmt(Stmt* stmt) {
    int stmtType = stmt->getStmtType();
    switch (stmtType)
    {
        case STMTEXPR:
            dynamic_cast<Expr*>(stmt)->Print();
            break;
        case STMTDECL:
            dynamic_cast<Decl*>(stmt)->Print();
            break;
        case STMTASSIGN:
            dynamic_cast<Assignment*>(stmt)->Print();
            break;
        default:
            break;
    }
}

void Expr::setDType(int dType){
    this->dType = dType;
}

int Expr::getDType(){
    return dType;
}

void Expr::setExprType(int exprType){
    this->exprType = exprType;
}

int Expr::getExprType(){
    return this->exprType;
}

exprPtr Expr::getValue(){
    if(dType!=EXPRBINARY)
    {
        return valueptr;
    }
    else{
        return valueptr->getValue();
    }
}