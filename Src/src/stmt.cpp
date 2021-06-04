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