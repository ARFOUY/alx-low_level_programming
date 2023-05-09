#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 64

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        exit(98);
    }

    char buf[BUF_SIZE];
    if (read(fd, buf, BUF_SIZE) != BUF_SIZE) {
        fprintf(stderr, "Error: could not read ELF header from file %s\n", argv[1]);
        exit(98);
    }

    // Check if it's an ELF file
    if (buf[0] != 0x7f || buf[1] != 'E' || buf[2] != 'L' || buf[3] != 'F') {
        fprintf(stderr, "Error: file %s is not an ELF file\n", argv[1]);
        exit(98);
    }

    // Extract required information from the ELF header
    unsigned char elf_class = buf[4];
    unsigned char elf_data = buf[5];
    unsigned char elf_version = buf[6];
    unsigned char elf_osabi = buf[7];
    unsigned char elf_abiversion = buf[8];
    unsigned short elf_type = *(unsigned short *)(buf + 16);
    unsigned long long elf_entry = *(unsigned long long *)(buf + 24);

    // Display the extracted information
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < 16; i++) {
        printf("%02x ", buf[i]);
    }
    printf("\n");
    printf("  Class:                             ");
    switch (elf_class) {
        case 1:
            printf("ELF32\n");
            break;
        case 2:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid class\n");
            exit(98);
    }
    printf("  Data:                              ");
    switch (elf_data) {
        case 1:
            printf("2's complement, little endian\n");
            break;
        case 2:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Invalid data format\n");
            exit(98);
    }
    printf("  Version:                           %d (current)\n", elf_version);
    printf("  OS/ABI:                            ");
    switch (elf_osabi) {
        case 0:
            printf("UNIX - System V\n");
            break;
        case 3:
            printf("UNIX - GNU\n");
            break;
        case 6:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
printf("  ABI Version:                       %d\n", elf_abiversion);
 printf(" 

