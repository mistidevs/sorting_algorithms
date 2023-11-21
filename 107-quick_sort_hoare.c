#include "sort.h"

/**
* partition - swapping values and obtaining
* the partition index
* @arr: pointer to array
* @low: start of array or sub-array
* @high: end of array or sub-array
*
* Return: partition index
*/

size_t partition(int *arr, int low, int high, size_t size)
{
int pivot;
int i, j, temp;

pivot = arr[high];
i = low - 1;
j = high + 1;

for (i = low, j = high; 1; i++, j--)
{
	while (arr[i] < pivot)
		i++;

	while (arr[j] > pivot)
		j--;

	if (i >= j)
		return i;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	print_array(arr, size);
}
}


/**
* quick_sort - recursive algorithm
* @arr: array to sort
* @low: starting index
* @high: last index
*
* Return: void
*/

void quick_sort_recurse(int *arr, int low, int high, size_t size)
{
int pi;

if (low < high)
{
	pi = partition(arr, low, high, size);
	quick_sort_recurse(arr, low, pi - 1, size);
	quick_sort_recurse(arr, pi, high, size);
}
}


/**
* quick_sort_hoare - using hoare partition scheme
* @array: array to sort
* @size: size of array
*
* Return void
*/


void quick_sort_hoare(int *array, size_t size)
{
if (size < 2)
	return;

quick_sort_recurse(array, 0, (int)(size - 1), size);
}
