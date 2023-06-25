/* 2. Add Two Numbers */

/* Complexities.
 * Time: O(n + m)
 * Space: O(1)
 * where n and m are the lengths of the two input arrays respectively. */

#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LNode;

/* Main functions */
LNode *addTwoNumbers(LNode *l1, LNode *l2);
LNode *createHead(LNode **l1, LNode **l2, int *carry);
LNode *addValues(LNode *l1, LNode *l2, int *carry);
LNode *addCarry(LNode *l, int *carry);
/* Auxiliary functions */
LNode *makeNode(int value);
LNode *addToValue(LNode *l, int add, int *carry);

/* MAIN FUNCTIONS */

LNode *addTwoNumbers(LNode *l1, LNode *l2)
{
	LNode *head, *tail;
	int carry;
	head = tail = NULL;

	if (l1 == NULL && l2 == NULL)
		return head;
	head = tail = createHead(&l1, &l2, &carry);

	while (l1 != NULL && l2 != NULL) {
		tail = (tail->next = addValues(l1, l2, &carry));
		l1 = l1->next;
		l2 = l2->next;
	}
	LNode *rest = (l1 != NULL) ? l1 : l2;
	while (rest != NULL) {
		tail = (tail->next = addCarry(rest, &carry));
		rest = rest->next;
	}
	if (carry != 0)
		tail->next = makeNode(carry);

	return head;
}

LNode *createHead(LNode **pl1, LNode **pl2, int *carry)
{
	int digit;
	const LNode *l1 = *pl1;
	const LNode *l2 = *pl2;

	if (l1 != NULL && l2 != NULL) {
		digit = l1->val + l2->val;
		*carry = digit / 10;
		digit %= 10;
		*pl1 = l1->next;
		*pl2 = l2->next;
	}
	else if (l1 != NULL) {
		digit = l1->val;
		*carry = 0;
		*pl1 = l1->next;
	}
	else {
		digit = l2->val;
		*carry = 0;
		*pl2 = l2->next;
	}
	return makeNode(digit);
}

LNode *addValues(LNode *l1, LNode *l2, int *carry)
{
	int digit = l1->val + l2->val + *carry;
	*carry = digit / 10;
	digit %= 10;
	return makeNode(digit);
}

LNode *addCarry(LNode *l, int *carry)
{
	int digit = l->val + *carry;
	*carry = digit / 10;
	digit %= 10;
	return makeNode(digit);
}

/* AUXILIARY FUNCTIONS */

LNode *makeNode(int value)
{
	LNode *node = malloc(sizeof(LNode));
	node->val = value;
	node->next = NULL;
	return node;
}
