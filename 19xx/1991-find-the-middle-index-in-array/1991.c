/* 1991. Find the Middle Index in Array */

/* Complexity.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list.
 */

/* Note.
 * This problem is the same as 724 (Find Pivot Index). */

int findMiddleIndex(int *nums, int numsSize)
{
	long leftSum = 0; /* Holds values between -1e7 and 1e7. */
	long rightSum = 0;
	for (int i = 0; i < numsSize; ++i)
		rightSum += nums[i];

	for (int i = 0; i < numsSize; ++i) {
		rightSum -= nums[i];
		if (leftSum == rightSum)
			return i;
		leftSum += nums[i];
	}

	return -1;
}
