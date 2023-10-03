/* 2396. Strictly Palindromic Number */

/* Complexities.
 * Time: Θ(1)
 * Space: Θ(1) */

/* Idea.
 * It follows for n ≥ 5 that the number n is represented in base n - 2 (≥ 3) by
 * the two digits 1 2. Therefore, n is not strictly palindromic. The number 4 is
 * also not strictly palindromic. There hence exist no strictly palindromic
 * number. */

#include <stdbool.h>

bool isStrictlyPalindromic(int n)
{
	return false;
}
