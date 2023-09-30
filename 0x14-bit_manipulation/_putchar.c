_putchar.c

#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to the Standard output
 * @c: The character to print out
 *
 * Return: On success 1.
 * On error, -1 is returned, and :w
 * errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

