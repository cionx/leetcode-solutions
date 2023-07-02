/* 1232. Check If It Is a Straight Line */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdbool.h>

/* The line going through the first two points can be described by an equation
 *   ax + by = c.
 * The vector (a, b) needs to be orthogonal to the line. It can therefore by
 * computed by take the difference v1 - v0 and rotating it by 90 degrees.
 * (Rotation by 90 degrees is given by (x, y) -> (y, -x).) The value c can then
 * be computed as
 *   c = ax₀ + by₀.
 */

bool checkStraightLine(int **coordinates, int coordinatesSize,
                       int *coordinatesColSize)
{
	const int a = coordinates[1][1] - coordinates[0][1];
	const int b = -(coordinates[1][0] - coordinates[0][0]);
	const int c = a * coordinates[0][0] + b * coordinates[0][1];

	for (int i = 2; i < coordinatesSize; ++i)
		if (a * coordinates[i][0] + b * coordinates[i][1] != c)
			return false;

	return true;
}
