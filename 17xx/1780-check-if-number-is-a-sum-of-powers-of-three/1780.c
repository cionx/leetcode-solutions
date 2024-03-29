/* 1780. Check if Number is a Sum of Powers of Three */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input number. */

#include <stdbool.h>

/* We have to check that all digits in the base-3-representation of n are either
 * 0 or 1. */
bool checkPowersOfThree(int n)
{
	if (n < 0)
		return false;

	for (; n > 0; n /= 3)
		if (n % 3 == 2)
			return false;

	return true;
}
