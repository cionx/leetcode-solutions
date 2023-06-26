/* 263. Ugly Number */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input number. */

#include <stdbool.h>

bool isUgly(int n)
{
	if (n < 1)
		return false;

	while (n % 5 == 0)
		n /= 5;
	while (n % 3 == 0)
		n /= 3;
	while (n % 2 == 0)
		n /= 2;

	return n == 1;
}
