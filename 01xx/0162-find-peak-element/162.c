/* Time: O(n)
 * Space: O(1)
 *
 * where n is the length of the input list.
 */

/* We have the following four possible cases:
 * - If nums[i - 1] < nums[i] < nums[i + 1], then nums must have a peak in the
 *   subinterval [i + 1 : n].
 * - If nums[i - 1] > nums[i] > nums[i + 1], then nums must have a peak in the
 *   subinterval [1 : i - 1].
 * - If nums[i - 1] > nums[i] < nums[i + 1], then nums must have a peak in both
 *   [1 : i - 1] and [i + 1 : n]. We then choose the lift subinterval.
 * - If nums[i - 1] < nums[i] > nums[i + 1], then we have a peak at i.
 */

int findPeakElement(int *nums, int numsSize)
{
	if (numsSize == 0)
		return -1;
	if (numsSize == 1)
		return 0;

	/* Testing edges. */
	if (nums[0] > nums[1])
		return 0;
	else if (nums[numsSize - 2] < nums[numsSize - 1])
		return numsSize - 1;

	/* The general binary search. */
	int lower = 1;
	int upper = numsSize - 2;
	while (lower <= upper) {
		const int i = lower + (upper - lower) / 2;
		if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
			return i;
		else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
			lower = i + 1;
		else
			upper = i - 1;
	}

	return -1;
}
