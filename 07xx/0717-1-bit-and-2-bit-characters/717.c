/* 717. 1-bit and 2-bit Characters */

/* Complexities.
 * Time: O(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * We need to check if the last bit is 0, and the preceeding block of
 * consecutive 1s is of even length. */
#include <stdbool.h>

bool isOneBitCharacter(int *bits, int bitsSize)
{
	if (bits[bitsSize - 1] == 1)
		return false;
	int length = 0;
	for (int i = bitsSize - 2; i >= 0 && bits[i] == 1; --i)
		++length;
	return length % 2 == 0;
}
