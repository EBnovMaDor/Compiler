#include "CodeGenerator.hpp"
#include <memory>
using namespace llvm;

void CodeGenerator::ProgramGen(shared_ptr<CompUnit> &program,const string& name) {
    // init external function
    InitExternalFunction();
    for (auto & Unit : program->CompUnits) {
        if (Unit->AST_type == FUNC) FuncGen(Unit);
        else if (Unit->AST_type == DECL) GlobalVarGen(Unit);
    }
    // GeneratorModule->print(outs(), nullptr);
    OutputGen(name);
}

void CodeGenerator::InitExternalFunction() {
    // scanf
    FunctionType *scanfTy = FunctionType::get(GetType(Int), {Type::getInt8PtrTy(*Context)}, true);
    Function *scanf = Function::Create(scanfTy, Function::ExternalLinkage, "scanf", GeneratorModule.get());
    scanf->setCallingConv(CallingConv::C);
    // printf
    FunctionType *printfTY = FunctionType::get(GetType(Int), {Type::getInt8PtrTy(*Context)}, true);
    Function *printf = Function::Create(printfTY, Function::ExternalLinkage, "printf", GeneratorModule.get());
    printf->setCallingConv(CallingConv::C);
}

void CodeGenerator::OutputGen(const string& Filename) {
    // Initialize the target registry etc.
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    GeneratorModule->setTargetTriple(TargetTriple);

    string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        errs() << Error;
        exit(0);
    }

    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TheTargetMachine =
            Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    GeneratorModule->setDataLayout(TheTargetMachine->createDataLayout());

    // auto Filename = "output.o";
    error_code EC;
    raw_fd_ostream dest(Filename, EC, sys::fs::OF_None);

    if (EC) {
        errs() << "Could not open file: " << EC.message();
        exit(0);
    }

    legacy::PassManager pass;
    auto FileType = CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        errs() << "TheTargetMachine can't emit a file of this type";
        exit(0);
    }

    pass.run(*GeneratorModule);
    dest.flush();

    // outs() << "Wrote " << Filename << "\n";
}

void CodeGenerator::GlobalVarGen(shared_ptr<BaseAST> &Unit) {
    shared_ptr<Decl> global(reinterpret_pointer_cast<Decl>(Unit));
    // determine whether it has been declared
    shared_ptr<Variable> var(reinterpret_pointer_cast<Variable>(global->Var));
    if (GlobalValues.find(var->Var_name) == GlobalValues.end()) {
        if (var->Length.empty()){
            auto *gVar = new GlobalVariable(*GeneratorModule, GetType(global->Decl_type), false, GlobalValue::ExternalLinkage,
                                           ConstantInt::get(*Context, APInt(32, 0)), var->Var_name);
            if (global->Exp != nullptr)
                gVar->setInitializer(dyn_cast<Constant>(ValueGen(global->Exp)));
            GlobalValues.emplace(var->Var_name, gVar);
        }
        else {
            // create array
            Value *arraySize = GetArraySize(var);
            auto arrayType = ArrayType::get(GetType(global->Decl_type),
                                            (dyn_cast<Constant>(arraySize)->getUniqueInteger().getSExtValue()));
            auto *gVar = new GlobalVariable(*GeneratorModule, arrayType, false, GlobalValue::ExternalLinkage,
                                            ConstantArray::get(arrayType, ConstantInt::get(*Context, APInt(32, 0))), var->Var_name);
            GlobalValues.emplace(var->Var_name, gVar);
        }
        NamedValues.insert(var->Var_name, nullptr, var->Length);
    }
    else cout << "error: redefinition of '"<< var->Var_name << "'" << endl;
}

void CodeGenerator::FuncGen(shared_ptr<BaseAST> &Unit) {
    shared_ptr<Func> FuncUnit(reinterpret_pointer_cast<Func>(Unit));
    shared_ptr<FuncPrototype> Proto(reinterpret_pointer_cast<FuncPrototype>(FuncUnit->Prototype));
    // Parameters
    vector<Type*> Para{};
    vector<std::string> ParaNames{};
    vector<vector<shared_ptr<BaseAST>>> ParaDim{};
    vector<type> ParaType{};
    for (auto & Param : Proto->Params){
        shared_ptr<Decl> decl(reinterpret_pointer_cast<Decl>(Param));
        shared_ptr<Variable> var(reinterpret_pointer_cast<Variable>(decl->Var));
        ParaNames.push_back(var->Var_name);
        if (var->Length.empty()) Para.push_back(GetType(decl->Decl_type));
        else Para.push_back(GetPtrType(decl->Decl_type));
        ParaDim.push_back(var->Length);
        ParaType.push_back(decl->Decl_type);
    }

    // Function
    FunctionType *FT = FunctionType::get(GetType(Proto->Func_type), Para, false);
    Function *F = Function::Create(FT, Function::ExternalLinkage, Proto->Func_name, GeneratorModule.get());

    // create block
    BasicBlock *BB = createBB(F, Proto->Func_name);
    Builder->SetInsertPoint(BB);

    // init symbol table
    auto *cur = Builder->GetInsertBlock();
    int i = 0;
    for(auto &Arg : F->args()) {
        Value *a = &Arg;
        AllocaInst *Alloca;
        if (ParaDim[i].empty()) Alloca = createBlockAlloca(*cur, ParaNames[i], ParaType[i]);
        else Alloca = createBlockPtrAlloca(*cur, ParaNames[i], ParaType[i]);
        NamedValues.insert(ParaNames[i], Alloca, ParaDim[i]);
        Builder->CreateStore(a, Alloca);
        ++i;
    }

    std::vector<std::string> removeList;
    for (auto & Block : FuncUnit->Blocks){
        if (Block->AST_type == STMT) StmtGen(F, Block);
        else if(Block->AST_type == DECL) DeclGen(Block, removeList);
    }
    NamedValues.remove(removeList);
    if (Proto->Func_type == Void) Builder->CreateRetVoid();

//    TheFPM->run(*F);
}

void CodeGenerator::DeclGen(shared_ptr<BaseAST> &Block, vector<std::string> &removeList) {
    shared_ptr<Decl> DeclUnit(reinterpret_pointer_cast<Decl>(Block));
    auto *cur = Builder->GetInsertBlock();
    if (DeclUnit->Decl_type == Struct){
        // create struct type
        if (DeclUnit->Exp == nullptr) {
            StructType *Str = StructType::create(*Context, DeclUnit->Struct_name);
            vector<Type*> Para{};
            vector<string> ParaNames{};
            for(auto & i : DeclUnit->Member){
                shared_ptr<Decl> Unit(reinterpret_pointer_cast<Decl>(i));
                shared_ptr<Variable> UnitVar(reinterpret_pointer_cast<Variable>(Unit->Var));
                Para.push_back(GetType(Unit->Decl_type));
                ParaNames.push_back(UnitVar->Var_name);
            }
            Str->setBody(Para);
            structInfo info;
            info.type = Str;
            info.field = ParaNames;
            NamedValues.insertStruct(DeclUnit->Struct_name, info);
        }
        // create struct with init value
        else {
            shared_ptr<Variable> VarUnit(reinterpret_pointer_cast<Variable>(DeclUnit->Var));
            structInfo info = NamedValues.findStruct(DeclUnit->Struct_name);
            if (info.type == nullptr) {
                cerr << "error: undefined struct '" << DeclUnit->Struct_name << "'" << endl;
                exit(0);
            }
            AllocaInst *Alloca;
            Alloca = Builder->CreateAlloca(info.type, nullptr, VarUnit->Var_name);
            NamedValues.insert(VarUnit->Var_name, Alloca, VarUnit->Length);
            shared_ptr<ExpList> ExpListUnit(reinterpret_pointer_cast<ExpList>(DeclUnit->Exp));
            for (int i = 0; i < ExpListUnit->Exps.size(); ++i){
                Value* V = ValueGen(ExpListUnit->Exps[i]);
                Value* loc = Builder->CreateInBoundsGEP(info.type, Alloca, {Builder->getInt32(0), Builder->getInt32(i)});
                Builder->CreateStore(V, loc);
            }
        }
    }
    else {
        shared_ptr<Variable> VarUnit(reinterpret_pointer_cast<Variable>(DeclUnit->Var));
        // check redefinition
        auto check_sym = find(removeList.begin(), removeList.end(), VarUnit->Var_name);
        if (check_sym != removeList.end()) {
            cout << "error: redefinition of '" << VarUnit->Var_name << "'" << endl;
            exit(0);
        }
        Value *InitVal = nullptr;
        if (DeclUnit->Exp != nullptr) {
            InitVal = ValueGen(DeclUnit->Exp);
            if (DeclUnit->Decl_type == Double && InitVal->getType()->isIntegerTy())
                InitVal = IntToDouble(InitVal);
        }
        // create IR
        AllocaInst *Alloca;
        if (VarUnit->Length.empty()) Alloca = createBlockAlloca(*cur, VarUnit->Var_name, DeclUnit->Decl_type);
        else {
            Value *arraySize = GetArraySize(VarUnit);
            Alloca = createBlockAlloca(*cur, VarUnit->Var_name, DeclUnit->Decl_type, arraySize);
        }
        if (InitVal != nullptr) Builder->CreateStore(InitVal, Alloca);
        // add to symbol table
        NamedValues.insert(VarUnit->Var_name, Alloca, VarUnit->Length);
        removeList.push_back(VarUnit->Var_name);
    }
}

Value *CodeGenerator::GetArraySize(shared_ptr<Variable> &VarUnit) {
    Value* arraySize = ValueGen(VarUnit->Length[0]);
    for (int i = 1; i < VarUnit->Length.size(); ++i)
        arraySize = Builder->CreateMul(arraySize, ValueGen(VarUnit->Length[i]));
    return arraySize;
}

// if StmtGen is changed, please change related code in WhileGen 
void CodeGenerator::StmtGen(Function *F, shared_ptr<BaseAST> &Block) {
    shared_ptr<Stmt> StmtUnit(reinterpret_pointer_cast<Stmt>(Block));
    if (StmtUnit->Stmt_type == If) IfGen(F, StmtUnit);
    else if (StmtUnit->Stmt_type == While) WhileGen(F, StmtUnit);
    else if(StmtUnit->Stmt_type == Assign) AssignGen(StmtUnit);
    else if(StmtUnit->Stmt_type == Return){
        if(StmtUnit->RVal == nullptr) Builder->CreateRetVoid();
        else Builder->CreateRet(ValueGen(StmtUnit->RVal));
    }
    else if (StmtUnit->Stmt_type == Expression) Value *V = ValueGen(StmtUnit->RVal);
    else if (StmtUnit->Stmt_type == Printf) PrintfGen(StmtUnit);
    else if (StmtUnit->Stmt_type == Scanf) ScanfGen(StmtUnit);
}

void CodeGenerator::ScanfGen(shared_ptr<Stmt> &StmtUnit) {
    Function *CalleeF = GeneratorModule->getFunction("scanf");
    vector<Value *> ArgValues;
    auto *FormatStrInst = Builder->CreateGlobalStringPtr(StmtUnit->IO, "scanf_format_str");
    ArgValues.push_back(FormatStrInst);
    if (!StmtUnit->First_block.empty()) {
        for(auto & Param : StmtUnit->First_block){
            if (Param->AST_type == VARIABLE){
                shared_ptr<Variable> VarUnit(reinterpret_pointer_cast<Variable>(Param));
                AllocaInst *var = NamedValues.find(VarUnit->Var_name);
                if (var == nullptr){
                    auto global = GlobalValues.find(VarUnit->Var_name);
                    if (global == GlobalValues.end()) {
                        cout << "error: undefined variable '" << VarUnit->Var_name << "'" << endl;
                        exit(1);
                    }
                    auto global_var = global->second;
                    if(global_var->getValueType()->isArrayTy()){
                        auto args = GetGlobalArrayIndex(VarUnit);
                        ArrayRef<Value*> argsRef(args);
                        Value *ptr = Builder->CreateInBoundsGEP(global_var->getValueType()->getScalarType(), global_var, argsRef);
                        ArgValues.push_back(ptr);
                    }
                    else
                        ArgValues.push_back(Builder->CreateInBoundsGEP(global_var->getValueType(), global_var,
                                                                  ConstantInt::get(*Context, APInt(32, 0))));
                }
                else {
                    if (VarUnit->Length.empty())
                        ArgValues.push_back(Builder->CreateInBoundsGEP(var->getAllocatedType(), var,
                                                                ConstantInt::get(*Context, APInt(32, 0))));
                    else {
                        Value *index = GetArrayIndex(VarUnit);
                        ArgValues.push_back(Builder->CreateInBoundsGEP(var->getAllocatedType(), var, index));
                    }
                }
            }
        }
    }
    Builder->CreateCall(CalleeF, ArgValues, "c_scanf");
}

vector<Value*> CodeGenerator::GetGlobalArrayIndex(const shared_ptr<Variable> &VarUnit) {
    Value *index = GetArrayIndex(VarUnit);
//    index = Builder->CreateSExt(index, Type::getInt64Ty(*Context));
    vector<Value*> args;
    args.push_back(ConstantInt::get(*Context, APInt(32, 0)));
    args.push_back(index);
    return args;
}

Value *CodeGenerator::GetArrayIndex(const shared_ptr<Variable> &VarUnit) {
    Value *index = ValueGen(VarUnit->Length[VarUnit->Length.size() - 1]);
    vector<shared_ptr<BaseAST>> arrayLength = NamedValues.array_dim(VarUnit->Var_name);
    for (int i = 0; i < VarUnit->Length.size() - 1; ++i) {
        Value *arrayIndex = ValueGen(VarUnit->Length[i]);
        for (int j = i + 1; j < arrayLength.size(); ++j) {
            arrayIndex = Builder->CreateMul(arrayIndex, ValueGen(arrayLength[j]));
        }
        index = Builder->CreateAdd(index, arrayIndex);
    }
    return index;
}

void CodeGenerator::PrintfGen(shared_ptr<Stmt> &StmtUnit) {
    Function *CalleeF = GeneratorModule->getFunction("printf");
    vector<Value *> ArgValues;
    // replace \n with ascii 10
    while(StmtUnit->IO.find("\\n") != string::npos)
        StmtUnit->IO.replace(StmtUnit->IO.find("\\n"), 2, string(1, toascii(10)));
    auto *FormatStrInst = Builder->CreateGlobalStringPtr(StmtUnit->IO, "printf_format_str");
    ArgValues.push_back(FormatStrInst);

    if (!StmtUnit->First_block.empty()) {
        for(auto & i : StmtUnit->First_block){
            Value *Val = ValueGen(i);
            if (Val->getType()->isDoubleTy())
                Val = Builder->CreateFPExt(Val, Type::getDoubleTy(*Context));
            ArgValues.push_back(Val);
        }
    }
    Builder->CreateCall(CalleeF, ArgValues, "c_printf");
}

void CodeGenerator::AssignGen(shared_ptr<Stmt> &StmtUnit) {
    shared_ptr<Variable> VarUnit(reinterpret_pointer_cast<Variable>(StmtUnit->LVal));
    // check symbol table
    AllocaInst *var = NamedValues.find(VarUnit->Var_name);
    // type conversion
    Value *right = ValueGen(StmtUnit->RVal);
    if (var == nullptr) {
        auto global = GlobalValues.find(VarUnit->Var_name);
        if (global == GlobalValues.end()) {
            cout << "error: undefined variable '" << VarUnit->Var_name << "'" << endl;
            exit(0);
        }
        if(GetFuncType(global->second) != GetFuncType(right)){
            if (GetFuncType(global->second) == Int) right = DoubleToInt(right);
            else if (GetFuncType(global->second) == Double) right = IntToDouble(right);
        }
        if(global->second->getValueType()->isArrayTy()){
            auto args = GetGlobalArrayIndex(VarUnit);
            ArrayRef<Value*> argsRef(args);
            Builder->CreateStore(right, Builder->CreateInBoundsGEP(global->second->getValueType()->getScalarType(), global->second, argsRef));
        }
        else Builder->CreateStore(right, global->second);
    }
    else {
        auto varType = var->getAllocatedType();
        if (varType->isStructTy()){
            structInfo info = NamedValues.findStruct(VarUnit->Var_name);
            int i = find(info.field.begin(), info.field.end(), VarUnit->Member_name) - info.field.begin();
            Value* loc = Builder->CreateInBoundsGEP(varType, var, {Builder->getInt32(0), Builder->getInt32(i)});
            Builder->CreateStore(right, loc);
        }
        else {
            if (varType != right->getType()) {
                if (varType->isIntegerTy()) right = DoubleToInt(right);
                else if (varType->isDoubleTy()) right = IntToDouble(right);
            }
            if (VarUnit->Length.empty()) Builder->CreateStore(right, var);
            else {
                // if is array
                Value *location = GetLocation(VarUnit, var);
                Builder->CreateStore(right, location);
            }
        }
    }
}

Value *CodeGenerator::GetLocation(const shared_ptr<Variable> &VarUnit, AllocaInst *var) {
    Value *location;
    Value *index = GetArrayIndex(VarUnit);
    if (var->getAllocatedType()->isPointerTy()){
        Value *st = Builder->CreateLoad(var->getAllocatedType(), var, var->getName().data());
        if (var->getAllocatedType() == GetPtrType(Int))
            location = Builder->CreateInBoundsGEP(GetType(Int), st, index);
        else
            location = Builder->CreateInBoundsGEP(GetType(Double), st, index);
    }
    else location = Builder->CreateInBoundsGEP(var->getAllocatedType(), var, index);
    return location;
}

void CodeGenerator::IfGen(Function *F, shared_ptr<Stmt> &StmtUnit) {
    BasicBlock *ThenBB = createBB(F, "then");
    BasicBlock *ElseBB = createBB(F, "else");
    BasicBlock *MergeBB = createBB(F, "ifcond");

    // condition generation
    Value *cond = ValueGen(StmtUnit->Condition);
    Builder->CreateCondBr(cond, ThenBB, ElseBB);

    // condition = true
    Builder->SetInsertPoint(ThenBB);
    std::vector<std::string> removeList;
    for(auto &true_block : StmtUnit->First_block){
        if(true_block->AST_type == DECL) DeclGen(true_block, removeList);
        else if(true_block->AST_type == STMT) StmtGen(F, true_block);
    }
    NamedValues.remove(removeList);
    Builder->CreateBr(MergeBB);

    // condition = false
    Builder->SetInsertPoint(ElseBB);
    if (!StmtUnit->Second_block.empty()) {
        for(auto & false_block : StmtUnit->Second_block){
            if(false_block->AST_type == DECL) DeclGen(false_block, removeList);
            else if(false_block->AST_type == STMT) StmtGen(F, false_block);
        }
        NamedValues.remove(removeList);
    }
    Builder->CreateBr(MergeBB);

    // merge
    Builder->SetInsertPoint(MergeBB);

}

// IfGen used in While
void CodeGenerator::IfGen(Function *F, shared_ptr<Stmt> &StmtUnit, BasicBlock *loopBB, BasicBlock *endLoopBB) {
    BasicBlock *ifBB = createBB(F, "if");
    BasicBlock *elseBB = createBB(F, "else");
    BasicBlock *mergeBB = createBB(F, "merge");
    // BasicBlock *endBB = createBB(F, "endif");
    bool is_break_if = false;
    bool is_break_else = false;


    // condition generation
    Value *ifcond = ValueGen(StmtUnit->Condition);
    Builder->CreateCondBr(ifcond, ifBB, elseBB);

    // condition = true
    Builder->SetInsertPoint(ifBB);
    std::vector<std::string> removeList;
    for(auto &true_block : StmtUnit->First_block){
        if(true_block->AST_type == DECL) DeclGen(true_block, removeList);
        else if(true_block->AST_type == STMT) {
            //StmtGen: true_block
            shared_ptr<Stmt> StmtFirst(reinterpret_pointer_cast<Stmt>(true_block));
            if (StmtFirst->Stmt_type == If) IfGen(F, StmtFirst, loopBB, endLoopBB);
            else if (StmtFirst->Stmt_type == While) WhileGen(F, StmtFirst);
            else if (StmtFirst->Stmt_type == Break) {
                is_break_if = true;
                break;
            }
            else if (StmtFirst->Stmt_type == Assign) AssignGen(StmtFirst);
            else if (StmtFirst->Stmt_type == Return){
                if(StmtFirst->RVal == nullptr) Builder->CreateRetVoid();
                else Builder->CreateRet(ValueGen(StmtFirst->RVal));
            }
            else if (StmtFirst->Stmt_type == Printf) PrintfGen(StmtFirst);
            else if (StmtFirst->Stmt_type == Scanf) ScanfGen(StmtFirst);
        }
    }
    NamedValues.remove(removeList);

    if(!is_break_if)
        Builder->CreateBr(mergeBB);
    else
        Builder->CreateBr(endLoopBB);

    // condition = false
    Builder->SetInsertPoint(elseBB);
    if (!StmtUnit->Second_block.empty()) {
        for(auto & false_block : StmtUnit->Second_block){
            if(false_block->AST_type == DECL) DeclGen(false_block, removeList);
            else if(false_block->AST_type == STMT) {
            //StmtGen: false_block
            shared_ptr<Stmt> StmtSecond(reinterpret_pointer_cast<Stmt>(false_block));
            if (StmtSecond->Stmt_type == If) IfGen(F, StmtSecond, loopBB, endLoopBB);
            else if (StmtSecond->Stmt_type == While) WhileGen(F, StmtSecond);
            else if (StmtSecond->Stmt_type == Break) {
                is_break_else = true;
                // Builder->CreateBr(endLoopBB);
                break;
            }
            else if (StmtSecond->Stmt_type == Assign) AssignGen(StmtSecond);
            else if (StmtSecond->Stmt_type == Return){
                if(StmtSecond->RVal == nullptr) Builder->CreateRetVoid();
                else Builder->CreateRet(ValueGen(StmtSecond->RVal));
            }
            else if (StmtSecond->Stmt_type == Printf) PrintfGen(StmtSecond);
            else if (StmtSecond->Stmt_type == Scanf) ScanfGen(StmtSecond);
            }
        }
        // Builder->CreateBr(MergeBB);
        NamedValues.remove(removeList);
    }
    if(!is_break_else)
        Builder->CreateBr(mergeBB);
    else
        Builder->CreateBr(endLoopBB);
    // merge
    Builder->SetInsertPoint(mergeBB);
}

// CodeGen of "while" -> 在while中的if中实现continue和break
void CodeGenerator::WhileGen(Function *F, shared_ptr<Stmt> &StmtUnit) {

    // BasicBlock *entryBB = createBB(F, "entry");
    BasicBlock *loopBB = createBB(F, "loop");
    BasicBlock *endLoopBB = createBB(F, "endLoop");
    // BasicBlock *endWhileBB = createBB(F, "endWhile");

    // Builder->SetInsertPoint(entryBB);
    // condition generation
    Value *EndCond = ValueGen(StmtUnit->Condition);
    // 根据EndCond判断是否跳转
    Builder->CreateCondBr(EndCond, loopBB, endLoopBB);

    // loop:
    Builder->SetInsertPoint(loopBB);
    std::vector<std::string> removeList;
    for(auto &true_block : StmtUnit->First_block){
        if(true_block->AST_type == DECL) DeclGen(true_block, removeList);
        else if(true_block->AST_type == STMT) {
            // StmtGen(F, true_block);
            shared_ptr<Stmt> StmtWhile(reinterpret_pointer_cast<Stmt>(true_block));
            if (StmtWhile->Stmt_type == If) IfGen(F, StmtWhile, loopBB, endLoopBB);
            else if (StmtWhile->Stmt_type == While) WhileGen(F, StmtWhile);
            else if (StmtWhile->Stmt_type == Assign) AssignGen(StmtWhile);
            else if (StmtWhile->Stmt_type == Return){
                if(StmtWhile->RVal == nullptr) Builder->CreateRetVoid();
                else Builder->CreateRet(ValueGen(StmtWhile->RVal));
            }
            else if (StmtWhile->Stmt_type == Printf) PrintfGen(StmtWhile);
            else if (StmtWhile->Stmt_type == Scanf) ScanfGen(StmtWhile);
        }
    }
    NamedValues.remove(removeList);
    // endLoop or not
    EndCond = ValueGen(StmtUnit->Condition);
    Builder->CreateCondBr(EndCond, loopBB, endLoopBB);

    Builder->SetInsertPoint(endLoopBB);
    // endWhile:
    // Builder->SetInsertPoint(endWhileBB);
}

Value *CodeGenerator::IntToDouble(Value *InitVal) {
    InitVal = Builder->CreateSIToFP(InitVal, Type::getDoubleTy(*Context));
    return InitVal;
}

Value *CodeGenerator::DoubleToInt(Value *InitVal) {
    InitVal = Builder->CreateFPToSI(InitVal, Type::getInt32Ty(*Context));
    return InitVal;
}

CodeGenerator::CodeGenerator(const string& name) {
    Context = std::make_unique<LLVMContext>();
    GeneratorModule = std::make_unique<Module>(name, *Context);
    Builder = std::make_unique<IRBuilder<>>(*Context);
    // Create a new pass manager attached to it.
    TheFPM = std::make_unique<legacy::FunctionPassManager>(GeneratorModule.get());

    // Do simple "peephole" optimizations and bit-twiddling optzns.
    TheFPM->add(createInstructionCombiningPass());
    // Reassociate expressions.
    TheFPM->add(createReassociatePass());
    // Eliminate Common SubExpressions.
    TheFPM->add(createGVNPass());
    // Simplify the control flow graph (deleting unreachable blocks, etc).
    TheFPM->add(createCFGSimplificationPass());
    // Loop unroll.
    TheFPM->add(createLoopUnrollPass(3));

    TheFPM->doInitialization();
}

Type *CodeGenerator::GetType(type FuncType) {
    switch (FuncType) {
        case Int:
            return Type::getInt32Ty(*Context);
        case Double:
            return Type::getDoubleTy(*Context);
        case Void:
            return Type::getVoidTy(*Context);
    }
}

BasicBlock *CodeGenerator::createBB(Function *fooFunc, const string &Name) {
    return BasicBlock::Create(*Context, Name, fooFunc);
}

Value *CodeGenerator::ValueGen(shared_ptr<BaseAST> &input) {
    if (input->AST_type == FINALEXP) {
        shared_ptr<FinalExp> expression(reinterpret_pointer_cast<FinalExp>(input));
        if(expression->Exp_type == Double) return ConstantFP::get(*Context, APFloat(expression->Number));
        else if(expression->Exp_type == Int) return ConstantInt::get(*Context, APInt(32, int(expression->Number)));
    }
    else if (input->AST_type == VARIABLE){
        shared_ptr<Variable> variable(reinterpret_pointer_cast<Variable>(input));
        AllocaInst *var = NamedValues.find(variable->Var_name);
        if (var == nullptr) {
            auto global = GlobalValues.find(variable->Var_name);
            if (global == GlobalValues.end()) {
                cout << "Error: Undefined variable " << variable->Var_name << endl;
                exit(1);
            }
            if (global->second->getValueType()->isArrayTy()){
                auto args = GetGlobalArrayIndex(variable);
                ArrayRef<Value*> argsRef(args);
                type re = GetFuncType(global->second);
                Value *location = Builder->CreateInBoundsGEP(global->second->getValueType()->getScalarType(), global->second, argsRef);
                return Builder->CreateLoad(GetType(re), location);
            }
            else
                return Builder->CreateLoad(global->second->getValueType(), global->second);
        }
        else {
            auto varType = var->getAllocatedType();
            if (varType->isStructTy()){
                structInfo info = NamedValues.findStruct(variable->Var_name);
                int i;
                for(int idx = 0; idx < info.field.size(); ++idx)
                    if (info.field[idx] == variable->Member_name) {
                        i = idx;
                        break;
                    }
                Value* loc = Builder->CreateInBoundsGEP(varType, var, {Builder->getInt32(0), Builder->getInt32(i)});
                return Builder->CreateLoad(var->getAllocatedType()->getStructElementType(i), loc);
            }
            else {
                if (variable->Length.empty())
                    return Builder->CreateLoad(var->getAllocatedType(), var, var->getName().data());
                else {
                    Value *location = GetLocation(variable, var);
                    type re = GetFuncType(var);
                    return Builder->CreateLoad(GetType(re), location, var->getName().data());
                }
            }
        }
    }
    else if (input->AST_type == FUNCPROTO) return FuncCallGen(input);
    else if (input->AST_type == EXP) return ExpGen(input);
}

Value *CodeGenerator::ExpGen(const shared_ptr<BaseAST> &input) {
    shared_ptr<Exp> expression(reinterpret_pointer_cast<Exp>(input));
    Value *L = ValueGen(expression->Left_exp);
    // fake EXP node
    if (expression->Operator.empty()) return L;
    Value *R = ValueGen(expression->Right_exp);
    bool is_Double = DoubleGen(L, R);

    // expression generation
    if(expression->Operator == "+"){
        if (is_Double) return Builder->CreateFAdd(L, R);
        else return Builder->CreateAdd(L, R);
    }
    else if(expression->Operator == "-"){
        if (is_Double) return Builder->CreateFSub(L, R);
        else return Builder->CreateSub(L, R);
    }
    else if(expression->Operator == "*"){
        if (is_Double) return Builder->CreateFMul(L, R);
        else return Builder->CreateMul(L, R);
    }
    else if(expression->Operator == "/"){
        if(L->getType()->isIntegerTy()) L = Builder->CreateSIToFP(L, Type::getDoubleTy(*Context));
        if(R->getType()->isIntegerTy()) R = Builder->CreateSIToFP(R, Type::getDoubleTy(*Context));
        return Builder->CreateFDiv(L, R);
    }
    else if(expression->Operator == "==") {
        if (is_Double) return Builder->CreateFCmpOEQ(L, R);
        else return Builder->CreateICmpEQ(L, R );
    }
    else if (expression->Operator == "!="){
        if (is_Double) return Builder->CreateFCmpONE(L, R);
        else return Builder->CreateICmpNE(L, R);
    }
    else if (expression->Operator == "<") {
        if (is_Double) return Builder->CreateFCmpOLT(L, R);
        else return Builder->CreateICmpSLT(L, R);
    }
    else if (expression->Operator == ">") {
        if (is_Double) return Builder->CreateFCmpOGT(L, R);
        else return Builder->CreateICmpSGT(L, R);
    }
    else if (expression->Operator == "<=") {
        if (is_Double) return Builder->CreateFCmpOLE(L, R);
        else return Builder->CreateICmpSLE(L, R);
    }
    else if (expression->Operator == ">=") {
        if (is_Double) return Builder->CreateFCmpOGE(L, R);
        else return Builder->CreateICmpSGE(L, R);
    }
    else if (expression->Operator == "&&") {
        return Builder->CreateAnd(L, R);
    }
    else if (expression->Operator == "||") {
        return Builder->CreateOr(L, R);
    }
    else if (expression->Operator == "%") {
        if (L->getType()->isDoubleTy()) L = DoubleToInt(L);
        if (R->getType()->isDoubleTy()) R = DoubleToInt(R);
        return Builder->CreateSRem(L, R);
    }
}

type CodeGenerator::GetFuncType(const AllocaInst *var) {
    type re;
    if (var->getAllocatedType()->isPointerTy()){
        if (var->getAllocatedType() == GetPtrType(Int))
            re = Int;
        else re = Double;
    }else {
        if (var->getAllocatedType() == GetType(Int))
            re = Int;
        else re = Double;
    }
    return re;
}

type CodeGenerator::GetFuncType(const GlobalVariable *var) {
    type re;
    auto tmp = var->getValueType();
    if(tmp->isArrayTy()){
        if(tmp->getArrayElementType()->isIntegerTy()) re = Int;
        else re = Double;
    }
    else{
        if(tmp->isIntegerTy()) re = Int;
        else re = Double;
    }
    return re;
}

type CodeGenerator::GetFuncType(const Value *var) {
    type re;
    if (var->getType()->isPointerTy()){
        if (var->getType() == GetPtrType(Int))
            re = Int;
        else re = Double;
    }else {
        if (var->getType() == GetType(Int))
            re = Int;
        else re = Double;
    }
    return re;
}

Value *CodeGenerator::FuncCallGen(shared_ptr<BaseAST> &input) {
    shared_ptr<FuncPrototype> prototype(reinterpret_pointer_cast<FuncPrototype>(input));
    Function *CalleeF = GeneratorModule->getFunction(prototype->Func_name);
    if (CalleeF == nullptr) {
        cout << "error: use of undeclared function '" << prototype->Func_name << "'" << endl;
        exit(0);
    }
    vector<Value*> ArgsV{};
    if (!prototype->Params.empty()){
        for(auto & Param : prototype->Params){
            if (Param->AST_type == VARIABLE){
                shared_ptr<Variable> VarUnit(reinterpret_pointer_cast<Variable>(Param));
                AllocaInst *var = NamedValues.find(VarUnit->Var_name);
                if (var == nullptr){
                    cout << "Error: Undefined variable " << VarUnit->Var_name << endl;
                    exit(1);
                }
                vector<shared_ptr<BaseAST>> dim = NamedValues.array_dim(VarUnit->Var_name);
                if (var->getAllocatedType()->isPointerTy())
                    ArgsV.push_back(Builder->CreateLoad(var->getAllocatedType(), var, var->getName().data()));
                else if (!dim.empty() && VarUnit->Length.empty())
                    ArgsV.push_back(Builder->CreateInBoundsGEP(var->getAllocatedType(), var, ConstantInt::get(*Context, APInt(32, 0))));
                else{
                    shared_ptr<BaseAST> te(reinterpret_pointer_cast<BaseAST>(VarUnit));
                    ArgsV.push_back(ValueGen(te));
                }
            }
            else if (Param->AST_type == EXP) ArgsV.push_back(ValueGen(Param));
        }
    }
    return Builder->CreateCall(CalleeF, ArgsV, "calltmp");
}

bool CodeGenerator::DoubleGen(Value *&L, Value *&R) {
    bool is_Double= !(L->getType()->isIntegerTy() && R->getType()->isIntegerTy());
    if (is_Double){
        if(L->getType()->isIntegerTy()) L = IntToDouble(L);
        if(R->getType()->isIntegerTy()) R = IntToDouble(R);
    }
    return is_Double;
}

AllocaInst *CodeGenerator::createBlockAlloca(BasicBlock &block, const string &VarName, type VarType) {
    IRBuilder<> TmpB(&block, block.begin());
    return TmpB.CreateAlloca(GetType(VarType), nullptr, VarName);
}

AllocaInst *CodeGenerator::createBlockPtrAlloca(BasicBlock &block, const string &VarName, type VarType) {
    IRBuilder<> TmpB(&block, block.begin());
    return TmpB.CreateAlloca(GetPtrType(VarType), nullptr, VarName);
}

AllocaInst *CodeGenerator::createBlockAlloca(BasicBlock &block, const string &VarName, type VarType, Value* ArraySize) {
    IRBuilder<> TmpB(&block, block.begin());
    return TmpB.CreateAlloca(GetType(VarType), ArraySize, VarName);
}

Type *CodeGenerator::GetPtrType(type FuncType) {
    switch (FuncType) {
        case Int:
            return Type::getInt32PtrTy(*Context);
        case Double:
            return Type::getDoublePtrTy(*Context);
    }
}
