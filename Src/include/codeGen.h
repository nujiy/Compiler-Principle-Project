#ifndef PARSER_CODEGEN_H
#define PARSER_CODEGEN_H

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/AssemblyAnnotationWriter.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include <memory>
#include <map>
#include <string>
#include <iostream>
#include "AST.h"
#include "stmt.h"
#include "expr.h"
#include "decl.h"
#include "function.h"
#include "util.h"

using namespace llvm;

static AllocaInst *createEntryBlockAlloca(Function *function, Value* size ,const std::string &name, Type *type);

static Function *getFunction(std::string name);

Value *IRError(string msg);

Value *StmtCodeGen(Stmt *stmt);

Value *ExprCodeGen(Expr *expr);

Type *TypeGen(int type,int size);

bool CheckArith(int, int, int *);

bool CheckCmp(int, int);

bool CheckLogic(int, int);

class SymbolTable {
    std::vector<std::map<std::string,AllocaInst*>*> namedValue;   // address map
    std::vector<std::map<string,Identifier*>*> tables;  // id map
    std::vector<std::map<string,ArrayDecl*>*> arrays;
public:
    SymbolTable(){}

    AllocaInst* findVar(Expr* id,int size){
        if(id->getExprType() == EXPRID){
            return findVar(static_cast<Identifier*>(id)->getId());
        }

        if(id->getExprType() == EXPRARRAY){
            return findVar(static_cast<ArrayExpr*>(id)->getId());
        }
    }

    AllocaInst* findVar(string name){
        for(int i=namedValue.size()-1;i>=0;i--){
            if(namedValue[i]->find(name) != namedValue[i]->end())
                return (*namedValue[i])[name];
        }
        return nullptr; //can't find
    }

    Identifier* findSymbol(string name){
        for(int i=tables.size()-1;i>=0;i--){
            if(tables[i]->find(name) != tables[i]->end())
                return (*tables[i])[name];
        }
        return nullptr; //can't find
    }

    ArrayDecl* findArray(string name){
        for(int i= arrays.size()-1;i>=0;i--){
            if(arrays[i]->find(name) != arrays[i]->end())
                return (*arrays[i])[name];
        }
        return nullptr;
    }

    void addVar(string name,AllocaInst* var){
        if(namedValue.size() <= 0)
            pushVarTable();

        (*namedValue.back())[name] = var;
    }


    void addSymbol(string name,Identifier* id){
        if(tables.size() <= 0)
            pushSymbolTable();
        (*tables.back())[name] = id;
    }

    void addArray(string name,ArrayDecl* array){
        if(arrays.size()<=0)
            pushArrayTable();

        (*arrays.back())[name] = array;
    }

    void pushVarTable(){
        namedValue.push_back(new std::map<string,AllocaInst*>());
    }

    void pushSymbolTable(){
        tables.push_back(new std::map<string,Identifier*>());
    }

    void pushArrayTable(){
        arrays.push_back(new std::map<string,ArrayDecl*>());
    }

    void popVarTable(){
        if(namedValue.size() > 0){
            namedValue.pop_back();
        }
    }

    void popSymbolTable(){
        if(tables.size()>0)
            tables.pop_back();
    }

    void popArrayTable(){
        if(arrays.size()>0)
            arrays.pop_back();
    }
};

#endif //PARSER_CODEGEN_H
