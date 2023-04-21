/**
 * array_iterator - Applies a function to each element of an array.
 *
 * @array: Pointer to the array to iterate over.
 * @size: The size of the array.
 * @action: Pointer to the function to apply to each element.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
