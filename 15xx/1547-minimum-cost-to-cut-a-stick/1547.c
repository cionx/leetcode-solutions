#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * For k = cutsSize + 1, we will ultimately split apart the interval [0, n] into
 * k many subintervals. We will number the endpoints of these intervals all the
 * way from 0 through k (inclusive). Assuming that cuts is sorted in ascending
 * order, the situation will thus look as follows:
 *
 *    0     1         2         3           k-3         k-2         k-1      k
 *    |     |         |         |            |           |           |       |
 *    |-----|---------|---------|----...-----|-----------|-----------|-------|
 *    |     |         |         |            |           |           |       |
 *    0  cuts[0]   cuts[1]   cuts[2]     cuts[k-4]   cuts[k-3]   cuts[k-2]   n
 *
 * We will cache for all pairs (i, j) with  0 <= i < j <= k  the optimal value
 * for splitting apart the subinterval with endpoints i and j. We will consider
 * three cases:
 * - For  j = i + 1  this value will be zero,
 * - For  j = i + 2  this value will be the length of the subinterval.
 * - In general, this value will be given by the recursion formula
 *     value for (i, j) = length of the subinterval
 *                        + minimum of [ value for (i, l) + value for (l, j) ]
 *                          over all i < l < j.
 */

/* The overall function. */
int minCost(int n, int *cuts, int cutsSize);
/* Using the cache. */
void generateCacheValue(int *cache, int k, int n, int *cuts, int i, int j);
int getValue(const int *cache, int k, int i, int j);
void setValue(int *cache, int k, int i, int j, int value);
int calcIndex(int k, int i, int j);
/* Auxiliary functions. */
int cmpFunction(const void *a, const void *b);
int min(int a, int b);
/* Debugging. */
void printCache(int *cache, int k);

int minCost(int n, int *cuts, int cutsSize)
{
	/* We need cuts to be sorted in ascending order. As we do not want to change
	 * the input inplace without permission, we creaty a new copy first.
	 */
	int *sorted = malloc((size_t) cutsSize * sizeof(int));
	memcpy(sorted, cuts, (size_t) cutsSize * sizeof(int));
	cuts = sorted;
	qsort(cuts, (size_t) cutsSize, sizeof(int), cmpFunction);

	int k = cutsSize + 1;
	int cacheSize = (k + 1) * (k + 1);
	int *cache = malloc((size_t) cacheSize * sizeof(n));
	/* We actually only need to remember
	 *   binomial(k, 2) = k * (k - 1) /  *
	 * many values. But using a cache of this size makes the computanion of
	 *   (i, j)  -->   corresponding index for the cache
	 * more complicated, resulting in longer run times:
	 * our cache will use the formula
	 *   i * k + j,
	 * whereas a smaller cache would require something akin to
	 *   (i * k) - (i * (i + 1) / 2) + (j - i - 1)
	 * instead. (The actual formula depends on how we distribute the values
	 * into the cache. The above formula is for the convention
	 *   c(0, 1) | ... | c(0, k) | c(1, 2) | ... | c(1, k) | c(2, 3) | ...
	 * Since cutSize is at most 100, we decided to take a minor increase in
	 * memory (in absolute terms) for a significantly faster cache.
	 *
	 * As a visualization, this is how our current cache will look like for the
	 * second example provided by LeetCode (n = 9, cuts = [5, 6, 1, 4, 2]):
	 *
	 *   i = 0 |  *  0  2  6 10 14 22
	 *   i = 1 |  *  *  0  3  7 10 18
	 *   i = 2 |  *  *  *  0  3  6 13
	 *   i = 3 |  *  *  *  *  0  2  7
	 *   i = 4 |  *  *  *  *  *  0  4
	 *   i = 5 |  *  *  *  *  *  *  0
	 *   i = 6 |  *  *  *  *  *  *  *
	 *
	 * Here * refers to entries whose value we never access. (As we use malloc
	 * instead of calloc, these entries may be filled with garbage.)
	 */

	/* Initial values: Subintervals without cut*. */
	for (int i = 0; i < k; ++i)
		setValue(cache, k, i, i + 1, 0);

	/* Subintervals with at least one cuts inside. (One could also do the
	 * special case of exactly one cut by hand, as this would be faster.)
	 */
	for (int stepSize = 2; stepSize <= k; ++stepSize)
		for (int i = 0, j = i + stepSize; j <= k; ++i, ++j)
			generateCacheValue(cache, k, n, cuts, i, j);

	printCache(cache, k);
	const int result = getValue(cache, k, 0, k);

	free(sorted);
	free(cache);

	return result;
}

void generateCacheValue(int *cache, int k, int n, int *cuts, int i, int j)
{
	const int upper = (j == k ? n : cuts[j - 1]);
	const int lower = (i == 0 ? 0 : cuts[i - 1]);
	const int length = upper - lower;

	int bestRecursion;
	bestRecursion = getValue(cache, k, i, i + 1) + getValue(cache, k, i + 1, j);
	for (int l = i + 2; l < j; ++l) {
		int possible = getValue(cache, k, i, l) + getValue(cache, k, l, j);
		bestRecursion = min(bestRecursion, possible);
	}

	setValue(cache, k, i, j, length + bestRecursion);
}

int getValue(const int *cache, int k, int i, int j)
{
	return cache[calcIndex(k, i, j)];
}

void setValue(int *cache, int k, int i, int j, int value)
{
	cache[calcIndex(k, i, j)] = value;
}

int calcIndex(int k, int i, int j)
{
	return i * (k + 1) + j;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

/* Taken from https://stackoverflow.com/a/27284248/21949339. */
int cmpFunction(const void *a, const void *b)
{
	const int *A = a, *B = b;
	return (*A > *B) - (*A < *B);
}

void printCache(int *cache, int k)
{
	for (int i = 0; i <= k; ++i) {
		printf("i = %d |", i);
		for (int j = 0; j <= k; ++j)
			printf(" %2d", getValue(cache, k, i, j));
		printf("\n");
	}
	printf("\n");
}

/* Don’t copy the below to LeetCode. */

int main(void)
{
	int n = 2;
	int cuts[] = {1};
	int cutSize = 1;

	int result = minCost(n, cuts, cutSize);
	printf("%d\n", result);

	return 0;
}
