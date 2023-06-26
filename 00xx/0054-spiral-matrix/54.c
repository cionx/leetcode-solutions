/* 54. Spiral Matrix */

/* Complexities
 * Time: O(m n)
 * Space: O(1)
 * where the input matrix of of size m × n. */

#include <stdlib.h>

/* The general pattern is as follows:
 *          n     right   ->   m     down
 *     ->   n - 1 left    ->   m - 1 up
 *     ->   n - 2 right   ->   m - 2 down
 *     ->   n - 3 left    ->   m - 3 down
 *     ->   ...
 */

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
                 int *returnSize);

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
                 int *returnSize)
{
	int m = matrixSize;
	int n = matrixColSize[0];

	int k = 0;
	int *result = malloc((size_t) (m * n) * sizeof(int));

	int i = 0, j = -1;
	int currentLength = n;
	int otherLength = m - 1;
	int iDirection = 0;
	int jDirection = 1;

	while (currentLength > 0) {
		for (int dummy = 0; dummy < currentLength; ++dummy) {
			i += iDirection;
			j += jDirection;
			result[k++] = matrix[i][j];
		}
		int tmp = jDirection;
		jDirection = -iDirection; /* rotation matrix */
		iDirection = tmp;

		tmp = otherLength;
		otherLength = --currentLength;
		currentLength = tmp;
	}

	*returnSize = m * n;
	return result;
}
