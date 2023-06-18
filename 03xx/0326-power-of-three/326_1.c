/* Iterative solution.
 *
 * Time O(log(n))
 * Space: O(1)
 */

#include <stdbool.h>

bool isPowerOfThree(int n)
{
	if (n < 1)
		return false;

	while (n % 3 == 0)
		n /= 3;

	return n == 1;
}
