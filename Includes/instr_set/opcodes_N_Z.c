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
 *      90h
 * ==================================================================== */
void __bea_callspec__ nop_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.Mnemonic = I_PAUSE;
        GV.EIP_++;
    }
    else {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 64;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0+8];
            (*pMyDisasm).Argument2.ArgSize = 64;
            (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
            GV.EIP_++;
        }
        else {
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_NOP;
            GV.EIP_++;
        }
    }
}

/* =======================================
 *      90h
 * ======================================= */
void __bea_callspec__ nop_Ev(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_NOP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP+2;
    (*pMyDisasm).Argument1.AccessMode = 0;
}

/* =======================================
 *      0f19h
 * ======================================= */
void __bea_callspec__ hint_nop(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_HINT_NOP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* =======================================
 *      08h
 * ======================================= */
void __bea_callspec__ or_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OR;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_OR);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      09h
 * ======================================= */
void __bea_callspec__ or_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OR;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_OR);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      0ah
 * ======================================= */
void __bea_callspec__ or_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OR;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_OR);
}

/* =======================================
 *      0bh
 * ======================================= */
void __bea_callspec__ or_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OR;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_OR);
}

/* =======================================
 *      0ch
 * ======================================= */
void __bea_callspec__ or_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OR;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_OR);
}

/* =======================================
 *      0dh
 * ======================================= */
void __bea_callspec__ or_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OR;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_OR);
}


/* =======================================
 *      06eh
 * ======================================= */
void __bea_callspec__ outsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        (*pMyDisasm).Instruction.Mnemonic = I_OUTS;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_OUTSB;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
    }
    
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_OUTS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
}

/* =======================================
 *      06fh
 * ======================================= */
void __bea_callspec__ outsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        (*pMyDisasm).Instruction.Mnemonic = I_OUTS;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize >= 32) {
            (*pMyDisasm).Instruction.Mnemonic = I_OUTSD;
            (*pMyDisasm).Argument2.ArgSize = 32;
        }

        else {
            (*pMyDisasm).Instruction.Mnemonic = I_OUTSW;
            (*pMyDisasm).Argument2.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
    }
    
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_OUTS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
}

/* =======================================
 *      e6h
 * ======================================= */
void __bea_callspec__ out_IbAL(PDISASM pMyDisasm)
{
    Int32 MyNumber;

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OUT;
    if (!Security(2, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      e7h
 * ======================================= */
void __bea_callspec__ out_Ib_eAX(PDISASM pMyDisasm)
{
    Int32 MyNumber;

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OUT;
    if (!Security(2, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    GV.EIP_ += 2;
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ out_DXAL(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OUT;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ ++;
}

/* =======================================
 *      efh
 * ======================================= */
void __bea_callspec__ out_DXeAX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_OUT;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    GV.EIP_ ++;
}

/* =======================================
 *      8fh
 * ======================================= */
void __bea_callspec__ pop_Ev(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Mnemonic = I_POP;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
            (*pMyDisasm).Argument1.ArgSize = 64;
        }
        else {
            (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      58h
 * ======================================= */
void __bea_callspec__ pop_eax(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      59h
 * ======================================= */
void __bea_callspec__ pop_ecx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      5ah
 * ======================================= */
void __bea_callspec__ pop_edx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];

        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      5bh
 * ======================================= */
void __bea_callspec__ pop_ebx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      5ch
 * ======================================= */
void __bea_callspec__ pop_esp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      5dh
 * ======================================= */
void __bea_callspec__ pop_ebp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      5eh
 * ======================================= */
void __bea_callspec__ pop_esi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      5fh
 * ======================================= */
void __bea_callspec__ pop_edi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7];
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    }
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      07h
 * ======================================= */
void __bea_callspec__ pop_es(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[0];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      17h
 * ======================================= */
void __bea_callspec__ pop_ss(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[2];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      1fh
 * ======================================= */
void __bea_callspec__ pop_ds(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[3];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      0fa1h
 * ======================================= */
void __bea_callspec__ pop_fs(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[4];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      0fa9h
 * ======================================= */
void __bea_callspec__ pop_gs(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POP;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[5];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      9dh
 * ======================================= */
void __bea_callspec__ popfd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;

    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Instruction.Mnemonic = I_POPFQ;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        FillFlags(pMyDisasm, EFLAGS_POPF);
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_POPFD;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        FillFlags(pMyDisasm, EFLAGS_POPF);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_POPF;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        FillFlags(pMyDisasm, EFLAGS_POPF);
    }
}

/* =======================================
 *      9dh
 * ======================================= */
void __bea_callspec__ popad_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;

    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_POPAD;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_POPA;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
    }
}


/* =======================================
 *      06h
 * ======================================= */
void __bea_callspec__ push_es(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[0];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      16h
 * ======================================= */
void __bea_callspec__ push_ss(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[2];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      1eh
 * ======================================= */
void __bea_callspec__ push_ds(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[3];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      0fa0h
 * ======================================= */
void __bea_callspec__ push_fs(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[4];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      0fa8
 * ======================================= */
void __bea_callspec__ push_gs(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[5];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}

/* =======================================
 *      0e
 * ======================================= */
void __bea_callspec__ push_cs(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[1];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_++;
    }
}



/* =======================================
 *      50h
 * ======================================= */
void __bea_callspec__ push_eax(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}

/* =======================================
 *      51h
 * ======================================= */
void __bea_callspec__ push_ecx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}

/* =======================================
 *      52h
 * ======================================= */
void __bea_callspec__ push_edx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];

        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}

/* =======================================
 *      53h
 * ======================================= */
void __bea_callspec__ push_ebx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}

/* =======================================
 *      54h
 * ======================================= */
void __bea_callspec__ push_esp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}

/* =======================================
 *      55h
 * ======================================= */
void __bea_callspec__ push_ebp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}

/* =======================================
 *      56h
 * ======================================= */
void __bea_callspec__ push_esi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}

/* =======================================
 *      57h
 * ======================================= */
void __bea_callspec__ push_edi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7];
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    GV.EIP_++;
}


/* =======================================
 *      68h
 * ======================================= */
void __bea_callspec__ push_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;

    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if ((*pMyDisasm).Archi == 64) {
        if (!Security(5, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        GV.EIP_ += 5;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        GV.EIP_ += 5;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_+1));
        GV.EIP_ += 3;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    }
}

/* =======================================
 *      6ah
 * ======================================= */
void __bea_callspec__ push_Ib(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_PUSH;
    if (!Security(2, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    GV.EIP_ += 2;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}


/* =======================================
 *      9ch
 * ======================================= */
void __bea_callspec__ pushfd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;

    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Instruction.Mnemonic = I_PUSHFQ;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        FillFlags(pMyDisasm, EFLAGS_PUSHF);
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_PUSHFD;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        FillFlags(pMyDisasm, EFLAGS_PUSHF);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PUSHF;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        FillFlags(pMyDisasm, EFLAGS_PUSHF);
    }
}


/* =======================================
 *      60h
 * ======================================= */
void __bea_callspec__ pushad_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;

    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_PUSHAD;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        (*pMyDisasm).Instruction.ImplicitUsedRegs = GENERAL_REG+REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PUSHA;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        (*pMyDisasm).Instruction.ImplicitUsedRegs = GENERAL_REG+REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
    }
}

/* =======================================
 *      0c2h
 * ======================================= */
void __bea_callspec__ retn_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    (*pMyDisasm).Instruction.Mnemonic = I_RETN;
    if (!Security(3, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_+1));
    GV.EIP_+=3;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      0c3h
 * ======================================= */
void __bea_callspec__ ret_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    (*pMyDisasm).Instruction.Mnemonic = I_RET;
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      cbh
 * ======================================= */
void __bea_callspec__ retf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    (*pMyDisasm).Instruction.Mnemonic = I_RETF;
    GV.EIP_++;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      cah
 * ======================================= */
void __bea_callspec__ retf_Iw(PDISASM pMyDisasm)
{
    int i = 0;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    (*pMyDisasm).Instruction.Mnemonic = I_RETF;
    if (!Security(3, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_+1));
    GV.EIP_+=3;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
}

/* =======================================
 *      0f31h
 * ======================================= */
void __bea_callspec__ rdtsc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_RDTSC;
    GV.EIP_++;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 32;
    (*pMyDisasm).Argument2.AccessMode = WRITE;
}

/* =======================================
 *      0f32h
 * ======================================= */
void __bea_callspec__ rdmsr_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_RDMSR;
    GV.EIP_++;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 32;
    (*pMyDisasm).Argument2.AccessMode = WRITE;
    (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument3.ArgSize = 32;
}

/* =======================================
 *      0f33h
 * ======================================= */
void __bea_callspec__ rdpmc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_RDPMC;
    GV.EIP_++;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 32;
    (*pMyDisasm).Argument2.AccessMode = WRITE;
    (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument3.ArgSize = 32;
}

/* =======================================
 *      0faah
 * ======================================= */
void __bea_callspec__ rsm_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_RSM;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_RSM);
}

/* =======================================
 *      0f34h
 * ======================================= */
void __bea_callspec__ sysenter_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SYSENTER;
    GV.EIP_++;
}

/* =======================================
 *      0f35h
 * ======================================= */
void __bea_callspec__ sysexit_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SYSEXIT;
    GV.EIP_++;
}

/* =======================================
 *      9eh
 * ======================================= */
void __bea_callspec__ sahf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SAHF;
    GV.EIP_++;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_SAHF);
}

/* =======================================
 *      d6h
 * ======================================= */
void __bea_callspec__ salc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = UNDOCUMENTED_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SALC;
    GV.EIP_++;
}


/* =======================================
 *      0ach
 * ======================================= */
void __bea_callspec__ scasb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SCASB;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument2.SegmentReg = ESReg;
    (*pMyDisasm).Argument2.ArgSize = 8;
    
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_SCAS);

    if ((*pMyDisasm).Prefix.Repeat) {
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7;
    }
}

/* =======================================
 *      0adh
 * ======================================= */
void __bea_callspec__ scas_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if ((*pMyDisasm).Instruction.OperandSize == 64) {
        (*pMyDisasm).Instruction.Mnemonic = I_SCASQ;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.SegmentReg = ESReg;
        (*pMyDisasm).Argument2.ArgSize = 64;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_SCAS);
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_SCASD;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.SegmentReg = ESReg;
        (*pMyDisasm).Argument2.ArgSize = 32;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_SCAS);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_SCASW;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.SegmentReg = ESReg;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_SCAS);
    }

    if ((*pMyDisasm).Prefix.Repeat) {
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7;
    }
}

/* =======================================
 *      f9h
 * ======================================= */
void __bea_callspec__ stc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_STC;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_STC);
}

/* =======================================
 *      fbh
 * ======================================= */
void __bea_callspec__ sti_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_STI;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_STI);
}


/* =======================================
 *      0aah
 * ======================================= */
void __bea_callspec__ stos_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_STOSB;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.SegmentReg = ESReg;
    (*pMyDisasm).Argument1.ArgSize = 8;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_STOS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7;
    }
}

/* =======================================
 *      0abh
 * ======================================= */
void __bea_callspec__ stosw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if ((*pMyDisasm).Instruction.OperandSize == 64) {
        (*pMyDisasm).Instruction.Mnemonic = I_STOSQ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.SegmentReg = ESReg;
        (*pMyDisasm).Argument1.ArgSize = 64;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_STOS);
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_STOSD;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.SegmentReg = ESReg;
        (*pMyDisasm).Argument1.ArgSize = 32;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_STOS);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_STOSW;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.SegmentReg = ESReg;
        (*pMyDisasm).Argument1.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_STOS);
    }

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG7;
    }
}

/* =======================================
 *      0f05h
 * ======================================= */
void __bea_callspec__ syscall_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_SYSCALL;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1+REG11;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      0f07h
 * ======================================= */
void __bea_callspec__ sysret_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SYSRET;
        GV.EIP_++;
        (*pMyDisasm).Instruction.ImplicitUsedRegs = GENERAL_REG+REG1+REG11;
    }
    else {
        FailDecode(pMyDisasm);
    }
}



/* =======================================
 *      18h
 * ======================================= */
void __bea_callspec__ sbb_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SBB;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SBB);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      19h
 * ======================================= */
void __bea_callspec__ sbb_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SBB;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SBB);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      1ah
 * ======================================= */
void __bea_callspec__ sbb_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SBB;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SBB);
}

/* =======================================
 *      1bh
 * ======================================= */
void __bea_callspec__ sbb_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SBB;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SBB);
}

/* =======================================
 *      1ch
 * ======================================= */
void __bea_callspec__ sbb_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SBB;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SBB);
}

/* =======================================
 *      1dh
 * ======================================= */
void __bea_callspec__ sbb_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SBB;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SBB);
}

/* =======================================
 *      0f90h
 * ======================================= */
void __bea_callspec__ seto_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_O;
    (*pMyDisasm).Instruction.Mnemonic = I_SETO;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccO);
}

/* =======================================
 *      0f91h
 * ======================================= */
void __bea_callspec__ setno_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_NO;
    (*pMyDisasm).Instruction.Mnemonic = I_SETNO;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccNO);
}

/* =======================================
 *      0f92h
 * ======================================= */
void __bea_callspec__ setb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_B;
    (*pMyDisasm).Instruction.Mnemonic = I_SETB;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccB);
}

/* =======================================
 *      0f93h
 * ======================================= */
void __bea_callspec__ setae_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_AE;
    (*pMyDisasm).Instruction.Mnemonic = I_SETAE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccAE);
}

/* =======================================
 *      0f94h
 * ======================================= */
void __bea_callspec__ sete_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.Mnemonic = I_SETE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccE);
}

/* =======================================
 *      0f95h
 * ======================================= */
void __bea_callspec__ setne_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.Mnemonic = I_SETNE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccNE);
}

/* =======================================
 *      0f96h
 * ======================================= */
void __bea_callspec__ setbe_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_BE;
    (*pMyDisasm).Instruction.Mnemonic = I_SETBE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccBE);
}

/* =======================================
 *      0f97h
 * ======================================= */
void __bea_callspec__ seta_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_A;
    (*pMyDisasm).Instruction.Mnemonic = I_SETA;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccA);
}

/* =======================================
 *      0f98h
 * ======================================= */
void __bea_callspec__ sets_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_S;
    (*pMyDisasm).Instruction.Mnemonic = I_SETS;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccS);
}

/* =======================================
 *      0f99h
 * ======================================= */
void __bea_callspec__ setns_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_NS;
    (*pMyDisasm).Instruction.Mnemonic = I_SETNS;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccNS);
}

/* =======================================
 *      0f9ah
 * ======================================= */
void __bea_callspec__ setp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_P;
    (*pMyDisasm).Instruction.Mnemonic = I_SETP;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccP);
}

/* =======================================
 *      0f9bh
 * ======================================= */
void __bea_callspec__ setnp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_NP;
    (*pMyDisasm).Instruction.Mnemonic = I_SETNP;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccNP);
}

/* =======================================
 *      0f9dh
 * ======================================= */
void __bea_callspec__ setge_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_GE;
    (*pMyDisasm).Instruction.Mnemonic = I_SETGE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccGE);
}

/* =======================================
 *      0f9ch
 * ======================================= */
void __bea_callspec__ setl_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_L;
    (*pMyDisasm).Instruction.Mnemonic = I_SETL;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccL);
}

/* =======================================
 *      0f9eh
 * ======================================= */
void __bea_callspec__ setle_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_LE;
    (*pMyDisasm).Instruction.Mnemonic = I_SETLE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccLE);
}

/* =======================================
 *      0f9fh
 * ======================================= */
void __bea_callspec__ setg_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.ConditionalType = CC_G;
    (*pMyDisasm).Instruction.Mnemonic = I_SETG;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+2;
    FillFlags(pMyDisasm, EFLAGS_ccG);
}


/* =======================================
 *      0fa4h
 * ======================================= */
void __bea_callspec__ shld_EvGvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
    (*pMyDisasm).Instruction.Mnemonic = I_SHLD;
    GV.ImmediatSize = 8;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;

    GV.EIP_+= 1;
    FillFlags(pMyDisasm, EFLAGS_SHIFTDP);
}


/* =======================================
 *     0fa5h
 * ======================================= */
void __bea_callspec__ shld_EvGvCL(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
    (*pMyDisasm).Instruction.Mnemonic = I_SHLD;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument3.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument3.ArgSize = 8;
    FillFlags(pMyDisasm, EFLAGS_SHIFTDP);
}

/* =======================================
 *      0fach
 * ======================================= */
void __bea_callspec__ shrd_EvGvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
    (*pMyDisasm).Instruction.Mnemonic = I_SHRD;
    GV.ImmediatSize = 8;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;

    GV.EIP_+= 1;
    FillFlags(pMyDisasm, EFLAGS_SHIFTDP);
}


/* =======================================
 *      0fadh
 * ======================================= */
void __bea_callspec__ shrd_EvGvCL(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SHIFT_ROTATE;
    (*pMyDisasm).Instruction.Mnemonic = I_SHRD;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument3.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument3.ArgSize = 8;
    FillFlags(pMyDisasm, EFLAGS_SHIFTDP);
}


/* =======================================
 *      fdh
 * ======================================= */
void __bea_callspec__ std_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_STD;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_STD);
}


/* =======================================
 *      28h
 * ======================================= */
void __bea_callspec__ sub_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SUB;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SUB);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      29h
 * ======================================= */
void __bea_callspec__ sub_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SUB;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SUB);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      2ah
 * ======================================= */
void __bea_callspec__ sub_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SUB;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SUB);
}

/* =======================================
 *      2bh
 * ======================================= */
void __bea_callspec__ sub_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SUB;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SUB);
}

/* =======================================
 *      2ch
 * ======================================= */
void __bea_callspec__ sub_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SUB;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SUB);
}

/* =======================================
 *      2dh
 * ======================================= */
void __bea_callspec__ sub_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_SUB;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_SUB);
}

/* =======================================
 *      84h
 * ======================================= */
void __bea_callspec__ test_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_TEST;
    (*pMyDisasm).Argument1.AccessMode = READ;
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_TEST);
}

/* =======================================
 *      85h
 * ======================================= */
void __bea_callspec__ test_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_TEST;
    (*pMyDisasm).Argument1.AccessMode = READ;
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_TEST);
}

/* =======================================
 *      86h
 * ======================================= */
void __bea_callspec__ test_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_TEST;
    (*pMyDisasm).Argument1.AccessMode = READ;
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_TEST);
}

/* =======================================
 *      87h
 * ======================================= */
void __bea_callspec__ test_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_TEST;
    (*pMyDisasm).Argument1.AccessMode = READ;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_TEST);
}

/* =======================================
 *      88h
 * ======================================= */
void __bea_callspec__ test_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_TEST;
    (*pMyDisasm).Argument1.AccessMode = READ;
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_TEST);
}

/* =======================================
 *      89h
 * ======================================= */
void __bea_callspec__ test_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_TEST;
    (*pMyDisasm).Argument1.AccessMode = READ;
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_TEST);
}

/* =======================================
 *      0f0bh
 * ======================================= */
void __bea_callspec__ ud2_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_UD2;
    GV.EIP_++;
}

/* =======================================
 *      0f78h
 * ======================================= */
void __bea_callspec__ vmread_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_VMREAD;
    /* OperandSize prefix has no affect */
    (*pMyDisasm).Instruction.OperandSize = (*pMyDisasm).Archi;
    EvGv(pMyDisasm);
}

/* =======================================
 *      0f79h
 * ======================================= */
void __bea_callspec__ vmwrite_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_VMWRITE;
    /* OperandSize prefix has no affect */
    (*pMyDisasm).Instruction.OperandSize = (*pMyDisasm).Archi;
    GvEv(pMyDisasm);
}

/* =======================================
 *      0f09h
 * ======================================= */
void __bea_callspec__ wbinvd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_WBINVD;
    GV.EIP_++;
}

/* =======================================
 *      0f30h
 * ======================================= */
void __bea_callspec__ wrmsr_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_WRMSR;
    GV.EIP_++;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG1+REG2;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument1.AccessMode = READ;
}


/* =======================================
 *      0fc0h
 * ======================================= */
void __bea_callspec__ xadd_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XADD;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XADD);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      0fc1h
 * ======================================= */
void __bea_callspec__ xadd_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XADD;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XADD);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      91h
 * ======================================= */
void __bea_callspec__ xchg_ecx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_++;
}


/* =======================================
 *      92h
 * ======================================= */
void __bea_callspec__ xchg_edx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_++;
}


/* =======================================
 *      93h
 * ======================================= */
void __bea_callspec__ xchg_ebx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_++;
}


/* =======================================
 *      94h
 * ======================================= */
void __bea_callspec__ xchg_esp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_++;
}


/* =======================================
 *      95h
 * ======================================= */
void __bea_callspec__ xchg_ebp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_++;
}


/* =======================================
 *      96h
 * ======================================= */
void __bea_callspec__ xchg_esi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_++;
}


/* =======================================
 *      97h
 * ======================================= */
void __bea_callspec__ xchg_edi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_++;
}

/* =======================================
 *      0d7h
 * ======================================= */
void __bea_callspec__ xlat_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_XLATB;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.AddressSize;
    GV.EIP_++;
}


/* =======================================
 *      30h
 * ======================================= */
void __bea_callspec__ xor_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_XOR;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XOR);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      31h
 * ======================================= */
void __bea_callspec__ xor_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_XOR;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XOR);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      32h
 * ======================================= */
void __bea_callspec__ xor_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_XOR;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XOR);
}

/* =======================================
 *      33h
 * ======================================= */
void __bea_callspec__ xor_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_XOR;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XOR);
}

/* =======================================
 *      34h
 * ======================================= */
void __bea_callspec__ xor_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_XOR;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XOR);
}

/* =======================================
 *      35h
 * ======================================= */
void __bea_callspec__ xor_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_XOR;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_XOR);
}


/* =======================================
 *      86h
 * ======================================= */
void __bea_callspec__ xchg_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_XOR);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      87h
 * ======================================= */
void __bea_callspec__ xchg_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_XCHG;
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_XOR);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ+WRITE;

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}
