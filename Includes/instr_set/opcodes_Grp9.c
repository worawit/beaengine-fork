/* Copyright 2006-2009, BeatriX
 * File coded by BeatriX
 *
 * This file is part of BeaEngine.
 *
 *    BeaEngine is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    BeaEngine is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>. */


/* ====================================================================
 *      0fc7h
 * ==================================================================== */
void __bea_callspec__ G9_(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    (*pMyDisasm).Argument1.ArgSize = 64;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_ == 3) {
        FailDecode(pMyDisasm);
        return;
    }
    if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        if ((*pMyDisasm).Prefix.REX.W_) {
            (*pMyDisasm).Argument1.ArgSize = 128;
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_CMPXCHG16B;
            (*pMyDisasm).Instruction.ImplicitUsedRegs = GENERAL_REG+REG0+REG2+REG1+REG3;
            (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG2;
            FillFlags(pMyDisasm, EFLAGS_CMPXCHGG8B);
            GV.EIP_ += GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_CMPXCHG8B;
            (*pMyDisasm).Instruction.ImplicitUsedRegs = GENERAL_REG+REG0+REG2+REG1+REG3;
            (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG2;
            FillFlags(pMyDisasm, EFLAGS_CMPXCHGG8B);
            GV.EIP_ += GV.DECALAGE_EIP+2;
        }
        if ((*pMyDisasm).Prefix.LockState == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockState = InUsePrefix;
        }
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
        (*pMyDisasm).Argument1.AccessMode = READ;
        if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
            (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
            (*pMyDisasm).Instruction.Mnemonic = I_VMXON;
        }
        else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
            (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
            (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
            (*pMyDisasm).Instruction.Mnemonic = I_VMCLEAR;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_VMPTRLD;
        }
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_VMPTRST;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }

}
