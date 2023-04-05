#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: the base number
 * @y: the exponent
 *
 * Return: the value of x raised to the power of y, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
if (y < 0) /* error case */
return (-1);
else if (y == 0) /* base case */
return (1);
else /* recursive case */
return (x * _pow_recursion(x, y - 1));
}

