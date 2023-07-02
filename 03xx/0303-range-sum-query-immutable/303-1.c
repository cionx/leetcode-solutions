/* 303. Range Sum Query - Immutable */

/* Complexities.
 *
 * numArrayCreate:
 * Time: O(1);
 * Space: (1);
 *
 * numArraySumRange:
 * Time: O(right - left);
 * Space: O(1);           */

#include <stdlib.h>

typedef struct {
	int *nums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
	NumArray *arr = malloc(sizeof(NumArray));
	arr->nums = nums;
	return arr;
}

int numArraySumRange(NumArray *arr, int left, int right)
{
	int sum = 0;
	for (int i = left; i <= right; ++i)
		sum += arr->nums[i];
	return sum;
}

void numArrayFree(NumArray *arr)
{
	free(arr);
}
