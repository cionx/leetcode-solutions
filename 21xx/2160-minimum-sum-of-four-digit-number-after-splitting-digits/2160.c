/* 2160. Minimum Sum of Four Digit Number after Splitting Digits. */

/* Idea.
 * Choose the two least digits as the leading digits, and the two greatest
 * digits as the trailing digits. Note that for the sum, it doesn’t matter how
 * we pair up the leading digits with the trailing digits.
 *
 * I don’t know if this will always give the correct result. */

#include <stdlib.h>

int minimumSum(int num);
int cmpInt(const void *vpa, const void *vpb);

int minimumSum(int num)
{
	int digits[4];
	for (int i = 0; i < 4; ++i) {
		digits[i] = num % 10;
		num /= 10;
	}

	qsort(digits, 4, sizeof(int), cmpInt);

	int num1 = 10 * digits[0] + digits[2];
	int num2 = 10 * digits[1] + digits[3];

	return num1 + num2;
}

int cmpInt(const void *vpa, const void *vpb)
{
	const int *pa = (const int *) vpa;
	const int *pb = (const int *) vpb;

	return (*pa > *pb) - (*pa < *pb);
}
