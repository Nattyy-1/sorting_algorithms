#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 *				 bubble_sort algorithm
 *
 * @array: The array of integers being sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t temp;
	int swapped;

	if (!array || size <= 0)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}

		if (!swapped)
			return;
	}
}
