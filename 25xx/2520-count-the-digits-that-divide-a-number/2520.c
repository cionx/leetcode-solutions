/* 2520. Count the Digits that Divide a Number */

/* Complexities.
 * Time: Θ(d) = Θ(log(n))
 * Space: Θ(1)
 * where d is number of digits of the input integer n. */

#define BASE 10

int countDigits(int num)
{
	int counter = 0;
	for (int n = num; n > 0; n /= BASE) {
		int digit = n % BASE;
		if (digit != 0 && num % digit == 0)
			++counter;
	}
	return counter;
}
