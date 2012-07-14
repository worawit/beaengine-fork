beaengine-fork
==============

This is a fork of BeaEngine project (http://www.beaengine.org).

I fork this project because I want to modify to suit my needs.
Additional, I cannot wait for beatrix to fix bugs. If anyone
does not like my changes, at least you are can take bug patches.

Note: This project is not compatitble with original BeaEngine.


COMPILE
--------------
Linux: (reqires make and GCC; tested on Linux Mint 13 64bit)
- cd /to/project/directory
- make

Windows: (reqires Windows SDK and (maybe) VC Express; tested on Windows 7 64bit)
- open Windows SDK command prompt
- cd /to/project/directory
- nmake -f nmakefile

The include files that used for using this project is /beaengine directory


GOAL
--------------
My goal is making BeaEngine light version easier to use (at least for me).
I do not care about CompleteInstruction in full version after changed.
So please do not report bugs regarding to CompleteInstruction, ArgumentMnemonic.


MODIFICATIONS
--------------
Here is a list of my modifications:

### INSTRTYPE.MnemonicId

Added in order to know the mnemonic in light version. MnemonicId constant
can be found in beaengine/BeaEngine.h. The constant pattern is I_{upper(mnemonic)}.
For example

    I_MOV => "mov"
    I_ADD => "add"
    I_CALL_FAR => "call far"

The MnemonicId can be converted to string by using exported variable MNEMONICS.

    BEA_API const__ char *MNEMONICS[];

For example:

	const char *mnemonic = MNEMONICS[I_MOV];
	// mnemonic now is "mov"

### IMPLICIT_ARG flag (in progress)

The implicited argument now is flag with IMPLICIT_ARG. With this and 
MnemonicId, we can construct assembly in light version easily.

Please note that the implicited argument, might be composite argument.
See below example from "pushad"

    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;

Also remind that implicited argument for some instructions are not complete.
I have no idea to  fix this problem because I do not know many assembly
instructions and it is required to add/change data structure.

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

### INSTRTYPE.BranchType

Instructions that used this variable are Jcc, CMOVcc, SETcc, LOOPcc, FCMOVcc.
This variable is separated into branch type (HIWORD) and conditional value (LOWORD).
branch type (HIWORD) is a bit flag while conditional is value. Below is what
they are defined

    #define CONDITION_SIGNED_FLAG 0x1000
    #define CONDITION_MASK 0xFFFF
    #define CONDITION_OP_MASK 0x7FFF
    enum CONDITION_TYPE
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
        CC_G = CONDITION_SIGNED_FLAG|CC_A,
        CC_GE,
        CC_L,
        CC_LE
    };

    #define BRANCH_MASK 0xFFFF0000
    enum BRANCH_TYPE
    {
        JmpType = 0x10000,
        CallType = 0x20000,
        RetType = 0x40000,
        LoopType = 0x80000,
        
        JE  = JmpType|CC_E,
        // ...

I hope you notice that jump and conditional jump is the same branch type.
You can check condition value to know if a jump is conditional. Here is a 
sample code for checking this variable.

    if (disasm.Instruction.BranchType & JmpType) {
        if (disasm.Instruction.BranchType & CONDITION_MASK) {
            // conditional jump
            if (disasm.Instruction.BranchType & CONDITION_SIGNED_FLAG) {
                // the variable that is compared before is signed
            }
        }
        else
            // unconditional jump
    }
    else if (disasm.Instruction.BranchType & CallType)
        // call
	// ...
	
	// or you can use switch
	switch (disasm.Instruction.BranchType & BRANCH_MASK) {
	    case JmpType:
	        break;
	    case CallType:
	        break;
	}

There might be a pitfall for checking branching instruction. You have to 
do logical and with CONDITION_MASK before comparing to 0. Because CMOVcc, 
SETcc are not branch but they are conditional instruction. The value in 
LOWORD is not 0.

Last I still keep "JE, JNE, JB, ...". But normally you do not need them 
because you can compare MnemonicId instead of BranchType.

    // code for original version
    if (disasm.Instruction.BranchType == JC)
        // do something
    
    // new code with same result
    // note: no JC in my modification
    if (disasm.Instruction.MnemonicId == I_JB)
        // do something

### Register flags for condition instructions

The tested flag for conditional instructions now are set according conditional.
