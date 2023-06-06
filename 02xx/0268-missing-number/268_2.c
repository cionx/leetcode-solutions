/* Time:  O(n)
 * Space: O(1)
 */
int missingNumber(int *nums, int numsSize)
{
	int partialSum = 0;
	for (int i = 0; i < numsSize; ++i)
		partialSum += nums[i];

	int totalSum = numsSize * (numsSize + 1) / 2;
	int missing = totalSum - partialSum;

	return missing;
}
/* Note: an int is only guaranteed to have 16 bit, which may not be enough to
 * hold totalSum, so an overflow may occur. Similar for partialSum. But these
 * potential overflows don’t affect the difference totalSum - partialSum, since
 * it will lie in the range of int.
 */
