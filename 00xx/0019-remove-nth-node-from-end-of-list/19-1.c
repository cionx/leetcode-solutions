/* 19. Remove Nth Node From End of List */

/* Two passes solution. */

/* Complexities.
 * Time: O(l)
 * Space: O(1)
 * where l is the length of the input list. */

#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LN;

LN *removeNthFromEnd(struct ListNode *head, int n)
{
	int length = 0;
	for (LN *current = head; current != NULL; current = current->next)
		++length;

	const int position = length - n + 1;
	if (position == 1)
		return head->next;

	int prevPosition = position - 1;
	LN *prev = head;
	while (--prevPosition > 0)
		prev = prev->next;
	const LN *target = prev->next;
	prev->next = target->next;

	return head;
}
