#include "../include/codeGen.h"

/// save repeated variable and make sense for error checking
/// it should be cleaned when jump out of a block
static std::map<std::string, protoPtr> protoMap;
static SymbolTable symbolTable;

Type *TypeGen(int type,int size = 0) {
    switch (type) {
        case VALUEINT:
            return Type::getInt32Ty(context);
        case VALUEINTPTR:
            return Type::getInt32PtrTy(context);
        case VALUEFLOAT:
            return Type::getDoubleTy(context);
        case VALUEFLOATPTR:
            return Type::getFloatPtrTy(context);
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
    if ((l == VALUEFLOAT || l == VALUEINT) && (r == VALUEFLOAT || r == VALUEINT)) {
        return true;
    }
    if(l == 0 && r == 0)
        return true;
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
        FunctionType* funcType = FunctionType::get(Type::getInt16Ty(context), argTypes,true);
        Function* func = Function::Create(funcType,Function::ExternalLinkage,"printf",thisModule.get());
        func->setCallingConv(CallingConv::C);
        llvmPrint = func;
    }

    if(params.size() > 1 && params[0]->getDType() != VALUESTRING){
        IRError("wrong argument of print");
    }

    std::vector<Value*> printArgs;
    std::string format;    // the first element is to store format

    if(params.size() == 0){
        if(!printLine)
            return IRError("wrong print call");
    }
    else
        format = static_cast<String*>(params[0].get())->getValue();

    if (printLine) {
        format += '\n';
    }

    Value* control = irBuilder.CreateGlobalStringPtr(format,"print_format");
    printArgs.emplace_back(control);

    for(int i=1,e = params.size();i<e;i++){
        int type = params[i]->getDType();

        if(params[i]->getExprType() == EXPRID){
            type = symbolTable.findSymbol(static_cast<Identifier*>(params[i].get())->getId())->getDType();
        }

        if(params[i]->getExprType() == EXPRARRAY){
            ArrayExpr* exprExpr = static_cast<ArrayExpr*>(params[i].get());
            if(symbolTable.isGlobal(exprExpr->getId()))
                type = VALUEINTPTR;
        }

        if(type != VALUEINT && type != VALUEINTPTR && type != VALUESTRING && type != VALUEFLOAT && type!=VALUEBOOL){
            return IRError("unsupported print type");
        }

        printArgs.emplace_back(params[i]->CodeGen());
    }

    return irBuilder.CreateCall(llvmPrint,printArgs,"call_printf");
}

static Value* SysRead(vector<exprPtr>& params,bool readLine){
    static Function* llvmRead = nullptr;
    if(llvmRead == nullptr){
        std::vector<Type*> argTypes = {Type::getInt8PtrTy(context)};
        FunctionType* funcType = FunctionType::get(Type::getInt16Ty(context),argTypes,true);
        Function* func = Function::Create(funcType,Function::ExternalLinkage,"scanf",thisModule.get());

        func->setCallingConv(CallingConv::C);
        llvmRead = func;
    }

    if(params.size() < 1 || params[0]->getDType() != VALUESTRING){
        IRError("wrong argument of print");
    }

    std::vector<Value*> readArgs;
    std::string format = static_cast<String*>(params[0].get())->getValue();    // the first element is to store format
    Value* control = irBuilder.CreateGlobalStringPtr(format,"print_format");
    readArgs.emplace_back(control);

    for(int i=1,e=params.size();i<e;i++){
        int type = params[i]->getDType();
        Value* addr;
        if(params[i]->getExprType() == EXPRID){
            type = symbolTable.findSymbol(static_cast<Identifier*>(params[i].get())->getId())->getDType();
            addr = symbolTable.findVar(params[i].get());
        }
        else if(params[i]->getExprType() == EXPRARRAY)
        {
//            string& id = static_cast<ArrayExpr*>(params[i].get())->getId();
            addr = symbolTable.findVar(params[i].get());
        }
        else
        {
            addr = params[i]->CodeGen();
        }
        if(type != VALUEINT && type != VALUESTRING && type != VALUEFLOAT){
            return IRError("unsupported print type");
        }

        readArgs.emplace_back(addr);
    }

    Value* ret = irBuilder.CreateCall(llvmRead,readArgs,"call_read");
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
//    globalNamedValue.clear();
//    globalIdTable.clear();
    symbolTable.clear();


    auto filename = "quick_sort.o";
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
            static_cast<ArrayDecl *>(decls[i].get())->GlobalGen();
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
    symbolTable.pushSymbolTable();
    symbolTable.pushVarTable();

    irBuilder.CreateRet(mainFunc->CodeGen());
    verifyFunction(*_main_);
    symbolTable.popSymbolTable();
    symbolTable.popVarTable();
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

Value* WhileLoop::CodeGen() {
    Function* atFunc = irBuilder.GetInsertBlock()->getParent();

    BasicBlock* startBB = BasicBlock::Create(context,"init",atFunc);
    BasicBlock* loopBodyBB = BasicBlock::Create(context,"loop",atFunc);
    BasicBlock* condBB = BasicBlock::Create(context,"cond",atFunc);
    BasicBlock* endBB = BasicBlock::Create(context,"endLoop",atFunc);
    irBuilder.CreateBr(startBB);
    irBuilder.SetInsertPoint(startBB);

    Value* cond = condition->CodeGen();
    if(!cond){
        return IRError("need condition expression in for loop");
    }

    symbolTable.pushVarTable();
    symbolTable.pushSymbolTable();

    irBuilder.CreateCondBr(cond,loopBodyBB,endBB);
    irBuilder.SetInsertPoint(loopBodyBB);

    for(int i=0,e = stmtlist.size();i<e;i++)
        stmtlist[i]->CodeGen();

    irBuilder.CreateBr(condBB);
    irBuilder.SetInsertPoint(condBB);

    cond = condition->CodeGen();
    irBuilder.CreateCondBr(cond, loopBodyBB,endBB);
    irBuilder.SetInsertPoint(endBB);

    symbolTable.popSymbolTable();
    symbolTable.popVarTable();
    return Constant::getNullValue(TypeGen(VALUEINT));
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
//    AllocaInst* alloca = symbolTable.findVar(loopID->getId());
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

    symbolTable.pushVarTable();
    symbolTable.pushSymbolTable();

    irBuilder.CreateCondBr(cond,loopBodyBB,endBB);
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
//    AllocaInst* alloca = symbolTable.findVar(loopID->getId());
//    irBuilder.CreateStore(stepValue,alloca);
    stepAssign->CodeGen();
    cond = condition->CodeGen();
    irBuilder.CreateCondBr(cond, loopBodyBB,endBB);
    irBuilder.SetInsertPoint(endBB);

    symbolTable.popSymbolTable();
    symbolTable.popVarTable();
    return Constant::getNullValue(TypeGen(VALUEINT));
}

Value* ConditionBlock::CodeGen(){
    symbolTable.pushSymbolTable();
    symbolTable.pushVarTable();

    for(int i=0,e=stmtList.size();i<e;i++){
        stmtList[i]->CodeGen();
    }
    if(returnExpr){
        Value* retVal = returnExpr->CodeGen();
        irBuilder.CreateRet(retVal);

        Function *atFunc = irBuilder.GetInsertBlock()->getParent();
        BasicBlock* outBB = BasicBlock::Create(context,"out",atFunc); //atFunc necessary?
        irBuilder.SetInsertPoint(outBB);
        //        return retVal;
    }
    symbolTable.popVarTable();
    symbolTable.popSymbolTable();
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
    irBuilder.SetInsertPoint(mergeBB);

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

    Value* varAddr = symbolTable.findVar(p);
    Value *init;

    if (expression) {
        // get value address from expression
        if (!(init = expression->CodeGen())) {
            return nullptr;
        }
    } else {
        IRError("assignment not find a expression");
        return nullptr;
    }

    irBuilder.CreateStore(init,varAddr);
    return init;
}

Value *Decl::CodeGen() {
    return DeclCodeGen(this);
}

void ArrayDecl::setArrayType(){
//    ArrayType* arrayType = ConstantDataArray::get()
    ArrayType* arrayType = ArrayType::get(TypeGen(dType),this->size);
    this->arrayType = arrayType;
    switch (dType) {
        case VALUEINT:
            this->allocaType = VALUEINTPTR;
            break;
        case VALUEFLOAT:
            this->allocaType = VALUEFLOATPTR;
            break;
        default:
            this->allocaType = VALUEINTPTR;
    }
}

void ArrayDecl::GlobalGen(){
    Value* init;

    //redefine
    if(symbolTable.findArray(getID())){
        IRError("redefined global array");
        return;
    }
    //TODO
    GlobalVariable *glbArray = new GlobalVariable(*thisModule.get(),arrayType,false,GlobalValue::InternalLinkage, 0,"global_array");
    glbArray->setAlignment(MaybeAlign(4));

    // Constant Definitions
    ConstantAggregateZero* const_array_2 = ConstantAggregateZero::get(arrayType);
    glbArray->setInitializer(const_array_2);

    symbolTable.addGlobalVar(name->getId(),glbArray);
    symbolTable.addGlobalArray(name->getId(),this);
}

Value* ArrayDecl::CodeGen() {
    Function *atFunc = irBuilder.GetInsertBlock()->getParent();

    // if it is real decl not
    Value* sizeValue = ConstantInt::get(TypeGen(VALUEINT),size);
    AllocaInst* arrAlloca = createEntryBlockAlloca(atFunc, nullptr,name->getId(), arrayType);
    symbolTable.addLocalArray(name->getId(),this);
    symbolTable.addVar(name->getId(),arrAlloca);
    return sizeValue;
}

/// used only when generating global variable
void VariableDecl::GlobalGen() {
    Value *init;
    if (symbolTable.findGlobalVar(id)) {
        IRError("redefined global variable");
        return;
    }

    GlobalVariable *glb = new GlobalVariable(*thisModule, TypeGen(getVarType()), 0, GlobalVariable::CommonLinkage,
                                             nullptr, getID());
    glb->setAlignment(MaybeAlign(4));

    if(name->getDType() == VALUEINT){
        glb->setInitializer(ConstantInt::get(TypeGen(VALUEINT),0,true));
    }
    else if(name->getDType() == VALUEFLOAT){
        glb->setInitializer(ConstantFP::get(TypeGen(VALUEFLOAT),APFloat(0.0)));
    }
    if (value) {
        Value *init = value->CodeGen();
        if (getVarType() == VALUEFLOAT && value->getDType() == VALUEINT)
            init = irBuilder.CreateSIToFP(init, TypeGen(VALUEFLOAT));

        glb->setInitializer(static_cast<Constant *>(init));
    }

    symbolTable.addGlobalVar(getID(),glb);
    symbolTable.addGlobalSymbol(getID(),name);
//    globalNamedValue[getID()] = glb;
//    globalIdTable[getID()] = name;
}

Value *VariableDecl::CodeGen() {
    Function *atFunc = irBuilder.GetInsertBlock()->getParent();
    std::string &varName = name->getId();
    Value *init;
    int type = name->getDType();

    // save id ptr into symbol table
    if (!symbolTable.judgeSymbolRedefine(varName)) {
            symbolTable.addLocalSymbol(varName, name);
    } else {
        IRError("redefined symbol");
        return nullptr;
    }


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
    if(type == VALUEFLOAT && init->getType()->isIntegerTy()){
            init = irBuilder.CreateSIToFP(init, TypeGen(VALUEFLOAT));
    }

    if(type == VALUESTRING){
        symbolTable.addVar(varName,init);
        return init;
    }

    AllocaInst *alloca = createEntryBlockAlloca(atFunc, nullptr,varName, TypeGen(type));

    if(init->getType() != alloca->getType()->getElementType()){
        if(value->getDType() ==VALUEFLOAT && name->getDType() == VALUEINT){
            init = irBuilder.CreateFPToSI(init, TypeGen(VALUEINT));
        }
        if(value->getDType() ==VALUEINT && name->getDType() == VALUEFLOAT){
            init = irBuilder.CreateSIToFP(init, TypeGen(VALUEFLOAT));
        }
    }
    irBuilder.CreateStore(init, alloca);

    symbolTable.addVar(varName, alloca);
    return alloca;
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
//    return UndefValue::get(TypeGen(VALUEVOID));
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
//    Value* str = irBuilder.CreateLoad(mem);
    return mem; // return a string start position
}

int ArrayExpr::getDType(){
    return symbolTable.findArray(id->getId())->getElementType();
}

Value* ArrayExpr::CodeGen() {
    ArrayDecl* arrayDecl = symbolTable.findArray(id->getId());
    if(!arrayDecl){
//TODO globalArray

//        GlobalVariable *glb = globalNamedValue[id->getId()];
//        if(!glb)
//            return IRError("undefined array");
//        else{
//
//            return irBuilder.CreateLoad(array->getType()->getPointerElementType(),)
//        }
        return IRError("undefined array");
    }

    Value* access = symbolTable.findVar(this);
    // 数组元素地址的指针
     return irBuilder.CreateLoad(access->getType()->getPointerElementType(),access,id->getId().c_str());
    // read value
}

Value *Identifier::CodeGen() {
    /// Value is a super base class of Instruction and Function
    // notice v is a AllocaInst pointer, point to mem address
    Value *v = symbolTable.findVar(identifier);
    if (!v) {
        GlobalVariable *glb = symbolTable.findGlobalVar(identifier);
        if (!glb)
            return IRError("undefined variable");
        else
            return irBuilder.CreateLoad(glb->getType()->getPointerElementType(), glb, identifier.c_str());
    }

    // v is the adddress of this variable
    // begin to generate load ir
    Value* addr = v;
//    if(symbolTable.isArray(identifier)){
        if(v->getType()->isArrayTy())
            addr = irBuilder.CreateBitCast(v,v->getType()->getArrayElementType()->getPointerTo(),"load_ele_addr");
        else if(v->getType()->isPointerTy() && v->getType()->getPointerElementType()->isArrayTy())
            addr = irBuilder.CreateBitCast(v,v->getType()->getPointerElementType()->getArrayElementType()->getPointerTo(),"load_ele_addr");
        else if(v->getType()->isPointerTy())
            addr = irBuilder.CreateLoad(v->getType()->getPointerElementType(),v,"load_addr");
//    }
    else
        addr = irBuilder.CreateLoad(v->getType()->getPointerElementType(), v, identifier.c_str());
    return addr;
}

// recursively set expression type
int BinaryExpr::getDType() {

    if(this->dType != -1)
        return dType;

    Expr* leftPtr = Left.get();
    Expr* rightPtr = Right.get();

    if (leftPtr->getExprType() == EXPRID) {
        string &id = static_cast<Identifier *>(Left.get())->getId();
//        if (symbolTable.findSymbol(id)) {
//            leftPtr = symbolTable.findSymbol(id);
//        } else if (globalIdTable.find(id) != globalIdTable.end()) {
//            leftPtr = globalIdTable[id];
//        }
        Expr* tmp = symbolTable.findSymbol(id);
        if(tmp)
            leftPtr = tmp;
    }

    if (rightPtr->getExprType() == EXPRID) {
        string &id = static_cast<Identifier *>(Right.get())->getId();
//        if (symbolTable.findSymbol(id)) {
//            rightPtr = symbolTable.findSymbol(id);
//        } else if (globalIdTable.find(id) != globalIdTable.end()) {
//            rightPtr = globalIdTable[id];
//        }
        Expr* tmp = symbolTable.findSymbol(id);
        if(tmp)
            rightPtr = tmp;
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
        Expr* tmp = symbolTable.findSymbol(id);
        if(tmp)
            leftPtr = tmp;
    }

    if (rightPtr->getExprType() == EXPRID) {
        string &id = static_cast<Identifier *>(Right.get())->getId();
        Expr* tmp = symbolTable.findSymbol(id);
        if(tmp)
            rightPtr = tmp;
    }

    int retType = this->getDType();

    // float division
    if (op == OPDIV) {
        retType = VALUEFLOAT;
        this->setDType(retType);
    }

    Value *L = leftPtr->CodeGen();
    Value *R = rightPtr->CodeGen();

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

    if(callee->getType()->isVoidTy())
        return irBuilder.CreateCall(callee,args);

    return irBuilder.CreateCall(callee, args);
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

    symbolTable.pushVarTable();
    symbolTable.pushSymbolTable();

    int id = 0;
    for (auto &arg: implFunc->args()) {
        AllocaInst *alloca = createEntryBlockAlloca(implFunc, nullptr,arg.getName().str(), arg.getType());

        irBuilder.CreateStore(&arg, alloca);
//        if(arg.getType()->isPointerTy()){
//            Value* tmp = irBuilder.CreateLoad(alloca->getType()->getPointerElementType(),alloca,"load_element");
//            symbolTable.addVar(arg.getName().str(), tmp);
//        }
//        else
            symbolTable.addVar(arg.getName().str(), alloca);
        symbolTable.addLocalSymbol(arg.getName().str(),proto->getParamsPtr(id++));
    }

    if (Value *retVal = funcBody->CodeGen()) {
        irBuilder.CreateRet(retVal);
        verifyFunction(*implFunc);
        symbolTable.popSymbolTable();
        symbolTable.popVarTable();

        return retVal;
    }

    symbolTable.popSymbolTable();
    symbolTable.popVarTable();

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