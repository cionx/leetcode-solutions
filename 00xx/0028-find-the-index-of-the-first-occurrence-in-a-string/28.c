/* Find the Index of the First Occurrence in a String */

/* Complexities.
 * Time: O(m n)
 * Space: O(1)
 * where m and n are the lengths of m and n respectively. */

int strStr(char *haystack, char *needle)
{
	for (int i = 0; haystack[i] != '\0'; ++i) {
		int k = 0;
		for (int j = i; haystack[j] == needle[k] && needle[k] != '\0'; ++j, ++k)
			;
		if (needle[k] == '\0')
			return i;
	}
	return -1;
}
