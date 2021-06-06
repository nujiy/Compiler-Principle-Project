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
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "AST.h"
#include "stmt.h"
#include "expr.h"
#include "decl.h"
#include "function.h"
#include "util.h"

using namespace llvm;


static LLVMContext context;
static IRBuilder<> irBuilder(context);
static std::unique_ptr<Module> thisModule;

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
    std::vector<std::map<string,Identifier*>*> idTable;  //local id map
    std::map<std::string, Identifier *> globalIdTable;  // global id

    std::vector<std::map<std::string,AllocaInst*>*> namedValue;   // local variable allocation
    std::map<std::string, GlobalVariable*> globalNamedValue;    //global variable allocation

    std::vector<std::map<string,ArrayDecl*>*> namedArray;   // local array allocation
    std::map<string,ArrayDecl*> globalNamedArray;   //global array map

    std::map<std::string, protoPtr> protoMap;   // function prototype

public:
    SymbolTable(){}

    void clear(){
        globalNamedValue.clear();
        globalIdTable.clear();
    }

    bool isGlobal(string& name){
        if(globalNamedArray.find(name) != globalNamedArray.end())
            return true;

        return false;
    }

    bool judgeSymbolRedefine(string name){
        if(namedValue.size()<=0){
            return false;
        }

        if(namedValue.back()->find(name) == namedValue.back()->end())
            return false;

        return true;
    }

    bool judgeArrayRedefine(string name){
        if(namedArray.size()<=0){
            return false;
        }

        if(namedArray.back()->find(name) != namedArray.back()->end())
            return false;

        return true;
    }

    Value* findVar(Expr* id){

        if(id->getExprType() == EXPRID){
            string name = static_cast<Identifier*>(id)->getId();
            Value* v = findVar(name);
            if(!v)
            {
                return findGlobalVar(name);
            }
            return v;
        }

        if(id->getExprType() == EXPRARRAY){
            ArrayExpr* arrayExpr = static_cast<ArrayExpr*>(id);
            AllocaInst* startAddr = findVar(arrayExpr->getId());

            Expr* indexExpr = arrayExpr->getIndex();

            if(startAddr){
                if(!indexExpr)
                    return startAddr;

                Value* index = arrayExpr->getIndex()->CodeGen();
                Value* access =  irBuilder.CreateGEP(startAddr,index,"access");
                return access;
            }
            else
            {
                GlobalVariable* glbStartAddr = findGlobalVar(arrayExpr->getId());
                if(!indexExpr)
                    return glbStartAddr;
                Value* index = arrayExpr->getIndex()->CodeGen();
                if(glbStartAddr){
                    Value* access = irBuilder.CreateGEP(glbStartAddr,index,"access");
                    return access;
                }
            }
        }
        return nullptr;
    }

    AllocaInst* findVar(string name){
        for(int i=namedValue.size()-1;i>=0;i--){
            if(namedValue[i]->find(name) != namedValue[i]->end())
                return (*namedValue[i])[name];

        }
        return nullptr; //can't find
    }

    GlobalVariable* findGlobalVar(string name){
        if(globalNamedValue.find(name) != globalNamedValue.end())
            return globalNamedValue[name];

        return nullptr;
    }

    //TODO cpp清理
    Identifier* findSymbol(string name){
        for(int i=idTable.size()-1;i>=0;i--){
            if(idTable[i]->find(name) != idTable[i]->end())
                return (*idTable[i])[name];
        }

        if(globalIdTable.find(name)!=globalIdTable.end())
            return globalIdTable[name];

        return nullptr; //can't find
    }

    ArrayDecl* findArray(string name){
        for(int i= namedArray.size()-1;i>=0;i--){
            if(namedArray[i]->find(name) != namedArray[i]->end())
                return (*namedArray[i])[name];
        }

        if(globalNamedArray.find(name) != globalNamedArray.end())
            return globalNamedArray[name];

        return nullptr;
    }

    void addVar(string name,AllocaInst* var){
        if(namedValue.size() <= 0)
            pushVarTable();

        (*namedValue.back())[name] = var;
    }

    void addGlobalVar(string name,GlobalVariable* glb){
        globalNamedValue[name] = glb;
    }

    void addLocalSymbol(string name,Identifier* id){
        if(idTable.size() <= 0)
            pushSymbolTable();
        (*idTable.back())[name] = id;
    }

    void addGlobalSymbol(string name,Identifier* id){
        globalIdTable[name] = id;
    }

    void addLocalArray(string name,ArrayDecl* array){
        if(namedArray.size()<=0)
            pushArrayTable();

        (*namedArray.back())[name] = array;
    }

    void addGlobalArray(string name,ArrayDecl* array){
        globalNamedArray[name] = array;
    }

    void pushVarTable(){
        namedValue.push_back(new std::map<string,AllocaInst*>());
    }

    void pushSymbolTable(){
        idTable.push_back(new std::map<string,Identifier*>());
    }

    void pushArrayTable(){
        namedArray.push_back(new std::map<string,ArrayDecl*>());
    }

    void popVarTable(){
        if(namedValue.size() > 0){
            namedValue.pop_back();
        }
    }

    void popSymbolTable(){
        if(idTable.size()>0)
            idTable.pop_back();
    }

    void popArrayTable(){
        if(namedArray.size()>0)
            namedArray.pop_back();
    }
};

#endif //PARSER_CODEGEN_H
