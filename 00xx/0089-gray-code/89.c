/* 89. Gray Code */

/* Complexities.
 * Time: Θ(2^n)
 * Space: Θ(1)
 * where n is the input number. */

/* Idea.
 * We need to arrange all binary sequences of length n in a directed cycle, such
 * that each binary sequence differs from its neighbours in exactly one place.
 * For n = 2, the only solution up to orientation is as follows:
 *
 *    00---->----01
 *    |           |
 *    |           |
 *    ∧           ∨
 *    |           |
 *    |           |
 *    10----<----11
 *
 * We want to construct a solution for n = 3 by induction. We can start by
 * taking the solution for n = 2 and prepending 0, or 1. This gives us all
 * binary sequences of length 3, arranged in two disjoint, directed cycles:
 *
 *    000---->----001     100---->----101
 *     |           |       |           |
 *     |           |       |           |
 *     ∧           ∨       ∧           ∨
 *     |           |       |           |
 *     |           |       |           |
 *    010----<----011     110----<----111
 *
 * We want to somehow connect these two cycles into one:
 *
 *    *-----------*       *-----------*
 *    |           |       |           |
 *    |           +-------+           |
 *    |                               |
 *    |           +-------+           |
 *    |           |       |           |
 *    *-----------*       *-----------*
 *
 * For this purpose, we need to connect two nodes from the first cycles with two
 * nodes with the second cycles. But for every node in the first cycle, there
 * exists only one node in the second cycle that it could possibly connect to:
 * the sequence that differs only in first digit. It makes therefore more sense
 * to situate the two cycles as follows:
 *
 *    100---------------101
 *     |                 |
 *     |                 |
 *     |   000-----001   |
 *     |    |       |    |
 *     |    |       |    |
 *     |    |       |    |
 *     |   010-----011   |
 *     |                 |
 *     |                 |
 *    110---------------111
 *
 * The idea now is to simply connect the outer cycle with the inner cycle at two
 * adjacent spots. We choose the connecting spots so that we first go through
 * the cycle with leading 0s, and the the cycles with leading 1s.
 *
 *     100-------------101
 *      \               |
 *       \              |
 *        000-----001   |
 *                 |    |
 *                 |    |
 *                 |    |
 *        010-----011   |
 *       /              |
 *      /               |
 *     110-------------111
 *
 * However, we need to be careful with the orientation of the outer and inner
 * cycle. The situation currently looks as follows:
 *
 *     100------>------101
 *      \               |
 *       \              |
 *        000-->--001   |
 *                 |    |
 *                 ∨    ∨
 *                 |    |
 *        010--<--011   |
 *       /              |
 *      /               |
 *     110------<------111
 *
 * The orientations of the outer and inner part are not compatible! To fix this
 * issue, we simply reverse the orientation of the outer part:
 *
 *     100------<------101
 *      \               |
 *       \              |
 *        000-->--001   |
 *                 |    |
 *                 ∨    ∧
 *                 |    |
 *        010--<--011   |
 *       /              |
 *      /               |
 *     110------>------111
 *
 * This procedure is relatively simply to implement:
 *
 *    Take the solution for n = 2:
 *    [00, 01, 11, 10]
 *
 *    Add 0 or 1 respectively:
 *    [000, 001, 011, 010]   [000, 001, 011, 010]
 *
 *    Reverse the second array:
 *    [000, 001, 011, 010]   [010, 011, 001, 000]
 *
 *    Concatenate both arrays:
 *    [000, 001, 011, 010, 010, 011, 001, 000]
 *
 * Since we are representing binary sequences as numbers, this process becomes
 * even simpler: adding a leading 0 to the binary representation of a number
 * does not change the number in question. The solution for n = 3 is therefore
 * an extension of the solution for n = 2:
 *
 *    Take the solution for n = 2:
 *    [0, 1, 3, 2]
 *
 *    Create a copy of this array:
 *    [0, 1, 3, 2]   [0, 1, 3, 2]
 *
 *    Add 2^2 = 4 to each value in the copied array.
 *    [0, 1, 3, 2]   [4, 5, 7, 6]
 *
 *    Reverse the second array:
 *    [0, 1, 3, 2]   [6, 7, 5, 4]
 *
 *    Concatenate both arrays:
 *    [0, 1, 3, 2, 6, 7, 5, 4]
 *
 * The same procedure works for every induction step. For example, going from
 * n = 3 to n = 4 looks as follows:
 *
 *    1000------<-------1001------<------1011
 *      \                                  |
 *       \                                 |
 *        \                                |
 *         +---0000-->--0001-->--0011      ∧
 *                                 |       |
 *                                 ∨       |
 *                                 |       |
 *    1100--<--0100              0010    1010
 *     |        |                  |       |
 *     |        ∧                  ∨       |
 *     |        |                  |       |
 *     ∨       0101--<--0111--<--0110      ∧
 *     |                                   |
 *     |                                   |
 *     |                                   |
 *    1101------->------1111------>------1110
 *
 *    [0, 1, 3, 2, 6, 7, 5, 4]
 *    [0, 1, 3, 2, 6, 7, 5, 4]   [0, 1, 3, 2, 6, 7, 5, 4]
 *    [0, 1, 3, 2, 6, 7, 5, 4]   [8, 9, 11, 10, 14, 15, 13, 12]
 *    [0, 1, 3, 2, 6, 7, 5, 4]   [12, 13, 15, 14, 10, 11, 9, 8]
 *    [0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8]
 */

#include <stdlib.h>

int *grayCode(int n, int *returnSize)
{
	*returnSize = 1 << n;
	int *result = malloc((size_t) *returnSize * sizeof(int));

	/* The base case of n = 0 by hand. */
	result[0] = 0;

	/* The general case via repeated induction. */
	for (int k = 1; k <= n; ++k) {
		int inc = 1 << (k - 1);
		for (int from = 0, to = (1 << k) - 1; from < to; ++from, --to)
			result[to] = result[from] + inc;
			/* We could also use result[from] | inc. */
	}

	return result;
}
