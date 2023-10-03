/* 1252. Cells with Odd Values in a Matrix */

/* Complexities.
 * Time: Θ(m n + i m + i n)
 * Space: Θ(m n)
 * where the matrix under consideration is of size m × n, and i is the number of
 * indices. */

/* Idea.
 * We simulate the described process and afterwards count the number of odd
 * entries. */

#include <stdlib.h>

int oddCells(int m, int n, int **indices, int indicesSize, int *indicesColSize);
int **makeMatrix(int m, int n);
void freeMatrix(int m, int n, int **matrix);
void incrementRow(int m, int n, int **matrix, int row);
void incrementColumn(int m, int n, int **matrix, int column);
int countOddEntries(int m, int n, int **matrix);

int oddCells(int m, int n, int **indices, int indicesSize, int *indicesColSize)
{
	int **matrix = makeMatrix(m, n);
	for (int i = 0; i < indicesSize; ++i) {
		incrementRow(m, n, matrix, indices[i][0]);
		incrementColumn(m, n, matrix, indices[i][1]);
	}
	int result = countOddEntries(m, n, matrix);
	freeMatrix(m, n, matrix);
	return result;
}

int **makeMatrix(int m, int n)
{
	int **result = malloc((size_t) m * sizeof(int *));
	for (int i = 0; i < m; ++i)
		result[i] = calloc((size_t) n, sizeof(int));
	return result;
}

void freeMatrix(int m, int n, int **matrix)
{
	for (int i = 0; i < m; ++i)
		free(matrix[i]);
	free(matrix);
}

void incrementRow(int m, int n, int **matrix, int row)
{
	for (int j = 0; j < n; ++j)
		++matrix[row][j];
}

void incrementColumn(int m, int n, int **matrix, int column)
{
	for (int i = 0; i < m; ++i)
		++matrix[i][column];
}

int countOddEntries(int m, int n, int **matrix)
{
	int result = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			result += matrix[i][j] % 2;
	return result;
}
