/* Sliding window approach
 *
 * Time: O(n)
 * Space: O(1)
 *
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

	for (int i = 0; i < k; ++i)
		result[i] = -1;

	long long sum = 0;         /* Must hold values between 0 and 1e10. */
	long diameter = 2 * k + 1; /* Must hold values between 1 and 2e5 + 1. */
	for (int j = 0; j < 2 * k; ++j) /* We skip j = 2 * k on purpose,    */
		sum += nums[j];             /* see first line of the loop body. */
	for (int i = k; i < numsSize - k; ++i) {
		sum += nums[i + k];
		result[i] = (int) (sum / diameter);
		sum -= nums[i - k];
	}

	for (int i = numsSize - k; i < numsSize; ++i)
		result[i] = -1;

	return result;
}
