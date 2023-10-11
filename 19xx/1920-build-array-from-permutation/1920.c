/* 1920. Build Array from Permutation */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

#include <stdlib.h>

int *buildArray(int *nums, int numsSize, int *returnSize)
{
	int *result = malloc((size_t) numsSize * sizeof(int));

	for (int i = 0; i < numsSize; ++i)
		result[i] = nums[nums[i]];

	*returnSize = numsSize;
	return result;
}
