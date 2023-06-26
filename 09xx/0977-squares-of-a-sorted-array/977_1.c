/* 977. Squares of a Sorted Array */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

/* This code assumes that int has at least 32 bit, as required by LeetCode.
 * (I tried using long instead of int, but this breaks LeetCode’s testing. */

#include <stdlib.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize);
int smallestIndex(int *nums, int length);
int secondSmallestIndex(int *nums, int numsSize, int smallest);
void swap(int *a, int *b);
int square(int x);

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
	int *result = malloc((size_t) numsSize * sizeof(int));

	/* We first search for an index with minimal associated absolute value via
	 * binary search. We then search for the index with second-to-minimal
	 * associated absolute value.
	 * If nums has length 1, then j will be out-of-bounds. */
	int i = smallestIndex(nums, numsSize);
	int j = secondSmallestIndex(nums, numsSize, i);

	/* We want i < j as it simplifies the rest of the code. */
	if (i > j)
		swap(&i, &j);

	/* We work our way through the subarrays nums[1 : i] and nums[j : n-1],
	 * always comparing the tail of the left subarray to the head of the right
	 * subarray. */
	int k = 0;
	int sqri = square(nums[i]);
	int sqrj;
	if (j < numsSize) /* For the case of numsSize = 1. */
		sqrj = square(nums[j]);
	while (0 <= i && j < numsSize) {
		if (sqri < sqrj) {
			result[k++] = sqri;
			if (0 <= --i)
				sqri = square(nums[i]);
		}
		else {
			result[k++] = sqrj;
			if (++j < numsSize)
				sqrj = square(nums[j]);
		}
	}
	/* Now that one of the two subarray is empty, we still have to work our way
	 * through the other one. */
	while (0 <= i)
		result[k++] = square(nums[i--]);
	while (j < numsSize)
		result[k++] = square(nums[j++]);

	*returnSize = numsSize;
	return result;
}

/* binarySearch: searches for an index whose entrie is closest to value */
int smallestIndex(int *nums, int length)
{
	int lower = 0;
	int upper = length - 1;
	while (upper - lower > 1) {
		const int middle = lower + (upper - lower) / 2;
		if (nums[middle] < 0)
			lower = middle;
		else if (0 < nums[middle])
			upper = middle;
		else
			return middle;
	}

	return ((abs(nums[lower]) < abs(nums[upper]))) ? lower : upper;
}

/* The following function relies on the fact that x ↦ x² is convex. */
int secondSmallestIndex(int *nums, int numsSize, int smallestIndex)
{
	if (0 < smallestIndex && smallestIndex + 1 < numsSize)
		return (abs(nums[smallestIndex - 1]) < abs(nums[smallestIndex + 1]))
		           ? smallestIndex - 1
		           : smallestIndex + 1;
	else if (0 < smallestIndex)
		return smallestIndex - 1;
	else
		return smallestIndex + 1;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int square(int x)
{
	return x * x;
}
