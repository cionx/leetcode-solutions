/* 2390. Removing Stars From a String */

/* Complexities.
 * Time: Θ(n)
 * Space: O(n)
 * where n is the length of the input string. */

char *removeStars(char *s)
{
	int from, to;
	from = to = 0;
	while (s[from] != '\0') {
		if (s[from] == '*')
			--to;
		else {
			s[to] = s[from];
			++to;
		}
		++from;
	}
	s[to] = '\0';

	return s;
}
