/* 338. Counting Bits */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the input number. */

/* Idea.
 * The number of 1s in the binary representation of 2^{n+1}, ..., 2^{n+2} - 1 is
 * always one larger than the number of 1s in the binary representation of
 * 0, ..., 2^{n+1} - 1. We can therefore compute the values in chunks:
 *
 *  0
 *
 *  0 [0]+1
 *  0  1
 *
 *  0 1 [0 1]+1
 *  0 1  1 2
 *
 *  0 1 1 2 [0 1 1 2]+1
 *  0 1 1 2  1 2 2 3
 *
 *  0 1 1 2 1 2 2 3 [0 1 1 2 1 2 2 3]+1
 *  0 1 1 2 1 2 2 3  1 2 2 3 2 3 3 4
 *
 * We will first do all full iterations, as depicted above, and then the
 * remaining partial iteration. */

/* Note.
 * We could further reduce our computations by using that the first half of a
 * new block is equal to the previously added block. We have chosen to keep our
 * code simple instead. Instead, we write this optimized version in a second
 * solution. Here, by “blocks” means mean the following subarrays:
 *
 *  | 0 | 1 | 1 2 | 1 2 2 3 | 1 2 2 3 2 3 3 4 |
 */

#include <stdlib.h>

int *countBits(int n, int *returnSize)
{
	int *result = malloc(((size_t) n + 1) * sizeof(int));

	int i = 0;
	result[i++] = 0;
	/* Full iterations. */
	while (2 * i - 1 <= n)
		for (int j = 0, limit = i; j < limit; ++j)
			result[i++] = result[j] + 1;
	/* Remaining partial iteration. */
	for (int j = 0; i <= n; ++j)
		result[i++] = result[j] + 1;

	*returnSize = n + 1;
	return result;
}
