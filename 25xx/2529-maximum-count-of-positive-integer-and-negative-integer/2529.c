/* 2529. Maximum Count of Positive and Negative Integers */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the length of the input array.
 */

int maximumCount(int *nums, int numsSize);
int firstIndexAtLeast(int nums[], int value, int lower, int limit);
int max(int a, int b);

int maximumCount(int *nums, int numsSize)
{
	int i = firstIndexAtLeast(nums, 0, 0, numsSize);
	int j = firstIndexAtLeast(nums, 1, i, numsSize);
	return max(i, numsSize - j);
}

int firstIndexAtLeast(int nums[], int value, int lower, int limit)
{
	while (lower < limit) {
		const int middle = (lower + limit) / 2; /* smaller than limit */
		if (nums[middle] < value)
			lower = middle + 1;
		else
			limit = middle;
	};

	return lower;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
