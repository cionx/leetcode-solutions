/* 35. Search Insert Position */

/* Complexities.
 * Time: O(log(n))
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * Straight up binary search. */

int searchInsert(int* nums, int numsSize, int target){
	int lower = 0;
	int upper = numsSize;

	while (lower < upper) {
		const int middle = lower + (upper - lower) / 2;
		if (nums[middle] < target)
			lower = middle + 1;
		else if (nums[middle] > target)
			upper = middle;
		else
			return middle;
	}

	return lower;
}
