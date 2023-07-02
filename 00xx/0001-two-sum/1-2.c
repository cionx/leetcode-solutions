/* 1. Two Sum */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(n)
 * where n is the length of the input list. */

#include <stdlib.h>

/* See the first solution for an explanation of the algorithm. */

typedef struct {
	int value;
	int index;
} entry;

int *twoSum(int *nums, int numsSize, int target, int *returnSize);
int cmpEntryFunction(const void *a, const void *b);
int cmpIntFunction(int a, int b);
int binSearch(int lower, int upper, entry entries[], int target);

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	size_t bitSize = (size_t) numsSize * sizeof(entry);
	entry *sorted = malloc(bitSize);
	for (int i = 0; i < numsSize; ++i)
		sorted[i] = (entry){.index = i, .value = nums[i]};
	qsort(sorted, (size_t) numsSize, sizeof(entry), cmpEntryFunction);

	int *result = malloc(2 * sizeof(int));
	result[0] = result[1] = -1;

	int i = 0;
	for (int j = numsSize - 1; i < j; --j) {
		i = binSearch(i, j - 1, sorted, target - sorted[j].value);
		if (sorted[i].value + sorted[j].value == target) {
			result[0] = sorted[i].index;
			result[1] = sorted[j].index;
			break;
		}
	}

	free(sorted);
	*returnSize = 2;
	return result;
}

int binSearch(int lower, int upper, entry entries[], int searchFor)
{
	int middle;

	while (lower < upper) {
		middle = (lower + upper) / 2; /* Always smaller than `upper`. */
		if (entries[middle].value < searchFor)
			lower = middle + 1;
		else
			upper = middle;
	}

	return upper;
}

/* Taken from https://stackoverflow.com/a/27284248/21949339. */
int cmpEntryFunction(const void *a, const void *b)
{
	const entry *A = a, *B = b;
	return cmpIntFunction(A->value, B->value);
}

int cmpIntFunction(int a, int b)
{
	return (a > b) - (a < b);
}
