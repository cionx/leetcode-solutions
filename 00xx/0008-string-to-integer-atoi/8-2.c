/* 8. String to Integer (atoi) */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input string. */

#include <ctype.h>
#include <stdint.h>

int myAtoi(char *s)
{
	while (*s == ' ')
		++s;

	const int sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;

	int_fast64_t num;
	/* We read in num as if it were negative. */
	for (num = -0; isdigit(*s) && INT32_MIN <= -num; ++s) {
		num *= 10;
		const int digit = *s - '0';
		num += digit;
	}

	num *= sign;
	if (num > INT32_MAX)
		return INT32_MAX;
	else if (num < INT32_MIN)
		return INT32_MIN;
	return (int) num;
}
