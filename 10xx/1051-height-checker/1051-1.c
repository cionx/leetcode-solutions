/* 1051. Height Checker */

/* Complexities.
 * Time: O(n log(n))
 * Space: Θ(n)
 * where n is the length of the input array. */

#include <stdlib.h>
#include <string.h>

int heightChecker(int *heights, int heightsSize);
int cmpInt(const void *vpa, const void *vpb);

int heightChecker(int *heights, int heightsSize)
{
	const size_t byteSize = (size_t) heightsSize * sizeof(int);
	int *expected = malloc(byteSize);
	memcpy(expected, heights, byteSize);
	qsort(expected, heightsSize, sizeof(int), cmpInt);

	int counter = 0;
	for (int i = 0; i < heightsSize; ++i)
		counter += (heights[i] != expected[i]);

	free(expected);
	return counter;
}

int cmpInt(const void *vpa, const void *vpb)
{
	const int *pa = (const int *) vpa;
	const int *pb = (const int *) vpb;
	return (*pa > *pb) - (*pa < *pb);
}
