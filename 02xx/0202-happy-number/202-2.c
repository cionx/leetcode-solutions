/* 202. Happy Number */

/* Complexities.
 * Time: O(extremly fast)
 * Space: O(1)
 * See the previous solution for more details on the time complexity. */

#include <stdbool.h>

int happyValue(int n);
bool isHappy(int n);

/* Note: a d-digit number has a happy value of at most 81 * d. Numbers with one
 * or two digits may grow larger at first, but already for three-digit numbers,
 * the maximal happy value is 243. Going downwards from 243, one can check that
 * by trial-and-error that 99 is the largest number who’s happy value is larger
 * than the number itself. In other words: for every start value n, we will
 * eventually land in the interval [1, 99].
 *
 * If we have been in this interval 100 times, then we know for sure that we
 * have repeated a value, and must therefore be trapped in a cycle.
 *
 * Using this approach, we can first determine all happy numbers in [1, 99], and
 * then determine how they actually get to 1:
 *
 *            44--32--13--23
 *                     |
 *       70  94   79   *--31  86  28  91
 *        |   |    |   |       |   |   |
 *    7--49--97--130--10--1--100--68--82--19
 *
 * We see that, in the worst case, we need to spend 4 steps in [1, 99] to
 * reach 1. So if we spend 5 steps in [1, 99], then we know that we’re trapped
 * in a cycle.
 */

bool isHappy(int n)
{
	if (n <= 0)
		return false;

	int smaller100 = 0;
	while (n > 100)
		n = happyValue(n);
	for (; n > 1; n = happyValue(n)) {
		smaller100 += n < 100;
		if (smaller100 == 5)
			return false;
	}

	return true;
}

int happyValue(int n)
{
	static int squares[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
	int sum;
	for (sum = 0; n > 0; n /= 10)
		sum += squares[n % 10];
	return sum;
}
