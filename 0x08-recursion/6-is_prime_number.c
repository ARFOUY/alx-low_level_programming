/**
 * is_prime_number - Checks if a number is prime.
 *
 * @n: The number to be checked.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (check_prime(n, 2));
}

/**
 * check_prime - Recursive helper function to check if a number is prime.
 *
 * @n: The number to be checked.
 * @i: The iterator to check the number's factors.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int check_prime(int n, int i)
{
	if (i == n)
		return (1);
	else if (n % i == 0)
		return (0);
	else
		return (check_prime(n, i + 1));
}
