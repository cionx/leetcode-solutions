/* 1232. Check If It Is a Straight Line */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdbool.h>

/* We check if the given vectors v0, v1, ... are affine dependent: we subtract
 * v0 from each vector, and then check that each vi - v0 is linear dependent to
 * v1 - v0. We check that two vectors (a, b) and (c, d) are linearly dependent
 * by checking that the determinant ad - bc is zero. */

bool checkStraightLine(int **coordinates, int coordinatesSize,
                       int *coordinatesColSize)
{
	const int a = coordinates[1][0] - coordinates[0][0];
	const int b = coordinates[1][1] - coordinates[0][1];

	for (int i = 2; i < coordinatesSize; ++i) {
		const int c = coordinates[i][0] - coordinates[0][0];
		const int d = coordinates[i][1] - coordinates[0][1];
		if (a * d - b * c != 0)
			return false;
	}

	return true;
}
