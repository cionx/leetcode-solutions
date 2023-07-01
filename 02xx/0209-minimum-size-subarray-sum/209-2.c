/* 209. Minimum Size Subarray Sum */

/* Complexities.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input list. */

/* Idea.
 * We first check the sum of over the entire interval [0, numSize - 1], which is
 * the largest sum we can get. If this sum is too small, we immediately return.
 *
 * We start by determining the largest index r for which the interval [0, r] is
 * still viable. We then repeat the following step:
 * - Increment the right border of the interval (i.e., increase by 1).
 * - Increase the left border of the interval as far as possible while keeping
 *   the interval viable.
 * In this way, we get for every index r = 0, ..., numsSize - 1 the smallest
 * minimal interval with right border r. We then look at the minimal interval
 * length among all these intervals. */

#include <stdlib.h>

int minSubArrayLen(int target, int *nums, int numsSize);
long long sum(long long *prefixSums, int left, int right);

int minSubArrayLen(int target, int *nums, int numsSize)
{
	long long *prefixSums = malloc(((size_t) numsSize + 1) * sizeof(long long));
	++prefixSums;
	long long pSum = 0;
	prefixSums[-1] = pSum;
	for (int i = 0; i < numsSize; ++i) {
		pSum += nums[i];
		prefixSums[i] = pSum;
	}

	int left = 0;
	int right = numsSize - 1;
	if (sum(prefixSums, left, right) < target) {
		free(prefixSums - 1);
		return 0;
	}
	int minLength = numsSize;

	while (sum(prefixSums, left, right) >= target)
		--right;
	++right;

	for (; right < numsSize; ++right) {
		while (sum(prefixSums, left, right) >= target)
			++left;
		--left;
		const int newLength = right - left + 1;
		if (newLength < minLength)
			minLength = newLength;
	}

	free(prefixSums - 1);
	return minLength;
}

long long sum(long long *prefixSums, int left, int right)
{
	return prefixSums[right] - prefixSums[left - 1];
}
