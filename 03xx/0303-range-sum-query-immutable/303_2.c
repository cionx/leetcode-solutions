/* 303. Range Sum Query - Immutable */

/* numArrayCreate:
 * Time: O(n);
 * Space: O(n);
 *
 * numArraySumRange:
 * Time: O(1);
 * Space: O(1);
 *
 * where n is the length of the input array. */

#include <stdlib.h>

typedef struct {
	int *sums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
	NumArray *arr = malloc(sizeof(NumArray));
	arr->sums = malloc((size_t) numsSize * sizeof(int));

	int sum = 0;
	for (int i = 0; i < numsSize; ++i) {
		sum += nums[i];
		arr->sums[i] = sum;
	}

	return arr;
}

int numArraySumRange(NumArray *arr, int left, int right)
{
	return arr->sums[right] - ((left > 0) ? arr->sums[left - 1] : 0);
}

void numArrayFree(NumArray *arr)
{
	free(arr->sums);
	free(arr);
}
