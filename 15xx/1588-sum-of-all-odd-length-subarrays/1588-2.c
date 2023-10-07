/* 1588. Sum of All Odd Length Subarrays */

/* Brute force solution, slightly optimized with prefix sums. */

/* Complexities.
 * Time: Θ(n^2)
 * Space: Θ(n)
 * where n is the length of the input array. */

#include <stdlib.h>

int sumOddLengthSubarrays(int *arr, int arrSize);
int subarraySum(int *arr, int start, int length);

int sumOddLengthSubarrays(int *arr, int arrSize)
{
	/* prefixSums[i] is the sum arr[0] + ... + arr[i - 1]. This convention is
	 * chosen so that the difference prefixSums[j] - prefixSums[i] for j > i
	 * equals the sum starting at arr[i] of length j - i; */
	int *prefixSums = malloc(((size_t) arrSize + 1) * sizeof(int));
	int pSum = 0;
	prefixSums[0] = pSum;
	for (int i = 0; i < arrSize; ++i) {
		pSum += arr[i];
		prefixSums[i + 1] = pSum;
	}

	int sum = 0;
	for (int start = 0; start < arrSize; ++start)
		for (int length = 1; start + length <= arrSize; length += 2)
			/* Sanity check: start + length is the first index beyond the
			 * subarray, and arrSize is the first out-of-bound index. */
			sum += prefixSums[start + length] - prefixSums[start];

	return sum;
}
