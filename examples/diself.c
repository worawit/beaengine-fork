#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <beaengine/BeaEngine.h>
#include "readcode.h"

static const char hexmap[20] = "0123456789ABCDEF";
void bin2hex(unsigned char *bin, int len, char *buffer)
{
    int i;
    for (i = 0; i < len; i++) {
        *buffer++ = hexmap[bin[i] >> 4];
        *buffer++ = hexmap[bin[i] & 0xf];
    }
    *buffer = '\0';
}

void disassemble(CodeInfo *codeinfo)
{
    DISASM myDisasm;
    int len;
    int left;
    char assembly[128];
    char instrhex[32];
    int cnt = 0;
    
    memset(&myDisasm, 0, sizeof(DISASM));
    myDisasm.EIP = (UIntPtr) codeinfo->code;
    myDisasm.VirtualAddr = (UInt64) codeinfo->vaddr;
    myDisasm.Archi = codeinfo->archi;
	myDisasm.AsmTabulation = 1;
    myDisasm.AsmPrefixedNumeral = 1;
    
    left = codeinfo->codesize;
    myDisasm.SecurityBlock = left;
    while (left > 0) {
        len = Disasm(&myDisasm);
        if (len == OUT_OF_BLOCK) {
            printf("Out of block\n");
            break;
        }
        if (len == UNKNOWN_OPCODE) {
            /* skip to next byte for invalid opcode */
            bin2hex((unsigned char*) myDisasm.EIP, 1, instrhex);
            printf("%8lx: %-32s  (FAIL)\n", myDisasm.VirtualAddr, instrhex);
            myDisasm.EIP++;
            myDisasm.VirtualAddr++;
            left--;
            myDisasm.SecurityBlock = left;
        }
        else {
            BuildAssembly(&myDisasm, assembly);
            bin2hex((unsigned char*) myDisasm.EIP, len, instrhex);
            printf("%8lx: %-32s  %s\n", myDisasm.VirtualAddr, instrhex, assembly);
            myDisasm.EIP += len;
            myDisasm.VirtualAddr += len;
            left -= len;
            myDisasm.SecurityBlock = left;
            cnt++;
        }        
    }
    
    printf("Number of valid instruction: %d\n", cnt);
}

int main(int argc, char **argv)
{
    CodeInfo codeinfo;
    if (argc != 2) {
        printf("Usage: %s elffile\n", argv[0]);
        return 1;
    }
    
    if (readelf_code(argv[1], &codeinfo) == 0) {
        //printf("vaddr: %lx, codesize: %x\n", codeinfo.vaddr, codeinfo.codesize);
        disassemble(&codeinfo);
        free(codeinfo.code);
    }
    
    return 0;
}
