/* 27. Remove Elements */

/* Complexities
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

int removeElement(int* nums, int numsSize, int val){
	int k = 0;

	for (int i = 0; i < numsSize; ++i)
		if (nums[i] != val)
			nums[k++] = nums[i];

	return k;
}
