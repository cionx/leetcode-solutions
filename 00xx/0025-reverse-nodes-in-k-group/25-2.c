/* 25. Reverse Nodes in k-Group */

/* Iterative solution. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is length of input list.
 */

#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/* Do not copy the above struct definition to LeetCode. */

/* Intuition:
 *
 *
 *  (before the loop)
 *
 *         ...       -->    a1 <-- a2     a3 --> a4 --> ... --> ak     -->   ...
 *           |               |      |      |      |              |
 *      prevRevEnd         start  prev  current next            end
 *
 *  (after the loop)
 *
 *         ...       -->    a1 <-- a2 <-- a3     a4 --> ... --> ak     -->   ...
 *           |               |      |      |      |              |
 *      prevRevEnd         start  prev  current next            end
 *
 *  [previous-k-groups]    [--------------current-k-group---------]       [rest]
 */

struct ListNode *reverseKGroup(struct ListNode *head, int k);
struct ListNode *groupEnd(struct ListNode *start, int k);
void reverseFirstGroup(struct ListNode *start, int k);

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	struct ListNode *firstGroupEnd = groupEnd(head, k);
	if (firstGroupEnd == NULL)
		return head;

	/* One iteration for each k-group. */
	for (struct ListNode *start = head, *end = firstGroupEnd, *prevEnd = NULL,
	                     *rest = firstGroupEnd->next;
	     end != NULL; prevEnd = start, start = rest, end = groupEnd(rest, k)) {
		rest = end->next; /* Not in the loop, because we need end != NULL. */
		reverseFirstGroup(start, k);
		if (prevEnd != NULL)
			prevEnd->next = end;
		start->next = rest;
	}

	return firstGroupEnd;
}

struct ListNode *groupEnd(struct ListNode *start, int k)
{
	if (k == 1 || start == NULL)
		return start;
	return groupEnd(start->next, k - 1);
}

void reverseFirstGroup(struct ListNode *start, int k)
{
	int l = 2; /* The position in the current k-group (from 1 to k). */
	for (struct ListNode *prev = start, *current = start->next, *next; l <= k;
	     ++l, prev = current, current = next) {
		next = current->next; /* Outside the loop so that != NULL. */
		current->next = prev;
	}
}
