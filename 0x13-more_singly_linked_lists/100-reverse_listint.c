#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: A pointer to the first node of the reversed listint_t list.
 *         NULL if the list is empty.
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL, *next = NULL;
if (*head == NULL)
return (NULL);
while (*head != NULL)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}
*head = prev;
return (*head);
}
