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
 *      0feh
 * ==================================================================== */
void __bea_callspec__ G4_Eb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_INC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc");
        #endif
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
        if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
            (*pMyDisasm).Prefix.LockState = InUsePrefix;
        }
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.MnemonicId = I_DEC;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec");
        #endif
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
        if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
            (*pMyDisasm).Prefix.LockState = InUsePrefix;
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}

