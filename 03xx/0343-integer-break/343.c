/* 343. Integer Break */

/* Complexities.
 * Time: Θ(log(n))
 * Space: Θ(1)
 * where n is the input integer. */

/* Idea.
 * We study natural number decompositions
 *
 *   n = n1 + ... + nr ,
 *
 * trying to maximize the product
 *
 *   p = n1 × ... × nr .
 *
 * We refer to the summands of such a decomposition as “components”. We make
 * the following observation regarding these components:
 *
 * - A component of 1 never helps in increasing p, while always decreasing the
 *   other components to choose from. We therefore avoid 1 as a component,
 *   unless forced to. More explicitly, we choose 1 as a component only for the
 *   small cases n = 2, 3.
 *
 * - It is always better to further break down a component k with k ≥ 4 since,
 *   for example,
 *
 *     2 × (k - 2) ≥ k .
 *
 * Together, this means that for n ≥ 4 we only use 2 and 3 as components! There
 * are still multiple ways of doing so, but we have one more observation:
 *
 * - It is always better to use two 3s instead of three 2s, since
 *
 *     3 × 3 = 9 > 8 = 2 × 2 × 2 .
 *
 * The idea is therefore to choose as many components as possible as 3, and as
 * few as possible as 2. More explicitly:
 *
 * - If n ≡ 0 modulo 3, then all components will be chosen as 3.
 *
 * - If n ≡ 2 modulo 3, then one component will be chosen as 2, and all other
 *   components as 3.
 *
 * - If n ≡ 1 modulo 3, then two components will be chosen as 2, and all other
 *   components as 3.
 *
 * This case distinction does not apply to the small cases n = 2, 3, which we
 * will have to handle by hand.
 */

int power(int x, int n);
int integerBreak(int n);

int integerBreak(int n)
{
	/* 2 = 1 + 1 */
	if (n == 2)
		return 1;

	/* 3 = 2 + 1 */
	if (n == 3)
		return 2;

	int threes, twos;

	if (n % 3 == 0) {
		threes = n / 3;
		twos = 0;
	}
	else if (n % 3 == 2) {
		threes = (n - 2) / 3;
		twos = 1;
	}
	else { /* n % 3 == 1 */
		threes = (n - 4) / 3;
		twos = 2;
	}

	return power(2, twos) * power(3, threes);
	/* We could precompute the first factor in each of three cases. We chose our
	 * code for readability and consistency. */
}

int power(int x, int n)
{
	/* Always x**n = (base ** exponent) * factor. */
	int base = x;
	int exponent = n;
	int factor = 1;

	while (exponent > 0) {
		if (exponent % 2 == 0) {
			base = base * base;
			exponent /= 2;
		}
		else {
			factor *= base;
			--exponent;
		}
	}
	return factor;
}
