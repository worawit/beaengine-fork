#include <stdio.h>
#include <stdlib.h>
#include "readcode.h"

typedef struct ELFIdent_ {
    char magic[4];
    char class;
    char byteorders;
    char hversion;
    char pad[9];
} ELFIdent;

/***** from elf.h *******/

/* Type for a 16-bit quantity.  */
typedef uint16_t Elf32_Half;
typedef uint16_t Elf64_Half;

/* Types for signed and unsigned 32-bit quantities.  */
typedef uint32_t Elf32_Word;
typedef int32_t  Elf32_Sword;
typedef uint32_t Elf64_Word;
typedef int32_t  Elf64_Sword;

/* Types for signed and unsigned 64-bit quantities.  */
typedef uint64_t Elf32_Xword;
typedef int64_t  Elf32_Sxword;
typedef uint64_t Elf64_Xword;
typedef int64_t  Elf64_Sxword;

/* Type of addresses.  */
typedef uint32_t Elf32_Addr;
typedef uint64_t Elf64_Addr;

/* Type of file offsets.  */
typedef uint32_t Elf32_Off;
typedef uint64_t Elf64_Off;

/* Type for section indices, which are 16-bit quantities.  */
typedef uint16_t Elf32_Section;
typedef uint16_t Elf64_Section;

/* Type for version symbol information.  */
typedef Elf32_Half Elf32_Versym;
typedef Elf64_Half Elf64_Versym;

/* remove e_ident for this program */
typedef struct
{
  Elf32_Half    e_type;         /* Object file type */
  Elf32_Half    e_machine;      /* Architecture */
  Elf32_Word    e_version;      /* Object file version */
  Elf32_Addr    e_entry;        /* Entry point virtual address */
  Elf32_Off e_phoff;        /* Program header table file offset */
  Elf32_Off e_shoff;        /* Section header table file offset */
  Elf32_Word    e_flags;        /* Processor-specific flags */
  Elf32_Half    e_ehsize;       /* ELF header size in bytes */
  Elf32_Half    e_phentsize;        /* Program header table entry size */
  Elf32_Half    e_phnum;        /* Program header table entry count */
  Elf32_Half    e_shentsize;        /* Section header table entry size */
  Elf32_Half    e_shnum;        /* Section header table entry count */
  Elf32_Half    e_shstrndx;     /* Section header string table index */
} Elf32_Ehdr;

typedef struct
{
  Elf64_Half    e_type;         /* Object file type */
  Elf64_Half    e_machine;      /* Architecture */
  Elf64_Word    e_version;      /* Object file version */
  Elf64_Addr    e_entry;        /* Entry point virtual address */
  Elf64_Off e_phoff;        /* Program header table file offset */
  Elf64_Off e_shoff;        /* Section header table file offset */
  Elf64_Word    e_flags;        /* Processor-specific flags */
  Elf64_Half    e_ehsize;       /* ELF header size in bytes */
  Elf64_Half    e_phentsize;        /* Program header table entry size */
  Elf64_Half    e_phnum;        /* Program header table entry count */
  Elf64_Half    e_shentsize;        /* Section header table entry size */
  Elf64_Half    e_shnum;        /* Section header table entry count */
  Elf64_Half    e_shstrndx;     /* Section header string table index */
} Elf64_Ehdr;

#define EM_386       3      /* Intel 80386 */
#define EM_X86_64   62      /* AMD x86-64 architecture */

/* Section header.  */

typedef struct
{
  Elf32_Word    sh_name;        /* Section name (string tbl index) */
  Elf32_Word    sh_type;        /* Section type */
  Elf32_Word    sh_flags;       /* Section flags */
  Elf32_Addr    sh_addr;        /* Section virtual addr at execution */
  Elf32_Off sh_offset;      /* Section file offset */
  Elf32_Word    sh_size;        /* Section size in bytes */
  Elf32_Word    sh_link;        /* Link to another section */
  Elf32_Word    sh_info;        /* Additional section information */
  Elf32_Word    sh_addralign;       /* Section alignment */
  Elf32_Word    sh_entsize;     /* Entry size if section holds table */
} Elf32_Shdr;

typedef struct
{
  Elf64_Word    sh_name;        /* Section name (string tbl index) */
  Elf64_Word    sh_type;        /* Section type */
  Elf64_Xword   sh_flags;       /* Section flags */
  Elf64_Addr    sh_addr;        /* Section virtual addr at execution */
  Elf64_Off sh_offset;      /* Section file offset */
  Elf64_Xword   sh_size;        /* Section size in bytes */
  Elf64_Word    sh_link;        /* Link to another section */
  Elf64_Word    sh_info;        /* Additional section information */
  Elf64_Xword   sh_addralign;       /* Section alignment */
  Elf64_Xword   sh_entsize;     /* Entry size if section holds table */
} Elf64_Shdr;

#define SHT_PROGBITS      1     /* Program data */

#define SHF_ALLOC        (1 << 1)   /* Occupies memory during execution */
#define SHF_EXECINSTR        (1 << 2)   /* Executable */

/************************/

static int readelf32_code(FILE *fp, CodeInfo *codeinfo);
static int readelf64_code(FILE *fp, CodeInfo *codeinfo);

int readelf64_code(FILE *fp, CodeInfo *codeinfo)
{
    size_t ritem;
    Elf64_Ehdr ehdr;
    Elf64_Shdr shdr;
    int i;
    uint64_t vaddr;
    uint32_t start, end, codesize;
    
    ritem = fread(&ehdr, sizeof(ehdr), 1, fp);
    if (ritem != 1) {
        printf("Cannot read ELF header\n");
        return -1;
    }
    
    if (ehdr.e_machine != EM_X86_64) {
        printf("Unsupport architecture\n");
        return -1;
    }
    
    if (ehdr.e_shentsize != sizeof(shdr)) {
        printf("Bad ELF file\n");
        return -1;
    }
    
    /* read only section header */
    if (fseek(fp, ehdr.e_shoff, SEEK_SET) == -1) {
        printf("Bad ELF file\n");
        return -1;
    }
    
    for (i = 0; i < ehdr.e_shnum; i++) {
        ritem = fread(&shdr, sizeof(shdr), 1, fp);
        if (ritem != 1) {
            printf("Cannot read ELF section header\n");
            return -1;
        }
        
        /* interest only code section */
        if (shdr.sh_type == SHT_PROGBITS && (shdr.sh_flags & SHF_ALLOC) && (shdr.sh_flags & SHF_EXECINSTR)) {
            start = (uint32_t) shdr.sh_offset;
            end = start + (uint32_t) shdr.sh_size;
            vaddr = (uint64_t) shdr.sh_addr;
            i++;
            break;
        }
    }
    
    for (; i < ehdr.e_shnum; i++) {
        ritem = fread(&shdr, sizeof(shdr), 1, fp);
        if (ritem != 1) {
            printf("Cannot read ELF section header\n");
            return -1;
        }
        
        /* interest only code section */
        if (shdr.sh_type == SHT_PROGBITS && (shdr.sh_flags & SHF_ALLOC) && (shdr.sh_flags & SHF_EXECINSTR)) {
            if (vaddr > (uint64_t) shdr.sh_addr) {
                vaddr = shdr.sh_addr;
            }
            if (start > (uint32_t) shdr.sh_offset) {
                start = (uint32_t) shdr.sh_offset;
            }
            if (end < (uint32_t)(shdr.sh_offset + shdr.sh_size)) {
                end = (uint32_t)(shdr.sh_offset + shdr.sh_size);
            }
        }
    }
    
    if (fseek(fp, start, SEEK_SET) == -1) {
        printf("Bad ELF file\n");
        return -1;
    }
    
    codesize = end - start;
    codeinfo->vaddr = vaddr;
    codeinfo->codesize = codesize;
    codeinfo->code = (char*) malloc(codesize);
    if (codeinfo->code == 0) {
        printf("malloc failed\n");
        return -1;
    }
    
    ritem = fread(codeinfo->code, 1, codesize, fp);
    if (ritem != codesize) {
        free(codeinfo->code);
        return -1;
    }
    
    return 0;
}

int readelf32_code(FILE *fp, CodeInfo *codeinfo)
{
    size_t ritem;
    Elf32_Ehdr ehdr;
    Elf32_Shdr shdr;
    int i;
    uint64_t vaddr;
    uint32_t start, end, codesize;
    
    ritem = fread(&ehdr, sizeof(ehdr), 1, fp);
    if (ritem != 1) {
        printf("Cannot read ELF header\n");
        return -1;
    }
    
    if (ehdr.e_machine != EM_386) {
        printf("Unsupport architecture\n");
        return -1;
    }
    
    if (ehdr.e_shentsize != sizeof(shdr)) {
        printf("Bad ELF file\n");
        return -1;
    }
    
    /* read only section header */
    if (fseek(fp, ehdr.e_shoff, SEEK_SET) == -1) {
        printf("Bad ELF file\n");
        return -1;
    }
    
    for (i = 0; i < ehdr.e_shnum; i++) {
        ritem = fread(&shdr, sizeof(shdr), 1, fp);
        if (ritem != 1) {
            printf("Cannot read ELF section header index: %d\n", i);
            return -1;
        }
        
        /* interest only code section */
        if (shdr.sh_type == SHT_PROGBITS && (shdr.sh_flags & SHF_ALLOC) && (shdr.sh_flags & SHF_EXECINSTR)) {
            start = (uint32_t) shdr.sh_offset;
            end = start + (uint32_t) shdr.sh_size;
            vaddr = (uint64_t) shdr.sh_addr;
            i++;
            break;
        }
    }
    
    for (; i < ehdr.e_shnum; i++) {
        ritem = fread(&shdr, sizeof(shdr), 1, fp);
        if (ritem != 1) {
            printf("Cannot read ELF section header index: %d\n", i);
            return -1;
        }
        
        /* interest only code section */
        if (shdr.sh_type == SHT_PROGBITS && (shdr.sh_flags & SHF_ALLOC) && (shdr.sh_flags & SHF_EXECINSTR)) {
            if (vaddr > (uint64_t) shdr.sh_addr) {
                vaddr = shdr.sh_addr;
            }
            if (start > (uint32_t) shdr.sh_offset) {
                start = (uint32_t) shdr.sh_offset;
            }
            if (end < (uint32_t)(shdr.sh_offset + shdr.sh_size)) {
                end = (uint32_t)(shdr.sh_offset + shdr.sh_size);
            }
        }
    }
    
    if (fseek(fp, start, SEEK_SET) == -1) {
        printf("Bad ELF file\n");
        return -1;
    }
    
    codesize = end - start;
    codeinfo->vaddr = vaddr;
    codeinfo->codesize = codesize;
    codeinfo->code = (char*) malloc(codesize);
    if (codeinfo->code == 0) {
        printf("malloc failed\n");
        return -1;
    }
    
    ritem = fread(codeinfo->code, 1, codesize, fp);
    if (ritem != codesize) {
        free(codeinfo->code);
        return -1;
    }
    
    return 0;
}

/* 0 = success */
int readelf_code(char *filename, CodeInfo *codeinfo)
{
    FILE *fp;
    int ret = 0;
    size_t ritem;
    ELFIdent elfIdent;
    
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }
    
    ritem = fread(&elfIdent, sizeof(ELFIdent), 1, fp);
    if (ritem != 1) {
        printf("Cannot read ELF Ident\n");
        ret = -1;
        goto error;
    }
    
    if (memcmp(elfIdent.magic, "\x7f""ELF", 4) != 0) {
        printf("Invalid ELF file\n");
        ret = -1;
        goto error;
    }
    
    if (elfIdent.byteorders != 1) {
        printf("Support only little-endian byte order\n");
        ret = -1;
        goto error;
    }
    
    if (elfIdent.class == 1) {
        /* 32 bit */
        codeinfo->archi = 32;
        readelf32_code(fp, codeinfo);
    }
    else if (elfIdent.class == 2) {
        /* 64 bit */
        codeinfo->archi = 64;
        readelf64_code(fp, codeinfo);
    }
    else {
        printf("Invalid ELF class\n");
        ret = -1;
        goto error;
    }
    
error:
    fclose(fp);
    return ret;
}

