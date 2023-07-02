/* 1295. Find Numbers with Even Number of Digits */

/* Complexities.
 * Time: O(D)
 * Space: O(1)
 * where D is the total number of digits of all elements in the input array. */

int findNumbers(int *nums, int numsSize);
int numberOfDigits(int a);

int findNumbers(int *nums, int numsSize)
{
	int counter = 0;
	for (int i = 0; i < numsSize; ++i)
		if (numberOfDigits(nums[i]) % 2 == 0)
			++counter;
	return counter;
}

int numberOfDigits(int a)
{
	int counter = 0;
	while (a != 0) {
		a /= 10;
		++counter;
	}
	return counter;
}
