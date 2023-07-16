/* 48. Rotate Image */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n × n is the size of the input matrix. */

/* Idea.
 * We imagine the image being situated in ℝ^2 as follows:
 *
 *        ^
 *    a b | c d
 *    e f | g h
 *   -----+---->
 *    i j | k l
 *    m n | o p
 *        |
 *
 * To rotate the image, we want to rotate ℝ^2 clockwise by 90°. We recall from
 * linear algebra that the composition of two reflections is a rotation. More
 * precisely,
 *   s(β) s(α) = r(2(β - α)) = r(2β - 2α).
 * (To see that the angles are correct, take a point on the fixed line of s(α),
 * and observe that it gets rotated by an angle of 2(β - α).) In our case, we
 * need the rotation r(-90°), or equivalently r(270°). We can easily implement
 * matrix transposition, which is given by s(135°). We therefore want to choose
 * β = 135° and α = 0°. The effect of s(0°) on the matrix is given by reversing
 * the rows, which is also easy to implement. */

void rotate(int **matrix, int matrixSize, int *matrixColSize);
void reverseRows(int **matrix, int rowNumber);
void transpose(int **matrix, int matrixSize);

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
	reverseRows(matrix, matrixSize);
	transpose(matrix, matrixSize);
}

void reverseRows(int **matrix, int rowNumber)
{
	for (int i = 0, j = rowNumber - 1; i < j; ++i, --j) {
		int *tmp = matrix[i];
		matrix[i] = matrix[j];
		matrix[j] = tmp;
	}
}

void transpose(int **matrix, int matrixSize)
{
	for (int i = 0; i < matrixSize; ++i)
		for (int j = 0; j < i; ++j) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
}
