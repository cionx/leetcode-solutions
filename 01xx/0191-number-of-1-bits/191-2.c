/* 191. Number of 1 Bits */

/* Complexities.
 * Time: Θ(b)
 * Space: Θ(1)
 * where b is the number of set bits in the binary representation of the input
 * number. */

#include <stdint.h>

int hammingWeight(uint32_t n)
{
	int counter = 0;
	while (n != 0) {
		++counter;
		n &= n - 1;
	}
	return counter;
}
