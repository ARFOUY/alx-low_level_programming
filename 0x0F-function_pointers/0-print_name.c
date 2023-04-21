/**
 * print_name - prints a name using a pointer to a function
 * @name: name to print
 * @f: pointer to function that prints the name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
