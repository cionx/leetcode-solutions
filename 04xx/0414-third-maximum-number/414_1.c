/* 414. Third Maximum Number */

/* Complexity.
 * Time: O(n) with only one pass
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdbool.h>

int thirdMax(int *nums, int numsSize)
{
	int max[3];
	bool foundThird = false;

	/* First distinct number. */
	max[0] = nums[0];

	int i = 0;

	/* Second distinct number. */
	for (; i < numsSize; ++i)
		if (nums[i] != max[0]) {
			if (nums[i] > max[0]) {
				max[1] = max[0];
				max[0] = nums[i];
			}
			else
				max[1] = nums[i];
			break;
		}

	/* Third distinct number. */
	for (++i; i < numsSize; ++i)
		if (nums[i] != max[0] && nums[i] != max[1]) {
			if (nums[i] > max[0]) {
				max[2] = max[1];
				max[1] = max[0];
				max[0] = nums[i];
			}
			else if (nums[i] > max[1]) {
				max[2] = max[1];
				max[1] = nums[i];
			}
			else
				max[2] = nums[i];
			foundThird = true;
			break;
		}

	/* Rest of the numbers. */
	for (++i; i < numsSize; ++i)
		if (nums[i] > max[2] && nums[i] != max[0] && nums[i] != max[1]) {
			if (nums[i] > max[0]) {
				max[2] = max[1];
				max[1] = max[0];
				max[0] = nums[i];
			}
			else if (nums[i] > max[1]) {
				max[2] = max[1];
				max[1] = nums[i];
			}
			else
				max[2] = nums[i];
		}

	if (!foundThird)
		return max[0];
	return max[2];
}
