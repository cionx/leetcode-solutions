/* 705. Design HashSet */

#include <stdbool.h>
#include <stdlib.h>

#define MAX_KEY 1000000

typedef struct {
	bool contains[MAX_KEY + 1];
} MyHashSet;

MyHashSet *myHashSetCreate(void);
void myHashSetAdd(MyHashSet *set, int key);
void myHashSetRemove(MyHashSet *set, int key);
bool myHashSetContains(MyHashSet *set, int key);
void myHashSetFree(MyHashSet *set);

MyHashSet *myHashSetCreate(void)
{
	MyHashSet *set = malloc(sizeof(MyHashSet));
	for (int i = 0; i <= MAX_KEY; ++i)
		set->contains[i] = false;
	return set;
}

void myHashSetAdd(MyHashSet *set, int key)
{
	set->contains[key] = true;
}

void myHashSetRemove(MyHashSet *set, int key)
{
	set->contains[key] = false;
}

bool myHashSetContains(MyHashSet *set, int key)
{
	return set->contains[key];
}

void myHashSetFree(MyHashSet *set)
{
	free(set);
}
