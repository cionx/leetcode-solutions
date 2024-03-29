/* 1351. Count Negative Numbers in a Sorted Matrix */

/* Complexities.
 * Time: O(m n)
 * Space: O(1)
 * where m × n is the size of the input matrix. */

int countNegatives(int **grid, int gridSize, int *gridColSize)
{
	int m = gridSize;
	int n = gridColSize[0];

	int counter = 0; /* maximal value is 10,000, so an int is enough */

	for (int i = 0; i < m && n > 0; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] < 0) {
				counter += (m - i) * (n - j);
				n = j;
			}
		}
	}

	return counter;
}
