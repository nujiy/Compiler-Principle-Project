#include "AST.h"
map<int,string> typeMap;
map<int,string> opMap;

void setMap()
{
    typeMap[VALUEBOOL] = "Bool";
    typeMap[VALUEINT] = "Int";
    typeMap[VALUEFLOAT] = "Float";
    typeMap[VALUEVOID] = "Void";
    opMap[OPADD] = "+";
    opMap[OPSUB] = "-";
    opMap[OPDIV] = "/";
    opMap[OPMUL] = "*";
    opMap[OPMOD] = "%"; 
    opMap[OPPOW] = "^";
    opMap[OPEQ] = "==";
    opMap[OPGT] = ">";
    opMap[OPLT] = "<";
}

string& getTypeMap(int index)
{
    return typeMap[index];
}

string& getOpMap(int index){
    return opMap[index];
}

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

void printDecl(Decl* decl) {
    int declType = decl->getDeclType();
    switch (declType)
    {
    case DECLVARIABLE:
        dynamic_cast<VariableDecl*>(decl)->Print();
        break;
    case DECLPROTO:
        dynamic_cast<ProtoType*>(decl)->Print();
        break;
    default:
        break;
    }
}
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