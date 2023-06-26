/* 118. Pascal’s Triangle */

/* Complexities.
 * Time: O(n^2)
 * Space: O(1)
 * where n is the input array. */

#include <stdlib.h>

int **generate(int n, int *returnSize, int **returnColumnSizes)
{
	*returnSize = n;
	*returnColumnSizes = malloc((size_t) n * sizeof(int));
	for (int i = 0; i < n; ++i)
		(*returnColumnSizes)[i] = i + 1;

	int **result = malloc((size_t) n * sizeof(int *));
	for (int row = 1; row <= n; ++row) {
		const int rowIndex = row - 1;
		result[rowIndex] = malloc((size_t) row * sizeof(int));
		result[rowIndex][0] = result[rowIndex][row - 1] = 1;
		for (int i = 1; i < row - 1; ++i)
			result[rowIndex][i] =
				result[rowIndex - 1][i] + result[rowIndex - 1][i - 1];
	}

	return result;
}
