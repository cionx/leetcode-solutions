/* 66. Plus One */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdlib.h>
#include <string.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int extraDigit = 1;
	for (int i = 0; i < digitsSize; ++i)
		if (digits[i] != 9) {
			extraDigit = 0;
			break;
		}

	int *result = malloc(((size_t) digitsSize + extraDigit) * sizeof(int));
	*returnSize = digitsSize + extraDigit;

	int carry = 1;
	for (int i = digitsSize - 1; i >= 0; --i) {
		const int sum = digits[i] + carry;
		result[i + extraDigit] = sum % 10;
		carry = sum / 10;
	}

	if (carry > 0)
		result[0] = carry;

	return result;
}
