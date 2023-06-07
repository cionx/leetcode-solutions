/* By turning our heads by 45 degrees, the n-th figure is a square with edge
 * length n. Going from the n-th square to the (n + 1)-th square adds four time
 * the edge length as new cells:
 *
 *           4
 *         1 E 4
 *       1 E * * 4
 *     1 E * * * * 4
 *   1 E * * * * * * 4
 * 1 E * * * * * * * * 3
 *   2 * * * * * * * 3
 *     2 * * * * * 3
 *       2 * * * 3
 *         2 * 3
 *           2
 *
 * The n-th figure has therefore a total of
 *     1 + 4*1 + 4*2 + 4*3 + ... + 4*(n-1)
 *   = 1 + sum(4 * k from k = 0 to k = (n - 1))
 *   = 1 + 4 * sum(k from k = 0 to k = (n - 1))
 *   = 1 + 4 * (n - 1) * n / 2
 *   = 1 + 2 * (n - 1) * n
 * cells.
 */

/* Alternatively, we can decompose the n-th figure into two actual squares:
 *
 *             X                             X
 *           X O X                         X   X                       O
 *         X O X O X                     X   X   X                   O   O
 *       X O X O X O X                 X   X   X   X               O   O   O
 *     X O X O X O X O X             X   X   X   X   X           O   O   O   O
 *   X O X O X O X O X O X   -->   X   X   X   X   X   X   +   O   O   O   O   O
 *     X O X O X O X O X             X   X   X   X   X           O   O   O   O
 *       X O X O X O X                 X   X   X   X               O   O   O
 *         X O X O X                     X   X   X                   O   O
 *           X O X                         X   X                       O
 *             X                             X
 *
 * We get a total of
 *   n^2 + (n - 1)^2
 *   = 2 * n^2 - 2 * n + 1
 *   = 1 + 2 * n * (n - 1)
 * cells.
 */

long long coloredCells(int n)
{
	long long N = (long long) n;

	return 1 + 2 * (N - 1) * N;
}
