#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list
 * @h: Address of pointer to first node
 * Return: Size of the list that was free'd
 */

size_t free_listint_safe(listint_t **h)
{
size_t size = 0;
listint_t *current, *temp;

if (!h || !*h)
return (size);

current = *h;
while (current)
	{
size++;
temp = current;
current = current->next;
free(temp);
if (temp <= current)
break;
}
*h = NULL;

return (size);
}
