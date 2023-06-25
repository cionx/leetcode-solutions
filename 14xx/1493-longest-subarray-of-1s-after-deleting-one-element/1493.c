#include <stdbool.h>

int longestSubarray(int *nums, int numsSize);

int longestSubarray(int *nums, int numsSize)
{
	int max = 0;
	int lastLength = 0;
	int onlyOnes = true;

	int i = 0;
	while (i < numsSize) {
		/* process a 0 block */
		if (nums[i] == 0) {
			onlyOnes = false;
			if (++i < numsSize && nums[i] == 0) {
				lastLength = 0;
				while (++i < numsSize && nums[i] == 0)
					;
			}
		}
		/* process a 1 block */
		if (i < numsSize) {
			int newLength = 1;
			while (++i < numsSize && nums[i] == 1)
				++newLength;
			if (i < numsSize)
				onlyOnes = false;
			if (lastLength + newLength > max) {
				max = lastLength + newLength;
			}
			lastLength = newLength;
		}
	}

	return onlyOnes ? (max - 1) : max;
}
