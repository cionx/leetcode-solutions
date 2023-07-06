/* 209. Minimum Size Subarray Sum */

/* Complexities.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input list. */

/* Idea.
 * We denote an interval [i, ..., j] by [i, j], and call this interval "viable"
 * if the sum of the array `nums` over this interval is larger or equal to
 * target.
 *
 * We first check if the entire interval [0, numSize - 1] is viable. If it is
 * not, then we can immediately return.
 *
 * We otherwise start by determining the largest index r for which the interval
 * [0, r] is still viable. We then repeat the following two step:
 * 1. Increment the right border of the interval (i.e., increase by 1).
 * 2. Increase the left border of the interval as far as possible while keeping
 *    the interval viable.
 * In this way, we get for every index r = 0, ..., numsSize - 1 the smallest
 * viable interval with right border r. We keep track of the minimal length
 * among all these intervals. */

#include <stdlib.h>

int minSubArrayLen(int target, int *nums, int numsSize);
long long sum(long long *prefixSums, int left, int right);

int minSubArrayLen(int target, int *nums, int numsSize)
{
	/* We label the prefix sums with indices -1, 0, ..., numsSize - 1. */
	long long *prefixSums = malloc(((size_t) numsSize + 1) * sizeof(long long));
	++prefixSums;
	long long pSum = 0;
	prefixSums[-1] = pSum;
	for (int i = 0; i < numsSize; ++i)
		prefixSums[i] = (pSum += nums[i]);

	/* We check if the entire interval [0, numsSize - 1] is viable. */
	int left = 0;
	int right = numsSize - 1;
	if (sum(prefixSums, left, right) < target) {
		free(prefixSums - 1);
		return 0;
	}
	int minLength = numsSize;

	/* If so, then we lower the right border as far as viable possible. */
	while (sum(prefixSums, left, right) >= target)
		--right;
	++right;

	/* Finally, we repeat the two steps and keep track of the smallest viable
	 * length found so far. */
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
