/* 414. Third Maximum Number */

/* Complexity.
 * Time: O(n) with three passes
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdbool.h>

int thirdMax(int *nums, int numsSize)
{
	int max[3];
	int i;

	/* First maximum. */
	max[0] = nums[0];
	for (i = 1; i < numsSize; ++i)
		if (nums[i] > max[0])
			max[0] = nums[i];

	/* Second maximum. */
	for (i = 0; i < numsSize; ++i)
		if (nums[i] != max[0])
			break;
	if (i == numsSize)
		return max[0];
	max[1] = nums[i];
	for (++i; i < numsSize; ++i)
		if (nums[i] > max[1] && nums[i] != max[0])
			max[1] = nums[i];

	/* Third maximum. */
	for (i = 0; i < numsSize; ++i)
		if (nums[i] != max[0] && nums[i] != max[1])
			break;
	if (i == numsSize)
		return max[0];
	max[2] = nums[i];
	for (++i; i < numsSize; ++i)
		if (nums[i] > max[2] && nums[i] < max[1])
			max[2] = nums[i];

	return max[2];
}
