/* 707. Design Linked List */

#include <stdlib.h>

/* AUXILIARY NODE CLASS */

typedef struct Node {
	int val;
	struct Node *next;
} Node;

Node *makeNode(int val);

Node *makeNode(int val)
{
	Node *result = malloc(sizeof(Node));
	result->val = val;
	result->next = NULL;
	return result;
}

/* THE LINKED LIST CLASS */

typedef struct {
	Node *head;
} MyLinkedList;

/* Auxiliary functions. */

Node *getTail(MyLinkedList *list);
Node *getNodeAtIndex(MyLinkedList *list, int index);

Node *getTail(MyLinkedList *list)
{
	if (list == NULL)
		return NULL;
	Node *node = list->head;
	while (node->next != NULL)
		node = node->next;
	return node;
}

Node *getNodeAtIndex(MyLinkedList *list, int index)
{
	Node *node = list->head;
	while (node != NULL && index > 0) {
		node = node->next;
		--index;
	}
	if (node == NULL)
		return NULL;
	return node;
}

/* Mandatory functions. */

MyLinkedList *myLinkedListCreate(void);
void myLinkedListFree(MyLinkedList *list);
void myLinkedListDeleteAtIndex(MyLinkedList *list, int index);
void myLinkedListAddAtIndex(MyLinkedList *list, int index, int val);
void myLinkedListAddAtTail(MyLinkedList *list, int val);
void myLinkedListAddAtHead(MyLinkedList *list, int val);
int myLinkedListGet(MyLinkedList *list, int index);

MyLinkedList *myLinkedListCreate(void)
{
	MyLinkedList *result = malloc(sizeof(MyLinkedList));
	result->head = NULL;
	return result;
}

int myLinkedListGet(MyLinkedList *list, int index)
{
	Node *node = getNodeAtIndex(list, index);
	if (node == NULL)
		return -1;
	return node->val;
}

void myLinkedListAddAtHead(MyLinkedList *list, int val)
{
	Node *newHead = makeNode(val);
	newHead->next = list->head;
	list->head = newHead;
}

void myLinkedListAddAtTail(MyLinkedList *list, int val)
{
	/* For an empty list, adding at the tail is the same as adding at the head.
	 */
	if (list->head == NULL) {
		myLinkedListAddAtHead(list, val);
		return;
	}
	/* For a nonempty list, the tail be will non-NULL. */
	Node *tail = getTail(list);
	Node *newTail = makeNode(val);
	tail->next = newTail;
}

void myLinkedListAddAtIndex(MyLinkedList *list, int index, int val)
{
	/* Adding at index 0 means adding as the new head. */
	if (index == 0) {
		myLinkedListAddAtHead(list, val);
		return;
	}
	/* For the more general case we need to find the node at the previous,
	 * i.e., (index - 1)-th position. */
	Node *prev = getNodeAtIndex(list, index - 1);
	if (prev == NULL)
		return;
	Node *after = prev->next;
	Node *newNode = makeNode(val);
	prev->next = newNode;
	newNode->next = after;
}

void myLinkedListDeleteAtIndex(MyLinkedList *list, int index)
{
	/* Deleting at index 0 means deleting the head. This amounts to shifting the
	 * head of the list by one. */
	if (index == 0) {
		Node *head = list->head;
		list->head = head->next;
		free(head);
		return;
	}
	/* For the more general case we need to find the node at the previous,
	 * i.e., (index - 1)-th position. */
	Node *prev = getNodeAtIndex(list, index - 1);
	if (prev == NULL)
		return;
	Node *toDelete = prev->next;
	if (toDelete == NULL) /* If we try to delete one past the tail. */
		return;
	Node *after = toDelete->next;
	free(toDelete);
	prev->next = after;
}

void myLinkedListFree(MyLinkedList *list)
{
	/* First free all the nodes. */
	Node *curNode = list->head;
	while (curNode != NULL) {
		Node *nextNode = curNode->next;
		free(curNode);
		curNode = nextNode;
	}
	/* Then free the list itself. */
	free(list);
}

/* FOR TESTING ONLY, do not copy to LeetCode. */

#include <stdio.h>

void printList(MyLinkedList *list);

void printList(MyLinkedList *list)
{
	Node *node = list->head;
	if (node == NULL) {
		printf("(empty)\n");
		return;
	}
	printf("%d", node->val);
	while ((node = node->next) != NULL)
		printf(" -> %d", node->val);
	printf("\n");
}

int main(void)
{
	MyLinkedList *list = myLinkedListCreate();
	printList(list);

	myLinkedListAddAtHead(list, 1);
	printList(list);

	myLinkedListAddAtTail(list, 3);
	printList(list);

	myLinkedListAddAtIndex(list, 1, 2);
	printList(list);

	printf("Position %d: %d\n", 1, myLinkedListGet(list, 1));

	myLinkedListDeleteAtIndex(list, 1);
	printList(list);

	printf("Position %d: %d\n", 1, myLinkedListGet(list, 1));

	myLinkedListFree(list);

	return 0;
}
