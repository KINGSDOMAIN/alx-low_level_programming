#include "main.h"

/**
 * clear_bit - Modifies a specific bit in a number and sets its value to 0.
 * @n: Pointer to the number to be modified.
 * @index: Index of the bit to be cleared.
 *
 * Return: 1 if the operation is successful, -1 if it fails.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
