/* 191. Number of 1 Bits */

/* Complexities.
 * Time: Θ(d)
 * Space: Θ(1)
 * where n is the input number and d ~ log(n) is the number of digits of n. */

#include <stdint.h>

int hammingWeight(uint32_t n)
{
	int counter;
	for (counter = 0; n != 0; n >>= 1) { /* Could also use n /= 2. */
		counter += n & 1;                /* Could also use n % 2. */
	}

	return counter;
}
