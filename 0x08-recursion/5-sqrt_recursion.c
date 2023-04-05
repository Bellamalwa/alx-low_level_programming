#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the natural square root of n,
 * or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
if (n < 0) /* error case */
return (-1);
else if (n == 0) /* base case */
return (0);
else /* recursive case */
{
int i = _sqrt_recursion(n - 1);
if (i * i == n)
return (i);
else
return (_sqrt_recursion(n - 1));
}
}

