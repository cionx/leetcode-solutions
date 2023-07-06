/* 392. Is Subsequence */

/* Complexities.
 * Time: O(m + n)
 * Space: Θ(1)
 * where m and n are the lengths of the input strings. */

#include <stdbool.h>
#include <strings.h>

bool isSubsequence(char *s, char *t)
{
	int i = 0, j = 0;
	while (s[i] != '\0' && t[j] != '\0') {
		while (t[j] != '\0' && t[j] != s[i])
			++j;
		if (t[j] == '\0')
			break;
		++i;
		++j;
	}
	return s[i] == '\0';
}
