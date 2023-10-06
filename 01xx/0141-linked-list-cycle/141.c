/* 141. Linked List Cycle */

/* Complexities.
 * Time: O(n)
 * Space: Θ(1)
 * where n is the length of the input list. */

/* Idea.
 * We use Floyd’s cycle finding algorithm:
 *
 * We go through the list with two pointers of different speed. The slow pointer
 * moves by one node at a time whereas the fast pointer moves by two nodes at a
 * time.
 * - If the list has no cycle then the fast pointer will eventuall arrive at
 *   NULL, in which case we return `false`.
 * - If the list has a cycle, then the slow pointer enters this cycle at some
 *   point in time. The fast pointer is then also already trapped in the cycle.
 *   The fast pointer will then overtake the slow pointer at some future point
 *   in time. As the speed difference between the two pointers is exactly one
 *   node, this will entail that the two pointers meet at some node. We can then
 *   return `true`.
 */

#include <stdbool.h>
#include <stdlib.h>

/* Do not copy this struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	struct ListNode *slow, *fast;
	slow = head;
	if (head == NULL || head->next == NULL)
		return false;
	fast = head->next;

	while (slow != fast) {
		/* Move slow by one. */
		slow = slow->next;
		/* Move fast by two. */
		if (fast->next == NULL)
			return false;
		fast = fast->next;
		if (fast->next == NULL)
			return false;
		fast = fast->next;
	}

	return true;
}
