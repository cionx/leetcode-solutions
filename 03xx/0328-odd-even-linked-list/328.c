/* 328. Odd Even Linked List */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdlib.h>

/* Do not copy the below struct definition of ListNode to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LN;

LN *oddEvenList(LN *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	LN *heads[2] = {head->next, head};
	LN *tails[2] = {head->next, head};
	LN *current = head->next;
	int parity = 0;
	while ((current = current->next) != NULL) {
		parity = 1 - parity;
		tails[parity]->next = current;
		tails[parity] = current;
	}

	tails[1]->next = heads[0];
	tails[0]->next = NULL;
	return heads[1];
}
