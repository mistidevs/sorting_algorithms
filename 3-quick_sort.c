#include "sort.h"
/**
 * value_swap - function that swaps the
 *	pivot and elems
 * @pivot: the pivot value
 * @elem: the other element to be swap
 */
void value_swap(int *pivot, int *elem)
{
	int tmp = *elem;
	*elem = *pi;
	*pi = tmp;
}

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	helper_quick_s(array, 0, size - 1, size);
}

/**
 * pivoting - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: i
 */
int pivoting(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j = lo;
	int pivot = array[hi];

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			/*Making sure the swap value is less than p*/
			if (array[i] != array[j])
			{
				/*swaping values*/
				value_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{

		value_swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * helper_quick_s - quick sort
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void helper_quick_s(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = pivoting(array, lo, hi, size);
		helper_quick_s(array, lo, pivot - 1, size);
		helper_quick_s(array, pivot + 1, hi, size);
	}
}
