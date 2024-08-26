#include "MyPass.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Support/raw_ostream.h"
#include <string>

namespace llvm{
    static int num = 0;
    PreservedAnalyses MyPass::run(Function &F, FunctionAnalysisManager& FAM) {
        outs() << F.getName() << "\n";
        return PreservedAnalyses::all();
    }

    extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
    llvmGetPassPluginInfo() {
        return {
            LLVM_PLUGIN_API_VERSION, 
            "MyPass", 
            "v0.1",
            [](llvm::PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](llvm::StringRef Name, llvm::FunctionPassManager &FPM,
                llvm::ArrayRef<llvm::PassBuilder::PipelineElement>) {
                  if(Name == "MyPass"){
                    FPM.addPass(llvm::MyPass());
                    return true;
                  }
                  return false;
                }
            );
            }
        };
    }
};
