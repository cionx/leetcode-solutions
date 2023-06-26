/* 509. Fibonacci Number */

/* Recursive solution. */

/* Complexity.
 * Time: O(n)
 * Space: O(n)
 * where n is the input number. */

#include <stdlib.h>

int fib(int n);
int fibMemo(int n, int *cache);

int fib(int n)
{
	int *cache = calloc((size_t) n + 1, sizeof(int));
	int result = fibMemo(n, cache);
	free(cache);
	return result;
}

int fibMemo(int n, int *cache)
{
	if (n <= 1)
		return n;
	if (cache[n] != 0)
		return cache[n];
	const int value = fibMemo(n - 1, cache) + fibMemo(n - 2, cache);
	cache[n] = value;
	return value;
}
