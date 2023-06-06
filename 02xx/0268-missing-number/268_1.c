#include <stdbool.h>
#include <stdlib.h>

/* Time:  O(n)
 * Space: O(n)
 */
int missingNumber(int* nums, int numsSize){
	bool *found = calloc((size_t) (numsSize + 1), sizeof(bool));

	for (int i = 0; i < numsSize; ++i)
		found[nums[i]] = true;

	int result = -1;
	for (int j = 0; j < numsSize + 1; ++j)
		if (!found[j]) {
			result = j;
			break;
		}

	free(found);
	return result;
}
