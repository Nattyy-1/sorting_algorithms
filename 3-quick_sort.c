#include "sort.h"

/**
 * partition - divides the array into two partitions
 *
 * @array: The array to be partitioned
 * @lo: lower bound of the given array
 * @hi: higher bound of the given array
 * @size: size of the array for the purposes of printing
 *
 * Return: The index of the pivot after placed in it's correct position
 */
size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	int pivot = array[hi];
	int temp;
	size_t i;
	size_t j;

	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != hi)
	{

		temp = array[i];
		array[i] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_h - helper function for quick_sort
 *
 * @array: The array to be sorted
 * @lo: the lower bound of the array index
 * @hi: the higher bound of the array index
 * @size: the size of the array for the purposes of printing
 */
void quick_sort_h(int *array, size_t lo, size_t hi, size_t size)
{
	size_t p;

	if (lo >= hi)
		return;

	p = partition(array, lo, hi, size);

	if (p > 0)
		quick_sort_h(array, lo, p - 1, size);

	quick_sort_h(array, p + 1, hi, size);
}

/**
 * quick_sort - sorts an array of integers in
 *				ascending order using the quick_sort algorithm
 *
 * @array: The array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t lo;
	size_t hi;

	if (!array || size < 2)
		return;

	lo = 0;
	hi = size - 1;

	quick_sort_h(array, lo, hi, size);
}
