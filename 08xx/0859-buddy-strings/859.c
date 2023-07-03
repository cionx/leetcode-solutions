/* 859. Buddy Strings */

/* Complexities:
 * Time: O(min(m,n))
 * Space: Θ(alphabet size) = Θ(1)
 * where m and n are the lengths of the two input strings. */

/* Idea.
 * A. If the strings have different lengths, then no swap will help.
 * In the following cases, the strings have the same length.
 * B. If the strings differ in at least three places, then one swap is simply
 *    not enough.
 * C. Suppose the strings differ in exactly two places, say i and j. Then we
 *    must swap these two places. This then requires that both s[i] = t[j] and
 *    s[j] = t[i].
 * D. Suppose the strings differ in exactly one place. Then swapping does not
 *    help, since the words have different letter frequencies.
 * E. If the strings are equal, then we need a swap that doesn’t change the
 *    word. This is possible if and only if some letter occurs multiple times.
 */

#include <stdbool.h>

#define ABCSIZE 26

bool buddyStrings(char *s, char *t)
{
	int first, second;
	first = second = -1;
	int freq[ABCSIZE] = {0}; /* Initialize all as 0. */

	int i;
	for (i = 0; s[i] != '\0' && t[i] != '\0'; ++i) {
		++freq[s[i] - 'a'];
		if (s[i] == t[i])
			continue;
		else if (first == -1)
			first = i;
		else if (second == -1)
			second = i;
		else
			/* B. */
			return false;
	}

	/* A. */
	if (s[i] != t[i]) /* Different lengths. */
		return false;
	/* C. */
	if (second != -1)
		return s[first] == t[second] && s[second] == t[first];
	/* D. */
	if (first != -1)
		return false;
	/* E. */
	for (int i = 0; i < ABCSIZE; ++i)
		if (freq[i] > 1)
			return true;

	return false;
}
