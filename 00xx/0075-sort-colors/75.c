/* 75. Sort Colors */

/* Complexities:
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

void sortColors(int *nums, int numsSize)
{
	int amount[3] = {0, 0, 0};

	for (int i = 0; i < numsSize; ++i)
		++amount[nums[i]];

	int i = 0;
	for (int color = 0; color < 3; ++color)
		for (int j = 0; j < amount[color]; ++i, ++j)
			nums[i] = color;
}
