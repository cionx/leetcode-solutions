/* 922. Sort Array By Parity II */

/* Not in-place solution. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of input array. */

#include <stdlib.h>

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
	int *result = malloc((size_t) numsSize * sizeof(int));
	*returnSize = numsSize;

	for (int from = 0, toEven = 0, toOdd = 1; from < numsSize; ++from)
		if (nums[from] % 2 == 0) {
			result[toEven] = nums[from];
			toEven += 2;
		}
		else {
			result[toOdd] = nums[from];
			toOdd += 2;
		}

	return result;
}
