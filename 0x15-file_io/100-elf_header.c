#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

#define BUF_SIZE 128

void print_error(char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if (fd < 0)
    {
        print_error("Cannot open file");
    }

    // read the ELF header
    Elf64_Ehdr ehdr;
    ssize_t n = read(fd, &ehdr, sizeof(ehdr));

    if (n < 0)
    {
        print_error("Cannot read file");
    }

    if (n != sizeof(ehdr) || memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0)
    {
        print_error("Not an ELF file");
    }

    // print the information
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", ehdr.e_ident[i]);
    }
    printf("\n");

    printf("Class:                             ");
    switch (ehdr.e_ident[EI_CLASS])
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Data:                              ");
    switch (ehdr.e_ident[EI_DATA])
    {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    printf("Version:                           %d (current)\n", ehdr.e_ident[EI_VERSION]);

    printf("OS/ABI:                            ");
    switch (ehdr.e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX System V ABI\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX ABI\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD ABI\n");
            break;
        case ELFOSABI_LINUX:
printf("Linux ABI\n");
break;
case ELFOSABI_SOLARIS:
printf("Solaris ABI\n");
break;
case ELFOSABI_IRIX:
printf("IRIX ABI\n");
break;
case ELFOSABI_FREEBSD:
printf("FreeBSD ABI\n");
break;
case ELFOSABI_TRU64:
printf("TRU64 UNIX ABI\n");
break;
case ELFOSABI_ARM:
printf("ARM architecture ABI\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone (embedded) ABI\n");
break;
default:
printf("Other\n");
break;
}

printf("ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);

printf("Type:                              ");
switch (ehdr.e_type)
{
case ET_NONE:
printf("NONE (No file type)\n");
break;
case ET_REL:
printf("REL (Relocatable

