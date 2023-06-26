/* 2413. Smallest Even Multiple */

/* Complexities.
 * Time: O(1)
 * Space: O(1)
 */

int smallestEvenMultiple(int n)
{
	return (n % 2) ? 2 * n : n;
}
