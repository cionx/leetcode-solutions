/* 2138. Divide a String Into Groups of Size k */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdlib.h>
#include <string.h>

char **divideString(char *s, int k, char fill, int *returnSize)
{
	int len = (int) strlen(s);
	int number = (len / k) + (len % k == 0 ? 0 : 1);
	char **result = malloc((size_t) number * sizeof(char *));

	for (int i = 0; i < number - 1; ++i) {
		char *group = malloc((size_t) (k + 1) * sizeof(char));
		int offset = i * k;
		for (int j = 0; j < k; ++j) {
			group[j] = s[offset + j];
		}
		group[k] = '\0';
		result[i] = group;
	}

	char *last = malloc((size_t) (k + 1) * sizeof(char));
	int offset = (number - 1) * k;
	int j = 0;
	for (; offset + j < len; ++j) {
		last[j] = s[offset + j];
	}
	for (; j < k; ++j) {
		last[j] = fill;
	}
	last[k] = '\0';
	result[number - 1] = last;

	*returnSize = number;
	return result;
}
