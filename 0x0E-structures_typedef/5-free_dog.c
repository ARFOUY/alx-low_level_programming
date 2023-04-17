#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees memory allocated for a struct dog.
 * @d: Pointer to the struct dog to free.
 *
 * Return: Void.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		if (d->name != NULL)
			free(d->name);
		if (d->owner != NULL)
			free(d->owner);
		free(d);
	}
}
