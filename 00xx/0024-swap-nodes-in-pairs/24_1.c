/* 24. Swap Nodes in Pairs */

/* Recursive solution. */

/* Complexities.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input list. */

#include <stdlib.h>

/* Don’t copy the struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	if (head == NULL)
		return head;

	struct ListNode *next = head->next;
	if (next == NULL)
		return head;

	head->next = swapPairs(next->next);
	next->next = head;

	return next;
}
