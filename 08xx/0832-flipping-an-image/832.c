/* 832. Flipping an Image */

/* Complexities.
 * Time: Θ(m n)
 * Space: Θ(1)
 * where m × n is the size of the input image. */

#include <stdlib.h>

int **createMatrix(int rows, int cols);
int **flipAndInvertImage(int **image, int imageSize, int *imageColSize,
                         int *returnSize, int **returnColumnSizes);

int **flipAndInvertImage(int **image, int imageSize, int *imageColSize,
                         int *returnSize, int **returnColumnSizes)
{
	/* Figure out the image size. */
	int rows = imageSize;
	int cols = imageColSize[0];

	/* Set the return sizes. */
	*returnSize = rows;
	int *rCS = malloc((size_t) rows * sizeof(int));
	for (int i = 0; i < rows; ++i)
		rCS[i] = cols;
	*returnColumnSizes = rCS;

	int **result = createMatrix(rows, cols);
	for (int r = 0; r < rows; ++r)
		for (int c = 0; c < cols; ++c)
			result[r][c] = 1 - image[r][cols - c - 1];

	return result;
}

int **createMatrix(int rows, int cols)
{
	int **result = malloc((size_t) rows * sizeof(int *));
	for (int r = 0; r < rows; ++r)
		result[r] = malloc((size_t) cols * sizeof(int));
	return result;
}
