/* 557. Reverse Words in a String III */

/* In-place, iterative solution. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

char *reverseWords(char *s)
{
	int wordStart, wordEnd;

	wordStart = 0;
	while (s[wordStart] != '\0') {
		/* Finding the next word. */
		while (s[wordStart] == ' ')
			++wordStart;
		wordEnd = wordStart;
		while (s[wordEnd] != ' ' && s[wordEnd] != '\0')
			++wordEnd;
		--wordEnd;
		/* Reversing the word. */
		for (int i = wordStart, j = wordEnd; i < j; ++i, --j) {
			const char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
		/* Move on to the rest of the string. */
		wordStart = wordEnd + 1;
	}

	return s;
}
