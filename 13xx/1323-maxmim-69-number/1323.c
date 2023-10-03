/* 1323. Maximum 69 Number */

/* Complexities.
 * Time: O(log(n))
 * Space: Θ(1)
 * where n is the input number. */

#include <stdbool.h>

int maximum69Number(int num)
{
	/* Create a power of 10 of the same order of magnitude as `num`. */
	int pow10 = 1;
	for (int k = num / 10; k > 0; k /= 10)
		pow10 *= 10;

	int result = 0;
	bool flipped = false;
	for (; pow10 > 0 && !flipped; pow10 /= 10) {
		int digit = num / pow10; /* The current leading digit. */
		num -= digit * pow10;    /* Remove the leading digit. */
		result += 9 * pow10;
		flipped = (digit != 9);
	}
	result += num; /* Add all the unchanged lower digits. */

	return result;
}
