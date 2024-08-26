#pragma once

#include "llvm/IR/PassManager.h"
#include "llvm/IR/Function.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include <llvm/Support/Compiler.h>


namespace llvm {
class MyPass: public PassInfoMixin<MyPass> {
    public:
    PreservedAnalyses run(Function &f, FunctionAnalysisManager &FAM);
};

}

extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
llvmGetPassPluginInfo();

