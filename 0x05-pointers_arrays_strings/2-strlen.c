#include "main.h"
#include <stdio.h>

/**
 * _strlen - takes string as input
 *
 * @s: integer
 *
 *
 * Return: length
 */

int _strlen(char *s)
{
int length = 0;

while (*s != '\0')
{
length++;
s++;
}

return (length);

}
