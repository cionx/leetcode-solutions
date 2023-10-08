/* 566. Reshape the Matrix */

/* Complexities.
 * Time: Θ(m n)
 * Space: Θ(1)
 * where m × n is the size of the input matrix. */

/* Idea.
 * We are trying to reshape a (p × q)-matrix into an (r × s)-matrix. The basic
 * idea is to first “serialize” the (p × q)-matrix into a (1 × n)-matrix, which
 * we then “de-serialize” into the desired (r × s)-matrix.
 *
 * To this end we assign to the (i, j)-th entry in the original (p × q)-matrix
 * the “serialized index”
 *
 *   σ = i * q + j .
 *
 * The corresponding indices (k, l) in the (r × s)-matrix must also satisfy
 *
 *   σ = k * s + l .
 *
 * We have k < r and l < s, so we can retrieve k and l from σ via
 *
 *   k = σ / s ,
 *   l = σ % s .
 */

#include <stdlib.h>

int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int s,
                    int *returnSize, int **returnColumnSizes);
void setReturnSizes(int *returnSize, int **returnColumnSizes, int m, int n);
int **createMatrix(int m, int n);

int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int s,
                    int *returnSize, int **returnColumnSizes)
{
	int p = matSize;
	int q = matColSize[0];

	/* If the resize is illegal, return the original matrix. */
	if (p * q != r * s) {
		setReturnSizes(returnSize, returnColumnSizes, p, q);
		return mat;
	}

	setReturnSizes(returnSize, returnColumnSizes, r, s);
	int **result = createMatrix(r, s);
	for (int i = 0; i < p; ++i)
		for (int j = 0; j < q; ++j) {
			int serialIndex = i * q + j;
			int k = serialIndex / s;
			int l = serialIndex % s;
			result[k][l] = mat[i][j];
		}

	return result;
}

void setReturnSizes(int *returnSize, int **returnColumnSizes, int m, int n)
{
	*returnSize = m;
	int *rCS = malloc((size_t) m * sizeof(int));
	for (int i = 0; i < m; ++i)
		rCS[i] = n;
	*returnColumnSizes = rCS;
}

/* Create an (m × n)-matrix. */
int **createMatrix(int m, int n)
{
	int **result = malloc((size_t) m * sizeof(int *));
	for (int i = 0; i < m; ++i)
		result[i] = malloc((size_t) n * sizeof(int));
	return result;
}
