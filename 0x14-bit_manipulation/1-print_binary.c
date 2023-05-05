#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
int flag = 0;

while (mask)
{
if ((n & mask) == mask)
{
flag = 1;
_putchar('1');
}
else if (flag)
}
_putchar('0');
}

mask >>= 1;
}

if (!flag)
{
_putchar('0');
}
}
