/* 189. Rotate Array */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * By rotating the array, we are permuting its entry. Moreover, this permutation
 * consists of cycles of the following form:
 * nums[0]  <--  nums[-k]  <--  nums[-2 k]  <-- ...  <--  nums[k]  <--  nums[0]
 * The number of circles is g := gcd(k, numsSize), and a set of representatives
 * for the cycles is given by 0, 1, ..., g - 1. */

#include <stdint.h>

void rotate(int *nums, int numsSize, int k);
int gcd(int a, int b);

void rotate(int *nums, int numsSize, int k)
{
	k %= numsSize;
	int g = gcd(k, numsSize);

	int_fast32_t current, next, prev; /* 16 bits are not enough */
	while (--g >= 0) {
		current = g;
		const int cycleStart = nums[current];
		do {
			prev = (current - k + numsSize) % numsSize;
			nums[current] = nums[prev];
			current = prev;
		} while (current != g);
		next = (current + k + numsSize) % numsSize;
		nums[next] = cycleStart;
	}
}

int gcd(int a, int b)
{
	while (b > 0) {
		const int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
