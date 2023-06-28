/* 54. Spiral Matrix */

/* Complexities
 * Time: O(m n)
 * Space: O(1)
 * where m × n is the size of the input matrix. */

/* The general pattern is as follows:
 *  1. n     right
 *  2. m     down
 *  3. n - 1 left
 *  4. m - 1 up
 *  5. n - 2 right
 *  6. m - 2 down
 *  7. n - 3 left
 *  8. m - 3 down
 *  ⋮
 * We see that we alternate between two lengths, which are slowly decremented.
 * The direction in which we move changes as follows:
 *  (0, 1)
 *  (1, 0)
 *  (0, -1)
 *  (-1, 0)
 *  ⋮
 *  repeat
 *  ⋮
 *  That is, (di, dj) becomes (dj, -di). */

#include <stdlib.h>

int *spiralOrder(int **mat, int matSize, int *matColSize, int *returnSize)
{
	int m = matSize;       /* Height. */
	int n = matColSize[0]; /* Width. */

	int *result = malloc((size_t) m * (size_t) n * sizeof(int));
	*returnSize = m * n;

	int i = 0, j = -1;  /* Current position in the matrix. */
	int k = 0;          /* Current position in the result array. */
	int currLength = n; /* We start with the horizontal length. */
	int otherLength = m - 1;
	int di = 0;         /* Current i-direction, i.e., vertical change. */
	int dj = 1;         /* Current j-direction. i.e., horizontal change. */

	while (currLength > 0) {
		for (int remaining = currLength; remaining > 0; --remaining) {
			i += di, j += dj; /* Note that we *must* start a movement. */
			result[k++] = mat[i][j];
		}
		int tmp = dj; /* We use the      */
		dj = -di;     /* rotation [0 -1] */
		di = tmp;     /* matrix   [1  0] */

		tmp = otherLength;
		otherLength = --currLength;
		currLength = tmp;
	}

	return result;
}
