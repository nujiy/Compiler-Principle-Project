#ifndef COMPILER_PRINCIPLE_PROJECT_AST_H
#define COMPILER_PRINCIPLE_PROJECT_AST_H
#include <string>
#include <vector>
using namespace std;
#define OPADD 0
#define OPSUB 1
#define OPMUL 2
#define OPDIV 3
#define OPMOD 4
#define OPPOW 5
#define OPGT 6    // 大于
#define OPLT 7    // 小于
#define OPEQ 8    // 相等

#define TYPEBOOL 0
#define TYPEINT 1
#define TYPEFLOAT 2
#define TYPECHAR 3
#define TYPEVOID 4
#define TYPEBINARY 6


class Expr;
class BinaryExpr;
class Identifier;
class VariableDecl;

// 各类语句
class Stmt {
public:
    Stmt(){}
};

class StmtList {
    vector<Stmt*> stmtList;
public:
    StmtList(){}
    void addStmt(Stmt* stmt){
        this->stmtList.push_back(stmt);
    }
};


// 表达式
class Expr: public Stmt{
    int dType;
    Expr* valueptr;
public:
    Expr(){}
    void setDType(int dType){
        this->dType = dType;
    }

    int getType(){
        return dType;
    }

    virtual Expr* getValue(){
        if(dType!=TYPEBINARY)
        {
            return valueptr;
        }
        else{
            return valueptr->getValue();
        }
    }
};

// 值 也属于表达式
class Void:public Expr{
public:

};

class Integer:public Expr{
    int value;
public:
    Integer(int value):value(value){
        this->setDType(TYPEINT);
    }
};

class Float:public Expr{
    double value;
public:
    Float(double value):value(value){
        this->setDType(TYPEFLOAT);
    }
};

class Bool:public Expr{
    bool value;
public:
    Bool(bool value):value(value){
        this->setDType(TYPEBOOL);
    }
};

// 函数名、变量名标识符
class Identifier:public Expr {
    string& identifier;
public:
    Identifier(string& identifier):identifier(identifier){}
};

class IdentifierList{
    vector<Identifier*> idList;
public:
    IdentifierList(){}
    void addIdentifier(Expr* id){
        this->idList.push_back(dynamic_cast<Identifier*>(id));
    }
};

// 二元表达式
class BinaryExpr: public Expr{
    Expr* Left;
    Expr* Right;
    int op;
public:
    BinaryExpr(Expr* Left,Expr* Right,int op):Left(Left),Right(Right),op(op){
        if(op == TYPEBOOL)
            this->setDType(TYPEBOOL);
        else{
            this->setDType(Left->getType());
        }
    }
    Expr* getValue()
    {
        if(this->getType() == TYPEBOOL)
        {
            return new Bool(false);
        }
        else{
            // calcaulate value
        }
    }
};

class Decl:public Stmt{
public:
    Decl(){}
};

class DeclList{
    vector<Decl*> declList;
public:
    DeclList():declList(declList){}
    void addDecl(Decl* decl){
        this->declList.push_back(decl);
    }
};

// 变量声明 type name
class VariableDecl: public Decl{
    Identifier* name; // identifier
    Expr* value;
public:
    VariableDecl(int dType,Expr* name):name(dynamic_cast<Identifier*>(name)),value(new Expr()){
        name->setDType(dType);
    }
    VariableDecl(int dType,Expr* name,Expr* value):name(dynamic_cast<Identifier*>(name)),value(value){
        name->setDType(dType);
    }
};

// 函数原型 type name (params)
class ParamsList: public Decl{
    vector<Decl*> params;
public:
    ParamsList(){}
    ~ParamsList(){}
    ParamsList(vector<Decl*>& params):params(params){}
    void addParam(Decl* param){
        this->params.push_back(param);
    }
};

class ProtoType: public Decl{
    Expr* name;
    ParamsList* params;
public:
    ProtoType(int dType,Expr* funcName,ParamsList* params):name(funcName),params(params){
        funcName->setDType(dType);
    }
};

class StmtReturn: public Stmt{
    Expr* value;
public:
    StmtReturn(Expr* value):value(value){}
};

// 赋值语句
class Assignment:public Stmt{
    Identifier* identifier;
    Expr* expression;
public:
    Assignment(Expr* identifier,Expr* expression):identifier(dynamic_cast<Identifier*> (identifier)),expression(expression){
        
    }
};


class FuncCall:public Stmt{
    Identifier* funcName;
    IdentifierList* params;
public:
    FuncCall(Expr* funcName,IdentifierList* params): funcName(dynamic_cast<Identifier*> (funcName)),params(params){}

};

class FuncBody{
    StmtList* stmts;
    StmtReturn* stmtReturn;
public:
    FuncBody(StmtList* stmts,Stmt* stmtReturn):stmts(stmts),stmtReturn(static_cast<StmtReturn*>(stmtReturn)){}
};

class FuncImpl{
    ProtoType* proto;
    FuncBody* funcBody;
public:
    FuncImpl(Decl* proto,FuncBody* funcBody):proto(static_cast<ProtoType*>(proto)),funcBody(funcBody){}
};

// 函数实现体
class FuncList{
    vector<FuncImpl*> functions;
public:
    FuncList(){}
    void addFunction(FuncImpl* impl){
        this->functions.push_back(impl);
    }
};

class Block{
public:
    Block(){}
    virtual ~Block(){}
};

// 全局成员 包括函数声明与全局变量
class GlobalPart:public Block {
    DeclList* decls;
public:
    GlobalPart(DeclList* decls):decls(decls){}
};

// 主函数 main(){...}
class MainPart:public Block {
    FuncBody* mainFunc;
public:
    MainPart(FuncBody* mainFunc):mainFunc(mainFunc){}
};

class FuncPart:public Block {
    FuncList* functions;
public:
    FuncPart(FuncList* functions):functions(functions){}
};


class AST {
GlobalPart* Global;
MainPart* Main;
FuncPart* Function;
public:
    AST(Block* Global,Block* Main,Block* Function):Global(dynamic_cast<GlobalPart*> (Global)),Main(dynamic_cast<MainPart*> (Main)),Function(dynamic_cast<FuncPart*> (Function)){};
};

#endif //COMPILER_PRINCIPLE_PROJECT_AST_H
