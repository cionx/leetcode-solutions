/* 2710. Remove Trailing Zeros From a String */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input string. */

#include <stdlib.h>

char *removeTrailingZeros(char *num)
{
	int i = 0;

	/* Search the end of the input string. */
	while (num[i] != '\0')
		++i;

	/* Go back to the first non-'0' character. */
	do
		--i;
	while (0 <= i && num[i] == '0');

	/* To get the index shift right: if we end up with i = 0, then the output
	 * consists of two characters: nums[0] and '\0'. The following code also
	 * works for the special case i = -1 (but LeetCode excludes this case).
	 */
	char *result = malloc((size_t) (i + 2) * sizeof(char));
	result[i + 1] = '\0';

	for (; i >= 0; --i)
		result[i] = num[i];

	return result;
}
