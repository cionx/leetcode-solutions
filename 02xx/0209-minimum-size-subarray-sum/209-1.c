/* 209. Minimum Size Subarray Sum */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(n)
 * where n is the length of the input list. */

/* Idea.
 * We can check for every specified width of subarrays for the maximal sum over
 * a subarray of this width. The result is weakly increasing in the specified
 * width. We can therefore search for the minimal viable width via binary
 * search. */

#include <stdlib.h>

int minSubArrayLen(int target, int *nums, int numsSize);
long maxSum(long long *prefixSums, int numsSize, int width);

int minSubArrayLen(int target, int *nums, int numsSize)
{
	long long *prefixSums = malloc(((size_t) numsSize + 1) * sizeof(long long));
	++prefixSums;
	long long sum = 0;
	prefixSums[-1] = sum;
	for (int i = 0; i < numsSize; ++i) {
		sum += nums[i];
		prefixSums[i] = sum;
	}

	int lower = 0;
	int upper = numsSize + 1;
	while (lower < upper) {
		const int width = lower + (upper - lower) / 2; /* rounded down */
		if (maxSum(prefixSums, numsSize, width) >= target)
			upper = width;
		else
			lower = width + 1;
	}

	free(prefixSums - 1);
	return (upper <= numsSize) ? upper : 0;
}

long maxSum(long long *prefixSums, int numsSize, int width)
{
	long long max = prefixSums[width - 1];
	for (int i = width; i < numsSize; ++i) {
		const long long sum = prefixSums[i] - prefixSums[i - width];
		if (sum > max)
			max = sum;
	}
	return max;
}
