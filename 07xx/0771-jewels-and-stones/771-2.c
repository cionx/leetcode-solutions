/* 771. Jewels and Stones */

/* Complexities
 * Time: Θ(m + n)
 * Space: Θ(128)
 * where m and n are the lengths of the input arrays. */

#include <stdbool.h>

int numJewelsInStones(char *jewels, char *stones)
{
	bool isJewel[128] = {false}; /* All 128 ASCII characters for simplicitly. */
	for (int i = 0; jewels[i] != '\0'; ++i)
		isJewel[jewels[i]] = true;

	int counter = 0;
	for (int j = 0; stones[j] != '\0'; ++j)
		if (isJewel[stones[j]])
			++counter;

	return counter;
}
