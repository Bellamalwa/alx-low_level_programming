#include <stdlib.h>
#include "main.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to STDOUT.
 * @filename: The name of the text file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: Actual number of bytes read and printed.
 *         Returns 0 if function fails or if filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fileDescriptor;
	ssize_t bytesRead;
	ssize_t bytesWritten;

	fileDescriptor = open(filename, O_RDONLY);
	if (fileDescriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	bytesRead = read(fileDescriptor, buffer, letters);
	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	free(buffer);
	close(fileDescriptor);

	return (bytesWritten);
}

