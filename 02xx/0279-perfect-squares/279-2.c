/* 279. Perfect Squares */

/* Complexities.
 * Time: O(n^(3/2))
 * Space: O(n)
 * where n is the input number. (Note that there are roughly sqrt(k) = k^(1/2)
 * many square numbers below k. Integrating k = 0 to n, we get n^(3/2). */

#include <stdlib.h>

int numSquares(int n)
{
	/* The result cache persists between multiple function calls. */
	int *results = malloc((size_t) (n + 1) * sizeof(int));
	results[0] = 0;

	for (int k = 1; k <= n; ++k) {
		int min = results[k - 1];
		for (int d = 2, sqr; (sqr = d * d) <= k; ++d)
			if (results[k - sqr] < min)
				min = results[k - sqr];
		results[k] = min + 1;
	}

	const int result = results[n];
	free(results);
	return result;
}
