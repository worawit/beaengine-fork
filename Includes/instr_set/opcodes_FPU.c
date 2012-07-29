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
void __bea_callspec__ D8_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        (*pMyDisasm).Argument2.ArgSize = 32;
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FADD;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 1) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FMUL;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 2) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FCOM;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FCOMP;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FSUB;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 5) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FSUBR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 6) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FDIV;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 7) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FDIVR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FADD;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FMUL;
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOM;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOMP;
            }
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSUB;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSUBR;
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FDIV;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FDIVR;
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ D9_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            (*pMyDisasm).Argument1.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.AccessMode = READ;
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FLD;
        }
        else if (GV.REGOPCODE == 2) {
            (*pMyDisasm).Argument1.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FST;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            (*pMyDisasm).Argument1.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FSTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            (*pMyDisasm).Argument2.ArgSize = 0;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (*pMyDisasm).Instruction.Mnemonic = I_FLDENV;
        }
        else if (GV.REGOPCODE == 5) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (*pMyDisasm).Instruction.Mnemonic = I_FLDCW;
        }
        else if (GV.REGOPCODE == 6) {
            (*pMyDisasm).Argument1.ArgSize = 0;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (*pMyDisasm).Instruction.Mnemonic = I_FNSTENV;
        }
        else if (GV.REGOPCODE == 7) {
            (*pMyDisasm).Argument1.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (*pMyDisasm).Instruction.Mnemonic = I_FNSTCW;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FLD;
                (*pMyDisasm).Argument1.AccessMode = READ;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FXCH;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
                (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0xf) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FNOP;
            }
            else if (MyMODRM & 0x8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FSTP1;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCHS;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FABS;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FTST;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FXAM;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (*pMyDisasm).Instruction.Mnemonic = I_FLD1;
            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (*pMyDisasm).Instruction.Mnemonic = I_FLDL2T;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (*pMyDisasm).Instruction.Mnemonic = I_FLDL2E;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (*pMyDisasm).Instruction.Mnemonic = I_FLDPI;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (*pMyDisasm).Instruction.Mnemonic = I_FLDLG2;
            }
            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (*pMyDisasm).Instruction.Mnemonic = I_FLDLN2;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (*pMyDisasm).Instruction.Mnemonic = I_FLDZ;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_F2XM1;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FYL2X;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgSize = READ;
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FPTAN;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FPATAN;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgSize = READ;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FXTRACT;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FPREM1;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgSize = READ;
            }
            else if ((MyMODRM & 0xf) ==6) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FDECSTP;
            }
            else if ((MyMODRM & 0xf) ==7) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FINCSTP;
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FPREM;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgSize = READ;
            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FYL2XP1;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgSize = READ;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSQRT;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSINCOS;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FRNDINT;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSCALE;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgSize = READ;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSIN;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else if ((MyMODRM & 0xf) ==0xf) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOS;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgSize = READ+WRITE;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DA_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIADD;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 1) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIMUL;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 2) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FICOM;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FICOMP;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FISUB;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 5) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FISUBR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 6) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIDIV;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            (*pMyDisasm).Argument2.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIDIVR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.ConditionalType = CC_B;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVB;
                FillFlags(pMyDisasm, EFLAGS_ccB);
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.ConditionalType = CC_E;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVE;
                FillFlags(pMyDisasm, EFLAGS_ccE);
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.ConditionalType = CC_BE;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVBE;
                FillFlags(pMyDisasm, EFLAGS_ccBE);
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.ConditionalType = CC_P;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVU;
                FillFlags(pMyDisasm, EFLAGS_ccP);
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;

        }
        else if (MyMODRM == 0xe9) {
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FUCOMPP;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DB_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            (*pMyDisasm).Argument1.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FILD;
        }
        else if (GV.REGOPCODE == 1) {
            (*pMyDisasm).Argument1.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FISTTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            (*pMyDisasm).Argument1.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FIST;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            (*pMyDisasm).Argument1.ArgSize = 32;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FISTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            (*pMyDisasm).Argument1.ArgSize = 80;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FLD;
        }
        else if (GV.REGOPCODE == 7) {
            (*pMyDisasm).Argument1.ArgSize = 80;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FSTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.ConditionalType = CC_AE;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVNB;
                FillFlags(pMyDisasm, EFLAGS_ccAE);
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.ConditionalType = CC_NE;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVNE;
                FillFlags(pMyDisasm, EFLAGS_ccNE);
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.ConditionalType = CC_A;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVNBE;
                FillFlags(pMyDisasm, EFLAGS_ccA);
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.ConditionalType = CC_NP;
                (*pMyDisasm).Instruction.Mnemonic = I_FCMOVNU;
                FillFlags(pMyDisasm, EFLAGS_ccNP);
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {

            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FNENI;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FNDISI;
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FNCLEX;
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FNINIT;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FNSETPM;
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FRSTPM;
            }
            else if (MyMODRM & 0x8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FUCOMI;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOMI;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DC_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FADD;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 1) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FMUL;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 2) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FCOM;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FCOMP;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FSUB;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 5) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FSUBR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 6) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FDIV;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 7) {
            (*pMyDisasm).Argument2.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FDIVR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FADD;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FMUL;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOM2;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOMP3;
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSUBR;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSUB;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FDIVR;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FDIV;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DD_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FLD;
        }
        else if (GV.REGOPCODE == 1) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FISTTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FST;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FSTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            (*pMyDisasm).Argument2.ArgSize = 0;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (*pMyDisasm).Instruction.Mnemonic = I_FRSTOR;
        }
        else if (GV.REGOPCODE == 6) {
            (*pMyDisasm).Argument1.ArgSize = 0;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (*pMyDisasm).Instruction.Mnemonic = I_FNSAVE;
        }
        else if (GV.REGOPCODE == 7) {
            (*pMyDisasm).Argument1.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (*pMyDisasm).Instruction.Mnemonic = I_FNSTSW;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FFREE;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG;
                (*pMyDisasm).Argument1.ArgSize = 2;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FXCH4;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
                (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FST;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FSTP;
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FUCOM;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FUCOMP;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
            }
        }

        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DE_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIADD;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 1) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIMUL;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 2) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FICOM;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FICOMP;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FISUB;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 5) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FISUBR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 6) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIDIV;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if (GV.REGOPCODE == 7) {
            (*pMyDisasm).Argument2.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (*pMyDisasm).Instruction.Mnemonic = I_FIDIVR;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FADDP;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FMULP;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOMP5;
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument2.ArgSize = 80;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
            }
            else if (MyMODRM == 0xd9){
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOMPP;
                (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG1;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSUBRP;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FSUBP;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FDIVRP;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FDIVP;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DF_(PDISASM pMyDisasm)
{
    Int32 MyMODRM;

    GV.DECALAGE_EIP = 1;
    if (!Security(0, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_));
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            (*pMyDisasm).Argument1.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FILD;
        }
        else if (GV.REGOPCODE == 1) {
            (*pMyDisasm).Argument1.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FISTTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            (*pMyDisasm).Argument1.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FIST;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            (*pMyDisasm).Argument1.ArgSize = 16;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FISTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            (*pMyDisasm).Argument2.ArgSize = 0;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FBLD;
            (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FILD;
        }
        else if (GV.REGOPCODE == 6) {
            (*pMyDisasm).Argument1.ArgSize = 0;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FBSTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            (*pMyDisasm).Argument1.ArgSize = 64;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (*pMyDisasm).Instruction.Mnemonic = I_FISTP;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FFREEP;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG;
                (*pMyDisasm).Argument1.ArgSize = 2;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FXCH7;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
                (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
            }
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FSTP8;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (*pMyDisasm).Instruction.Mnemonic = I_FSTP9;
            }
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (MyMODRM == 0xe0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (*pMyDisasm).Instruction.Mnemonic = I_FNSTSW;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 16;
            }
            else if (MyMODRM & 0x8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FUCOMIP;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }


            else {
                FailDecode(pMyDisasm);
            }
        }

        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0x8) == 0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (*pMyDisasm).Instruction.Mnemonic = I_FCOMIP;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[MyMODRM & 0x7];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* =======================================
 *      9Bh
 * ======================================= */
void __bea_callspec__ wait_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
    (*pMyDisasm).Instruction.Mnemonic = I_WAIT;

    if (GV.EIP_+2 < GV.EndOfBlock) {
        /*
         * Extra FPU instructions
         * if they fail to decode, fallback to wait instruction
         * 9B D9 /6 FSTENV
         * 9B D9 /7 FSTCW
         * 9B DB E2 FCLEX
         * 9B DB E3 FINIT
         * 9B DD /6 FSAVE
         * 9B DD /7 FSTSW m2byte
         * 9B DF E0 FSTSW AX
         */
        /* TODO: MOD_RM check Security, it is not for this case */
        if (*((UInt8*) (UIntPtr)GV.EIP_) == 0xd9) {
            /* allow only memory argument */
            if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) <= 0xbf) {
                GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
                if (GV.REGOPCODE == 6) {
                    GV.EIP_++;
                    (*pMyDisasm).Instruction.Opcode = 0x9bd9;
                    (*pMyDisasm).Argument1.ArgSize = 0;
                    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
                    (*pMyDisasm).Instruction.Mnemonic = I_FSTENV;
                    GV.EIP_ += GV.DECALAGE_EIP;
                }
                else if (GV.REGOPCODE == 7) {
                    GV.EIP_++;
                    (*pMyDisasm).Instruction.Opcode = 0x9bd9;
                    (*pMyDisasm).Argument1.ArgSize = 16;
                    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
                    (*pMyDisasm).Instruction.Mnemonic = I_FSTCW;
                    GV.EIP_ += GV.DECALAGE_EIP;
                }
            }
        }
        else if (*((UInt8*) (UIntPtr)GV.EIP_) == 0xdb) {
            if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) == 0xe2) {
                (*pMyDisasm).Instruction.Opcode = 0x9bdbe2;
                (*pMyDisasm).Instruction.Mnemonic = I_FCLEX;
                GV.EIP_ += 2;
            }
            else if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) == 0xe3) {
                (*pMyDisasm).Instruction.Opcode = 0x9bdbe3;
                (*pMyDisasm).Instruction.Mnemonic = I_FINIT;
                GV.EIP_ += 2;
            }
        }
        else if (*((UInt8*) (UIntPtr)GV.EIP_) == 0xdd) {
            /* allow only memory argument */
            if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) <= 0xbf) {
                GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
                if (GV.REGOPCODE == 6) {
                    GV.EIP_++;
                    (*pMyDisasm).Instruction.Opcode = 0x9bdd;
                    (*pMyDisasm).Argument1.ArgSize = 0;
                    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
                    (*pMyDisasm).Instruction.Mnemonic = I_FSAVE;
                    GV.EIP_ += GV.DECALAGE_EIP;
                }
                else if (GV.REGOPCODE == 7) {
                    GV.EIP_++;
                    (*pMyDisasm).Instruction.Opcode = 0x9bdd;
                    (*pMyDisasm).Argument1.ArgSize = 16;
                    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
                    (*pMyDisasm).Instruction.Mnemonic = I_FSTSW;
                    GV.EIP_ += GV.DECALAGE_EIP;
                }
            }
        }
        else if (*((UInt8*) (UIntPtr)GV.EIP_) == 0xdf) {
            if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) == 0xe0) {
                (*pMyDisasm).Instruction.Opcode = 0x9bdfe0;
                (*pMyDisasm).Instruction.Mnemonic = I_FSTSW;
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
                (*pMyDisasm).Argument1.ArgSize = 16;
                GV.EIP_ += 2;
            }
        }
    }
    
    if (GV.OutOfBlock) {
        (*pMyDisasm).Instruction.Mnemonic = I_WAIT;
        (*pMyDisasm).Argument1.ArgType = 0;
        GV.EIP_ = (*pMyDisasm).EIP+1;
        GV.OutOfBlock = 0;
    }
}
