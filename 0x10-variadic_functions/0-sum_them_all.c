#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Calculates the sum of all its parameters.
 * @n: The number of parameters to sum.
 * @...: The list of parameters to sum.
 *
 * Return: The sum of all parameters. If n is 0, returns 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	/* Initialize the va_list with the given number of arguments */
	va_start(args, n);

	/* Loop through all the arguments and add them to the sum */
	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}

	/* Clean up the va_list */
	va_end(args);

	return (sum);
}
