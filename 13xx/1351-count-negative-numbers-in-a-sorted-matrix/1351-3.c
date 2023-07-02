/* 1351. Count Negative Numbers in a Sorted Matrix */

/* Complexities.
 * Time: O(m + n)
 * Space: O(1)
 * where m × n is the size of the input matrix. */

int countNegatives(int **grid, int gridSize, int *gridColSize)
{
	int m = gridSize;
	int n = gridColSize[0];

	int counter = 0; /* maximal value is 10,000, so an int is enough */

	for (int i = 0, j = n - 1; i < m; ++i) {
		while (j >= 0 && grid[i][j] < 0)
			--j;
		counter += n - 1 - j;
	}

	return counter;
}
