/* 1342. Number of Steps to Reduce a Number to Zero */

/* Complexities.
 * Time: O(log(n))
 * Space: Θ(1)
 * where n is the input number. */

int numberOfSteps(int num)
{
	int counter = 0;
	while (num > 0) {
		if (num % 2 == 0)
			num /= 2;
		else
			num -= 1;
		++counter;
	}
	return counter;
}
