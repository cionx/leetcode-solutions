#include "2661.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int arr[] = {8, 2, 4, 9, 3, 5, 7, 10, 1, 6};
	int arrSize = 10;

	int matSize = 2;
	int *matColSize = malloc(sizeof(int));
	*matColSize = 5;

	const int row1[] = {8, 2, 9, 10, 4};
	const int row2[] = {1, 7, 6, 3, 5};
	const int *mat[] = {row1, row2};

	int result = firstCompleteIndex(arr, arrSize, mat, matSize, matColSize);
	printf("The result is %d\n", result);

	free(matColSize);
	return 0;
}
