/* 326. Power of Three */

/* Iterative solution. */

/* Complexities.
 * Time O(log(n))
 * Space: Θ(1)
 * where n is the input number. */

#include <stdbool.h>

bool isPowerOfThree(int n)
{
	if (n < 1)
		return false;

	while (n % 3 == 0)
		n /= 3;

	return n == 1;
}
