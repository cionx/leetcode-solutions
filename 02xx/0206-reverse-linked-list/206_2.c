/* Iterative solution, in-place.
 *
 * Time: O(n)
 * Space: O(1)
 *
 * where n is the length of the list.
 */

#include <stdlib.h> /* for NULL */

/* Do not copy the following struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

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
 *  (next loop iteration)
 *
 *  NULL <-- * <-- * <-- * <-- *     * --> … --> * --> NULL
 *                            prev  head
 */

struct ListNode *reverseList(struct ListNode *head)
{
	struct ListNode *prevReversed = NULL;

	while (head != NULL) {
		struct ListNode *next = head->next;
		head->next = prevReversed;
		prevReversed = head;
		head = next;
	}

	return prevReversed;
}
