/* 509. Fibonacci Number */

/* Iterative solution. */

/* Complexity.
 * Time: O(n)
 * Space: O(1)
 * where n is the input number. */

int fib(int n)
{
	if (n <= 1)
		return n;

	int prev = 0, cur = 1;
	while (--n > 0) {
		const int tmp = cur;
		cur += prev;
		prev = tmp;
	}

	return cur;
}
