/* 19. Remove Nth Node From End of List */

/* One pass solution. */

/* Complexities.
 * Time: O(l)
 * Space: O(n)
 * where l is the length of the input list, and we are removing the n-th node
 * from the end of the input list. */

/* Idea.
 * As we traverse through the list we are keeping track of the last (n + 1)
 * visited nodes in a circular array. */

#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LN;

LN *removeNthFromEnd(struct ListNode *head, int n)
{
	/* We use calloc to initialize all pointers as NULL. */
	int cacheSize = n + 1;
	LN **prevs = calloc((size_t) cacheSize, sizeof(LN *));
	int position = 0;

	for (LN *current = head; current != NULL; current = current->next) {
		prevs[position] = current;
		position = (position + 1) % cacheSize;
	}

	LN *beforeTarget = prevs[position];
	LN *target = prevs[(position + 1) % cacheSize];
	if (beforeTarget == NULL) {
		free(prevs);
		return head->next;
	}
	beforeTarget->next = target->next;
	free(prevs);
	return head;
}
