/* 2894. Divisible and Non-Divisible Sums Difference */

/* Complexities.
 * Time: Θ(1)
 * Space: Θ(1) */

int differenceOfSums(int n, int m);
int sumAll(int n);
int sumMultiples(int a, int n);

int differenceOfSums(int n, int m)
{
	int num2 = sumMultiples(m, n);
	int num1 = sumAll(n) - num2;

	return num1 - num2;
}

/* Sum of all integers in the inclusive range [1, n]. */
int sumAll(int n)
{
	return n * (n + 1) / 2;
}

/* Sum of all multiples of d in the inclusive range [1, n]. */
int sumMultiples(int d, int n)
{
	return d * sumAll(n / d);
}
