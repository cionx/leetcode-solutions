#include <stdint.h>

int hammingWeight(uint32_t n)
{
	int counter;
	for (counter = 0; n != 0; n >>= 1) { /* Could also use n /= 2. */
		counter += n & 1;                /* Could also use n % 2. */
	}

	return counter;
}
