/* 14. Longest Common Prefix. */

/* Complexities.
 * Time: O(n MAXLENGTH)
 * Space: O(MAXLENGTH)
 * where MAXLENGTH = 200 and n is the length of the input array. */

#include <stdlib.h>

#define MAXLENGTH 200

char *longestCommonPrefix(char **strs, int strsSize)
{
	char *result = malloc(MAXLENGTH * sizeof(char));

	int pos;
	char c;
	for (pos = 0; (c = strs[0][pos]) != '\0'; ++pos) {
		for (int i = 0; i < strsSize; ++i)
			if (strs[i][pos] != c) {
				result[pos] = '\0';
				return result;
			}
		result[pos] = c;
	}

	result[pos] = '\0';
	return result;
}
