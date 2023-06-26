/* 1979. Find Greatest Common Divisor of Array */

/* Complexities.
 * Time: O(n + log(max))
 * Space: O(1)
 * where n is the length of the input array and max is the maximum of the input
 * array. (The euclidian algorithm with division and remainder needs O(log(a))
 * to compute gcd(a, b) with a >= b. See https://en.wikipedia.org/wiki/
 * Euclidean_algorithm#Worst-case for more details.)  */

int findGCD(const int *nums, int numsSize);
int gcd(int a, int b);

int findGCD(const int *nums, int numsSize)
{
	int min = nums[0];
	int max = nums[0];

	for (int i = 1; i < numsSize; ++i) {
		if (nums[i] > max)
			max = nums[i];
		else if (nums[i] < min)
			min = nums[i];
	}

	return gcd(min, max);
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
