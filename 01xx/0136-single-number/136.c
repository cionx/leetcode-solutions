/* 136. Single Number */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * When xor-ing all numbers together, two equal numbers cancel each other out.
 * We are therefore left with the xor of all numbers that occur an odd number of
 * times. In the gives situation, this is the searched-for number. */

int singleNumber(int *nums, int numsSize)
{
	int result = nums[0];
	for (int i = 1; i < numsSize; ++i)
		result ^= nums[i];
	return result;
}
