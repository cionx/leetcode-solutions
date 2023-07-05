/* 9. Palindrome Number */

/* Complexities.
 * Time: O(d)
 * Space: O(1)
 * where d is the number of digits of the input number n. */

/* Idea.
 * If x is non-negative, then we can compute the i-th digit of x as
 *   (x / (i-th power of 10)) % 10,
 * where the first digit of x is counted as its 0-th digit. This allows us to
 * compute each digit in O(1). */

#include <stdbool.h>

bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	int digitSize = 0;
	for (int y = x; y > 0; y /= 10)
		++digitSize;

	int smallPow10 = 1;
	int largePow10 = 1;
	for (int i = 1; i < digitSize; ++i)
		largePow10 *= 10;

	for (int i = 0, j = digitSize - 1; i < j;
	     ++i, --j, largePow10 /= 10, smallPow10 *= 10) {
		const int upperDigit = (x / largePow10) % 10;
		const int lowerDigit = (x / smallPow10) % 10;
		if (upperDigit != lowerDigit)
			return false;
	}

	return true;
}
