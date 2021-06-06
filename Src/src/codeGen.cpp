#include "../include/codeGen.h"

static LLVMContext context;
static IRBuilder<> irBuilder(context);
static std::unique_ptr<Module> thisModule;

/// save repeated variable and make sense for error checking
/// it should be cleaned when jump out of a block
static std::map<std::string, AllocaInst *> oldValue;
static std::map<std::string, protoPtr> protoMap;
static SymbolTable localSymbolTable;
static std::map<std::string, Identifier *> globalSymbolTable;
static std::map<std::string, GlobalVariable*> globalValue;

Type *TypeGen(int type,int size = 0) {
    switch (type) {
        case VALUEINT:
            return Type::getInt32Ty(context);
        case VALUEFLOAT:
            return Type::getFloatTy(context);
        case VALUEBOOL:
            return Type::getInt1Ty(context);
        case VALUEVOID:
            return Type::getVoidTy(context);
        case VALUECHAR:
            return Type::getInt8Ty(context);
        default:
            return Type::getInt32Ty(context);
    }
}

bool CheckArith(int l, int r, int *ret) {
    if ((l == VALUEFLOAT || l == VALUEINT) && (r == VALUEFLOAT || r == VALUEINT)) {
        *ret = l > r ? l : r;
        return true;
    }
    return false;
}

bool CheckCmp(int l, int r) {
    if (!l || !r)
        return false;

    if ((l == VALUEFLOAT || l == VALUEINT) && (r == VALUEFLOAT || r == VALUEINT)) {
        return true;
    }
    return false;
}

bool CheckLogic(int l, int r) {
    if (l == VALUEBOOL && r == VALUEBOOL)
        return true;

    return false;
}

Value *ExprCodeGen(Expr *expr) {
    int exprType = expr->getExprType();
    if (exprType == EXPRVALUE) {
        ValueExpr *valueExpr = dynamic_cast<ValueExpr *>(expr);
        switch (valueExpr->getValueType()) {
            case VALUEINT:
                return dynamic_cast<Integer *>(expr)->CodeGen();
            case VALUEBOOL:
                return dynamic_cast<Bool *>(expr)->CodeGen();
            case VALUEFLOAT:
                return dynamic_cast<Float *>(expr)->CodeGen();
            default:
                break;
        }
    } else if (exprType == EXPRBINARY) {
        BinaryExpr* binaryExpr = dynamic_cast<BinaryExpr*>(expr);
        binaryExpr->getDType();
        return binaryExpr->CodeGen();
    } else if (exprType == EXPRID) {
        return dynamic_cast<Identifier *>(expr)->CodeGen();
    } else if (exprType == EXPRFUNCCALL) {
        return dynamic_cast<FuncCall *>(expr)->CodeGen();
    }

    return nullptr;
}

Value *StmtCodeGen(Stmt *stmt) {
    int stmtType = stmt->getStmtType();
    switch (stmtType) {
        case STMTASSIGN:
            return dynamic_cast<Assignment *>(stmt)->CodeGen();
        case STMTDECL:
            return dynamic_cast<Decl *>(stmt)->CodeGen();
        case STMTEXPR:
            return dynamic_cast<Expr *>(stmt)->CodeGen();
        default:
            return nullptr;
    }
}

Value *DeclCodeGen(Decl *decl) {
    int declType = decl->getDeclType();
    switch (declType) {
        case DECLPROTO:
            return dynamic_cast<ProtoType *>(decl)->CodeGen();
        case DECLARRAY:
            return dynamic_cast<ArrayDecl *>(decl)->CodeGen();
        case DECLVARIABLE:
            return dynamic_cast<VariableDecl *>(decl)->CodeGen();
        default:
            return nullptr;
    }
}

// codes below have referencd llvm kaleidoscope example
Value *IRError(std::string msg) {
    std::cout << msg << std::endl;
    return nullptr;
}

static AllocaInst *createEntryBlockAlloca(Function *function,Value* size,const std::string &name, Type *type) {
    // get a IRbuilder object pointer to the entry of the function
    IRBuilder<> tmp(&function->getEntryBlock(), function->getEntryBlock().begin());

    return tmp.CreateAlloca(type, size, name.c_str());
}

static Function *getFunction(std::string name) {
    if (auto *f = thisModule->getFunction(name))
        return f;

    // if not find code gen the declaration from function map
    // if there is a call before function body, make sure it'll find the proper function
    auto fp = protoMap.find(name);

    if (fp != protoMap.end())
        return fp->second->FunctionGen();   // generate a function ptoto

    IRError("undefined prototype");
    return nullptr;
}

static Value* SysPrint(vector<exprPtr>& params,bool printLine){
    static Function* llvmPrint = nullptr;
    if(llvmPrint == nullptr){
        std::vector<Type*> argTypes = {Type::getInt8PtrTy(context)};
        FunctionType* funcType = FunctionType::get(Type::getInt32Ty(context), argTypes,true);
        Function* func = Function::Create(funcType,Function::ExternalLinkage,"printf",thisModule.get());
        func->setCallingConv(CallingConv::C);
        llvmPrint = func;
    }
    std::string format;
    std::vector<Value*> printArgs;
    printArgs.emplace_back(nullptr);    // the first element is to store format

    for(int i=0,e = params.size();i<e;i++){
        int type = params[i]->getDType();

        if(params[i]->getExprType() == EXPRID){
            type = localSymbolTable.findSymbol(static_cast<Identifier*>(params[i].get())->getId())->getDType();
        }

        if(type == VALUEINT){
            format += "%d";
            printArgs.emplace_back(params[i]->CodeGen());
        }
        else if(type == VALUEFLOAT){
            format += "%lf";
            printArgs.emplace_back(params[i]->CodeGen());
        }
        else if(type == VALUESTRING){
            format += "%s";
            printArgs.emplace_back(params[i]->CodeGen());
        }
        else{
            return IRError("unsupported print type");
        }
    }

    if(printLine){
        format += "\n";
    }
    printArgs[0] = irBuilder.CreateGlobalStringPtr(format,"print_format");
    return irBuilder.CreateCall(llvmPrint,printArgs,"call_printf");
}

static Value* SysRead(vector<exprPtr>& params,bool readLine){
    static Function* llvmRead = nullptr;
    if(llvmRead == nullptr){
        std::vector<Type*> argTypes = {Type::getInt8PtrTy(context)};
        FunctionType* funcType = FunctionType::get(Type::getInt32Ty(context),argTypes,true);
        Function* func = Function::Create(funcType,Function::ExternalLinkage,"scanf",thisModule.get());

        func->setCallingConv(CallingConv::C);
        llvmRead = func;
    }

    std::string format;
    std::vector<Value*> readArgs;
    readArgs.emplace_back(nullptr);

    for(int i=0,e=params.size();i<e;i++){
        int type = params[i]->getDType();
        if(params[i]->getExprType() == EXPRID){
            type = localSymbolTable.findSymbol(static_cast<Identifier*>(params[i].get())->getId())->getDType();
        }

        if(type == VALUEINT){
            format += "%d";
        }
        else if(type == VALUEFLOAT){
            format += "%lf";
        }
        else if(type == VALUESTRING){
            format += "%s";
        }
        else{
            return IRError("unsupported read type");
        }

        readArgs.emplace_back(params[i]->CodeGen());
    }

    if(readLine){
        format += "%*[^\n]";
    }

    readArgs[0] = irBuilder.CreateGlobalStringPtr(format,"read_format");
    Value* ret = irBuilder.CreateCall(llvmRead,readArgs,"call_read");

    if(readLine){
        irBuilder.CreateCall(llvmRead,irBuilder.CreateGlobalStringPtr("%*c","read_new_line"),"call_read");
    }
    return ret;
}

bool isIO(std::string name){
    if(name == "print" || name == "read" || name == "readln" || name == "println"){
        return true;
    }

    return false;
}

Value* getIO(std::string id,std::vector<exprPtr>& params){
    if(id == "print") return SysPrint(params,false);
    if(id =="read") return SysRead(params,false);
    if(id == "println") return SysPrint(params,true);
    if(id == "readln") return SysRead(params,true);
    return nullptr;
}

void AST::CodeGen() {
    thisModule = std::make_unique<Module>("IRGen", context);

    Global->CodeGen();
    Main->CodeGen();
    Function->CodeGen();

    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto targetTriple = sys::getDefaultTargetTriple();
    thisModule->setTargetTriple(targetTriple);

    std::string error;
    auto target = TargetRegistry::lookupTarget(targetTriple, error);

    if (!target) {
        errs() << error;
        return;
    }

    auto cpu = "generic";
    auto feature = "";

    TargetOptions opt;
    auto rm = Optional<Reloc::Model>();
    auto targetMachine = target->createTargetMachine(targetTriple, cpu, feature, opt, rm);

    thisModule->setDataLayout(targetMachine->createDataLayout());
    thisModule->setTargetTriple(targetTriple);

    raw_os_ostream irout(std::cout);
    int fd = open("test.ll",O_CREAT | O_WRONLY,0644);

    if(fd <0){
        std::cerr<<"can't open file test.ll: "<<errno<<std::endl;
    }

    if(_dup2(fd,1)<0){
        std::cerr<<"can't dup file test.ll to stdout: "<<errno<<std::endl;
    }
    close(fd);

    thisModule->print(outs(), nullptr);
    globalValue.clear();
    globalSymbolTable.clear();


    auto filename = "test.exe";
    std::error_code ec;
    raw_fd_ostream dst(filename, ec, sys::fs::OF_None);

    if (ec) {
        errs() << "couldn't open file" << ec.message() << "\n";
        return;
    }

    legacy::PassManager pass;
    auto fileType = CGFT_ObjectFile;

    if (targetMachine->addPassesToEmitFile(pass, dst, nullptr, fileType)) {
        errs() << "TargetMachine can't emit a file of this type" << "\n";
        return;
    }

    pass.run(*(thisModule.get()));
    dst.flush();

//    std::cout << "wrote " << filename << "\n";
    return;
}

void GlobalPart::CodeGen() {
    for (int i = 0, e = decls.size(); i < e; i++) {
        if (decls[i]->getDeclType() == DECLVARIABLE) {
            static_cast<VariableDecl *>(decls[i].get())->GlobalGen();
        } else if (decls[i]->getDeclType() == DECLARRAY) {
            //TODO global Array
            static_cast<ArrayDecl *>(decls[i].get())->CodeGen();
        } else if (decls[i]->getDeclType() == DECLPROTO) {
            static_cast<ProtoType *>(decls[i].get())->CodeGen();
        } else {
            IRError("unrecognized declaration");
        }
    }
}

void MainPart::CodeGen() {
    // get main function block
    FunctionType *funcType = FunctionType::get(TypeGen(VALUEINT), false);
    Function *_main_ = Function::Create(funcType, Function::ExternalLinkage, "main", thisModule.get());
    BasicBlock *entry = BasicBlock::Create(context, "entry", _main_);
    irBuilder.SetInsertPoint(entry);
    localSymbolTable.pushSymbolTable();
    localSymbolTable.pushVarTable();

    irBuilder.CreateRet(mainFunc->CodeGen());
    verifyFunction(*_main_);
    localSymbolTable.popSymbolTable();
    localSymbolTable.popVarTable();
}

void FuncPart::CodeGen() {
    for (int i = 0, e = functions.size(); i < e; i++) {
        functions[i]->CodeGen();
        functions[i]->Print();
    }
}

Value *Stmt::CodeGen() {
    return StmtCodeGen(this);
}

Value* ForLoop::CodeGen(){
    Identifier* loopID = static_cast<Identifier*>(getVar());
    Function* atFunc = irBuilder.GetInsertBlock()->getParent();

    BasicBlock* startBB = BasicBlock::Create(context,"init",atFunc);
    BasicBlock* loopBodyBB = BasicBlock::Create(context,"loop",atFunc);
    BasicBlock* condBB = BasicBlock::Create(context,"cond",atFunc);
    BasicBlock* endBB = BasicBlock::Create(context,"endLoop",atFunc);
    irBuilder.CreateBr(startBB);
    irBuilder.SetInsertPoint(startBB);

    // defined first before use
    //TODO check existence
//    AllocaInst* alloca = localSymbolTable.findVar(loopID->getId());
//    // initial value from current scope
//    Value* startValue = getInitValue()->CodeGen();
//    if(!startValue)
//        return nullptr;
//    irBuilder.CreateStore(startValue,alloca);
    if(!initAssign->CodeGen())
        return nullptr;

    Value* cond = condition->CodeGen();
    if(!cond){
        return IRError("need condition expression in for loop");
    }

    localSymbolTable.pushVarTable();
    localSymbolTable.pushSymbolTable();

    irBuilder.CreateCondBr(cond,endBB,loopBodyBB);
    irBuilder.SetInsertPoint(loopBodyBB);

    for(int i=0,e = stmtlist.size();i<e;i++)
        stmtlist[i]->CodeGen();

    irBuilder.CreateBr(condBB);
    irBuilder.SetInsertPoint(condBB);

    // update value
//    Value* stepValue = nullptr;
//    if(getStepValue()){
//        stepValue = getStepValue()->CodeGen();
//        if(!stepValue)
//            return nullptr;
//    }
//    else{
//        stepValue = getStepValue()->CodeGen();
//    }
//
//    AllocaInst* alloca = localSymbolTable.findVar(loopID->getId());
//    irBuilder.CreateStore(stepValue,alloca);
    stepAssign->CodeGen();
    cond = condition->CodeGen();
    irBuilder.CreateCondBr(cond, endBB,loopBodyBB);
    irBuilder.SetInsertPoint(endBB);

    localSymbolTable.popSymbolTable();
    localSymbolTable.popVarTable();
    return Constant::getNullValue(TypeGen(VALUEFLOAT));
}

Value* ConditionBlock::CodeGen(){
    localSymbolTable.pushSymbolTable();
    localSymbolTable.pushVarTable();

    for(int i=0,e=stmtList.size();i<e;i++){
        stmtList[i]->CodeGen();
    }
    if(returnExpr){
        Value* retVal = returnExpr->CodeGen();
        irBuilder.CreateRet(retVal);
        return retVal;
    }
    localSymbolTable.popVarTable();
    localSymbolTable.popSymbolTable();
    return nullptr;
}

Value* Condition::CodeGen() {
    Value* cond = expression->CodeGen();
    if(!cond){
        return IRError("if without condition");
    }

    Function *atFunc = irBuilder.GetInsertBlock()->getParent();

    BasicBlock* thenBB = BasicBlock::Create(context,"then",atFunc); //atFunc necessary?
    BasicBlock* elseBB = BasicBlock::Create(context,"else",atFunc);
    BasicBlock* mergeBB = BasicBlock::Create(context,"cont",atFunc);

    irBuilder.CreateCondBr(cond,thenBB, elseBB);
    irBuilder.SetInsertPoint(thenBB);

    if(block.size()<1){
        return IRError("no list");
    }

    block[0]->CodeGen();

    irBuilder.CreateBr(mergeBB);
    irBuilder.SetInsertPoint(elseBB);

    // else
    if(block.size()==2){
        block[1]->CodeGen();
    }

    irBuilder.CreateBr(mergeBB);
    irBuilder.SetInsertPoint(mergeBB);

    return nullptr;
}

Value *Assignment::CodeGen() {
    Expr *p = identifier.get();

    string varName;
    if(identifier->getExprType() == EXPRID)
        varName = static_cast<Identifier *>(p)->getId();
    else if(identifier->getExprType() == EXPRARRAY)
        varName = static_cast<ArrayExpr *>(p)->getId();
    else;

    Value *init;
    // a variable or the start address of an array
    auto varAddr = localSymbolTable.findVar(varName);

    if (!varAddr) {
        //Global array
        auto glbAddr = globalValue.find(varName);
        if (glbAddr == globalValue.end()) {
            IRError("undefined variable");
            return nullptr;
        } else {
            // assign global
            GlobalVariable *glb = globalValue[varName];
            init = expression->CodeGen();
            if (p->getDType() == VALUEFLOAT && expression->getDType() == VALUEINT)
                init = irBuilder.CreateUIToFP(init, TypeGen(VALUEFLOAT));
            glb->setInitializer(static_cast<Constant *>(init));

            return init;
        }
    }

    if (expression) {
        // get value address from expression
        if (!(init = expression->CodeGen())) {
            return nullptr;
        }
    } else {
        IRError("assignment not find a expression");
        return nullptr;
    }

    if(identifier->getExprType() == EXPRARRAY){
        //array address
        Value* alloca = p->CodeGen();  // get element address
        irBuilder.CreateStore(init,alloca);
    }
    else if(identifier->getExprType() == EXPRID){
        // assign value
        AllocaInst *alloca = varAddr;
        irBuilder.CreateStore(init, alloca);
    }
    return init;
}

Value *Decl::CodeGen() {
    return DeclCodeGen(this);
}

void ArrayDecl::setArrayType(){
    ArrayType* arrayType = ArrayType::get(TypeGen(dType),this->size);
    this->arrayType = arrayType;
}

Value* ArrayDecl::CodeGen() {
    Function *atFunc = irBuilder.GetInsertBlock()->getParent();

    // if it is real decl not
    Value* sizeValue = ConstantInt::get(TypeGen(VALUEINT),size);
    AllocaInst* arrAlloca = createEntryBlockAlloca(atFunc,sizeValue,name->getId(), TypeGen(dType));

    localSymbolTable.addArray(name->getId(),this);
    localSymbolTable.addVar(name->getId(),arrAlloca);
    return sizeValue;
}

/// used only when generating global variable
void VariableDecl::GlobalGen() {
    Value *init;
    if (globalValue.find(getID()) != globalValue.end()) {
        IRError("redefined global variable");
        return;
    }

    GlobalVariable *glb = new GlobalVariable(*thisModule, TypeGen(getVarType()), 0, GlobalVariable::CommonLinkage,
                                             nullptr, getID());
    glb->setAlignment(MaybeAlign(4));

    if (value) {
        Value *init = value->CodeGen();
        if (getVarType() == VALUEFLOAT && value->getDType() == VALUEINT)
            init = irBuilder.CreateUIToFP(init, TypeGen(VALUEFLOAT));

        glb->setInitializer(static_cast<Constant *>(init));
    }

    globalValue[getID()] = glb;
    globalSymbolTable[getID()] = name;
}

Value *VariableDecl::CodeGen() {
    Function *atFunc = irBuilder.GetInsertBlock()->getParent();
    std::string &varName = name->getId();
    Value *init;

    // save id ptr into symbol table
    if (!localSymbolTable.judgeSymbolRedefine(varName)) {
        localSymbolTable.addSymbol(varName, name);
    } else {
        IRError("redefined symbol");
        return nullptr;
    }

    int type = name->getDType();

    if (!value) {
        switch (type) {
            case VALUEINT:
                init = ConstantInt::get(TypeGen(type), 0);
            case VALUEFLOAT:
                init = ConstantFP::get(TypeGen(type), 0);
        }
    } else {
        if (!(init = value->CodeGen())) {
            return nullptr;
        }
    }

    AllocaInst *alloca = createEntryBlockAlloca(atFunc, nullptr,varName, init->getType());
    irBuilder.CreateStore(init, alloca);
    localSymbolTable.addVar(varName, alloca);
    return init;
}

Value *ProtoType::CodeGen() {
    string &funcName = name->getId();

    if (protoMap.find(funcName) == protoMap.end()) {
        protoMap[funcName] = std::move(protoPtr(this));
    }
    // IRError("redefined function");
    return nullptr;
}

Function* ProtoType::FunctionGen() {
    // generate type
    std::vector<Type *> argTypes;
    for (int i = 0, e = getParamSize(); i < e; i++) {
        argTypes.push_back(TypeGen(getParamType(i)));
    }

    int returnType = getReturnType();

    // generate function block
    FunctionType *ft;
    ft = FunctionType::get(TypeGen(returnType), argTypes, false);
    Function *func = Function::Create(ft, Function::ExternalLinkage, getFuncName(), thisModule.get());

    int id = 0;
    for (auto &arg: func->args()) {
        string &paramName = getParamName(id++);
        if (paramName == "") {
            delete &paramName;
            return nullptr;
        }
        arg.setName(paramName);
    }
    return func;
}

Value *Expr::CodeGen() {
    return ExprCodeGen(this);
}

Value *Void::CodeGen(){
    return ConstantPointerNull::getNullValue(TypeGen(VALUEINT));
}

Value *Integer::CodeGen() {
    return ConstantInt::get(context, APInt(32,value,true));
}

Value *Float::CodeGen() {
    return ConstantFP::get(context,APFloat(value));
}

Value *Bool::CodeGen() {
    return ConstantInt::get(TypeGen(VALUEBOOL), value, false);
}

Value *String::CodeGen() {
    // constraint length of string in (0,255), include \n
    if(value.length() > 255){
        IRError("string is too long");
        value = value.substr(0,255);
    }
    int length = value.length();
    char end = 0;
    // align with zero
    for(int i=0,e=255-length;i<e;i++)
        value = value+end;

    Value* mem = irBuilder.CreateGlobalString(value);
    Value* str = irBuilder.CreateLoad(mem);
    return str; // return a string start position
}

int ArrayExpr::getDType(){
    return localSymbolTable.findArray(id->getId())->getElementType();
}

Value* ArrayExpr::CodeGen() {
    ArrayDecl* arrayDecl = localSymbolTable.findArray(id->getId());
    if(!arrayDecl){
//TODO globalArray

//        GlobalVariable *glb = globalValue[id->getId()];
//        if(!glb)
//            return IRError("undefined array");
//        else{
//
//            return irBuilder.CreateLoad(array->getType()->getPointerElementType(),)
//        }
        return IRError("undefined array");
    }

    AllocaInst* startAddr = localSymbolTable.findVar(id->getId());
    Value* index = this->index->CodeGen();
    Type* arrayType = arrayDecl->getArrayType();

    Value* access =  irBuilder.CreateGEP(startAddr,index,"access");
    return access;

    // read value
    // return irBuilder.CreateLoad(access->getType()->getPointerElementType(),access,id->getId().c_str());
}

Value *Identifier::CodeGen() {
    /// Value is a super base class of Instruction and Function
    // notice v is a AllocaInst pointer, point to mem address
    Value *v = localSymbolTable.findVar(identifier);
    if (!v) {
        GlobalVariable *glb = globalValue[identifier];
        if (!glb)
            return IRError("undefined variable");
        else
            return irBuilder.CreateLoad(glb->getType()->getPointerElementType(), glb, identifier.c_str());
    }

    // v is the adddress of this variable
    // begin to generate load ir
    return irBuilder.CreateLoad(v->getType()->getPointerElementType(), v, identifier.c_str());
}

// recursively set expression type
int BinaryExpr::getDType() {

    if(this->dType != -1)
        return dType;

    Expr* leftPtr = Left.get();
    Expr* rightPtr = Right.get();

    if (leftPtr->getExprType() == EXPRID) {
        string &id = static_cast<Identifier *>(Left.get())->getId();
        if (localSymbolTable.findSymbol(id)) {
            leftPtr = localSymbolTable.findSymbol(id);
        } else if (globalSymbolTable.find(id) != globalSymbolTable.end()) {
            leftPtr = globalSymbolTable[id];
        }
    }

    if (rightPtr->getExprType() == EXPRID) {
        string &id = static_cast<Identifier *>(Right.get())->getId();
        if (localSymbolTable.findSymbol(id)) {
            rightPtr = localSymbolTable.findSymbol(id);
        } else if (globalSymbolTable.find(id) != globalSymbolTable.end()) {
            rightPtr = globalSymbolTable[id];
        }
    }

    int leftType = leftPtr->getDType();
    int rightType = rightPtr->getDType();

    int retType = VALUEBOOL;
    if (op == OPEQ || op == OPLT || op == OPGT || op == OPEGT || op == OPELT || op == OPNEQ){
        if (!CheckCmp(leftType, rightType)) {
            IRError("Can't make comparison because of unmatched type");
            return -1;
        }
    }
    else if (op == OPOR || op == OPAND) {
        if (!CheckLogic(leftType, rightType)) {
            IRError("Can't make logic calculation because of unmatched type");
            return -1;
        }
    }
    else {
        if (!CheckArith(leftType, rightType, &retType)) {
            IRError("Can't do arithmetic because of unmatched type");
            return -1;
        }
    }

    // float division
    if (op == OPDIV) {
        retType = VALUEFLOAT;
    }

    this->setDType(retType);

    return retType;
}

Value *BinaryExpr::CodeGen() {
    Expr *leftPtr = Left.get();
    Expr *rightPtr = Right.get();

    // look up symbol
    // table
    if (leftPtr->getExprType() == EXPRID) {
        string &id = static_cast<Identifier *>(Left.get())->getId();
        if (localSymbolTable.findSymbol(id)) {
            leftPtr = localSymbolTable.findSymbol(id);
        } else if (globalSymbolTable.find(id) != globalSymbolTable.end()) {
            leftPtr = globalSymbolTable[id];
        }
    }

    if (rightPtr->getExprType() == EXPRID) {
        string &id = static_cast<Identifier *>(Right.get())->getId();
        if (localSymbolTable.findSymbol(id)) {
            rightPtr = localSymbolTable.findSymbol(id);
        } else if (globalSymbolTable.find(id) != globalSymbolTable.end()) {
            rightPtr = globalSymbolTable[id];
        }
    }
//
//    if (op == OPGT || op == OPLT || op == OPEQ || op == OPEGT || op == OPELT || op == OPNEQ) {
//        if (!CheckCmp(leftPtr->getDType(), rightPtr->getDType())) {
//            IRError("Can't make comparison because of unmatched type");
//            return nullptr;
//        }
//        this->setDType(VALUEBOOL);
//    } else if (op == OPOR || op == OPAND) {
//        if (!CheckLogic(leftPtr->getDType(), rightPtr->getDType())) {
//            IRError("Can't make logic calculation because of unmatched type");
//            return nullptr;
//        }
//        this->setDType(VALUEBOOL);
//    } else {
//        if (!CheckArith(leftPtr->getDType(), rightPtr->getDType(), &retType)) {
//            return nullptr;
//        }
//        this->setDType(retType);
//    }

    int retType = this->getDType();

    // float division
    if (op == OPDIV) {
        retType = VALUEFLOAT;
        this->setDType(retType);
    }

    Value *L = leftPtr->CodeGen();
    Value *R = rightPtr->CodeGen();

    if(leftPtr->getExprType() == EXPRARRAY) {
        L = irBuilder.CreateLoad(L->getType()->getPointerElementType(),L,"load element");
    }

    if (rightPtr->getExprType() == EXPRARRAY) {
        R = irBuilder.CreateLoad(R->getType()->getPointerElementType(),R,"load element");
    }

    if (!L || !R)
        return nullptr;

    // if return float, make some necessary conversion
    if (retType == VALUEFLOAT) {
        L = irBuilder.CreateUIToFP(L, TypeGen(retType));
        R = irBuilder.CreateUIToFP(R, TypeGen(retType));
    }

    switch (op) {
        case OPADD:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFAdd(L, R, "addftmp") :
                   irBuilder.CreateAdd(L, R, "addtmp");
        case OPSUB:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFSub(L, R, "subftmp")
                   : irBuilder.CreateSub(L, R, "subtmp");
        case OPMUL:
            return irBuilder.CreateMul(L, R, "multmp");
        case OPDIV:
            return irBuilder.CreateFDiv(L, R, "divftmp");
        case OPLT:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFCmpOLT(L, R, "cmpftmp")
                   : irBuilder.CreateICmpSLT(L, R, "cmplt");
        case OPGT:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFCmpOGT(L, R, "cmpftmp")
                   : irBuilder.CreateICmpSGT(L, R, "cmptmp");
        case OPELT:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFCmpOLE(L, R, "cmpftmp")
                   : irBuilder.CreateICmpSLE(L, R, "cmptmp");
        case OPEGT:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFCmpOGE(L, R, "cmpftmp")
                   : irBuilder.CreateICmpSGE(L, R, "cmptmp");
        case OPEQ:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFCmpOEQ(L, R, "cmpftmp")
                   : irBuilder.CreateICmpEQ(L, R, "cmptmp");
        case OPNEQ:
            return (retType == VALUEFLOAT)
                   ? irBuilder.CreateFCmpONE(L, R, "cmpftmp")
                   : irBuilder.CreateICmpNE(L, R, "cmptmp");
        case OPAND:
            return irBuilder.CreateAnd(L, R, "andtmp");
        case OPOR:
            return irBuilder.CreateOr(L, R, "ortmp");
    }
    return nullptr;
}

Value *FuncCall::CodeGen() {
    std::string &funcName = func->getId();
    std::vector<Value *> args;

    if(isIO(funcName)){
        return getIO(funcName,params);
    }

    Function *callee = getFunction(funcName);
    if (!callee) {
        string msg = "undefined reference to" + funcName;
        return IRError(msg);
    }

    // check args match
    if (callee->arg_size() != params.size()) {
        string msg = "unmatch arguments when calling" + funcName;
        return IRError(msg);
    }

    for (int i = 0, e = params.size(); i < e; i++) {
        args.push_back(params[i]->CodeGen());//Type conversion
        if (!args.back()) {
            return nullptr; //function call failed?
        }
    }


    std::cout<<"function size:"<<callee->arg_size()<<std::endl;

    return irBuilder.CreateCall(callee, args, "calltmp");
}

Value *FuncImpl::CodeGen() {
    auto &p = *proto;
    std::string &funcName = proto->getFuncName();

    /// proto undefined before, register as a prototype
    if (protoMap.find(funcName) == protoMap.end()) {
        proto->CodeGen();
    }

    Function* implFunc = getFunction(funcName);

    BasicBlock *BB = BasicBlock::Create(context, "entry", implFunc);
    irBuilder.SetInsertPoint(BB);

    localSymbolTable.pushVarTable();
    localSymbolTable.pushSymbolTable();

    int id = 0;
    for (auto &arg: implFunc->args()) {
        AllocaInst *alloca = createEntryBlockAlloca(implFunc, nullptr,arg.getName().str(), arg.getType());

        irBuilder.CreateStore(&arg, alloca);

        localSymbolTable.addVar(arg.getName().str(), alloca);
        localSymbolTable.addSymbol(arg.getName().str(),proto->getParamsPtr(id++));
    }

    if (Value *retVal = funcBody->CodeGen()) {
        irBuilder.CreateRet(retVal);
        verifyFunction(*implFunc);
        localSymbolTable.popSymbolTable();
        localSymbolTable.popVarTable();

        return implFunc;
    }

    localSymbolTable.popSymbolTable();
    localSymbolTable.popVarTable();

    implFunc->eraseFromParent();
    IRError("error when generate function");
    return nullptr;
}

Value *FuncBody::CodeGen() {
    for (int i = 0, e = stmts.size(); i < e; i++) {
        stmts[i]->Print();
        stmts[i]->CodeGen();
    }
    if(exprReturn)
        return exprReturn->CodeGen();
    return ConstantPointerNull::getNullValue(TypeGen(VALUEINT));
}