/* 268. Missing Number */

/* Complexities.
 * Time:  O(n)
 * Space: O(1)
 * where n is the length of the input array.
 */

int missingNumber(int *nums, int numsSize)
{

	long long partialSum = 0;
	for (int i = 0; i < numsSize; ++i)
		partialSum += nums[i];

	long long totalSum = numsSize * ((long long) numsSize + 1) / 2;
	long long missing = totalSum - partialSum;

	return (int) missing;
}

/* Note: we use long long to avoid overflows. */
