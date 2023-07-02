/* 1089. Duplicate Zeros */

/* Complexities.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input array. */

#include <stdlib.h>
#include <string.h>

void duplicateZeros(int *arr, int arrSize)
{
	const size_t byteSize = (size_t) arrSize * sizeof(int);
	int *result = malloc(byteSize);

	for (int from = 0, to = 0; to < arrSize; ++from) {
		if (arr[from] != 0)
			result[to++] = arr[from];
		else {
			result[to++] = 0;
			if (to < arrSize)
				result[to++] = 0;
		}
	}

	memcpy(arr, result, byteSize);
	free(result);
}
