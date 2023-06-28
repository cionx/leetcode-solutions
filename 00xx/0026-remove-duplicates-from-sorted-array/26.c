/* 26. Remove Duplicates from Sorted Array */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

int removeDuplicates(int* nums, int numsSize){
	int to = 0;

	for (int from = 1; from < numsSize; ++from)
		if (nums[to] != nums[from])
			nums[++to] = nums[from];

	return to + 1;
}
