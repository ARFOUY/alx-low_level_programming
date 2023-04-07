#include "main.h"

/**
 * _puts_recursion - function like puts();
 * @s: input string
 *
 * Description: prints a string, followed by a new line, to stdout
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (s == NULL || *s == '\0')
	{
		_putchar('\n');
		return;
	}

	for (; *s != '\0'; s++)
		_putchar(*s);

	_putchar('\n');
}
