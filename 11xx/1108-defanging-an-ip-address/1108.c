/* 1108. Defanging an IP Address */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input string. */

#include <stdlib.h>
#include <string.h>

char *defangIPaddr(char *address)
{
	int oldLength = (int) strlen(address);
	int newLength = oldLength + 6;

	char *result = malloc(((size_t) newLength + 1) * sizeof(char));

	int to = 0;
	for (int from = 0; from < oldLength; ++from) {
		if (address[from] == '.') {
			result[to++] = '[';
			result[to++] = '.';
			result[to++] = ']';
		}
		else
			result[to++] = address[from];
	}
	result[to] = '\0';

	return result;
}
