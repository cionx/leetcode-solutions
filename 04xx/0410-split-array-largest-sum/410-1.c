/* 410. Split Array Largest Sum */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(n)
 * where n is the length of the input list.
 */

#include <stdbool.h>
#include <stdlib.h>

int splitArray(int *nums, int numsSize, int k);
bool kGroupsEnough(long long *prefixSums, int numsSize, int k, long long value);

int splitArray(int *nums, int numsSize, int k)
{
	long long *prefixSums = malloc((size_t) (numsSize + 1) * sizeof(long long));
	++prefixSums;
	long long sum = 0;
	prefixSums[-1] = sum;
	for (int i = 0; i < numsSize; ++i)
		prefixSums[i] = (sum = sum + nums[i]);

	/* We search for the correct result via binary search. */
	long long lower = 0;
	long long upper = prefixSums[numsSize - 1];
	while (lower < upper) {
		const long long middle = lower + (upper - lower) / 2; /* rounded down */
		if (kGroupsEnough(prefixSums, numsSize, k, middle))
			upper = middle;
		else
			lower = middle + 1;
	}

	free(prefixSums - 1);
	return (int) upper;
}

bool kGroupsEnough(long long *prefixSums, int numsSize, int k, long long value)
{
	/* We can quickly filter out small values. */
	if (prefixSums[numsSize - 1] > k * value)
		return false;
	/* But in general, we need to do some counting. */
	for (int i = 0, subArrStart = 0; k > 0; --k, subArrStart = i) {
		while (i < numsSize &&
		       prefixSums[i] - prefixSums[subArrStart - 1] <= value)
			++i;
		if (i == numsSize)
			return true;
	}
	return false;
}
