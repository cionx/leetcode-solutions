/* 905. Sort Array by Parity */

/* In-place solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input list. */

/* Idea.
 * We use two pointers. The first pointer goes from the left to the right of the
 * array, searching for an odd number. The second pointer goes from the right to
 * the left of the array, searching for an even number. Once we found two
 * numbers, we swap them. We stop whenever the two pointers meet. */

int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
	*returnSize = numsSize;
	for (int i = 0, j = numsSize - 1; i < j; ++i, --j) {
		while (i < j && nums[i] % 2 == 0)
			++i;
		while (i < j && nums[j] % 2 == 1)
			--j;
		const int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	return nums;
}
