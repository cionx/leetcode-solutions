/* 1207. Unique Number of Occurences */

/* Complexities.
 * Time: O(n log(n))
 * Space: Θ(n)
 * where n is the length of the input array. */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmpInt(const void *vpa, const void *vpb);

bool uniqueOccurrences(int *arr, int arrSize)
{
	/* Create a sorted copy of the input array. */
	int *copy = malloc((size_t) arrSize * sizeof(int));
	memcpy(copy, arr, (size_t) arrSize * sizeof(int));
	qsort(copy, (size_t) arrSize, sizeof(int), cmpInt);

	/* Collect the numbers of occurrences in another array. */
	int *occur = calloc((size_t) arrSize, sizeof(int));
	int occurNum = 0;
	for (int i = 0; i < arrSize; ++occurNum) {
		int current = copy[i];
		for (; i < arrSize && copy[i] == current; ++i)
			++occur[occurNum];
	}
	free(copy);

	/* Sort the numbers of occurrences and check for duplicates. */
	qsort(occur, (size_t) occurNum, sizeof(int), cmpInt);
	bool unique = true;
	for (int i = 0; i < occurNum - 1; ++i)
		if (occur[i] == occur[i + 1]) {
			unique = false;
			break;
		}
	free(occur);

	return unique;
}

int cmpInt(const void *vpa, const void *vpb)
{
	const int *pa = (const int *) vpa;
	const int *pb = (const int *) vpb;

	return (*pa > *pb) - (*pa < *pb);
}
