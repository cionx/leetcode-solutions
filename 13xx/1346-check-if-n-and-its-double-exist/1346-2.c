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

bool checkIfExist(int *arr, int arrSize)
{
	if (arrSize == 0)
		return false;

	/* Created a sorted copy of the input array. */
	const size_t byteSize = (size_t) arrSize * sizeof(int);
	int *sorted = malloc(byteSize);
	memcpy(sorted, arr, byteSize);
	qsort(sorted, (size_t) arrSize, sizeof(int), cmpInt);

	/* Nowe we search for doubles with two pointers. First for negative values,
	 * then non-negative values. */
	int i = 0, j = 1;
	for (; j < arrSize && sorted[j] < 0; ++i) {
		while (j < arrSize && 2 * sorted[j] < sorted[i])
			++j;
		if (j == arrSize)
			break;
		if (2 * sorted[j] == sorted[i]) {
			free(sorted);
			return true;
		}
	}
	/* If the above loop had an iteration, then j is the first index with
	 * non-negitave value. If the loop had no iteration, then it is i. So either
	 * i or j is the first index with negative value. */
	i = (sorted[i] == 0) ? i : j;
	j = i + 1;
	for (; j < arrSize; ++i) {
		while (j < arrSize && sorted[j] < 2 * sorted[i])
			++j;
		if (j == arrSize)
			break;
		if (sorted[j] == 2 * sorted[i]) {
			free(sorted);
			return true;
		}
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
