#include "Project1.h"

#include "llvm/IR/Instructions.h"

namespace llvm {
namespace {

#define END_LINE '\n'
#define OUT_STREAM errs()
#define CAST_TO_ALLOC_PTR(ptr) dynamic_cast<const AllocaInst*>(ptr)

} // namespace

bool Project1::runOnFunction(Function& F) {
    if (F.isDeclaration()) return false;

    OUT_STREAM << "Start analyzing function: " << F.getName() << END_LINE;

    std::unordered_map<std::string, Value*> arrayNameToSize;
    collectAllAllocInfo(F, arrayNameToSize);


    return false;
}

void Project1::getAnalysisUsage(AnalysisUsage& AU) const {
    AU.addRequired<DominatorTreeWrapperPass>();
}

bool Project1::doFinalization(Module& m) {
}

void Project1::collectAllAllocInfo(
    const Function& F,
    std::unordered_map<std::string, Value*>& arrayNameToSize
) {
    OUT_STREAM << "Collection Alloc Info in function: " << F.getName() << END_LINE;

    for (const BasicBlock& block : F.getBasicBlockList()) {
        for (const Instruction& instruction : block) {
            OUT_STREAM << "Instruction is " << instruction.getOpcodeName() << END_LINE;

            for (auto& operand : instruction.operands()) {
                OUT_STREAM << *operand << END_LINE;
            }

            OUT_STREAM << "Instruction is " << *(instruction.getOperand(0)) << END_LINE;
            if (instruction.getOpcode() == llvm::Instruction::Alloca) {
                // Alloca instruction located, further checking needed
                const AllocaInst* allocPtr = dyn_cast<AllocaInst>(&instruction);

                if (allocPtr && allocPtr->isArrayAllocation()) {
                    // Detected an array allocation, remember it
                    // arrayNameToSize.emplace(allocPtr->getName(), allocPtr->getArraySize());

                    OUT_STREAM << "My name is " << instruction.getName() << END_LINE;
                    OUT_STREAM << "My other name is " << *(allocPtr->getArraySize()) << END_LINE;
                    OUT_STREAM << "My other name is " << *(allocPtr->getOperand(0)) << END_LINE;

                }
                
                OUT_STREAM << *(allocPtr->getArraySize()) << " look at me " << END_LINE;
                OUT_STREAM << "My name is " << instruction.getName() << END_LINE;
                OUT_STREAM << "My other name is " << *(allocPtr->getArraySize()) << END_LINE;
                OUT_STREAM << "My other name is " << *(allocPtr->getOperand(0)) << END_LINE;
                
            }
        }
    }
}

} // namespace llvm

char llvm::Project1::ID = 0;
static llvm::RegisterPass<llvm::Project1> X("Project1", "Project1 Stuff", false, false);
