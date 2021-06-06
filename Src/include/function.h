#ifndef COMPILER_FUNCTION_H
#define COMPILER_FUNCTION_H

#include <memory>
#include "decl.h"

class FuncImpl;

class FuncList;

class FuncBody;

typedef unique_ptr<FuncImpl> funcImplPtr;
typedef unique_ptr<FuncList> funcListPtr;
typedef unique_ptr<FuncBody> funcBodyPtr;

class FuncBody {
    vector<stmtPtr> stmts;
    exprPtr exprReturn;
public:
    FuncBody(StmtList *stmts, Expr *exprReturn) {
        for (int i = 0, e = stmts->stmtList.size(); i < e; i++) {
            this->stmts.push_back(stmtPtr(stmts->stmtList[i]));
        }
        this->exprReturn = exprPtr(exprReturn);
    }

    void Print() {
        cout << "{" << endl;
        for (int i = 0, e = stmts.size(); i < e; i++) {
            stmts[i]->Print();
        }
        cout << "return ";
        if(exprReturn)
            exprReturn->Print();
        cout << endl << "}" << endl;
    }

    llvm::Value *CodeGen();

};

class FuncImpl {
    protoPtr proto;
    funcBodyPtr funcBody;
public:
    FuncImpl(Decl *proto, FuncBody *funcBody) {
        ProtoType *p = static_cast<ProtoType *>(proto);
        this->proto = protoPtr(p);
        this->funcBody = funcBodyPtr(funcBody);
    }

    void Print() {
        proto->Print();
        funcBody->Print();
        cout << endl;
    }

    llvm::Value *CodeGen();
};

// 函数实现体
class FuncList {
public:
    vector<FuncImpl *> functions;

    FuncList() {}

    void addFunction(FuncImpl *impl) {
        this->functions.push_back(impl);
    }
};

#endif //COMPILER_FUNCTION_H
