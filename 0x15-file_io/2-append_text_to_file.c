#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The text content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fileDescriptor;
	ssize_t bytesWritten;
	ssize_t length = 0;

	if (filename == NULL)
		return (-1);

	fileDescriptor = open(filename, O_WRONLY | O_APPEND);
	if (fileDescriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;

		bytesWritten = write(fileDescriptor, text_content, length);
		if (bytesWritten == -1)
		{
			close(fileDescriptor);
			return (-1);
		}
	}

	close(fileDescriptor);
	return (1);
}

