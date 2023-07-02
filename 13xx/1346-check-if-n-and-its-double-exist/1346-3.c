/* 1346. Check If N and Its Double Exist */

/* Complexities.
 * Time: O(n log(n))
 * Space: Θ(n)
 * where n is the length of the input array. */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool checkIfExist(int *arr, int arrSize);
int cmpInt(const void *vpa, const void *vpb);
int binarySearch(int *arr, int lower, int upper, int target);

bool checkIfExist(int *arr, int arrSize)
{
	if (arrSize == 0)
		return false;

	/* Created a sorted copy of the input array. */
	const size_t byteSize = (size_t) arrSize * sizeof(int);
	int *sorted = malloc(byteSize);
	memcpy(sorted, arr, byteSize);
	qsort(sorted, (size_t) arrSize, sizeof(int), cmpInt);

	for (int i = 0; i < arrSize; ++i)
		if (binarySearch(sorted, 0, i - 1, 2 * sorted[i]) != -1 ||
		    binarySearch(sorted, i + 1, arrSize - 1, 2 * sorted[i]) != -1) {
			free(sorted);
			return true;
		}

	free(sorted);
	return false;
}

int cmpInt(const void *vpa, const void *vpb)
{
	const int *pa = (const int *) vpa;
	const int *pb = (const int *) vpb;
	return (*pa > *pb) - (*pa < *pb);
}

int binarySearch(int *arr, int lower, int upper, int target)
{
	while (lower <= upper) {
		const int middle = lower + (upper - lower) / 2;
		if (arr[middle] < target)
			lower = middle + 1;
		else if (arr[middle] > target)
			upper = middle - 1;
		else
			return middle;
	}
	return -1;
}
