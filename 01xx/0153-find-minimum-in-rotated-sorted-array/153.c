/* 153: Find Minimum in Rotated Sorted Array. */

/* Complexities
 * - Time: O(log(n))
 * - Space: O(1)
 * where n is the length of the input array. */

/* Note:
 * As part of our solution to Problem 33 (Search in Rotated Sorted Array) we
 * have already written a function that searchs for the (right-most) maximum in
 * the given situation. We simply adapt the previous code for this problem. */

/* findMin: searches via binary search for the left-most index i with
 * nums[0] <= ... <= nums[i - 1] >= nums[i] <= ... <= nums[n - 1] <= nums[0],
 * assuming that such an index exists. */
int findMin(int *nums, int numsSize)
{
	int lower = 0;
	int upper = numsSize - 1;
	while (lower < upper) {
		const int middle = lower + (upper - lower) / 2; /* rounded down */
		if (nums[middle] > nums[numsSize - 1])
			lower = middle + 1;
		else
			upper = middle;
	}

	return nums[upper];
}
