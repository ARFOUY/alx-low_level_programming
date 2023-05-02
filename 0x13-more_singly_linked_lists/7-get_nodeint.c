#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head of the listint_t linked list
 * @index: index of the node starting from 0
 *
 * Return: pointer to the nth node, or NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i = 0;

while (head != NULL && i < index)
{
head = head->next;
i++;
}
if (i == index && head != NULL)
return (head);
else
return (NULL);
}
