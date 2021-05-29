#include "../include/decl.h"
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
