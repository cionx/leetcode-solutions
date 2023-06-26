/* 2090. K Radius Subarray Averages */

/* Prefix sum approach. */

/* Complexities
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input list.
 */

#include <stdlib.h>

int *getAverages(int *nums, int numsSize, int k, int *returnSize)
{
	int *result = malloc((size_t) numsSize * sizeof(int));
	*returnSize = numsSize;

	if (2 * k + 1 > numsSize) {
		for (int i = 0; i < numsSize; ++i)
			result[i] = -1;
		return result;
	}

	/* preSum[i] equals nums[0] + nums[1] + ... + nums[i] */
	long long *preSums = malloc((size_t) numsSize * sizeof(long long));
	for (long long sum = 0, j = 0; j < numsSize; ++j) {
		sum += nums[j];
		preSums[j] = sum;
	}

	/* First part. */
	for (int i = 0; i < k; ++i)
		result[i] = -1;

	/* Second part. */
	long diameter = 2 * (long) k + 1; /* Must hold values from 1 to 2e5 + 1. */
	result[k] = preSums[2 * k] / diameter;
	for (int i = k + 1; i < numsSize - k; ++i) {
		const long long sum = preSums[i + k] - preSums[i - k - 1];
		result[i] = (int) (sum / diameter);
	}

	/* Third part. */
	for (int i = numsSize - k; i < numsSize; ++i)
		result[i] = -1;

	return result;
}
