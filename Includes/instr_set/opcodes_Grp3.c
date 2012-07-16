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
        (*pMyDisasm).Instruction.MnemonicId = I_TEST;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        #endif
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (*pMyDisasm).Instruction.MnemonicId = I_TEST;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        #endif
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 2) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_NOT;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "not");
        #endif
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NOT);
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_NEG;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "neg");
        #endif
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NEG);
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MUL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mul");
        #endif
        GV.MemDecoration = Arg1byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_MUL);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_IMUL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul");
        #endif
        GV.MemDecoration = Arg1byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DIV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "div");
        #endif
        GV.MemDecoration = Arg1byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_DIV);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_IDIV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "idiv");
        #endif
        GV.MemDecoration = Arg1byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
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
        (*pMyDisasm).Instruction.MnemonicId = I_TEST;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        #endif
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (*pMyDisasm).Instruction.MnemonicId = I_TEST;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test");
        #endif
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 2) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_NOT;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "not");
        #endif
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NOT);
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_NEG;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "neg");
        #endif
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NEG);
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MUL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mul");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            (*pMyDisasm).Argument2.ArgSize = 64;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            (*pMyDisasm).Argument2.ArgSize = 32;
        }
        else {
            GV.MemDecoration = Arg1word;
            (*pMyDisasm).Argument2.ArgSize = 16;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_MUL);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_IMUL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            (*pMyDisasm).Argument2.ArgSize = 64;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            (*pMyDisasm).Argument2.ArgSize = 32;
        }
        else {
            GV.MemDecoration = Arg1word;
            (*pMyDisasm).Argument2.ArgSize = 16;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DIV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "div");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            (*pMyDisasm).Argument2.ArgSize = 64;
            (*pMyDisasm).Argument3.ArgSize = 64;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            (*pMyDisasm).Argument2.ArgSize = 32;
            (*pMyDisasm).Argument3.ArgSize = 32;
        }
        else {
            GV.MemDecoration = Arg1word;
            (*pMyDisasm).Argument2.ArgSize = 16;
            (*pMyDisasm).Argument3.ArgSize = 16;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument3.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;		
        FillFlags(pMyDisasm, EFLAGS_DIV);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_IDIV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "idiv");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            (*pMyDisasm).Argument2.ArgSize = 64;
            (*pMyDisasm).Argument3.ArgSize = 64;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            (*pMyDisasm).Argument2.ArgSize = 32;
            (*pMyDisasm).Argument3.ArgSize = 32;
        }
        else {
            GV.MemDecoration = Arg1word;
            (*pMyDisasm).Argument2.ArgSize = 16;
            (*pMyDisasm).Argument3.ArgSize = 16;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument3.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;		
        FillFlags(pMyDisasm, EFLAGS_IDIV);
    }
}
