#include <stdio.h>
#include <stdlib.h>

/* See the other file for an explanation of the algorithm. */

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

/* Testing */

int main(void)
{
	int nums[] = {3,3};
	int numsSize = 2;
	int target = 6;
	int *returnSize = calloc(1, sizeof(int));

	int *result = twoSum(nums, numsSize, target, returnSize);
	printf("Result: %d %d\n", result[0], result[1]);

	free(returnSize);
	free(result);

	return 0;
}
