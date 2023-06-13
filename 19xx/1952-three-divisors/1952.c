/* Time: O(fourth root of n)
 * Space: O(1)
 */

/* We need to check if the given input n is the square of a prime number.
 */

#include <stdbool.h>

bool isThree(int n);
int square(int n);
int isPrime(int n);

bool isThree(int n)
{
	int sqr = square(n);
	if (sqr == -1)
		return false;
	else return isPrime(sqr);
}

int square(int n)
{
	/* Search for an integer square root of n via binary search. */
	int lower = 1;
	int upper = n;
	while (lower <= upper) {
		const int middle = lower + (upper - lower) / 2;
		const int sqr = middle * middle;
		if (sqr < n)
			lower = middle + 1;
		else if (sqr > n)
			upper = middle - 1;
		else
			return middle;
	}

	return -1;
}


int isPrime(int n)
{
	if (n <= 1)
		return false;

	for (int d = 2; d * d <= n; ++d)
		if (n % d == 0)
			return false;

	return true;
}
