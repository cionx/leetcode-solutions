/* 238. Product of Array Except Self */

/* Complexities.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input array. */

#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	int *prefixes = malloc((size_t) numsSize * sizeof(int));
	prefixes[0] = 1;
	for (int i = 1; i < numsSize; ++i)
		prefixes[i] = prefixes[i - 1] * nums[i - 1];

	int *suffices = malloc((size_t) numsSize * sizeof(int));
	suffices[numsSize - 1] = 1;
	for (int j = numsSize - 2; j >= 0; --j)
		suffices[j] = suffices[j + 1] * nums[j + 1];

	int *result = malloc((size_t) numsSize * sizeof(int));
	for (int i = 0; i < numsSize; ++i)
		result[i] = prefixes[i] * suffices[i];

	free(prefixes);
	free(suffices);
	*returnSize = numsSize;
	return result;
}
