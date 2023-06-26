/* 977. Squares of a Sorted Array */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(1)
 * where n is the length of the input array
 */

#include <stdlib.h>
#include <string.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize);
int square(int a);
int cmpInt(const void *pa, const void *pb);

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
	size_t bitSize = (size_t) numsSize * sizeof(int);
	int *result = malloc(bitSize);
	memcpy(result, nums, bitSize);

	for (int i = 0; i < numsSize; ++i) {
		result[i] *= result[i];
	}
	qsort(result, (size_t) numsSize, sizeof(int), cmpInt);

	*returnSize = numsSize;
	return result;
}

int square(int a)
{
	return a * a;
}

int cmpInt(const void *pa, const void *pb)
{
	const int *a = (const int *) pa;
	const int *b = (const int *) pb;

	return (*a > *b) - (*a < *b);
}
