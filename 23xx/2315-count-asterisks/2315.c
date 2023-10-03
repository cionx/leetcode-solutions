/* 2315. Count Asterisks */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input string. */

enum status { inside, outside };

int countAsterisks(char *s)
{
	int counter = 0;
	enum status state = outside;

	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '|')
			state = (state == outside) ? inside : outside;
		else if (s[i] == '*' && state == outside)
			++counter;
	}

	return counter;
}
