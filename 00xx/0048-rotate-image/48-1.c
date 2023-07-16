/* 48. Rotate Image */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n × n is the size of the input matrix. */

/* Idea.
 * We partition the matrix into its outer layer and inner core:
 *   O O O O O O O
 *   O I I I I I O
 *   O I I I I I O
 *   O I I I I I O
 *   O I I I I I O
 *   O I I I I I O
 *   O O O O O O O
 * The outer layer is the disjoint union of groups of four fields:
 *   1 2 3 4 5 6 1
 *   6           2
 *   5           3
 *   4           4
 *   3           5
 *   2           6
 *   1 6 5 4 3 2 1
 * Inside these groups of fours, we have to cyclically permute the entries.
 * After having done so, we recursively proceed into the inner core.
 *
 * We parametrize the considered submatrices by their top-left corner entry and
 * their size:
 *   * . . . . . .   . . . . . . .   . . . . . . .   . . . . . . .
 *   . . . . . . .   . * . . . . .   . . . . . . .   . . . . . . .
 *   . . . . . . .   . . . . . . .   . . * . . . .   . . . . . . .
 *   . . . . . . .   . . . . . . .   . . . . . . .   . . . * . . .
 *   . . . . . . .   . . . . . . .   . . . . . . .   . . . . . . .
 *   . . . . . . .   . . . . . . .   . . . . . . .   . . . . . . .
 *   . . . . . . .   . . . . . . .   . . . . . . .   . . . . . . .
 *      size 7          size 5          size 3          size 1
 *
 * We parametrize each group of four by their top(-left) entry.
 *   A . . . . a   . A . . . .   . . A . . .   . . . A . .   . . . . A .
 *   .         .   .         a   .         .   .         .   a         .
 *   .         .   .         .   .         a   a         .   .         .
 *   .         .   .         .   a         .   .         a   .         .
 *   .         .   a         .   .         .   .         .   .         a
 *   a . . . . a   . . . . a .   . . . a . .   . . a . . .   . a . . . .
 */

void rotate(int **matrix, int matrixSize, int *matrixColSize);
void rotate4(int **matrix, int n, int k, int d);

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
	for (int n = matrixSize, k = 0; n > 1; n -= 2, ++k)
		for (int offset = 0; offset < n - 1; ++offset)
			rotate4(matrix, n, k, offset);
}

inline void rotate4(int **matrix, int n, int k, int offset)
{
	/* To get the coordinates right: if n == 2 and offset == 0, then the
	 * coordinates are
	 *   (k, k)    (k, k+1)
	 *   (k+1, k)  (k+1, k+1)
	 * So for arbitrary n and offset == 0 the coordinates are
	 *   (k, k)      (k, k+n-1)
	 *   (k+n-1, k)  (k+n-1, k+n-1).
	 * So for arbitrary n and offset the coordinates are
	 *   (k, k+offset)      (k+offset, k+n-1)
	 *   (k+n-1-offset, k)  (k+n-1, k+n-1-offset).
	 */
	/* Precompute the indices. */
	int i1 = k;
	int i2 = k + offset;
	int i3 = k + n - 1;
	int i4 = k + n - 1 - offset;
	/* Swap entries. */
	int tmp = matrix[i1][i2];
	matrix[i1][i2] = matrix[i4][i1];
	matrix[i4][i1] = matrix[i3][i4];
	matrix[i3][i4] = matrix[i2][i3];
	matrix[i2][i3] = tmp;
}
