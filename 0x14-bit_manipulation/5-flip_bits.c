#include "main.h"

/**
 * flip_bits - Calculates the number of bits that need to be changed
 *             to convert one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: The number of bits that need to be changed.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i = 63, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	while (i >= 0)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;

		i--;
	}

	return (count);
}
