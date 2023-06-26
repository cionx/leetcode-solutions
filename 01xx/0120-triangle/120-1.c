/* 120. Triangle */

/* In-place solution. */

/* Complexities.
 * Time: O(n^2)
 * Space: O(1)
 * where n is the height/width of the triangle. */

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize);
int min(int a, int b);

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
	for (int row = triangleSize - 2; row >= 0; --row)
		for (int column = 0; column <= row; ++column)
			triangle[row][column] +=
				min(triangle[row + 1][column], triangle[row + 1][column + 1]);
	return triangle[0][0];
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}
