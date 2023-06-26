/* 1557. Minimum Number of Vertices to Reach All Nodes */

/* Complexities.
 * Time: O(n + e)
 * Space: O(n)
 * where n is the number of vertices in the graph, and e its number of edges. */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int *findSmallestSetOfVertices(int n, int **edges, int edgesSize,
                               int *edgesColSize, int *returnSize)
{
	/* booleans that state which vertices are sources */
	size_t space = (size_t) n * sizeof(int);
	int *isSource = malloc(space);
	memset(isSource, true, space);
	for (int i = 0; i < edgesSize; i++) {
		isSource[edges[i][1]] = false;
	}

	/* Gather together those vertices that are sources */
	int size = 0;
	int *tmp_result = malloc(space);
	int j = 0;
	for (int i = 0; i < n; ++i)
		if (isSource[i]) {
			tmp_result[j] = i;
			j++;
			size++;
		}
	/* the values in source are no longer needed */
	free(isSource);

	*returnSize = size;
	return reallocarray(tmp_result, (size_t) size, sizeof(int));
}
