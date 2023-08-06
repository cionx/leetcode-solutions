/* 1657. Determine if Two Strings Are Close */

/* Complexities.
 * Time: Θ(n1 + n2)
 * Space: Θ(a)
 * where n1 and n1 are the lengths of the two input strings, and a = 26 is the
 * size of the given alphabet. */

/* Idea.
 * Two words are close if they contain the same set of characters, and up to
 * permutation the same multiplicities. */

#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

bool closeStrings(char *word1, char *word2);
int *frequencyVector(char *word);
bool sameCharacters(int *freq1, int *freq2);
bool equalVectors(int *freq1, int *freq2);
int cmpInt(const void *pva, const void *pvb);

bool closeStrings(char *word1, char *word2)
{
	int *freq1 = frequencyVector(word1);
	int *freq2 = frequencyVector(word2);
	if (!sameCharacters(freq1, freq2)) {
		free(freq1), free(freq2);
		return false;
	}
	qsort(freq1, ALPHABET_SIZE, sizeof(int), cmpInt);
	qsort(freq2, ALPHABET_SIZE, sizeof(int), cmpInt);
	bool result = equalVectors(freq1, freq2);
	free(freq1), free(freq2);
	return result;
}

int *frequencyVector(char *word)
{
	int *result = calloc(ALPHABET_SIZE, sizeof(int));
	for (int i = 0; word[i] != '\0'; ++i)
		++result[word[i] - 'a'];
	return result;
}

bool sameCharacters(int *freq1, int *freq2)
{
	for (int i = 0; i < ALPHABET_SIZE; ++i)
		if ((freq1[i] == 0) != (freq2[i] == 0))
			return false;
	return true;
}

bool equalVectors(int *freq1, int *freq2)
{
	for (int i = 0; i < ALPHABET_SIZE; ++i)
		if (freq1[i] != freq2[i])
			return false;
	return true;
}

int cmpInt(const void *pva, const void *pvb)
{
	const int *pa = (const int *) pva;
	const int *pb = (const int *) pvb;
	return (*pa > *pb) - (*pa < *pb);
}
