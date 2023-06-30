/* 189. Rotate Array */

/* Complexities.
 * Time: O(n)
 * Space: Θ(n)
 * where n is the length of the input array. */

/* Idea.
 * We concatenate two copies of nums and use a shifted subarray of the result.*/

#include <stdlib.h>
#include <string.h>

void rotate(int *nums, int numsSize, int k)
{
	k %= numsSize;
	size_t numByteSize = (size_t) numsSize * sizeof(int);
	int *doubleNums = malloc(2 * numByteSize);
	memcpy(doubleNums, nums, numByteSize);
	memcpy(doubleNums + numsSize, nums, numByteSize);
	memcpy(nums, doubleNums + numsSize - k, numByteSize);
	free(doubleNums);
}
