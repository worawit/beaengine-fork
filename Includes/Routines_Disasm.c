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
int __bea_callspec__ Disasm (PDISASM pMyDisasm)
{
    InitVariables(pMyDisasm);
    AnalyzeOpcode(pMyDisasm);
    if (GV.ERROR_OPCODE) {
        return -1;
    }
    if (!GV.OutOfBlock) {
        //CompleteInstructionFields(pMyDisasm);
        return (int) (GV.EIP_-(*pMyDisasm).EIP);
    }
    else {
        return 0;
    }
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ CompleteInstructionFields (PDISASM pMyDisasm) {

}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ InitVariables (PDISASM pMyDisasm) {
    /* Note: no check Archi value. It must be 16,32,64 */

    (void) memset (&(*pMyDisasm).Instruction, 0, sizeof (INSTRTYPE));
	(void) memset (&(*pMyDisasm).Argument1, 0, sizeof (ARGTYPE));
	(void) memset (&(*pMyDisasm).Argument2, 0, sizeof (ARGTYPE));
	(void) memset (&(*pMyDisasm).Argument3, 0, sizeof (ARGTYPE));
    (void) memset (&(*pMyDisasm).Prefix, 0, sizeof (PREFIXINFO));
    (void) memset (&GV, 0, sizeof (InternalDatas));

    GV.EIP_ = (*pMyDisasm).EIP+1; /* +1 because it is at least 1 byte*/
    if ((*pMyDisasm).SecurityBlock == 0 || (*pMyDisasm).SecurityBlock > MAX_INSTR_LENGTH)
        GV.EndOfBlock = (*pMyDisasm).EIP+MAX_INSTR_LENGTH;
    else
        GV.EndOfBlock = (*pMyDisasm).EIP+(*pMyDisasm).SecurityBlock;

    (*pMyDisasm).Instruction.OperandSize = 32;
    GV.OriginalOperandSize = 32;
    (*pMyDisasm).Instruction.AddressSize = (*pMyDisasm).Archi;
    if ((*pMyDisasm).Archi == 16) {
        (*pMyDisasm).Instruction.OperandSize = 16;
        GV.OriginalOperandSize = 16;
    }

    (*pMyDisasm).Argument1.AccessMode = WRITE;
    (*pMyDisasm).Argument2.AccessMode = READ;
    (*pMyDisasm).Argument3.AccessMode = READ;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ AnalyzeOpcode (PDISASM pMyDisasm) {
    UInt32 opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
    /* no need to check security here because length always at least 1 */
    (*pMyDisasm).Instruction.Opcode = opcode;
    (void) opcode_map1[opcode](pMyDisasm);
}

/* ====================================================================
 *  set OperandSize prefix as mandatory prefix
 * ==================================================================== */
void __bea_callspec__ PrefOpSizeMandatory(PDISASM pMyDisasm) {
    (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
    (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
}

/* ====================================================================
 *
 * ==================================================================== */
int __bea_callspec__ Security(int len, PDISASM pMyDisasm)
{
    if ((GV.EIP_+(UInt64)len) > GV.EndOfBlock) {
        GV.OutOfBlock = 1;
        return 0;
    }
    return 1;
}

int __bea_callspec__ Security1(PDISASM pMyDisasm)
{
    if (GV.EIP_ >= GV.EndOfBlock) {
        GV.OutOfBlock = 1;
        return 0;
    }
    return 1;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ FillFlags(PDISASM pMyDisasm, int index)
{
    (*pMyDisasm).Instruction.Flags = EFLAGS_TABLE[index];
}
/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ CalculateRelativeAddress(UInt64 * pMyAddress, Int64 MyNumber, PDISASM pMyDisasm)
{
    *pMyAddress = (UInt64) ((*pMyDisasm).VirtualAddr+(UInt64) MyNumber);
}

/* ====================================================================
 *
 * ==================================================================== */
static Int32 RegValue2Index(Int32 value)
{
    switch (value) {
        case REG0: return 0;
        case REG1: return 1;
        case REG2: return 2;
        case REG3: return 3;
        case REG4: return 4;
        case REG5: return 5;
        case REG6: return 6;
        case REG7: return 7;
        case REG8: return 8;
        case REG9: return 9;
        case REG10: return 10;
        case REG11: return 11;
        case REG12: return 12;
        case REG13: return 13;
        case REG14: return 14;
        case REG15: return 15;
    }
    /* never reach */
    return 0;
}

static size_t BuildMemoryRegister(Int32 idx, Int32 size, char *buffer)
{
    if (size == 32) {
        (void) strcpy(buffer, Registers32Bits[idx]);
        return strlen(Registers32Bits[idx]);
    }
    else if (size == 64) {
        (void) strcpy(buffer, Registers64Bits[idx]);
        return strlen(Registers64Bits[idx]);
    }
    /* size == 16, AddressSize never be 8-bit */
    (void) strcpy(buffer, Registers16Bits[idx]);
    return strlen(Registers16Bits[idx]);
}

static size_t BuildMemorySegment(Int32 idx, char *buffer)
{
    (void) strcpy(buffer, SegmentRegs[idx]);
    return 3;
}

static size_t BuildMemoryDecoration(ARGTYPE* arg, char *buffer)
{
    /* MASM mem decoration */
    switch ((*arg).ArgSize) {
        case 8:
            (void) strcpy(buffer, "byte ptr ");
            return 9;
        case 16:
            (void) strcpy(buffer, "word ptr ");
            return 9;
        case 32:
            (void) strcpy(buffer, "dword ptr ");
            return 10;
        case 64:
            if ((*arg).ArgType & MM_MEM) {
                (void) strcpy(buffer, "mmword ptr ");
                return 11;
            }
            else {
                (void) strcpy(buffer, "qword ptr ");
                return 10;
            }
        case 80:
            (void) strcpy(buffer, "tbyte ptr ");
            return 10;
        case 48:
            (void) strcpy(buffer, "fword ptr ");
            return 10;
        case 128:
            if ((*arg).ArgType & MM_MEM) {
                (void) strcpy(buffer, "xmmword ptr ");
                return 12;
            }
            else {
                (void) strcpy(buffer, "dqword ptr ");
                return 11;
            }
    }
    *buffer = ' ';
    return 1;
}

static size_t BuildArgRegGeneral(Int32 idx, Int32 size, Int32 pos, char *buffer)
{
    if (size == 32) {
        (void) strcpy(buffer, Registers32Bits[idx]);
        return strlen(Registers32Bits[idx]);
    }
    else if (size == 64) {
        (void) strcpy(buffer, Registers64Bits[idx]);
        return strlen(Registers64Bits[idx]);
    }
    else if (size == 16) {
        (void) strcpy(buffer, Registers16Bits[idx]);
        return strlen(Registers16Bits[idx]);
    }
    /* size == 8 */
    if (pos) {
        (void) strcpy(buffer, Registers8BitsHigh[idx]);
        return strlen(Registers8BitsHigh[idx]);
    }
    (void) strcpy(buffer, Registers8Bits[idx]);
    return strlen(Registers8Bits[idx]);
}

/* real build hex string */
static const char hexmap[24] = "0123456789abcdef";
static size_t BuildHexString2(Int64 num, Int32 bitShift, char *buffer)
{
    size_t i = 0;
    while (bitShift > 0) {
        buffer[i] = hexmap[(num >> bitShift) & 0xf];
        bitShift -= 4;
        i++;
    }
    buffer[i] = hexmap[num & 0xf];
    return i+1;
}

/* find the first non-zero hex */
static size_t BuildHexString(Int64 num, Int32 bitShift, char *buffer) {
    while (((num >> bitShift) & 0xf) == 0) {
        bitShift -= 4;
        if (bitShift == 0)
            break;
    }
    return BuildHexString2(num, bitShift, buffer);
}

static size_t BuildHexNumber(Int64 num, int size, Int32 prefixedHex, char *buffer)
{
    size_t i;
    if (prefixedHex) {
        buffer[0] = '0';
        buffer[1] = 'x';
        i = BuildHexString(num, size-4, buffer+2);
        return i+2;
    }
    else {
        i = BuildHexString(num, size-4, buffer);
        buffer[i] = 'h';
        return i+1;
    }
    /* never reach */
    return 0;
}

static size_t BuildMemoryMnemonic(PDISASM pMyDisasm, ARGTYPE* arg, char *buffer)
{
    int has_base = 0;
    int has_index = 0;
    size_t i;
    
    if ((*pMyDisasm).Instruction.Mnemonic != I_LEA) {
        i = BuildMemoryDecoration(arg, buffer);
    }
    else {
        i = 0;
    }
    
    /* segment prefix */
    if (((*pMyDisasm).Prefix.SegmentState == InUsePrefix) || (*pMyDisasm).AsmShowImplicitSegmentRegs) {
        i += BuildMemorySegment((*arg).SegmentReg, buffer+i);
    }
    
    buffer[i++] = '[';
    
    /* base register */
    if ((*arg).Memory.BaseRegister) {
        i += BuildMemoryRegister(RegValue2Index((*arg).Memory.BaseRegister), (*pMyDisasm).Instruction.AddressSize, buffer+i);
        has_base = 1;
    }
    else if ((*arg).ArgType & RELATIVE_) {
        /* RIP relative, should display relative result? */
        (void) strcpy(buffer+i, "rip");
        i += 3;
        has_base = 1;
    }
    
    /* index*scale */
    if ((*arg).Memory.IndexRegister) {
        if (has_base) {
            buffer[i++] = '+';
        }
        i += BuildMemoryRegister(RegValue2Index((*arg).Memory.IndexRegister), (*pMyDisasm).Instruction.AddressSize, buffer+i);
        if ((*arg).Memory.Scale > 1) {
            buffer[i] = '*';
            buffer[i+1] = '0' + (*arg).Memory.Scale;
            i += 2;
        }
        has_index = 1;
    }
    
    /* displacement */
    if ((*arg).Memory.Displacement) {
        if ((*arg).Memory.Displacement < 0 && has_base) {
            /* display displacement as signed only if there is base register */
            buffer[i++] = '-';
            i += BuildHexNumber(-((*arg).Memory.Displacement), 32, (*pMyDisasm).AsmPrefixedNumeral, buffer+i);
        }
        else {
            if (has_base || has_index) {
                buffer[i++] = '+';
            }
            i += BuildHexNumber((*arg).Memory.Displacement, 32, (*pMyDisasm).AsmPrefixedNumeral, buffer+i);
        }
    }
    
    buffer[i] = ']';
    
    return i+1;
}

static size_t BuildRegMnemonic(PDISASM pMyDisasm, ARGTYPE* arg, char *buffer)
{
    Int32 index = RegValue2Index((*arg).ArgType & 0xffff);
    switch ((*arg).ArgType & 0x0fff0000) {
        case GENERAL_REG:
            return BuildArgRegGeneral(index, (*arg).ArgSize, (*arg).ArgPosition, buffer);
        case FPU_REG:
            (void) strcpy(buffer, RegistersFPU_Masm[index]);
            return strlen(RegistersFPU_Masm[index]);
        case MMX_REG:
            (void) strcpy(buffer, RegistersMMX[index]);
            return strlen(RegistersMMX[index]);
        case SSE_REG:
            (void) strcpy(buffer, RegistersSSE[index]);
            return strlen(RegistersSSE[index]);
        case SEGMENT_REG:
            (void) strcpy(buffer, RegistersSEG[index]);
            return strlen(RegistersSEG[index]);
        case CR_REG:
            (void) strcpy(buffer, RegistersCR[index]);
            return strlen(RegistersCR[index]);
        case DR_REG:
            (void) strcpy(buffer, RegistersDR[index]);
            return strlen(RegistersDR[index]);
    }
    return 0;
}

static size_t BuildArgumentMnemonic(PDISASM pMyDisasm, ARGTYPE* arg, char *buffer)
{
    if ((*arg).ArgType & MEMORY_TYPE) {
        return BuildMemoryMnemonic(pMyDisasm, arg, buffer);
    }
    else if ((*arg).ArgType & REGISTER_TYPE) {
        return BuildRegMnemonic(pMyDisasm, arg, buffer);
    }
    else if ((*arg).ArgType & CONSTANT_TYPE) {
        if ((*arg).ArgType & RELATIVE_) {
            return BuildHexString((Int64) (*pMyDisasm).Instruction.AddrValue, (*pMyDisasm).Instruction.AddressSize-4, buffer);
        }
        else if ((*arg).ArgType & ABSOLUTE_) {
            return BuildHexNumber((*pMyDisasm).Instruction.Immediat, (*pMyDisasm).Instruction.OperandSize, (*pMyDisasm).AsmPrefixedNumeral, buffer);
        }
        else if ((*arg).ArgType & FARPTR_) {
            size_t i = BuildHexString2((*arg).SegmentReg, 12, buffer);
            buffer[i] = ':';
            i++;
            i += BuildHexString2((*pMyDisasm).Instruction.Immediat, (*arg).ArgSize-20, buffer+i);
            return i;
        }
        else if ((*arg).ArgType & IMM_IN_TYPE) {
            return BuildHexNumber((*arg).ArgType & 0xff, (*arg).ArgSize, (*pMyDisasm).AsmPrefixedNumeral, buffer);
        }
    }
    return 0;
}

void __bea_callspec__ BuildAssembly(PDISASM pMyDisasm, char *buffer)
{
    size_t i = 0;
    Int32 has_arg = 0;
    
    /* =============== Instruction Prefix */
    if ((*pMyDisasm).Prefix.RepeatState == InUsePrefix) {
        if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
            (void) strcpy(buffer, "repe ");
            i = 5;
        }
        else if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
            (void) strcpy(buffer, "repne ");
            i = 6;
        }
        else if ((*pMyDisasm).Prefix.Repeat == PrefixRep) {
            (void) strcpy(buffer, "rep ");
            i = 4;
        }
    }
    else if ((*pMyDisasm).Prefix.LockState == InUsePrefix) {
        (void) strcpy(buffer, "lock ");
        i = 5;
    }
    
    /* Mnemonic */
    (void) strcpy (buffer+i, MNEMONICS[(*pMyDisasm).Instruction.Mnemonic]);
    i += strlen(MNEMONICS[(*pMyDisasm).Instruction.Mnemonic]);

    /* =============== if TAB = 1, add tabulation */
    if ((*pMyDisasm).AsmTabulation && (i < 10)) {
        (void) strcpy (buffer+i, space_tab[10-i]);
        i = 10;
    }
    else {
        buffer[i] = ' ';
        i++;
    }
    
    /* =============== Arg1 */
    if ((*pMyDisasm).Argument1.ArgType && ((*pMyDisasm).Argument1.ArgType & IMPLICIT_ARG) == 0) {
        i += BuildArgumentMnemonic(pMyDisasm, &((*pMyDisasm).Argument1), buffer+i);
        has_arg = 1;
    }
    /* =============== Arg2 */
    if ((*pMyDisasm).Argument2.ArgType && ((*pMyDisasm).Argument2.ArgType & IMPLICIT_ARG) == 0) {
        if (has_arg) {
            buffer[i] = ',';
            buffer[i+1] = ' ';
            i += 2;
        }
        i += BuildArgumentMnemonic(pMyDisasm, &((*pMyDisasm).Argument2), buffer+i);
        has_arg = 1;
    }
    /* =============== Arg3 */
    if ((*pMyDisasm).Argument3.ArgType && ((*pMyDisasm).Argument3.ArgType & IMPLICIT_ARG) == 0) {
        if (has_arg) {
            buffer[i] = ',';
            buffer[i+1] = ' ';
            i += 2;
        }
        i += BuildArgumentMnemonic(pMyDisasm, &((*pMyDisasm).Argument3), buffer+i);
    }
    buffer[i] = '\0';
}
