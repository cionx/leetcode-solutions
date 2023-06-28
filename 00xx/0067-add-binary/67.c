/* 67. Add Binary */

/* Complexities.
 * Time: O(m + n)
 * Space: O(1)
 * where m and n are the lengths of the two input string. */

#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b);
inline int toDigit(char c);
inline char toChar(int d);

char *addBinary(char *a, char *b)
{
	int aLength = (int) strlen(a);
	int bLength = (int) strlen(b);

	int maxLength = (aLength > bLength) ? aLength : bLength;
	char *result = malloc(((size_t) maxLength + 2) * sizeof(int));

	int i = aLength - 1;
	int j = bLength - 1;
	int k = 0;
	int carry = 0;
	while (i >= 0 && j >= 0) {
		const int sum = toDigit(a[i--]) + toDigit(b[j--]) + carry;
		result[k++] = toChar(sum % 2);
		carry = sum / 2;
	}
	while (i >= 0) {
		const int sum = toDigit(a[i--]) + carry;
		result[k++] = toChar(sum % 2);
		carry = sum / 2;
	}
	while (j >= 0) {
		const int sum = toDigit(b[j--]) + carry;
		result[k++] = toChar(sum % 2);
		carry = sum / 2;
	}
	if (carry > 0)
		result[k++] = toChar(carry);
	else
		result = realloc(result, (size_t) (maxLength + 1) * sizeof(int));
	result[k] = '\0';

	/* Reverse the result. */
	for (i = 0, j = k - 1; i < j; ++i, --j) {
		const char tmp = result[i];
		result[i] = result[j];
		result[j] = tmp;
	}

	return result;
}

inline int toDigit(char c)
{
	return c - '0';
}

inline char toChar(int d)
{
	return (char) ('0' + d);
}
