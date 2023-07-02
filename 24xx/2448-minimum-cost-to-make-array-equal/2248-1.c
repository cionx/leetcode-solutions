/* 2248. Minimum Cost to Make Array Equal */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(n)
 * where n is the length of the input arrays. */

/* Note.
 * For an explanation of the code, see the accompanying markdown file (that I
 * have yet to write). */

#include <stdlib.h>

typedef struct {
	int number;
	long long amount;
} Entry;

long long minCost(int *nums, int numsSize, int *cost, int costSize);
Entry *zipSorted(int *nums, int *cost, int sameSize);
int cmpByNumber(const void *px, const void *py);
int cmpInt(int a, int b);
int groupTogether(Entry *entries, int entriesSize);
int weightedMedianIndex(Entry *entries, int entriesSize);
long long getTotalCost(int *nums, int *cost, int sameSize, int target);

long long minCost(int *nums, int numsSize, int *cost, int costSize)
{
	Entry *sorted = zipSorted(nums, cost, numsSize);
	int newLength = groupTogether(sorted, numsSize);
	int index = weightedMedianIndex(sorted, newLength);
	if (index == -1) /* This should not happen. */
		return -1;
	const int target = sorted[index].number;
	const long long totalCost = getTotalCost(nums, cost, numsSize, target);
	free(sorted);
	return totalCost;
}

Entry *zipSorted(int *nums, int *cost, int sameSize)
{
	/* Sort the pairs (nums[i], costs[i]) by the first component. */
	Entry *entries = malloc((size_t) sameSize * sizeof(Entry));
	for (int i = 0; i < sameSize; ++i)
		entries[i] = (Entry){.number = nums[i], .amount = cost[i]};
	qsort(entries, (size_t) sameSize, sizeof(Entry), cmpByNumber);
	return entries;
}

int cmpByNumber(const void *px, const void *py)
{
	const Entry *x = (const Entry *) px;
	const Entry *y = (const Entry *) py;
	return cmpInt(x->number, y->number);
}

int cmpInt(int a, int b)
{
	return (a > b) - (a < b);
}

int groupTogether(Entry *entries, int entriesSize)
{
	long long weightedTotal = 0;
	int i, j;
	for (i = 0, j = 0; j < entriesSize; ++i) {
		const int number = entries[j].number;
		for (; j < entriesSize && entries[j].number == number; ++j)
			weightedTotal += entries[j].amount;
		entries[i] = (Entry){.number = number, .amount = weightedTotal};
	}
	return i;
}

int weightedMedianIndex(Entry *entries, int entriesSize)
{
	if (entriesSize == 1)
		return 0;

	int lower = 0;
	int upper = entriesSize - 1;
	const long long totalWeight = entries[entriesSize - 1].amount;
	while (lower < upper) {
		const int middle = lower + (upper - lower - 1) / 2 + 1; /* rounded up */
		const long long leftAmount = entries[middle - 1].amount;
		const long long middleAmount = entries[middle].amount - leftAmount;
		const long long rightAmount = totalWeight - middleAmount - leftAmount;
		if (leftAmount + middleAmount < rightAmount)
			lower = middle + 1;
		else if (leftAmount > middleAmount + rightAmount)
			upper = middle - 1;
		else
			return middle;
	}

	return lower;
}

long long getTotalCost(int *nums, int *cost, int sameSize, int target)
{
	long long totalCost = 0;
	for (int i = 0; i < sameSize; ++i) {
		const int amount =
			(target > nums[i]) ? target - nums[i] : nums[i] - target;
		totalCost += (long long) amount * cost[i];
	}
	return totalCost;
}
