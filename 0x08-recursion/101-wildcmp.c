#include "main.h"

/**
 * wildcmp - Compares two strings for identity.
 *
 * @s1: The first string to be compared.
 * @s2: The second string to be compared, can contain the special character *.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0') /* If both strings are empty, return 1 */
		return (1);

	if (*s2 == '*') /* If the second string starts with *, recursively check with the next character of s2 */
	{
		if (*(s1 + 1) == '\0') /* If s1 is empty, skip it */
			return (wildcmp(s1, s2 + 1));
		else /* If s1 is not empty, check s1 with the next character of s2, or s1 with the next character of s1 */
			return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}

	if (*s1 == *s2) /* If both characters match, continue to the next */
		return (wildcmp(s1 + 1, s2 + 1));

	return (0); /* Otherwise, return 0 */
}
