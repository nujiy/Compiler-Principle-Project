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

Type *TypeGen(int type) {
    switch (type) {
        case VALUEINT:
            return Type::getInt32Ty(context);
        case VALUEFLOAT:
            return Type::getFloatTy(context);
        case VALUEBOOL:
            return Type::getInt1Ty(context);
        case VALUEVOID:
            return Type::getVoidTy(context);
        case VALUEARRAY:
            return Type::getFloatTy(context);
        case VALUECHAR:
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

static AllocaInst *createEntryBlockAlloca(Function *function, const std::string &name, Type *type) {
    // get a IRbuilder object pointer to the entry of the function
    IRBuilder<> tmp(&function->getEntryBlock(), function->getEntryBlock().begin());

    return tmp.CreateAlloca(type, 0, name.c_str());
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

void AST::CodeGen() {
    thisModule = std::make_unique<Module>("IRGen", context);

    Global->CodeGen();
    Main->CodeGen();
    Function->CodeGen();

    raw_os_ostream irout(std::cout);
    thisModule->print(irout, new AssemblyAnnotationWriter());
    globalValue.clear();
    for(auto &p: globalSymbolTable){
    }
    globalSymbolTable.clear();
//    //TODO what are these for?
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

    auto filename = "output";
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

    outs() << "wrote " << filename << "\n";
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
    FunctionType *funcType = FunctionType::get(Type::getInt16Ty(context), false);
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

Value *Expr::CodeGen() {
    return ExprCodeGen(this);
}

Value *Integer::CodeGen() {
    return ConstantInt::get(TypeGen(VALUEINT), value, false);
}

Value *Float::CodeGen() {
    return ConstantFP::get(context,APFloat(value));
}

Value *Bool::CodeGen() {
    return ConstantInt::get(TypeGen(VALUEBOOL), value, false);
}

Value *Identifier::CodeGen() {
    /// Value is a super base class of Instruction and Function
    // notice v is a AllocaInst pointer, point to mem address
    Value *v = localSymbolTable.findVar(identifier);
    if (!v) {
        GlobalVariable *glb = globalValue[identifier];
        if (!glb)
            return IRError("undefined variable");
        else //TODO global variable with load?
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

    std::vector<Value *> args;
    for (int i = 0, e = params.size(); i < e; i++) {
        args.push_back(params[i]->CodeGen());//Type conversion
        if (!args.back()) {
            return nullptr; //TODO function call failed?
        }
    }
    std::cout<<"function size:"<<callee->arg_size()<<std::endl;

    return irBuilder.CreateCall(callee, args, "calltmp");
}

Value *Stmt::CodeGen() {
    return StmtCodeGen(this);
}

Value *FuncBody::CodeGen() {
    for (int i = 0, e = stmts.size(); i < e; i++) {
        stmts[i]->Print();
        stmts[i]->CodeGen();
    }
    if(exprReturn)
        return exprReturn->CodeGen();
    return nullptr;
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
        AllocaInst *alloca = createEntryBlockAlloca(implFunc, arg.getName().str(), arg.getType());

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

Value *Decl::CodeGen() {
    return DeclCodeGen(this);
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
    if (!localSymbolTable.findSymbol(varName)) {
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
    } else {//TODO type conversion
        if (!(init = value->CodeGen())) {
            return nullptr;
        }
    }

    AllocaInst *alloca = createEntryBlockAlloca(atFunc, varName, init->getType());
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

Value *ArrayDecl::CodeGen() {

    return nullptr;
}

// assign value for declared variable
Value *Assignment::CodeGen() {
    Expr *p = identifier.get();
    string &varName = static_cast<Identifier *>(p)->getId();

    Value *init;
    auto varAddr = localSymbolTable.findVar(varName);
    auto glbAddr = globalValue.find(varName);
    if (!varAddr) {
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

    // assign value
    AllocaInst *alloca = varAddr;
    irBuilder.CreateStore(init, alloca);

    return init;
}
