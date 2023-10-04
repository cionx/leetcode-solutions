/* 2535. Difference Between Element Sum and Digit Sum of an Array */

/* Complexities.
 * Time: Θ(n log(n))
 * Space: Θ(1)
 * where n is the length of the input array. */

#include <stdlib.h> /* For abs. */

int differenceOfSum(int *nums, int numsSize);
int digitSum(int n);

int differenceOfSum(int *nums, int numsSize)
{
	int sum = 0;  /* Will be at most 4 million, which fits into a 32bit int. */
	int dsum = 0; /* Will also easily fit. */
	for (int i = 0; i < numsSize; ++i) {
		sum += nums[i];
		dsum += digitSum(nums[i]);
	}
	return abs(sum - dsum);
	/* We should always have sum ≥ dsum, so the abs should be unneeded. */
}

/* Determines the sum of all digits of n.
 * Time: Θ(log(n))
 * Space: Θ(1)     */
int digitSum(int n)
{
	int sum = 0;
	while (n > 0) {
		sum += n % 10; /* Add last digit. */
		n /= 10;
	}
	return sum;
}
