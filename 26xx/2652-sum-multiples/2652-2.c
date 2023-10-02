/* 2652. Sum Multiples */

/* Complexities.
 * Time: Θ(1)
 * Space: Θ(1)
 */

/* Idea.
 * The sum of all multiples of d from 1 to n is given by
 *     sum of d * i for k = 1, ..., ⌊n / d⌋
 *   = d * sum of i for k = 1, ..., ⌊n / d⌋
 *   = d * k * (k + 1) / 2 for k = ⌊n / d⌋ .
 * We then use the inclusion-exclusion principle to get the result from these
 * sums for d = 3, 5, 7, 15, 21, 35, 105. */

int sumOfMults(int n, int d);

int sumOfMultiples(int n)
{
	return sumOfMults(n, 3) + sumOfMults(n, 5) + sumOfMults(n, 7) -
	       sumOfMults(n, 15) - sumOfMults(n, 21) - sumOfMults(n, 35) +
	       sumOfMults(n, 105);
}

int sumOfMults(int n, int d)
{
	int k = n / d;
	return d * k * (k + 1) / 2;
}
