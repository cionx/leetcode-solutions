/* Maximum Odd Binary Number */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input string. */

/* Idea.
 * We put one 1 at the end of the result, and all others 1s at the front. */

#include <stdlib.h>
#include <string.h>

char *maximumOddBinaryNumber(char *s)
{
	int length = (int) strlen(s);
	char *result = malloc(((size_t) length + 1) * sizeof(char));

	int ones = 0;
	for (int i = 0; i < length; ++i)
		if (s[i] == '1')
			++ones;

	for (int i = 0; i < ones - 1; ++i)
		result[i] = '1';
	for (int i = ones - 1; i < length - 1; ++i)
		result[i] = '0';
	result[length - 1] = '1';
	result[length] = '\0';

	return result;
}
