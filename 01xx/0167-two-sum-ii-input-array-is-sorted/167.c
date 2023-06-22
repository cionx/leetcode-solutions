/* 167. Two Sum II - Input Array is Sorted */

/* Complexities:
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

/* Note.
 * We copy our approach from Problem 1 (Two Sum). */

/* Suppose that nums consists of n elements. We try to solve the equation
 * nums[i] + nums[j] = target for two indices i and j with i < j. We observe
 * that every possible j splits the array nums into two subarrays:
 * - the lower part {i : nums[i] + nums[j] < target} and
 * - the upper part {i : nums[i] + nums[j] >= target}.
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
 * - Starting with j = n-1, search the list below the j-th value for the minimal
 *   element x of the upper part.
 * - Check if x is the required value.
 * - If not, then go to j = n-2 and repeat the above steps. This time, search
 *   the list from x to j-1 (inclusive).
 *
 * We have two pointers, i and j, such that i is repeatedly incremented and j is
 * repeatedly decremented, but only as long as i < j. Every item in the list is
 * visited by a pointer at most once, and each visit leads to the same amount of
 * calculations. We thus have a time complexity of O(n).
 *
 * Instead of repeatedly incrementing i, we could also use binary search. But it
 * is not clear to me how this affects the complexity.
 */

#include <stdlib.h>

int *twoSum(const int *nums, int numsSize, int target, int *returnSize)
{
	int *result = malloc(2 * sizeof(int));
	*returnSize = 2;

	for (int i = 0, j = numsSize - 1; i < j; --j) {
		while (i < j && nums[i] + nums[j] < target)
			++i;
		if (nums[i] + nums[j] == target) {
			result[0] = i + 1;
			result[1] = j + 1;
			return result;
		}
	}

	result[0] = -1;
	result[1] = -1;
	return result;
}
