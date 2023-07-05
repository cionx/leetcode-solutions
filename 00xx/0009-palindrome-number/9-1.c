/* 9. Palindrome Number */

/* Complexities.
 * Time: O(d) = O(log(n))
 * Space: O(d) = O(log(n))
 * where d is the number of digits of the input number n. */

#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	int digitsSize = 0;
	for (int y = x; y > 0; y /= 10)
		++digitsSize;

	int *digits = malloc((size_t) digitsSize * sizeof(int));
	for (int i = 0, y = x; i < digitsSize; ++i, y /= 10)
		digits[i] = y % 10;

	bool result = true;
	for (int i = 0, j = digitsSize - 1; i < j; ++i, --j)
		if (digits[i] != digits[j]) {
			result = false;
			break;
		}

	free(digits);
	return result;
}
