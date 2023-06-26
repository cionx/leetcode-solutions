/* 2140. Solving Questions With Brainpower */

/* Complexities.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input array. */

#include <stdlib.h>

long long mostPoints(int **questions, int questionsSize, int *questionsColSize);
long long max(long long a, long long b);

long long mostPoints(int **questions, int questionsSize, int *questionsColSize)
{
	/* For every integer i let
	 *   best(i)
	 * be the maximum points we can earn if we ignore all questions before the
	 * i-th one. We want to determine the value best(0). The function best
	 * satisfies the recursive relation
	 *   best(i) = maximum of points(i) + best(i + brainpower(i) + 1)
	 *                    and points(i+1).
	 * We can therefore determine the values of best iteratively, starting with
	 * the maximum value of i and then counting down. The starting value is
	 * simply the last number of points in the list.
	 */

	long long *best = malloc((size_t) questionsSize * sizeof(long long));

	/* Base case. */
	best[questionsSize - 1] = questions[questionsSize - 1][0];

	/* General recursion case (implemented iteratively). */
	for (int i = questionsSize - 2; i >= 0; --i) {
		const int j = i + questions[i][1] + 1; /* second summand is positive */
		const long long withThis =
			questions[i][0] + ((j < questionsSize) ? best[j] : 0);
		const long long withoutThis = best[i + 1];
		best[i] = max(withThis, withoutThis);
	}

	const long long result = best[0];
	free(best);
	return result;
}

long long max(long long a, long long b)
{
	return (a > b) ? a : b;
}
