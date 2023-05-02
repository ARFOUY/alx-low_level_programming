#include "lists.h"

/**
 * print_listint - Imprime tous les éléments d'une liste de type listint_t.
 * @h: Pointeur vers le début de la liste listint_t.
 *
 * Return: Le nombre de nœuds dans la liste.
 */
size_t print_listint(const listint_t *h)
{
size_t count = 0;

while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
count++;
}
return (count);
}
