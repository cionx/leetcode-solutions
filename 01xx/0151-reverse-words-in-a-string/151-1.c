/* 151. Reverse Words in a String */

/* Not-in-place, iterative solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

#include <stdlib.h>
#include <string.h>

char *reverseWords(char *s)
{

	size_t length = strlen(s);
	char *result = malloc((length + 1) * sizeof(char));

	char *start, *end, *to;
	end = s + (length - 1);
	to = result;
	while (s <= end) {
		/* Finding the end of the previous word. */
		while (s <= end && *end == ' ')
			--end;
		start = end;
		while (s <= start && *start != ' ')
			--start;
		++start;
		/* Copying the word into the result, and add a trailing space. */
		for (char *letter = start; letter <= end; ++letter)
			*(to++) = *letter;
		*(to++) = ' ';
		end = start - 1;
	}

	/* We remove all trailing space from the result. */
	if (result < to) {
		--to;
		while (result <= to && *to == ' ')
			--to;
		++to;
	}
	*(to++) = '\0';

	result = realloc(result, (size_t) (to - result) * sizeof(char));
	return result;
}
