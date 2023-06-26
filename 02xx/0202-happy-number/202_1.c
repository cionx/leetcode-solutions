/* 202. Happy Number */

/* Complexities.
 * Time: O(extremly fast)
 * Space: O(1)
 * Regarding the complexity: we need to get below 100, and after that we have at
 * most a fixed number of further loop iterations, and thus only O(1) additional
 * steps. To get below 100 we are basically taking repeated logarithms, as
 * 81 d ≈ 81 log10(n), where d is the number of digits of n. This process is
 * extremly fast, but I don’t know if there is a closed expression for the
 * resulting running time. (We seem need an inverse for the repeated exponential
 * function x -> a^x -> a^(a^x) -> a^(a^(a^x)), so in inverse to some kind of
 * arrow function. */

#include <stdbool.h>

int square(int a);
int happyValue(int n);
bool isHappy(int n);

/* Note: a d-digit number has a happy value of at most 81 * d. Numbers with one
 * or two digits may grow larger at first, but already for three-digit numbers,
 * the maximal happy value is 243. Going downwards from 243, one can check that
 * by trial-and-error that 99 is the largest number who’s happy value is larger
 * than the number itself. In other words: for every start value n, we will
 * eventually land in the interval [1, 99].
 *
 * If we have been in this interval 100 times, then we know for sure that we
 * have repeated a value, and must therefore be trapped in a cycle. (We could
 * also use a more careful analysis: we could count the longest cycle one can
 * find in [1, 99], or do manual checks for specific values once the happy value
 * becomes small enough.)
 */

bool isHappy(int n)
{
	if (n <= 0)
		return false;

	int smaller100 = 0;
	for (n = happyValue(n); n > 1; n = happyValue(n)) {
		smaller100 += n < 100;
		if (smaller100 == 100)
			return false;
	}

	return true;
}

int happyValue(int n)
{
	int sum;
	for (sum = 0; n > 0; n /= 10)
		sum += square(n % 10);
	return sum;
}

int square(int a)
{
	return a * a;
}
