/* 746. Min Cost Climbing Stairs */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * We works our way backwards through the array, keeping track of the minimal
 * total cast that we get from either taking one step, or two steps. Each new
 * value is the minimum of the next two numbers plus the current cost:
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *                                          100    1
 *                                          one  two
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *                                       2  100    1
 *                                     one  two
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *                                  3    2  100    1
 *                                one  two
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *                           103    3    2  100    1
 *                           one  two
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *                        4  103    3    2  100    1
 *                      one  two
 *
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *                   5    4  103    3    2  100    1
 *                 one   two
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *              5    5    4  103    3    2  100    1
 *            one  two
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *       105    5    5    4  103    3    2  100    1
 *       one  two
 *
 * [  1, 100,   1,   1,   1, 100,   1,   1, 100,   1]
 *    6  105    5    5    4  103    3    2  100    1
 *  one  two
 *
 * One minimal path is:
 *    6  ---->  5  ---->  4  ---->  3 -> 2  ---->  1
 */

int minCostClimbingStairs(int *cost, int costSize);
int min(int a, int b);

int minCostClimbingStairs(int *cost, int costSize)
{
	int twoStep = cost[costSize - 1]; /* i = costSize - 1 */
	int oneStep = cost[costSize - 2]; /* i = costSize - 2 */
	for (int i = costSize - 3; i >= 0; --i) {
		int tmp = cost[i] + min(oneStep, twoStep);
		twoStep = oneStep;
		oneStep = tmp;
	}
	return min(oneStep, twoStep);
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}
