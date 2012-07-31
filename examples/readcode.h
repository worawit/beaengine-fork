#ifndef __READCODE_H__
#define __READCODE_H__

#include <stdint.h>

typedef struct CodeInfo_ {
    int archi;
    char *code;
    uint32_t codesize;
    uint64_t vaddr;
} CodeInfo;

/* Quick read all code sections from ELF.
 * Assume all code section is contiguous. Ignore section alignment.
 * Because normally GCC put valid assembly in alignment space, it is still
 * ok to disassemble them
 * 
 * return 0 for success
 */
int readelf_code(char *filename, CodeInfo *codeinfo);

#endif
