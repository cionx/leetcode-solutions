/* 338. Counting Bits */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the input number. */

/* Note.
 * The the first solution for an explanation of the algorithm. */

#include <stdlib.h>
#include <string.h>

int *countBits(int n, int *returnSize)
{
	int *result = malloc(((size_t) n + 1) * sizeof(int));
	*returnSize = n + 1;

	int i = 0;

	/* Special case 0. */
	result[i++] = 0;
	if (n <= 0)
		return result;

	/* Special case 1. */
	result[i++] = 1;

	/* Full iterations. */
	while (2 * i - 1 <= n) {
		const int prevBlockStart = i / 2;
		const int prevBlockLimit = i; /* Non-inclusive. */
		const int prevBlockWidth = i / 2;
		/* Copy the previous block. */
		memcpy(result + i, result + prevBlockStart,
		       (size_t) prevBlockWidth * sizeof(int));
		i += i / 2;
		/* The previous block plus 1. */
		for (int j = prevBlockStart; j < prevBlockLimit; ++j)
			result[i++] = result[j] + 1;
	}

	/* Remaining partial iteration. */
	/*   Copy the previous block. */
	const int prevBlockStart = i / 2;
	const int prevBlockWidth = i / 2;
	int remaining = n - i + 1;
	int width = (remaining < prevBlockWidth) ? remaining : prevBlockWidth;
	memcpy(result + i, result + prevBlockStart, (size_t) width * sizeof(int));
	i += width;
	/*   The previous block plus 1. */
	remaining = n - i + 1;
	width = (remaining < prevBlockWidth) ? remaining : prevBlockWidth;
	int limit = prevBlockStart + width;
	for (int j = prevBlockStart; j < limit; ++j)
		result[i++] = result[j] + 1;

	return result;
}
