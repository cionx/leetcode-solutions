/* 300. Longest Increasing Subsequence */

/* Complexities.
 * Time: Θ(n^2)
 * Space: Θ(n)
 * where n is the length of the input list. */

#include <stdlib.h>

int lengthOfLIS(int *nums, int numsSize)
{
	if (numsSize <= 1)
		return numsSize;

	int *recResults = malloc((size_t) numsSize * sizeof(int));

	for (int j = 0; j < numsSize; ++j) {
		int newResult = 1;
		for (int i = 0; i < j; ++i)
			if (nums[i] < nums[j] && recResults[i] >= newResult)
				newResult = recResults[i] + 1;
		recResults[j] = newResult;
	}

	int result = 1;
	for (int i = 0; i < numsSize; ++i)
		if (recResults[i] > result)
			result = recResults[i];

	free(recResults);
	return result;
}
