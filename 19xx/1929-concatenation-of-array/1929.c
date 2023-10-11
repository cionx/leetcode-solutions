/* 1929. Concatenation of Array */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

#include <stdlib.h>

int *getConcatenation(int *nums, int numsSize, int *returnSize)
{
	int *result = malloc(2 * (size_t) numsSize * sizeof(int));

	for (int i = 0; i < numsSize; ++i) {
		result[i] = nums[i];
		result[numsSize + i] = nums[i];
	}

	*returnSize = 2 * numsSize;
	return result;
}
