#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_numbers - prints the numbers, from 0 to 9
 *
 * Return: Always 0
 */

void print_numbers(void)
{
int i;

for (i = 0 ; i <= 9 ; i++)
{
putchar(i + '0');
}
putchar('\n');
}
