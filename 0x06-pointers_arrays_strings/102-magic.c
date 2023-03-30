#include <stdio.h>

/**
 * main - check the code
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

