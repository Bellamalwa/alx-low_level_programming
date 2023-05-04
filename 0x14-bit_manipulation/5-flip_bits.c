#include <stdio.h>
#include "main.h"

/**
 * flip_bits - returns number of bits needed to flip to get
 *
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m;
	unsigned int count = 0;

	while (x)
	{
		count += x & 1;
		x >>= 1;
	}

	return (count);
}
