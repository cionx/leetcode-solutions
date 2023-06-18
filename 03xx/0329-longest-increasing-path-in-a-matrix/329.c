/* Time: O(m n )
 * Space: O(m n)
 *
 * Note: LeetCode assumes that int has at least 32 bits, but the C standard only
 * guarantees 16 bits.
 */

#include <stdlib.h>

int longestIncreasingPath(int **grid, int gridSize, int *gridColSize);
int startAt(int i, int j, int m, int n, int **grid, int *cache);
int max(int a, int b);

int longestIncreasingPath(int **grid, int gridSize, int *gridColSize)
{
	const int m = gridSize;
	const int n = gridColSize[0]; /* m is required to be at least 1 */

	int *cache = calloc((size_t) (m * n), sizeof(int));
	int result = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			result = max(result, startAt(i, j, m, n, grid, cache));

	free(cache);
	return result;
}

int startAt(int i, int j, int m, int n, int **grid, int *cache)
{
	const int index = i * n + j;
	if (cache[index] != 0)
		return cache[index];

	int result = 0;
	if (i > 0 && grid[i - 1][j] > grid[i][j])
		result = max(result, startAt(i - 1, j, m, n, grid, cache));
	if (i + 1 < m && grid[i + 1][j] > grid[i][j])
		result = max(result, startAt(i + 1, j, m, n, grid, cache));
	if (j > 0 && grid[i][j - 1] > grid[i][j])
		result = max(result, startAt(i, j - 1, m, n, grid, cache));
	if (j + 1 < n && grid[i][j + 1] > grid[i][j])
		result = max(result, startAt(i, j + 1, m, n, grid, cache));
	++result;

	cache[index] = result;
	return result;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
