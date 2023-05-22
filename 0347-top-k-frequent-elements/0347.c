#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *topKFrequent(int *nums, int numsSize, size_t k, int *returnSize);
bool elementIn(int number, int array[], size_t arraySize);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *topKFrequent(int *nums, int numsSize, size_t k, int *returnSize) {
	int lower = -100000;
	int upper = 100000;
	size_t size = (size_t)(upper - lower + 1);

	int *freq = calloc(size, sizeof(int));
	for (int i = 0; i < numsSize; i++)
		freq[nums[i] - lower]++;

	int *mostFrequent = calloc(k, sizeof(int));
	memset(mostFrequent, lower - 1, k);
	int *mostFrequencies = calloc(k, sizeof(int));
	memset(mostFrequencies, 0, k);

	for (int i = 0; i < numsSize; i++) {
		int num = nums[i];
		int f = freq[num - lower];
		if (f > mostFrequencies[0] &&
		    !elementIn(num, mostFrequent, k)) {
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

bool elementIn(int number, int array[], size_t arraySize) {
	for (int i = 0; (size_t) i < arraySize; i++)
		if (number == array[i])
			return true;
	return false;
}

/* Don’t copy the following. */

int main(void) {
	int nums[6] = {1, 1, 1, 2, 2, 3};
	size_t k = 2;
	int* returnSize = malloc(sizeof(int));

	int* result = topKFrequent(nums, 6, k, returnSize);
	for (int i = 0; i < *returnSize; i++)
		printf("%d\n", result[i]);

	free(returnSize);
	free(result);
	return 0;
}
