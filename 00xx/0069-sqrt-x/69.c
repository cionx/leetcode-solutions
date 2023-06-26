/* 69. Sqrt(x) */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input non-negative integer. */

int mySqrt(int n)
{
	int lower = 0, upper = n;

	while (lower < upper) {
		const int middle = lower + (upper - lower - 1) / 2 + 1; /* rounded up */
		const long long sqr = (long long) middle * middle;
		if (sqr > n)
			upper = middle - 1;
		else if (sqr < n)
			lower = middle;
		else
			return middle;
	}

	return lower;
}
