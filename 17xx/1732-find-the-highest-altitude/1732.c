/* 1732. Find the Highest Altitude */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the lenght of the input array. */

/* The numbers are small enough that no overflow will occur. */

int largestAltitude(int *gain, int gainSize)
{
	int max = 0, current = 0;
	for (int i = 0; i < gainSize; ++i) {
		current += gain[i];
		if (current > max)
			max = current;
	}

	return max;
}
