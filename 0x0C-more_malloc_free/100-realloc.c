#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *mim1;
	char *old_mim;
	unsigned int i;

	if (new_size == old_size)
		return (mim);

	if (new_size == 0 && mim)
	{
		free(mim);
		return (NULL);
	}

	if (!mim)
		return (malloc(new_size));

	mim1 = malloc(new_size);
	if (!mim1)
		return (NULL);

	old_mim = mim;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
		mim1[i] = old_mim[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			mim1[i] = old_mim[i];
	}

	free(mim);
	return (mim1);
}
