/* 189. Rotate Array */

/* Complexities.
 * Time: Θ(n k)
 * Space: Θ(STEPSIZE) = Θ(1)
 * where n is the length of the input array and 0 <= k <= n. */

/* Idea.
 * We can implement a single rotation step by remembering the last entry, then
 * moving every entry one to the right, and finally placing the remembered entry
 * in the front. Larger rotations can then be implemented by repeated single
 * steps.
 *
 * However, to get our answer accepted to LeetCode without getting TLE, we need
 * to do slightly better.
 * - To do so, we implement rotation in both directions. This halves the worst-
 *   case time.
 * - Instead of doing a single rotation at a time, we can do a fixed number of
 *   steps at once. If we do r rotations at once, then we speed up our program
 *   by a factor of r. */

#include <string.h>

#define STEPSIZE 500

void rotate(int *nums, int numsSize, int k)
{
	k %= numsSize;
	if (k > numsSize / 2) {
		k -= numsSize;
	}
	const size_t smallChunkSize = STEPSIZE * sizeof(int);
	const size_t largeChunkSize = ((size_t) numsSize - STEPSIZE) * sizeof(int);
	const size_t largeSize = ((size_t) numsSize - 1) * sizeof(int);

	int tmp[STEPSIZE];
	while (k >= STEPSIZE) {
		/* STEPSIZE many rotation as in the problem statement. */
		memcpy(tmp, nums + (numsSize - k), smallChunkSize);
		memmove(nums + STEPSIZE, nums, largeChunkSize);
		memcpy(nums, tmp, smallChunkSize);
		k -= STEPSIZE;
	}
	while (k > 0) {
		/* A single rotation as in the problem statement. */
		const int last = nums[numsSize - 1];
		memmove(nums + 1, nums, largeSize);
		nums[0] = last;
		--k;
	}
	while (k <= -STEPSIZE) {
		/* STEPSIZE many reverse rotation. */
		memcpy(tmp, nums, smallChunkSize);
		memmove(nums, nums + STEPSIZE, largeChunkSize);
		memcpy(nums + (numsSize - STEPSIZE), tmp, smallChunkSize);
		k += STEPSIZE;
	}
	while (k < 0) {
		/* A single reverse rotation. */
		const int first = nums[0];
		memmove(nums, nums + 1, largeSize);
		nums[numsSize - 1] = first;
		++k;
	}
}
