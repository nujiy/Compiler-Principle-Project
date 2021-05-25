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

class Expr;
class Identifier;
class VariableDecl;

// 数据类型
class DataType{
    string typeName;
public:
    DataType(const char* typeName){
        this->typeName = string(typeName);
    }
    string getType() {
        return typeName;
    }
};

// 各类语句
class Stmt {};


// 表达式
class Expr: public Stmt{
public:
    Expr(){}
};

// 值 也属于表达式
class Void:public Expr{
public:
    Void(){}
};

class Integer:public Expr{
    int value;
public:
    Integer(int value):value(value){}
};

class Float:public Expr{
    double value;
public:
    Float(double value):value(value){}
};

class Bool:public Expr{
    bool value;
public:
    Bool(bool value):value(value){}
};

// 函数名、变量名标识符
class Identifier:public Expr {
    string& identifier;
public:
    Identifier(string& identifier):identifier(identifier){}
};

class IdentifierList{
    vector<Expr*> idList;
public:
    IdentifierList(){}
    void addIdentifier(Expr* id){
        this->idList.push_back(id);
    }
};

// 二元表达式
class BinaryExpr: public Expr{
    Expr* Left;
    Expr* Right;
    int op;
public:
    BinaryExpr(Expr* Left,Expr* Right,int op):Left(Left),Right(Right),op(op){}
};

class Decl{};

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
    DataType* typeName;
    Expr* name;
    Expr* value;
public:
    VariableDecl(DataType* typeName,Expr* name):typeName(typeName),name(name),value(new Expr()){}
    VariableDecl(DataType* typeName,Expr* name,Expr* value):typeName(typeName),name(name),value(value){}
};

// 函数原型 type name (params)
class ParamsList: public Decl{
    vector<Decl*> params;
public:
    ParamsList(){}
    ParamsList(vector<Decl*>& params):params(params){}
    void addParam(Decl* param){
        this->params.push_back(param);
    }
};

class ProtoType: public Decl{
    DataType* typeName;
    Expr* name;
    ParamsList* params;
public:
    ProtoType(DataType* typeName,Expr* funcName,ParamsList* params):typeName(typeName),name(funcName),params(params){}
};

class StmtList {
    vector<Stmt*> stmtList;
public:
    StmtList(){}
    void addStmt(Stmt* stmt){
        this->stmtList.push_back(stmt);
    }
};

class StmtReturn: public Stmt{
    Expr* value;
public:
    StmtReturn(Expr* value):value(value){}
};

// 赋值语句
class Assignment:public Stmt{
    Expr* identifier;
    Expr* expression;
public:
    Assignment(Expr* identifier,Expr* expression):identifier(identifier),expression(expression){}
};


class FuncCall:public Stmt{
    Expr* funcName;
    IdentifierList* params;
public:
    FuncCall(Expr* funcName,IdentifierList* params): funcName(funcName),params(params){}

};

class FuncBody{
    StmtList* stmts;
    Stmt* stmtReturn;
public:
    FuncBody(StmtList* stmts,Stmt* stmtReturn):stmts(stmts),stmtReturn(stmtReturn){}
};

class FuncImpl{
    Decl* proto;
    FuncBody* funcBody;
public:
    FuncImpl(Decl* proto,FuncBody* funcBody):proto(proto),funcBody(funcBody){}
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

class Block{};

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
Block* Global;
Block* Main;
Block* Function;
public:
    AST(Block* Global,Block* Main,Block* Function):Global(Global),Main(Main),Function(Function){};
};

#endif //COMPILER_PRINCIPLE_PROJECT_AST_H
