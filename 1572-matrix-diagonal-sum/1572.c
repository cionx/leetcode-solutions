int diagonalSum(int **matrix, int n, int *matColSize)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += matrix[i][i];
	for (int i = 0; i < n; ++i)
		sum += matrix[i][n - 1 - i];
	if (n % 2 == 1)
		sum -= matrix[n / 2][n / 2];

	return sum;
}
