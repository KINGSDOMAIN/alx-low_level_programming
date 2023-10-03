#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- It will  read text file print to STDOUT.
 * @filename: this text file being read
 * @letters: the number of letters to be read
 * Return: p- the actual number of bytes read and printed
 *        0 when the function fails or filename returns NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t p;
	ssize_t o;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	p = read(fd, buf, letters);
	o = write(STDOUT_FILENO, buf, p);

	free(buf);
	close(fd);
	return (o);
}

