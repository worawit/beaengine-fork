beaengine-fork
==============

This is a fork of BeaEngine project (http://www.beaengine.org).

I fork this project because I want to modify to suit my needs.
Additional, I cannot wait for beatrix to fix bugs. If anyone
does not like my changes, at least you are can take bug patches.

Note: This project is not compatitble with original BeaEngine.

WARNING: This fork project is still under developement, public structures 
are not finalized.


COMPILE
--------------
Linux: (reqires make and GCC; tested on Linux Mint 13 64bit)
- cd /to/project/directory
- make

Windows: (reqires Windows SDK and (maybe) VC Express; tested on Windows 7 64bit)
- open Windows SDK command prompt
- cd /to/project/directory
- nmake -f nmakefile

The library file is in /build directory. The include files that used for 
using this project is /beaengine directory



MODIFICATIONS
--------------
Here is a list of my modifications:

### No default architecture to 32-bit

Now, you have to set DISASM.Archi to 16, 32 or 64. Disasm() function does 
not check this value. You have to make sure it is not other values.

### No more Mnemonic/ArgMnemonic/CompleteInstruction string

No string operation while decoding the binary. So no full and light version.
There is only one build now. This change also makes BeaEngine smaller and faster.

There is a new library API for building a complete instruction. It is

    BEA_API void __bea_callspec__ BuildAssembly(PDISASM pMyDisasm, char *buffer);

This function must be called after Disasm() returns successfully. The function
does not check for invalid value in DISASM structure. Do try to do it.

Now, BuildAssembly() function supports only MASM syntax. But you can use
decoded data to build your own assembly. You can see BuildAssembly() code
in Includes/Routines_Disasm.c as an example.

Because the Argument structure does not support to store far ptr type, I put
the segment selector in ARGTYPE.SegmentReg and offset value in Immediat with
setting subtype of CONSTANT_TYPE to FARPTR_.

Similar to enter instruction, it uses 2 immediate operand but the structure
supports only one. So I put the second operand, which size is 8 bit, to low word
of ARGTYPE.ArgType with setting subtype of CONSTANT_TYPE to IMM_IN_TYPE.

### DISASM.AsmXXX

I remove Option from DISASM struct. Use below 4 value to set the assembly
output format.
- AsmPrefixedNumeral (0 for Suffixed with 'h'. Others for Prefixed with '0x')
- AsmSyntax (ignored for now)
- AsmShowImplicitSegmentRegs (non 0 for always display memory segment)
- AsmTabulation (non 0 for Tabulation)

### INSTRTYPE.Mnemonic

Now Mnemonic is integer. It is supposed to be easier for comparison. 
Mnemonic constant can be found in beaengine/BeaEngine.h. The constant
pattern is I_{upper(mnemonic)}. For example

    I_MOV => "mov"
    I_ADD => "add"
    I_CALL_FAR => "call far"

The Mnemonic can be converted to string by using exported variable MNEMONICS.

    BEA_API const__ char MNEMONICS[NUM_MNEMONIC][16];

For example:

	const char *mnemonic = MNEMONICS[I_MOV];
	// mnemonic now is "mov"

### IMPLICIT_ARG flag (in progress)

The implicited argument now is flag with IMPLICIT_ARG. This can help 
constructing assembly.

All arguments should not be composited like below (from previous 'popad').

    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;

I move them to INSTRTYPE.ImplicitUsedReg.

Also remind that implicited argument for some instructions are not complete.
I have no idea to fix this problem because I do not know many assembly
instructions and it is required to add/change data structure.

### INSTRTYPE.ImplicitUsedReg (in progress)

All composited arguments go here. Also some instruction needs it.

### NO_ARGUMENT is 0

NO_ARGUMENT is not flag anymore. When checking unused variable, use comparison
operator such as

    if (disasm.Argument1 != NO_ARGUMENT)
        // decode Argument1
    // or
    if (disasm.Arguemnt2)
        // decode Argument2

### signess of immediate

For instruction that size of immediate is less than another operand, 
immediate is sign-extened. In original version, immediate is always unsigned.

For example with hex "83 C0 DE", the assembly should be

    add eax, -22    ; or
    add eax, 0xffffffde

The operand size of "eax" is 32 bit and operand size of immediate value
is 8 bit. The original version stores immediate value as "0xde".
With this change, the immediate value is "0xffffffffffffffde".
So this change purpose is to make value in memory correct.

While the operand size and immediate size is same, the immediate value is 
still unsigned. I have no reason to change it because all value is computed 
as 2's complement. It anyone has a good reason to change this case, tell me.

### ARGTYPE.AccessMode

READ and WRITE is flag. Many assembly argument is used and defined.

Here is a common list that argument is READ+WRITE (not complete)
- add/sub/or/xor/and/not/inc/dec/adc/sbb - 1st argument is READ+WRITE
- xchg - both arguments are READ+WRITE

### Conditional instructions (Jcc, CMOVcc, SETcc, LOOPcc)

In assembly, some condition can be written differently but have same meaning 
such as 'jb', 'jc', 'jnae'. I changed this to use only condition that easy 
to map to C comparison operator (<, <=, ==, !=, >=, >). So the mnemonic 
has only

    jo, jno, jb, jbe, ja, jae, je, jne, jl, jle, jg, jge, js, jns, jp, jnp

With this change, I re-designed the BranchType value to make it more useful 
(for me). See the next modification for detail.

### INSTRTYPE.ConditionalType

Added to checking the conditional type of Jcc, CMOVcc, SETcc, LOOPcc, FCMOVcc 
instructions. Here is definition.

    enum CONDITIONAL_TYPE
    {
        CC_E = 1,
        CC_NE,
        CC_A,
        CC_AE,
        CC_B,
        CC_BE,
        CC_O,
        CC_NO,
        CC_S,
        CC_NS,
        CC_P,
        CC_NP,
        CC_ECXZ,
        CC_SIGNED_IDX, /* marker for checking signed comparison */
        CC_G = CC_SIGNED_IDX,
        CC_GE,
        CC_L,
        CC_LE
    };

The conditional type is same as conditional instruction from previous change item.
The special value is CC_SIGNED_IDX. You can use to check for signed comparison.

    if (disasm.Instruction.ConditionalType >= CC_SIGNED_IDX)
        // the variable that is compared before is signed

### INSTRTYPE.BranchType

Now branch type is very simple as defined below.

    enum BRANCH_TYPE
    {
        JmpType = 1,
        CallType,
        RetType,
        LoopType
    };

There are no more Jxx type. For an original code that compared it with 
conditional jump (JC, JB, ...), you have to change the comparision to 
Mnemonic.

    // code for original version
    if (disasm.Instruction.BranchType == JC)
        // do something
    
    // new code with same result
    // note: no JC in my modification
    if (disasm.Instruction.Mnemonic == I_JB)
        // do something
    
    // or use ConditionalType that work on LoopType too
    if (disasm.Instruction.CondtionalType == CC_B)
        // do something

### Register flags for condition instructions

The tested flag for conditional instructions now are set according conditional.

### New prefix structure

If there are more than one prefixes from same prefix group in one instruction,
the last prefix takes affect. The original BeaEngine just keep all found
prefixed. It is awkward to code on that structure to get what prefix is
effective. See the new structure in beaengine/BeaEngine.h

### Effective OperandSize and AddressSize

Now you can access effective OperandSize and AddressSize from INSTRTYPE
structure. The OperandSize value can be 8, 16, 32, 64. The AddressSize value
can be 16, 32, 64.
