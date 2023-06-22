/* 1262. Greatest Sum Divisible by Three. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdlib.h>
#include <string.h>

#define MODULO 3

int maxSumDivThree(int *nums, int numsSize);
int max(int a, int b);

int maxSumDivThree(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;

	/* bestSums[i] is the best sum we can get that is congruent i modulo 3. The
	 * value -1 indicates that no such sum is currently possible. */
	int bestSums[MODULO] = {0, -1, -1};
	int prevBestSums[MODULO];
	for (int i = 0; i < numsSize; ++i) {
		memcpy(prevBestSums, bestSums, MODULO * sizeof(int));
		for (int j = 0; j < MODULO; ++j) {
			const int shift = nums[i] % MODULO;
			const int doNothing = prevBestSums[j];
			const int reverseShifted =
				prevBestSums[(j - shift + MODULO) % MODULO];
			if (reverseShifted != -1)
				bestSums[j] = max(doNothing, reverseShifted + nums[i]);
			else
				bestSums[j] = doNothing;
		}
	}

	return bestSums[0];
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
