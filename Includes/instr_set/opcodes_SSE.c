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
 *      0x 0f 58
 * ==================================================================== */
void __bea_callspec__ addps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ADDSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ADDSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ADDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ADDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d0
 * ==================================================================== */
void __bea_callspec__ addsubpd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        (*pMyDisasm).Instruction.MnemonicId = I_ADDSUBPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        (*pMyDisasm).Instruction.MnemonicId = I_ADDSUBPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 55
 * ==================================================================== */
void __bea_callspec__ andnps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ANDNPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ANDNPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 54
 * ==================================================================== */
void __bea_callspec__ andps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ANDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ANDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0d
 * ==================================================================== */
void __bea_callspec__ blendpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_BLENDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 0c
 * ==================================================================== */
void __bea_callspec__ blendps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_BLENDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 15
 * ==================================================================== */
void __bea_callspec__ blendvpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_BLENDVPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SSE_REG+REG0;
        (*pMyDisasm).Argument3.ArgSize = 128;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 14
 * ==================================================================== */
void __bea_callspec__ blendvps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_BLENDVPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SSE_REG+REG0;
        (*pMyDisasm).Argument3.ArgSize = 128;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c2
 * ==================================================================== */
void __bea_callspec__ cmpps_VW(PDISASM pMyDisasm)
{

    /* ========= 0xf2 */
    GV.ImmediatSize = 8;
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CMPSD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CMPSS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CMPPD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CMPPS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;

}


/* ====================================================================
 *      0x 0f 38 f0
 * ==================================================================== */
void __bea_callspec__ crc32_GvEb(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CRC32;
        if ((*pMyDisasm).Instruction.OperandSize == 64) {
            (*pMyDisasm).Argument2.ArgSize = 8;
            (*pMyDisasm).Instruction.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 8;
            (*pMyDisasm).Instruction.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.OperandSize = 32;
        }

        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 f1
 * ==================================================================== */
void __bea_callspec__ crc32_GvEv(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CRC32;

        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);

        if ((*pMyDisasm).Instruction.OperandSize == 16) {
            (*pMyDisasm).Instruction.OperandSize = 32;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.OperandSize = 16;
        }
        else {
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 2f
 * ==================================================================== */
void __bea_callspec__ comiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_COMISD;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_COMISS;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 5a
 * ==================================================================== */
void __bea_callspec__ cvtps2pd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTSD2SS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTSS2SD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPD2PS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPS2PD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5b
 * ==================================================================== */
void __bea_callspec__ cvtdq2ps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTTPS2DQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPS2DQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTDQ2PS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 2a
 * ==================================================================== */
void __bea_callspec__ cvtpi2ps_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTSI2SD;
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTSI2SS;
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPI2PD;
        (*pMyDisasm).Argument2.ArgSize = 64;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPI2PS;
        (*pMyDisasm).Argument2.ArgSize = 64;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f 2d
 * ==================================================================== */
void __bea_callspec__ cvtps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTSD2SI;
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 64;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTSS2SI;
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 32;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPD2PI;
        (*pMyDisasm).Argument2.ArgSize = 128;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPS2PI;
        (*pMyDisasm).Argument2.ArgSize = 64;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f 2c
 * ==================================================================== */
void __bea_callspec__ cvttps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTTSD2SI;
        if ((*pMyDisasm).Prefix.REX.W_ == 1) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 64;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTTSS2SI;
        (*pMyDisasm).Argument2.ArgSize = 32;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTTPD2PI;
        (*pMyDisasm).Argument2.ArgSize = 128;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTTPS2PI;
        (*pMyDisasm).Argument2.ArgSize = 64;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f e6
 * ==================================================================== */
void __bea_callspec__ cvtpd2dq_(PDISASM pMyDisasm)
{
    /* ========== 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTPD2DQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTDQ2PD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_CVTTPD2DQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 41
 * ==================================================================== */
void __bea_callspec__ dppd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        (*pMyDisasm).Instruction.MnemonicId = I_DPPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 3a 40
 * ==================================================================== */
void __bea_callspec__ dpps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        (*pMyDisasm).Instruction.MnemonicId = I_DPPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 5e
 * ==================================================================== */
void __bea_callspec__ divps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DIVSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DIVSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DIVPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DIVPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 17
 * ==================================================================== */
void __bea_callspec__ extractps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.MnemonicId = I_EXTRACTPS;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 7c
 * ==================================================================== */
void __bea_callspec__ haddpd_VW(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.MnemonicId = I_HADDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.MnemonicId = I_HADDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 7d
 * ==================================================================== */
void __bea_callspec__ hsubpd_VW(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.MnemonicId = I_HSUBPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.MnemonicId = I_HSUBPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 21
 * ==================================================================== */
void __bea_callspec__ insertps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INSERTPS;
        GV.SSE_ = 1;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            (*pMyDisasm).Argument2.ArgSize = 64;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 32;
        }

        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);


        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }

}



/* ====================================================================
 *      0x 0f f0
 * ==================================================================== */
void __bea_callspec__ lddqu_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SPECIALIZED_128bits;
        (*pMyDisasm).Instruction.MnemonicId = I_LDDQU;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f f7
 * ==================================================================== */
void __bea_callspec__ maskmovq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.MnemonicId = I_MASKMOVDQU;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument3.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument3.ArgSize = 8; /* don't know */
        (*pMyDisasm).Argument3.AccessMode = WRITE;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.MnemonicId = I_MASKMOVQ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument3.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument3.ArgSize = 8; /* don't know */
        (*pMyDisasm).Argument3.AccessMode = WRITE;
    }
}


/* ====================================================================
 *      0x 0f 5f
 * ==================================================================== */
void __bea_callspec__ maxps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MAXSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MAXSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MAXPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MAXPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5d
 * ==================================================================== */
void __bea_callspec__ minps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MINSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MINSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MINPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MINPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 28
 * ==================================================================== */
void __bea_callspec__ movaps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVAPD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVAPS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 29
 * ==================================================================== */
void __bea_callspec__ movaps_WV(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVAPD;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVAPS;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 16
 * ==================================================================== */
void __bea_callspec__ movhps_VM(PDISASM pMyDisasm)
{

    /* ========= 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSHDUP;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVHPD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            (*pMyDisasm).Instruction.MnemonicId = I_MOVLHPS;
        }
        else {
            (*pMyDisasm).Instruction.MnemonicId = I_MOVHPS;
        }
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 17
 * ==================================================================== */
void __bea_callspec__ movhps_MV(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVHPD;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVHPS;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 12
 * ==================================================================== */
void __bea_callspec__ movlps_VM(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVDDUP;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSLDUP;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVLPD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        if (GV.MOD_== 0x3) {
            (*pMyDisasm).Instruction.MnemonicId = I_MOVHLPS;
        }
        else {
            (*pMyDisasm).Instruction.MnemonicId = I_MOVLPS;
        }
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 13
 * ==================================================================== */
void __bea_callspec__ movlps_MV(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVLPD;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVLPS;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 50
 * ==================================================================== */
void __bea_callspec__ movmskps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_!= 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVMSKPD;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVMSKPS;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
}


/* ====================================================================
 *      0x 0f 38 2a
 * ==================================================================== */
void __bea_callspec__ movntdqa_(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+STREAMING_LOAD;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVNTDQA;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c3
 * ==================================================================== */
void __bea_callspec__ movnti_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
    (*pMyDisasm).Instruction.MnemonicId = I_MOVNTI;
    EvGv(pMyDisasm);

}


/* ====================================================================
 *      0x 0f 2b
 * ==================================================================== */
void __bea_callspec__ movntps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVNTPD;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVNTPS;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
}


/* ====================================================================
 *      0x 0f e7
 * ==================================================================== */
void __bea_callspec__ movntq_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVNTDQ;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVNTQ;
        GV.MMX_ = 1;
        ExGx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 10
 * ==================================================================== */
void __bea_callspec__ movups_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVUPD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVUPS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}



/* ====================================================================
 *      0x 0f 11
 * ==================================================================== */
void __bea_callspec__ movups_WV(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSD;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVSS;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVUPD;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MOVUPS;
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 42
 * ==================================================================== */
void __bea_callspec__ mpsadbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MPSADBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 59
 * ==================================================================== */
void __bea_callspec__ mulps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MULSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MULSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MULPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_MULPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 56
 * ==================================================================== */
void __bea_callspec__ orps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ORPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ORPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 2b
 * ==================================================================== */
void __bea_callspec__ packusdw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PACKUSDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f d4
 * ==================================================================== */
void __bea_callspec__ paddq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PADDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PADDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e0
 * ==================================================================== */
void __bea_callspec__ pavgb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PAVGB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PAVGB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e3
 * ==================================================================== */
void __bea_callspec__ pavgw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PAVGW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PAVGW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0f
 * ==================================================================== */
void __bea_callspec__ palignr_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PALIGNR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PALIGNR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
}


/* ====================================================================
 *      0x 0f 38 10
 * ==================================================================== */
void __bea_callspec__ pblendvb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PBLENDVB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+SSE_REG+REG0;
        (*pMyDisasm).Argument3.ArgSize = 128;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0e
 * ==================================================================== */
void __bea_callspec__ pblendw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PBLENDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 29
 * ==================================================================== */
void __bea_callspec__ pcmpeqq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_EQUALITY;
        (*pMyDisasm).Instruction.MnemonicId = I_PCMPEQQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 61
 * ==================================================================== */
void __bea_callspec__ pcmpestri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PCMPESTRI;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 60
 * ==================================================================== */
void __bea_callspec__ pcmpestrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PCMPESTRM;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = SSE_REG+REG0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 63
 * ==================================================================== */
void __bea_callspec__ pcmpistri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PCMPISTRI;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 62
 * ==================================================================== */
void __bea_callspec__ pcmpistrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PCMPESTRM;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = SSE_REG+REG0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 37
 * ==================================================================== */
void __bea_callspec__ pcmpgtq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PCMPGTQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 14
 * ==================================================================== */
void __bea_callspec__ pextrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PEXTRB;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgSize = 8;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 16
 * ==================================================================== */
void __bea_callspec__ pextrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        if ((*pMyDisasm).Prefix.REX.W_ == 0x1) {
            (*pMyDisasm).Instruction.MnemonicId = I_PEXTRQ;
            (*pMyDisasm).Argument1.ArgSize = 64;
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        else {
            (*pMyDisasm).Instruction.MnemonicId = I_PEXTRD;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f c5
 * ==================================================================== */
void __bea_callspec__ pextrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PEXTRW;
        (*pMyDisasm).Argument2.ArgSize = 128;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PEXTRW;
        (*pMyDisasm).Argument2.ArgSize = 128;
        GV.ImmediatSize = 8;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }

}

/* ====================================================================
 *      0x 0f 3a 15
 * ==================================================================== */
void __bea_callspec__ pextrw2_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PEXTRW;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 02
 * ==================================================================== */
void __bea_callspec__ phaddd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHADDD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHADDD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 03
 * ==================================================================== */
void __bea_callspec__ phaddsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHADDSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHADDSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 01
 * ==================================================================== */
void __bea_callspec__ phaddw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHADDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHADDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 41
 * ==================================================================== */
void __bea_callspec__ phminposuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+HORIZONTAL_SEARCH;
        (*pMyDisasm).Instruction.MnemonicId = I_PHMINPOSUW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 05
 * ==================================================================== */
void __bea_callspec__ phsubw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHSUBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHSUBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 06
 * ==================================================================== */
void __bea_callspec__ phsubd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHSUBD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHSUBD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 07
 * ==================================================================== */
void __bea_callspec__ phsubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHSUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PHSUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 20
 * ==================================================================== */
void __bea_callspec__ pinsrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PINSRB;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 22
 * ==================================================================== */
void __bea_callspec__ pinsrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        if ((*pMyDisasm).Prefix.REX.W_ == 0x1) {
            (*pMyDisasm).Instruction.MnemonicId = I_PINSRQ;
            (*pMyDisasm).Argument1.ArgSize = 64;
        }
        else {
            (*pMyDisasm).Instruction.MnemonicId = I_PINSRD;
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f c4
 * ==================================================================== */
void __bea_callspec__ pinsrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PINSRW;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PINSRW;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }

}


/* ====================================================================
 *      0x 0f 38 3c
 * ==================================================================== */
void __bea_callspec__ pmaxsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3d
 * ==================================================================== */
void __bea_callspec__ pmaxsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3e
 * ==================================================================== */
void __bea_callspec__ pmaxuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3f
 * ==================================================================== */
void __bea_callspec__ pmaxud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXUD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 38
 * ==================================================================== */
void __bea_callspec__ pminsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 39
 * ==================================================================== */
void __bea_callspec__ pminsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3a
 * ==================================================================== */
void __bea_callspec__ pminuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3b
 * ==================================================================== */
void __bea_callspec__ pminud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINUD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f da
 * ==================================================================== */
void __bea_callspec__ pminub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f de
 * ==================================================================== */
void __bea_callspec__ pmaxub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f ea
 * ==================================================================== */
void __bea_callspec__ pminsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMINSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f ee
 * ==================================================================== */
void __bea_callspec__ pmaxsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMAXSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 04
 * ==================================================================== */
void __bea_callspec__ pmaddubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMADDUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMADDUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f d7
 * ==================================================================== */
void __bea_callspec__ pmovmskb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {

        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVMSKB;
        (*pMyDisasm).Argument2.ArgSize = 128;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVMSKB;
        (*pMyDisasm).Argument2.ArgSize = 64;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }

}


/* ====================================================================
 *      0x 0f 38 21
 * ==================================================================== */
void __bea_callspec__ pmovsxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVSXBD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 22
 * ==================================================================== */
void __bea_callspec__ pmovsxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVSXBQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 20
 * ==================================================================== */
void __bea_callspec__ pmovsxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVSXBW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 25
 * ==================================================================== */
void __bea_callspec__ pmovsxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVSXDQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 23
 * ==================================================================== */
void __bea_callspec__ pmovsxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVSXWD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 24
 * ==================================================================== */
void __bea_callspec__ pmovsxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVSXWQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 31
 * ==================================================================== */
void __bea_callspec__ pmovzxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVZXBD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 32
 * ==================================================================== */
void __bea_callspec__ pmovzxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVZXBQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 30
 * ==================================================================== */
void __bea_callspec__ pmovzxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVZXBW;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 35
 * ==================================================================== */
void __bea_callspec__ pmovzxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVZXDQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 33
 * ==================================================================== */
void __bea_callspec__ pmovzxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVZXWD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 34
 * ==================================================================== */
void __bea_callspec__ pmovzxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMOVZXWQ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 28
 * ==================================================================== */
void __bea_callspec__ pmuldq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 40
 * ==================================================================== */
void __bea_callspec__ pmulld_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULLD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 0b
 * ==================================================================== */
void __bea_callspec__ pmulhrsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULHRSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULHRSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e4
 * ==================================================================== */
void __bea_callspec__ pmulhuw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULHUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULHUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f f4
 * ==================================================================== */
void __bea_callspec__ pmuludq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULUDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PMULUDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* =======================================
 *      0x 0f b8
 * ======================================= */
void __bea_callspec__ popcnt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.MnemonicId = I_POPCNT;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_POPCNT);
}


/* ====================================================================
 *      0x 0f f6
 * ==================================================================== */
void __bea_callspec__ psadbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PSADBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PSADBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 00
 * ==================================================================== */
void __bea_callspec__ pshufb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_PSHUFB;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_PSHUFB;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 70
 * ==================================================================== */
void __bea_callspec__ pshufw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========= 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PSHUFHW;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    /* ========= 0xf2 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PSHUFLW;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.MnemonicId = I_PSHUFD;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.MnemonicId = I_PSHUFW;
        GV.ImmediatSize = 8;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
}

/* ====================================================================
 *      0x 0f 38 08
 * ==================================================================== */
void __bea_callspec__ psignb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.MnemonicId = I_PSIGNB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.MnemonicId = I_PSIGNB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 0a
 * ==================================================================== */
void __bea_callspec__ psignd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.MnemonicId = I_PSIGND;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.MnemonicId = I_PSIGND;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 09
 * ==================================================================== */
void __bea_callspec__ psignw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.MnemonicId = I_PSIGNW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.MnemonicId = I_PSIGNW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f fb
 * ==================================================================== */
void __bea_callspec__ psubq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PSUBQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PSUBQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 17
 * ==================================================================== */
void __bea_callspec__ ptest_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_TEST;
        (*pMyDisasm).Instruction.MnemonicId = I_PTEST;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 6c
 * ==================================================================== */
void __bea_callspec__ punpcklqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PUNPCKLQDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 6d
 * ==================================================================== */
void __bea_callspec__ punpckhqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.MnemonicId = I_PUNPCKHQDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 53
 * ==================================================================== */
void __bea_callspec__ rcpps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_RCPSS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_RCPPS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 09
 * ==================================================================== */
void __bea_callspec__ roundpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ROUNDPD;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 08
 * ==================================================================== */
void __bea_callspec__ roundps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ROUNDPS;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0b
 * ==================================================================== */
void __bea_callspec__ roundsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ROUNDSD;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0a
 * ==================================================================== */
void __bea_callspec__ roundss_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_ROUNDSS;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 52
 * ==================================================================== */
void __bea_callspec__ rsqrtps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_RSQRTSS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_RSQRTPS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f c6
 * ==================================================================== */
void __bea_callspec__ shufps_(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    GV.ImmediatSize = 8;
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_SHUFPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_SHUFPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;

}


/* ====================================================================
 *      0x 0f 51
 * ==================================================================== */
void __bea_callspec__ sqrtps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SQRTSD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SQRTSS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SQRTPD;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SQRTPS;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5c
 * ==================================================================== */
void __bea_callspec__ subps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SUBSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SUBSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SUBPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_SUBPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 2e
 * ==================================================================== */
void __bea_callspec__ ucomiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Instruction.OperandSize == 16) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_UCOMISD;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_UCOMISS;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 15
 * ==================================================================== */
void __bea_callspec__ unpckhps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Instruction.OperandSize == 16) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_UNPCKHPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_UNPCKHPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 14
 * ==================================================================== */
void __bea_callspec__ unpcklps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_UNPCKLPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.MnemonicId = I_UNPCKLPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 57
 * ==================================================================== */
void __bea_callspec__ xorps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_XORPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_XORPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}
