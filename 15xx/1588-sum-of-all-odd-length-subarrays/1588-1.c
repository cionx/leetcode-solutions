/* 1588. Sum of All Odd Length Subarrays */

/* Brute force solution. */

/* Complexities.
 * Time: Θ(n^3)
 * Space: Θ(1)
 * where n is the length of the input array. */

int sumOddLengthSubarrays(int *arr, int arrSize);
int subarraySum(int *arr, int start, int length);

int sumOddLengthSubarrays(int *arr, int arrSize)
{
	int sum = 0;
	for (int start = 0; start < arrSize; ++start)
		for (int length = 1; start + length <= arrSize; length += 2)
			/* Sanity check: start + length is the first index beyond the
			 * subarray, and arrSize is the first out-of-bound index. */
			sum += subarraySum(arr, start, length);

	return sum;
}

int subarraySum(int *arr, int start, int length)
{
	int sum = 0;
	for (int i = start; i < start + length; ++i)
		sum += arr[i];
	return sum;
}
