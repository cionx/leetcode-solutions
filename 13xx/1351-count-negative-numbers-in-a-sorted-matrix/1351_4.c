int countNegatives(int **grid, int gridSize, int *gridColSize);

/* We are going to use two auxiliary functions, which respectively determine the
 * number of negative and non-negative entries in a gives submatrix. We will
 * refer to non-negative as “positive” for readability. Both functions take as
 * their arguments the grid, as well as the minimal and maximal row and column
 * indices of the submatrix. The minimal value will be inclusive, the maximal
 * value exclusive.
 * Both functions will recursively call one another.
 */
int negativeCount(int **grid, int rowMin, int rowLim, int colMin, int colLim);
int positiveCount(int **grid, int rowMin, int rowLim, int colMin, int colLim);

/* We will also need to auxiliary functions to determine the first index in a
 * specified row or specified column that holds a negative value.
 */
int firstNegativeInRow(int **grid, int row, int colMin, int colLim);
int firstNegativeInColumn(int **grid, int col, int rowMin, int rowLim);

int countNegatives(int **grid, int gridSize, int *gridColSize)
{
	int m = gridSize;
	int n = gridColSize[0];

	return negativeCount(grid, 0, m, 0, n);
}

int negativeCount(int **grid, int rowMin, int rowLim, int colMin, int colLim)
{
	if (rowLim <= rowMin || colLim <= colMin)
		return 0;

	/* We determine the smallest block in the bottom-right corner of the
	 * specified submatrix that contains all negative entries. */
	int i = firstNegativeInColumn(grid, colLim - 1, rowMin, rowLim);
	int j = firstNegativeInRow(grid, rowLim - 1, colMin, colLim);

	return (rowLim - i) * (colLim - j) -
	       positiveCount(grid, i, rowLim, j, colLim);
}

int positiveCount(int **grid, int rowMin, int rowLim, int colMin, int colLim)
{
	if (rowLim <= rowMin || colLim <= colMin)
		return 0;

	/* We determine the smallest block in the top-left corner of the specified
	 * submatrix that contains all positive entries. */
	int i = firstNegativeInColumn(grid, colMin, 0, rowLim);
	int j = firstNegativeInRow(grid, rowMin, 0, colLim);

	return (i - rowMin) * (j - colMin) -
	       negativeCount(grid, rowMin, i, colMin, j);
}

int firstNegativeInRow(int **grid, int row, int colMin, int colLim)
{
	int lower, upper, middle;

	for (lower = colMin, upper = colLim, middle = (lower + upper) / 2;
	     lower < upper; middle = (lower + upper) / 2) {
		if (grid[row][middle] >= 0)
			lower = middle + 1;
		else
			upper = middle;
	}

	return lower;
}

int firstNegativeInColumn(int **grid, int col, int rowMin, int rowLim)
{
	int lower, upper, middle;

	for (lower = rowMin, upper = rowLim, middle = (lower + upper) / 2;
	     lower < upper; middle = (lower + upper) / 2) {
		if (grid[middle][col] >= 0)
			lower = middle + 1;
		else
			upper = middle;
	}

	return lower;
}
