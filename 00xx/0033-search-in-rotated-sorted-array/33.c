/* Time: O(log(n))
 * Space: O(1)
 *
 * where n is the length of the input array.
 */

int search(int *nums, int numsSize, int target);
int getPrevEnd(int *nums, int numsSize);
int binarySearch(int *nums, int lower, int upper, int target);

int search(int *nums, int numsSize, int target)
{
	/* We search for the original end of the array using a variant of binary
	 * search. The resulting index splits the array into two subarrays, namely a
	 * left and right part. We determine in which part the target must lie, and
	 * then use classical binary search in this subarray.
	 */
	const int end = getPrevEnd(nums, numsSize);
	if (nums[0] <= target)
		return binarySearch(nums, 0, end, target);
	else
		return binarySearch(nums, end + 1, numsSize - 1, target);
}

/* getPrevEnd: searchs via binary search for the right-most index i with
 * nums[0] <= ... <= nums[i] >= nums[i + 1] <= ... <= nums[n - 1] <= nums[0],
 * assuming that such an index exists. */
int getPrevEnd(int *nums, int numsSize)
{
	int lower = 0;
	int upper = numsSize - 1;
	while (lower < upper) {
		const int middle = lower + (upper - lower + 1) / 2; /* rounded up */
		if (nums[middle] < nums[0])
			upper = middle - 1;
		else
			lower = middle;
	}

	return upper;
}

/* binarySearch: searches for a target value in a subarray nums[lower: upper]
 * via binary search. Returns the respective index, or -1 if the target is not
 * in the subarray. */
int binarySearch(int *nums, int lower, int upper, int target)
{
	while (lower <= upper) {
		const int middle = lower + (upper - lower) / 2;
		if (nums[middle] > target)
			upper = middle - 1;
		else if (nums[middle] < target)
			lower = middle + 1;
		else
			return middle;
	}

	return -1;
}
