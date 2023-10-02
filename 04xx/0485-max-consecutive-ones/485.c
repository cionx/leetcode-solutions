/* 485. Max Consecutive Ones */

/* Complexities.
 * Time: O(n)
 * Space(1)
 * where n is the length of the input array. */

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
	int max = 0;
	for (int i = 0; i < numsSize;) {
		if (nums[i++] != 1)
			continue; /* Jump two lines up. */
		/* We only get here when we are at the start of a new block of 1s. */
		int counter = 1;
		while (i < numsSize && nums[i++] == 1)
			++counter;
		if (counter > max)
			max = counter;
	}
	return max;
}
