/* 1470. Shuffle the array */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

#include <stdlib.h>

int *shuffle(int *nums, int numsSize, int n, int *returnSize)
{
	int *result = malloc((size_t) numsSize * sizeof(int));

	int to = 0;
	for (int i = 0; i < n; ++i) {
		result[to++] = nums[i];
		result[to++] = nums[n + i];
	}

	*returnSize = numsSize;
	return result;
}
