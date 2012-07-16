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

void __bea_callspec__ FailDecode(PDISASM pMyDisasm)
{
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "???");
    #endif
    GV.ERROR_OPCODE = 1;
}
/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aaa_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_AAA;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aaa");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
    };
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aad_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_AAD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aad");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        if (!Security(1, pMyDisasm)) return;
        GV.ImmediatSize = 8;
        if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
            #endif
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=2;
    };
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aam_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_AAM;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aam");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        if (!Security(1, pMyDisasm)) return;
        GV.ImmediatSize = 8;
        if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
            #endif
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=2;
    };
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ aas_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_AAS;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aas");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
    };
}

/* =======================================
 *      00h
 * ======================================= */
void __bea_callspec__ add_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add");
    #endif
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      01h
 * ======================================= */
void __bea_callspec__ add_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      02h
 * ======================================= */
void __bea_callspec__ add_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add");
    #endif
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      03h
 * ======================================= */
void __bea_callspec__ add_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add");
    #endif
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      04h
 * ======================================= */
void __bea_callspec__ add_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add");
    #endif
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      05h
 * ======================================= */
void __bea_callspec__ add_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add");
    #endif
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      10h
 * ======================================= */
void __bea_callspec__ adc_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc");
    #endif
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      11h
 * ======================================= */
void __bea_callspec__ adc_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      12h
 * ======================================= */
void __bea_callspec__ adc_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc");
    #endif
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      13h
 * ======================================= */
void __bea_callspec__ adc_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc");
    #endif
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      14h
 * ======================================= */
void __bea_callspec__ adc_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc");
    #endif
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      15h
 * ======================================= */
void __bea_callspec__ adc_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_ADC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc");
    #endif
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      20h
 * ======================================= */
void __bea_callspec__ and_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_AND;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and");
    #endif
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      21h
 * ======================================= */
void __bea_callspec__ and_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_AND;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      22h
 * ======================================= */
void __bea_callspec__ and_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_AND;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and");
    #endif
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      23h
 * ======================================= */
void __bea_callspec__ and_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_AND;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and");
    #endif
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      24h
 * ======================================= */
void __bea_callspec__ and_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_AND;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and");
    #endif
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      25h
 * ======================================= */
void __bea_callspec__ and_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_AND;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and");
    #endif
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ arpl_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSXD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsxd");
        #endif
        GvEv(pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_MOVSX);
    }
    else {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ARPL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "arpl");
        #endif
        GV.OperandSize = 16;
        EvGv(pMyDisasm);
        GV.OperandSize = 32;
        FillFlags(pMyDisasm, EFLAGS_ARPL);
    }

}

/* =======================================
 *      62h
 * ======================================= */
void __bea_callspec__ bound_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_BOUND;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bound");
        #endif
        GvEv(pMyDisasm);
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_BOUND);
    }

}

/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_eax(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ecx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esp(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebp(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esi(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edi(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_BSWAP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}

/* =======================================
 *      0fbch
 * ======================================= */
void __bea_callspec__ bsf_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.MnemonicId = I_BSF;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsf");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_BSCAN);
}

/* =======================================
 *      0fbdh
 * ======================================= */
void __bea_callspec__ bsr_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.MnemonicId = I_BSR;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsr");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_BSCAN);
}

/* =======================================
 *      0fbbh
 * ======================================= */
void __bea_callspec__ btc_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;

    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.MnemonicId = I_BTC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btc");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);
}

/* =======================================
 *      0fa3h
 * ======================================= */
void __bea_callspec__ bt_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.MnemonicId = I_BT;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bt");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);
}

/* =======================================
 *      0fb3h
 * ======================================= */
void __bea_callspec__ btr_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.MnemonicId = I_BTR;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btr");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);
}

/* =======================================
 *      0fabh
 * ======================================= */
void __bea_callspec__ bts_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.MnemonicId = I_BTS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bts");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);
}

/* =======================================
 *      e8h
 * ======================================= */
void __bea_callspec__ call_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = CallType;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.MnemonicId = I_CALL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1))+5+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        if (MyAddress >= 0x80000000) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1))+3+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ callf_(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    UInt64 MyAddress;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = CallType;
        (*pMyDisasm).Instruction.MnemonicId = I_CALL_FAR;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lcall");
            #endif
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic,"\x24");
            #endif
            i++;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call far");
            #endif
        }
        if (GV.OperandSize ==32) {
            if (!Security(7, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+5));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        else {
            if (!Security(5, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+3));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " , \x24");
            #endif
            i+=4;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " : ");
            #endif
            i+=3;
        }
        MyAddress = MyNumber*16;
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.8X",(Int64) MyNumber);
        #endif
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
    }
}

/* =======================================
 *      99h
 * ======================================= */
void __bea_callspec__ cdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Instruction.MnemonicId = I_CQO;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cqto");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cqo");
            #endif
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize ==32) {
        (*pMyDisasm).Instruction.MnemonicId = I_CDQ;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cltd");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdq");
            #endif
        }
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_CWD;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwtd");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwd");
            #endif
        }
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ clts_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CLTS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clts");
    #endif
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+CR_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, EFLAGS_CLTS);
    GV.EIP_++;
}


/* =======================================
 *      F5h
 * ======================================= */
void __bea_callspec__ cmc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmc");
    #endif
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, EFLAGS_CMC);
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovo_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_O;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovo");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccO);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovno_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NO;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVNO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovno");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNO);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_B;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVB;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovb");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccB);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovae_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_AE;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVAE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovae");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccAE);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmove_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmove");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccE);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovne_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVNE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovne");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNE);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovbe_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_BE;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVBE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovbe");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccBE);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmova_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_A;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVA;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmova");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccA);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovs_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_S;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovs");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccS);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovns_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NS;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVNS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovns");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNS);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_P;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovp");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccP);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NP;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVNP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnp");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNP);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovl_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_L;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovl");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccL);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovge_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_GE;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVGE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovge");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccGE);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovle_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_LE;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVLE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovle");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccLE);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovg_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_G;
    (*pMyDisasm).Instruction.MnemonicId = I_CMOVG;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovg");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccG);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmpx_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_CMPXCHG;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg");
    #endif
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_CMPXCHG);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmpx_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_CMPXCHG;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_CMPXCHG);
}

/* =======================================
 *      38h
 * ======================================= */
void __bea_callspec__ cmp_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp");
    #endif
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      39h
 * ======================================= */
void __bea_callspec__ cmp_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3ah
 * ======================================= */
void __bea_callspec__ cmp_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp");
    #endif
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3bh
 * ======================================= */
void __bea_callspec__ cmp_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp");
    #endif
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3ch
 * ======================================= */
void __bea_callspec__ cmp_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp");
    #endif
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3dh
 * ======================================= */
void __bea_callspec__ cmp_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp");
    #endif
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      a6h
 * ======================================= */
void __bea_callspec__ cmpsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_CMPSB;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsb");
    #endif
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
    /* ========= 0xf2 */
    else if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
    FillFlags(pMyDisasm, EFLAGS_CMPS);
    GV.EIP_++;
}

/* =======================================
 *      a7h
 * ======================================= */
void __bea_callspec__ cmps_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    if (GV.Architecture == 64) {
        (*pMyDisasm).Instruction.MnemonicId = I_CMPSQ;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsq");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        (*pMyDisasm).Instruction.MnemonicId = I_CMPSD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsd");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_CMPSW;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsw");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
    /* ========= 0xf2 */
    else if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
    FillFlags(pMyDisasm, EFLAGS_CMPS);
    GV.EIP_++;
}

/* =======================================
 *      98h
 * ======================================= */
void __bea_callspec__ cwde_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Instruction.MnemonicId = I_CDQE;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cltq");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdqe");
            #endif
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if (GV.OperandSize == 32) {
        (*pMyDisasm).Instruction.MnemonicId = I_CWDE;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwtl");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwde");
            #endif
        }
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_CBW;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cbtw");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cbw");
            #endif
        }
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 8;
    }
    GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ clc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Instruction.MnemonicId = I_CLC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clc");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, EFLAGS_CLC);
    GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ cld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Instruction.MnemonicId = I_CLD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cld");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, EFLAGS_CLD);
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cli_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Instruction.MnemonicId = I_CLI;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cli");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, EFLAGS_CLI);
    GV.EIP_++;
}

/* =======================================
 *      0fa2h
 * ======================================= */
void __bea_callspec__ cpuid_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0+REG1+REG2+REG3;
    (*pMyDisasm).Instruction.MnemonicId = I_CPUID;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cpuid");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 32;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ daa_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DAA;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "daa");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DAA);
        GV.EIP_++;
    }

}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ das_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DAS;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "das");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DAS);
        GV.EIP_++;
    }

}

/* =======================================
 *      48h
 * ======================================= */
void __bea_callspec__ dec_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      49h
 * ======================================= */
void __bea_callspec__ dec_ecx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4ah
 * ======================================= */
void __bea_callspec__ dec_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4bh
 * ======================================= */
void __bea_callspec__ dec_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4ch
 * ======================================= */
void __bea_callspec__ dec_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4dh
 * ======================================= */
void __bea_callspec__ dec_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4eh
 * ======================================= */
void __bea_callspec__ dec_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4fh
 * ======================================= */
void __bea_callspec__ dec_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      0c8h
 * ======================================= */
void __bea_callspec__ enter_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_ENTER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "enter");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic,"%.4X",(Int64) *((UInt16*)(UIntPtr) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+3)));
    #endif
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    GV.EIP_+=4;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ femms_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = AMD_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_FEMMS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "femms");
    #endif
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ hlt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_HLT;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hlt");
    #endif
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ invd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_INVD;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "invd");
    #endif
    GV.EIP_++;
}

/* =======================================
 *      40h
 * ======================================= */
void __bea_callspec__ inc_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      41h
 * ======================================= */
void __bea_callspec__ inc_ecx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      42h
 * ======================================= */
void __bea_callspec__ inc_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      43h
 * ======================================= */
void __bea_callspec__ inc_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      44h
 * ======================================= */
void __bea_callspec__ inc_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      45h
 * ======================================= */
void __bea_callspec__ inc_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      46h
 * ======================================= */
void __bea_callspec__ inc_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      47h
 * ======================================= */
void __bea_callspec__ inc_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(2, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}
/* =======================================
 *  0xcf
 * ======================================= */
void __bea_callspec__ iret_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    if (GV.OperandSize ==64) {
        (*pMyDisasm).Instruction.MnemonicId = I_IRETQ;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretq");
        #endif
    }
    else if (GV.OperandSize == 32) {
        (*pMyDisasm).Instruction.MnemonicId = I_IRETD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretd");
        #endif
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_IRETW;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretw");
        #endif
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ in_ALDX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_IN;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0]);
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 16;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ in_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_IN;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in");
    #endif
    ALIb(pMyDisasm);
}

/* =======================================
 *      0xe5
 * ======================================= */
void __bea_callspec__ in_eAX_Ib(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_IN;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_+=2;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ insb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_INSB;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insb");
    #endif
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 16;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_INS);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ ins_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    if (GV.OperandSize >= 32) {
        (*pMyDisasm).Instruction.MnemonicId = I_INSD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insd");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INS);
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_INSW;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insw");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INS);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ into_(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_INTO;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "into");
        #endif
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_INTO);
    }
}

/* =======================================
 *      0edh
 * ======================================= */
void __bea_callspec__ in_eAX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_IN;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in");
    #endif
    if (GV.OperandSize >=32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
        #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
        #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *      0cdh
 * ======================================= */
void __bea_callspec__ int_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_INT;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_INT);
}

/* =======================================
 *      0f1h
 * ======================================= */
void __bea_callspec__ int1_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_INT1;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int1");
    #endif
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_INT);
}

/* =======================================
 *      0cch
 * ======================================= */
void __bea_callspec__ int3_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_INT3;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int3");
    #endif
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_INT);
}

/* =======================================
 *      69h
 * ======================================= */
void __bea_callspec__ imul_GvEvIv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_IMUL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        GV.ImmediatSize = 32;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+6;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((Int32*)(UIntPtr) (GV.EIP_- 4));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.8X",(Int64) *((Int32*)(UIntPtr) (GV.EIP_- 4)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 32;

        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else {
        GV.MemDecoration = Arg2word;
        GV.ImmediatSize = 16;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+4;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((Int16*)(UIntPtr) (GV.EIP_- 2));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.4X",(Int64) *((Int16*)(UIntPtr) (GV.EIP_- 2)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 16;

        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
}

/* =======================================
 *      6bh
 * ======================================= */
void __bea_callspec__ imul_GvEvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_IMUL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((Int8*)(UIntPtr) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((Int8*)(UIntPtr) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else {
        GV.MemDecoration = Arg2word;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((Int8*)(UIntPtr) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((Int8*)(UIntPtr) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
}

/* =======================================
 *      0fafh
 * ======================================= */
void __bea_callspec__ imul_GvEv(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_IMUL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul");
    #endif
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_IMUL);
}

/* =======================================
 *      70h
 * ======================================= */
void __bea_callspec__ jo_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;

    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_O;
    (*pMyDisasm).Instruction.MnemonicId = I_JO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jo");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccO);
}

/* =======================================
 *      71h
 * ======================================= */
void __bea_callspec__ jno_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NO;
    (*pMyDisasm).Instruction.MnemonicId = I_JNO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jno");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccNO);
}

/* =======================================
 *      72h
 * ======================================= */
void __bea_callspec__ jb_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_B;
    (*pMyDisasm).Instruction.MnemonicId = I_JB;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jb");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccB);
}

/* =======================================
 *      73h
 * ======================================= */
void __bea_callspec__ jae_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_AE;
    (*pMyDisasm).Instruction.MnemonicId = I_JAE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jae");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccAE);
}
/* =======================================
 *      74h
 * ======================================= */
void __bea_callspec__ je_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.MnemonicId = I_JE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "je");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccE);
}

/* =======================================
 *      75h
 * ======================================= */
void __bea_callspec__ jne_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.MnemonicId = I_JNE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jne");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccNE);
}

/* =======================================
 *      76h
 * ======================================= */
void __bea_callspec__ jbe_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_BE;
    (*pMyDisasm).Instruction.MnemonicId = I_JBE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jbe");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccBE);
}

/* =======================================
 *      77h
 * ======================================= */
void __bea_callspec__ ja_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_A;
    (*pMyDisasm).Instruction.MnemonicId = I_JA;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ja");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccA);
}

/* =======================================
 *      78h
 * ======================================= */
void __bea_callspec__ js_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_S;
    (*pMyDisasm).Instruction.MnemonicId = I_JS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "js");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccS);
}

/* =======================================
 *      79h
 * ======================================= */
void __bea_callspec__ jns_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NS;
    (*pMyDisasm).Instruction.MnemonicId = I_JNS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jns");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccNS);
}

/* =======================================
 *      7ah
 * ======================================= */
void __bea_callspec__ jp_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_P;
    (*pMyDisasm).Instruction.MnemonicId = I_JP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jp");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccP);
}

/* =======================================
 *      7bh
 * ======================================= */
void __bea_callspec__ jnp_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NP;
    (*pMyDisasm).Instruction.MnemonicId = I_JNP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnp");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccNP);
}

/* =======================================
 *      7ch
 * ======================================= */
void __bea_callspec__ jl_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_L;
    (*pMyDisasm).Instruction.MnemonicId = I_JL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jl");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccL);
}

/* =======================================
 *      7dh
 * ======================================= */
void __bea_callspec__ jge_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_GE;
    (*pMyDisasm).Instruction.MnemonicId = I_JGE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jge");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccGE);
}

/* =======================================
 *      7eh
 * ======================================= */
void __bea_callspec__ jle_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_LE;
    (*pMyDisasm).Instruction.MnemonicId = I_JLE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jle");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccLE);
}

/* =======================================
 *      7fh
 * ======================================= */
void __bea_callspec__ jg_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_G;
    (*pMyDisasm).Instruction.MnemonicId = I_JG;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jg");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_ccG);
}


/* =======================================
 *      0f80h
 * ======================================= */
void __bea_callspec__ jo_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_O;
    (*pMyDisasm).Instruction.MnemonicId = I_JO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jo");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccO);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccO);
    }
}


/* =======================================
 *      0f81h
 * ======================================= */
void __bea_callspec__ jno_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NO;
    (*pMyDisasm).Instruction.MnemonicId = I_JNO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jno");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccNO);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccNO);
    }
}

/* =======================================
 *      0f82h
 * ======================================= */
void __bea_callspec__ jb_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_B;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JB;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jb");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccB);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccB);
    }
}

/* =======================================
 *      0f83h
 * ======================================= */
void __bea_callspec__ jae_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_AE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JAE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jae");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccAE);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccAE);
    }
}

/* =======================================
 *      0f84h
 * ======================================= */
void __bea_callspec__ je_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "je");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccE);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccE);
    }
}

/* =======================================
 *      0f85h
 * ======================================= */
void __bea_callspec__ jne_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JNE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jne");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccNE);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccNE);
    }
}
/* =======================================
 *      0f86h
 * ======================================= */
void __bea_callspec__ jbe_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_BE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JBE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jbe");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccBE);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccBE);
    }
}


/* =======================================
 *      0f87h
 * ======================================= */
void __bea_callspec__ ja_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_A;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JA;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ja");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccA);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccA);
    }
}

/* =======================================
 *      0f88h
 * ======================================= */
void __bea_callspec__ js_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_S;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "js");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccS);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccS);
    }
}

/* =======================================
 *      0f89h
 * ======================================= */
void __bea_callspec__ jns_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NS;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JNS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jns");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccNS);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccNS);
    }
}

/* =======================================
 *      0f8ah
 * ======================================= */
void __bea_callspec__ jp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_P;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jp");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccP);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccP);
    }
}

/* =======================================
 *      0f8bh
 * ======================================= */
void __bea_callspec__ jnp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NP;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JNP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnp");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccNP);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccNP);
    }
}

/* =======================================
 *      0f8ch
 * ======================================= */
void __bea_callspec__ jl_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_L;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jl");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccL);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccL);
    }
}

/* =======================================
 *      0f8dh
 * ======================================= */
void __bea_callspec__ jge_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_GE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JGE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jge");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccGE);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccGE);
    }
}

/* =======================================
 *      0f8eh
 * ======================================= */
void __bea_callspec__ jle_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_LE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JLE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jle");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccLE);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccLE);
    }
}

/* =======================================
 *      0f8fh
 * ======================================= */
void __bea_callspec__ jg_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int64 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_G;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JG;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jg");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_ccG);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_ccG);
    }
}

/* =======================================
 *      0e3h
 * ======================================= */
void __bea_callspec__ jecxz_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int64 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_ECXZ;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    if (GV.AddressSize == 64) {
        (*pMyDisasm).Instruction.MnemonicId = I_JRCXZ;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jrcxz");
        #endif
    }
    else if (GV.AddressSize == 32) {
        (*pMyDisasm).Instruction.MnemonicId = I_JECXZ;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jecxz");
        #endif
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_JCXZ;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jcxz");
        #endif
    }
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_JCXZ);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_JCXZ);
    }
}

/* =======================================
 *      0e9h
 * ======================================= */
void __bea_callspec__ jmp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+5+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;

        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm, EFLAGS_JMP);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+3+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm, EFLAGS_JMP);
    }
}


/* =======================================
 *      0ebh
 * ======================================= */
void __bea_callspec__ jmp_short(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Instruction.MnemonicId = I_JMP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, EFLAGS_JMP);
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ jmp_far(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    UInt64 MyAddress;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = JmpType;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.MnemonicId = I_JMP_FAR;
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ljmp");
            #endif
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic,"\x24");
            #endif
            i++;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp far");
            #endif
        }
        if (GV.OperandSize ==32) {
            if (!Security(7, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+5));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        else {
            if (!Security(5, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+3));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
            #endif
        }
        if (GV.SYNTAX_ == ATSyntax) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " , \x24");
            #endif
            i+=4;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " : ");
            #endif
            i+=3;
        }
        MyAddress = MyNumber*16;
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.8X",(Int64) MyNumber);
        #endif
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lahf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_LAHF;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lahf");
    #endif
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lar_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_LAR;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lar");
    #endif
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_LAR);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lds_GvM(PDISASM pMyDisasm)
{
    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        (*pMyDisasm).Instruction.MnemonicId = I_LDS;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lds");
        #endif
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0c9h
 * ======================================= */
void __bea_callspec__ leave_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_LEAVE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "leave");
    #endif
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG5;
    (*pMyDisasm).Argument2.ArgSize = 32;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lea_GvM(PDISASM pMyDisasm)
{

    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_LEA;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lea");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    (*pMyDisasm).Argument2.AccessMode = 0;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ les_GvM(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        (*pMyDisasm).Instruction.MnemonicId = I_LES;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "les");
        #endif
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0ach
 * ======================================= */
void __bea_callspec__ lodsb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_LODSB;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsb");
    #endif
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_LODS);
}

/* =======================================
 *      0adh
 * ======================================= */
void __bea_callspec__ lodsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Instruction.MnemonicId = I_LODSQ;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsq");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_LODS);
    }
    else if (GV.OperandSize == 32) {
        (*pMyDisasm).Instruction.MnemonicId = I_LODSD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsd");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_LODS);
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_LODSW;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsw");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_LODS);
    }
}

/* =======================================
 *      0e2h
 * ======================================= */
void __bea_callspec__ loop_(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = LoopType;
    (*pMyDisasm).Instruction.MnemonicId = I_LOOP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loop");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_LOOP);
    }
    else {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_LOOP);
    }
}

/* =======================================
 *      0xe0
 * ======================================= */
void __bea_callspec__ loopne_(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = LoopType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.MnemonicId = I_LOOPNE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loopne");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_ccNE);
    }
    else {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_ccNE);
    }
}

/* =======================================
 *      0xe1
 * ======================================= */
void __bea_callspec__ loope_(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = LoopType;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.MnemonicId = I_LOOPE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loope");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_ccE);
    }
    else {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, EFLAGS_ccE);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lsl_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_LSL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lsl");
    #endif
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_LSL);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lss_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (*pMyDisasm).Instruction.MnemonicId = I_LSS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lss");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lfs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (*pMyDisasm).Instruction.MnemonicId = I_LFS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lfs");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lgs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (*pMyDisasm).Instruction.MnemonicId = I_LGS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lgs");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_RdCd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.MnemonicId = I_MOV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
        #endif
        GV.CR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.CR_ = 0;
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_RdDd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.MnemonicId = I_MOV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
        #endif
        GV.DR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.DR_ = 0;
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_CdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.MnemonicId = I_MOV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
        #endif
        GV.CR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.CR_ = 0;
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_DdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.MnemonicId = I_MOV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
        #endif
        GV.DR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.DR_ = 0;
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      88h
 * ======================================= */
void __bea_callspec__ mov_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    EbGb(pMyDisasm);
}

/* =======================================
 *      89h
 * ======================================= */
void __bea_callspec__ mov_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    EvGv(pMyDisasm);
}

/* =======================================
 *      8ah
 * ======================================= */
void __bea_callspec__ mov_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GbEb(pMyDisasm);
}

/* =======================================
 *      8bh
 * ======================================= */
void __bea_callspec__ mov_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *      0a0h
 * ======================================= */
void __bea_callspec__ mov_ALOb(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GV.MemDecoration = Arg2byte;
    GV.RM_ = 5;
    GV.MOD_= 0;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0]);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0+8]);
        #endif
    }

}

/* =======================================
 *      0a1h
 * ======================================= */
void __bea_callspec__ mov_eAXOv(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            GV.MemDecoration = Arg2word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            GV.MemDecoration = Arg2word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE ;
    if (GV.MemDecoration == 104) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.MemDecoration == 103) {
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if (GV.MemDecoration == 102) {
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

}

/* =======================================
 *      0a2h
 * ======================================= */
void __bea_callspec__ mov_ObAL(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.RM_ = 5;
    GV.MOD_= 0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers8Bits[0]);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers8Bits[0+8]);
        #endif
    }

}

/* =======================================
 *      0a3h
 * ======================================= */
void __bea_callspec__ mov_OveAX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            GV.MemDecoration = Arg1word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            GV.MemDecoration = Arg1word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }

    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
    if (GV.MemDecoration == Arg1qword) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.MemDecoration == Arg1dword) {
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if (GV.MemDecoration == Arg1word) {
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
}

/* =======================================
 *      0b0h
 * ======================================= */
void __bea_callspec__ mov_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    ALIb(pMyDisasm);
}

/* =======================================
 *      0b1h
 * ======================================= */
void __bea_callspec__ mov_CLIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[1]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b2h
 * ======================================= */
void __bea_callspec__ mov_DLIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[2]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b3h
 * ======================================= */
void __bea_callspec__ mov_BLIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[3]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b4h
 * ======================================= */
void __bea_callspec__ mov_AHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[4]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b5h
 * ======================================= */
void __bea_callspec__ mov_CHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[5]);
    #endif
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b6h
 * ======================================= */
void __bea_callspec__ mov_DHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[6]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b7h
 * ======================================= */
void __bea_callspec__ mov_BHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[7]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
	(*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}


/* =======================================
 *      0a4h
 * ======================================= */
void __bea_callspec__ movs_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Instruction.MnemonicId = I_MOVSB;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsb");
    #endif
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_MOVS);
}

/* =======================================
 *      0a5h
 * ======================================= */
void __bea_callspec__ movsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSQ;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsq");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_MOVS);
    }
    else if (GV.OperandSize == 32) {
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd");
        #endif
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_MOVS);
    }
    else {
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSW;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsw");
        #endif
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, EFLAGS_MOVS);
    }
}

/* =======================================
 *      0fb6h
 * ======================================= */
void __bea_callspec__ movzx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOVZX;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx");
    #endif
    GvEb(pMyDisasm);
}


/* =======================================
 *      0fbeh
 * ======================================= */
void __bea_callspec__ movsx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOVSX;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx");
    #endif
    GvEb(pMyDisasm);
}

/* =======================================
 *      0fbfh
 * ======================================= */
void __bea_callspec__ movsx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOVSX;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx");
    #endif
    GvEw(pMyDisasm);
}

/* =======================================
 *      0fb7h
 * ======================================= */
void __bea_callspec__ movzx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOVZX;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx");
    #endif
    GvEw(pMyDisasm);
}

/* =======================================
 *      0b8h
 * ======================================= */
void __bea_callspec__ mov_EAX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
        GV.EIP_+=9;
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0b9h
 * ======================================= */
void __bea_callspec__ mov_ECX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
        #endif
        GV.EIP_+=9;
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bah
 * ======================================= */
void __bea_callspec__ mov_EDX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bbh
 * ======================================= */
void __bea_callspec__ mov_EBX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bch
 * ======================================= */
void __bea_callspec__ mov_ESP(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bdh
 * ======================================= */
void __bea_callspec__ mov_EBP(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0beh
 * ======================================= */
void __bea_callspec__ mov_ESI(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bfh
 * ======================================= */
void __bea_callspec__ mov_EDI(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(Int64) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64) MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0+8]);
            #endif
        }
    }

}
/* =======================================
 *      0c6h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EbIb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
        #endif
        EbIb(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      0c7h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EvIv(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOV;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
        #endif
        EvIv(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      08ch
 * ======================================= */
void __bea_callspec__ mov_EwSreg(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GV.MemDecoration = Arg1word;
    GV.OperandSize = 16;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.OperandSize = 32;
    GV.SEG_ = 1;
    Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.SEG_ = 0;
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* =======================================
 *      08eh
 * ======================================= */
void __bea_callspec__ mov_SregEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_MOV;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov");
    #endif
    GV.MemDecoration = Arg2word;
    GV.OperandSize = 16;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.OperandSize = 32;
    GV.SEG_ = 1;
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.SEG_ = 0;
    GV.EIP_ += GV.DECALAGE_EIP+2;
}
