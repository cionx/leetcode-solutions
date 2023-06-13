/* Time:  O(ℓ1 + ℓ2)
 *        where str1 and str2 are of lengths ℓ1 and ℓ2
 * Space: O(1)
 */

/* *****************************************************************************
 * We make the following observations:
 *
 * If gcd(str1, str2) is nonempty, then str1 and str2 are of the form
 *      str1 = n * str,  str2 = m * str     (*)
 * for some nonempty string str.
 *
 * If str1 and str2 are of the form (*) for any string str, then gcd(str1, str2)
 * is given by
 *      gcd(str1, str2) = gcd(m, n) * str.
 * If we denote the length of str by ℓ, then it follows that str1 has length
 * n * ℓ and str2 has length m * ℓ. The length of gcd(str1, str2) is then
 *      gcd(m, n) * ℓ = gcd(m * ℓ, n * ℓ).
 * In other words, we have
 *      length(gcd(str1, str2)) = gcd(length(str1), length(str2)).
 *
 * If gcd(str1, str2) is nonempty, then it is a leading substring of str1 or
 * str2, whichever of the two is nonempty.
 * *****************************************************************************
 * This leads us to the following algorithms:
 * 1. If one of the two strings is empty, return the other one.
 * 2. Determine the greatest common divisor ℓ of the lengths of str1 and str2.
 * 3. Check that the initial substrings of str1 and str2 of length ℓ are equal.
 * 4. Check that both str1 and str2 are multiples of this initial substring.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long length; /* return type of strlen */

char *gcdOfStrings(char *str1, char *str2);
length gcd(length a, length b);
bool initialEqual(const char *str1, const char *str2, length len);
bool initialDivisor(const char *str, length len);

char *gcdOfStrings(char *str1, char *str2)
{
	length len1 = strlen(str1);
	length len2 = strlen(str2);

	if (len1 == 0)
		return str2;
	else if (len2 == 0)
		return str1;

	length len_gcd = gcd(len1, len2);

	if (!initialEqual(str1, str2, len_gcd) || !initialDivisor(str1, len_gcd) ||
	    !initialDivisor(str2, len_gcd)) {
		char *result = malloc(sizeof(char));
		result[0] = '\0';
		return result;
	}

	char *result = malloc((size_t) (len_gcd + 1) * sizeof(char));
	for (length i = 0; i < len_gcd; ++i)
		result[i] = str1[i]; /* Could also use str2. */
	result[len_gcd] = '\0';

	return result;
}

length gcd(length a, length b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

/* Requires len to be smaller or equal to the lengths of str1 and str2. */
bool initialEqual(const char *str1, const char *str2, length len)
{
	for (length i = 0; i < len; ++i)
		if (str1[i] != str2[i])
			return false;

	return true;
}

/* Assumes the length of str to be a multiple of len. */
bool initialDivisor(const char *str, length len)
{
	for (length i = len; str[i] != '\0'; ++i)
		if (str[i] != str[i % len])
			return false;

	return true;
}
