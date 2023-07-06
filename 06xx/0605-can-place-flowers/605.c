/* 605. Can Place Flowers */

/* Complexities.
 * Time: O(l)
 * Space: O(1)
 * where l is the length of the input array. */

/* Idea.
 * We add two fields to the left of the flower bed, and two fields to the right.
 * We place a flower on both the very left and the very right field. We then
 * traverse through the array, and for every distance between two subsequent
 * flowers, we calculate how many new flowers can be placed in-between. In the
 * end, we check if we were able to place enough new flowers throughout the
 * entire extended flower bed. */

#include <stdbool.h>

enum { flower = 1, empty = 0 };

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
	int prev = -2;
	int current = 0;
	while (current < flowerbedSize && n > 0) {
		/* Find the next flower. */
		while (current < flowerbedSize && flowerbed[current] != flower)
			++current;
		/* Determine free space to the left of the found flower. If we find no
		 * flower and are outside the field, then we pretend that there is a
		 * flower slightly to the right of the field. */
		if (current == flowerbedSize)
			++current;
		n -= (current - prev - 2) / 2;
		prev = current;
		++current;
	}

	return (n <= 0);
}
