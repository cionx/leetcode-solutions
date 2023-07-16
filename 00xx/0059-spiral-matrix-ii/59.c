/* 59. Spiral Matrix II */

/* Complexities.
 * Time: Θ(n^2)
 * Space: Θ(1)
 * where n is the input integer. */

/* Idea.
 * We walk through the matrix in the specified spiral path, and add the entries
 * along the way. */

#include <stdlib.h>

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
	int **result = malloc((size_t) n * sizeof(int *));
	*returnSize = n;
	*returnColumnSizes = malloc((size_t) n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		result[i] = malloc((size_t) n * sizeof(int));
		(*returnColumnSizes)[i] = n;
	}

	/* The current position. */
	int i = 0;
	int j = -1;
	/* The next entry. */
	int entry = 1;
	/* The change in position, i.e., the direction. */
	int iDirection = 0;
	int jDirection = 1;
	/* How long to move in that direction. */
	int curLength = n;
	int nextLength = n - 1;
	/* Finally, the main loop. */
	while (curLength > 0) {
		/* Insert all entries for the current direction. */
		for (int _ = 0; _ < curLength; ++_)
			result[i += iDirection][j += jDirection] = entry++;
		/* Update movement direction. */
		int tmpDirection = iDirection;
		iDirection = jDirection;
		jDirection = -tmpDirection;
		/* Update lengths. */
		int tmpLength = curLength;
		curLength = nextLength;
		nextLength = tmpLength - 1;
	}

	return result;
}
