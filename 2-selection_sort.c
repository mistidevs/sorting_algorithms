#include "sort.h"

/**
* selection_sort - sorting using the selection algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/

void selection_sort(int *array, size_t size)
{
int min, temp;
size_t i, ind, j;

for (i = 0; i < size; i++)
{
	min = array[i];

	for (j = i + 1; j < size; j++)
	{
		if (min > array[j])
		{
			ind = j;
			min = array[j];
		}
	}
	if (min != array[i])
	{
		temp = array[i];
		array[i] = min;
		array[ind] = temp;
		print_array(array, size);
	}
}
}
