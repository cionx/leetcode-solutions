/* 2373. Largest Local Values in a Matrix */

/* Complexities.
 * Time: Θ(n^2)
 * Space: Θ(1)
 * where n × n is the size of the input matrix. */

#include <limits.h>
#include <stdlib.h>

int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize,
                   int **returnColumnSizes);
int **generateMatrix(int m, int n);
int localMaximum(int **grid, int row, int column);

int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize,
                   int **returnColumnSizes)
{
	int n = gridSize;
	int m = n - 2;

	*returnSize = m;
	int *rCS = malloc((size_t) m * sizeof(int));
	for (int i = 0; i < m; ++i)
		rCS[i] = m;
	*returnColumnSizes = rCS;

	int **result = generateMatrix(m, m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			result[i][j] = localMaximum(grid, i + 1, j + 1);

	return result;
}

int **generateMatrix(int m, int n)
{
	int **result = malloc((size_t) m * sizeof(int *));
	for (int i = 0; i < m; ++i)
		result[i] = malloc((size_t) n * sizeof(int));
	return result;
}

int localMaximum(int **grid, int row, int column)
{
	int max = INT_MIN;
	for (int i = row - 1; i <= row + 1; ++i)
		for (int j = column - 1; j <= column + 1; ++j)
			if (grid[i][j] > max)
				max = grid[i][j];
	return max;
}
