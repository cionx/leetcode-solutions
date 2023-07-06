/* 1137. N-th Tribonacci Number */

/* Iterative solution with matrices. */

/* Complexities.
 * Time: Θ(log(n))
 * Space: Θ(1)
 * where n is the input number. */

/* Idea.
 * We have the formula
 *   [0 1 0] [Tri(n - 2)]       [Tri(n - 1)]
 *   [0 0 1] [Tri(n - 1)]   =   [Tri(n)    ]
 *   [1 1 1] [Tri(n)]           [Tri(n + 1)]
 * It follows that
 *   [0 1 0]^n [Tri(0)]         [Tri(n)    ]
 *   [0 0 1]   [Tri(1)]     =   [Tri(n + 1)]
 *   [1 1 1]   [Tri(2)]     =   [Tri(n + 2)]
 * We can therefore compute the Tribonacci numbers via fast matrix
 * exponentiation and matrix-vector multiplication.
 */

int tribonacci(int n);
void matrixSqr(int mat[9]);
void matrixVectorMult(int mat[9], long long vect[3]);

int tribonacci(int n)
{
	long long vect[3] = {0, 1, 1};
	int mat[9] = {0, 1, 0, 0, 0, 1, 1, 1, 1};

	while (n > 0)
		if (n % 2 == 0) {
			matrixSqr(mat);
			n /= 2;
		}
		else {
			matrixVectorMult(mat, vect);
			--n;
		}

	return (int) vect[0];
}

void matrixSqr(int mat[9])
{
	const int a = mat[0];
	const int b = mat[1];
	const int c = mat[2];
	const int d = mat[3];
	const int e = mat[4];
	const int f = mat[5];
	const int g = mat[6];
	const int h = mat[7];
	const int i = mat[8];
	mat[0] = a * a + b * d + c * g;
	mat[1] = a * b + b * e + c * h;
	mat[2] = a * c + b * f + c * i;
	mat[3] = a * d + d * e + f * g;
	mat[4] = b * d + e * e + f * h;
	mat[5] = c * d + f * e + f * i;
	mat[6] = a * g + d * h + g * i;
	mat[7] = b * g + h * e + h * i;
	mat[8] = c * g + f * h + i * i;
}

void matrixVectorMult(int mat[9], long long vect[3])
{
	const long long x = vect[0];
	const long long y = vect[1];
	const long long z = vect[2];
	vect[0] = mat[0] * x + mat[1] * y + mat[2] * z;
	vect[1] = mat[3] * x + mat[4] * y + mat[5] * z;
	vect[2] = mat[6] * x + mat[7] * y + mat[8] * z;
}
