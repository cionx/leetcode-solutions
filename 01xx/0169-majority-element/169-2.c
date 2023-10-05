/* 169. Majority Element */

/* Complexities.
 * Time: O(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * We use the Boyer–Moore majority algorithm. */

int majorityElement(int *nums, int numsSize)
{
	int candidate = nums[0];
	int counter = 1;

	for (int i = 1; i < numsSize; ++i) {
		counter += (nums[i] == candidate) ? 1 : -1;
		if (counter == 0) {
			candidate = nums[i];
			counter = 1;
		}
	}

	return candidate;
}
