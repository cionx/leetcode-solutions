/* 279. Perfect Squares */

/* Complexities.
 * Time: O(LIMIT + n^(3/2))
 * Space: O(LIMIT)
 * where LIMIT is 10000 and n is the input number. */

#include <stdbool.h>

#define LIMIT 10000

int numSquares(int n);
int getNextIndex(int results[]);

int numSquares(int n)
{
	/* The result cache persists between multiple function calls. */
	static int results[LIMIT + 1];

	/* This block happens only on the first function call. */
	static bool initialized = false;
	if (!initialized) {
		for (int i = 0; i <= LIMIT; ++i)
			results[i] = -1;
		results[0] = 0;
		initialized = true;
	}

	/* We may have already calculated the result in a previous run. */
	if (results[n] != -1)
		return results[n];

	/* Otherwise we continue calculating where we left off last time. */
	for (int k = getNextIndex(results); k <= n; ++k) {
		int min = results[k - 1];
		for (int d = 2, sqr; (sqr = d * d) <= k; ++d)
			if (results[k - sqr] < min)
				min = results[k - sqr];
		results[k] = min + 1;
	}

	return results[n];
}

/* getNextIndex: gets the first entry that is still set to -1. If not such entry
 * exists, returns the first out-of-bound index. */
int getNextIndex(int results[])
{
	int lower = 0;
	int upper = LIMIT + 2;
	while (lower < upper) {
		const int middle = lower + (upper - lower) / 2; /* rounded down */
		if (results[middle] == -1)
			upper = middle;
		else
			lower = middle + 1;
	}
	return upper;
}
