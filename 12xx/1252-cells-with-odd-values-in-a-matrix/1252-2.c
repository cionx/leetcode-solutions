/* 1252. Cells with Odd Values in a Matrix */

/* Complexities.
 * Time: Θ(m + n + i)
 * Space: Θ(m + n)
 * where the matrix in question is of size m × n, and i is the number of
 * indices. */

/* Idea.
 * Incrementing a row/column flips the parity of all its entries. An entry is
 * odd if and only if its row and column have together been flipped an odd
 * number of times. This means that either
 * - its row has been flipped an even number of times and its column an odd
 *   number of times, or
 * - its row has been flipped an odd number of times and its column an even
 *   number of times.
 * Let f_R and f_C be the number of rows/columns that have been flipped an odd
 * number of times. By the above consideration, the number of odd entries is
 * given by
 *
 *   (m - f_R) * f_C  +  f_R * (n - f_C) .
 *
 *      first case         second case
 *
 * It hence suffices to determine the two numbers f_R and f_C. */

#include <stdlib.h>

int oddCells(int m, int n, int **indices, int indicesSize, int *indicesColSize)
{
	int *rowFlips = calloc((size_t) m, sizeof(int));
	int *columnFlips = calloc((size_t) n, sizeof(int));

	/* We determine how many times each row/column has been flipped. */
	for (int i = 0; i < indicesSize; ++i) {
		++rowFlips[indices[i][0]];
		++columnFlips[indices[i][1]];
	}

	/* Now we count how many rows/columns have been flipped an odd number of
	 * times. */
	int fRows, fColumns;
	fRows = fColumns = 0;
	for (int i = 0; i < m; ++i)
		fRows += rowFlips[i] % 2;
	for (int j = 0; j < n; ++j)
		fColumns += columnFlips[j] % 2;

	free(rowFlips);
	free(columnFlips);
	return (m - fRows) * fColumns + fRows * (n - fColumns);
}
