/* 1721. Swapping Nodes in a Linked List */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LN;

LN *swapNodes(LN *head, int k);
int length(LN *list);

LN *swapNodes(LN *head, int k)
{
	LN *node1, *node2, *prevNode1, *prevNode2;
	prevNode1 = prevNode2 = NULL;
	const int len = length(head);
	/* We guarantee that the k-to node is in the first half of hte list. */
	if (k > len / 2) {
		k = len - k + 1;
	}
	/* If the list is of odd length we are need to swap the midpoint with
	 * itself, then we do nothing.*/
	if (len % 2 == 1 && 2 * k - 1 == len)
		return head;

	int position = 1;
	LN *searcher = head;
	/* prevNode1 */
	while (position < k - 1) {
		searcher = searcher->next;
		++position;
	}
	if (k > 1) {
		prevNode1 = searcher;
		/* node1 */
		searcher = searcher->next;
		++position;
	}
	node1 = searcher;
	/* prevNode2 */
	while (position < len - k) {
		searcher = searcher->next;
		++position;
	}
	if (len != 1) {
		prevNode2 = searcher;
		/* node2 */
		searcher = searcher->next;
		++position;
	}
	node2 = searcher;

	if (prevNode1 != NULL)
		prevNode1->next = node2;
	if (prevNode2 != NULL)
		prevNode2->next = node1;
	LN *tmp = node1->next;
	node1->next = node2->next;
	node2->next = tmp;

	return (k != 1) ? head : node2;
}

int length(LN *list)
{
	int length = 0;
	while (list != NULL) {
		++length;
		list = list->next;
	}
	return length;
}
