/* 80. Remove Duplicates from Sorted Array II */

/* Complexities.
 * Time: O(n)
 * Spaces O(1)
 * where n is the length of the input array. */

int removeDuplicates(int *nums, int numsSize)
{
	int from = 0;
	int to = 0;
	int current;

	while (from < numsSize) {
		current = (nums[to++] = nums[from++]);
		if (from < numsSize && nums[from] == current) {
			nums[to++] = current;
			while (++from < numsSize && nums[from] == current)
				;
		}
	}

	return to;
}
