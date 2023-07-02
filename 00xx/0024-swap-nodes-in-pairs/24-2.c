/* 24. Swap Nodes in Pairs */

/* Iterative solution. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdlib.h>

/* Don’t copy the struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

/* The general picture:
 * (... prevTail) -> head -> next -> (rest ...) */

struct ListNode *swapPairs(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	/* The eventual return value. It is left unchanged throughout the rest of
	 * the program, but we still need to remember it. */
	struct ListNode *returnHead = head->next;

	/* The first one by hand.*/
	struct ListNode *next = head->next;
	struct ListNode *rest = next->next;
	next->next = head;
	head->next = NULL;
	struct ListNode *prevTail = head;
	/* Afterwards, an automated loop. */
	while ((head = rest) != NULL) {
		next = head->next;
		if (next == NULL) {
			prevTail->next = head;
			break;
		}
		rest = next->next;
		next->next = head;
		head->next = NULL;
		prevTail->next = next;
		prevTail = head;
	}

	return returnHead;
}
