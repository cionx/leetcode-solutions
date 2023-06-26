/* 278. First Bad Version */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input number. Assumes that isBadVersion is in O(1). */

#include <stdbool.h>

/* Don’t copy this function declaration to LeetCode. */
extern bool isBadVersion(int version);

int firstBadVersion(int n)
{
	int lower = 0;
	int upper = n;

	while (lower < upper) {
		const int middle = lower + (upper - lower) / 2;
		if (isBadVersion(middle))
			upper = middle;
		else
			lower = middle + 1;
	}

	return lower;
}
