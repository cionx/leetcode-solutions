/* 771. Jewels and Stones */

/* Complexities
 * Time: Θ(m n)
 * Space: Θ(1)
 * where m and n are the lengths of the input arrays. */

int numJewelsInStones(char *jewels, char *stones)
{
	int counter = 0;

	for (int i = 0; jewels[i] != '\0'; ++i)
		for (int j = 0; stones[j] != '\0'; ++j)
			if (jewels[i] == stones[j])
				++counter;

	return counter;
}
