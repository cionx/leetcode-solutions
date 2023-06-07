#include <stdio.h>

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
