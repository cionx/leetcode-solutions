/* 21. Merge Two Sorted Lists */

/* Recursive solution. */

/* Complexities.
 * Time: O(m + n)
 * Space: O(m + n)
 * where m and n are the lenghts of the input arrays respectively. */

#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2);
struct ListNode *makeNode(int value);

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
	if (list1 == NULL && list2 == NULL)
		return NULL;

	int value;
	if (list2 == NULL ||
	    (list1 != NULL && list2 != NULL && list1->val <= list2->val)) {
		value = list1->val;
		list1 = list1->next;
	}
	else {
		value = list2->val;
		list2 = list2->next;
	}
	struct ListNode *node = makeNode(value);
	node->next = mergeTwoLists(list1, list2);
	return node;
}

struct ListNode *makeNode(int value)
{
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->val = value;
	node->next = NULL;

	return node;
}
