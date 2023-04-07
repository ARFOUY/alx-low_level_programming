#include "main.h"

/**
 * _sqrt_recursion - Calculates the natural square root of a number
 * @n: Number to calculate the square root of
 *
 * Return: The natural square root of n, or -1 if n does not have a natural
 * square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	return (sqrt_recursive(n, 1));
}

/**
 * sqrt_recursive - Recursively calculates the natural square root of a number
 * @n: Number to calculate the square root of
 * @i: Possible square root value
 *
 * Return: The natural square root of n, or -1 if n does not have a natural
 * square root.
 */
int sqrt_recursive(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);

	return (sqrt_recursive(n, i + 1));
}
