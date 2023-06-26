/* 120. Triangle */

/* Not-in-place solution. */

/* Complexities.
 * Time: O(n^2)
 * Space: O(n)
 * where n is the height/width of the triangle. */

#include <stdlib.h>
#include <string.h>

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize);
int min(int a, int b);

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
	/* cache starts off as a copy of the last row */
	const size_t size = (size_t) triangleSize * sizeof(int);
	int *cache = malloc(size);
	memcpy(cache, triangle[triangleSize - 1], size);

	for (int row = triangleSize - 2; row >= 0; --row)
		for (int column = 0; column <= row; ++column)
			cache[column] =
				triangle[row][column] + min(cache[column], cache[column + 1]);

	const int result = cache[0];
	free(cache);
	return result;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}
