beaengine-fork
==============

This is a fork of BeaEngine project (http://www.beaengine.org).

I fork this project because I want to modify to suit my needs.
Additional, I cannot wait for beatrix to fix bugs. If anyone
does not like my changes, at least you are can take bug patches.

Note: This project is not 100% compatitble with original BeaEngine.


COMPILE
==============
Linux: (reqires make and GCC; tested on Linux Mint 13 64bit)
- cd /to/project/directory
- make

Windows: (reqires Windows SDK and (maybe) VC Express; tested on Windows 7 64bit)
- cd /to/project/directory
- nmake -f nmakefile

The include files that used for using this project is /beaengine directory


GOAL
==============
My goal is making BeaEngine light version easier to use (at least for me).
I do not care about CompleteInstruction in full version after changed.
So please do not report bugs about CompleteInstruction, ArgumentMnemonic.


MODIFICATIONS
==============
Here is a list of my modifications:

INSTRTYPE.MnemonicId
-------------
Added in order to know the mnemonic in light version

IMPLICIT_ARG flag (in progress)
-------------
The implicited argument now is flag with IMPLICIT_ARG. With this and 
MnemonicId, we can construct assembly in light version easily.

Please note that the implicited argument, might be composite argument.
See below example from "pushad"
<pre>
(*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0+REG1+REG2+REG3+REG4+REG5+REG6+REG7;
</pre>

signess of immediate
-------------
For instruction that size of immediate is less than another operand, 
immediate is sign-extened. In original version, immediate is always unsigned.

For example with hex "83 C0 DE", the assembly should be "add eax, -22" or 
"add eax, 0xffffffde". The operand size of "eax" is 32 bit and operand size
of immediate value is 8 bit. The original version stores immediate value 
as "0xde". With this change, the immediate value is "0xffffffffffffffde".
So this change purpose is to make value in memory correct.

While the operand size and immediate size is same, the immediate value is 
still unsigned. I have no reason to change it because all value is computed 
as 2's complement. It anyone has a good reason to change this case, tell me.

ARGTYPE.AccessMode
-------------
READ and WRITE is flag. Many assembly argument is used and defined.
Here is a common list that argument is READ+WRITE
- add/sub/or/xor/and/not/inc/dec/adc/sbb - 1st argument is READ+WRITE
- xchg - both arguments are READ+WRITE

Conditional instructions (jxx, cmovxx, setxx, loopxx)
-------------
In assembly, some condition is written differently but have same meaning 
such as 'jb', 'jc', 'jnae'. I changed this to use only condition that easy 
to map to C comparison operator (<, <=, ==, !=, >=, >). So the mnemonic 
has only
<pre>
jo, jno, jb, jbe, ja, jae, je, jne, jl, jle, jg, jge, js, jns, jp, jnp
</pre>

BranchType
-------------
After modification

Register flags for condition instructions
-------------
After modification
