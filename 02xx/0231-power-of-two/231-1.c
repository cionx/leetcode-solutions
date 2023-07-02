/* 231. Power of Two */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input number. */

#include <stdbool.h>

bool isPowerOfTwo(int n){
	if (n <= 0)
		return false;

	while ((n & 1) == 0)
		n >>= 1;

	return (n >> 1) == 0;
}
