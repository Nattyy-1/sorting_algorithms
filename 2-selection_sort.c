#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 *					ascending order using the selection_sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t smallest;
	int temp;

	for (i = 0; i < size; i++)
	{
		smallest = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}

		if (i != smallest)
		{
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
	}
}
