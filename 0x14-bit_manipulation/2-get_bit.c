#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns value of a bit at a given index
 *
 * @n: the number to check
 * @index: index starting from 0 of the bit to get
 *
 * Return: value of bit at index, or -1 if error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((n >> index) & 1);
}

