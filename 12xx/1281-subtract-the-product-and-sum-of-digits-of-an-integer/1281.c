/* 1281. Subtract the Product and Sum of Digits of an Integer */

/* Complexities.
 * Time: Θ(log(n))
 * Space: Θ(1) */

#include <stdlib.h>

int subtractProductAndSum(int n)
{
	int sum = 0;
	int product = 1;
	for (; n > 0; n /= 10) {
		int digit = n % 10;
		sum += digit;
		product *= digit;
	}
	return product - sum;
}
