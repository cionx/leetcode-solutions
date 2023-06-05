#include <stdlib.h>
#include "2661.h"

int firstCompleteIndex(const int *arr, int arrSize, const int **mat,
                       int matSize, const int *matColSize)
{
	const int m = matSize;
	const int n = matColSize[0];

	int *row = malloc((size_t) (m * n + 1) * sizeof(int));
	int *column = malloc((size_t) (m * n + 1) * sizeof(int));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			row[mat[i][j]] = i;
			column[mat[i][j]] = j;
		}
	}

	int *rowCounter = calloc((size_t) m, sizeof(int));
	int *columnCounter = calloc((size_t) n, sizeof(int));


	int result = -1;
	for (int k = 0; k < arrSize; ++k) {
		const int i = row[arr[k]];
		const int j = column[arr[k]];
		if (++rowCounter[i] == n || ++columnCounter[j] == m) {
			result = k;
			break;
		}
	}

	free(row), free(column), free(rowCounter), free(columnCounter);
	return result;
}
