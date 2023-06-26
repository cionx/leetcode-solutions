/* 2438. Range Product Queries of Powers */

/* Complexities.
 * Time: O(log(n) + q * log(log(n)))
 * Space: O(1)
 * where n is the input number, and q is the length of the query array. */

/*
 * In the time complexity, the last term, log(log(n)) comes about as follows:
 * - For each query, we first determine the resulting exponent sum in O(1).
 * - We then compute the resulting power of 2, which takes log(sum), where sum
 *   is the exponent sum.
 * - The exponent sum is O(m^2), where m is the maximal exponent occurring in n.
 * - This maximal exponent is in log(n).
 * We thus get worst case
 *     O(log(sum))
 *   = O(log(m^2))
 *   = O(log(log(n)^2))
 *   = O(2 log(log(n)))
 *   = O(log(log(n))
 * for each query call.
 */

/* Idea: a product 2^{n1} * 2^{n2} * ... * 2^{ns} = 2^{n1 + n2 + ns} can be
 * reduced to addition of consequitive exponents, which can be done via prefix
 * sums. */

#include <stdlib.h>

#define MODULO 1##000##000##007

int *productQueries(int n, int **queries, int queriesSize, int *queriesColSize,
                    int *returnSize);
int extractSum(int expSums[], int from, int to);
int twoPowModulo(int exponent);

int *productQueries(int n, int **queries, int queriesSize, int *queriesColSize,
                    int *returnSize)
{
	/* The maximum value of n is 10^9, and log2(10^9) ≈ 29.897 < 30, so
	 * 10^9 < 2^30. We therefore have at most 30 exponents, namely the exponents
	 * 0, 1, 2, ..., 29. */
	int exps[30] = {0}; /* The additional zeros shouldn’t be needed, but they */
	int expsSize = 0;   /* provide some help against index errors.            */

	for (int e = 0; n > 0; n /= 2, ++e)
		if (n % 2 == 1)
			exps[expsSize++] = e;

	/* The largest possible sum of exponents is 0 + 1 + 2 + ... + 29 = 435, and
	 * therefore fits into an int. We will store the exponent sums
	 * exps[0] + exps[1] + ... + exps[i] again in exps. */
	for (int i = 0, prevSum = 0; i < expsSize; prevSum = exps[i++])
		exps[i] += prevSum;

	int *result = malloc((size_t) queriesSize * sizeof(int));
	for (int i = 0; i < queriesSize; ++i) {
		int exponent = extractSum(exps, queries[i][0], queries[i][1]);
		result[i] = twoPowModulo(exponent);
	}

	*returnSize = queriesSize;
	return result;
}

int extractSum(int expSums[], int from, int to)
{
	return expSums[to] - ((from > 0) ? expSums[from - 1] : 0);
}

int twoPowModulo(int exponent)
{
	/* The products factor * base and base * base can lead to overflows with
	 only ints. As base and factor can go up to 10^9, we need space for 10^18.
	 This is guaranteed by long long, which goes up to around 9e18. */
	long long factor = 1;
	long long base = 2;
	/* Loop invariant: factor * base^exponent */
	while (exponent > 0) {
		if (exponent % 2 == 0) {
			base = (base * base) % MODULO;
			exponent /= 2;
		}
		else {
			factor = (factor * base) % MODULO;
			--exponent;
		}
	}
	return (int) factor;
}
