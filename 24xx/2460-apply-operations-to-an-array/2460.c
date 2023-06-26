/* 2460. Apply Operations to an Array */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdlib.h>

int *applyOperations(int *nums, int numsSize, int *returnSize)
{
	int *result = calloc((size_t) numsSize, sizeof(int));

	for (int from = 0, to = 0; from < numsSize; ++from) {
		if (nums[from] != 0) {
			if (from + 1 < numsSize && nums[from] == nums[from + 1])
				result[to] = 2 * nums[from++];
			else
				result[to] = nums[from];
			++to;
		}
	}

	*returnSize = numsSize;
	return result;
}
