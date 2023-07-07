/* 334. Increasing Triplet Subsequence */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

/* Idea.
 * As we go through the list, we keep track of two numbers.
 * - The mimimal value `min` encountered so far.
 * - The minimal value `limit` for which there exist indices i < j with
 *   nums[i] < nums[j] = limit.
 * We claim that there exists an increasing triple if and only if at some point,
 * nums[k] > limit.
 * (->) Suppose that, as we traverse through the list, we encounter an index k
 *      with nums[k] > limit. Then we have i < j with j < k and
 *      nums[i] < nums[j] = limit < nums[k], and therefore the increasing triple
 *      (i, j, k).
 * (<-) Suppose conversely that an increasing triple exist. Let k be the minimal
 *      index for which an increasing triple exist (i, j, k) exist. The indices
 *      i and j satisfy i < j < k and nums[i] < nums[j]. By definition of
 *      `limit` we then have limit <= nums[j]. We therefore have
 *      limit < nums[k].
 * Whenever we meet a new index k, we check the following:
 * - If nums[k] > limit, then return `true`.
 * - If nums[k] <= limit, then we need to replace limit by nums[k] if there
 *   exists an index i with i < k and nums[i] < nums[k]. This is the case if and
 *   only if min < nums[k].
 * - If nums[k] <= min, then we replace min by nums[k].
 */

#include <stdbool.h>

bool increasingTriplet(int *nums, int numsSize)
{
	int min = nums[0];
	int i = 1;
	while (i < numsSize && nums[i - 1] >= nums[i])
		min = nums[i++];
	if (i == numsSize)
		return false;
	int limit = nums[i++];

	for (; i < numsSize; ++i)
		if (limit < nums[i])
			return true;
		else if (min < nums[i])
			limit = nums[i];
		else
			min = nums[i];

	return false;
}
