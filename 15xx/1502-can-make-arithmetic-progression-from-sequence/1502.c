/* 1502. Can Make Arithmetic Progression From Sequence */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(n)
 * where n is the length of the input array */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canMakeArithmeticProgression(int *arr, int arrSize);
int cmpFunction(const void *pa, const void *pb);

bool canMakeArithmeticProgression(int *arr, int arrSize)
{
	int *sorted = malloc((size_t) arrSize * sizeof(int));
	memcpy(sorted, arr, (size_t) arrSize * sizeof(int));
	qsort(sorted, arrSize, sizeof(int), cmpFunction);

	int growth = sorted[1] - sorted[0];

	bool result = true;
	for (int i = 2; i < arrSize; ++i)
		if (sorted[i] - sorted[i - 1] != growth) {
			result = false;
			break;
		}

	free(sorted);
	return result;
}

int cmpFunction(const void *pa, const void *pb)
{
	const int *a = (const int *) pa;
	const int *b = (const int *) pb;
	return (*a > *b) - (*a < *b);
}
