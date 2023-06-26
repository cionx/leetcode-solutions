/* 1456. Maximum Number of Vowels in a Substring of Given Length */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input string. */

#include <stdbool.h>

int maxVowels(char *s, int k);
bool isVowel(char c);

int maxVowels(char *s, int k)
{
	int best = 0;
	int current = 0;

	for (int j = 0; j < k; j++)
		current += isVowel(s[j]);
	best = current;

	for (int i = 0, j = k; s[j] != '\0'; ++i, ++j) {
		current -= isVowel(s[i]);
		current += isVowel(s[j]);
		if (current > best)
			best = current;
	}

	return best;
}

bool isVowel(char c)
{
	return c == 'e' || c == 'a' || c == 'o' || c == 'i' || c == 'u';
}
