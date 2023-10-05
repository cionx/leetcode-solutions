/* 1290. Convert Binary Number in a Linked List to Integer */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input list. */

#include <stdlib.h>

/* Do not copy this struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

int getDecimalValue(struct ListNode *head)
{
	int result = 0;
	for (; head != NULL; head = head->next) {
		result *= 2;
		result += head->val;
	}
	return result;
}
