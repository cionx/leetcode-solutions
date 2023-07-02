/* 941. Valid Mountain Array */

/* Complexities.
 * Time: O(n)
 * Space: Θ(1)
 * where n is the length of the input list. */

#include <stdbool.h>

bool validMountainArray(int *arr, int arrSize)
{
	if (arrSize < 3 || arr[0] >= arr[1])
		return false;

	int i = 1;
	while (i < arrSize && arr[i - 1] < arr[i])
		++i;
	if (i == arrSize || arr[i - 1] == arr[i])
		return false;
	while (i < arrSize && arr[i - 1] > arr[i])
		++i;
	return i == arrSize;
}
