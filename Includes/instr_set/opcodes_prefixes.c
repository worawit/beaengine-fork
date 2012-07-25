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
 *      Legacy Prefix F0h-Group 1
 * ==================================================================== */
void __bea_callspec__ PrefLock(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.LockState = InvalidPrefix;
    (*pMyDisasm).Prefix.Number++;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode =  *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix F2h-Group 1
 * ==================================================================== */
void __bea_callspec__ PrefREPNE(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Repeat = PrefixRepne;
    (*pMyDisasm).Prefix.RepeatState = SuperfluousPrefix;
    (*pMyDisasm).Prefix.Number++;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix F3h-Group 1
 * ==================================================================== */
void __bea_callspec__ PrefREPE(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Repeat = PrefixRepe;
    (*pMyDisasm).Prefix.RepeatState = SuperfluousPrefix;
    (*pMyDisasm).Prefix.Number++;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 2Eh-Group 2
 * ==================================================================== */
void __bea_callspec__ PrefSEGCS(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Number++;
    if ((*pMyDisasm).Archi != 64) {
        (*pMyDisasm).Prefix.Segment = PrefixCS;
        (*pMyDisasm).Prefix.SegmentState = InUsePrefix;
    }
    (*pMyDisasm).Prefix.BranchHints = PrefixBranchNotTaken;
    (*pMyDisasm).Prefix.BranchHintsState = SuperfluousPrefix;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 3Eh-Group 2
 * ==================================================================== */
void __bea_callspec__ PrefSEGDS(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Number++;
    if ((*pMyDisasm).Archi != 64) {
        (*pMyDisasm).Prefix.Segment = PrefixDS;
        (*pMyDisasm).Prefix.SegmentState = InUsePrefix;
    }
    (*pMyDisasm).Prefix.BranchHints = PrefixBranchTaken;
    (*pMyDisasm).Prefix.BranchHintsState = SuperfluousPrefix;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 26h-Group 2
 * ==================================================================== */
void __bea_callspec__ PrefSEGES(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Number++;
    if ((*pMyDisasm).Archi != 64) {
        (*pMyDisasm).Prefix.Segment = PrefixES;
        (*pMyDisasm).Prefix.SegmentState = InUsePrefix;
    }
    (*pMyDisasm).Prefix.BranchHintsState = NotUsedPrefix;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 64h-Group 2
 * ==================================================================== */
void __bea_callspec__ PrefSEGFS(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Number++;
    (*pMyDisasm).Prefix.Segment = PrefixFS;
    (*pMyDisasm).Prefix.SegmentState = InUsePrefix;
    (*pMyDisasm).Prefix.BranchHintsState = NotUsedPrefix;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 65h-Group 2
 * ==================================================================== */
void __bea_callspec__ PrefSEGGS(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Number++;
    (*pMyDisasm).Prefix.Segment = PrefixGS;
    (*pMyDisasm).Prefix.SegmentState = InUsePrefix;
    (*pMyDisasm).Prefix.BranchHintsState = NotUsedPrefix;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}


/* ====================================================================
 *      Legacy Prefix 36h-Group 2
 * ==================================================================== */
void __bea_callspec__ PrefSEGSS(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.Number++;
    if ((*pMyDisasm).Archi != 64) {
        (*pMyDisasm).Prefix.Segment = PrefixSS;
        (*pMyDisasm).Prefix.SegmentState = InUsePrefix;
    }
    (*pMyDisasm).Prefix.BranchHintsState = NotUsedPrefix;

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 66h-Group 3
 * ==================================================================== */
void __bea_callspec__ PrefOpSize(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.OperandSizeState = InUsePrefix;
    (*pMyDisasm).Prefix.Number++;
    if ((*pMyDisasm).Archi == 16) {
        (*pMyDisasm).Instruction.OperandSize = 32;
    }
    else {
        (*pMyDisasm).Instruction.OperandSize = 16;
    }

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 67h-Group 4
 * ==================================================================== */
void __bea_callspec__ PrefAdSize(PDISASM pMyDisasm)
{
    (*pMyDisasm).Prefix.AddressSizeState = InUsePrefix;
    (*pMyDisasm).Prefix.Number++;
    if ((*pMyDisasm).Archi == 32) {
        (*pMyDisasm).Instruction.AddressSize = 16;
    }
    else  {
        /* 16-bit and 64-bit architecture*/
        (*pMyDisasm).Instruction.AddressSize = 32;
    }

    if ((*pMyDisasm).Prefix.REXState == InUsePrefix) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = NotUsedPrefix;
        /* only 64-bit have REX prefix, so no need to check architecture */
        if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix)
            (*pMyDisasm).Instruction.OperandSize = 16;
        else
            (*pMyDisasm).Instruction.OperandSize = 32;
    }

    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
    (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Escape Prefix 0Fh-two bytes opcodes
 * ==================================================================== */
void __bea_callspec__ Esc_2byte(PDISASM pMyDisasm)
{
    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_)|0x0F00;
    (void) opcode_map2[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Escape Prefix 0F38h-three bytes opcodes
 * ==================================================================== */
void __bea_callspec__ Esc_tableA4(PDISASM pMyDisasm)
{
    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_)|0x0F3800;
    (void) opcode_map3[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}
/* ====================================================================
 *      Escape Prefix 0F3Ah-three bytes opcodes
 * ==================================================================== */
void __bea_callspec__ Esc_tableA5(PDISASM pMyDisasm)
{
    GV.EIP_++;
    if (!Security(1, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_)|0x0F3A00;
    (void) opcode_map4[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
}
