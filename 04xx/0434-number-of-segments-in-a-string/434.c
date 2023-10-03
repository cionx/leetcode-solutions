/* 434. Number of Segments in a String */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input string. */

typedef enum { inside, outside } state;

int countSegments(char *s)
{
	state state = outside;
	int counter = 0;

	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == ' ')
			state = outside;
		else if (state == outside) {
			state = inside;
			++counter;
		}
	}

	return counter;
}
