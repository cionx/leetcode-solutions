/* 206. Reverse Linked List */

/* Recursive solution, in-place. */

/* Complexities.
 * Time: O(n)
 * Space: with tail recursion elimination: O(1)
 *        without tail recursion elimination: O(n)
 * where n is the length of the list.
 */

#include <stdlib.h> /* for NULL */

/* Do not copy the following struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head);
struct ListNode *helper(struct ListNode *prevReversed, struct ListNode *head);

/* Idea:
 *
 *  NULL <-- * <-- * <-- *     * --> * --> … --> * --> NULL
 *                      prev  head
 *
 *  NULL <-- * <-- * <-- *     * --> * --> … --> * --> NULL
 *                      prev  head  next
 *
 *  NULL <-- * <-- * <-- * <-- *     * --> … --> * --> NULL
 *                      prev  head  next
 *
 *  (recursive call to helper)
 *
 *  NULL <-- * <-- * <-- * <-- *     * --> … --> * --> NULL
 *                            prev  head
 */

struct ListNode *reverseList(struct ListNode *head)
{
	return helper(NULL, head);
}

struct ListNode *helper(struct ListNode *prevReversed, struct ListNode *head)
{
	if (head == NULL)
		return prevReversed;

	struct ListNode *next = head->next;
	head->next = prevReversed;
	return helper(head, next);
}
