/* 151. Reverse Words in a String */

/* In-place, iterative solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * We first remove leading and trailing spaces, and squash together blocks of
 * consecutive spaces into a single space. Then we reverse the entire string.
 * This reverses the position of the words as desired, but also reverses each
 * word internally. We revert the second effect by reversing each word. */

#include <string.h>

char *reverseWords(char *str);
int normalizeSpaces(char *str);
void reverse(char *str, int first, int last);

char *reverseWords(char *str)
{

	/* STEP 1: remove leading and trailing spaces, and also squash together
	 * blocks of consecutive spaces. */
	int length = normalizeSpaces(str);

	/* STEP 2: reverse the entire string. */
	reverse(str, 0, length - 1);

	/* STEP 3: Go through the string and reverse each word. */
	int start, end;
	for (start = 0; start < length; start = end + 1) {
		/* Search for the beginning of the next word. */
		while (str[start] == ' ')
			++start;
		/* Search for the end of the word. */
		end = start;
		while (end < length && str[end] != ' ')
			++end;
		--end;
		/* Finally, reverse the found word. */
		reverse(str, start, end);
		/* Note: if s[start] is EOF, the end = start - 1, and the above call to
		 * reverse will do nothing. The loop will terminate afterwards. */
	}

	return str;
}

/* normalizeSpaces(s): Removes leading and trailing spaces from s, and replaces
 * blocks of consecutive spaces by a single space. Returns the new length. */
int normalizeSpaces(char *str)
{
	const size_t length = strlen(str);

	unsigned int from = 0; /* uint to compare with length without conversion. */
	int to = 0;
	/* We simplify (spaces + word) to (word + single space) as we go. */
	while (from < length) {
		while (str[from] == ' ')
			++from;
		while (from < length && str[from] != ' ')
			str[to++] = str[from++];
		str[to++] = ' ';
	}
	/* Ignore unnecessarily added spaces at the end. There is at least one such
	 * space, as we added a space after the last word. */
	do
		--to;
	while (to >= 0 && str[to] == ' ');
	str[++to] = '\0';

	return to;
}

/* reverse(s, i, j): reverses the substring s[i : j]. */
void reverse(char *str, int first, int last)
{
	for (int i = first, j = last; i < j; ++i, --j) {
		const char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}
