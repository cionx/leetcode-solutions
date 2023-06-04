int removeDuplicates(int *nums, int numsSize);
int nextIndex(int *nums, int lower, int upper, int value);

int removeDuplicates(int *nums, int numsSize)
{
	int from = 0;
	int to = 0;
	int current;

	while (from < numsSize) {
		current = (nums[to++] = nums[from++]);
		if (from < numsSize && nums[from] == current) {
			nums[to++] = current;
			from = nextIndex(nums, from + 1, numsSize, current);
		}
	}

	return to;
}

/* nextIndex: returns the first index i for which nums[i] > value;.
 * if not such index exists, then the initial value of upper is returned.
 * The value of upper may be one larger than the largest legal index for nums.
 * Uses binary search.
 */
int nextIndex(int *nums, int lower, int upper, int value)
{
	while (lower < upper) {
		int middle = (upper + lower) / 2; /* always smaller than upper */
		if (nums[middle] <= value)
			lower = middle + 1;
		else
			upper = middle;
	}

	return lower;
}
