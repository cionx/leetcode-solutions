/* 2652. Sum Multiples */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the input integer. */

int sumOfMultiples(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k)
		if (k % 3 == 0 || k % 5 == 0 || k % 7 == 0)
			sum += k;
	return sum;
}
