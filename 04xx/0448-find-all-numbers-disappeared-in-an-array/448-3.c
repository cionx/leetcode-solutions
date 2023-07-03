/* 448. Find All Numbers Disappeared in an Array */

/* This solution temporarily changes the input array. */

/* Complexeties.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

/* Idea.
 * To each number i in [1, …, n] we have an associated array entry, namely the
 * one in (i + 1)-th position. We can record the existence of i in the input
 * array by flipping the sign of the entry at the position associated to i. This
 * works since the entries of the input array are required to be positive. */

#include <stdlib.h>

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize);
void makePositive(int *arr, int index);
void makeNegative(int *arr, int index);

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
	for (int i = 0; i < numsSize; ++i)
		makeNegative(nums, abs(nums[i]) - 1);

	*returnSize = 0;
	for (int i = 0; i < numsSize; ++i)
		*returnSize += (nums[i] > 0);
	int *result = malloc((size_t) *returnSize * sizeof(int));
	for (int i = 0, to = 0; i < numsSize; ++i)
		if (nums[i] > 0)
			result[to++] = i + 1;

	for (int i = 0; i < numsSize; ++i)
		makePositive(nums, i);
	return result;
}

void makePositive(int *arr, int index)
{
	if (arr[index] < 0)
		arr[index] *= -1;
}

void makeNegative(int *arr, int index)
{
	if (arr[index] > 0)
		arr[index] *= -1;
}
