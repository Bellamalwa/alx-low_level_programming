#include "function_pointers.h"
 /**
 * int_index - searches for an integer in an array using a comparison function
 * @array: the integer array to search
 * @size: the size of the array
 * @cmp: a pointer to the comparison function to use
 *
 * Return: the index of the first element for which the comparison function returns
 *         non-zero, or -1 if none of the elements satisfy the condition or if any of
 *         the inputs are invalid.
 */

	int int_index(int *array, int size, int (*cmp)(int))
	{
		int i;


		if (array == NULL || size <= 0 || cmp == NULL)
			return (-1);


		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
		return (-1);
	}

