/* 204. Count Primes */

/* Complexities.
 * Time: ?
 * Space: O(n)
 * where n is the input number. */

/* We will use the sieve of Eratosthenes, with the following minor changes:
 * - We will only sieve through the odd numbers 3, 5, 7, 9, 11, ...
 * - Once we are at prime that is larger than sqrt(n), we stop sieving and count
 *   the remaining primes.
 */

#include <stdbool.h>
#include <stdlib.h>

int countPrimes(int n)
{
	if (n <= 2)
		return 0;

	/* The numbers 3, 5, 7, ..., (n-1 or n). The position of k is (k - 3) / 2 */
	long size = (n - 2) / 2;
	bool *notPrime = calloc((size_t) size, sizeof(bool));

	int counter = 0;
	long index = 0;
	long prime = 3;
	while (prime * prime < n) {
		++counter;
		/* Mark multiples as not prime. */
		for (long j = (prime * prime - 3) / 2; j < size; j += prime)
			notPrime[j] = true;
		/* Search the next prime. */
		while (notPrime[++index])
			;
		prime = index * 2 + 3;
	}

	for (; index < size; ++index)
		if (!notPrime[index])
			++counter;

	free(notPrime);
	return counter + 1; /* We haven’t counted 2 yet. */
}
