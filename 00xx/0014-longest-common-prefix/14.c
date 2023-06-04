#include <stdlib.h>

#define MAXLENGTH 200

char *longestCommonPrefix(char **strs, int strsSize);

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
