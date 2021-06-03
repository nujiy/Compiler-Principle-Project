#include "../include/expr.h"
static std::map<std::string,idPtr> symbolTable;

void printExpr(Expr* expr){
    int exprType = expr->getExprType();
    if( exprType == EXPRVALUE) {
        switch (expr->getDType())
        {
            case VALUEINT:
                static_cast<Integer*>(expr)->Print();
                break;
            case VALUEBOOL:
                static_cast<Bool*>(expr)->Print();
                break;
            case VALUEFLOAT:
                static_cast<Float*>(expr)->Print();
                break;
            default:
                break;
        }
    }
    else if(exprType == EXPRBINARY) {
        dynamic_cast<BinaryExpr*>(expr)->Print();
    }
    else if(exprType == EXPRID) {
        dynamic_cast<Identifier*>(expr)->Print();
    }
    else if(exprType == EXPRFUNCCALL){
        dynamic_cast<FuncCall*>(expr)->Print();
    }
}

