/* 1768. Merge Strings Alternately */

/* Complexities.
 * Time: O(m + n)
 * Space: O(1)
 * where m and n are the lengths of the input strings. */

#include <stdlib.h>
#include <string.h>

char *mergeAlternately(char *word1, char *word2)
{
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	char *result = malloc(((size_t) len1 + len2 + 1) * sizeof(char));

	int from1 = 0, from2 = 0, to = 0;
	while (from1 < len1 && from2 < len2) {
		result[to++] = word1[from1++];
		result[to++] = word2[from2++];
	}
	while (from1 < len1)
		result[to++] = word1[from1++];
	while (from2 < len2)
		result[to++] = word2[from2++];

	result[to] = '\0';
	return result;
}
