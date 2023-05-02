#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index index of a listint_t
 *                           linked list.
 * @head: A pointer to the head node of the listint_t list.
 * @index: The index of the node to delete.
 *
 * Return: If the function succeeds - 1.
 *         Otherwise - -1.
 **/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int i;

if (*head == NULL)
return (-1);

if (index == 0)
{
current = *head;
*head = (*head)->next;
free(current);
return (1);
}

prev = NULL;
current = *head;

for (i = 0; current != NULL && i < index; i++)
{
prev = current;
current = current->next;
}
if (current == NULL)
return (-1);
prev->next = current->next;
free(current);
return (1);
}
