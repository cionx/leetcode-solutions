#include <stdio.h>
#include <stdlib.h>

/* Suppose that nums is sorted and consists of n elements. We try to solve
 * the equation nums[i] + nums[j] = target for two indices i and j with i < j.
 * We observe that every possible j splits the nums into two pieces:
 * - the lower part {i : nums[i] + nums[j] < target} and
 * - the upper part {i : nums[i] + nums[j] >= target }.
 * The upper part is typically the same as {i : nums[i] + nums[j] > target},
 * unless there exists a solution that includes the j that we are currently
 * considering. As j decreases, the lower part grows, while the upper part
 * shrinks:
 *
 * |---------|-----------------------------------------------------*| j = n-1
 *
 * |-----------------------|--------------------------------------*-| j = n-2
 *
 * |--------------------------------|----------------------------*--| j = n-3
 *
 * |---------------------------------------|--------------------*---| j = n-4
 *
 * ...
 *
 * Note that for the given solution (i, j), the index i must be precisely the
 * first element of the upper part determined by j. We can therefore proceed as
 * follows:
 * - Order the given list, and remember the original indices for each entry.
 * - Starting with j = n-1, search the list below the j-th value for the minimal
 *   element of the upper part, using binary search.
 * - Check if this minimal element x is the required value.
 * - If not, then go to j = n-2 and repeat the above steps. This time, search
 *   the list from x to j-1 (inclusive).
 *
 * Ordering the list takes O(n log(n)).
 *
 * For the complexity of the rest of th algorithm, suppose for a moment that
 * instead of binary search, we were simply to count up the value of i. We would
 * then have two pointers, i and j, such that i is repeatedly incremented and j
 * is repeatedly decremented, but only as long as i < j. Every item in the list
 * is visited by a pointer at most once, and each visit leads to the same amount
 * of calculations. We would thus have a complexity of O(n).
 *
 * However, in this alternative version of the algorithm, we are basically
 * searching for a specific entry in a sorted list by iterating through over
 * list. Binary search should hopefully be faster. The exact difference in
 * speed, and if there is one at all, depends on the given data set.
 *
 * We will therefore write two versions of this program: once that uses the
 * naive “iterating upwards” tactic, and one that uses binary search as
 * originally described above. This file contains the first version.
 */

typedef struct {
	int value;
	int index;
} entry;

int *twoSum(int *nums, int numsSize, int target, int *returnSize);
int cmpEntryFunction(const void *a, const void *b);
int cmpIntFunction(int a, int b);

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
		while (sorted[i].value + sorted[j].value < target)
			++i;
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
	int nums[] = {-3, 4, 3, 90};
	int numsSize = 4;
	int target = 0;
	int *returnSize = calloc(1, sizeof(int));

	int *result = twoSum(nums, numsSize, target, returnSize);
	printf("Result: %d %d\n", result[0], result[1]);

	free(returnSize);
	free(result);

	return 0;
}
