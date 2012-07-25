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
void __bea_callspec__ G12_(PDISASM pMyDisasm)
{
    Int32 MyNumber;

    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 2) {
        if ((*pMyDisasm).Instruction.OperandSize == 16) {
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHIFT_ROTATE;
            (*pMyDisasm).Argument1.ArgSize = 128;
            GV.ImmediatSize = 8;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            GV.SSE_ = 0;
            if (GV.MOD_== 0x3) {
                (*pMyDisasm).Instruction.MnemonicId = I_PSRLW;
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        else {
            (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
            (*pMyDisasm).Argument1.ArgSize = 64;
            GV.ImmediatSize = 8;
            GV.MMX_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            GV.MMX_ = 0;
            if (GV.MOD_== 0x3) {
                (*pMyDisasm).Instruction.MnemonicId = I_PSRLW;
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
    }
    else if (GV.REGOPCODE == 4) {
        if ((*pMyDisasm).Instruction.OperandSize == 16) {
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHIFT_ROTATE;
            (*pMyDisasm).Argument1.ArgSize = 128;
            GV.ImmediatSize = 8;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            GV.SSE_ = 0;
            if (GV.MOD_== 0x3) {
                (*pMyDisasm).Instruction.MnemonicId = I_PSRAW;
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        else {
            (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
            (*pMyDisasm).Argument1.ArgSize = 64;
            GV.ImmediatSize = 8;
            GV.MMX_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            GV.MMX_ = 0;
            if (GV.MOD_== 0x3) {
                (*pMyDisasm).Instruction.MnemonicId = I_PSRAW;
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }

    }
    else if (GV.REGOPCODE == 6) {
        if ((*pMyDisasm).Instruction.OperandSize == 16) {
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHIFT_ROTATE;
            (*pMyDisasm).Argument1.ArgSize = 128;
            GV.ImmediatSize = 8;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            GV.SSE_ = 0;
            if (GV.MOD_== 0x3) {
                (*pMyDisasm).Instruction.MnemonicId = I_PSLLW;
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        else {
            (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
            (*pMyDisasm).Argument1.ArgSize = 64;
            GV.ImmediatSize = 8;
            GV.MMX_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            GV.MMX_ = 0;
            if (GV.MOD_== 0x3) {
                (*pMyDisasm).Instruction.MnemonicId = I_PSLLW;
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
    }

    else {
        FailDecode(pMyDisasm);
    }

}
