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
 *    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>.
 * =======================================
 *
 * ======================================= */
static void _FillSegmentDS(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        (*pMyArgument).SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        (*pMyArgument).SegmentReg = DSReg;
    }
}

static void _FillSegmentSS(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        (*pMyArgument).SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        (*pMyArgument).SegmentReg = SSReg;
    }
}
/* =======================================
 *     Mod/RM 0
 * ======================================= */
static void _ModRM0(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.RM_ == 4) {
        if (!Security(2, pMyDisasm)) return;
        _SIB(pMyArgument, pMyDisasm);
    }
    else if (GV.RM_ == 5) {
        Int32 MyNumber;
        UInt64 MyAddress;
        if (!Security(6, pMyDisasm)) return;
        GV.DECALAGE_EIP+=4;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.Displacement = MyNumber;
        if ((*pMyDisasm).Archi == 64) {
            MyNumber += 6 + 1;
            MyNumber += (int) (GV.EIP_-(*pMyDisasm).EIP);
            MyNumber += (GV.ImmediatSize >> 3);
            CalculateRelativeAddress(&MyAddress, (Int64)MyNumber, pMyDisasm);
            (*pMyDisasm).Instruction.AddrValue = MyAddress;
            (*pMyArgument).ArgType = MEMORY_TYPE+RELATIVE_;
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGVAL(GV.RM_|(*pMyDisasm).Prefix.REX.B_);
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *     Mod/RM 1
 * ======================================= */
static void _ModRM1(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    GV.DECALAGE_EIP++;
    if (GV.RM_ == 4) {
        if (!Security(3, pMyDisasm)) return;
        (*pMyArgument).Memory.Displacement = *((Int8*)(UIntPtr) (GV.EIP_+3));
        _SIB(pMyArgument, pMyDisasm);
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        (*pMyArgument).Memory.Displacement = *((Int8*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGVAL(GV.RM_|(*pMyDisasm).Prefix.REX.B_);
        if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
            (*pMyArgument).SegmentReg = (*pMyDisasm).Prefix.Segment;
        }
        else if (GV.RM_ == 5 && (*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyArgument).SegmentReg = SSReg;
        }
        else {
            (*pMyArgument).SegmentReg = DSReg;
        }
    }
}

/* =======================================
 *     Mod/RM 2
 * ======================================= */
static void _ModRM2(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    GV.DECALAGE_EIP += 4;
    if (GV.RM_ == 4) {
        if (!Security(6, pMyDisasm)) return;
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+3));
        _SIB(pMyArgument, pMyDisasm);
    }
    else {
        if (!Security(5, pMyDisasm)) return;
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGVAL(GV.RM_|(*pMyDisasm).Prefix.REX.B_);
        if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
            (*pMyArgument).SegmentReg = (*pMyDisasm).Prefix.Segment;
        }
        else if (GV.RM_ == 5 && (*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyArgument).SegmentReg = SSReg;
        }
        else {
            (*pMyArgument).SegmentReg = DSReg;
        }
    }
}

/* =======================================
 *     Mod/RM 3
 * ======================================= */
static void _ModRM3(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[GV.RM_];
        (*pMyArgument).ArgSize = 64;
        return;
    }
    
    if (GV.SSE_) {
        (*pMyArgument).ArgType = REGISTER_TYPE|SSE_REG|REGVAL(GV.RM_|(*pMyDisasm).Prefix.REX.B_);
        (*pMyArgument).ArgSize = 128;
        return;
    }
    
    /* general purpose register */
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[GV.RM_];
        /* determine HighPos from 3rd bit (Hxx)*/
        (*pMyArgument).ArgPosition = GV.RM_ >> 2;
    }
    else {
        (*pMyArgument).ArgType = REGISTER_TYPE|GENERAL_REG|REGVAL(GV.RM_|(*pMyDisasm).Prefix.REX.B_);
    }
}
/* =======================================
 *     Mod/RM 3 MMX
 * ======================================= */
static void _ModRM3_MMX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGVAL(GV.RM_);
}

/* =======================================
 *     Mod/RM 3 SSE
 * ======================================= */
static void _ModRM3_SSE(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = REGISTER_TYPE|SSE_REG|REGVAL(GV.RM_|(*pMyDisasm).Prefix.REX.B_);
}

/* =======================================
 *     Mod/RM 0  AddressSize=16
 * ======================================= */
static void _ModRM0_16(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    switch (GV.RM_) {
        case 0:
            (*pMyArgument).Memory.BaseRegister = REGS[3];
            (*pMyArgument).Memory.IndexRegister = REGS[6];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 1:
            (*pMyArgument).Memory.BaseRegister = REGS[3];
            (*pMyArgument).Memory.IndexRegister = REGS[7];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 2:
            (*pMyArgument).Memory.BaseRegister = REGS[5];
            (*pMyArgument).Memory.IndexRegister = REGS[6];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentSS(pMyArgument, pMyDisasm);
            break;
        case 3:
            (*pMyArgument).Memory.BaseRegister = REGS[5];
            (*pMyArgument).Memory.IndexRegister = REGS[7];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentSS(pMyArgument, pMyDisasm);
            break;
        case 4:
            (*pMyArgument).Memory.BaseRegister = REGS[6];
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 5:
            (*pMyArgument).Memory.BaseRegister = REGS[7];
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 6:
            GV.DECALAGE_EIP+=2;
            if (!Security(2, pMyDisasm)) return;
            (*pMyArgument).Memory.Displacement = *((UInt16*)(UIntPtr) (GV.EIP_+2));
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 7:
            (*pMyArgument).Memory.BaseRegister = REGS[3];
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
    }
}
/* =======================================
 *     Mod/RM 1/2  AddressSize=16
 * ======================================= */
static void _ModRM12_16(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    switch (GV.RM_) {
        case 0:
            (*pMyArgument).Memory.BaseRegister = REGS[3];
            (*pMyArgument).Memory.IndexRegister = REGS[6];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 1:
            (*pMyArgument).Memory.BaseRegister = REGS[3];
            (*pMyArgument).Memory.IndexRegister = REGS[7];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 2:
            (*pMyArgument).Memory.BaseRegister = REGS[5];
            (*pMyArgument).Memory.IndexRegister = REGS[6];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentSS(pMyArgument, pMyDisasm);
            break;
        case 3:
            (*pMyArgument).Memory.BaseRegister = REGS[5];
            (*pMyArgument).Memory.IndexRegister = REGS[7];
            (*pMyArgument).Memory.Scale = 1;
            _FillSegmentSS(pMyArgument, pMyDisasm);
            break;
        case 4:
            (*pMyArgument).Memory.BaseRegister = REGS[6];
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 5:
            (*pMyArgument).Memory.BaseRegister = REGS[7];
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
        case 6:
            (*pMyArgument).Memory.BaseRegister = REGS[5];
            _FillSegmentSS(pMyArgument, pMyDisasm);
            break;
        case 7:
            (*pMyArgument).Memory.BaseRegister = REGS[3];
            _FillSegmentDS(pMyArgument, pMyDisasm);
            break;
    }
}

void __bea_callspec__ MOD_RM(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) return;
    GV.MOD_ = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6);
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
        if (GV.MOD_ == 3) {
            _ModRM3(pMyArgument, pMyDisasm);
        }
        else {
            (*pMyArgument).ArgType = MEMORY_TYPE;
            if (GV.MOD_ == 0) {
                _ModRM0(pMyArgument, pMyDisasm);
            }
            else if (GV.MOD_ == 1) {
                _ModRM1(pMyArgument, pMyDisasm);
            }
            else {
                _ModRM2(pMyArgument, pMyDisasm);
            }
        }
    }
    else {
        GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
        if (GV.MOD_ == 0) {
            (*pMyArgument).ArgType = MEMORY_TYPE;
            _ModRM0_16(pMyArgument, pMyDisasm);
        }
        else if (GV.MOD_ == 3) {
            _ModRM3(pMyArgument, pMyDisasm);
        }
        else {
            (*pMyArgument).ArgType = MEMORY_TYPE;
            if (GV.MOD_ == 1) {
                GV.DECALAGE_EIP++;
                (*pMyArgument).Memory.Displacement = *((Int8*)(UIntPtr) (GV.EIP_+2));
            }
            else {
                GV.DECALAGE_EIP += 2;
                (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
            }
            _ModRM12_16(pMyArgument, pMyDisasm);
        }
    }
}

void __bea_callspec__ MOD_RM_MMX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    GV.DECALAGE_EIP = 0;
    (*pMyArgument).ArgSize = 64;
    if (!Security(1, pMyDisasm)) return;
    GV.MOD_ = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6);
    GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
    if (GV.MOD_ == 3) {
        _ModRM3_MMX(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).ArgType = MEMORY_TYPE|MMX_MEM;
        if (GV.MOD_ == 0) {
            _ModRM0(pMyArgument, pMyDisasm);
        }
        else if (GV.MOD_ == 1) {
            _ModRM1(pMyArgument, pMyDisasm);
        }
        else {
            _ModRM2(pMyArgument, pMyDisasm);
        }
    }
}

void __bea_callspec__ MOD_RM_SSE(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    GV.DECALAGE_EIP = 0;
    (*pMyArgument).ArgSize = 128;
    if (!Security(1, pMyDisasm)) return;
    GV.MOD_ = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6);
    GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
    if (GV.MOD_ == 3) {
        _ModRM3_SSE(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).ArgType = MEMORY_TYPE|SSE_MEM;
        if (GV.MOD_ == 0) {
            _ModRM0(pMyArgument, pMyDisasm);
        }
        else if (GV.MOD_ == 1) {
            _ModRM1(pMyArgument, pMyDisasm);
        }
        else {
            _ModRM2(pMyArgument, pMyDisasm);
        }
    }
}

void __bea_callspec__ RegSeg_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (reg < 6) {
        (*pMyArgument).ArgType = REGISTER_TYPE|SEGMENT_REG|REGVAL(reg);
        (*pMyArgument).ArgSize = 16;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

void __bea_callspec__ RegCR_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    (*pMyArgument).ArgType = REGISTER_TYPE+CR_REG+REGVAL(reg|(*pMyDisasm).Prefix.REX.R_);
    (*pMyArgument).ArgSize = 32;
}

void __bea_callspec__ RegDR_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    (*pMyArgument).ArgType = REGISTER_TYPE+DR_REG+REGVAL(reg|(*pMyDisasm).Prefix.REX.R_);
    (*pMyArgument).ArgSize = 32;
}

void __bea_callspec__ RegMMX_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    (*pMyArgument).ArgType = REGISTER_TYPE|MMX_REG|REGVAL(reg);
    (*pMyArgument).ArgSize = 64;
}

void __bea_callspec__ RegSSE_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    (*pMyArgument).ArgType = REGISTER_TYPE|SSE_REG|REGVAL(reg|(*pMyDisasm).Prefix.REX.R_);
    (*pMyArgument).ArgSize = 128;
}
/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Reg_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[reg];
        (*pMyArgument).ArgSize = 64;
        return;
    }
    
    if (GV.SSE_) {
        (*pMyArgument).ArgType = REGISTER_TYPE|SSE_REG|REGVAL(reg|(*pMyDisasm).Prefix.REX.R_);
        (*pMyArgument).ArgSize = 128;
        return;
    }
    
    /* general purpose register */
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[reg];
        /* determine HighPos from 3rd bit (Hxx)*/
        (*pMyArgument).ArgPosition = reg >> 2;
    }
    else {
        (*pMyArgument).ArgType = REGISTER_TYPE|GENERAL_REG|REGVAL(reg|(*pMyDisasm).Prefix.REX.R_);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ _SIB(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 base, scale, index;
    
    GV.DECALAGE_EIP++;
    
    base  = (*((UInt8*) (UIntPtr) (GV.EIP_+2))) & 0x7;
    index = ((*((UInt8*)(UIntPtr) (GV.EIP_+2))) >> 3) & 0x7;
    scale = 1 << ((*((UInt8*) (UIntPtr) (GV.EIP_+2))) >> 6);
    /* ========================= Interpret Base */
    if ((base == 5) && (GV.MOD_ == 0)) {
        GV.DECALAGE_EIP += 4;
        if (!Security(7, pMyDisasm)) return;
        (*pMyArgument).Memory.Displacement = *((UInt32*)(UIntPtr) (GV.EIP_+3));
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        if ((*pMyDisasm).Prefix.REX.B_ == 0) {
            (*pMyArgument).Memory.BaseRegister = REGS[base];
            if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
                (*pMyArgument).SegmentReg = (*pMyDisasm).Prefix.Segment;
            }
            else if (base == 4 || base == 5) {
                (*pMyArgument).SegmentReg = SSReg;
            }
            else {
                (*pMyArgument).SegmentReg = DSReg;
            }
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[base|8];
            _FillSegmentDS(pMyArgument, pMyDisasm);
        }
    }

    /* ======================== Interpret Index */
    if (index != 4 || (*pMyDisasm).Prefix.REX.X_) {
        (*pMyArgument).Memory.IndexRegister = REGS[index|(*pMyDisasm).Prefix.REX.X_];
        (*pMyArgument).Memory.Scale = scale;
    }
}
