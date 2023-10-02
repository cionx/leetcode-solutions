/* 2807. Insert Greatest Common Divisors in Linked List */

#include <stdlib.h>

/* Do not copy this struct definition to LeetCode. */
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode LN;

LN *insertGreatestCommonDivisors(LN *head);
void insertGCDs(LN *head);
LN *makeNode(int val);
int gcd(int a, int b);

LN *insertGreatestCommonDivisors(LN *head)
{
	insertGCDs(head);
	return head;
}

void insertGCDs(LN *head)
{
	if (head == NULL || head->next == NULL)
		return;
	LN *next = head->next;
	LN *newNode = makeNode(gcd(head->val, next->val));
	head->next = newNode;
	newNode->next = next;
	insertGCDs(next);
}

LN *makeNode(int val)
{
	LN *result = malloc(sizeof(LN));
	result->val = val;
	result->next = NULL;
	return result;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
