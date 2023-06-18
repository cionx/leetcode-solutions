/* Time: O(m n)
 * Space: O(m n)
 */
#include <stdlib.h>

#define MODULO 1##000##000##007 /* 10^9 + 7 */
/* long is guaranted to have 32 bits, giving a maximal value of
 * 2,147,483,647 ≈ 2.1e9. This means that we can add two long values smaller
 * than MODULO without an overflow.
 */

long countPaths(int **grid, int gridSize, int *gridColSize);
long pathNumber(int i, int j, int m, int n, int **grid, long *cache);

long countPaths(int **grid, int gridSize, int *gridColSize)
{
	const int m = gridSize;
	const int n = gridColSize[0];

	long *cache = calloc((size_t) (m * n), sizeof(long));

	long sum = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			sum += pathNumber(i, j, m, n, grid, cache);
			sum %= MODULO;
		}

	free(cache);
	return sum;
}

long pathNumber(int i, int j, int m, int n, int **grid, long *cache)
{
	const int index = i * n + j;
	if (cache[index] != 0)
		return cache[index];

	long result = 1;
	/* above */
	if (i > 0 && grid[i][j] < grid[i - 1][j]) {
		result += pathNumber(i - 1, j, m, n, grid, cache);
		result %= MODULO;
	}
	/* below */
	if (i + 1 < m && grid[i][j] < grid[i + 1][j]) {
		result += pathNumber(i + 1, j, m, n, grid, cache);
		result %= MODULO;
	}
	/* left */
	if (j > 0 && grid[i][j] < grid[i][j - 1]) {
		result += pathNumber(i, j - 1, m, n, grid, cache);
		result %= MODULO;
	}
	/* right */
	if (j + 1 < n && grid[i][j] < grid[i][j + 1]) {
		result += pathNumber(i, j + 1, m, n, grid, cache);
		result %= MODULO;
	}

	cache[index] = result;

	return result;
}
