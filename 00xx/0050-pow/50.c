/* 50. Pow(x, n) */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the length of the input list. */

#include <limits.h>

double myPow(double x, int n)
{
	if (n < 0) {
		if (n == INT_MIN) /* To prevent an overflow when going from n to -n. */
			return 1 / myPow(x * x, -(n / 2));
		else
			return 1 / myPow(x, -n);
	}

	double acc = 1.0;
	/* The value of x^n * acc will stay the same inbetween iterations. */

	while (n != 0) {
		if (n % 2 == 0) {
			x = x * x; /* Square x. */
			n /= 2;
		}
		else {
			acc *= x;
			--n;
		}
	}

	return acc;
}
