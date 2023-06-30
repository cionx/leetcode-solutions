/* 189. Rotate Array */

/* Complexities.
 * Time: Θ(n)
 * Space: O(min(k, n - k))
 * where n is the length of the input array and 0 <= k <= n. */

/* Idea.
 * We split the array into two parts: the head, consisting of n - k entries, and
 * the tail, consisting of k entries. We then swap the positions of the two
 * parts.
 *
 *  *---------------------*          *---------------------*
 *  |     head     | tail |   --->   | tail |     head     |
 *  *---------------------*          *---------------------*
 *
 * We will need some additional memory to prevent issues with overwriting. We
 * can move the larger part with memmove, which takes proper care of the
 * overlap. In this way, we only need to remember the smaller part. */

#include <stdlib.h>
#include <string.h>

void rotate(int *nums, int numsSize, int k)
{
	k %= numsSize;
	/* We need to move the last k entries to the front, in order. */
	const int headLength = numsSize - k;
	const int tailLength = k;
	const size_t headSize = (size_t) headLength * sizeof(int);
	const size_t tailSize = (size_t) tailLength * sizeof(int);
	if (headSize < tailSize) {
		int *head = malloc(headSize);
		memcpy(head, nums, headSize);
		memmove(nums, nums + headLength, tailSize);
		memcpy(nums + tailLength, head, headSize);
		free(head);
	}
	else {
		int *tail = malloc(tailSize);
		memcpy(tail, nums + headLength, tailSize);
		memmove(nums + tailLength, nums, headSize);
		memcpy(nums, tail, tailSize);
		free(tail);
	}
}
