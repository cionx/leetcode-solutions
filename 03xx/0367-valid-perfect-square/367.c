/* 367. Valid Perfect Square */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input integer. */

#include <stdbool.h>

bool isPerfectSquare(int n)
{
	/* We are searching for the smallest integer x with x * x >= n. In other
	 * words, ceil(sqrt(n)). */
	int lower = 0;
	int upper = n;
	while (lower < upper) {
		const int middle = lower + (upper - lower) / 2;
		if ((long) middle * middle < n)
			lower = middle + 1;
		else
			upper = middle;
	}

	return (long) lower * lower == n;
}
