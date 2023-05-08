#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates a buffer of size 1024 bytes.
 * @file: The name of the file associated with the buffer.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate buffer for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		fprintf(stderr, "Error: Failed to close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with different error codes in case of errors:
 *              - 97: Incorrect argument count.
 *              - 98: Unable to read from file_from.
 *              - 99: Unable to create or write to file_to.
 *              - 100: Unable to close file descriptors.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			fprintf(stderr, "Error: Failed to read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			fprintf(stderr, "Error: Failed to write to file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

