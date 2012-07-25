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
void __bea_callspec__ MOD_RM(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) return;
    GV.MOD_ = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6);
    GV.RM_  = (*((UInt8*)(UIntPtr) (GV.EIP_+1))) & 0x7;
    if (GV.MOD_ == 0) {
        ModRM_0[GV.RM_](pMyArgument, pMyDisasm);
    }
    else if (GV.MOD_ == 1) {
        GV.DECALAGE_EIP++;
        ModRM_1[GV.RM_](pMyArgument, pMyDisasm);
    }
    else if (GV.MOD_ == 2) {
        if ((*pMyDisasm).Instruction.AddressSize >= 32) {
            GV.DECALAGE_EIP += 4;
        }
        else {
            GV.DECALAGE_EIP += 2;
        }
        ModRM_2[GV.RM_](pMyArgument, pMyDisasm);
    }
    else {
        ModRM_3[GV.RM_](pMyArgument, pMyDisasm);
    }

}
void __bea_callspec__ RegSeg_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (reg < 6) {
        (*pMyArgument).ArgType = REGISTER_TYPE+SEGMENT_REG+REGS[reg];
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
    if ((*pMyDisasm).Prefix.REX.R_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+CR_REG+REGS[reg|8];
    }
    else {
        (*pMyArgument).ArgType = REGISTER_TYPE+CR_REG+REGS[reg];
    }
    (*pMyArgument).ArgSize = 32;
}

void __bea_callspec__ RegDR_Opcode(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 reg;
    if (!Security(1, pMyDisasm)) return;
    reg = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if ((*pMyDisasm).Prefix.REX.R_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+DR_REG+REGS[reg|8];
    }
    else {
        (*pMyArgument).ArgType = REGISTER_TYPE+DR_REG+REGS[reg];
    }
    (*pMyArgument).ArgSize = 32;
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
        if ((*pMyDisasm).Prefix.REX.R_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[reg|8];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[reg];
        }
        (*pMyArgument).ArgSize = 128;
        return;
    }
    
    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.R_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[reg|8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[reg];
            /* determine HighPos from 3rd bit (Hxx)*/
            (*pMyArgument).ArgPosition = reg >> 2;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[reg];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}

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
 *          ModRM_0
 * ======================================= */
void __bea_callspec__ Addr_EAX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[0];
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[3];
        (*pMyArgument).Memory.IndexRegister = REGS[6];
        (*pMyArgument).Memory.Scale = 1;
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}
/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_ECX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[1+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[1];
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[3];
        (*pMyArgument).Memory.IndexRegister = REGS[7];
        (*pMyArgument).Memory.Scale = 1;
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_EDX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[2+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[2];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        (*pMyArgument).Memory.IndexRegister = REGS[6];
        (*pMyArgument).Memory.Scale = 1;
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_EBX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[3+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[3];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        (*pMyArgument).Memory.IndexRegister = REGS[7];
        (*pMyArgument).Memory.Scale = 1;
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_SIB(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (!Security(2, pMyDisasm)) return;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        _SIB(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[6];
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    Int32 MyNumber;
    UInt64 MyAddress;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if (!Security(6, pMyDisasm)) return;
        GV.DECALAGE_EIP+=4;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.Displacement = MyNumber;
        if ((*pMyDisasm).Archi == 64) {
            MyNumber += 6;
            MyNumber += (*pMyDisasm).Prefix.Number;
            if (GV.ImmediatSize == 32) {
                MyNumber += 4;
            }
            else if (GV.ImmediatSize == 16) {
                MyNumber += 2;
            }
            else if (GV.ImmediatSize == 8) {
                MyNumber += 1;
            }
            if ((*pMyDisasm).Instruction.Opcode >= 0x0F3800) {      /* add two bytes if opcode is a 3-bytes */
                MyNumber +=2;
            }
            else if ((*pMyDisasm).Instruction.Opcode >= 0x0100) {   /* add one byte if opcode is a 2-bytes */
                MyNumber +=1;
            }
            CalculateRelativeAddress(&MyAddress, (Int64)MyNumber, pMyDisasm);
            (*pMyDisasm).Instruction.AddrValue = MyAddress;
            (*pMyArgument).ArgType = MEMORY_TYPE+RELATIVE_;
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[7];
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_ESI(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[6+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[6];
        }
    }
    else {
        GV.DECALAGE_EIP+=2;
        (*pMyArgument).Memory.Displacement = *((UInt16*)(UIntPtr) (GV.EIP_+2));
        if (!Security(2, pMyDisasm)) return;
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_EDI(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[7+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[7];
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[3];
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *          ModRM_1
 * ======================================= */
void __bea_callspec__ Addr_EAX_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    long MyNumber;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+2));
    (*pMyArgument).Memory.Displacement = MyNumber;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[0];
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[3];
        (*pMyArgument).Memory.IndexRegister = REGS[6];
        (*pMyArgument).Memory.Scale = 1;
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *          ModRM_1
 * ======================================= */
void __bea_callspec__ Addr_ECX_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    long MyNumber;
    MyNumber = *((Int8*) (UIntPtr)GV.EIP_+2);
    (*pMyArgument).Memory.Displacement = MyNumber;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[1+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[1];
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[3];
        (*pMyArgument).Memory.IndexRegister = REGS[7];
        (*pMyArgument).Memory.Scale = 1;
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *          ModRM_1
 * ======================================= */
void __bea_callspec__ Addr_EDX_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    long MyNumber;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+2));
    (*pMyArgument).Memory.Displacement = MyNumber;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[2+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[2];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        (*pMyArgument).Memory.IndexRegister = REGS[6];
        (*pMyArgument).Memory.Scale = 1;
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *          ModRM_1
 * ======================================= */
void __bea_callspec__ Addr_EBX_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    long MyNumber;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+2));
    (*pMyArgument).Memory.Displacement = MyNumber;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[3+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[3];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        (*pMyArgument).Memory.IndexRegister = REGS[7];
        (*pMyArgument).Memory.Scale = 1;
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_SIB_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if (!Security(3, pMyDisasm)) return;
        (*pMyArgument).Memory.Displacement = *((Int8*)(UIntPtr) (GV.EIP_+3));
        _SIB(pMyArgument, pMyDisasm);
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        (*pMyArgument).Memory.Displacement = *((Int8*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[7];
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *          ModRM_1
 * ======================================= */
void __bea_callspec__ Addr_EBP_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    long MyNumber;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+2));
    (*pMyArgument).Memory.Displacement = MyNumber;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[5+8];
            _FillSegmentDS(pMyArgument, pMyDisasm);
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[5];
            _FillSegmentSS(pMyArgument, pMyDisasm);
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[7];
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *          ModRM_1
 * ======================================= */
void __bea_callspec__ Addr_ESI_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    long MyNumber;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+2));
    (*pMyArgument).Memory.Displacement = MyNumber;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[6+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[6];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }

}

/* =======================================
 *          ModRM_1
 * ======================================= */
void __bea_callspec__ Addr_EDI_disp8(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    long MyNumber;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+2));
    (*pMyArgument).Memory.Displacement = MyNumber;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[7+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[7];
        }
    }
    else {
        (*pMyArgument).Memory.BaseRegister = REGS[3];
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *          ModRM_2
 * ======================================= */
void __bea_callspec__ Addr_EAX_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[0];
        }
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[3];
        (*pMyArgument).Memory.IndexRegister = REGS[6];
        (*pMyArgument).Memory.Scale = 1;
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}


/* =======================================
 *          ModRM_2
 * ======================================= */
void __bea_callspec__ Addr_ECX_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[1+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[1];
        }
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[3];
        (*pMyArgument).Memory.IndexRegister = REGS[7];
        (*pMyArgument).Memory.Scale = 1;
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *          ModRM_2
 * ======================================= */
void __bea_callspec__ Addr_EDX_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[2+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[2];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        (*pMyArgument).Memory.IndexRegister = REGS[6];
        (*pMyArgument).Memory.Scale = 1;
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *          ModRM_2
 * ======================================= */
void __bea_callspec__ Addr_EBX_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[3+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[3];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        (*pMyArgument).Memory.IndexRegister = REGS[7];
        (*pMyArgument).Memory.Scale = 1;
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ Addr_SIB_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (!Security(2, pMyDisasm)) return;
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+3));
        _SIB(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[6];
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *          ModRM_2
 * ======================================= */
void __bea_callspec__ Addr_EBP_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[5+8];
            _FillSegmentDS(pMyArgument, pMyDisasm);
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[5];
            _FillSegmentSS(pMyArgument, pMyDisasm);
        }
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[7];
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *          ModRM_2
 * ======================================= */
void __bea_callspec__ Addr_ESI_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[6+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[6];
        }
        _FillSegmentDS(pMyArgument, pMyDisasm);
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[5];
        _FillSegmentSS(pMyArgument, pMyDisasm);
    }
}

/* =======================================
 *          ModRM_2
 * ======================================= */
void __bea_callspec__ Addr_EDI_disp32(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    (*pMyArgument).ArgType = MEMORY_TYPE;
    if ((*pMyDisasm).Instruction.AddressSize >= 32) {
        (*pMyArgument).Memory.Displacement = *((Int32*)(UIntPtr) (GV.EIP_+2));
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).Memory.BaseRegister = REGS[7+8];
        }
        else {
            (*pMyArgument).Memory.BaseRegister = REGS[7];
        }
    }
    else {
        (*pMyArgument).Memory.Displacement = *((Int16*)(UIntPtr) (GV.EIP_+2));
        (*pMyArgument).Memory.BaseRegister = REGS[3];
    }
    _FillSegmentDS(pMyArgument, pMyDisasm);
}

/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rEAX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[0];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[0];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }

    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[0];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}


/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rECX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[1];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[1+8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[1];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }

    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[1];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}



/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rEDX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[2+0];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[2+8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[2+0];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }

    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[2+0];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}



/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rEBX(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[3+0];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[3+8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[3+0];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }
    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[3+0];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}



/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rESP(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[4+0];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[4+8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[4+0];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }

    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgPosition = HighPosition;
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[4+0];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}



/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rEBP(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[5+0];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[5+8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[5+0];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }

    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgPosition = HighPosition;
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[5+0];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}



/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rESI(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[6+0];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[6+8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[6+0];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }

    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgPosition = HighPosition;
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[6+0];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
}



/* =======================================
 *          ModRM_3
 * ======================================= */
void __bea_callspec__ _rEDI(ARGTYPE* pMyArgument, PDISASM pMyDisasm)
{
    if (GV.MMX_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+MMX_REG+REGS[7+0];
        (*pMyArgument).ArgSize = 64;
        return;
    }

    if (GV.SSE_) {
        if ((*pMyDisasm).Prefix.REX.B_) {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[7+8];
            (*pMyArgument).ArgSize = 128;
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+SSE_REG+REGS[7+0];
            (*pMyArgument).ArgSize = 128;
        }
        return;
    }

    /* general purpose register */
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 8 && (*pMyDisasm).Prefix.REXState == 0) {
            (*pMyArgument).ArgPosition = HighPosition;
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[7+0];
        }
        else {
            (*pMyArgument).ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    (*pMyArgument).ArgSize = (*pMyDisasm).Instruction.OperandSize;
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
        if ((*pMyDisasm).Prefix.REX.X_ == 0) {
            (*pMyArgument).Memory.IndexRegister = REGS[index];
        }
        else {
            (*pMyArgument).Memory.IndexRegister = REGS[index|8];
        }
        
        (*pMyArgument).Memory.Scale = scale;
    }
}
