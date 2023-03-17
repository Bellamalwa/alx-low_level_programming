#include <stdio.h>

/**
  *main - Entry point
  *
  *Return: - Always 0 (success)
  */

int main(void)
{
int i;
char ch;

for(i = 0; i < 10; i++)
{
ch = i + '0';
putchar(ch);
}

for(i = 10; i < 16; i++)
{
ch = i - 10 + 'a';
putchar(ch);
}

putchar('\n');
return (0);
}
