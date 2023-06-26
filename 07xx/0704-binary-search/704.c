/* 704. Binary Search */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the length of the input array. */

/* Just straight up binary search. */
int search(int *nums, int numsSize, int target)
{
	int lower = 0, upper = numsSize - 1;

	while (lower <= upper) {
		const int middle = (lower + upper) / 2;
		if (nums[middle] < target)
			lower = middle + 1;
		else if (nums[middle] > target)
			upper = middle - 1;
		else
			return middle;
	}

	return -1;
}
