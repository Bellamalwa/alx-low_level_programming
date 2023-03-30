#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * infinite_add - check the code
 * @n1: variable 1
 * @n2: variable 2
 * @r: variable 3
 * @size_r: variable 4
 *Return: pointer to result 
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int len1 = strlen(n1);
int len2 = strlen(n2);
int carry = 0;
int sum;
int i, j;

if (len1 + 1 > size_r || len2 + 1 > size_r)
{
return (0);
}

for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--)
{
sum = carry;
if (i >= 0)
{
sum += n1[i] - '0';
}
if (j >= 0)
{
sum += n2[j] - '0';
}
if (sum > 9)
{
carry = 1;
sum -= 10;
}
else
{
carry = 0;
}
r[len1 + len2 - i - j - 2] = sum + '0';
}


if (carry)
{
if (len1 + len2 >= size_r)
{
return (0);
}
r[len1 + len2 - i - j - 2] = '1';
}

for (i = 0, j = len1 + len2 - 2; i < j; i++, j--)
{
char tmp = r[i];
r[i] = r[j];
r[j] = tmp;
}

r[len1 + len2 - 1] = '\0';

return (r);
}

