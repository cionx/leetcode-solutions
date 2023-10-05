/* 1551. Minimum Operations to Make Array Equal */

/* Complexities.
 * Time: Θ(1)
 * Space: Θ(1)   */

/* Idea.
 * The average of the array doesn’t change throughout the operations, so all
 * entries must be made equal to this average. The average of the numbers
 *
 *    1, 3, 5, ..., 2n - 1
 *
 * is simply
 *
 *    ( 1 + (2n - 1) ) / 2 = n.
 *
 * We thus need to make all entries equal to n. To do this in the minimal amount
 * of operations means that we need to increase the numbers strictly smaller
 * than n, and decrease the numbers strictly larger than n. We can group
 * together these operations as in the following examples for n = 6 and n = 7:
 *
 *
 *    1     3     5     7     9     11
 *    |     |     |     |     |      |
 *    |     |     +- 1 -+     |      |              n = 6
 *    |     +------- 3 -------+      |
 *    +------------- 5 --------------+
 *
 *
 *    1     3     5     7     9     11    13
 *    |     |     |           |      |     |
 *    |     |     +---- 2 ----+      |     |        n = 7
 *    |     +---------- 4 -----------+     |
 *    +---------------- 6 -----------------+
 *
 *
 * We can see that if n is even, then the total number of operations is given by
 *
 *      1 + 3 + 5 + ... + (n - 1)
 *    = sum of 2k - 1 from k = 1 to k = n/2
 *    = (n/2)²
 *    = n² / 4 .
 *
 * Similarly, if n is odd, then the total number of operations is given by
 *
 *      2 + 4 + 6 + ... + (n - 1)
 *    = [1 + 3 + 5 + ... + (n - 2)] + (n - 1)/2
 *    = (n - 1)²/4 - (n - 1)/2
 *    = [ (n - 1)² - 2(n - 1) ] / 4
 *    = [ (n - 1)² - 2(n - 1) + 1 - 1 ] / 4
 *    = [ ((n - 1) + 1)^2 - 1 ] / 4
 *    = (n² - 1) / 4 .
 */

int minOperations(int n)
{
	if (n % 2 == 0)
		return n * n / 4; /* Fits into a 32-bit int. */
	else
		return (n * n - 1) / 4;
}
