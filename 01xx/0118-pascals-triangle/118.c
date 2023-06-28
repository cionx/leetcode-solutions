/* 118. Pascal’s Triangle */

/* Complexities.
 * Time: O(n^2)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdlib.h>

int **generate(int n, int *returnSize, int **returnColSizes)
{
	*returnColSizes = malloc((size_t) n * sizeof(int));
	*returnSize = n;

	int **result = malloc((size_t) n * sizeof(int *));
	for (int rowSize = 1; rowSize <= n; ++rowSize) {
		const int rowIndex = rowSize - 1;
		(*returnColSizes)[rowIndex] = rowSize;
		result[rowIndex] = malloc((size_t) rowSize * sizeof(int));
		result[rowIndex][0] = result[rowIndex][rowSize - 1] = 1;
		for (int i = 1; i < rowSize - 1; ++i)
			result[rowIndex][i] =
				result[rowIndex - 1][i] + result[rowIndex - 1][i - 1];
	}

	return result;
}
