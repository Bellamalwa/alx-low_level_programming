#include "main.h"
#include <stdio.h>

/**
 * _strlen - takes string as input
 * returns length as integer
 * @s: integer
 * @length: integer 1
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
