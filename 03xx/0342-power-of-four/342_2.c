/* Time: O(1)
 * Space: O(1)
 *
 * where n is the input integer. */

/* Recall from problem 231 that a number n > 0 is a power of two if and only if
 * n & (n - 1) is zero. This can be tested in O(1). To test whether a power of 2
 * is also a power of 4, we go modulo 3. We have
 *   2 ≡ -1 mod 3
 * and therefore
 *   2^k ≡ (-1)^k mod 3.
 * It follows that for n = 2^k we have the sequence of equivalences
 *       n is a power of 2
 *   iff k is even
 *   iff n ≡ 1 mod 3.
 * This last condition can be tested in O(1) via (n % 3 == 1).
 */

#include <stdbool.h>

bool isPowerOfFour(int n)
{
	return (n > 0) && !(n & (n - 1)) && (n % 3 == 1);
}
