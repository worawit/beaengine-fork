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

/* Define prefix GV aka GlobalVariable - used instead of global internal variables to make BeaEngine thread-safe  */

#define GV (*pMyDisasm).Reserved_

/* Define constants to identify the position and type of decoration used in case of memory argument */

#define     Arg1byte        1
#define     Arg1word        2
#define     Arg1dword       3
#define     Arg1qword       4
#define     Arg1multibytes  5
#define     Arg1tbyte       6
#define     Arg1fword       7
#define     Arg1dqword      8

#define     Arg2byte        101
#define     Arg2word        102
#define     Arg2dword       103
#define     Arg2qword       104
#define     Arg2multibytes  105
#define     Arg2tbyte       106
#define     Arg2fword       107
#define     Arg2dqword      108

/* BSCAN (Bit Scan) - BSF/BSR
 * BTEST (Bit Test) - BT/BTS/BTR/BTC
 */
#define EFLAGS_MAP_DEF_A_B \
    EFLAGS_DEF( EFLAGS_AAA,     {UN_, UN_, UN_, MO_, UN_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_AAD,     {UN_, MO_, MO_, UN_, MO_, UN_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_AAM,     {UN_, MO_, MO_, UN_, MO_, UN_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_AAS,     {UN_, UN_, UN_, MO_, UN_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ADC,     {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ADD,     {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_AND,     {RE_, MO_, MO_, UN_, MO_, RE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ARPL,    {0  , 0  , MO_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_BOUND,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_BSCAN,   {UN_, UN_, MO_, UN_, UN_, UN_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_BSWAP,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_BTEST,   {UN_, UN_, UN_, UN_, UN_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \

/* ccXX - for conditional instructions
 *        (use cc as lowercase to make sure it never get conficted)
 */
#define EFLAGS_MAP_DEF_C_D \
    EFLAGS_DEF( EFLAGS_CALL,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CBW,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccE,     {0  , 0  , TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccNE,    {0  , 0  , TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccA,     {0  , 0  , TE_, 0  , 0  , TE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccAE,    {0  , 0  , 0  , 0  , 0  , TE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccB,     {0  , 0  , 0  , 0  , 0  , TE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccBE,    {0  , 0  , TE_, 0  , 0  , TE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccO,     {TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccNO,    {TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccS,     {0  , TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccNS,    {0  , TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccP,     {0  , 0  , 0  , 0  , TE_, 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccNP,    {0  , 0  , 0  , 0  , TE_, 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccG,     {TE_, TE_, TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccGE,    {TE_, TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccL,     {TE_, TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ccLE,    {TE_, TE_, TE_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CLC,     {0  , 0  , 0  , 0  , 0  , RE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CLD,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , RE_, 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CLI,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , RE_, 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CLTS,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CMC,     {0  , 0  , 0  , 0  , 0  , MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CMP,     {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CMPS,    {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CMPXCHG, {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CMPXCHGG8B,{0  , 0  , MO_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_COMSID,  {RE_, RE_, MO_, RE_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_COMISS,  {RE_, RE_, MO_, RE_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CPUID,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_CWD,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_DAA,     {UN_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_DAS,     {UN_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_DEC,     {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_DIV,     {UN_, UN_, UN_, UN_, UN_, UN_, 0  , 0  , 0  , 0  , 0, 0} ), \

/* FCMP (Floating Point Compare) - FCOMI FCOMIP FUCMI FUCMIP
 */
#define EFLAGS_MAP_DEF_E_J \
    EFLAGS_DEF( EFLAGS_ENTER,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ESC,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_FCMOV,   {0  , 0  , TE_, 0  , TE_, TE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_FCMP,    {0  , 0  , MO_, 0  , MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_HLT,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_IDIV,    {UN_, UN_, UN_, UN_, UN_, UN_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_IMUL,    {MO_, UN_, UN_, UN_, UN_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_IN,      {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_INC,     {MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_INS,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , TE_, 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_INT,     {0  , 0  , 0  , 0  , 0  , 0  , RE_, 0  , 0  , RE_, 0, 0} ), \
    EFLAGS_DEF( EFLAGS_INTO,    {TE_, 0  , 0  , 0  , 0  , 0  , RE_, 0  , 0  , RE_, 0, 0} ), \
    EFLAGS_DEF( EFLAGS_INVD,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_INVLPG,  {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_UCOMSID, {RE_, RE_, MO_, RE_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_UCOMISS, {RE_, RE_, MO_, RE_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_IRET,    {PR_, PR_, PR_, PR_, PR_, PR_, PR_, PR_, PR_, TE_, 0, 0} ), \
    EFLAGS_DEF( EFLAGS_JCXZ,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_JMP,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    
/* LFAR (Load Far Pointer) - LDS LES LSS LFS LGS
 * LxDT (Load Descriptor Table) - LGDT LIDT LLDT LMSW
 * LOOPc (Loop Condition) - use ccXX
 * MOVCRDR - MOV control, debug, test
 */
#define EFLAGS_MAP_DEF_L_N \
    EFLAGS_DEF( EFLAGS_LAHF,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LAR,     {0  , 0  , MO_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LFAR,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LEA,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LEAVE,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LxDT,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LOCK,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LODS,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , TE_, 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LOOP,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LSL,     {0  , 0  , MO_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_LTR,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_MONITOR, {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_MWAIT,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_MOV,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_MOVCRDR, {UN_, UN_, UN_, UN_, UN_, UN_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_MOVS,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , TE_, 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_MOVSX,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_MUL,     {MO_, UN_, UN_, UN_, UN_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_NEG,     {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_NOP,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_NOT,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \

/* POP - POP POPA
 * PUSH - PUSH PUSHA PUSHF
 * REP - REP REPE REPNE
 * ROTC1 (Rotate Carry 1 bit) - RCL RCR 1
 * ROTC (Rotate Carry n bit) - RCL RCR
 * ROT1 (Rotate 1 bit) - ROL ROR 1
 * ROT (Rotate n bit) - ROL ROR
 */
#define EFLAGS_MAP_DEF_O_R \
    EFLAGS_DEF( EFLAGS_OR,      {RE_, MO_, MO_, UN_, MO_, RE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_OUT,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_OUTS,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , TE_, 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_POP,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_POPCNT,  {RE_, RE_, MO_, RE_, RE_, RE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_POPF,    {PR_, PR_, PR_, PR_, PR_, PR_, PR_, PR_, PR_, PR_, 0, 0} ), \
    EFLAGS_DEF( EFLAGS_PUSH,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ROTC1,   {MO_, 0  , 0  , 0  , 0  , MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ROTC,    {UN_, 0  , 0  , 0  , 0  , MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_RDMSR,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_RDPMC,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_RDTSC,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_REP,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_RET,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ROT1,    {MO_, 0  , 0  , 0  , 0  , MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_ROT,     {UN_, 0  , 0  , 0  , 0  , MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_RSM,     {MO_, MO_, MO_, MO_, MO_, MO_, MO_, MO_, MO_, MO_, MO_, 0} ), \

/* SHIFT1 (Shift 1 bit) - SAL SAR SHL SHR 1
 * SHIFT (Shift n bit) - SAL SAR SHL SHR
 * SxDT (Store Descriptor Table) - SGDT SIDT SLDT SMSW
 * SHIFTDP (Shift Double Precision) - SHLD SHRD
 * SETcc - use ccXX
 * VERR (Verify Segment) - VERR VERW
 */
#define EFLAGS_MAP_DEF_S_Z \
    EFLAGS_DEF( EFLAGS_SAHF,    {0  , PR_, PR_, PR_, PR_, PR_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_SHIFT1,  {MO_, MO_, MO_, 0  , MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_SHIFT,   {0  , MO_, MO_, 0  , MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_SBB,     {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_SCAS,    {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_SxDT,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_SHIFTDP, {UN_, MO_, MO_, UN_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_STC,     {0  , 0  , 0  , 0  , 0  , SE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_STD,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , SE_, 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_STI,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , SE_, 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_STOS,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_STR,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_SUB,     {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_TEST,    {RE_, MO_, MO_, UN_, MO_, RE_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_UD2,     {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_VERR,    {0  , 0  , MO_, 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_WAIT,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_WBINVD,  {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_WRMSR,   {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_XADD,    {MO_, MO_, MO_, MO_, MO_, MO_, 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_XCHG,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_XLAT,    {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0, 0} ), \
    EFLAGS_DEF( EFLAGS_XOR,     {RE_, MO_, MO_, UN_, MO_, RE_, 0  , 0  , 0  , 0  , 0, 0} ), \

#define EFLAGS_MAP_DEF EFLAGS_MAP_DEF_A_B EFLAGS_MAP_DEF_C_D \
    EFLAGS_MAP_DEF_E_J EFLAGS_MAP_DEF_L_N EFLAGS_MAP_DEF_O_R EFLAGS_MAP_DEF_S_Z
    
#define EFLAGS_DEF(id, ...) id
enum EFLAGS_ENUM { EFLAGS_MAP_DEF };
#undef EFLAGS_DEF
#define EFLAGS_DEF(id, ...) __VA_ARGS__
EFLStruct EFLAGS_TABLE[] = { EFLAGS_MAP_DEF };

/* =====================================================
 * To make a tabulation between mnemonic and first argument
 * ===================================================== */
char space_tab[11][16] = {
    " ",
    "  ",
    "   ",
    "    ",
    "     ",
    "      ",
    "       ",
    "        ",
    "         ",
    "          ",
    "           ",

};
/* =====================================================
 * Segment registers
 * ===================================================== */
char SegmentRegs[7][4] = {
    "??:",      /* +0 */
    "es:",      /* +1 */
    "ds:",      /* +2 */
    "fs:",      /* +3 */
    "gs:",      /* +4 */
    "cs:",      /* +5 */
    "ss:",      /* +6 */
};
/* =====================================================
 * AT&T Suffixes
 * ===================================================== */
char ATSuffixes[8][4] = {
    "b ",     /* GV.MemDecoration == 1 */
    "w ",     /* GV.MemDecoration == 2 */
    "l ",     /* GV.MemDecoration == 3 */
    "q ",     /* GV.MemDecoration == 4 */
    " ",      /* GV.MemDecoration == 5 (multibytes) */
    "t ",     /* GV.MemDecoration == 6 */
    " ",      /* GV.MemDecoration == 7 (fword) */
    " ",      /* GV.MemDecoration == 8 (dqword) */
};

/* =====================================================
 * MASM Prefixes for MemoryType
 * ===================================================== */

char MasmPrefixes[8][16] = {
    "byte ptr ",        /* GV.MemDecoration == 1 */
    "word ptr ",        /* GV.MemDecoration == 2 */
    "dword ptr ",       /* GV.MemDecoration == 3 */
    "qword ptr ",       /* GV.MemDecoration == 4 */
    " ",                /* GV.MemDecoration == 5 (multibytes) */
    "tbyte ptr ",       /* GV.MemDecoration == 6 */
    "fword ptr ",       /* GV.MemDecoration == 7 (fword) */
    "dqword ptr ",      /* GV.MemDecoration == 8 (dqword) */
};

/* =====================================================
 * NASM Prefixes for MemoryType
 * ===================================================== */
char NasmPrefixes[8][8] = {
    "byte ",      /* GV.MemDecoration == 1 */
    "word ",      /* GV.MemDecoration == 2 */
    "dword ",     /* GV.MemDecoration == 3 */
    "qword ",     /* GV.MemDecoration == 4 */
    " ",          /* GV.MemDecoration == 5 (multibytes) */
    "tword ",     /* GV.MemDecoration == 6 */
    " ",          /* GV.MemDecoration == 7 (fword) */
    " ",          /* GV.MemDecoration == 8 (dqword) */
};



/* =====================================================
 * GOASM Prefixes for MemoryType
 * ===================================================== */
char GoAsmPrefixes[8][4] = {
    "b ",     /* GV.MemDecoration == 1 */
    "w ",     /* GV.MemDecoration == 2 */
    "d ",     /* GV.MemDecoration == 3 */
    "q ",     /* GV.MemDecoration == 4 */
    " ",      /* GV.MemDecoration == 5 (multibytes) */
    "t ",     /* GV.MemDecoration == 6 */
    " ",      /* GV.MemDecoration == 7 (fword) */
    " ",      /* GV.MemDecoration == 8 (dqword) */
};


/* =====================================================
 * Segment registers
 * ===================================================== */
char RegistersSEG[16][8] = {
    "es",      /* +0 */
    "cs",      /* +1 */
    "ss",      /* +2 */
    "ds",      /* +3 */
    "fs",      /* +4 */
    "gs",      /* +5 */
    "seg?",
    "seg?",
    "seg?",
    "seg?",
    "seg?",
    "seg?",
    "seg?",
    "seg?",
    "seg?",
    "seg?",
};

/* =====================================================
 * FPU Registers
 * ===================================================== */
char RegistersFPU_Masm[8][8] = {
    "st(0)",      /* +0 */
    "st(1)",      /* +1 */
    "st(2)",      /* +2 */
    "st(3)",      /* +3 */
    "st(4)",      /* +4 */
    "st(5)",      /* +5 */
    "st(6)",      /* +6 */
    "st(7)",      /* +7 */
};

char RegistersFPU_Nasm[8][8] = {
    "st0",      /* +0 */
    "st1",      /* +1 */
    "st2",      /* +2 */
    "st3",      /* +3 */
    "st4",      /* +4 */
    "st5",      /* +5 */
    "st6",      /* +6 */
    "st7",      /* +7 */
};

/* =====================================================
 * debug registers
 * ===================================================== */
char RegistersDR[16][8] = {
    "dr0",      /* +0 */
    "dr1",      /* +1 */
    "dr2",      /* +2 */
    "dr3",      /* +3 */
    "dr4",      /* +4 */
    "dr5",      /* +5 */
    "dr6",      /* +6 */
    "dr7",      /* +7 */
    "dr8",       /* +8 */
    "dr9",       /* +9 */
    "dr10",      /* +10 */
    "dr11",      /* +11 */
    "dr12",      /* +12 */
    "dr13",      /* +13 */
    "dr14",      /* +14 */
    "dr15",      /* +15 */
};

/* =====================================================
 * debug registers-AT&T syntax
 * ===================================================== */
char RegistersDR_AT[16][8] = {
    "db0",      /* +0 */
    "db1",      /* +1 */
    "db2",      /* +2 */
    "db3",      /* +3 */
    "db4",      /* +4 */
    "db5",      /* +5 */
    "db6",      /* +6 */
    "db7",      /* +7 */
    "db8",       /* +8 */
    "db9",       /* +9 */
    "db10",      /* +10 */
    "db11",      /* +11 */
    "db12",      /* +12 */
    "db13",      /* +13 */
    "db14",      /* +14 */
    "db15",      /* +15 */
};


/* =====================================================
 * control registers
 * ===================================================== */
char RegistersCR[16][8] = {
    "cr0",      /* +0 */
    "cr1",      /* +1 */
    "cr2",      /* +2 */
    "cr3",      /* +3 */
    "cr4",      /* +4 */
    "cr5",      /* +5 */
    "cr6",      /* +6 */
    "cr7",      /* +7 */
    "cr8",       /* +8 */
    "cr9",       /* +9 */
    "cr10",      /* +10 */
    "cr11",      /* +11 */
    "cr12",      /* +12 */
    "cr13",      /* +13 */
    "cr14",      /* +14 */
    "cr15",      /* +15 */
};



/* =====================================================
 * 64 bits registers
 * ===================================================== */
char Registers64Bits[16][4] = {
    "rax",      /* +0 */
    "rcx",      /* +1 */
    "rdx",      /* +2 */
    "rbx",      /* +3 */
    "rsp",      /* +4 */
    "rbp",      /* +5 */
    "rsi",      /* +6 */
    "rdi",      /* +7 */
    "r8",       /* +8 */
    "r9",       /* +9 */
    "r10",      /* +10 */
    "r11",      /* +11 */
    "r12",      /* +12 */
    "r13",      /* +13 */
    "r14",      /* +14 */
    "r15",      /* +15 */
};

/* =====================================================
 * 32 bits registers
 * ===================================================== */
char Registers32Bits[16][8] = {
    "eax",
    "ecx",
    "edx",
    "ebx",
    "esp",
    "ebp",
    "esi",
    "edi",
    "r8d",
    "r9d",
    "r10d",
    "r11d",
    "r12d",
    "r13d",
    "r14d",
    "r15d",
};

/* =====================================================
 * 16 bits registers
 * ===================================================== */
char Registers16Bits[16][8] = {
    "ax",
    "cx",
    "dx",
    "bx",
    "sp",
    "bp",
    "si",
    "di",
    "r8w",
    "r9w",
    "r10w",
    "r11w",
    "r12w",
    "r13w",
    "r14w",
    "r15w",
};
/* =====================================================
 * 8 bits registers
 * ===================================================== */
char Registers8BitsLegacy[8][4] = {
    "al",
    "cl",
    "dl",
    "bl",
    "ah",
    "ch",
    "dh",
    "bh",
};

Int32 REGS8BITS[] = {
    REG0,
    REG1,
    REG2,
    REG3,
    REG0,
    REG1,
    REG2,
    REG3,
};

/* =====================================================
 * 8 bits registers
 * ===================================================== */
char Registers8Bits[16][8] = {
    "al",
    "cl",
    "dl",
    "bl",
    "spl",
    "bpl",
    "sil",
    "dil",
    "r8L",
    "r9L",
    "r10L",
    "r11L",
    "r12L",
    "r13L",
    "r14L",
    "r15L",
};
/* =====================================================
 * MMX Registers
 * ===================================================== */
char RegistersMMX[8][4] = {
    "mm0",
    "mm1",
    "mm2",
    "mm3",
    "mm4",
    "mm5",
    "mm6",
    "mm7",
};

/* =====================================================
 * SSE Registers
 * ===================================================== */
char RegistersSSE[16][8] = {
    "xmm0",
    "xmm1",
    "xmm2",
    "xmm3",
    "xmm4",
    "xmm5",
    "xmm6",
    "xmm7",
    "xmm8",     /* SSE3, SSSE3, SSE4 */
    "xmm9",     /* SSE3, SSSE3, SSE4 */
    "xmm10",    /* SSE3, SSSE3, SSE4 */
    "xmm11",    /* SSE3, SSSE3, SSE4 */
    "xmm12",    /* SSE3, SSSE3, SSE4 */
    "xmm13",    /* SSE3, SSSE3, SSE4 */
    "xmm14",    /* SSE3, SSSE3, SSE4 */
    "xmm15",    /* SSE3, SSSE3, SSE4 */
};

Int32 REGS[] = {
    REG0,        /* REG0 */
    REG1,        /* REG1 */
    REG2,        /* REG2 */
    REG3,        /* REG3 */
    REG4,       /* REG4 */
    REG5,       /* REG5 */
    REG6,       /* REG6 */
    REG7,       /* REG7 */
    REG8,      /* REG8 */
    REG9,      /* REG9 */
    REG10,      /* REG10 */
    REG11,      /* REG11 */
    REG12,     /* REG12 */
    REG13,     /* REG13 */
    REG14,     /* REG14 */
    REG15,     /* REG15 */
};

char BXSI_[] = "bx+si";
char BXDI_[] = "bx+di";
char BPSI_[] = "bp+si";
char BPDI_[] = "bp+di";



