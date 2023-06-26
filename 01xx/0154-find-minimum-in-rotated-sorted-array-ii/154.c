/* 154. Find Minimum in Rotated Sorted Array II */

/* Complexities.
 * Time: best case: O(log(n))
 *       worst case: O(n)
 * Space: best case: with tail recursion elimination: O(1)
 *                   without tail recursion elimination: O(log(n))
 *        worst case: O(log(n))
 * where n is the length of the input array. The worst case occurs if all
 * entries of the input array are equal. The best case occurs if they are all
 * entries are distinct.
 */

#include <stdlib.h>

int findMin(int *nums, int numsSize);
int binarySearch(int *nums, int lower, int upper);

int findMin(int *nums, int numsSize)
{
	if (nums[0] < nums[numsSize - 1]) /* Not rotated. */
		return nums[0];

	return binarySearch(nums, 0, numsSize - 1);
}

int binarySearch(int *nums, int lower, int upper)
{
	/* If we have only two numbers, then the third recursion case can lead to
	 * empty sublists. It is easiest to avoid this problem by handling lists of
	 * length 2 by hand. */
	if (upper - lower == 1)
		return (nums[lower] < nums[upper]) ? nums[lower] : nums[upper];

	if (lower < upper) {
		const int middle = lower + (upper - lower) / 2; /* rounded down */
		if (nums[middle] > nums[upper])
			return binarySearch(nums, middle + 1, upper);
		else if (nums[lower] > nums[middle])
			return binarySearch(nums, lower, middle);
		else {
			/* Otherwise,
			 * nums[lower] <= nums[middle] <= nums[upper] <= nums[lower], so all
			 * three values are the same. We then need to check both sides. */
			const int leftResult = binarySearch(nums, lower, middle - 1);
			const int rightResult = binarySearch(nums, middle + 1, upper);
			return (leftResult < rightResult) ? leftResult : rightResult;
		}
	}

	return nums[lower];
}
