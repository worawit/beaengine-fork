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
 *
 * ==================================================================== */
void __bea_callspec__ EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    (*pMyDisasm).Instruction.OperandSize = 32;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Instruction.OperandSize = 32;
    GV.EIP_ += GV.DECALAGE_EIP;
}
/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ ExGx(PDISASM pMyDisasm)
{
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  MMX r/m, MMX reg
 * ==================================================================== */
void __bea_callspec__ MMrmMMreg(PDISASM pMyDisasm)
{
    MOD_RM_MMX(&(*pMyDisasm).Argument1, pMyDisasm);
    RegMMX_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  MMX reg, MMX r/m
 * ==================================================================== */
void __bea_callspec__ MMregMMrm(PDISASM pMyDisasm)
{
    MOD_RM_MMX(&(*pMyDisasm).Argument2, pMyDisasm);
    RegMMX_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  SSE r/m, SSE reg
 * ==================================================================== */
void __bea_callspec__ XMMrmXMMreg(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument1, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  SSE reg, SSE r/m
 * ==================================================================== */
void __bea_callspec__ XMMregXMMrm(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  SSE reg, SSE r/m64
 * ==================================================================== */
void __bea_callspec__ XMMregXMMrm64(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Argument2.ArgSize = 64;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ XMMrm64XMMreg(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument1, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    (*pMyDisasm).Argument1.ArgSize = 64;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  SSE reg, SSE r/m32
 * ==================================================================== */
void __bea_callspec__ XMMregXMMrm32(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Argument2.ArgSize = 32;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ XMMrm32XMMreg(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument1, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    (*pMyDisasm).Argument1.ArgSize = 32;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  MMX reg, SSE r/m
 * ==================================================================== */
void __bea_callspec__ MMregXMMrm(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
    RegMMX_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  SSE r/m, MMX reg
 * ==================================================================== */
void __bea_callspec__ XMMrmMMreg(PDISASM pMyDisasm)
{
    MOD_RM_SSE(&(*pMyDisasm).Argument1, pMyDisasm);
    RegMMX_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  MMX r/m, SSE reg
 * ==================================================================== */
void __bea_callspec__ MMrmXMMreg(PDISASM pMyDisasm)
{
    MOD_RM_MMX(&(*pMyDisasm).Argument1, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *  SSE reg, MMX r/m
 * ==================================================================== */
void __bea_callspec__ XMMregMMrm(PDISASM pMyDisasm)
{
    MOD_RM_MMX(&(*pMyDisasm).Argument2, pMyDisasm);
    RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ EvIv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        GV.ImmediatSize = 32;                       /* place this instruction before MOD_RM routine to inform it there is an immediat value */
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+4;
        if (!Security(0, pMyDisasm)) return;

        (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument2.ArgSize = 32;
        if ((*pMyDisasm).Instruction.OperandSize == 64) {
            (*pMyDisasm).Instruction.Immediat = *((Int32*)(UIntPtr) (GV.EIP_-4));
        }
        else {
            (*pMyDisasm).Instruction.Immediat = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        }
    }
    else {
        GV.ImmediatSize = 16;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_-2));
    }
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ EvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP+1;
    if (!Security(0, pMyDisasm)) return;

    (*pMyDisasm).Instruction.Immediat = *((Int8*)(UIntPtr) (GV.EIP_-1));
}
/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ EbIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Instruction.OperandSize = 32;
    GV.EIP_ += GV.DECALAGE_EIP+1;
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_-1));
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ Eb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.OperandSize = 8;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Argument1.ArgSize = 8;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ Ev(PDISASM pMyDisasm)
{
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ GvEv(PDISASM pMyDisasm)
{
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ GvMptp(PDISASM pMyDisasm)
{
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_ == 3) FailDecode(pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize + 16;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE + FARPTR_MEM;
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ GvEd(PDISASM pMyDisasm)
{
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    (*pMyDisasm).Argument2.ArgSize = 32;
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument2.ArgSize = 8;
    if ((*pMyDisasm).Instruction.OperandSize == 64) {
        (*pMyDisasm).Instruction.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Instruction.OperandSize = 64;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Instruction.OperandSize = 32;
    }
    else {
        (*pMyDisasm).Instruction.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Instruction.OperandSize = 16;
    }
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ GxEx(PDISASM pMyDisasm)
{
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Argument2.ArgSize = 16;
    GV.OriginalOperandSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Instruction.OperandSize = 16;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ ALIb(PDISASM pMyDisasm)
{
    long MyNumber;
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((UInt8*)(IntPtr) (GV.EIP_));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_++;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ eAX_Iv(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+= 4;
        (*pMyDisasm).Argument2.ArgSize = 32;
        if (!Security(0, pMyDisasm)) return;
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int32) MyNumber;
    }
    else if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        GV.EIP_+= 4;
        (*pMyDisasm).Argument2.ArgSize = 32;
        if (!Security(0, pMyDisasm)) return;
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = MyNumber;
    }
    else {
        GV.EIP_+= 2;
        (*pMyDisasm).Argument2.ArgSize = 16;
        if (!Security(0, pMyDisasm)) return;
        MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = MyNumber;
    }
}
