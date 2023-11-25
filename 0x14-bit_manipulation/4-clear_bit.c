#include "main.h"
/**
 * clear_bit -Set value of bit to 0 at index i
 * @index: the index of the number to be set
 * @n: a pointer to the number whose  bitis  to be cleared
 * Return: 1 if sucess else return -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n = (*n & ~(1UL << index));
	return (1);
}
