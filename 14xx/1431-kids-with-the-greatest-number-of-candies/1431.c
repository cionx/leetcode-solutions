/* 1431. Kids With the Greatest Number of Candies */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdbool.h>
#include <stdlib.h>

bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies,
                      int *returnSize)
{
	int max = 0;
	for (int i = 0; i < candiesSize; ++i)
		if (candies[i] > max)
			max = candies[i];

	bool *result = malloc((size_t) candiesSize * sizeof(bool));
	for (int i = 0; i < candiesSize; ++i)
		result[i] = (candies[i] + extraCandies >= max);

	*returnSize = candiesSize;
	return result;
}
