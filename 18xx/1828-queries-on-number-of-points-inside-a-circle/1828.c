/* 1828. Queries on Number of Points Inside a Circle */

/* Complexities.
 * Time: Θ(p q)
 * Space: Θ(1)
 * where p is the number of points and q is the number of queries. */

#include <stdbool.h>
#include <stdlib.h>

int *countPoints(int **points, int pointsSize, int *pointsColSize,
                 int **queries, int queriesSize, int *queriesColSize,
                 int *returnSize);
bool inCircle(int *point, int *circle);
int square(int x);

int *countPoints(int **points, int pointsSize, int *pointsColSize,
                 int **queries, int queriesSize, int *queriesColSize,
                 int *returnSize)
{
	int p = pointsSize;
	int q = queriesSize;

	int *result = calloc((size_t) q, sizeof(int));

	for (int j = 0; j < q; ++j)
		for (int i = 0; i < p; ++i)
			if (inCircle(points[i], queries[j]))
				++result[j];

	*returnSize = q;
	return result;
}

bool inCircle(int *point, int *circle)
{
	int px = point[0];
	int py = point[1];

	int cx = circle[0];
	int cy = circle[1];
	int cr = circle[2];

	return square(px - cx) + square(py - cy) <= square(cr);
}

int square(int x)
{
	return x * x;
}
