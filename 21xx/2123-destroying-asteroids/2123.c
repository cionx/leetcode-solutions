/* 2126. Destroying Asteroids */

/* Complexities.
 * O(n log(n))
 * Θ(1)
 * where n is the number of asteroids. */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

bool asteroidsDestroyed(int initialMass, int *asteroids, int asteroidsSize);
int cmpInt(const void *vpa, const void *vpb);

bool asteroidsDestroyed(int initialMass, int *asteroids, int asteroidsSize)
{
	qsort(asteroids, (size_t) asteroidsSize, sizeof(int), cmpInt);

	int64_t mass = (int64_t) initialMass;
	for (int i = 0; i < asteroidsSize; ++i) {
		if (mass < asteroids[i])
			return false;
		mass += asteroids[i];
	}

	return true;
}

int cmpInt(const void *vpa, const void *vpb)
{
	const int *pa = (const int *) vpa;
	const int *pb = (const int *) vpb;

	return (*pa > *pb) - (*pa < *pb);
}
