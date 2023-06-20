/* 34. Find First and Last Position of Element in Sorted Array */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdlib.h>

int searchRightMost(int *nums, int numsSize, int target);
int searchLeftMost(int *nums, int numsSize, int target);
int *searchRange(int *nums, int numsSize, int target, int *returnSize);

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int left = searchLeftMost(nums, numsSize, target);
	int right = (left == -1) ? -1 : searchRightMost(nums, numsSize, target);

	int *result = malloc(2 * sizeof(int));
	result[0] = left;
	result[1] = right;
	*returnSize = 2;

	return result;
}

int searchLeftMost(int *nums, int numsSize, int target)
{
	if (numsSize == 0)
		return -1;

	int lower = 0;
	int upper = numsSize - 1;
	while (lower < upper) {
		const int middle = lower + (upper - lower) / 2; /* rounded down */
		if (nums[middle] < target)
			lower = middle + 1;
		else
			upper = middle;
	}

	return (nums[lower] == target) ? lower : -1;
}

int searchRightMost(int *nums, int numsSize, int target)
{
	if (numsSize == 0)
		return -1;

	int lower = 0;
	int upper = numsSize - 1;
	while (lower < upper) {
		const int middle = lower + (upper - lower + 1) / 2; /* rounded up */
		if (nums[middle] > target)
			upper = middle - 1;
		else
			lower = middle;
	}

	return (nums[upper] == target) ? upper : -1;
}
