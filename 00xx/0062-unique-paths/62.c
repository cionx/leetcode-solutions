/* 62. Unique Paths */

/* Complexities.
 * Time: Θ(1 + min(m - 1, n - 1))
 * Space: Θ(1)
 * where m × n is the size of the input grid. */

/* Idea.
 * We need to make a total of (m - 1) horizontal moves and (n - 1) vertical
 * moves. That gives a total of (m + n - 2) moves. In other words, we have
 * (m + n - 2) moves, and for each unique path, we need to decide which of those
 * moves are supposed to be horizontal, and which one vertical. We have a total
 * of
 *   Binom(m + n - 2, m - 1) = Binom(m + n - 2, n - 1)
 * such choices. */

int uniquePaths(int m, int n);
long long binomial(int n, int k);

int uniquePaths(int m, int n)
{
	return (int) binomial(m + n - 2, m - 1);
}

/* binomial(n, k): computes the binomial coefficient of choosing k out of n.
 * Takes Θ(min(k, n - k)) time and Θ(1) space. */
long long binomial(int n, int k)
{
	if (k < 0 || k > n)
		return 0;
	if (n - k < k)
		return binomial(n, n - k);

	/* We use the recursion relation
	 *   Binom(n, 0) = 1 ,
	 *   Binom(n, k) = Binom(n, k - 1) * (n - k + 1) / k .  */
	long long bin = 1;
	for (int l = 1; l <= k; ++l)
		bin = bin * (n - l + 1) / l;
	return bin;
}
