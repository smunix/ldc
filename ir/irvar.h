#ifndef LLVMDC_IR_IRVAR_H
#define LLVMDC_IR_IRVAR_H

#include "ir/ir.h"
#include "llvm/Type.h"

struct IrVar : IrBase
{
    IrVar(VarDeclaration* var);

    VarDeclaration* V;
    llvm::Value* value;
};

// represents a global variable
struct IrGlobal : IrVar
{
    IrGlobal(VarDeclaration* v);

    llvm::PATypeHolder type;
    llvm::Constant* constInit;
};

// represents a local variable variable
struct IrLocal : IrVar
{
    IrLocal(VarDeclaration* v);

    int nestedIndex;
};

// represents an aggregate field variable
struct IrField : IrVar
{
    IrField(VarDeclaration* v);

    int index;
    size_t indexOffset;
    llvm::Constant* constInit;
};

#endif