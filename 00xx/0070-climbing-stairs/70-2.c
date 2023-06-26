/* 70. Climbing Stairs */

/* Matrix solution. */

/* Complexities.
 * Time: O(log(n))
 * Spacce: O(1)
 * where n is the input number. */

/* Idea.
 * The given function c satisfies the recursive relation
 *   c(n) = c(n - 1) + c(n - 2),
 * as well as the base conditions c(1) = 1, c(2) = 2. The sequence c(1), c(2),
 * c(3), ... is therefore just a shifted version of the Fibonacci numbers. We
 * can therefore copy the matrix approach from Problem 509. */

int climbStairs(long long n);
void squareMatrix(long long mat[3]);
void multMatrixVector(long long mat[3], long long vect[2]);

int climbStairs(long long n)
{
	if (n <= 2)
		return n;

	long long mat[3] = {0, 1, 1};
	long long vect[2] = {1, 2};
	--n;
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

	return (int) vect[0];
}

void squareMatrix(long long mat[3])
{
	const long long a = mat[0];
	const long long b = mat[1];
	const long long c = mat[2];
	mat[0] = a * a + b * b;
	mat[1] = a * b + b * c;
	mat[2] = b * b + c * c;
}

void multMatrixVector(long long mat[3], long long vect[2])
{
	const long long a = mat[0];
	const long long b = mat[1];
	const long long c = mat[2];
	const long long x = vect[0];
	const long long y = vect[1];
	vect[0] = a * x + b * y;
	vect[1] = b * x + c * y;
}
