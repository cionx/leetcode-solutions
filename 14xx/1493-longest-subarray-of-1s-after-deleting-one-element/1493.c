/* 1493. Longest Subarray of 1’s After Deleting One Element */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

/* Idea.
 * The input array consists of contiguous blocks of 1s, which are separated from
 * one another by one or more 0s. Deleting one element can meld two blocks
 * together.
 *
 * We are therefore doing the following:
 * - Go through the array and record the lengths of contiguous blocks of 1s.
 *   More precisely, once we reach the end of a block, we check if the current
 *   block and previous block were separated by precisely one 0. If so, then we
 *   add the lengths of two blocks, and compare it to the best result found so
 *   far. (In praxis we can forget the length of a block after it has been
 *   followed by two 0s.)
 * - If the array consists only of 1s, then we must return the length of the
 *   array minus 1. If the array contains at least one 0, then it doesn’t make
 *   sense to delete 1.
 * - If the array contains a 0 but one one contiguous block of 1s, then we
 *   return the length of block, unchanged. */

#include <stdbool.h>

int longestSubarray(int *nums, int numsSize)
{
	int bestSoFar = 0;

	int lastLength = 0;
	int onlyOnes = true;

	int i = 0;
	while (i < numsSize) {
		/* Process consecutive 0s. */
		if (nums[i] == 0) {
			onlyOnes = false;
			if (++i < numsSize && nums[i] == 0) {
				lastLength = 0;
				/* Gobble up the remaining 0s. */
				while (++i < numsSize && nums[i] == 0)
					;
			}
		}
		/* Process consecutive 1s. */
		if (i < numsSize) {
			int curLength = 1;
			while (++i < numsSize && nums[i] == 1)
				++curLength;
			const int sumLength = lastLength + curLength;
			if (sumLength > bestSoFar)
				bestSoFar = sumLength;
			lastLength = curLength;
		}
	}

	return onlyOnes ? (bestSoFar - 1) : bestSoFar;
}
