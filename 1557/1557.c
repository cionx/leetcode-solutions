#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
	/* booleans that state which vertices are sources */
	size_t space = (unsigned int) n * sizeof(int);
	int* source = malloc(space);
	memset(source, true, space);
	for (int i = 0; i < edgesSize; i++) {
		source[ edges[i][1] ] = false;
	}

	/* gather together those vertices that are nodes */
	int size = 0;
	int* tmp_result = malloc(space);
	int j = 0;
	for (int i = 0; i < n; ++i)
		if (source[i]) {
			tmp_result[j] = i;
			j++;
			size++;
		}
	/* the values in source are no longer needed */
	free(source);

	int* result = reallocarray(tmp_result, (size_t) size, sizeof(int));

	*returnSize = size;
	return result;
}
