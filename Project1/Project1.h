#pragma once

#include "llvm/IR/Dominators.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Value.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

#include <string>
#include <unordered_map>

namespace llvm {

class Project1 : public FunctionPass {
public:
    static char ID;
    Project1() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override;
    void getAnalysisUsage(AnalysisUsage& AU) const override;
    bool doFinalization(Module& m) override;

private:
    void collectAllAllocInfo(const Function& F, std::unordered_map<std::string, Value*>& arrayNameToSize);

};

} // namespace llvm
