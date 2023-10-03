#include "main.h"

/**
 * create_file - Creates a new file.
 * @filename: A pointer to the name of the file to be created.
 * @text_content: A pointer to a string that will be written to the file.
 *
 * Return: If the function fails, it returns -1.
 *         Otherwise, it returns 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	// Check if the filename is NULL
	if (filename is equal to NULL)
		return (-1);

	// Calculate the length of the text_content string
	if (text_content is not equal to NULL)
	{
		// Calculate the length by counting the characters in text_content
		for (len = 0; text_content[len];)
			increment len by 1;
	}

	// Create the file with read and write permissions
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	// Write the text_content to the file
	w = write(fd, text_content, len);

	// Check for errors in opening or writing to the file
	if (fd is equal to -1 or w is equal to -1)
		return (-1);

	// Close the file
	close(fd);

	// Return 1 to indicate success
	return (1);
}
