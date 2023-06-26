/* 1575. Count All Possible Routes */

/* Complexities.
 * Time: O(l^2 f)
 * Space: Θ(l f)
 * where l is the number of locations and f is the starting fuel. */

#include <stdlib.h>

#define MODULO 1##000##000##007

int countRoutes(int *locs, int locsSize, int start, int end, int fuel);
long getValue(int *locations, int locationsSize, int start, int end, int fuel,
              long *cache);

int countRoutes(int *locations, int locationsSize, int start, int end, int fuel)
{
	const int cacheSize = locationsSize * (fuel + 1);
	long *cache = malloc((size_t) cacheSize * sizeof(long));
	for (int i = 0; i < cacheSize; ++i)
		cache[i] = -1;

	const long result =
		getValue(locations, locationsSize, start, end, fuel, cache);

	free(cache);
	return (int) result;
}

long getValue(int *locations, int locationsSize, int start, int end, int fuel,
              long *cache)
{
	/* We don’t need this check, but it’s faster and more robust to do it. */
	if (fuel <= 0)
		return start == end;

	const int index = fuel * locationsSize + start;
	if (cache[index] != -1)
		return cache[index];

	long sum = (start == end);
	for (int between = 0; between < locationsSize; ++between) {
		const int dist = abs(locations[start] - locations[between]);
		if (dist <= fuel && between != start) {
			sum += getValue(locations, locationsSize, between, end, fuel - dist,
			                cache);
			sum %= MODULO;
		}
	}

	cache[index] = sum;
	return sum;
}
