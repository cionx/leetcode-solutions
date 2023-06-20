/* 2733. Neither Minimum nor Maximum */

/* Complexities.
 * Time: O(1)
 * Space: O(1)
 */

int findNonMinOrMax(int *nums, int numsSize)
{
	if (numsSize < 3)
		return -1;

	const int x = nums[0];
	const int y = nums[1];
	const int z = nums[2];
	if (y < x && x < z || z < x && x < y)
		return x;
	if (x < y && y < z || z < y && y < x)
		return y;
	return z;
}
