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
 *      0x 0f 38 db
 * ==================================================================== */
void __bea_callspec__ aesimc(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AESIMC;
        VxWx(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 dc
 * ==================================================================== */
void __bea_callspec__ aesenc(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AESENC;
        VxWx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 dd
 * ==================================================================== */
void __bea_callspec__ aesenclast(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AESENCLAST;
        VxWx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 de
 * ==================================================================== */
void __bea_callspec__ aesdec(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AESDEC;
        VxWx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 df
 * ==================================================================== */
void __bea_callspec__ aesdeclast(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AESDECLAST;
        VxWx(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 3a df
 * ==================================================================== */
void __bea_callspec__ aeskeygen(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        (*pMyDisasm).Instruction.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSizeState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AESKEYGENASSIST;
        GV.ImmediatSize = 8;
        VxWx(pMyDisasm);
        if (!Security(1, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }

}
