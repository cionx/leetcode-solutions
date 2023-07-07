/* 643. Maximum Average Subarray I */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

double findMaxAverage(int *nums, int numsSize, int k)
{
	long long sum = 0;
	for (int i = 0; i < k; ++i)
		sum += nums[i];
	long long maxSum = sum;
	for (int i = k; i < numsSize; ++i) {
		sum = sum - nums[i - k] + nums[i];
		if (sum > maxSum)
			maxSum = sum;
	}
	return (double) maxSum / (double) k;
}
