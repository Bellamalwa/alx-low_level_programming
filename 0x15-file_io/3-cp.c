#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_error(const char *message, const char *file);
char *create_buffer();
void close_file(int fd, const char *file);
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
*/

int main(int argc, char *argv[])
{
	int from_fd, to_fd, r, w;
	char *buffer;

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to\n", NULL);
	}

	buffer = create_buffer();
	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		print_error("Error: Can't read from file %s\n", argv[1]);
	}

	r = read(from_fd, buffer, BUFFER_SIZE);
	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		print_error("Error: Can't write to %s\n", argv[2]);
	}

	do {
		if (from_fd == -1 || r == -1)
		{
			print_error("Error: Can't read from file %s\n", argv[1]);
		}

		w = write(to_fd, buffer, r);
		if (to_fd == -1 || w == -1)
		{
			print_error("Error: Can't write to %s\n", argv[2]);
		}

		r = read(from_fd, buffer, BUFFER_SIZE);
		to_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from_fd, argv[1]);
	close_file(to_fd, argv[2]);

	return (0);
}
/**
 * print_error - Prints an error message to stderr.
 * @message: The error message format string.
 * @file: The file name or argument to be included in the error message.
 *
 * Description: Prints the error message specified by the format string.
 *              This function terminates program with an exit status of 1.
 */
void print_error(const char *message, const char *file)
{
	dprintf(STDERR_FILENO, message, file);
	exit(1);
}

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * file The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */

char *create_buffer()
{
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
{
		print_error("Error: Can't allocate memory for the buffer\n", NULL);
	}
	return (buffer);
}
/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 * @file: file
 */

void close_file(int fd, const char *file)
{
	if (close(fd) == -1)
	{
		print_error("Error: Can't close file descriptor for %s\n", file);
	}
}

