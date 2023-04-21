/**
 * int_index - Searches for an integer in an array and returns its index.
 *
 * @array: Pointer to the array to search in.
 * @size: The size of the array.
 * @cmp: Pointer to the function to use to compare elements.
 *
 * Return: The index of the first element for which cmp doesn't return 0,
 * or -1 if no element matches or if size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || !cmp || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
