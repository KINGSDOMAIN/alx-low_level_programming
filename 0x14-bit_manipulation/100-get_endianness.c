#include "main.h"
/**
 * get-endianness - check the endianess
 * Return: 0 if Big endian, 1 otherwise
 */
int get_endianness(void)
{
	unsigned int test_endian = 1;
	char *check_endian = (char *)&test_endian;

	if (*check_endian)
		return (1);
	else
		return (0);
}
