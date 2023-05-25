#include <stdio.h>
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

int main(void)
{
	int row1[] = {1, 2, 3, 4, 5};
	int row2[] = {6, 7, 8, 9, 10};
	int row3[] = {11, 12, 13, 14, 15};
	int row4[] = {16, 17, 18, 19, 20};
	int row5[] = {21, 22, 23, 24, 25};

	int *(matrix)[] = {row1, row2, row3, row4, row5};
	int matrixSize = 5;
	int matrixColSize[] = {5, 5, 5, 5, 5};

	int *returnSize = malloc(sizeof(int));
	*returnSize = 0;
	int *result = spiralOrder(matrix, matrixSize, matrixColSize, returnSize);

	for (int l = 0; l < *returnSize; ++l)
		printf("%d ", result[l]);
	printf("\n");

	/* How do I free matrix? */
	free(returnSize);
	free(result);
	return 0;
}
