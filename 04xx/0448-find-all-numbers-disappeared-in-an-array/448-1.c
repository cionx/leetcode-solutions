/* 448. Find All Numbers Disappeared in an Array */

/* This solution leaves the input array unchanged. */

/* Complexeties.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input list. */

#include <stdbool.h>
#include <stdlib.h>

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
	bool *missing = malloc(((size_t) numsSize + 1) * sizeof(bool));
	for (int i = 0; i <= numsSize; ++i)
		missing[i] = true;
	for (int j = 0; j < numsSize; ++j)
		missing[nums[j]] = false;

	*returnSize = 0;
	for (int i = 1; i <= numsSize; ++i)
		*returnSize += missing[i];
	if (*returnSize == 0)
		return NULL;
	int *result = malloc((size_t) (*returnSize) * sizeof(int));
	for (int i = 1, k = 0; i <= numsSize; ++i)
		if (missing[i])
			result[k++] = i;

	free(missing);
	return result;
}
