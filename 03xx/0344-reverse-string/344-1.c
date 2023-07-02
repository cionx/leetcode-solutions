/* 344. Reverse String */

/* Iterative solution. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

void reverseString(char *s, int sSize)
{
	for (int i = 0, j = sSize - 1; i < j; ++i, --j) {
		const char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
