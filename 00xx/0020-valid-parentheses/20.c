/* 20. Valid Parentheses */

/* Complexities.
 * Time: O(n)
 * Space: Θ(n)
 * where n is the length of the input array. */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* AUXILIARY STACK FUNCTIONS */

typedef struct {
	char *entries;
	size_t size;
} Stack;

Stack *createStack(size_t size);
void push(Stack *stack, char c);
void pop(Stack *stack);
char lookup(Stack *stack);
size_t stackSize(Stack *stack);
void freeStack(Stack *stack);

Stack *createStack(size_t size)
{
	Stack *stack = malloc(sizeof(Stack));
	stack->entries = malloc(size * sizeof(char));
	stack->size = 0;
	return stack;
}

void push(Stack *stack, char c)
{
	stack->entries[(stack->size)++] = c;
}

void pop(Stack *stack)
{
	--(stack->size);
}

char lookup(Stack *stack)
{
	return stack->entries[stack->size - 1];
}

size_t stackSize(Stack *stack)
{
	return stack->size;
}

void freeStack(Stack *stack)
{
	free(stack->entries);
	free(stack);
}

/* THE MAIN FUNCTIONS */

bool isValid(char *s);
bool isValidAux(char *s, size_t length, Stack *stack);
bool isClosing(char c);
char makeOpening(char c);

bool isValid(char *s)
{
	const size_t length = strlen(s);
	Stack *stack = createStack(length / 2 + 1);
	bool result = isValidAux(s, length, stack);
	freeStack(stack);
	return result;
}

bool isValidAux(char *s, size_t length, Stack *stack)
{
	for (; *s != '\0'; ++s) {
		if (isClosing(*s)) {
			if (stackSize(stack) == 0 || lookup(stack) != makeOpening(*s))
				return false;
			pop(stack);
		}
		else {
			push(stack, *s);
			if (stackSize(stack) > length / 2)
				return false;
		}
	}
	return stackSize(stack) == 0;
}

bool isClosing(char c)
{
	return c == ')' || c == ']' || c == '}';
}

char makeOpening(char c)
{
	switch (c) {
		case ')':
			return '(';
		case ']':
			return '[';
		case '}':
			return '{';
		default:
			return '\0';
	}
}
