/* 21. Merge Two Sorted Lists */

/* Iterative solution. */

/* Complexities.
 * Time: O(m + n)
 * Space: O(1)
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
	struct ListNode *result = NULL;

	if (list1 == NULL && list2 == NULL)
		return result;

	/* Handle the first node by hand. */
	if (list2 == NULL || (list1 != NULL && list1->val < list2->val)) {
		result = makeNode(list1->val);
		list1 = list1->next;
	}
	else {
		result = makeNode(list2->val);
		list2 = list2->next;
	}
	struct ListNode *tail = result;

	/* The main loop. */
	while (list1 != NULL && list2 != NULL) {
		if (list1->val < list2->val) {
			tail->next = makeNode(list1->val);
			list1 = list1->next;
		}
		else {
			tail->next = makeNode(list2->val);
			list2 = list2->next;
		}
		tail = tail->next;
	}

	/* The ending loops. Only one of them will run. */
	while (list1 != NULL) {
		tail->next = makeNode(list1->val);
		list1 = list1->next;
		tail = tail->next;
	}
	while (list2 != NULL) {
		tail->next = makeNode(list2->val);
		list2 = list2->next;
		tail = tail->next;
	}

	return result;
}

struct ListNode *makeNode(int value)
{
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->val = value;
	node->next = NULL;

	return node;
}
