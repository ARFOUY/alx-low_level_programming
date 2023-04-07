/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 *
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of n, or -1 if n does not have one.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (0);
	}
	else if (n == 1)
	{
		return (1);
	}
	else
	{
		return (sqrt_check(n, 1));
	}
}

/**
 * sqrt_check - Recursively checks for the square root of a number.
 *
 * @n: The number to check.
 * @i: The integer to check as a possible square root of n.
 *
 * Return: The square root of n, or -1 if n does not have one.
 */
int sqrt_check(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	else if (i * i == n)
	{
		return (i);
	}
	else
	{
		return (sqrt_check(n, i + 1));
	}
}
