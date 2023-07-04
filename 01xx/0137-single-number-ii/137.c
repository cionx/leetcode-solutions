/* 137. Single Number II */

/* Complexities.
 * Time. O(b n)
 * Space: O(b)
 * where n is the length of the input list and b is the number of bits used to
 * represent the input integers. For the sake of this exercise, it is set at 32.
 *
 * This doesn’t actually solve the exercise, but I’m afraid LeetCode thinks it
 * does. */

/* Idea.
 * We look at the first binary digit of each number, and count how many 0s and
 * 1s we have. We note that one the two amounts must be a multiple of three,
 * while the other one will be congruent 1 modulo 3. The second group will be
 * the one holding the searched-for number. We have thus determined the first
 * digit of the searched-for number. By iterating over all digits, we can
 * reconstruct the entire number.
 *
 * We formulate our code purely in terms of bitwise operations to ensure that it
 * does not depend on how negative numbers are represented. We only assume that
 * - 0 is represented as all 0s, and that
 * - 1 is represented as 0s followed by a single 1. */

#define INT_WIDTH 32

int singleNumber(int *nums, int numsSize)
{
	/* The entries of bitCounter are unsigned to support shifting. */
	unsigned int bitCounter[INT_WIDTH] = {0};

	for (int i = 0; i < numsSize; ++i) {
		int n = nums[i];
		for (int b = 0; b < INT_WIDTH; ++b, n >>= 1)
			bitCounter[b] += n & 1;
	}
	int result = 0;
	for (int b = 0; b < INT_WIDTH; ++b)
		result |= (bitCounter[b] % 3) << b;

	return result;
}
