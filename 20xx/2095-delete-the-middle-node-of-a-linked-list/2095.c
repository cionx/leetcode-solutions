/* 2095. Delete the Middle Node of a Linked List */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length  of the input linked list. */

/* Idea.
 * Use a two-pointer approach to find the middle node. As the slow pointer moves
 * from the original head to the middle node, we also remember the node just
 * before the slow pointer. */

#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *deleteMiddle(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return NULL;
	/* We now have at least two nodes. This streamlines the following code. */

	struct ListNode *beforeSlow = NULL;
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast->next != NULL) {
		fast = fast->next;
		beforeSlow = slow;
		slow = slow->next;
		if (fast->next != NULL)
			fast = fast->next;
	}

	/* We have at least one loop iteration, so beforeSlow is non-NULL. Also,
	 * slow is non-NULL since fast is non-NULL. */
	beforeSlow->next = slow->next;
	return head;
}
