#include <stdio.h>
#include <math.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
long int num = 612852475143;
long int largest = -1;
long int i;

while (num % 2 == 0)
{
largest = 2;
num /= 2;
}

for (i = 3; i <= sqrt(num); i += 2)
{
while (num % i == 0)
{
largest = i;
num /= i;
}
}

if (num > 2)
{
largest = num;
}

printf("%ld\n", largest);

return (0);
}
