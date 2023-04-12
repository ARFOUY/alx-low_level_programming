#include <stdlib.h>
#include <string.h>

char *_strdup(char *str)
{
char *newstr;
if (str == NULL)
return (NULL);
newstr = malloc(sizeof(char) * (strlen(str) + 1));
if (newstr == NULL)
return (NULL);
strcpy(newstr, str);
return (newstr);
}
