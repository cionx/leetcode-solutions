/* Recursive solution
 *
 * Time: O(n)
 * Space: without tail recursion elimination: O(n)
 *           with tail recursion elimination: O(1)
 *
 * where n is length of input list.
 */

#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/* Do not copy the above struct definition to LeetCode. */

struct ListNode *reverseKGroup(struct ListNode *head, int k);
struct ListNode *helper(struct ListNode *linkStart, struct ListNode *linkEnd,
                        struct ListNode *head, int l, int k);
bool groupEnd(struct ListNode *head, int k);

/* We have an auxiliary function h(linkStart, linkEnd, head, l, k) which
 * returns the concatination of the following three lists:
 *
 *   - the reverse of the first l many entries of head
 *   - the list linkStart --> ... --> linkEnd
 *   - the k-group reverse of the rest of head
 *
 * The recursion works as follows:
 *
 *         b1     --> ... -->   bn    |  a1  --> a2  --> ... --> al --> rest
 *      linkStart             linkEnd | head
 *
 *         b1     --> ... -->   bn    |  a1    a2  --> ... --> al --> rest
 *      linkStart             linkEnd | head  next
 *
 *       a1  -->    b1     --> ... -->   bn    |  a2  --> ... --> al --> rest
 *      head     linkStart             linkEnd | next
 *
 *    [recursive call to helper]
 *
 *         a1     --> b1 --> ... -->   bn    |  a2  --> ... --> al --> rest
 *      linkStart                    linkEnd | head
 *      [-------------part-1---------------]   [------part-2-----]    [part-3]
 *
 *    [this recursive call to helper eventually returns the following list]
 *
 *      al --> ... --> a2 --> a1 --> b1 --> ... --> bn --> k-reversed rest
 *      [---2-reversed--]     [------1-unchanged-----]     [--3-reversed-]
 *
 *    [this list is also the correct return value for the original helper call]
 *
 * Base case if l is 0:
 *
 *       b1      -->  ...  -->    bk     |  rest
 *    linkStart                 linkEnd  |  head
 *
 *    (recursive call to reverseKGroup)
 *
 *       b1      -->  ...  -->    bk     |  k-reversed rest
 *    linkStart                 linkEnd  |     recResult
 *
 *       b1      -->  ...  -->    bk     -->  k-reversed rest
 *    linkStart                 linkEnd          recResult
 *
 */

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	if (!groupEnd(head, k) || head == NULL)
		return head;

	return helper(head, head, head->next, k - 1, k);
}

struct ListNode *helper(struct ListNode *linkStart, struct ListNode *linkEnd,
                        struct ListNode *head, int l, int k)
{
	if (l == 0) {
		struct ListNode *recResult = reverseKGroup(head, k);
		linkEnd->next = recResult;
		return linkStart;
	}

	struct ListNode *next = head->next;
	head->next = linkStart;
	return helper(head, linkEnd, next, l - 1, k);
}

bool groupEnd(struct ListNode *head, int k)
{
	if (k == 0)
		return true;
	if (head == NULL)
		return false;
	return groupEnd(head->next, k - 1);
}
