#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
Python wrapper for BeaEngine
This file is an example of how to make library easier to use in python.
You should modify this or rewrite your own to be what you need.
"""

__all__ = ['disassemble', 'disassemble_generator', 'dis1']

from .beaengine import *

REG_GENERAL_MAP = {
    REG0: {8:'al',  16:'ax', 32:'eax', 64:'rax'},
    REG1: {8:'cl',  16:'cx', 32:'ecx', 64:'rcx'},
    REG2: {8:'dl',  16:'dx', 32:'edx', 64:'rdx'},
    REG3: {8:'bl',  16:'bx', 32:'ebx', 64:'rbx'},
    REG4: {8:'spl', 16:'sp', 32:'esp', 64:'rsp'},
    REG5: {8:'bpl', 16:'bp', 32:'ebp', 64:'rbp'},
    REG6: {8:'sil', 16:'si', 32:'esi', 64:'rsi'},
    REG7: {8:'dil', 16:'di', 32:'edi', 64:'rdi'},
    REG8: {8:'r8b', 16:'r8w', 32:'r8d', 64:'r8'},
    REG9: {8:'r9b', 16:'r9w', 32:'r9d', 64:'r9'},
    REG10:{8:'r10b', 16:'r10w', 32:'r10d', 64:'r10'},
    REG11:{8:'r11b', 16:'r11w', 32:'r11d', 64:'r11'},
    REG12:{8:'r12b', 16:'r12w', 32:'r12d', 64:'r12'},
    REG13:{8:'r13b', 16:'r13w', 32:'r13d', 64:'r13'},
    REG14:{8:'r14b', 16:'r14w', 32:'r14d', 64:'r14'},
    REG15:{8:'r15b', 16:'r15w', 32:'r15d', 64:'r15'},
}
REG_GENERAL_HI_MAP = {
    REG0: 'ah', REG1: 'ch', REG2: 'dh', REG3: 'bh'
}
REG_GENERAL_MASK = {
    8:0xff, 16:0xffff, 32:0xffffffff, 64:0xffffffffffffffff
}
REG_FPU_MAP = {
    REG0:'st0', REG1:'st1', REG2:'st2', REG3:'st3',
    REG4:'st4', REG5:'st5', REG6:'st6', REG7:'st7',
}
REG_SSE_MAP = {
    REG0 :'xmm0',  REG1 :'xmm1',  REG2:'xmm2',   REG3 :'xmm3',
    REG4 :'xmm4',  REG5 :'xmm5',  REG6:'xmm6',   REG7 :'xmm7',
    REG8 :'xmm8',  REG9 :'xmm9',  REG10:'xmm10', REG11:'xmm11',
    REG12:'xmm12', REG13:'xmm13', REG14:'xmm14', REG15:'xmm15',
}
REG_SEGMENT_MAP = [ None, 'es', 'ds', 'fs', 'gs', 'cs', 'ss' ]

Mnemonics = [ "", "aaa", "aad", "aam", "aas", "adc", "add", "addpd",
    "addps", "addsd", "addss", "addsubpd", "addsubps", "aesdec",
    "aesdeclast", "aesenc", "aesenclast", "aesimc", "aeskeygenassist",
    "and", "andnpd", "andnps", "andpd", "andps", "arpl", "blendpd",
    "blendps", "blendvpd", "blendvps", "bound", "bsf", "bsr", "bswap",
    "bt", "btc", "btr", "bts", "call", "call far", "cbw", "cdq", "cdqe",
    "clc", "cld", "clflush", "clgi", "cli", "clts", "cmc", "cmova",
    "cmovae", "cmovb", "cmovbe", "cmove", "cmovg", "cmovge", "cmovl",
    "cmovle", "cmovne", "cmovno", "cmovnp", "cmovns", "cmovo", "cmovp",
    "cmovs", "cmp", "cmppd", "cmpps", "cmps", "cmpsb", "cmpsd", "cmpsq",
    "cmpss", "cmpsw", "cmpxchg", "cmpxchg16b", "cmpxchg8b", "comisd",
    "comiss", "cpuid", "cqo", "crc32", "cvtdq2pd", "cvtdq2ps", 
    "cvtpd2dq", "cvtpd2pi", "cvtpd2ps", "cvtpi2pd", "cvtpi2ps", 
    "cvtps2dq", "cvtps2pd", "cvtps2pi", "cvtsd2si", "cvtsd2ss", 
    "cvtsi2sd", "cvtsi2ss", "cvtss2sd", "cvtss2si", "cvttpd2dq", 
    "cvttpd2pi", "cvttps2dq", "cvttps2pi", "cvttsd2si", "cvttss2si", 
    "cwd", "cwde", "daa", "das", "dec", "div", "divpd", "divps", 
    "divsd", "divss", "dppd", "dpps", "emms", "enter", "extractps", 
    "f2xm1", "fabs", "fadd", "faddp", "fbld", "fbstp", "fchs", "fcmovb",
    "fcmovbe", "fcmove", "fcmovnb", "fcmovnbe", "fcmovne", "fcmovnu",
    "fcmovu", "fclex", "fcom", "fcom2", "fcomi", "fcomip", "fcomp",
    "fcomp3", "fcomp5", "fcompp", "fcos", "fdecstp", "fdiv", "fdivp",
    "fdivr", "fdivrp", "femms", "ffree", "ffreep", "fiadd", "ficom",
    "ficomp", "fidiv", "fidivr", "fild", "fimul", "fincstp", "finit",
    "fist", "fistp", "fisttp", "fisub", "fisubr", "fld", "fld1", "fldcw",
    "fldenv", "fldl2e", "fldl2t", "fldlg2", "fldln2", "fldpi", "fldz",
    "fmul", "fmulp", "fnclex", "fndisi", "fneni", "fninit", "fnop",
    "fnsave", "fnsetpm", "fnstcw", "fnstenv", "fnstsw", "fpatan",
    "fprem", "fprem1", "fptan", "frndint", "frstor", "frstpm", "fsave",
    "fscale", "fsin", "fsincos", "fsqrt", "fst", "fstcw", "fstenv",
    "fstp", "fstp1", "fstp8", "fstp9", "fstsw", "fsub", "fsubp",
    "fsubr", "fsubrp", "ftst", "fucom", "fucomi", "fucomip", "fucomp",
    "fucompp", "fxam", "fxch", "fxch4", "fxch7", "fxrstor", "fxsave",
    "fxtract", "fyl2x", "fyl2xp1", "haddpd", "haddps", "hint_nop", 
    "hlt", "hsubpd", "hsubps", "idiv", "imul", "in", "inc", "insb",
    "insd", "insertps", "insw", "int", "int1", "int3", "into", "invd",
    "invlpg", "invlpga", "iretd", "iretq", "iretw", "ja", "jae", "jb",
    "jbe", "jcxz", "je", "jecxz", "jg", "jge", "jl", "jle", "jmp", 
    "jmp far", "jne", "jno", "jnp", "jns", "jo", "jp", "jrcxz", "js",
    "lahf", "lar", "lddqu", "ldmxcsr", "lds", "lea", "leave", "les",
    "lfence", "lfs", "lgdt", "lgs", "lidt", "lldt", "lmsw", "lods", "lodsb",
    "lodsd", "lodsq", "lodsw", "loop", "loope", "loopne", "lsl", "lss",
    "ltr", "maskmovdqu", "maskmovq", "maxpd", "maxps", "maxsd", "maxss", 
    "mfence", "minpd", "minps", "minsd", "minss", "monitor", "mov", 
    "movapd", "movaps", "movd", "movddup", "movdq2q", "movdqa", 
    "movdqu", "movhlps", "movhpd", "movhps", "movlhps", "movlpd", 
    "movlps", "movmskpd", "movmskps", "movntdq", "movntdqa", "movnti",
    "movntpd", "movntps", "movntq", "movq", "movq2dq", "movs", "movsb", 
    "movsd", "movshdup", "movsldup", "movsq", "movss", "movsw", 
    "movsx", "movsxd", "movupd", "movups", "movzx", "mpsadbw", "mul",
    "mulpd", "mulps", "mulsd", "mulss", "mwait", "neg", "nop", "not",
    "or", "orpd", "orps", "out", "outs", "outsb", "outsd", "outsw",
    "pabsb", "pabsd", "pabsw", "packssdw", "packsswb", "packusdw", 
    "packuswb", "paddb", "paddd", "paddq", "paddsb", "paddsw", 
    "paddusb", "paddusw", "paddw", "palignr", "pand", "pandn", 
    "pause", "pavgb", "pavgw", "pblendvb", "pblendw", "pclmulhqhqdq",
    "pclmulhqlqdq", "pclmullqhqdq", "pclmullqlqdq", "pclmulqdq", 
    "pcmpeqb", "pcmpeqd", "pcmpeqq", "pcmpeqw", "pcmpestri", 
    "pcmpestrm", "pcmpgtb", "pcmpgtd", "pcmpgtq", "pcmpgtw", 
    "pcmpistri" , "pextrb", "pextrd", "pextrq", "pextrw", "phaddd", 
    "phaddsw", "phaddw", "phminposuw", "phsubd", "phsubsw", "phsubw",
    "pinsrb", "pinsrd", "pinsrq", "pinsrw", "pmaddubsw", "pmaddwd", 
    "pmaxsb", "pmaxsd", "pmaxsw", "pmaxub", "pmaxud", "pmaxuw", 
    "pminsb", "pminsd", "pminsw", "pminub", "pminud", "pminuw", 
    "pmovmskb", "pmovsxbd", "pmovsxbq", "pmovsxbw", "pmovsxdq", 
    "pmovsxwd", "pmovsxwq", "pmovzxbd", "pmovzxbq", "pmovzxbw", 
    "pmovzxdq", "pmovzxwd", "pmovzxwq", "pmuldq", "pmulhrsw", 
    "pmulhuw", "pmulhw", "pmulld", "pmullw", "pmuludq", "pop", "popa",
    "popad", "popcnt", "popf", "popfd", "popfq", "por", "prefetchNTA",
    "prefetchT0", "prefetchT1", "prefetchT2", "psadbw", "pshufb",
    "pshufd", "pshufhw", "pshuflw", "pshufw", "psignb", "psignd", 
    "psignw", "pslld", "pslldq", "psllq", "psllw", "psrad", "psraw", 
    "psrld", "psrldq", "psrlq", "psrlw", "psubb", "psubd", "psubq", 
    "psubsb", "psubsw", "psubusb", "psubusw", "psubw", "ptest", 
    "punpckhbw", "punpckhdq", "punpckhqdq", "punpckhwd" , "punpcklbw",
    "punpckldq", "punpcklqdq", "punpcklwd", "push", "pusha", "pushad",
    "pushf", "pushfd", "pushfq", "pxor", "rcl", "rcpps", "rcpss", 
    "rcr", "rdmsr", "rdpmc", "rdtsc", "rdtscp", "ret", "retf", "retn",
    "rol", "ror", "roundpd", "roundps", "roundsd", "roundss", "rsm",
    "rsqrtps", "rsqrtss", "sahf", "sal", "salc", "sar", "sbb", "scasb",
    "scasd", "scasq", "scasw", "seta" , "setae", "setb", "setbe", 
    "sete", "setg", "setge", "setl", "setle", "setne", "setno", 
    "setnp", "setns", "seto", "setp", "sets", "sfence", "sgdt", "shl",
    "shld", "shr", "shrd", "shufpd", "shufps", "sidt", "skinit",
    "sldt", "smsw", "sqrtpd", "sqrtps", "sqrtsd", "sqrtss", "stc", 
    "std", "stgi", "sti", "stmxcsr", "stosb", "stosd", "stosq", 
    "stosw", "str", "sub", "subpd", "subps", "subsd", "subss", 
    "swapgs", "syscall", "sysenter", "sysexit", "sysret", "test", 
    "ucomisd", "ucomiss", "ud2", "unpckhpd", "unpckhps", "unpcklpd", 
    "unpcklps", "verr", "verw", "vmcall", "vmclear", "vmlaunch", 
    "vmload", "vmmcall", "vmptrld", "vmptrst", "vmread", "vmresume", 
    "vmrun", "vmsave", "vmwrite", "vmxoff", "vmxon" , "wait", 
    "wbinvd", "wrmsr", "xadd", "xchg", "xgetbv", "xlatb", "xor", 
    "xorpd", "xorps", "xrstor", "xsave", "xsetbv" ]

BranchTypes = [ None, 'jmp', 'call', 'ret', 'loop' ]

class Operand(object):
    def __init__(self, arg, asm, ins):
        argType = arg.ArgType
        self.size = arg.ArgSize
        self.read = True if arg.AccessMode & READ else False
        self.write = True if arg.AccessMode & WRITE else False
            
        # support only 32 and 64 bit
        if argType & REGISTER_TYPE:
            self.type = "REG"
            regbit = argType & 0xffff
            if argType & GENERAL_REG:
                self.reg = REG_GENERAL_MAP[regbit][asm.Archi]
                if arg.ArgSize == 1 and arg.ArgPosition == 1:
                    # only ah, bh, ch, dh are allowed to access this
                    self.name = REG_GENERAL_HI_MAP[regbit]
                    self.reg_mask = 0xff00
                else:
                    self.name = REG_GENERAL_MAP[regbit][arg.ArgSize]
                    self.reg_mask = REG_GENERAL_MASK[arg.ArgSize]
            elif argType & FPU_REG:
                self.name = REG_FPU_MAP[regbit]
            elif argType & SSE_REG:
                self.name = REG_SSE_MAP[regbit]
            elif argType & SEGMENT_REG:
                self.name = REG_SEGMENT_MAP[regbit]
        elif argType & CONSTANT_TYPE:
            if argType & FARPTR_:
                self.type = "FARPTR"
                self.segment = arg.SegmentRegs
                self.offset = asm.Instruction.Immediat
            else:
                self.type = "IMM"
                if argType & ABSOLUTE_:
                    self.value = asm.Instruction.Immediat
                elif argType & IMM_IN_TYPE:
                    self.value = argType & 0xff
                else: # RELATIVE_
                    self.value = asm.Instruction.AddrValue
        elif argType & MEMORY_TYPE:
            self.type = "MEM"
            mem = arg.Memory
            addr_size = asm.Instruction.AddressSize
            self.segment = REG_SEGMENT_MAP[arg.SegmentReg]
            self.segment_override = (asm.Prefix.SegmentState == InUsePrefix)
            if mem.BaseRegister == 0:
                self.base = None
            else:
                self.base = REG_GENERAL_MAP[mem.BaseRegister][addr_size]
                self.base_reg = REG_GENERAL_MAP[mem.BaseRegister][asm.Archi]
            if mem.IndexRegister == 0:
                self.index = None
            else:
                self.index = REG_GENERAL_MAP[mem.IndexRegister][addr_size]
                self.index_reg = REG_GENERAL_MAP[mem.IndexRegister][asm.Archi]
            self.scale = mem.Scale
            self.disp = mem.Displacement
            if self.base is None and self.index is None:
                if argType & RELATIVE_:
                    self.base = 'rip'
                    self.value = asm.Instruction.AddrValue
                else:
                    self.value = self.disp
            else:
                self.value = None
        
    def __str__(self):
        if self.type == "REG":
            return self.name
        elif self.type == "IMM":
            if self.value < 0:
                return "-%xh" % -self.value
            return "%xh" % self.value
        elif self.type == "MEM":
            size_txt = {8:'byte', 16:'word', 32:'dword', 64:'qword', 128:'xmmword', 48:'fword', 80:'tbyte'}
            op = ''
            s = "%s ptr [" % (size_txt[self.size])
            if self.segment_override:
                s += "%s:" % self.segment
            
            if self.base is not None:
                s += "%s" % self.base
                op = '+'
            if self.index is not None:
                s += "%s%s" % (op, self.index)
                if self.scale > 1:
                    s += "*%d" % self.scale
            if self.disp != 0 or (self.base is None and self.index is None):
                if self.disp < 0:
                    s += "-%xh" % (-self.disp)
                else:
                    s += "%s%xh" % (op, self.disp)
                op = '+'
            s += "]"
            return s
        elif self.type == "FARPTR":
            if self.size == 16:
                return "%02x:%02x" % (self.segment, self.offset)
            else:
                return "%02x:%04x" % (self.segment, self.offset)
        return ""
            
class Instruction(object):
    def __init__(self, asm, raw_bytes, valid=True):
        self.address = asm.VirtualAddr
        self.raw_bytes = raw_bytes
        if not valid:
            # invalid opcode
            self.mnemonic = None
            return
        
        instr = asm.Instruction
        self.mnemonic = Mnemonics[instr.Mnemonic] # should no exception
        self.size = len(raw_bytes)
        self.flags = []
        
        self.operand_size = asm.Instruction.OperandSize
        self.address_size = asm.Instruction.AddressSize
        
        prefix = asm.Prefix
        self.prefix = None # prefix Grp1
        if prefix.LockState == InUsePrefix:
            self.prefix = "lock"
        elif prefix.RepeatState == InUsePrefix:
            if prefix.Repeat == PrefixRep:
                self.prefix = "rep"
            elif prefix.Repeat == PrefixRepe:
                self.prefix = "repe"
            elif prefix.Repeat == PrefixRepne:
                self.prefix = "repne"
        
        self.branch_type = BranchTypes[instr.BranchType]
            
        self.conditional_type = instr.ConditionalType
        if self.mnemonic.startswith('cmov') or self.mnemonic.startswith('fcmov'):
            self.flags.append('CMOV')
            
        self.eflags_use = []
        self.eflags_def = []
        self.eflags_undef = []
        flags = instr.Flags
        
        for eflags, mask in ((self.eflags_use, TE_), (self.eflags_def, MO_|RE_|SE_|PR_), (self.eflags_undef, UN_)):
            if flags.OF_ & mask: eflags.append('OF')
            if flags.SF_ & mask: eflags.append('SF')
            if flags.ZF_ & mask: eflags.append('ZF')
            #if flags.AF_ & mask: eflags.append('AF')
            if flags.PF_ & mask: eflags.append('PF')
            if flags.CF_ & mask: eflags.append('CF')
            #if flags.TF_ & mask: eflags.append('TF')
            #if flags.IF_ & mask: eflags.append('IF')
            #if flags.DF_ & mask: eflags.append('DF')
            #if flags.NT_ & mask: eflags.append('NT')
            #if flags.RF_ & mask: eflags.append('RF')
        
        self.operands = []
        self.implicit_operands = []
        for arg in (asm.Argument1, asm.Argument2, asm.Argument3):
            if arg.ArgType == 0:
                break
            if (arg.ArgType & IMPLICIT_ARG) == 0:
                self.operands.append(Operand(arg, asm, self))
            else:
                self.implicit_operands.append(Operand(arg, asm, self))
            
    def __str__(self):
        if self.mnemonic is None:
            return "INVAID"
        s = ""
        if self.prefix is not None:
            s = self.prefix + ' '
            
        s += "%s " % self.mnemonic
        s += ", ".join([ str(op) for op in self.operands ])
        return s
        
    def next_IP(self):
        """compute next Insturction Pointer"""
        return self.address + self.size
    
def dis1(code, vaddr=0, archi=64):
    """disassemble only 1 instruction without checking arguments
    """
    code_buf = create_string_buffer(code, len(code))
    asm = DISASM()
    asm.EIP = addressof(code_buf)
    asm.VirtualAddr = vaddr
    asm.Archi = archi
    asm.Options = 0
    
    result = Disasm(addressof(asm))
    if result == OUT_OF_BLOCK or result == UNKNOWN_OPCODE:
        return Instruction(asm, code[0], False)
    return Instruction(asm, code[:result])
    
def disassemble_generator(code, vaddr=0, archi=64):
    if archi not in (32, 64):
        # invalid architecture (should raise exception?)
        return
	
    code_buf = create_string_buffer(code, len(code))
    asm = DISASM()
    asm.EIP = addressof(code_buf)
    asm.VirtualAddr = vaddr
    asm.Archi = archi
    
    left = len(code)
    offset = 0
    while left > 0:
        asm.SecurityBlock = left
        result = Disasm(addressof(asm))
        
        if result == OUT_OF_BLOCK or left < result:
            break
            
        # move to next asm
        if result == UNKNOWN_OPCODE:
            yield Instruction(asm, code[offset], False)
            asm.EIP += 1
            asm.VirtualAddr += 1
            left -= 1
            offset += 1
        else:
            yield Instruction(asm, code[offset:offset+result])
            asm.EIP += result
            asm.VirtualAddr += result
            left -= result
            offset += result

def disassemble(code, vaddr=0, archi=64):
    return list( disassemble_generator(code, vaddr, archi) )

