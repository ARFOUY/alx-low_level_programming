#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to a pointer to the head node of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
size_t size = 0;
listint_t *temp;

if (!h || !*h)
return (size);

while (*h)
{
size++;
if (*h <= (*h)->next)
{
free(*h);
*h = NULL;
break;
}
temp = (*h)->next;
free(*h);
*h = temp;
}

*h = NULL;
return (size);
}
