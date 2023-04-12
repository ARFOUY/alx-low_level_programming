#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the strings in av
 * @ac: the number of strings
 * @av: an array of strings
 *
 * Return: a pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
        int i, j, k = 0, len = 0;
        char *str;

        if (ac == 0 || av == NULL)
                return (NULL);

        for (i = 0; i < ac; i++)
        {
                for (j = 0; av[i][j]; j++)
                        len++;
        }

        len += ac;
        str = malloc(sizeof(char) * (len + 1));
        if (str == NULL)
                return (NULL);

        for (i = 0; i < ac; i++)
        {
                for (j = 0; av[i][j]; j++)
                {
                        str[k] = av[i][j];
                        k++;
                }
                str[k] = '\n';
                k++;
        }
        str[k] = '\0';

        return (str);
}
