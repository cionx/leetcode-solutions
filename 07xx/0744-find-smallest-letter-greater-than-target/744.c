char nextGreatestLetter(char *letters, int lettersSize, char target);
int binarySearch(char arr[], int lower, int upper, char value);

char nextGreatestLetter(char *letters, int lettersSize, char target)
{
	if (target >= letters[lettersSize - 1])
		return letters[0];

	const int i = binarySearch(letters, 0, lettersSize - 1, target);
	return letters[i];
}

int binarySearch(char arr[], int lower, int upper, char value)
{
	/* `lower` and `upper` are at most 10^4 - 1, and a signed int has at least
	 * 16 bits, giving a maximum value of at least 32,767. We can therefore
	 * compute `middle` without overflow.
	 */
	while (lower < upper) {
		const int middle = (upper + lower) / 2;
		if (arr[middle] <= value)
			lower = middle + 1;
		else
			upper = middle;
	}

	return lower;
}
