/* 345. Reverse Vowels in String */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

#include <stdbool.h>
#include <string.h>

char *reverseVowels(char *s);
bool isVowel(char c);

char *reverseVowels(char *s)
{
	int length = (int) strlen(s);
	int i = 0, j = length - 1;
	while (i < j) {
		while (i < j && !isVowel(s[i]))
			++i;
		while (i < j && !isVowel(s[j]))
			--j;
		if (i >= j)
			break;
		const char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		++i;
		--j;
	}
	return s;
}

bool isVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
	       c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
