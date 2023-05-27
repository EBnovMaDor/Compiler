#ifndef CODE_GENERATOR_HPP
#define CODE_GENERATOR_HPP

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/ValueSymbolTable.h"
#include "llvm/IR/SymbolTableListTraits.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/LoopUnrollPass.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Vectorize/LoopVectorize.h"
#include "llvm/IR/Instructions.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "AST.hpp"
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace llvm;

typedef struct _structInfo
{
    StructType *type;
    vector<string> field;
} structInfo;

class CodeGenerator
{
private:
    std::unique_ptr<LLVMContext> Context;
    std::unique_ptr<IRBuilder<>> Builder;
    std::unique_ptr<Module> GeneratorModule;
    std::unordered_map<std::string, GlobalVariable *> GlobalValues;
    std::unique_ptr<legacy::FunctionPassManager> TheFPM;
    // symbolTable NamedValues;

    BasicBlock *createBB(Function *fooFunc, const std::string &Name);
    AllocaInst *createBlockAlloca(BasicBlock &block, const string &VarName, type VarType);
    AllocaInst *createBlockPtrAlloca(BasicBlock &block, const string &VarName, type VarType);
    AllocaInst *createBlockAlloca(BasicBlock &block, const string &VarName, type VarType, Value *ArraySize);
    Value *IntToDouble(Value *input);
    Value *DoubleToInt(Value *InitVal);
    Value *FuncCallGen(shared_ptr<BaseAST> &input);
    void OutputGen(const string & name);
    void InitExternalFunction();
    Value *ValueGen(shared_ptr<BaseAST> &input);
    Type *GetType(type FuncType);
    Type *GetPtrType(type FuncType);
    type GetFuncType(const AllocaInst *var);
    type GetFuncType(const GlobalVariable *var);
    type GetFuncType(const Value *var);
    Value *GetArraySize(shared_ptr<Variable> &VarUnit);
    Value *GetLocation(const shared_ptr<Variable> &VarUnit, AllocaInst *var);
    Value *ExpGen(const shared_ptr<BaseAST> &input);
    Value *GetArrayIndex(const shared_ptr<Variable> &VarUnit);
    vector<Value *> GetGlobalArrayIndex(const shared_ptr<Variable> &VarUnit);
    bool DoubleGen(Value *&L, Value *&R);
    void AssignGen(shared_ptr<Stmt> &StmtUnit);
    void IfGen(Function *F, shared_ptr<Stmt> &StmtUnit);
    void IfGen(Function *F, shared_ptr<Stmt> &StmtUnit, BasicBlock *loopBB, BasicBlock *endLoopBB);
    void WhileGen(Function *F, shared_ptr<Stmt> &StmtUnit);
    void GlobalVarGen(shared_ptr<BaseAST> &Unit);
    void DeclGen(shared_ptr<BaseAST> &Block, vector<std::string> &removeList);
    void FuncGen(shared_ptr<BaseAST> &Unit);
    void StmtGen(Function *F, shared_ptr<BaseAST> &Block);
    void PrintfGen(shared_ptr<Stmt> &StmtUnit);
    void ScanfGen(shared_ptr<Stmt> &StmtUnit);

    class symbolTable
    {
    private:
        unordered_map<string, structInfo> structTable;
        unordered_map<string, stack<AllocaInst *>> table;
        // value indicate array dim, 0 indicate it's not an array
        unordered_map<string, stack<vector<shared_ptr<BaseAST>>>> array;

    public:
        void insert(const std::string &name, AllocaInst *input, std::vector<std::shared_ptr<BaseAST>> &dim)
        {
            auto re = table.find(name);
            auto ar = array.find(name);
            // if not in symbol table
            if (re == table.end())
            {
                // add variable
                auto new_stack = std::stack<AllocaInst *>();
                new_stack.push(input);
                table.emplace(name, new_stack);
                // add array length
                auto array_stack = std::stack<std::vector<std::shared_ptr<BaseAST>>>();
                array_stack.push(dim);
                array.emplace(name, array_stack);
            }
            // already have definition in symbol table
            else
            {
                re->second.push(input);
                ar->second.push(dim);
            }
        }
        void insertStruct(const string &name, const structInfo &info)
        {
            structTable.emplace(name, info);
        }
        void remove(const std::vector<std::string> &name)
        {
            for (auto &i : name)
            {
                auto re = table.find(i);
                // TODO: identify possible error
                if (re == table.end())
                    continue;
                if (re->second.size() == 1)
                    table.erase(re);
                else
                    re->second.pop();
            }
        }
        AllocaInst *find(const std::string &name)
        {
            auto re = table.find(name);
            if (re == table.end())
                return nullptr;
            return re->second.top();
        }
        structInfo findStruct(const std::string &name)
        {
            auto re = structTable.find(name);
            if (re == structTable.end())
            {
                structInfo info;
                info.type = nullptr;
                return info;
            }
            return re->second;
        }

        vector<shared_ptr<BaseAST>> array_dim(const std::string &name)
        {
            auto re = array.find(name);
            if (re == array.end())
                return {};
            return re->second.top();
        }
    };
    symbolTable NamedValues;

public:
    explicit CodeGenerator(const string &name);
    void ProgramGen(shared_ptr<CompUnit> &program,const string& name);
};
#endif