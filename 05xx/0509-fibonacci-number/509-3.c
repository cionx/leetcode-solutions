/* 509. Fibonacci Number */

/* Matrix solution. */

/* Complexity.
 * Time: O(log(n))
 * Space: O(1)
 * where n is the input number. */

/* Idea:
 * We have
 *  [0 1] ⋅ [a] = [b]
 *  [1 1]   [b]   [a + b] .
 * Therefore, by induction,
 *  [0 1]^n ⋅ [Fib(0)] = [Fib(n)    ]
 *  [1 1]     [Fib(1)]   [Fib(n + 1)] .
 * We can therefore calculate the Fibonacci numbers via matrix powers, which can
 * be computed in logarithmic time.
 *
 * The above matrix is symmetric, whence its powers are again symmetric. We will
 * represent the symmetric matrix
 *  [a b]
 *  [b c]
 * as the triple [a, b, c], and the column vector
 *  [x]
 *  [y]
 * as the tuple [x, y]. We then have the following two formulas:
 *  [a, b, c] ⋅ [x, y] = [a x + b y, b x + c y],
 *  [a, b, c]^2 = [a^2 + b^2, a b + b c, b^2 + c^2 ]. */

#include <stdlib.h>

int fib(int n);
void squareMatrix(int mat[3]);
void multMatrixVector(int mat[3], int vect[2]);

int fib(int n)
{
	if (n <= 1)
		return n;

	int mat[3] = {0, 1, 1};
	int vect[2] = {0, 1};
	/* We make the product  mat^n ⋅ vect  a loop invariant. */
	while (n > 0) {
		if (n % 2 == 0) {
			squareMatrix(mat);
			n /= 2;
		}
		else {
			multMatrixVector(mat, vect);
			--n;
		}
	}

	return vect[0];
}

void squareMatrix(int mat[3])
{
	const int a = mat[0];
	const int b = mat[1];
	const int c = mat[2];
	mat[0] = a * a + b * b;
	mat[1] = a * b + b * c;
	mat[2] = b * b + c * c;
}

void multMatrixVector(int mat[3], int vect[2])
{
	const int a = mat[0];
	const int b = mat[1];
	const int c = mat[2];
	const int x = vect[0];
	const int y = vect[1];
	vect[0] = a * x + b * y;
	vect[1] = b * x + c * y;
}
