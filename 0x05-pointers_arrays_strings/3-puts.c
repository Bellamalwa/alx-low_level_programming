#include "main.h"
#include "main.h"

/**
 * _puts - takes string as input
 * @str: intiger 1
 *
 * Return: Always 0.
 */

void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str);
str++;
}

_putchar('\n');
}
