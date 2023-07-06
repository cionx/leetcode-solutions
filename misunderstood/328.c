/* PROBLEM.
 * I misunderstood the question, and grouped together nodes by value instead of index. */

/* 328. Odd Even Linked List */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

/* Idea.
 * 1. If the input list is empty, return an empty list.
 * 2. Otherwise, compute the parity of the first element, and search through the
 *    list for an element of the opposite parity. If no such element exists,
 *    then we leave the list unchanged.
 * 3. Otherwise we start keeping track of two separate linked list. One lists
 *    contains all odd elements of the input list, the other list contails all
 *    even elements.
 * 4. Finally, we link the tail of the odd list to the head of the even list. */

#include <stdlib.h>

/* Do not copy the below struct definition of ListNode to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LN;

LN *oddEvenList(struct ListNode *head);
int modulo(int n, int d);

LN *oddEvenList(LN *head)
{
	/* STEP 1 */
	if (head == NULL)
		return NULL;

	/* STEP 2 */
	LN *heads[2] = {NULL, NULL};
	LN *tails[2] = {NULL, NULL};
	const int headParity = modulo(head->val, 2);
	heads[headParity] = head;
	tails[headParity] = head;
	LN *current = head;
	while ((current = current->next) != NULL) {
		const int parity = modulo(current->val, 2);
		if (parity != headParity)
			break;
		tails[headParity] = current;
	}
	if (current == NULL)
		return head;

	/* STEP 3 */
	heads[1 - headParity] = current;
	tails[1 - headParity] = current;
	while ((current = current->next) != NULL) {
		const int parity = modulo(current->val, 2);
		tails[parity]->next = current;
		tails[parity] = current;
	}

	/* STEP 4 */
	tails[1]->next = heads[0];
	tails[0]->next = NULL;
	return heads[1];
}

int modulo(int n, int d)
{
	const int remainder = n % d;
	return (remainder < 0) ? remainder + d : remainder;
}
