/* 658. Find K Closest Elements */

/* Complexities
 * Time: O(log(n) + k)
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdlib.h>

int *findClosestElements(int *nums, int numsSize, int k, int x,
                         int *returnSize);
int rightMostSmallest(int *nums, int numsSize, int value);

int *findClosestElements(int *nums, int numsSize, int k, int x, int *returnSize)
{
	k = (k <= numsSize) ? k : numsSize;
	int *result = malloc((size_t) k * sizeof(int));
	*returnSize = k;

	const int pivot = rightMostSmallest(nums, numsSize, x);

	/* Edge cases: all entries in nums are strictly smaller than x, or all
	 * values in nums are strictly larger than x. */
	if (pivot == -1) {
		for (int i = 0; i < k; ++i)
			result[i] = nums[i];
		return result;
	}
	if (pivot == numsSize - 1) {
		for (int i = 0; i < k; ++i)
			result[i] = nums[numsSize - k + i];
		return result;
	}

	int i = 0;

	int lower = pivot;
	int upper = pivot + 1;
	/* We always have nums[j1] <= x < nums[j2]. The subarray that we search for
	 * will be nums[lower+1 : upper-1]. */
	while (0 <= lower && upper < numsSize && i < k)
		if (x - nums[lower] <= nums[upper] - x)
			++i, --lower;
		else
			++i, ++upper;
	for (; 0 <= lower && i < k; ++i)
		--lower;
	for (; upper < numsSize && i < k; ++i)
		++upper;

	for (i = 0; i < k; ++i)
		result[i] = nums[lower + 1 + i];

	return result;
}

/* rightMostSmallest: returns the left-most index i with nums[i] < value. If no
 * such index exists, -1 is returned. */
int rightMostSmallest(int *nums, int numsSize, int value)
{
	if (numsSize > 0 && nums[0] > value)
		return -1;

	int lower = 0;
	int upper = numsSize - 1;

	while (lower < upper) {
		const int middle = lower + (upper - lower - 1) / 2 + 1; /* rounded up */
		if (nums[middle] > value)
			upper = middle - 1;
		else
			lower = middle;
	}

	return lower;
}
