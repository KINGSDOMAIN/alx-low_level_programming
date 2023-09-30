#include "main.h"

/**
 * get_endianness - Determines whether a machine is big endian or little endian.
 *
 * Return: 0 for big endian, 1 for little endian.
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
