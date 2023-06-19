/* Time: O(log(n^2)) = O(2 log(n)) = O(log(n))
 * Space: O(1)
 *
 * where n is the input integer. */

/* Using Gauss’s summation formula
 *   ∑_{k = 1}^n k = n (n + 1) /2 ,
 * we can eventually reformulate and rearrange the equation
 *   ∑_{k = 1}^x k = ∑_{k = x}^n k
 * to
 *   x^2 = n (n + 1) / 2 .
 * There is probably a nice geometric reason for this, but I don’t know it.
 */

int pivotInteger(int n);
int maybeSqrt(int a);

int pivotInteger(int n)
{
	return maybeSqrt(n * (n + 1) / 2); /* n <= 1000, no overflow */
}

/* Returns sqrt(a) if a is a square number. Otherwise returns -1. */
int maybeSqrt(int a)
{
	int lower = 0;
	int upper = a;
	while (lower <= upper) {
		const int middle = lower + (upper - lower) / 2;
		const long long sqr = (long long) middle * middle;
		if (sqr < a)
			lower = middle + 1;
		else if (sqr > a)
			upper = middle - 1;
		else
			return middle;
	}

	return -1;
}
