/* 443. String Compression */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

int compress(char *chars, int charsSize)
{
	int to = 0;
	int groupStart = 0;
	while (groupStart < charsSize) {
		/* Determine the next group. */
		int groupEnd = groupStart;
		while (groupEnd < charsSize && chars[groupEnd] == chars[groupStart])
			++groupEnd;
		--groupEnd;
		/* Encode the group. */
		chars[to++] = chars[groupStart];
		const int amount = groupEnd - groupStart + 1;
		groupStart = groupEnd + 1;
		if (amount == 1)
			continue;
		int digitNumber = 0;
		for (int l = amount; l > 0; l /= 10)
			++digitNumber;
		for (int i = to + digitNumber - 1, l = amount; to <= i; --i, l /= 10)
			chars[i] = (l % 10) + '0';
		to += digitNumber;
	}
	return to;
}
