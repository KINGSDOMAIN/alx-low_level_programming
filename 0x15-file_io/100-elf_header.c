#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

void print_elf_header(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(98);
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) {
        fprintf(stderr, "Error: Unable to read ELF header from file %s\n", filename);
        exit(98);
    }

    if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' || header.e_ident[2] != 'L' || header.e_ident[3] != 'F') {
        fprintf(stderr, "Error: File %s is not an ELF file\n", filename);
        exit(98);
    }

    printf("Magic: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");

    printf("Class:                            %u-bit\n", header.e_ident[4] == 1 ? 32 : 64);

    printf("Data:                             %s\n", header.e_ident[5] == 1 ? "2's complement, little endian" : "2's complement, big endian");

    printf("Version:                          %d (current)\n", header.e_ident[6]);

    printf("OS/ABI:                           ");
    switch (header.e_ident[7]) {
        case 0: printf("System V"); break;
        case 1: printf("HP-UX"); break;
        case 2: printf("NetBSD"); break;
        case 3: printf("Linux"); break;
        case 6: printf("Solaris"); break;
        case 7: printf("AIX"); break;
        case 8: printf("IRIX"); break;
        case 9: printf("FreeBSD"); break;
        case 10: printf("Tru64"); break;
        case 11: printf("Novell Modesto"); break;
        case 12: printf("OpenBSD"); break;
        case 13: printf("OpenVMS"); break;
        case 14: printf("NonStop Kernel"); break;
        case 15: printf("AROS"); break;
        case 16: printf("Fenix OS"); break;
        case 17: printf("CloudABI"); break;
        case 18: printf("Stratus Technologies OpenVOS"); break;
        default: printf("<unknown>"); break;
    }
    printf("\n");

    printf("ABI Version:                      %d\n", header.e_ident[8]);

    printf("Type:                             ");
    switch (header.e_type) {
        case 0: printf("NONE (No file type)"); break;
        case 1: printf("REL (Relocatable file)"); break;
        case 2: printf("EXEC (Executable file)"); break;
        case 3: printf("DYN (Shared object file)"); break;
        case 4: printf("CORE (Core file)"); break;
        default: printf("<unknown>"); break;
    }
    printf("\n");

    printf("Entry point address:              0x%lx\n", header.e_entry);

    printf("Format:                           ELF64\n");

    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        exit(98);
    }

    lseek(fd, 0, SEEK_SET);

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof
