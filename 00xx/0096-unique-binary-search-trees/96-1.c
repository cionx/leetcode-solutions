/* 96. Unique Binary Search Trees */

/* Recursive Solution. */

/* Complexities.
 * Time: O(n^2)
 * Space: O(n)
 * where n is the input number. */

/* Observation.
 * We have for bst(n) the recursive relation
 *  bst(n) = bst(0) bst(n-1) + bst(1) bst(n-2) + ... + bst(n-1) bst(0),
 * and the base case bst(0) = 1 (we could also use bst(1) = 1). */

#include <stdlib.h>

int numTrees(int n)
{
	int *results = malloc(((size_t) n + 1) * sizeof(int));
	results[0] = 1;
	for (int i = 1; i <= n; ++i) {
		results[i] = 0;
		for (int j = 0; j < i / 2; ++j)
			results[i] += 2 * results[j] * results[i - 1 - j];
		if (i % 2 == 1)
			results[i] += results[i/2] * results[i/2];
	}
	const int result = results[n];
	free(results);
	return result;
}
