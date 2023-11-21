#include "sort.h"

/**
* merge - merging the split halves
* @array: pointer to array to sort
* @size: size of array
* @left: pointer to left array
* @right: pointer to right array
* @mid: middle index of array
* @temp: pointer to temporary array
*
* Return: void
*/

void merge(int *array, size_t size, int *left,
int *right, size_t mid, int *temp)
{
size_t i, j, k;

i = j = k = 0;
printf("Merging...\n");
printf("[left]: ");
print_array(left, mid);
printf("[right]: ");
print_array(right, size - mid);

while (i < mid && j < size - mid)
{
	if (left[i] < right[j])
		temp[k++] = left[i++];
	else
		temp[k++] = right[j++];
}

while (i < mid)
	temp[k++] = left[i++];

while (j < size - mid)
	temp[k++] = right[j++];

for (i = 0; i < size; i++)
	array[i] = temp[i];

printf("[Done]: ");
print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
size_t mid, i;
int left[100];
int right[100];
int *temp;

if (array == NULL || size < 2)
	return;

temp = malloc(size * sizeof(int));
if (temp == NULL)
	return;

mid = size / 2;
for (i = 0; i < mid; i++)
	left[i] = array[i];
for (i = mid; i < size; i++)
	right[i - mid] = array[i];

merge_sort(left, mid);
merge_sort(right, size - mid);
merge(array, size, left, right, mid, temp);

free(temp);
}
