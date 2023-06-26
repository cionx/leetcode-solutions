/* 283. Move Zeroes */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <string.h>

void moveZeroes(int* nums, int numsSize){
	int j = 0;

	for (int i = 0; i < numsSize; ++i)
		if (nums[i] != 0)
			nums[j++] = nums[i];

	memset(nums + j, 0, (size_t) (numsSize - j) * sizeof(int));
}
