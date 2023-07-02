/* 1299. Replace Elements with Greatest Element on Right Side */

/* Not in-place. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdlib.h>

int *replaceElements(int *arr, int arrSize, int *returnSize)
{
	int *result = malloc((size_t) arrSize * sizeof(int));

	int max = -1;
	for (int i = arrSize - 1; i >= 0; --i) {
		result[i] = max;
		if (arr[i] > max)
			max = arr[i];
	}

	*returnSize = arrSize;
	return result;
}
