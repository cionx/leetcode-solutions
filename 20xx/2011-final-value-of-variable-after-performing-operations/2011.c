/* 2011. Final Value After Performing Operations */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

int finalValueAfterOperations(char **operations, int operationsSize)
{
	int x = 0;
	for (int i = 0; i < operationsSize; ++i) {
		if (operations[i][1] == '+') /* Consider the middle character. */
			++x;
		else
			--x;
	}
	return x;
}
