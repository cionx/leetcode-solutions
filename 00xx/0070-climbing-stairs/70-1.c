/* 70. Climbing Stairs */

/* Iterative solution. */

/* Complexities.
 * Time: O(n)
 * Spacce: O(1)
 * where n is the input number. */

/* Idea.
 * The given function c satisfies the recursive relation
 *   c(n) = c(n - 1) + c(n - 2),
 * as well as the base conditions c(1) = 1, c(2) = 2. The sequence c(1), c(2),
 * c(3), ... is therefore just a shifted version of the Fibonacci numbers. */

int climbStairs(int n)
{
	if (n <= 2)
		return n;

	int prev = 1, curr = 2;
	while (n-- > 2) {
		const int tmp = curr;
		curr += prev;
		prev = tmp;
	}

	return curr;
}
