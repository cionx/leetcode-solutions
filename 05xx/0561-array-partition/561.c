/* 561. Array Partition */

/* Complexities.
 * Time: O(m log(m))
 * Space: O(1)
 * where m is the length of the input array. */

/* Idea.
 * The given sum consists of half the numbers in the array. We can maximize this
 * sum by choosing every second element in decreasing order, starting from the
 * second-largest element. */

#include <stdlib.h>

int arrayPairSum(int *nums, int numsSize);
int cmpInt(const void *pa, const void *pb);

int arrayPairSum(int *nums, int numsSize)
{
	qsort(nums, (size_t) numsSize, sizeof(int), cmpInt);
	long long sum = 0;
	for (int i = 0; i < numsSize; i += 2)
		sum += nums[i];
	return (int) sum;
}

int cmpInt(const void *pa, const void *pb)
{
	const int *a = (const int *) pa;
	const int *b = (const int *) pb;
	return (*a > *b) - (*a < *b);
}
