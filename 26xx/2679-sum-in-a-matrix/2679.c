/* 2679. Sum in a Matrix */

/* Complexities.
 * Time: O(m n log(n))
 * Space: O(1)
 * where m × n is the size of the input matrix. */

#include <stdlib.h>

int matrixSum(int **nums, int numsSize, int *numsColSize);
int columnMax(int **nums, int column, int rows);
int cmpInt(const void *pva, const void *pvb);

int matrixSum(int **nums, int numsSize, int *numsColSize)
{
	const int m = numsSize;
	const int n = numsColSize[0];
	for (int i = 0; i < m; ++i)
		qsort(nums[i], n, sizeof(int), cmpInt);
	int sum = 0;
	for (int j = 0; j < n; ++j)
		sum += columnMax(nums, j, m);
	return sum;
}

int columnMax(int **nums, int column, int rows)
{
	int max = nums[0][column];
	for (int i = 1; i < rows; ++i)
		if (nums[i][column] > max)
			max = nums[i][column];
	return max;
}

int cmpInt(const void *pva, const void *pvb)
{
	const int *pa = (const int *) pva;
	const int *pb = (const int *) pvb;
	return (*pa > *pb) - (*pa < *pb);
}
