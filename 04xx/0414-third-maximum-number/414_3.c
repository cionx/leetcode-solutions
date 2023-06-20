/* 414. Third Maximum Number */

/* Complexity.
 * Time: O(n log(n))
 * Space: O(n)
 * where n is the length of the input list. */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int thirdMax(int *nums, int numsSize);
int cmpInt(const void *pa, const void *pb);

int thirdMax(int *nums, int numsSize)
{
	size_t size = (size_t) numsSize * sizeof(int);
	int *sorted = malloc(size);
	memcpy(sorted, nums, size);
	qsort(sorted, (size_t) numsSize, sizeof(int), cmpInt);

	int max = sorted[0];
	/* First maximum number. */
	int i = 0;
	int current = sorted[0];
	/* Second maximum number. */
	while (i < numsSize && sorted[i] == current)
		++i;
	if (i == numsSize) {
		free(sorted);
		return max;
	}
	current = sorted[i];
	/* Third maximum number. */
	while (i < numsSize && sorted[i] == current)
		++i;
	if (i == numsSize) {
		free(sorted);
		return max;
	}
	max = sorted[i];
	free(sorted);
	return max;
}

int cmpInt(const void *pa, const void *pb)
{
	const int *a = (const int *) pa;
	const int *b = (const int *) pb;
	return (*a < *b) - (*a > *b); /* To sort in descending order. */
}
