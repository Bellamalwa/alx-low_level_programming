#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * elf_header - displays the information contained in the ELF header
 * at the start of an ELF file
 * @filename: the name of the ELF file
 * Return: 0 on success, 98 on failure
 */
int elf_header(char *filename)
{
    int fd, i;
    Elf64_Ehdr *header;
    char magic[16] = {0x7f, 'E', 'L', 'F', 0};

    /* Open the ELF file */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return 98;
    }

    /* Read the ELF header */
    header = malloc(sizeof(Elf64_Ehdr));
    if (!header)
    {
        fprintf(stderr, "Error: Cannot allocate memory\n");
        return 98;
    }
    if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
    {
        fprintf(stderr, "Error: Cannot read ELF header\n");
        free(header);
        return 98;
    }

    /* Check if the file is an ELF file */
    size_t magic_size = sizeof(magic);
    for (size_t i = 0; i < magic_size; i++)
    {
        if (header->e_ident[i] != magic[i])
        {
            fprintf(stderr, "Error: %s is not an ELF file\n", filename);
            free(header);
            return 98;
        }
    }

    /* Print the ELF header information */
    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");
    printf("Class:                             %s\n",
           header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           header->e_ident[EI_CLASS] == ELFCLASSNONE ? "none" : "unknown");
    printf("Data:                              %s\n",
           header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
           header->e_ident[EI_DATA] == ELFDATANONE ? "none" : "unknown");
    printf("Version:                           %d%s\n",
           header->e_ident[EI_VERSION],
           header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
    printf("OS/ABI:                            %s\n",
           header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
           header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
           header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - GNU" :
           header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
           header->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
           header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
           header->e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
           header->e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
           header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" : "UNIX - unknown");
    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("Type:                              %s\n",
           header->e_type == ET_NONE ? "NONE (None)" :
           header->e_type == ET_REL ? "REL (Relocatable file)" :
           header->e_type == ET_EXEC ? "EXEC (Executable file)" :
           header->e_type == ET_DYN ? "DYN (Shared object file)" :
           header->e_type == ET_CORE ? "CORE (Core file)" :
           "unknown");
    printf("Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
    printf("Start of program headers:          %lu (bytes into file)\n", (unsigned long)header->e_phoff);
    printf("Start of section headers:          %lu (bytes into file)\n", (unsigned long)header->e_shoff);
    printf("Flags:                             0x%x\n", header->e_flags);
    printf("Size of this header:               %d (bytes)\n", header->e_ehsize);
    printf("Size of program headers:           %d (bytes)\n", header->e_phentsize);
    printf("Number of program headers:         %d\n", header->e_phnum);
    printf("Size of section headers:           %d (bytes)\n", header->e_shentsize);
    printf("Number of section headers:         %d\n", header->e_shnum);
    printf("Section header string table index: %d\n", header->e_shstrndx);

    /* Cleanup and return */
    free(header);
    close(fd);
    return (0);
}
