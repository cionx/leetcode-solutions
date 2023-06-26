/* 779. K-th Symbol in Grammar */

/* Complexities.
 * Time: O(n)
 * Space: with tail recursion elimination: O(1)
 *        without tail recursion elimination: O(n)
 * where n is one of the input integers as in the problem statement. */

/* Idea.
 * The first few rows are as follows:
 *  0
 *  01
 *  0110
 *  01101001
 *  0110100110010110
 *  ...
 * We can observe that
 *  - the n-th row has 2^(n-1) many digits,
 *  - the first half of a row is equal to the previous row, and
 *  - the second half of a row is the bitwise flipped of the previous row.
 * We can derive a recursive relation from these observations:
 *  - s(n, k) = s(n - 1, k) if k <= 2^(n-2)
 *  - s(n, k) = flipped of s(n - 1, k - 2^(n-2)) otherwise.
 * As a base case, we have s(1, 0) = 0. */

#include <stdbool.h>
#include <stdint.h>

int kthGrammar(int n, int k);
int helper(int n, int k, bool needsFlip);

int kthGrammar(int n, int k)
{
	return helper(n, k, false);
}

int helper(int n, int k, bool needsFlip)
{
	if (n == 1)
		return needsFlip ? 1 : 0;

	/* The largest power of n that we need is 2^28 */
	int32_t pow2 = 1 << (n - 2);
	if (k <= pow2)
		return helper(n - 1, k, needsFlip);
	else
		return helper(n - 1, k - pow2, !needsFlip);
}
