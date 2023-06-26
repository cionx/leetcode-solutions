/* 2500. Delete Greatest Value in Each Row */

/* Complexities.
 * Time: O(m n log(n))
 * Space: O(m n)
 * where the input grid is of size m × n.
 */

/* Idea: we sort each row, and then sum up the maximum of each column. */

#include <stdlib.h>
#include <string.h>

int deleteGreatestValue(const int **grid, int gridSize, int *gridColSize);
int cmpInts(const void *a, const void *b);
int columnMax(int **grid, int m, int column);
int max(int a, int b);

int deleteGreatestValue(const int **grid, int gridSize, int *gridColSize)
{
	const int m = gridSize;
	const int n = gridColSize[0];

	int **sortedGrid = malloc((size_t) m * sizeof(int *));
	size_t rowBitSize = (size_t) n * sizeof(int);
	for (int i = 0; i < m; ++i) {
		sortedGrid[i] = malloc(rowBitSize);
		memcpy(sortedGrid[i], grid[i], rowBitSize);
		qsort(sortedGrid[i], (size_t) n, sizeof(int), cmpInts);
	}

	int sum = 0; /* Max value of 100 * 50 = 5,000. So no overflow */

	for (int j = 0; j < n; ++j)
		sum += columnMax(sortedGrid, m, j);

	for (int i = 0; i < m; ++i)
		free(sortedGrid[i]);
	free(sortedGrid);

	return sum;
}

int cmpInts(const void *a, const void *b)
{
	const int *A = (const int *) a;
	const int *B = (const int *) b;

	return (*A > *B) - (*A < *B);
}

int columnMax(int **grid, int m, int column)
{
	int best = grid[0][column];

	for (int i = 1; i < m; ++i)
		best = max(best, grid[i][column]);

	return best;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
