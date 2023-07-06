/* 1498. Number of Subsequences That Satisfy the Given Sum Condition. */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(1)
 * where n is the length of the input list. */

/* Idea.
 * We call a subsequence “valid” if it is nonempty and the sum of its maximum
 * and minimum is less or equal to the given `target` value. Suppose that the
 * input array is sorted. The number n of valid subsequences whose minimal value
 * is nums[i] can be computes as follows: if j is the largest index with
 *   i <= j   and   nums[i] + nums[j] <= target ,
 * then n = 2^(j - i). If no such index exists, then n = 0. We can determine
 * this index j via binary search. If 2 * nums[i] > target, then we don’t even
 * need to search, as then num[i] + nums[j] > target for whenever i <= j. */

#include <stdlib.h>

#define MODULO 1##000##000##007

int numSubseq(int *nums, int numsSize, int target);
int cmpInt(const void *pva, const void *pvb);
int binarySearchMaxLeq(int *nums, int numsSize, int lower, int target);
int power2Mod(int n);

int numSubseq(int *nums, int numsSize, int target)
{
	qsort(nums, (size_t) numsSize, sizeof(int), cmpInt);
	int sum = 0;
	for (int i = 0; i < numsSize && nums[i] <= target / 2; ++i) {
		const int j = binarySearchMaxLeq(nums, numsSize, i, target - nums[i]);
		const int new = power2Mod(j - i);
		sum = (sum + new) % MODULO;
	}
	return sum;
}

/* power2Mod(n): computes the power 2^n modulo MODULO if n >= 0, and returns 0
 * if n < 0. */
int power2Mod(int n)
{
	if (n < 0)
		return 0;
	/* 2^n = power^n ̲⋅ accumulator */
	long long power = 2;
	long long accumulator = 1;
	while (n > 0)
		if (n % 2 == 0) {
			power = (power * power) % MODULO;
			n /= 2;
		}
		else {
			accumulator = (power * accumulator) % MODULO;
			--n;
		}
	return (int) accumulator;
}

/* binarySearch(nums, numsSize, lower, target) searches for the largest index j
 * in the interval [lower, ...] for which nums[j] <= target. If no such index
 * exists, then the out-of-bounds index (lower - 1) is returned instead. */
int binarySearchMaxLeq(int *nums, int numsSize, int lower, int target)
{
	--lower;
	int upper = numsSize - 1;
	while (lower < upper) {
		const int middle = lower + (upper - lower + 1) / 2; /* rounded up */
		if (nums[middle] <= target)
			lower = middle;
		else
			upper = middle - 1;
	}
	return upper;
}

int cmpInt(const void *pva, const void *pvb)
{
	const int *pa = (const int *) pva;
	const int *pb = (const int *) pvb;
	return (*pa > *pb) - (*pa < *pb);
}
