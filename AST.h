#ifndef _AST_H
#define _AST_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define OPADD 0
#define OPSUB 1
#define OPMUL 2
#define OPDIV 3
#define OPMOD 4
#define OPPOW 5
#define OPGT 6    // larger than
#define OPLT 7    // less than
#define OPEQ 8    // equal

#define VALUEBOOL 0     // determine the type of expression value
#define VALUEINT 1
#define VALUEFLOAT 2
#define VALUECHAR 3
#define VALUEVOID 4

#define EXPRID 0    // determine the expr type variable | literal | binary-expression to be calculate
#define EXPRVALUE 1
#define EXPRBINARY 2

#define DECLVARIABLE 10
#define DECLPROTO 11
#define DECLPARAM 12

#define STMTEXPR 0
#define STMTASSIGN 1
#define STMTFUNCCALL 2
#define STMTDECL 3
#define STMTRETURN 4

class Stmt;

// stmt deriavtion
class Expr;
class Decl;
class Assignment;
class FuncCall;

// decl deriavtion
class VariableDecl;
class ProtoType;

// expr derivation
class BinaryExpr;
class Identifier;
class Integer;
class Float;
class Void;
class Bool;

void setMap();
string& getTypeMap(int index);
string& getOpMap(int index);
void printExpr(Expr* expr);
void printDecl(Decl* decl);
void printStmt(Stmt* stmt);

// 各类语句
class Stmt {
    int stmtType;
public:
    Stmt(){}
    ~Stmt(){}
    void setStmtType(int stmtType){
        this->stmtType = stmtType;
    }

    int getStmtType(){
        return this->stmtType;
    }

    virtual void Print(){
        printStmt(this);
    }
};

class StmtList {
    vector<Stmt*> stmtList;
public:
    StmtList(){}
    void addStmt(Stmt* stmt){
        this->stmtList.push_back(stmt);
    }
    void Print(){
        for(int i=0;i<stmtList.size();i++){
            stmtList[i]->Print();           
        }
    }
};

// 表达式
class Expr: public Stmt{
    int dType;
    int exprType;
    Expr* valueptr;
public:
    Expr(){
        dType = -1; // null node
        this->setStmtType(STMTEXPR);
    }
    ~Expr(){}
    void setDType(int dType){
        this->dType = dType;
    }

    int getDType(){
        return dType;
    }

    void setExprType(int exprType){
        this->exprType = exprType;
    }

    int getExprType(){
        return this->exprType;
    }

    virtual Expr* getValue(){
        if(dType!=EXPRBINARY)
        {
            return valueptr;
        }
        else{
            return valueptr->getValue();
        }
    }

    virtual void Print(){
        printExpr(this);
    }
};

// 值 也属于表达式
class Void:public Expr{
public:
   void Print(){}
};

class Integer:public Expr{
    int value;
public:
    Integer(int value):value(value){
        this->setDType(VALUEINT);
        this->setExprType(EXPRVALUE);
    }
    void Print(){
        cout<<value;
    }
};

class Float:public Expr{
    double value;
public:
    Float(double value):value(value){
        this->setDType(VALUEFLOAT);
        this->setExprType(EXPRVALUE);

    }
    void Print(){
        cout<<value;
    }
};

class Bool:public Expr{
    bool value;
public:
    Bool(bool value):value(value){
        this->setDType(VALUEBOOL);
        this->setExprType(EXPRVALUE);
    }
    void Print(){
        cout<<value;
    }
};

// 函数名、变量名标识符
class Identifier:public Expr {
    string identifier;
public:
    Identifier(const char* identifier){
        this->identifier = string(identifier); 
        this->setExprType(EXPRID);
    }

    void Print(){
        cout<<identifier;
    }
};

class IdentifierList{
    vector<Identifier*> idList;
public:
    IdentifierList(){}
    void addIdentifier(Expr* id){
        this->idList.push_back(dynamic_cast<Identifier*>(id));
    }
    void Print(){
        for(int i=0;i<idList.size();i++){
            if(i==0){
                idList[i]->Print();
            }
            else{
                cout<<',';
                idList[i]->Print();
            }
        }
    }
};

// 二元表达式
class BinaryExpr: public Expr{
    Expr* Left;
    Expr* Right;
    int op;
public:
    BinaryExpr(Expr* Left,Expr* Right,int op):Left(Left),Right(Right),op(op) {
        this->setExprType(EXPRBINARY);

        if(op == OPEQ || op==OPLT || op == OPGT)
            this->setDType(VALUEBOOL);
        else{
            this->setDType(Left->getDType());
        }
    }

    Expr* getValue() {
        if(this->getDType() == VALUEBOOL)
        {
            return new Bool(false);
        }
        else{
            // calcaulate value
        }
    }

    void Print() {
        cout<<"(";
        this->Left->Print();
        cout<<")"<< getOpMap(this->op)<<"(";
        this->Right->Print();
    }
};

class Decl:public Stmt{
    int declType;
public:
    Decl(){
        this->setStmtType(STMTDECL);
    }
    void setDeclType(int declType){
        this->declType = declType;
    }

    int getDeclType(){
        return this->declType;
    }

    virtual void Print(){
        printDecl(this);
    }
};

class DeclList{
    vector<Decl*> declList;
public:
    DeclList():declList(declList){}
    void addDecl(Decl* decl){
        this->declList.push_back(decl);
    }
    void Print()
    {
        for(int i=0;i<this->declList.size();i++) {
            declList[i]->Print();
        }
    }
};

// 变量声明 type name
class VariableDecl: public Decl{
    Expr* name; // identifier
    Expr* value;
public:
    VariableDecl(int dType,Expr* name):name(name),value(new Expr()){
        name->setDType(dType);
        this->setDeclType(DECLVARIABLE);
    }
    VariableDecl(int dType,Expr* name,Expr* value):name(name),value(value){
        name->setDType(dType);
        this->setDeclType(DECLPROTO);
    }
    void Print()
    {
        cout<<getTypeMap(name->getDType())<<" ";
        name->Print();
        cout<<" ";
        value->Print();
        cout<<endl;
    }
};

// 函数原型 type name (params)
class ParamsList: public Decl{
    vector<Decl*> params;
public:
    ParamsList(){
        this->setDeclType(DECLPARAM);
    }
    ~ParamsList(){}
    ParamsList(vector<Decl*>& params):params(params){
        this->setDeclType(DECLPARAM);
    }
    void addParam(Decl* param){
        this->params.push_back(param);
    }
    void Print(){
        for(int i=0;i<params.size();i++){
            if(i==0){
                params[i]->Print();
            }
            else{
                cout<<" ,";
                params[i]->Print();
            }
        }
        cout<<endl;
    }
};

class ProtoType: public Decl{
    Expr* name;
    ParamsList* params;
public:
    ProtoType(int dType,Expr* funcName,ParamsList* params):name(funcName),params(params){
        funcName->setDType(dType);
        this->setDeclType(DECLPROTO);
    }
    void Print(){
        cout<<getTypeMap(name->getDType())<<" ";
        name->Print();
        cout<<" (";
        params->Print();
        cout<<")"<<endl;
    }
};

class StmtReturn: public Stmt{
    Expr* value;
public:
    StmtReturn(Expr* value):value(value){
        this->setStmtType(STMTRETURN);
    }
    void Print(){
        cout<<"return ";
        value->Print();
        cout<<endl;
    }
};

// 赋值语句
class Assignment:public Stmt{
    Identifier* identifier;
    Expr* expression;
public:
    Assignment(Expr* identifier,Expr* expression):identifier(dynamic_cast<Identifier*> (identifier)),expression(expression){
        this->setStmtType(STMTASSIGN);
    }
    void Print(){
        identifier->Print();
        cout<<"=";

        int exprType = expression->getExprType();
        

        expression->Print();
        cout<<endl;
    }
};

class FuncCall:public Stmt{
    Identifier* funcName;
    IdentifierList* params;
public:
    FuncCall(Expr* funcName,IdentifierList* params): funcName(dynamic_cast<Identifier*> (funcName)),params(params){
        this->setStmtType(STMTFUNCCALL);
    }
    void Print(){
        funcName->Print();
        cout<<"(";
        params->Print();
        cout<<")"<<endl;
    }
};

class FuncBody{
    StmtList* stmts;
    StmtReturn* stmtReturn;
public:
    FuncBody(StmtList* stmts,Stmt* stmtReturn):stmts(stmts),stmtReturn(static_cast<StmtReturn*>(stmtReturn)){}
    void Print(){
        stmts->Print();
        stmtReturn->Print();
    }
};

class FuncImpl{
    ProtoType* proto;
    FuncBody* funcBody;
public:
    FuncImpl(Decl* proto,FuncBody* funcBody):proto(static_cast<ProtoType*>(proto)),funcBody(funcBody){}
    void Print(){
        proto->Print();
        cout<<endl<<"{";
        funcBody->Print();
        cout<<"}"<<endl;
    }
};

// 函数实现体
class FuncList{
    vector<FuncImpl*> functions;
public:
    FuncList(){
        cout<<"create FuncList node"<<endl;
    }
    void addFunction(FuncImpl* impl){
        this->functions.push_back(impl);
        cout<<"impl a function"<<endl;
    }

    void Print(){
        for(int i = 0;i<functions.size();i++){
            functions[i]->Print();
        }
    }
};

class Block{
public:
    Block(){}
    virtual ~Block(){}
    virtual void Print() {};
};

// 全局成员 包括函数声明与全局变量
class GlobalPart:public Block {
    DeclList* decls;
public:
    GlobalPart(DeclList* decls):decls(decls){}
    void Print(){
        decls->Print();
    }
};

// 主函数 main(){...}
class MainPart:public Block {
    FuncBody* mainFunc;
public:
    MainPart(FuncBody* mainFunc):mainFunc(mainFunc){}
    void Print(){
        mainFunc->Print();
    }
};

class FuncPart:public Block {
    FuncList* functions;
public:
    FuncPart(FuncList* functions):functions(functions){}
    void Print(){
        functions->Print();
    }
};


class AST {
GlobalPart* Global;
MainPart* Main;
FuncPart* Function;
public:
    AST(Block* Global,Block* Main,Block* Function):Global(dynamic_cast<GlobalPart*> (Global)),Main(dynamic_cast<MainPart*> (Main)),Function(dynamic_cast<FuncPart*> (Function)){
        cout<<"create AST node"<<endl;
        setMap();
    };
    void Print()
    {
        Global->Print();
        Main->Print();
        Function->Print();
    }
};

#endif //_AST_H
