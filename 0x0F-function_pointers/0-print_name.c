#include "function_pointers.h"
	#include <stdio.h>

/**
 * print_name - Prints a name using a pointer to a function.
 *
 * @name: A pointer to the name to print.
 * @f: Pointer to function that takes pointer to character and returns void.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
{
return;
}

f(name);
}

