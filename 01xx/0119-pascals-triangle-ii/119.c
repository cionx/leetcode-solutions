/* 119. Pascal’s Triangle II */

/* Complexities.
 * Time: O(n^2)
 * Space: O(1)
 * where n is the row index. */

#include <stdlib.h>

int *getRow(int rowIndex, int *returnSize)
{
	int *result = malloc(((size_t) rowIndex + 1) * sizeof(int));

	result[0] = 1;
	for (int row = 1; row <= rowIndex; ++row) {
		result[row] = 1;
		for (int column = row - 1; column > 0; --column)
			result[column] += result[column - 1];
	}

	*returnSize = rowIndex + 1;
	return result;
}
