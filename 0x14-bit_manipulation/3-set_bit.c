#include "main.h"
/**
 * set_bit - set value of bit to 1 at a given index
 * @index: the index starting from 0 of the bit to set
 * Return: 1 if successful or -1 if error
 * @n: the number to be  inputed
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n = *n | (1UL << index);
	return (1);
}
