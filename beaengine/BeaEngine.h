#ifndef _BEA_ENGINE_
#define _BEA_ENGINE_
#if  defined(__cplusplus) && defined(__BORLANDC__)
namespace BeaEngine {
#endif

#include <beaengine/macros.h>
#include <beaengine/export.h>
#include <beaengine/basic_types.h>

#if !defined(BEA_ENGINE_STATIC)
	#if defined(BUILD_BEA_ENGINE_DLL)
		#define BEA_API bea__api_export__
	#else
		#define BEA_API bea__api_import__
	#endif
#else
	#define BEA_API
#endif


#define INSTRUCT_LENGTH 64

#pragma pack(1)
typedef struct {
   UInt8 W_;
   UInt8 R_;
   UInt8 X_;
   UInt8 B_;
   UInt8 state;
} REX_Struct  ;
#pragma pack()

#pragma pack(1)
typedef struct {
   int Number;
   int NbUndefined;
   UInt8 LockPrefix;
   UInt8 OperandSize;
   UInt8 AddressSize;
   UInt8 RepnePrefix;
   UInt8 RepPrefix;
   UInt8 FSPrefix;
   UInt8 SSPrefix;
   UInt8 GSPrefix;
   UInt8 ESPrefix;
   UInt8 CSPrefix;
   UInt8 DSPrefix;
   UInt8 BranchTaken;
   UInt8 BranchNotTaken;
   REX_Struct REX;
} PREFIXINFO  ;
#pragma pack()

#pragma pack(1)
typedef struct {
   UInt8 OF_;
   UInt8 SF_;
   UInt8 ZF_;
   UInt8 AF_;
   UInt8 PF_;
   UInt8 CF_;
   UInt8 TF_;
   UInt8 IF_;
   UInt8 DF_;
   UInt8 NT_;
   UInt8 RF_;
   UInt8 alignment;
} EFLStruct  ;
#pragma pack()

#pragma pack(4)
typedef struct {
   Int32 BaseRegister;
   Int32 IndexRegister;
   Int32 Scale;
   Int64 Displacement;
} MEMORYTYPE ;
#pragma pack()


#pragma pack(1)
typedef struct  {
   Int32 Category;
   Int32 Opcode;
   char Mnemonic[16];
   Int32 MnemonicId;
   Int32 BranchType;
   EFLStruct Flags;
   UInt32 ImplicitModifiedRegs;
   UInt64 AddrValue;
   Int64 Immediat;
} INSTRTYPE;
#pragma pack()

#pragma pack(1)
typedef struct  {
   char ArgMnemonic[32];
   Int32 ArgType;
   Int32 ArgSize;
   Int32 ArgPosition;
   UInt32 AccessMode;
   UInt32 SegmentReg;
   MEMORYTYPE Memory;
} ARGTYPE;
#pragma pack()

/* reserved structure used for thread-safety */
/* unusable by customer */
#pragma pack(1)
typedef struct {
   UIntPtr EIP_;
   UInt64 EIP_VA;
   UIntPtr EIP_REAL;
   Int32 OriginalOperandSize;
   Int32 OperandSize;
   Int32 MemDecoration;
   Int32 AddressSize;
   Int32 MOD_;
   Int32 RM_;
   Int32 INDEX_;
   Int32 SCALE_;
   Int32 BASE_;
   Int32 MMX_;
   Int32 SSE_;
   Int32 CR_;
   Int32 DR_;
   Int32 SEG_;
   Int32 REGOPCODE;
   UInt32 DECALAGE_EIP;
   Int32 FORMATNUMBER;
   Int32 SYNTAX_;
   UInt64 EndOfBlock;
   Int32 RelativeAddress;
   UInt32 Architecture;
   Int32 ImmediatSize;
   Int32 NB_PREFIX;
   Int32 PrefRepe;
   Int32 PrefRepne;
   UInt32 SEGMENTREGS;
   UInt32 SEGMENTFS;
   Int32 third_arg;
   Int32 TAB_;
   Int32 ERROR_OPCODE;
   Int32 OutOfBlock;
   REX_Struct REX;
} InternalDatas;
#pragma pack()

/* ************** main structure ************ */
#pragma pack(1)
typedef struct _Disasm {
   UIntPtr EIP;
   UInt64 VirtualAddr;
   UInt32 SecurityBlock;
   char CompleteInstr[INSTRUCT_LENGTH];
   UInt32 Archi;
   UInt64 Options;
   INSTRTYPE Instruction;
   ARGTYPE Argument1;
   ARGTYPE Argument2;
   ARGTYPE Argument3;
   PREFIXINFO Prefix;
   char alignments[6];
   InternalDatas Reserved_;
} DISASM, *PDISASM, *LPDISASM;
#pragma pack()

#define ESReg 1
#define DSReg 2
#define FSReg 3
#define GSReg 4
#define CSReg 5
#define SSReg 6

#define InvalidPrefix 4
#define SuperfluousPrefix 2
#define NotUsedPrefix 0
#define MandatoryPrefix 8
#define InUsePrefix 1

#define LowPosition 0
#define HighPosition 1

enum INSTRUCTION_TYPE
{
  GENERAL_PURPOSE_INSTRUCTION   =    0x10000,
  FPU_INSTRUCTION               =    0x20000,
  MMX_INSTRUCTION               =    0x40000,
  SSE_INSTRUCTION               =    0x80000,
  SSE2_INSTRUCTION              =   0x100000,
  SSE3_INSTRUCTION              =   0x200000,
  SSSE3_INSTRUCTION             =   0x400000,
  SSE41_INSTRUCTION             =   0x800000,
  SSE42_INSTRUCTION             =  0x1000000,
  SYSTEM_INSTRUCTION            =  0x2000000,
  VM_INSTRUCTION                =  0x4000000,
  UNDOCUMENTED_INSTRUCTION      =  0x8000000,
  AMD_INSTRUCTION               = 0x10000000,
  ILLEGAL_INSTRUCTION           = 0x20000000,
  AES_INSTRUCTION               = 0x40000000,
  CLMUL_INSTRUCTION             = (int)0x80000000,


    DATA_TRANSFER = 0x1,
    ARITHMETIC_INSTRUCTION,
    LOGICAL_INSTRUCTION,
    SHIFT_ROTATE,
    BIT_UInt8,
    CONTROL_TRANSFER,
    STRING_INSTRUCTION,
    InOutINSTRUCTION,
    ENTER_LEAVE_INSTRUCTION,
    FLAG_CONTROL_INSTRUCTION,
    SEGMENT_REGISTER,
    MISCELLANEOUS_INSTRUCTION,
    COMPARISON_INSTRUCTION,
    LOGARITHMIC_INSTRUCTION,
    TRIGONOMETRIC_INSTRUCTION,
    UNSUPPORTED_INSTRUCTION,
    LOAD_CONSTANTS,
    FPUCONTROL,
    STATE_MANAGEMENT,
    CONVERSION_INSTRUCTION,
    SHUFFLE_UNPACK,
    PACKED_SINGLE_PRECISION,
    SIMD128bits,
    SIMD64bits,
    CACHEABILITY_CONTROL,
    FP_INTEGER_CONVERSION,
    SPECIALIZED_128bits,
    SIMD_FP_PACKED,
    SIMD_FP_HORIZONTAL ,
    AGENT_SYNCHRONISATION,
    PACKED_ALIGN_RIGHT  ,
    PACKED_SIGN,
    PACKED_BLENDING_INSTRUCTION,
    PACKED_TEST,
    PACKED_MINMAX,
    HORIZONTAL_SEARCH,
    PACKED_EQUALITY,
    STREAMING_LOAD,
    INSERTION_EXTRACTION,
    DOT_PRODUCT,
    SAD_INSTRUCTION,
    ACCELERATOR_INSTRUCTION,    /* crc32, popcnt (sse4.2) */
    ROUND_INSTRUCTION

};

enum EFLAGS_STATES
{
  TE_ = 1,
  MO_ = 2,
  RE_ = 4,
  SE_ = 8,
  UN_ = 0x10,
  PR_ = 0x20
};

enum BRANCH_TYPE
{
  JO = 1,
  JC,
  JE,
  JA,
  JS,
  JP,
  JL,
  JG,
  JB,
  JECXZ,
  JmpType,
  CallType,
  RetType,
  JNO = -1,
  JNC = -2,
  JNE = -3,
  JNA = -4,
  JNS = -5,
  JNP = -6,
  JNL = -7,
  JNG = -8,
  JNB = -9
};

enum ARGUMENTS_TYPE
{
  NO_ARGUMENT = 0,
  REGISTER_TYPE = 0x20000000,
  MEMORY_TYPE = 0x40000000,
  CONSTANT_TYPE = (int)0x80000000,

  IMPLICIT_ARG = 0x10000000,

  /* value for register type */
  MMX_REG = 0x10000,
  GENERAL_REG = 0x20000,
  FPU_REG = 0x40000,
  SSE_REG = 0x80000,
  CR_REG = 0x100000,
  DR_REG = 0x200000,
  SPECIAL_REG = 0x400000,
  MEMORY_MANAGEMENT_REG = 0x800000,
  SEGMENT_REG = 0x1000000,

  /* value for constant type */
  RELATIVE_ = 0x10000,
  ABSOLUTE_ = 0x20000,

  /* argument access mode */
  READ = 0x1,
  WRITE = 0x2,

  REG0 = 0x1,
  REG1 = 0x2,
  REG2 = 0x4,
  REG3 = 0x8,
  REG4 = 0x10,
  REG5 = 0x20,
  REG6 = 0x40,
  REG7 = 0x80,
  REG8 = 0x100,
  REG9 = 0x200,
  REG10 = 0x400,
  REG11 = 0x800,
  REG12 = 0x1000,
  REG13 = 0x2000,
  REG14 = 0x4000,
  REG15 = 0x8000
};

enum SPECIAL_INFO
{
  UNKNOWN_OPCODE = -1,
  OUT_OF_BLOCK = 0,

  /* === mask = 0xff */
  NoTabulation      = 0x00000000,
  Tabulation        = 0x00000001,

  /* === mask = 0xff00 */
  MasmSyntax        = 0x00000000,
  GoAsmSyntax       = 0x00000100,
  NasmSyntax        = 0x00000200,
  ATSyntax          = 0x00000400,

  /* === mask = 0xff0000 */
  PrefixedNumeral   = 0x00010000,
  SuffixedNumeral   = 0x00000000,

  /* === mask = 0xff000000 */
  ShowSegmentRegs   = 0x01000000
};

#define MNEMONIC_MAP_DEF \
    MNEMONIC_DEF( I_INVALID, "" ), \
    MNEMONIC_DEF( I_AAA, "aaa" ), \
    MNEMONIC_DEF( I_AAD, "aad" ), \
    MNEMONIC_DEF( I_AAM, "aam" ), \
    MNEMONIC_DEF( I_AAS, "aas" ), \
    MNEMONIC_DEF( I_ADC, "adc" ), \
    MNEMONIC_DEF( I_ADD, "add" ), \
    MNEMONIC_DEF( I_ADDPD, "addpd" ), \
    MNEMONIC_DEF( I_ADDPS, "addps" ), \
    MNEMONIC_DEF( I_ADDSD, "addsd" ), \
    MNEMONIC_DEF( I_ADDSS, "addss" ), \
    MNEMONIC_DEF( I_ADDSUBPD, "addsubpd" ), \
    MNEMONIC_DEF( I_ADDSUBPS, "addsubps" ), \
    MNEMONIC_DEF( I_AESDEC, "aesdec" ), \
    MNEMONIC_DEF( I_AESDECLAST, "aesdeclast" ), \
    MNEMONIC_DEF( I_AESENC, "aesenc" ), \
    MNEMONIC_DEF( I_AESENCLAST, "aesenclast" ), \
    MNEMONIC_DEF( I_AESIMC, "aesimc" ), \
    MNEMONIC_DEF( I_AESKEYGENASSIST, "aeskeygenassist" ), \
    MNEMONIC_DEF( I_AND, "and" ), \
    MNEMONIC_DEF( I_ANDNPD, "andnpd" ), \
    MNEMONIC_DEF( I_ANDNPS, "andnps" ), \
    MNEMONIC_DEF( I_ANDPD, "andpd" ), \
    MNEMONIC_DEF( I_ANDPS, "andps" ), \
    MNEMONIC_DEF( I_ARPL, "arpl" ), \
    MNEMONIC_DEF( I_BLENDPD, "blendpd" ), \
    MNEMONIC_DEF( I_BLENDPS, "blendps" ), \
    MNEMONIC_DEF( I_BLENDVPD, "blendvpd" ), \
    MNEMONIC_DEF( I_BLENDVPS, "blendvps" ), \
    MNEMONIC_DEF( I_BOUND, "bound" ), \
    MNEMONIC_DEF( I_BSF, "bsf" ), \
    MNEMONIC_DEF( I_BSR, "bsr" ), \
    MNEMONIC_DEF( I_BSWAP, "bswap" ), \
    MNEMONIC_DEF( I_BT, "bt" ), \
    MNEMONIC_DEF( I_BTC, "btc" ), \
    MNEMONIC_DEF( I_BTR, "btr" ), \
    MNEMONIC_DEF( I_BTS, "bts" ), \
    MNEMONIC_DEF( I_CALL, "call" ), \
    MNEMONIC_DEF( I_CALL_FAR, "call far" ), \
    MNEMONIC_DEF( I_CBW, "cbw" ), \
    MNEMONIC_DEF( I_CDQ, "cdq" ), \
    MNEMONIC_DEF( I_CDQE, "cdqe" ), \
    MNEMONIC_DEF( I_CLC, "clc" ), \
    MNEMONIC_DEF( I_CLD, "cld" ), \
    MNEMONIC_DEF( I_CLFLUSH, "clflush" ), \
    MNEMONIC_DEF( I_CLGI, "clgi" ), \
    MNEMONIC_DEF( I_CLI, "cli" ), \
    MNEMONIC_DEF( I_CLTS, "clts" ), \
    MNEMONIC_DEF( I_CMC, "cmc" ), \
    MNEMONIC_DEF( I_CMOVA, "cmova" ), \
    MNEMONIC_DEF( I_CMOVAE, "cmovae" ), \
    MNEMONIC_DEF( I_CMOVB, "cmovb" ), \
    MNEMONIC_DEF( I_CMOVBE, "cmovbe" ), \
    MNEMONIC_DEF( I_CMOVE, "cmove" ), \
    MNEMONIC_DEF( I_CMOVG, "cmovg" ), \
    MNEMONIC_DEF( I_CMOVGE, "cmovge" ), \
    MNEMONIC_DEF( I_CMOVL, "cmovl" ), \
    MNEMONIC_DEF( I_CMOVLE, "cmovle" ), \
    MNEMONIC_DEF( I_CMOVNE, "cmovne" ), \
    MNEMONIC_DEF( I_CMOVNO, "cmovno" ), \
    MNEMONIC_DEF( I_CMOVNP, "cmovnp" ), \
    MNEMONIC_DEF( I_CMOVNS, "cmovns" ), \
    MNEMONIC_DEF( I_CMOVO, "cmovo" ), \
    MNEMONIC_DEF( I_CMOVP, "cmovp" ), \
    MNEMONIC_DEF( I_CMOVS, "cmovs" ), \
    MNEMONIC_DEF( I_CMP, "cmp" ), \
    MNEMONIC_DEF( I_CMPPD, "cmppd" ), \
    MNEMONIC_DEF( I_CMPPS, "cmpps" ), \
    MNEMONIC_DEF( I_CMPSB, "cmpsb" ), \
    MNEMONIC_DEF( I_CMPSD, "cmpsd" ), \
    MNEMONIC_DEF( I_CMPSQ, "cmpsq" ), \
    MNEMONIC_DEF( I_CMPSS, "cmpss" ), \
    MNEMONIC_DEF( I_CMPSW, "cmpsw" ), \
    MNEMONIC_DEF( I_CMPXCHG, "cmpxchg" ), \
    MNEMONIC_DEF( I_CMPXCHG16B, "cmpxchg16b" ), \
    MNEMONIC_DEF( I_CMPXCHG8B, "cmpxchg8b" ), \
    MNEMONIC_DEF( I_COMISD, "comisd" ), \
    MNEMONIC_DEF( I_COMISS, "comiss" ), \
    MNEMONIC_DEF( I_CPUID, "cpuid" ), \
    MNEMONIC_DEF( I_CQO, "cqo" ), \
    MNEMONIC_DEF( I_CRC32, "crc32" ), \
    MNEMONIC_DEF( I_CVTDQ2PD, "cvtdq2pd" ), \
    MNEMONIC_DEF( I_CVTDQ2PS, "cvtdq2ps" ), \
    MNEMONIC_DEF( I_CVTPD2DQ, "cvtpd2dq" ), \
    MNEMONIC_DEF( I_CVTPD2PI, "cvtpd2pi" ), \
    MNEMONIC_DEF( I_CVTPD2PS, "cvtpd2ps" ), \
    MNEMONIC_DEF( I_CVTPI2PD, "cvtpi2pd" ), \
    MNEMONIC_DEF( I_CVTPI2PS, "cvtpi2ps" ), \
    MNEMONIC_DEF( I_CVTPS2DQ, "cvtps2dq" ), \
    MNEMONIC_DEF( I_CVTPS2PD, "cvtps2pd" ), \
    MNEMONIC_DEF( I_CVTPS2PI, "cvtps2pi" ), \
    MNEMONIC_DEF( I_CVTSD2SI, "cvtsd2si" ), \
    MNEMONIC_DEF( I_CVTSD2SS, "cvtsd2ss" ), \
    MNEMONIC_DEF( I_CVTSI2SD, "cvtsi2sd" ), \
    MNEMONIC_DEF( I_CVTSI2SS, "cvtsi2ss" ), \
    MNEMONIC_DEF( I_CVTSS2SD, "cvtss2sd" ), \
    MNEMONIC_DEF( I_CVTSS2SI, "cvtss2si" ), \
    MNEMONIC_DEF( I_CVTTPD2DQ, "cvttpd2dq" ), \
    MNEMONIC_DEF( I_CVTTPD2PI, "cvttpd2pi" ), \
    MNEMONIC_DEF( I_CVTTPS2DQ, "cvttps2dq" ), \
    MNEMONIC_DEF( I_CVTTPS2PI, "cvttps2pi" ), \
    MNEMONIC_DEF( I_CVTTSD2SI, "cvttsd2si" ), \
    MNEMONIC_DEF( I_CVTTSS2SI, "cvttss2si" ), \
    MNEMONIC_DEF( I_CWD, "cwd" ), \
    MNEMONIC_DEF( I_CWDE, "cwde" ), \
    MNEMONIC_DEF( I_DAA, "daa" ), \
    MNEMONIC_DEF( I_DAS, "das" ), \
    MNEMONIC_DEF( I_DEC, "dec" ), \
    MNEMONIC_DEF( I_DIV, "div" ), \
    MNEMONIC_DEF( I_DIVPD, "divpd" ), \
    MNEMONIC_DEF( I_DIVPS, "divps" ), \
    MNEMONIC_DEF( I_DIVSD, "divsd" ), \
    MNEMONIC_DEF( I_DIVSS, "divss" ), \
    MNEMONIC_DEF( I_DPPD, "dppd" ), \
    MNEMONIC_DEF( I_DPPS, "dpps" ), \
    MNEMONIC_DEF( I_EMMS, "emms" ), \
    MNEMONIC_DEF( I_ENTER, "enter" ), \
    MNEMONIC_DEF( I_EXTRACTPS, "extractps" ), \
    MNEMONIC_DEF( I_F2XM1, "f2xm1" ), \
    MNEMONIC_DEF( I_FABS, "fabs" ), \
    MNEMONIC_DEF( I_FADD, "fadd" ), \
    MNEMONIC_DEF( I_FADDP, "faddp" ), \
    MNEMONIC_DEF( I_FBLD, "fbld" ), \
    MNEMONIC_DEF( I_FBSTP, "fbstp" ), \
    MNEMONIC_DEF( I_FCHS, "fchs" ), \
    MNEMONIC_DEF( I_FCMOVB, "fcmovb" ), \
    MNEMONIC_DEF( I_FCMOVBE, "fcmovbe" ), \
    MNEMONIC_DEF( I_FCMOVE, "fcmove" ), \
    MNEMONIC_DEF( I_FCMOVNB, "fcmovnb" ), \
    MNEMONIC_DEF( I_FCMOVNBE, "fcmovnbe" ), \
    MNEMONIC_DEF( I_FCMOVNE, "fcmovne" ), \
    MNEMONIC_DEF( I_FCMOVNU, "fcmovnu" ), \
    MNEMONIC_DEF( I_FCMOVU, "fcmovu" ), \
    MNEMONIC_DEF( I_FCOM, "fcom" ), \
    MNEMONIC_DEF( I_FCOM2, "fcom2" ), \
    MNEMONIC_DEF( I_FCOMI, "fcomi" ), \
    MNEMONIC_DEF( I_FCOMIP, "fcomip" ), \
    MNEMONIC_DEF( I_FCOMP, "fcomp" ), \
    MNEMONIC_DEF( I_FCOMP3, "fcomp3" ), \
    MNEMONIC_DEF( I_FCOMP5, "fcomp5" ), \
    MNEMONIC_DEF( I_FCOMPP, "fcompp" ), \
    MNEMONIC_DEF( I_FCOS, "fcos" ), \
    MNEMONIC_DEF( I_FDECSTP, "fdecstp" ), \
    MNEMONIC_DEF( I_FDIV, "fdiv" ), \
    MNEMONIC_DEF( I_FDIVP, "fdivp" ), \
    MNEMONIC_DEF( I_FDIVR, "fdivr" ), \
    MNEMONIC_DEF( I_FDIVRP, "fdivrp" ), \
    MNEMONIC_DEF( I_FEMMS, "femms" ), \
    MNEMONIC_DEF( I_FFREE, "ffree" ), \
    MNEMONIC_DEF( I_FFREEP, "ffreep" ), \
    MNEMONIC_DEF( I_FIADD, "fiadd" ), \
    MNEMONIC_DEF( I_FICOM, "ficom" ), \
    MNEMONIC_DEF( I_FICOMP, "ficomp" ), \
    MNEMONIC_DEF( I_FIDIV, "fidiv" ), \
    MNEMONIC_DEF( I_FIDIVR, "fidivr" ), \
    MNEMONIC_DEF( I_FILD, "fild" ), \
    MNEMONIC_DEF( I_FIMUL, "fimul" ), \
    MNEMONIC_DEF( I_FINCSTP, "fincstp" ), \
    MNEMONIC_DEF( I_FIST, "fist" ), \
    MNEMONIC_DEF( I_FISTP, "fistp" ), \
    MNEMONIC_DEF( I_FISTTP, "fisttp" ), \
    MNEMONIC_DEF( I_FISUB, "fisub" ), \
    MNEMONIC_DEF( I_FISUBR, "fisubr" ), \
    MNEMONIC_DEF( I_FLD, "fld" ), \
    MNEMONIC_DEF( I_FLD1, "fld1" ), \
    MNEMONIC_DEF( I_FLDCW, "fldcw" ), \
    MNEMONIC_DEF( I_FLDENV, "fldenv" ), \
    MNEMONIC_DEF( I_FLDL2E, "fldl2e" ), \
    MNEMONIC_DEF( I_FLDL2T, "fldl2t" ), \
    MNEMONIC_DEF( I_FLDLG2, "fldlg2" ), \
    MNEMONIC_DEF( I_FLDLN2, "fldln2" ), \
    MNEMONIC_DEF( I_FLDPI, "fldpi" ), \
    MNEMONIC_DEF( I_FLDZ, "fldz" ), \
    MNEMONIC_DEF( I_FMUL, "fmul" ), \
    MNEMONIC_DEF( I_FMULP, "fmulp" ), \
    MNEMONIC_DEF( I_FNCLEX, "fnclex" ), \
    MNEMONIC_DEF( I_FNDISI, "fndisi" ), \
    MNEMONIC_DEF( I_FNENI, "fneni" ), \
    MNEMONIC_DEF( I_FNINIT, "fninit" ), \
    MNEMONIC_DEF( I_FNOP, "fnop" ), \
    MNEMONIC_DEF( I_FNSETPM, "fnsetpm" ), \
    MNEMONIC_DEF( I_FPATAN, "fpatan" ), \
    MNEMONIC_DEF( I_FPREM, "fprem" ), \
    MNEMONIC_DEF( I_FPREM1, "fprem1" ), \
    MNEMONIC_DEF( I_FPTAN, "fptan" ), \
    MNEMONIC_DEF( I_FRNDINT, "frndint" ), \
    MNEMONIC_DEF( I_FRSTOR, "frstor" ), \
    MNEMONIC_DEF( I_FRSTPM, "frstpm" ), \
    MNEMONIC_DEF( I_FSAVE, "fsave" ), \
    MNEMONIC_DEF( I_FSCALE, "fscale" ), \
    MNEMONIC_DEF( I_FSIN, "fsin" ), \
    MNEMONIC_DEF( I_FSINCOS, "fsincos" ), \
    MNEMONIC_DEF( I_FSQRT, "fsqrt" ), \
    MNEMONIC_DEF( I_FST, "fst" ), \
    MNEMONIC_DEF( I_FSTCW, "fstcw" ), \
    MNEMONIC_DEF( I_FSTENV, "fstenv" ), \
    MNEMONIC_DEF( I_FSTP, "fstp" ), \
    MNEMONIC_DEF( I_FSTP1, "fstp1" ), \
    MNEMONIC_DEF( I_FSTP8, "fstp8" ), \
    MNEMONIC_DEF( I_FSTP9, "fstp9" ), \
    MNEMONIC_DEF( I_FSTSW, "fstsw" ), \
    MNEMONIC_DEF( I_FSUB, "fsub" ), \
    MNEMONIC_DEF( I_FSUBP, "fsubp" ), \
    MNEMONIC_DEF( I_FSUBR, "fsubr" ), \
    MNEMONIC_DEF( I_FSUBRP, "fsubrp" ), \
    MNEMONIC_DEF( I_FTST, "ftst" ), \
    MNEMONIC_DEF( I_FUCOM, "fucom" ), \
    MNEMONIC_DEF( I_FUCOMI, "fucomi" ), \
    MNEMONIC_DEF( I_FUCOMIP, "fucomip" ), \
    MNEMONIC_DEF( I_FUCOMP, "fucomp" ), \
    MNEMONIC_DEF( I_FUCOMPP, "fucompp" ), \
    MNEMONIC_DEF( I_FXAM, "fxam" ), \
    MNEMONIC_DEF( I_FXCH, "fxch" ), \
    MNEMONIC_DEF( I_FXCH4, "fxch4" ), \
    MNEMONIC_DEF( I_FXCH7, "fxch7" ), \
    MNEMONIC_DEF( I_FXRSTOR, "fxrstor" ), \
    MNEMONIC_DEF( I_FXSAVE, "fxsave" ), \
    MNEMONIC_DEF( I_FXTRACT, "fxtract" ), \
    MNEMONIC_DEF( I_FYL2X, "fyl2x" ), \
    MNEMONIC_DEF( I_FYL2XP1, "fyl2xp1" ), \
    MNEMONIC_DEF( I_HADDPD, "haddpd" ), \
    MNEMONIC_DEF( I_HADDPS, "haddps" ), \
    MNEMONIC_DEF( I_HINT_NOP, "hint_nop" ), \
    MNEMONIC_DEF( I_HLT, "hlt" ), \
    MNEMONIC_DEF( I_HSUBPD, "hsubpd" ), \
    MNEMONIC_DEF( I_HSUBPS, "hsubps" ), \
    MNEMONIC_DEF( I_IDIV, "idiv" ), \
    MNEMONIC_DEF( I_IMUL, "imul" ), \
    MNEMONIC_DEF( I_IN, "in" ), \
    MNEMONIC_DEF( I_INC, "inc" ), \
    MNEMONIC_DEF( I_INSB, "insb" ), \
    MNEMONIC_DEF( I_INSD, "insd" ), \
    MNEMONIC_DEF( I_INSERTPS, "insertps" ), \
    MNEMONIC_DEF( I_INSW, "insw" ), \
    MNEMONIC_DEF( I_INT, "int" ), \
    MNEMONIC_DEF( I_INT1, "int1" ), \
    MNEMONIC_DEF( I_INT3, "int3" ), \
    MNEMONIC_DEF( I_INTO, "into" ), \
    MNEMONIC_DEF( I_INVD, "invd" ), \
    MNEMONIC_DEF( I_INVLPG, "invlpg" ), \
    MNEMONIC_DEF( I_INVLPGA, "invlpga" ), \
    MNEMONIC_DEF( I_IRETD, "iretd" ), \
    MNEMONIC_DEF( I_IRETQ, "iretq" ), \
    MNEMONIC_DEF( I_IRETW, "iretw" ), \
    MNEMONIC_DEF( I_JA, "ja" ), \
    MNEMONIC_DEF( I_JAE, "jae" ), \
    MNEMONIC_DEF( I_JB, "jb" ), \
    MNEMONIC_DEF( I_JBE, "jbe" ), \
    MNEMONIC_DEF( I_JCXZ, "jcxz" ), \
    MNEMONIC_DEF( I_JE, "je" ), \
    MNEMONIC_DEF( I_JECXZ, "jecxz" ), \
    MNEMONIC_DEF( I_JG, "jg" ), \
    MNEMONIC_DEF( I_JGE, "jge" ), \
    MNEMONIC_DEF( I_JL, "jl" ), \
    MNEMONIC_DEF( I_JLE, "jle" ), \
    MNEMONIC_DEF( I_JMP, "jmp" ), \
    MNEMONIC_DEF( I_JMP_FAR, "jmp far" ), \
    MNEMONIC_DEF( I_JNE, "jne" ), \
    MNEMONIC_DEF( I_JNG, "jng" ), \
    MNEMONIC_DEF( I_JNO, "jno" ), \
    MNEMONIC_DEF( I_JNP, "jnp" ), \
    MNEMONIC_DEF( I_JNS, "jns" ), \
    MNEMONIC_DEF( I_JO, "jo" ), \
    MNEMONIC_DEF( I_JP, "jp" ), \
    MNEMONIC_DEF( I_JRCXZ, "jrcxz" ), \
    MNEMONIC_DEF( I_JS, "js" ), \
    MNEMONIC_DEF( I_LAHF, "lahf" ), \
    MNEMONIC_DEF( I_LAR, "lar" ), \
    MNEMONIC_DEF( I_LDDQU, "lddqu" ), \
    MNEMONIC_DEF( I_LDMXCSR, "ldmxcsr" ), \
    MNEMONIC_DEF( I_LDS, "lds" ), \
    MNEMONIC_DEF( I_LEA, "lea" ), \
    MNEMONIC_DEF( I_LEAVE, "leave" ), \
    MNEMONIC_DEF( I_LES, "les" ), \
    MNEMONIC_DEF( I_LFENCE, "lfence" ), \
    MNEMONIC_DEF( I_LFS, "lfs" ), \
    MNEMONIC_DEF( I_LGDT, "lgdt" ), \
    MNEMONIC_DEF( I_LGS, "lgs" ), \
    MNEMONIC_DEF( I_LIDT, "lidt" ), \
    MNEMONIC_DEF( I_LLDT, "lldt" ), \
    MNEMONIC_DEF( I_LMSW, "lmsw" ), \
    MNEMONIC_DEF( I_LODSB, "lodsb" ), \
    MNEMONIC_DEF( I_LODSD, "lodsd" ), \
    MNEMONIC_DEF( I_LODSQ, "lodsq" ), \
    MNEMONIC_DEF( I_LODSW, "lodsw" ), \
    MNEMONIC_DEF( I_LOOP, "loop" ), \
    MNEMONIC_DEF( I_LOOPE, "loope" ), \
    MNEMONIC_DEF( I_LOOPNE, "loopne" ), \
    MNEMONIC_DEF( I_LSL, "lsl" ), \
    MNEMONIC_DEF( I_LSS, "lss" ), \
    MNEMONIC_DEF( I_LTR, "ltr" ), \
    MNEMONIC_DEF( I_MASKMOVDQU, "maskmovdqu" ), \
    MNEMONIC_DEF( I_MASKMOVQ, "maskmovq" ), \
    MNEMONIC_DEF( I_MAXPD, "maxpd" ), \
    MNEMONIC_DEF( I_MAXPS, "maxps" ), \
    MNEMONIC_DEF( I_MAXSD, "maxsd" ), \
    MNEMONIC_DEF( I_MAXSS, "maxss" ), \
    MNEMONIC_DEF( I_MFENCE, "mfence" ), \
    MNEMONIC_DEF( I_MINPD, "minpd" ), \
    MNEMONIC_DEF( I_MINPS, "minps" ), \
    MNEMONIC_DEF( I_MINSD, "minsd" ), \
    MNEMONIC_DEF( I_MINSS, "minss" ), \
    MNEMONIC_DEF( I_MONITOR, "monitor" ), \
    MNEMONIC_DEF( I_MOV, "mov" ), \
    MNEMONIC_DEF( I_MOVAPD, "movapd" ), \
    MNEMONIC_DEF( I_MOVAPS, "movaps" ), \
    MNEMONIC_DEF( I_MOVD, "movd" ), \
    MNEMONIC_DEF( I_MOVDDUP, "movddup" ), \
    MNEMONIC_DEF( I_MOVDQ2Q, "movdq2q" ), \
    MNEMONIC_DEF( I_MOVDQA, "movdqa" ), \
    MNEMONIC_DEF( I_MOVDQU, "movdqu" ), \
    MNEMONIC_DEF( I_MOVHLPS, "movhlps" ), \
    MNEMONIC_DEF( I_MOVHPD, "movhpd" ), \
    MNEMONIC_DEF( I_MOVHPS, "movhps" ), \
    MNEMONIC_DEF( I_MOVLHPS, "movlhps" ), \
    MNEMONIC_DEF( I_MOVLPD, "movlpd" ), \
    MNEMONIC_DEF( I_MOVLPS, "movlps" ), \
    MNEMONIC_DEF( I_MOVMSKPD, "movmskpd" ), \
    MNEMONIC_DEF( I_MOVMSKPS, "movmskps" ), \
    MNEMONIC_DEF( I_MOVNTDQ, "movntdq" ), \
    MNEMONIC_DEF( I_MOVNTDQA, "movntdqa" ), \
    MNEMONIC_DEF( I_MOVNTI, "movnti" ), \
    MNEMONIC_DEF( I_MOVNTPD, "movntpd" ), \
    MNEMONIC_DEF( I_MOVNTPS, "movntps" ), \
    MNEMONIC_DEF( I_MOVNTQ, "movntq" ), \
    MNEMONIC_DEF( I_MOVQ, "movq" ), \
    MNEMONIC_DEF( I_MOVQ2DQ, "movq2dq" ), \
    MNEMONIC_DEF( I_MOVSB, "movsb" ), \
    MNEMONIC_DEF( I_MOVSD, "movsd" ), \
    MNEMONIC_DEF( I_MOVSHDUP, "movshdup" ), \
    MNEMONIC_DEF( I_MOVSLDUP, "movsldup" ), \
    MNEMONIC_DEF( I_MOVSQ, "movsq" ), \
    MNEMONIC_DEF( I_MOVSS, "movss" ), \
    MNEMONIC_DEF( I_MOVSW, "movsw" ), \
    MNEMONIC_DEF( I_MOVSX, "movsx" ), \
    MNEMONIC_DEF( I_MOVSXD, "movsxd" ), \
    MNEMONIC_DEF( I_MOVUPD, "movupd" ), \
    MNEMONIC_DEF( I_MOVUPS, "movups" ), \
    MNEMONIC_DEF( I_MOVZX, "movzx" ), \
    MNEMONIC_DEF( I_MPSADBW, "mpsadbw" ), \
    MNEMONIC_DEF( I_MUL, "mul" ), \
    MNEMONIC_DEF( I_MULPD, "mulpd" ), \
    MNEMONIC_DEF( I_MULPS, "mulps" ), \
    MNEMONIC_DEF( I_MULSD, "mulsd" ), \
    MNEMONIC_DEF( I_MULSS, "mulss" ), \
    MNEMONIC_DEF( I_MWAIT, "mwait" ), \
    MNEMONIC_DEF( I_NEG, "neg" ), \
    MNEMONIC_DEF( I_NOP, "nop" ), \
    MNEMONIC_DEF( I_NOT, "not" ), \
    MNEMONIC_DEF( I_OR, "or" ), \
    MNEMONIC_DEF( I_ORPD, "orpd" ), \
    MNEMONIC_DEF( I_ORPS, "orps" ), \
    MNEMONIC_DEF( I_OUT, "out" ), \
    MNEMONIC_DEF( I_OUTSB, "outsb" ), \
    MNEMONIC_DEF( I_OUTSD, "outsd" ), \
    MNEMONIC_DEF( I_OUTSW, "outsw" ), \
    MNEMONIC_DEF( I_PABSB, "pabsb" ), \
    MNEMONIC_DEF( I_PABSD, "pabsd" ), \
    MNEMONIC_DEF( I_PABSW, "pabsw" ), \
    MNEMONIC_DEF( I_PACKSSDW, "packssdw" ), \
    MNEMONIC_DEF( I_PACKSSWB, "packsswb" ), \
    MNEMONIC_DEF( I_PACKUSDW, "packusdw" ), \
    MNEMONIC_DEF( I_PACKUSWB, "packuswb" ), \
    MNEMONIC_DEF( I_PADDB, "paddb" ), \
    MNEMONIC_DEF( I_PADDD, "paddd" ), \
    MNEMONIC_DEF( I_PADDQ, "paddq" ), \
    MNEMONIC_DEF( I_PADDSB, "paddsb" ), \
    MNEMONIC_DEF( I_PADDSW, "paddsw" ), \
    MNEMONIC_DEF( I_PADDUSB, "paddusb" ), \
    MNEMONIC_DEF( I_PADDUSW, "paddusw" ), \
    MNEMONIC_DEF( I_PADDW, "paddw" ), \
    MNEMONIC_DEF( I_PALIGNR, "palignr" ), \
    MNEMONIC_DEF( I_PAND, "pand" ), \
    MNEMONIC_DEF( I_PANDN, "pandn" ), \
    MNEMONIC_DEF( I_PAUSE, "pause" ), \
    MNEMONIC_DEF( I_PAVGB, "pavgb" ), \
    MNEMONIC_DEF( I_PAVGW, "pavgw" ), \
    MNEMONIC_DEF( I_PBLENDVB, "pblendvb" ), \
    MNEMONIC_DEF( I_PBLENDW, "pblendw" ), \
    MNEMONIC_DEF( I_PCLMULHQHQDQ, "pclmulhqhqdq" ), \
    MNEMONIC_DEF( I_PCLMULHQLQDQ, "pclmulhqlqdq" ), \
    MNEMONIC_DEF( I_PCLMULLQHQDQ, "pclmullqhqdq" ), \
    MNEMONIC_DEF( I_PCLMULLQLQDQ, "pclmullqlqdq" ), \
    MNEMONIC_DEF( I_PCLMULQDQ, "pclmulqdq" ), \
    MNEMONIC_DEF( I_PCMPEQB, "pcmpeqb" ), \
    MNEMONIC_DEF( I_PCMPEQD, "pcmpeqd" ), \
    MNEMONIC_DEF( I_PCMPEQQ, "pcmpeqq" ), \
    MNEMONIC_DEF( I_PCMPEQW, "pcmpeqw" ), \
    MNEMONIC_DEF( I_PCMPESTRI, "pcmpestri" ), \
    MNEMONIC_DEF( I_PCMPESTRM, "pcmpestrm" ), \
    MNEMONIC_DEF( I_PCMPGTB, "pcmpgtb" ), \
    MNEMONIC_DEF( I_PCMPGTD, "pcmpgtd" ), \
    MNEMONIC_DEF( I_PCMPGTQ, "pcmpgtq" ), \
    MNEMONIC_DEF( I_PCMPGTW, "pcmpgtw" ), \
    MNEMONIC_DEF( I_PCMPISTRI, "pcmpistri" ), \
    MNEMONIC_DEF( I_PEXTRB, "pextrb" ), \
    MNEMONIC_DEF( I_PEXTRD, "pextrd" ), \
    MNEMONIC_DEF( I_PEXTRQ, "pextrq" ), \
    MNEMONIC_DEF( I_PEXTRW, "pextrw" ), \
    MNEMONIC_DEF( I_PHADDD, "phaddd" ), \
    MNEMONIC_DEF( I_PHADDSW, "phaddsw" ), \
    MNEMONIC_DEF( I_PHADDW, "phaddw" ), \
    MNEMONIC_DEF( I_PHMINPOSUW, "phminposuw" ), \
    MNEMONIC_DEF( I_PHSUBD, "phsubd" ), \
    MNEMONIC_DEF( I_PHSUBSW, "phsubsw" ), \
    MNEMONIC_DEF( I_PHSUBW, "phsubw" ), \
    MNEMONIC_DEF( I_PINSRB, "pinsrb" ), \
    MNEMONIC_DEF( I_PINSRD, "pinsrd" ), \
    MNEMONIC_DEF( I_PINSRQ, "pinsrq" ), \
    MNEMONIC_DEF( I_PINSRW, "pinsrw" ), \
    MNEMONIC_DEF( I_PMADDUBSW, "pmaddubsw" ), \
    MNEMONIC_DEF( I_PMADDWD, "pmaddwd" ), \
    MNEMONIC_DEF( I_PMAXSB, "pmaxsb" ), \
    MNEMONIC_DEF( I_PMAXSD, "pmaxsd" ), \
    MNEMONIC_DEF( I_PMAXSW, "pmaxsw" ), \
    MNEMONIC_DEF( I_PMAXUB, "pmaxub" ), \
    MNEMONIC_DEF( I_PMAXUD, "pmaxud" ), \
    MNEMONIC_DEF( I_PMAXUW, "pmaxuw" ), \
    MNEMONIC_DEF( I_PMINSB, "pminsb" ), \
    MNEMONIC_DEF( I_PMINSD, "pminsd" ), \
    MNEMONIC_DEF( I_PMINSW, "pminsw" ), \
    MNEMONIC_DEF( I_PMINUB, "pminub" ), \
    MNEMONIC_DEF( I_PMINUD, "pminud" ), \
    MNEMONIC_DEF( I_PMINUW, "pminuw" ), \
    MNEMONIC_DEF( I_PMOVMSKB, "pmovmskb" ), \
    MNEMONIC_DEF( I_PMOVSXBD, "pmovsxbd" ), \
    MNEMONIC_DEF( I_PMOVSXBQ, "pmovsxbq" ), \
    MNEMONIC_DEF( I_PMOVSXBW, "pmovsxbw" ), \
    MNEMONIC_DEF( I_PMOVSXDQ, "pmovsxdq" ), \
    MNEMONIC_DEF( I_PMOVSXWD, "pmovsxwd" ), \
    MNEMONIC_DEF( I_PMOVSXWQ, "pmovsxwq" ), \
    MNEMONIC_DEF( I_PMOVZXBD, "pmovzxbd" ), \
    MNEMONIC_DEF( I_PMOVZXBQ, "pmovzxbq" ), \
    MNEMONIC_DEF( I_PMOVZXBW, "pmovzxbw" ), \
    MNEMONIC_DEF( I_PMOVZXDQ, "pmovzxdq" ), \
    MNEMONIC_DEF( I_PMOVZXWD, "pmovzxwd" ), \
    MNEMONIC_DEF( I_PMOVZXWQ, "pmovzxwq" ), \
    MNEMONIC_DEF( I_PMULDQ, "pmuldq" ), \
    MNEMONIC_DEF( I_PMULHRSW, "pmulhrsw" ), \
    MNEMONIC_DEF( I_PMULHUW, "pmulhuw" ), \
    MNEMONIC_DEF( I_PMULHW, "pmulhw" ), \
    MNEMONIC_DEF( I_PMULLD, "pmulld" ), \
    MNEMONIC_DEF( I_PMULLW, "pmullw" ), \
    MNEMONIC_DEF( I_PMULUDQ, "pmuludq" ), \
    MNEMONIC_DEF( I_POP, "pop" ), \
    MNEMONIC_DEF( I_POPA, "popa" ), \
    MNEMONIC_DEF( I_POPAD, "popad" ), \
    MNEMONIC_DEF( I_POPCNT, "popcnt" ), \
    MNEMONIC_DEF( I_POPF, "popf" ), \
    MNEMONIC_DEF( I_POPFD, "popfd" ), \
    MNEMONIC_DEF( I_POPFQ, "popfq" ), \
    MNEMONIC_DEF( I_POR, "por" ), \
    MNEMONIC_DEF( I_PREFETCHNTA, "prefetchNTA" ), \
    MNEMONIC_DEF( I_PREFETCHT0, "prefetchT0" ), \
    MNEMONIC_DEF( I_PREFETCHT1, "prefetchT1" ), \
    MNEMONIC_DEF( I_PREFETCHT2, "prefetchT2" ), \
    MNEMONIC_DEF( I_PSADBW, "psadbw" ), \
    MNEMONIC_DEF( I_PSHUFB, "pshufb" ), \
    MNEMONIC_DEF( I_PSHUFD, "pshufd" ), \
    MNEMONIC_DEF( I_PSHUFHW, "pshufhw" ), \
    MNEMONIC_DEF( I_PSHUFLW, "pshuflw" ), \
    MNEMONIC_DEF( I_PSHUFW, "pshufw" ), \
    MNEMONIC_DEF( I_PSIGNB, "psignb" ), \
    MNEMONIC_DEF( I_PSIGND, "psignd" ), \
    MNEMONIC_DEF( I_PSIGNW, "psignw" ), \
    MNEMONIC_DEF( I_PSLLD, "pslld" ), \
    MNEMONIC_DEF( I_PSLLDQ, "pslldq" ), \
    MNEMONIC_DEF( I_PSLLQ, "psllq" ), \
    MNEMONIC_DEF( I_PSLLW, "psllw" ), \
    MNEMONIC_DEF( I_PSRAD, "psrad" ), \
    MNEMONIC_DEF( I_PSRAW, "psraw" ), \
    MNEMONIC_DEF( I_PSRLD, "psrld" ), \
    MNEMONIC_DEF( I_PSRLDQ, "psrldq" ), \
    MNEMONIC_DEF( I_PSRLQ, "psrlq" ), \
    MNEMONIC_DEF( I_PSRLW, "psrlw" ), \
    MNEMONIC_DEF( I_PSUBB, "psubb" ), \
    MNEMONIC_DEF( I_PSUBD, "psubd" ), \
    MNEMONIC_DEF( I_PSUBQ, "psubq" ), \
    MNEMONIC_DEF( I_PSUBSB, "psubsb" ), \
    MNEMONIC_DEF( I_PSUBSW, "psubsw" ), \
    MNEMONIC_DEF( I_PSUBUSB, "psubusb" ), \
    MNEMONIC_DEF( I_PSUBUSW, "psubusw" ), \
    MNEMONIC_DEF( I_PSUBW, "psubw" ), \
    MNEMONIC_DEF( I_PTEST, "ptest" ), \
    MNEMONIC_DEF( I_PUNPCKHBW, "punpckhbw" ), \
    MNEMONIC_DEF( I_PUNPCKHDQ, "punpckhdq" ), \
    MNEMONIC_DEF( I_PUNPCKHQDQ, "punpckhqdq" ), \
    MNEMONIC_DEF( I_PUNPCKHWD, "punpckhwd" ), \
    MNEMONIC_DEF( I_PUNPCKLBW, "punpcklbw" ), \
    MNEMONIC_DEF( I_PUNPCKLDQ, "punpckldq" ), \
    MNEMONIC_DEF( I_PUNPCKLQDQ, "punpcklqdq" ), \
    MNEMONIC_DEF( I_PUNPCKLWD, "punpcklwd" ), \
    MNEMONIC_DEF( I_PUSH, "push" ), \
    MNEMONIC_DEF( I_PUSHA, "pusha" ), \
    MNEMONIC_DEF( I_PUSHAD, "pushad" ), \
    MNEMONIC_DEF( I_PUSHF, "pushf" ), \
    MNEMONIC_DEF( I_PUSHFD, "pushfd" ), \
    MNEMONIC_DEF( I_PUSHFQ, "pushfq" ), \
    MNEMONIC_DEF( I_PXOR, "pxor" ), \
    MNEMONIC_DEF( I_RCL, "rcl" ), \
    MNEMONIC_DEF( I_RCPPS, "rcpps" ), \
    MNEMONIC_DEF( I_RCPSS, "rcpss" ), \
    MNEMONIC_DEF( I_RCR, "rcr" ), \
    MNEMONIC_DEF( I_RDMSR, "rdmsr" ), \
    MNEMONIC_DEF( I_RDPMC, "rdpmc" ), \
    MNEMONIC_DEF( I_RDTSC, "rdtsc" ), \
    MNEMONIC_DEF( I_RDTSCP, "rdtscp" ), \
    MNEMONIC_DEF( I_RET, "ret" ), \
    MNEMONIC_DEF( I_RETF, "retf" ), \
    MNEMONIC_DEF( I_RETN, "retn" ), \
    MNEMONIC_DEF( I_ROL, "rol" ), \
    MNEMONIC_DEF( I_ROR, "ror" ), \
    MNEMONIC_DEF( I_ROUNDPD, "roundpd" ), \
    MNEMONIC_DEF( I_ROUNDPS, "roundps" ), \
    MNEMONIC_DEF( I_ROUNDSD, "roundsd" ), \
    MNEMONIC_DEF( I_ROUNDSS, "roundss" ), \
    MNEMONIC_DEF( I_RSM, "rsm" ), \
    MNEMONIC_DEF( I_RSQRTPS, "rsqrtps" ), \
    MNEMONIC_DEF( I_RSQRTSS, "rsqrtss" ), \
    MNEMONIC_DEF( I_SAHF, "sahf" ), \
    MNEMONIC_DEF( I_SAL, "sal" ), \
    MNEMONIC_DEF( I_SALC, "salc" ), \
    MNEMONIC_DEF( I_SAR, "sar" ), \
    MNEMONIC_DEF( I_SBB, "sbb" ), \
    MNEMONIC_DEF( I_SCASB, "scasb" ), \
    MNEMONIC_DEF( I_SCASD, "scasd" ), \
    MNEMONIC_DEF( I_SCASQ, "scasq" ), \
    MNEMONIC_DEF( I_SCASW, "scasw" ), \
    MNEMONIC_DEF( I_SETA, "seta" ), \
    MNEMONIC_DEF( I_SETAE, "setae" ), \
    MNEMONIC_DEF( I_SETB, "setb" ), \
    MNEMONIC_DEF( I_SETBE, "setbe" ), \
    MNEMONIC_DEF( I_SETE, "sete" ), \
    MNEMONIC_DEF( I_SETG, "setg" ), \
    MNEMONIC_DEF( I_SETGE, "setge" ), \
    MNEMONIC_DEF( I_SETL, "setl" ), \
    MNEMONIC_DEF( I_SETLE, "setle" ), \
    MNEMONIC_DEF( I_SETNE, "setne" ), \
    MNEMONIC_DEF( I_SETNO, "setno" ), \
    MNEMONIC_DEF( I_SETNP, "setnp" ), \
    MNEMONIC_DEF( I_SETNS, "setns" ), \
    MNEMONIC_DEF( I_SETO, "seto" ), \
    MNEMONIC_DEF( I_SETP, "setp" ), \
    MNEMONIC_DEF( I_SETS, "sets" ), \
    MNEMONIC_DEF( I_SFENCE, "sfence" ), \
    MNEMONIC_DEF( I_SGDT, "sgdt" ), \
    MNEMONIC_DEF( I_SHL, "shl" ), \
    MNEMONIC_DEF( I_SHLD, "shld" ), \
    MNEMONIC_DEF( I_SHR, "shr" ), \
    MNEMONIC_DEF( I_SHRD, "shrd" ), \
    MNEMONIC_DEF( I_SHUFPD, "shufpd" ), \
    MNEMONIC_DEF( I_SHUFPS, "shufps" ), \
    MNEMONIC_DEF( I_SIDT, "sidt" ), \
    MNEMONIC_DEF( I_SKINIT, "skinit" ), \
    MNEMONIC_DEF( I_SLDT, "sldt" ), \
    MNEMONIC_DEF( I_SMSW, "smsw" ), \
    MNEMONIC_DEF( I_SQRTPD, "sqrtpd" ), \
    MNEMONIC_DEF( I_SQRTPS, "sqrtps" ), \
    MNEMONIC_DEF( I_SQRTSD, "sqrtsd" ), \
    MNEMONIC_DEF( I_SQRTSS, "sqrtss" ), \
    MNEMONIC_DEF( I_STC, "stc" ), \
    MNEMONIC_DEF( I_STD, "std" ), \
    MNEMONIC_DEF( I_STGI, "stgi" ), \
    MNEMONIC_DEF( I_STI, "sti" ), \
    MNEMONIC_DEF( I_STMXCSR, "stmxcsr" ), \
    MNEMONIC_DEF( I_STOSB, "stosb" ), \
    MNEMONIC_DEF( I_STOSD, "stosd" ), \
    MNEMONIC_DEF( I_STOSQ, "stosq" ), \
    MNEMONIC_DEF( I_STOSW, "stosw" ), \
    MNEMONIC_DEF( I_STR, "str" ), \
    MNEMONIC_DEF( I_SUB, "sub" ), \
    MNEMONIC_DEF( I_SUBPD, "subpd" ), \
    MNEMONIC_DEF( I_SUBPS, "subps" ), \
    MNEMONIC_DEF( I_SUBSD, "subsd" ), \
    MNEMONIC_DEF( I_SUBSS, "subss" ), \
    MNEMONIC_DEF( I_SWAPGS, "swapgs" ), \
    MNEMONIC_DEF( I_SYSCALL, "syscall" ), \
    MNEMONIC_DEF( I_SYSENTER, "sysenter" ), \
    MNEMONIC_DEF( I_SYSEXIT, "sysexit" ), \
    MNEMONIC_DEF( I_SYSRET, "sysret" ), \
    MNEMONIC_DEF( I_TEST, "test" ), \
    MNEMONIC_DEF( I_UCOMISD, "ucomisd" ), \
    MNEMONIC_DEF( I_UCOMISS, "ucomiss" ), \
    MNEMONIC_DEF( I_UD2, "ud2" ), \
    MNEMONIC_DEF( I_UNPCKHPD, "unpckhpd" ), \
    MNEMONIC_DEF( I_UNPCKHPS, "unpckhps" ), \
    MNEMONIC_DEF( I_UNPCKLPD, "unpcklpd" ), \
    MNEMONIC_DEF( I_UNPCKLPS, "unpcklps" ), \
    MNEMONIC_DEF( I_VERR, "verr" ), \
    MNEMONIC_DEF( I_VERW, "verw" ), \
    MNEMONIC_DEF( I_VMCALL, "vmcall" ), \
    MNEMONIC_DEF( I_VMCLEAR, "vmclear" ), \
    MNEMONIC_DEF( I_VMLAUNCH, "vmlaunch" ), \
    MNEMONIC_DEF( I_VMLOAD, "vmload" ), \
    MNEMONIC_DEF( I_VMMCALL, "vmmcall" ), \
    MNEMONIC_DEF( I_VMPTRLD, "vmptrld" ), \
    MNEMONIC_DEF( I_VMPTRST, "vmptrst" ), \
    MNEMONIC_DEF( I_VMREAD, "vmread" ), \
    MNEMONIC_DEF( I_VMRESUME, "vmresume" ), \
    MNEMONIC_DEF( I_VMRUN, "vmrun" ), \
    MNEMONIC_DEF( I_VMSAVE, "vmsave" ), \
    MNEMONIC_DEF( I_VMWRITE, "vmwrite" ), \
    MNEMONIC_DEF( I_VMXOFF, "vmxoff" ), \
    MNEMONIC_DEF( I_VMXON, "vmxon" ), \
    MNEMONIC_DEF( I_WAIT, "wait" ), \
    MNEMONIC_DEF( I_WBINVD, "wbinvd" ), \
    MNEMONIC_DEF( I_WRMSR, "wrmsr" ), \
    MNEMONIC_DEF( I_XADD, "xadd" ), \
    MNEMONIC_DEF( I_XCHG, "xchg" ), \
    MNEMONIC_DEF( I_XGETBV, "xgetbv" ), \
    MNEMONIC_DEF( I_XLATB, "xlatb" ), \
    MNEMONIC_DEF( I_XOR, "xor" ), \
    MNEMONIC_DEF( I_XORPD, "xorpd" ), \
    MNEMONIC_DEF( I_XORPS, "xorps" ), \
    MNEMONIC_DEF( I_XRSTOR, "xrstor" ), \
    MNEMONIC_DEF( I_XSAVE, "xsave" ), \
    MNEMONIC_DEF( I_XSETBV, "xsetbv" ), \

#define MNEMONIC_DEF(id, name) id
enum MNEMONIC_ENUM { MNEMONIC_MAP_DEF };
#undef MNEMONIC_DEF
#define MNEMONIC_DEF(id, name) name
//const char *MNEMONICS[] = { MNEMONIC_MAP_DEF };
#undef MNEMONIC_DEF

#ifdef __cplusplus
extern "C" {
#endif

BEA_API int __bea_callspec__ Disasm (LPDISASM pDisAsm);
BEA_API const__ char* __bea_callspec__ BeaEngineVersion (void);
BEA_API const__ char* __bea_callspec__ BeaEngineRevision (void);

#ifdef __cplusplus
}
#endif

#if  defined(__cplusplus) && defined(__BORLANDC__)
};
using namespace BeaEngine;
#endif
#endif
