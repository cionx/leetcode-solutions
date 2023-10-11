/* 1689. Partitioning Into Minimum Number of Deci-Binary Numbers */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input string. */

/* Idea.
 *
 * We simply need to determine the maximal digit contained in the input. */

int minPartitions(char *digits)
{
	int max = 0;

	for (int i = 0; digits[i] != '\0'; ++i) {
		int digit = digits[i] - '0';
		if (digit > max)
			max = digit;
	}

	return max;
}
