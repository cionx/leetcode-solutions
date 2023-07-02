/* 342. Power of Four */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input integer. */

#include <stdbool.h>

bool isPowerOfFour(int n){
	if (n <= 0)
		return false;

	while (n % 4 == 0)
		n /= 4;

	return n == 1;
}
