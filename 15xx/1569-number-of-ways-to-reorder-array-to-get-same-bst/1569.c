#include <stdlib.h>

#define MODULO 1##000##000##007 /* 10^9 + 7 */
#define MAXN   1000

/* For an explanation of the calculations, we refer to the attacked markdown
 * file.
 */

typedef long long largeInt;

largeInt numOfWays(const int *nums, int numsSize);
largeInt numOfPermut(const int *nums, int numsSize);
int *smallerNums(const int *nums, int numsSize, int value, int *returnSize);
int *largerNums(const int *nums, int numsSize, int value, int *returnSize);
largeInt binomialModulo(int n, int k);

largeInt numOfWays(const int *nums, int numsSize)
{
	return numOfPermut(nums, numsSize) - 1;
}

largeInt numOfPermut(const int *nums, int numsSize)
{
	if (numsSize <= 2) {
		return 1;
	}

	const int first = nums[0];
	int smallerSize, largerSize;
	int *smaller = smallerNums(nums, numsSize, first, &smallerSize);
	int *larger = largerNums(nums, numsSize, first, &largerSize);
	const largeInt smallerResult = numOfPermut(smaller, smallerSize);
	const largeInt largerResult = numOfPermut(larger, largerSize);

	const int n = numsSize - 1;
	const int k = smallerSize;
	largeInt binom = binomialModulo(n, k);

	free(smaller);
	free(larger);

	return (((binom * smallerResult) % MODULO) * largerResult) % MODULO;
}

/* smallerNums:
 * Returns a new array that contains all the elements of the input array that
 * are strictly smaller than a specified value. The elements in the output array
 * are arranged in the same order as in the input array.
 */
int *smallerNums(const int *nums, int numsSize, int value, int *resultSize)
{
	*resultSize = 0;
	for (int i = 0; i < numsSize; ++i)
		if (nums[i] < value)
			++(*resultSize);

	int *result = malloc((size_t) (*resultSize) * sizeof(int));
	for (int i = 0, j = 0; i < numsSize; ++i)
		if (nums[i] < value)
			result[j++] = nums[i];

	return result;
}

/* largerNums:
 * Returns a new array that contains all the elements of the input array that
 * are strictly larger than a specified value. The elements in the output array
 * are arranged in the same order as in the input array.
 */
int *largerNums(const int *nums, int numsSize, int value, int *resultSize)
{
	*resultSize = 0;
	for (int i = 0; i < numsSize; ++i)
		if (nums[i] > value)
			++(*resultSize);

	int *result = malloc((size_t) (*resultSize) * sizeof(int));
	for (int i = 0, j = 0; i < numsSize; ++i)
		if (nums[i] > value)
			result[j++] = nums[i];

	return result;
}

/* binomialMod:
 * Computes binomial coefficients modulo MODULO.
 *
 * To avoid repeated expensive calculations, we cache the results. Note that
 * this cache persists throughout multiple calls to numOfPermut.
 *
 * We need to safe values binom(n, k) with 0 <= k<= n. For simplicity we use
 * 0 <= k, n <= MAXN. Most of the entries of the cache will therefore be unused.
 *
 * To calculate the binomial values, we use the following recursive formula:
 *   binom(n, k) = binom(n - 1, k) + binom(n - 1, k - 1)
 * This recursion boils down to the following base cases:
 *   binom(n, 0) = 1   for every natural number n,
 *   binom(n, n) = 1   for every natural number n.
 * We will also include the following edge cases:
 *   binom(n, k) = 0   whenever k < 0,
 *   binom(n, k) = 0   whenever k > n.
 * We should actually never reach these edge cases, but it’s better to be safe
 * than sorry.
 *
 * We will not safe the edge cases in the cache.
 */

largeInt binomialModulo(int n, int k)
{
	/* We make the cache static, so that
	 * 1. it is shared between different calls to binomialMod, and
	 * 2. it persists for future runs of binomialMod;
	 */
	static largeInt cache[MAXN * MAXN + 1];
	/* Be default, all values are initialized as 0. We change this to -1 the
	 * first time we enter this function. We can use the otherwise unused entry
	 * cache[0] to check if we have done so already. */
	if (cache[0] != -1)
		for (int i = 0; i <= MAXN * MAXN; ++i)
			cache[i] = -1;

	/* First the edge cases. */
	if (0 == k || k == n)
		return 1;
	if (k < 0 || n < k)
		return 0;

	/* Otherwise, looking for a cached value */
	const int cacheIndex = n * MAXN + k;
	const largeInt cacheValue = cache[cacheIndex];
	if (cacheValue != -1)
		return cacheValue;

	/* If no value has been cached before, calculate a new value, and save it in
	 * the cache before returning it. */
	const largeInt result =
		(binomialModulo(n - 1, k) + binomialModulo(n - 1, k - 1)) % MODULO;
	cache[cacheIndex] = result;

	return result;
}
