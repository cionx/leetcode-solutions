/* 8. String to Integer (atoi) */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input string. */

#include <ctype.h>
#include <stdint.h>

/* We use that -2^31 equals INT32_MIN. */

int myAtoi(char *s)
{
	while (*s == ' ')
		++s;
	const int sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;

	/* We read in num as if it were negative. */
	int num;
	for (num = -0; isdigit(*s); ++s) {
		if (num < INT32_MIN / 10) { /* Note: in C, -number.fraction is*/
			num = INT32_MIN;        /* rounded up to -number. */
			break;
		}
		num *= 10;
		const int digit = *s - '0';
		if (-digit < INT32_MIN - num) {
			num = INT32_MIN;
			break;
		}
		num -= digit;
	}

	if (num == INT32_MIN && sign == 1)
		return INT32_MAX;
	return (-sign) * num;
}
