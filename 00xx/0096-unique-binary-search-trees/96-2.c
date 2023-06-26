/* 96. Unique Binary Search Trees */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the input number. */

/* Observation.
 * We have for bst(n) the recursive relation
 *  bst(n) = bst(0) bst(n-1) + bst(1) bst(n-2) + ... + bst(n-1) bst(0),
 * and the base case bst(0) = 1 (we could also use bst(1) = 1). The value bst(n)
 * is therefore the n-th Catalan number. It can therefore be computed as
 * binom(2 n, n) / (n + 1). */

#include <stdlib.h>

int numTrees(int n);
long long binomial(int n, int k);

int numTrees(int n)
{
	return (int) (binomial(2 * n, n) / (n + 1));
}

long long binomial(int n, int k)
{
	if (k < 0 || k > n)
		return 0;
	if (n - k < k)
		return binomial(n, n - k);
	long long prod = 1;
	for (int i = 0; i < k; ++i) {
		prod *= (n - i);
		prod /= (i + 1);
		/* prod will be cleanly divisible by (i + 1): we are using the recursive
		 * relation binom(n, k) = binom(n, k - 1) * (n - k) / k. */
	}
	return prod;
}
