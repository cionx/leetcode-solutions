/* Time:  O(log(n))
 * Space: O(1)
 *
 * where n is the length of the input array.
 */

enum direction { ascend, peak, descend, lost };

long peakIndexInMountainArray(int *array, long arraySize);
enum direction getDirection(int *array, long index);
int cmpInt(int a, int b);

/* arrSize goes up to 1e5, but an int is only guaranteed to holp up to
 * 32,767 ≈ 3e4. We therefore changed the type of arrSize to long. */
long peakIndexInMountainArray(int *array, long arraySize)
{
	/* It is given that the searched-for index i satisfies
	 * 0 < i < arraySize - 1.
	 */
	long lower = 1;
	long upper = arraySize - 2;

	while (lower <= upper) {
		const long middle = lower + (upper - lower) / 2;
		switch (getDirection(array, middle)) {
			case ascend:
				lower = middle + 1;
				break;
			case descend:
				upper = middle - 1;
				break;
			case peak:
				return middle;
			/* The following cases should never occur. */
			case lost:
				return -1;
		}
	}

	/* We should never get here. */
	return -1;
}

/* Requires: 0 < index < array length - 1 */
enum direction getDirection(int *array, long index)
{
	const int leftSlope = cmpInt(array[index], array[index - 1]);
	const int rightSlope = cmpInt(array[index + 1], array[index]);

	if (leftSlope > 0 && rightSlope > 0)
		return ascend;
	else if (leftSlope > 0 && rightSlope < 0)
		return peak;
	else if (leftSlope < 0 && rightSlope < 0)
		return descend;
	/* The following case should never occur. */
	else
		return lost;
}

/* cmpInt(a, b) is 1 if a > b, 0 if a == b, and -1 if a < b.
 * In terms of negative/zero/positive it is therefore the same as a - b,
 * but this function is safe from overflows. */
int cmpInt(int a, int b)
{
	return (a > b) - (a < b);
}
