#include "main.h"
/**
 * flip_bits - returns the number of bits you need to flip
 * to get from one number to another
 * @n1: First number
 * @m2: Second number
 * Return: Number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n1, unsigned long int m2)
{
	unsigned long int xor_output = n1 ^ m2;
	unsigned int count = 0;

	for (; xor_output > 0; xor_output >>= 1)
	{
		if (xor_output & 1)
		{
			count++;
		}
	}
	return (count);
}
