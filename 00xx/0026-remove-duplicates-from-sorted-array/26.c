/* 26. Remove Duplicates from Sorted Array */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

int removeDuplicates(int* nums, int numsSize){
	int k = 0;

	for (int i = 1; i < numsSize; ++i)
		if (nums[k] != nums[i])
			nums[++k] = nums[i];

	return k + 1;
}
