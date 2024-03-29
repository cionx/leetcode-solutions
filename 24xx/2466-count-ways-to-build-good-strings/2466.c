/* 2466. Count Ways to Build Good Strings */

/* Complexities.
 * Time: O(high)
 * Space: O(high)
 * where high is as in the problem description. */

#include <stdlib.h>

#define NORESULT -1
#define MODULO   1##000##000##007

int countGoodStrings(int low, int high, int zero, int one);
int computeValue(int low, int high, int one, int zero, int result[]);

int countGoodStrings(int low, int high, int zero, int one)
{
	int *results = malloc(((size_t) high + 1) * sizeof(int));
	for (int i = 0; i <= high; i++) {
		results[i] = NORESULT;
	}
	results[0] = 1;
	return computeValue(low, high, zero, one, results);
}

/* computeValue(low, high, zero, one, ...) is the number of good strings
   in the interval between low and high (inclusive). */
int computeValue(int low, int high, int zero, int one, int results[])
{
	if (high < 0)
		return 0;
	else if (results[high] == NORESULT) {
		/* the number of strings coming from the general recursion */
		results[high] =
			computeValue(low - zero, high - zero, zero, one, results) +
			computeValue(low - one, high - one, zero, one, results);
		/* the special case of the empty string */
		if (low <= 0)
			results[high]++;
	}
	results[high] %= MODULO;
	return results[high];
}
