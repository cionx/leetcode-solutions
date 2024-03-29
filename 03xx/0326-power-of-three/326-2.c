/* 326. Power of Three */

/* Recursive solution. */

/* Complexities.
 * Time O(log(n))
 * Space: with tail recursion elimination: Θ(1)
 *        without tail recursion elimination: O(log(n))
 * where n is the input number. */

#include <stdbool.h>

bool isPowerOfThree(int n);
bool helper(int n);

bool isPowerOfThree(int n)
{
	if (n < 1)
		return false;
	return helper(n);
}

bool helper(int n)
{
	/* We could also use
	 *   return (n == 1) || (n % 3 == 0 && helper(n / 3))
	 * by I don’t know if this would be tail recursive. (I’d hope so.)
	 */
	if (n == 1)
		return true;
	if (n % 3 == 0)
		return helper(n / 3);
	return false;
}
