/* 405. Convert a Number to Hexadecimal */

/* Complexities.
 * Time: O(log(n))
 * Space: Θ(1)
 * where n is the input integer. */

/* Idea.
 * If num is negative, then we must replace it by the positive number
 *   2**32 + num.
 * This happens automatically if we convert `num` to an unsigned 32-bit int, see
 * https://stackoverflow.com/questions/50605/. We thus convert `num`, and then
 * do all computations with unsigned 32-bit ints. (We need to work with 32-bit
 * unsigned ints anyways, because otherwise we cannot represent 2**32 + num.)
 *
 * The case num = 0 has to be handled separately, since by the default rules
 * there would be no digits. */

#include <stdint.h>
#include <stdlib.h>

#define HEXADEC 16

char *toHex(int num);
char hexadecDigit(char d);

char *toHex(int num)
{
	/* Converting to an unsigned 32bit int takes care of negative numbers. */
	uint32_t n = (uint32_t) num;

	/* The case n = 0 has to be handled differently. */
	if (n == 0) {
		char *result = malloc(2 * sizeof(char));
		result[0] = '0';
		result[1] = '\0';
		return result;
	}

	/* The number of required hexadecimal digits. */
	int numOfDigits = 0;
	for (uint32_t k = n; k > 0; k /= HEXADEC)
		++numOfDigits;

	/* The result is a string, and thus terminated by \0. */
	char *result = malloc((size_t) (numOfDigits + 1) * sizeof(char));
	result[numOfDigits] = '\0';

	/* Finally, the computation of the digits, from right to left. */
	for (int i = numOfDigits - 1; i >= 0; --i) {
		uint32_t lastPlace = n % HEXADEC;
		result[i] = hexadecDigit((char) lastPlace);
		n /= HEXADEC;
	}

	return result;
}

/* Convert a number 0, ..., 15 to a hexadecimal digit. (Actually works with
 * numbers 0, ..., 35.) */
char hexadecDigit(char d)
{
	if (d <= 9)
		return '0' + d;
	return 'a' + (d - 10);
}
