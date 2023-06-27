/* 66. Plus One */

/* Complexities.
 * Time: O(n)
 * Space: nearly always O(1)
 *        if all nines: O(n)
 * where n is the length of the input array. */

#include <stdlib.h>
#include <string.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int *result = malloc((size_t) digitsSize * sizeof(int));
	*returnSize = digitsSize;

	int carry = 1;
	for (int i = digitsSize - 1; i >= 0; --i) {
		const int sum = digits[i] + carry;
		result[i] = sum % 10;
		carry = sum / 10;
	}

	if (carry > 0) {
		int *largerResult = malloc(((size_t) digitsSize + 1) * sizeof(int));
		memcpy(largerResult + 1, result, (size_t) digitsSize * sizeof(int));
		free(result);
		result = largerResult;
		result[0] = carry;
		++(*returnSize);
	}

	return result;
}
