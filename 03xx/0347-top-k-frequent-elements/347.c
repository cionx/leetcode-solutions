/* 347. Top K Frequent Elements */

/* Complexities.
 * Time: O(n k)
 * Space: O(UPPER - LOWER)
 * where n is the length of the input array and k is as in the problem
 * statement. */

/* Note.
 * This solution can be greatly improved with heaps. I’ll have to revisit this
 * problem once I’ve learned how to implement heaps. */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LOWER -100000
#define UPPER 100000

int *topKFrequent(int *nums, int numsSize, size_t k, int *returnSize);
bool elementIn(int number, int array[], size_t arraySize);

int *topKFrequent(int *nums, int numsSize, size_t k, int *returnSize)
{
	size_t size = (size_t) (UPPER - LOWER + 1);

	int *freq = calloc(size, sizeof(int));
	for (int i = 0; i < numsSize; i++)
		freq[nums[i] - LOWER]++;

	int *mostFrequent = calloc(k, sizeof(int));
	memset(mostFrequent, LOWER - 1, k);
	int *mostFrequencies = calloc(k, sizeof(int));
	memset(mostFrequencies, 0, k);

	for (int i = 0; i < numsSize; i++) {
		int num = nums[i];
		int f = freq[num - LOWER];
		if (f > mostFrequencies[0] && !elementIn(num, mostFrequent, k)) {
			int j = 0;
			while (j + 1 < (int) k && f > mostFrequencies[j + 1]) {
				mostFrequent[j] = mostFrequent[j + 1];
				mostFrequencies[j] = mostFrequencies[j + 1];
				j++;
			}
			mostFrequent[j] = num;
			mostFrequencies[j] = f;
		}
	}

	free(freq);
	free(mostFrequencies);
	*returnSize = (int) k;
	return mostFrequent;
}

bool elementIn(int number, int array[], size_t arraySize)
{
	for (int i = 0; (size_t) i < arraySize; i++)
		if (number == array[i])
			return true;
	return false;
}
