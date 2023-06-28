/* 498. Diagonal Traverse */

/* Complexities.
 * Time: O(m n)
 * Space: O(1)
 * where m × n is the size of the input matrix. */

#include <stdlib.h>

int *findDiagonalOrder(int **mat, int matSize, int *matColSize, int *returnSize)
{
	const int m = matSize;
	const int n = matColSize[0];
	const int min = (m < n) ? m : n;

	int *result = malloc((size_t) m * (size_t) n * sizeof(int));
	*returnSize = m * n;

	const int diagNumber = m + n - 1; /* Total number of diagonals. */
	int i = 0, j = 0;                 /* Current matrix position. */
	int k = 0;                        /* Current result position. */
	int di = -1, dj = 1;              /* Current direction. */
	/* Observation.
	 * The d-th diagonal (0-indexed) consists of all those fields (i, j) for
	 * which i + j = d: the first diagonal is (0,0), the second is (0,1) and
	 * (1,0), etc. */
	for (int d = 0; d < diagNumber; ++d) {
		/* Determine length of the current diagonal. This length starts off as
		 * 1, then increments until it reaches the minumum of m and n. It stays
		 * at this size for a while (if the matrix is not square). Finally, it
		 * decrements back to 1. */
		int length, remain;
		if (d + 1 < min)
			length = d + 1;
		else if ((remain = diagNumber - d) < min)
			length = remain;
		else
			length = min;
		/* Determine the starting position, using that the fields (i, j) on the
		 * d-th diagonal satisfy i + j = d. The even-numbered digonals want to
		 * start with j = 0, the odd-numbered with i = 0. However, once we have
		 * d >= min, these starting points lie outside the matrix. Intuitively
		 * speaking, we then move along the diagonal i + j = d until we are
		 * inside the matrix. */
		if (d % 2 == 0) {
			if (d < m)
				i = d, j = 0;
			else
				/* Otherwise we make i as large as possible, and j = d - i. */
				i = m - 1, j = d - m + 1;
		}
		else {
			if (d < n)
				i = 0, j = d;
			else
				i = d - n + 1, j = n - 1;
		}
		/* Go through the diagonal. */
		for (; length > 0; --length, ++k, i += di, j += dj)
			result[k] = mat[i][j];
		/* Flip direction for the next diagonal. We put this at the end of the
		 * loop, so that for the first diagonal the initial values are used. */
		di *= -1;
		dj *= -1;
	}

	return result;
}
