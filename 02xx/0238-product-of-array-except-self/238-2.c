/* 238. Product of Array Except Self */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	int *result = malloc((size_t) numsSize * sizeof(int));
	for (int i = 0; i < numsSize; ++i)
		result[i] = 1;
	*returnSize = numsSize;

	int leftFactor = 1;
	for (int i = 1; i < numsSize; ++i)
		result[i] *= (leftFactor = leftFactor * nums[i - 1]);
	int rightFactor = 1;
	for (int i = numsSize - 2; i >= 0; --i)
		result[i] *= (rightFactor = rightFactor * nums[i + 1]);

	return result;
}
