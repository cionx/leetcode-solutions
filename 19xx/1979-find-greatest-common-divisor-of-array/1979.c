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
