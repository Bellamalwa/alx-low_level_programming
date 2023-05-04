#include <stdio.h>
#include "main.h"

/**
 * clear_bit - sets value of a bit to 0 at a given index
 * @n: pointer to number for modification
 * @index: index starting from 0, of the bit to clear
 *
 * Return: 1 if it works, or -1 if an error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);
	return (1);
}

