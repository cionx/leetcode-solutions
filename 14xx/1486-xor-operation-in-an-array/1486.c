/* 1486. XOR Operation in an Array */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the input number of the same name. */

int xorOperation(int n, int start)
{
	unsigned int result = 0;
	for (int i = 0; i < n; ++i) {
		unsigned int number = (unsigned int) (start + 2 * i);
		result ^= number;
	}
	return (int) result;
}
