/* Time: O(log(n))
 * Space O(1)       */

/**
 * int guess(int num);
 * -1 if num is higher than the picked number
 *  1 if num is lower than the picked number
 *  0 otherwise
 */
int guess(int num);

int guessNumber(int n)
{
	int lower = 0;
	int upper = n;
	while (lower <= upper) {
		const int middle = lower + (upper - lower) / 2;
		switch (guess(middle)) {
			case 1:
				lower = middle + 1;
				break;
			case -1:
				upper = middle - 1;
				break;
			case 0:
				return middle;
			/* We should never get the default case. */
			default:
				return -1;
		}
	}

	/* The game is rigged! */
	return -1;
}
