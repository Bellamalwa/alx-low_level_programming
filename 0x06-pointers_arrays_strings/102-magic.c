#include <stdio.h>

/**
 * main - add onr line to the code
 * program prints a[2] = 98
 * followed by new line
 *
 * Return: Always 0.
 */

int main(void)
{
int a[] = { 0, 1, 2, 3, 4 };
int *p;

p = &a[2];

_putchar('a[2] = %d', *(p));
_putchar('%c', '\n');
return (0);
}

