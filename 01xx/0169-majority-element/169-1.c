/* 169. Majority Element */

/* Changes the input array for simplicity. */

/* Complexities.
 * Time: O(n log(n))
 * Space: Θ(1)
 * where n is the length of the input array. */

#include <stdlib.h>

int majorityElement(int *nums, int numsSize);
int cmpInt(const void *vpa, const void *vpb);

int majorityElement(int *nums, int numsSize)
{
	qsort(nums, (size_t) numsSize, sizeof(int), cmpInt);
	return nums[numsSize / 2];
}

int cmpInt(const void *vpa, const void *vpb)
{
	const int *pa = (const int *) vpa;
	const int *pb = (const int *) vpb;
	return (*pa > *pb) - (*pa < *pb);
}
