/* 27. Remove Elements */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

int removeElement(int* nums, int numsSize, int val){
	int to = 0;

	for (int from = 0; from < numsSize; ++from)
		if (nums[from] != val)
			nums[to++] = nums[from];

	return to;
}
