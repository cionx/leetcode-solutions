/* 231. Power of Two */

/* Complexities.
 * Time: O(1)
 * Space: O(1)
 * where n is the input number. */

/* Suppose that n > 0. Then by passing from n to n - 1, the following happens:
 *
 *  *******1000...000     n
 *
 *  *******0111...111     n - 1
 *
 * We see that passing from n to n & (n - 1) sets the first 1 (from the right)
 * to 0. We can therefore check if the binary representation of n contains
 * precisely one 1 by checking if n & (n - 1) has no 1s, i.e., by checking if
 * n & (n - 1) is zero.
 */

#include <stdbool.h>

bool isPowerOfTwo(int n)
{
	return (n > 0) && !(n & (n - 1));
}
