/* 410. Split Array Largest Sum */

/* Complexities
 * Time: O(n * k)
 * Space: O(n * k)
 * where n is the length of the list, and k is the number of subarrays.
 * (Note that thanks to memoization, the recursion doesn’t give us cursed
 * running time.) */

#include <stdlib.h>

typedef struct {
	int numsSize;
	long long *values;
	long long *prefixSums;
	int *prefixMaxs;
} statics;

/* THE MAIN FUNCTIONS */
int splitArray(int *nums, int numsSize, int k);
long long getValue(int *arr, int arrSize, int k, statics *memories);
long long calcValue(int *arr, int arrSize, int k, statics *memories);
/* AUXILIARY FUNCTIONS */
int max(int a, int b);
long long maxll(long long a, long long b);
long long min(long long a, long long b);

/* THE MAIN FUNCTIONS */

int splitArray(int *nums, int numsSize, int k)
{
	long long *prefixSums = malloc((size_t) (numsSize + 1) * sizeof(long long));
	++prefixSums;
	long long sum = 0;
	prefixSums[-1] = sum;
	for (int i = 0; i < numsSize; ++i)
		prefixSums[i] = (sum = sum + nums[i]);

	int *prefixMaxs = malloc((size_t) numsSize * sizeof(int));
	int m = (prefixMaxs[0] = nums[0]);
	for (int i = 1; i < numsSize; ++i)
		prefixMaxs[i] = (m = max(m, nums[i]));

	long long *cache =
		malloc((size_t) numsSize * (size_t) k * sizeof(long long));
	for (int i = 0; i < numsSize * k; ++i)
		cache[i] = -1;

	statics totalCache = {numsSize, cache, prefixSums, prefixMaxs};

	const long long result = getValue(nums, numsSize, k, &totalCache);

	free(prefixSums - 1);
	free(prefixMaxs);
	free(cache);
	return (int) result;
}

long long getValue(int *arr, int arrSize, int k, statics *cache)
{
	/* If the array is empty, then all subarrays are empty, whence all subarray
	 * sums are zero. */
	if (arrSize == 0)
		return 0;

	/* If we have only subarray, then this subarray is the entire array. */
	if (k == 1)
		return cache->prefixSums[arrSize - 1];

	/* If possible, it is best to use only empty and one-element subarrays. */
	if (arrSize <= k)
		return cache->prefixMaxs[arrSize - 1];

	const int index = (k - 1) * cache->numsSize + (arrSize - 1);
	long long value = cache->values[index];
	if (value != -1)
		return value;

	value = calcValue(arr, arrSize, k, cache);
	cache->values[index] = value;
	return value;
	;
}

long long calcValue(int *arr, int arrSize, int k, statics *cache)
{
	/* Starting value: the entire array is one single subarray, all other
	 * subarrays are empty. */
	long long result = cache->prefixSums[arrSize - 1];

	/* We use nums[leftSize + 1 : arrSize - 1] as the last subarray. In the case
	 * of leftSize < k - 1, the left part would have some empty subarrays, which
	 * would be strictly suboptimal. It would similarly be suboptimal to have
	 * leftSize = arrSize, as this would mean that the last subarray is empty.
	 */
	for (int leftSize = k - 1; leftSize < arrSize; ++leftSize) {
		const long long rightSum =
			cache->prefixSums[arrSize - 1] - cache->prefixSums[leftSize - 1];
		const long long bestLeftResult = getValue(arr, leftSize, k - 1, cache);
		/* The term bestLeftResult keeps increasing throughout the iterations,
		 * whereas the term rightSum keeps decreasing. Therefore, once we reach
		 * the point bestLeftResult >= rightSum, the term curMaxSum will only
		 * keep on increasing throughout any future loop iterations. We can
		 * therefore skip these iterations. */
		/* (The expression curMaxSum is convex as a function of the variable
		 * leftSize. We could therefore use ternary search to determine the
		 * minimum. This could maybe give a better running time.) */
		const long long curMaxSum = maxll(bestLeftResult, rightSum);
		result = min(result, curMaxSum);
		if (bestLeftResult >= rightSum)
			break;
	}

	return result;
}

/* AUXILIARY FUNCTIONS */

inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

inline long long maxll(long long a, long long b)
{
	return (a > b) ? a : b;
}

inline long long min(long long a, long long b)
{
	return (a < b) ? a : b;
}
