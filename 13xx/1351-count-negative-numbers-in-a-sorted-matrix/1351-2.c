/* 1351. Count Negative Numbers in a Sorted Matrix */

/* Complexities:
 * Time: O(m log(n))
 * Space: O(1)
 * where m × n is the size of the input matrix. */

int countNegatives(int **grid, int gridSize, int *gridColSize);
int firstNegative(int **grid, int row, int n);

int countNegatives(int **grid, int gridSize, int *gridColSize)
{
	int m = gridSize;
	int n = gridColSize[0];

	int counter = 0; /* maximal value is 10,000, so an int is enough */

	for (int i = 0; i < m && n > 0; ++i) {
		int j = firstNegative(grid, i, n);
		counter += (m - i) * (n - j);
		n = j;
	}

	return counter;
}

int firstNegative(int **grid, int row, int n)
{
	int lower, upper, middle;
	for (lower = 0, upper = n, middle = n / 2; /* upper starts out of bounds */
	     lower < upper; middle = (lower + upper) / 2) {
		if (grid[row][middle] >= 0)
			lower = middle + 1;
		else
			upper = middle;
	}

	return lower;
}
