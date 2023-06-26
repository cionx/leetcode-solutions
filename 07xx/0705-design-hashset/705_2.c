/* 705. Design HashSet */

#include <stdbool.h>
#include <stdlib.h>

#define MAX_KEY 1000000

typedef struct {
	unsigned char bits[(MAX_KEY + 1) / 8 + 1];
} MyHashSet;

MyHashSet *myHashSetCreate(void);
void myHashSetAdd(MyHashSet *set, int key);
void myHashSetRemove(MyHashSet *set, int key);
bool myHashSetContains(MyHashSet *set, int key);
void myHashSetFree(MyHashSet *set);

MyHashSet *myHashSetCreate(void)
{
	MyHashSet *set = malloc(sizeof(MyHashSet));
	*set = (MyHashSet) { .bits = {0u} };
	return set;
}

void myHashSetAdd(MyHashSet *set, int key)
{
	int i = key / 8;
	key %= 8;
	unsigned char mask = (unsigned char) (~(~0u << 1) << key);
	set->bits[i] |= mask;
}

void myHashSetRemove(MyHashSet *set, int key)
{
	int i = key / 8;
	key = key % 8;
	unsigned char mask = (unsigned char) ~(~(~0u << 1) << key);
	set->bits[i] &= mask;
}

bool myHashSetContains(MyHashSet *set, int key)
{
	int i = key / 8;
	key %= 8;
	return ((set->bits[i]) >> key) & ~(~0u << 1);
}

void myHashSetFree(MyHashSet *set)
{
	free(set);
}
