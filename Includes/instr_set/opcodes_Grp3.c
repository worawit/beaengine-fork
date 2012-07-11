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
 *      0f6h
 * ==================================================================== */
void __bea_callspec__ G3_Eb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 2) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "not");
        Eb(pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_NOT);
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "neg");
        Eb(pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_NEG);
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mul");
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_MUL);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul");
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "div");
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm, EFLAGS_DIV);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "idiv");
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_IDIV);
    }
}

/* ====================================================================
 *      0f7h
 * ==================================================================== */
void __bea_callspec__ G3_Ev(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 2) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "not");
        Ev(pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_NOT);
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "neg");
        Ev(pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_NEG);
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mul");
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_MUL);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul");
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "div");
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;		
        FillFlags(pMyDisasm, EFLAGS_DIV);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "idiv");
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;		
        FillFlags(pMyDisasm, EFLAGS_IDIV);
    }
}
