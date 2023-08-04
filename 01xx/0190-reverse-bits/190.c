/* 190. Reverse Bits */

/* Complexities.
 * Time: Θ(b)
 * Space: Θ(1)
 * where b is the number of bits (which is fixed as 32). */

#include <stdint.h>

#define BITS 32

uint32_t reverseBits(uint32_t n)
{
	uint32_t result = 0;
	for (int _ = 0; _ < BITS; ++_, n >>= 1) {
		result <<= 1;
		result |= n & 1;
	}
	return result;
}
