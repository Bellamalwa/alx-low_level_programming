#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file and writes text content into it.
 * @filename: Name of the file to create.
 * @text_content: Text content to write into the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fileDescriptor;
	ssize_t bytesWritten;
	ssize_t length = 0;

	if (filename == NULL)
		return (-1);

	fileDescriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
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

