/* 905. Sort Array by Parity */

/* Not in-place in solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input list. */

#include <stdlib.h>

int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
	int *result = malloc((size_t) numsSize * sizeof(int));
	*returnSize = numsSize;

	for (int from = 0, toEven = 0, toOdd = numsSize - 1; from < numsSize;
	     ++from)
		if (nums[from] % 2 == 0)
			result[toEven++] = nums[from];
		else
			result[toOdd--] = nums[from];

	return result;
}
